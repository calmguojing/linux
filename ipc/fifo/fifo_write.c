#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


int main( int argc, char *argv[] ){
    int fd;

    mkfifo( "./tmp.txt", 0666 );

    fd = open( "./tmp.txt", O_WRONLY );

    write( fd, "hello fifo", 12 );

    close( fd );
}

