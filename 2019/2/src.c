#include "intcode.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

	int err;

	// usage
	if(argc != 2){
		printf("usage: %s <program>, ex. %s input.txt\n", argv[0], argv[0]);
		exit(1);
	}

	FILE *fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Error: could not open program\n");
		exit(1);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	if((nread = getline(&line, &len, fp)) == -1){
		printf("Error: could not read line from program\n");
		exit(1);
	}

	// run the program
	int n; // allocated number of ints returned by parse()
	int *pr = parse(line, &n);
	int *copy = malloc(n * sizeof(int));
	//execute(pr, n, &err, 1);
	find_noun_verb(pr, n);

	// clean up
	if(line)
		free(line);
	free(pr);
	free(copy);
	fclose(fp);
	exit(err);
}
