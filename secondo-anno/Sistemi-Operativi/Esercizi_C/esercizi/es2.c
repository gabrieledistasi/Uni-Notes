#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <time.h>

void p(const char *msg) {printf("[%d -> %d] %s", getpid(), getpid(), msg);}
void work_p(int fd[2], char *name) {

 
  close(fd[0]);
 
  p("Ciao sono il processo ");
  printf("%s\n", name);
 
  srand(time(NULL) + getpid()); // seed diversi per processo
  for (int i = 0; i < 10; i++) {
    int random = rand() % 10;
    if ((random % 2) != 0) {
      if (!strcmp(name, "P2")) {
        p("");
        printf("Number random dispari : %d\n", random);
        write(fd[1], &random, sizeof(int));
      }
    } else {
      if (!strcmp(name, "P1")) {
        p("");
        printf("Number random pari : %d\n", random);
        write(fd[1], &random, sizeof(int));
      }
    }
 
    sleep(1);
  }
 
  close(fd[1]);
}
 
int main() {
 
  int fd2[2];
  int fd1[2];
  pipe(fd1); // flusso P1 -> P
 
  pid_t p1 = fork();
 
  if (p1 == 0) {
    work_p(fd1, "P1");
  } else {
 
    pipe(fd2); // flusso P2 -> P
 
    pid_t p2 = fork();
 
    if (p2 == 0) {
      work_p(fd2, "P2");
    } else {
 
      close(fd1[1]);
      close(fd2[1]);
      int rec1;
      int rec2;
     while (1) {
        // questa roba si può incorporare nella condizione del while
        int r1 = read(fd1[0], &rec1, sizeof(int));
        int r2 = read(fd2[0], &rec2, sizeof(int));
 
        if (r1 <= 0 || r2 <= 0) {
          // controllo if se uno dei read ha finito allora abbiamo finito perché
          // non riusciamo a creare più coppie per la somma
          break;
        }
 
        p("Received ");
        printf("%d and %d | ", rec1, rec2);
        printf("sum %d\n", rec1 + rec2);
      }
 
      close(fd2[0]);
      close(fd1[0]);
      wait(NULL);
      wait(NULL);
    }
  }
 
  return 0;
}
 