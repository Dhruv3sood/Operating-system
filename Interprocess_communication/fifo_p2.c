#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>
int main() {
    clock_t t1=clock();
    int fd ; 
    char arraystr[50][11] = {{0}} ;
    int ID,n  ; 
    for (int i=0 ; i<50 ;) {
        printf("\n") ;
        fd = open("Main_fifo" , O_RDONLY) ; 
        if (fd < 0 ) {
            printf("Couldn't open the file in read mode..") ; 
            return 1; 
        }
        if(read(fd, &ID, sizeof(int)) ){
            printf("Read from ID: %d\n",ID) ; 
        }
        if(read (fd, &n , sizeof(int)) <0 ) {
           printf("Couldn't read the size from file") ;  
        } 
        int count = 1 ;
        while (count !=6 ) {
            if(read(fd, arraystr[i], n) < 0) {
                printf("Couldn't read from file") ; 
                return 2 ;
            }
            printf("Read: %d %s\n",i,arraystr[i]) ;
            i++ ; 
            count++ ; 
        }
        close(fd) ;
        ID = ID+4 ; 
        fd = open("Main_fifo" , O_WRONLY)  ; 
        if (fd < 0 ) {
            printf("Couldn't open the file in write mode..") ; 
            return 1; 
        }
        if (write(fd, &ID, sizeof(int))) {
            printf("Wrote ID %d to file\n", ID) ; 
        }
        close(fd) ; 
    }
  clock_t t2 = clock();
  double time=(double) (t2-t1)/CLOCKS_PER_SEC;
  printf("Time needed %f\n",time);
  return 0 ;
}