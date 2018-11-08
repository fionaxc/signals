#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int fd = open("foo.txt", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    char message[256] = "Program ended due to SIGINT \n";
    write(fd, message, 256);
    close(fd);
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
