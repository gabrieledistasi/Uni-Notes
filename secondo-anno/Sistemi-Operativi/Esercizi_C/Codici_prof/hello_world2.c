#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
#define STDOUT 1

int main(int argc, char *argv){
    char msg[] = "Hello World!\n"; 
    int nr = SYS_write; //id funzione write 
    
    syscall(nr, STDOUT, msg, sizeof(msg)); 

    return 0; 
}