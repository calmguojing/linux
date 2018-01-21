#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "apue.h"

int main( int argc, char *argv[] ){
    int n;
    int fd[2];
    pid_t pid, cpid;
    char line[MAXLINE];
    int status;

    if( pipe( fd ) < 0 ){
        printf("pipe error\n");
        exit(1);
    }
    if( (pid = fork()) < 0 ){
        printf("fork error\n");
        exit(1);
    }else if( pid > 0 ){
        //parent process
        //close( fd[0] );
        write( fd[1], "hello world\n", 12 );
        if( wait( &status ) != pid ){
            printf("wait error\n");
        }
        close( fd[1] );
        exit(0);
    }else{
        //child process
        //close( fd[1] );
        if( ( cpid = fork() ) == 0 ){
            n = read( fd[0], line, MAXLINE );
            write( STDOUT_FILENO, line, n );
            close( fd[0] );
            exit(0);
        }
        exit(0);
    }
}
