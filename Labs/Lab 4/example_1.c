/*Code developed by Miguel Garzon
for code : CSI 3130
Merged and edited by Johan Fernandes*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5


int main(void)
{
	//Example of bad array indexing
	char a[10];
	char *b = "bbbbb";

	a[0]=a[1]=a[2]= 'a';
	a[3]='\0';

	printf("a: %s \n b: %s\n ----------\n", a, b);

	//This is 100% wrong!
	//a[8000]='b';

	

  //Example of pointers with arrays
  int c[10];
  int d[] = {1, 2, 3};
  int *pb = &d[1];
  
  char *char_arr[] = {"aaa", "bbb", "ccc", "ddd"};
  char **p = char_arr;
  char *q = char_arr[0];
  char **r = &char_arr[0];
  
  printf("%d, %d, %d, %d\n", c[0], d[0], d[1], *pb);
  
  printf("%s, %s, %s, %s\n", 
                  char_arr[0], p[0], q, r[0]);
  printf("%p, %p, %p, %p\n", 
                  char_arr[0], p[0], q, r[0]);



	//Example of memory allocation with pointers
	int *ptr;
    int size = MAX;
	
	ptr = (int *) malloc(size);
     
  printf("Enter some numbers: \n");

	for (int i=0; i < size; i++){
		scanf("%d", (ptr + i));
	}
	
	for (int i=0; i < size; i++){
		printf("%d ", *(ptr + i));
	}
	
	printf("\n");
	
	//Increasing the array size
    size *= 2;
    ptr = realloc(ptr, size);
	
    if (ptr == NULL) {
      /* the realloc failed (it returned NULL), but the original address in ptr has been lost
         so the memory cannot be freed and a leak has occurred */
      /* ... */
      return (1);
    }
    else{
		
    printf("\n Enter some more numbers: \n");

		for (int i= MAX ; i < size; i++){
			scanf("%d", (ptr + i));
		}
	
		for (int i=0; i < size; i++){
			printf("%d ", *(ptr + i));
    }

		printf("\n");
	}
    
    free(ptr);

}