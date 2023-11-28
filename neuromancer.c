// vi:ft=c
#include <stdio.h>
#include <string.h>

int isPalindrome(char * p) {
  char * index, * reverse;

  index = p;
  while ( * index != '\0') {
    ++index;
  }
  --index;
  
  for (reverse = p; index >= reverse;) {
    if ( * index == * reverse) {
      --index;
      reverse++;
    } else {
    break;
    }
  }

  if (reverse > index) {
    return 1;
  } else {
    return 0;
  }
}

int main(int argc, char * argv[]) {
  if (argc == 1) {
    printf("Give me a string to check if it is palindrome\n");
    return 1;
  }

  char buf[128];

  char * word = argv[1];
  if (!isPalindrome(word)) {
    printf("The word \"%s\" is not palindrome\n", word);
  } else {
    strcpy(buf, word);
    printf("The string \"%s\" is palindrome and was written to the memory address %p.\n", buf, & buf);
  }

  return 0;
}
