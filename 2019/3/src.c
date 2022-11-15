#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){

	if (argc != 2){
		printf("usage: %s <input filename> \n", argv[0]);
		exit(1);
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL){
		printf("Could not open file %s\n", argv[1]);
		exit(1);
	}

	// the file has two lines: one for each wire
	// each line is a comma separated list of movements,
	// eg U30,R1,D15,L9
	// U R D L are directions, the number preceding the comma is the number of units to move
	char *line = NULL;
	size_t len;
	ssize_t nread;

	while((nread = getline(&line, &len, fp)) != -1){
		printf("%s", line);	
	}

	if (line)
		free(line);

	exit(0);
}
	
