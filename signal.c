#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("Program ended due to SIGINT\n");
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("Parent Process PID: %d\n", getppid());
  }
}

int main(){

  while (1) {
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    printf("Process PID: %d\n", getpid());
    sleep(1);
  }

  return 0;
}
