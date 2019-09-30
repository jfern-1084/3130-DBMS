#include <stdio.h>
#define MAX 256

int main(void) {
  FILE *fptr;
  char sentence[MAX];

  fptr = fopen("test.txt","r");
  
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence);
  
  printf("\nEnd of file access \n");

  fclose(fptr);
}