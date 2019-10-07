/*Code developed by Miguel Garzon
Edited by Johan Fernandes for 
CSI 3130*/
#include <stdio.h>
#include <unistd.h>

int main(void)
{

    int x = 1; // Parent and child will get private copies!

    pid_t pid = fork();

    if (pid == 0) {
      //This is the child block or resultant process from fork()
      printf("in child (%d), x = %d\n", getpid(), ++x);
      fflush(stdout);

      //Use this for unbuffered output.
      //Ignore the fact that it uses stderr. 
      //This is just for learning hoe fork works
      //Do not use in deployment sitatuation
      // fprintf(stderr, "in child (%d), x = %d\n", getpid(), ++x);

    } else {
      //This is the parent process block
      printf("in parent(%d), x = %d\n", getpid(), --x);

    }
    //Both child and parent process will run this next line
    printf("bye from process (%d) with x = %d\n", getpid(), x);
    fflush(stdout);
    
} 