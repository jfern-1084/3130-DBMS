/*Developed by Johan Fernandes
for CSI 3130*/
#include <stdio.h>
#include <string.h>

/*Alternative way to declare strucutres*/
//struct Student { .....};
//You can then use this in the main function as:
//struct student a1. Here a1 is a variable of type student
typedef struct Student
{
    char name[50];
    int id;
    char univ[50];
}student;


int main(void) {

  student a1;         //Just one student
  student list[3];    //Array of students

  student *pt1 = &a1; //Access via pointer

  //Different ways to provide the values to elements of
  //a structure variable
  printf("Enter the name of the person : ");
  scanf("%s",a1.name);
  a1.id = 23425;
  printf("Enter the univ of the person : ");
  scanf("%s",a1.univ);

  //Print the contents of that variable
  printf("%d : %s : %s \n",a1.id,a1.name,a1.univ);

  //Change the contents of the variable
  //The below line is a quick way to edit string as we
  //normally would in Java
  strncpy((pt1)->name, "jane",5); 
  printf("Enter the new univ of the person : ");
  scanf("%s",(pt1)->univ);
  printf("Enter the new id of the person : ");
  //Look I've passed the address.
  //This is because id unlike name and univ is an int 
  //and not an array/pointer.
  scanf("%d",&(pt1)->id); 

  //Print the contents using the pointer and not the 
  //variable
  printf("%d : %s : %s \n",
    (pt1)->id,(pt1)->name,(pt1)->univ);

  //Fill the contents of the array of student structure
  for (int i = 0; i < 3; i++){
      printf("Enter the name of the person : ");
      scanf("%s",list[i].name);
      printf("Enter the id of the person : ");
      scanf("%d",&list[i].id);
      printf("Enter the univ of the person : ");
      scanf("%s",list[i].univ);
  }

  //Print the entire list
  for (int i = 0; i < 3; i++){
    printf("%d : %s : %s \n",
    (list + i)->id,(list + i)->name,(list + i)->univ);
  }
}