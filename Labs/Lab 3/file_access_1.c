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
  
  //Print the file contents here:
  printf("File contents are: \n");
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence);
 
  printf("\n\nEnd of file access \n\n");
  //close the file access
  fclose(fptr);


  //Clearing the file and adding new content
  //w+ will clear the content and provide read-write access or it will create a new file
  //r+ will provide read-write access or it will throw an error if the file does not exist
  fptr = fopen("string_data.txt","w+");

  printf("\nFile contents are: \n\n");
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence);  

  printf("Oop's it looks like all the content has been cleared, no thanks to w+\n\n");

  printf("Enter some new content \n");
  //This is one way to get a string input.
  //Scanf will not discard the new line character
  //We'll remove the \n in a while
  scanf("%[^\n]s", sentence);

  //Print the string you just got onto the blank file
  fprintf(fptr, "%s\n", sentence);

  
  printf("\nCool, now enter another line\n");
  c = getchar();     //Remove the new line char
  //Better  way to get a string input.
  fgets(sentence, sizeof(sentence), stdin);
  
  //Print the new input onto the next line on the file
  //Notice no \n here becuase fgets will inlcude that in string as well.
  fprintf(fptr, "%s", sentence);
  //close the file access
  fclose(fptr);



  //Appending content to the file
  fptr = fopen("string_data.txt","a+");

  printf("\n\nEnter some new content to append\n");
  //By now you know this is better
  fgets(sentence, sizeof(sentence), stdin); 
  //Notice no \n here becuase fgets will inlcude that in string as well.
  fprintf(fptr, "%s", sentence);
  //close the file access
  fclose(fptr);

  printf("\n");

  //Appending data somwhere in the middle
  fptr = fopen("string_data.txt","r+");

  printf("\nFile contents are: \n");
  while(fgets(sentence, sizeof(sentence), fptr))
    printf("%s", sentence); 
  
  //fseek will move th pointer to a specific location in the file
  //in this case it will start at the last word in the file and begin printing from the 3rd place to the left of the last character.
  fseek(fptr, -4, SEEK_END);
  
  printf("Enter some new content \n");
  fgets(sentence, sizeof(sentence), stdin);

  fprintf(fptr, "%s", sentence);
  //close the file access
  fclose(fptr);
}