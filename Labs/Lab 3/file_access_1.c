/*Code developed by Johan Fernandes
for CSI 3130*/

#include <stdio.h>
#define MAX 256

int main(void) {
  FILE *fptr;
  char sentence[MAX];
  char c;

  //Simple file read
  fptr = fopen("string_data.txt","r");
  
  printf("File contents are: \n");
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence);
 
  printf("\nEnd of file access \n");

  fclose(fptr);



  //Clearing the file and adding new content
  fptr = fopen("string_data.txt","w+");

  printf("File contents are: \n");
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence);  

  printf("There's nothing in the file \n");
  printf("Enter some new content \n");
  scanf("%[^\n]s", sentence);

  fprintf(fptr, "%s\n", sentence);

  printf("Enter another line \n");
  c = getchar();     //For the new line char
  gets(sentence);
  
  fprintf(fptr, "%s\n", sentence);

  fclose(fptr);



  //Appending content to the file
  fptr = fopen("string_data.txt","a+");

  printf("Enter some new content \n");
  gets(sentence);  

  fprintf(fptr, "%s", sentence);

  fclose(fptr);

  printf("\n");

  //Appending in a different manner
  fptr = fopen("string_data.txt","r+");

  printf("File contents are: \n");
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence); 
  
  // fseek(fptr, -4, SEEK_END);
  fseek(fptr, -4, SEEK_END);
  
  printf("Enter some new content \n");
  gets(sentence);  

  fprintf(fptr, "%s", sentence);

  fclose(fptr);
}