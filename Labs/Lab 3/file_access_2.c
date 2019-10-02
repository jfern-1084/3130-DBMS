/*Code developed by Johan Fernandes
for CSI 3130*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//The student structure from Lab 2
typedef struct Student
{
    char name[50];
    int id;
    char univ[50];
}student;


int main(void) {

  //Make two arrays of the structure
  student list[2], list2[2];    //Array of students
  char c;

  
  //Experimentation of realloc and malloc
  //Another way to declare an array
  //With this pointer method we can even increase the //array size
  student *list3 = (student *)( malloc(2 * 
                          sizeof(student))); 
  student *list4 = NULL;      


  FILE *fptr;

  fptr = fopen("student_data.txt","w+");

  //Fill the contents of the array of student structure
  for (int i = 0; i < 2; i++){
      printf("Enter the name of the person : ");
      //Use scanf if you don't want the \n as part of your word/sentence
      // scanf("%s",list[i].name);
      fgets(list[i].name,sizeof(list[i].name),stdin);
      fprintf(fptr, "%s", list[i].name);

      printf("Enter the id of the person : ");
      scanf("%d",&list[i].id);
      c = getchar();  //Get the \n char
      fprintf(fptr, "%d\n", list[i].id);

      printf("Enter the univ of the person : ");
      //use fgets if you would like to keep the \n as part of your word/sentence
      fgets(list[i].univ,sizeof(list[i].univ),stdin);
      fprintf(fptr, "%s", list[i].univ);
  }

  // fwrite(list, sizeof(list), 1, fptr);
  fclose(fptr);

  fptr = fopen("student_data.txt","r+");

  for (int i = 0; i < 2; i++){
      fgets(list2[i].name, sizeof(list2[i].name), fptr);
      fscanf(fptr, "%d\n",&list2[i].id);
      fgets(list2[i].univ, sizeof(list2[i].univ), fptr);
  }

  fclose(fptr);
  
  //Print the entire list
  //Also copying the content to list3
  for (int i = 0; i < 2; i++){
    printf("%d : %s : %s \n",
    (list2 + i)->id,(list2 + i)->name,
    (list2 + i)->univ);

    //Also quickly copying the contents to list3
    (list3 + i)->id = (list2 + i)->id;
    //This is how you move a string
    strcpy((list3 + i)->name, (list2 + i)->name);
    strcpy((list3 + i)->univ, (list2 + i)->univ); 
  }

  printf("\n\n");

  
  //Printing the contents of list3 which is technically the same as list2
  for (int i = 0; i < 2; i++){
    printf("%d : %s : %s \n",
    (list2 + i)->id,(list2 + i)->name,
    (list2 + i)->univ);
  }

  //Adding a new element to the exisiting array
  list4 = (student *) realloc(list3, 
                              ( 3 * sizeof(student)));

  strncpy(list4[2].name, "kate",5); 
  printf("Enter the new univ of the person : ");
  fgets(list4[2].univ,sizeof(list4[2].univ),stdin);
  printf("Enter the new id of the person : ");
  fgets(list4[2].univ,sizeof(list4[2].univ),stdin); 


  //Printing list4 now
  for (int i = 0; i < 3; i++){
    printf("%d : %s : %s \n",
    (list4 + i)->id,(list4 + i)->name,
    (list4 + i)->univ);
  }
  
}