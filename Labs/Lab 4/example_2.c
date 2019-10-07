/*Code developed by Miguel Garzon
Edited by Johan Fernandes for 
CSI 3130*/
#include <stdio.h>

char *string_val = "john";
int int_val = 100;

void
func(void )
{
  static int count = 0;
  
  count++;
  printf("counting in func: %d in line %d\n", count, __LINE__);
  
  int ia = 0;
  printf("value of ia : %d in line %d\n", ia, __LINE__);

  {
    int ia = 1;
    printf("value of ia : %d in line %d\n", ia, __LINE__);
  }
  
  printf("value of ia : %d in line %d\n", ia, __LINE__);

  string_val = "jam";
  int_val = 300;
  printf("string_val: %s, int_val %d in line %d\n", string_val, int_val, __LINE__);
}


int main()
{                                                                               
  string_val = "jane";
  int_val = 200;
  printf("string_val: %s, int_val %d in line %d\n", string_val, int_val, __LINE__);


  printf("\n\n------ calling func ---------\n\n");  
  func();
  printf("\n\n------ returned from func ---------\n\n");  
  
  string_val = "jane";
  int_val = 200;
  printf("string_val: %s, int_val %d in line %d\n", string_val, int_val, __LINE__);

  printf("\n\n------ calling func again ---------\n\n");
  func();
  printf("\n\n------ returned from func ---------\n\n");  
  
  printf("string_val: %s, int_val %d in line %d\n", string_val, int_val, __LINE__);
}