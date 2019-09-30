/*Developed by Johan Fernandes
for course CSI 3130*/
#include <stdio.h>
#define MAX 5  //constant

//Function declarations
void printArray(int size, int n[size]);
void print2DArray(int size, int n[][size]);
void swap(int *x1, int *x2);
void bubbleSort(int size, int n[size]);

int main(void) {

  int *pc;
  int c;
  int n_ary[MAX] = {0};

  int m1[2][2] = {{4,7},{6,9}};
  int m2[2][2] = {{0}};

  printf("Enter an integer value \n");
  scanf("%d", &c);

  /* Note: * with a pointer variable indicates a deferencing operation */
  //Pointers to numerical values
  pc = &c;
  printf("Value of c : %d\n",c);
  printf("Adress of c : %p\n",&c);
  printf("Value of pointer pc : %p\n", pc);
  //Changing the value of c through pointer pc
  printf("Value of c : %d\n", *pc);
  printf("Value of c : %d\n", ++(*pc));
  printf("Value of c : %d\n", (*pc)--);
  //Displaying the final changes
  printf("Value of c : %d\n",c);


  /*Dealing with Arrays*/
  //Print an all 0 array
  printArray(MAX,n_ary);
  
  //Get inputs from user:
  printf("Enter a sequence of 5 numbers\n");
  for (int i = 0; i < MAX; i++){
    /*Although n_ary is a static pointer you must provide the address of the pointer where the value is to be stored*/
    scanf("%d",&n_ary[i]);  
  }

  //Print new array with user provided values
  printArray(MAX,n_ary);

  //increment the values of each element by 1
  for (int i = 0; i < MAX; i++){
    n_ary[i]++;
    //Alternative by dereferencing the pointer
    //(*(n_ary + i))++ ; 
  }

  //Print newly updated array
  printArray(MAX,n_ary);

  //Decrement the values of each element by 10
  for (int i = 0; i < MAX; i++){
    n_ary[i] -= 10;
    //Alternative by dereferencing the pointer
    // *(n_ary + i) -= 10;
  }

  //Print newly updated array
  printArray(MAX,n_ary);

  //Sort the array in ascending order.
  //The sorting will be inplace so you don't need
  //another array to store the sorted values.
  //All thanks to the fact that an array act as pointer //and thus use the call by reference property. 
  bubbleSort(MAX,n_ary);

  //Print new sorted array
  printArray(MAX,n_ary);

  //Print 2D array we initialized earlier
  print2DArray(2,m1);

  //Enter the values for the second 2D array
  printf("Enter values for a 2 x 2 array\n");
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      scanf("%d",&m2[i][j]);
    }
  }

  //Print the new 2D array as well
  print2DArray(2,m2);

  //Matrix addition
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      m1[i][j] += m2[i][j] ;
    }
  }

  printf("\n");
  
  //Print the new contents of the first 2D array. 
  print2DArray(2,m1);
}


//Function to print the entire 1d array
void printArray(int size, int n[size]){
  printf("Here's the array : ");
  for (int i = 0; i < size; i++){
    printf("%d ",n[i]);
    //Alternative by dereferencing the pointer
    // printf("%d ",*(n + i));
  }
  printf("\n");
}


//Function to print the entire 2D array
void print2DArray(int size, int n[][size]){
  printf("Here's the 2d array : \n");
  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      printf("%d ",n[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

//Swap two integer values using call by reference
void swap(int *x1, int *x2){
  int temp;
  temp = *x1;
  *x1 = *x2;
  *x2 = temp;
}

//Sort the contents of the array in ascending order
void bubbleSort(int size, int n[size]){
  for (int i = 0; i < size - 1; i++){
    for(int j = 0; j < size - i - 1; j++){
      if (n[j] > n[j+1]){
        swap(&n[j], &n[j+1]);
      }
    }
  }
}

