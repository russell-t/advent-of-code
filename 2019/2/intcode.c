#include "intcode.h"

// run a program
int* parse(char *program, int *nints){

	// program is a list of integers separated by commas	

	char *ptr; // strtok pointer 
	char *str = program; //copy pointer

	size_t len = strlen(program); // determine length of string 
	
	int n = 1; // number of integers in the program

	// assume the worst case scenario in terms of number of integers, that all the integers are 1 digit
	// in that case, the number of integers would be the string size divided by 2
	// (since every other character would be a comma)
	int *pr = malloc(len/2 * sizeof(int));

	ptr = strtok(str, ",");
	pr[0] = atoi(ptr);	

	// parse
	while((ptr = strtok(NULL, ",")) != NULL) {
		pr[n] = atoi(ptr);
		n++;	
	}

	*nints = n;

	return pr;
}

void find_noun_verb(int *pr, int n){

	int *cpy = malloc(n * sizeof(int));

	if(cpy == NULL){
		printf("Error: could not allocate %ld bytes of memory\n", n * sizeof(int));
		return;
	}

	bool notFound = true;
	for (int noun = 0; (noun < 100) && notFound; noun++){
		for (int verb = 0; verb < 100; verb++){
			memcpy(cpy, pr, n * sizeof(int));
			cpy[1] = noun;
			cpy[2] = verb;
			execute(cpy,n,NULL,0);
			if (cpy[0] == 19690720){
				printf("noun: %d, verb: %d\n", noun, verb);
				notFound = false;
			}
		}
	}

	if(cpy)
		free(cpy);
}


void execute(int *program, int nints, int *err, bool print){

	int idx = 0;
	while(idx <= nints){
		if (program[idx] == 99)
			break;
		
		switch(program[idx]){
			case 1:
				add(program,&idx);
				break;
			case 2:
				multiply(program,&idx);
				break;
			default:
				printf("Error unrecognized opcode (%d) at position (%d)\n", program[idx], idx);
				if (err != NULL)
					*err = 1;
				return;
		}

	}

	if (print){
		// print the result
		for (int i = 0; i < nints-1; i++){
			printf("%d,", program[i]);
		}
		printf("%d\n", program[nints-1]);
	}
	if (err != NULL)
		*err = 0;
}

// opcode 1
void add(int *program, int *index){

	// e.g. opcode 1,9,10,3
	// add numbers at positions 9 and 10, store result in position 3
	int idx = *index;
	program[program[idx+3]] = program[program[idx+1]] + program[program[idx+2]];
	*index+=4;
}

// opcode 2
void multiply(int *program, int *index){

	// e.g. opcode 1,9,10,3
	// multiply numbers at positions 9 and 10, store result in position 3
	int idx = *index;
	program[program[idx+3]] = program[program[idx+1]]*program[program[idx+2]];
	*index+=4;
}

