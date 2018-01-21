#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main( int argc, char *argv[] ){
    int fd; 
    char buf[15];

    fd = open( "./tmp.txt", O_RDONLY );

    read( fd, buf, 12 );

    printf( "read fifo: %s\n", buf );

    unlink( "./tmp.txt" );

    return 0;
}
