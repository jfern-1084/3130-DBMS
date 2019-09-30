#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char name[50];
    int id;
    char univ[50];
}student;


int main(void) {

  student list[2], list2[2];    //Array of students
  student *list3 = NULL;


  FILE *fptr;

  fptr = fopen("student_data.txt","w+");

  //Fill the contents of the array of student structure
  for (int i = 0; i < 2; i++){
      printf("Enter the name of the person : ");
      scanf("%s",list[i].name);
      fprintf(fptr, "%s\n", list[i].name);

      printf("Enter the id of the person : ");
      scanf("%d",&list[i].id);
      fprintf(fptr, "%d\n", list[i].id);

      printf("Enter the univ of the person : ");
      scanf("%s",list[i].univ);
      fprintf(fptr, "%s\n", list[i].univ);
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
  for (int i = 0; i < 2; i++){
    printf("%d : %s : %s \n",
    (list2 + i)->id,(list2 + i)->name,
    (list2 + i)->univ);
  }

  printf("\n");

  fflush(stdin);

  //Adding new data to the exisiting structure
  list3 = (student *) malloc(( 3 * sizeof(student)));

  strncpy(list3[2].name, "kate",5); 
  printf("Enter the new univ of the person : ");
  scanf("%s",list3[2].univ);
  printf("Enter the new id of the person : ");
  scanf("%d",&list3[2].id); 

  //Print the entire list
  printf("%d : %s : %s \n",
  (list3 + 2)->id,(list3 + 2)->name,
  (list3 + 2)->univ);
}