#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

int main (void) {
  clock_t t1 = clock();
    int fd ; 
    mkfifo("Main_fifo",0777) ; 
    char randstrs[50][11] = {{0}}; 
    srand (time(NULL));                         
    int i=0;  
    while(i<50)  { 
      int j=0;
        while(j<10){
           randstrs[i][j] = rand() % 26 + 97;
          j++;
          }
      i++;
      }
    for (int i=0 ; i<50 ; ) {
        printf("\n") ; 
        fd = open("Main_fifo",O_WRONLY) ; 
        if (fd == -1) {
            printf("Couldn't open the file in write mode..") ;
            return 1; 
        }
        if (write(fd,&i,sizeof(int))<0) {
             printf("Couldn't write the ID to file..") ;  
        }
        int n = strlen(randstrs[i]) + 1; 
        if(write(fd,&n,sizeof(int))<0) {
            printf("Couldn't write the size to file..") ;  
            return 2 ; 
        } 
        int moko = 1; 
        while (moko!=6) {
            if (write(fd,randstrs[i],sizeof(char)*11)){
                printf("Wrote: %d %s\n",i,randstrs[i]) ; 
                i++ ; 
            }
            moko++ ;  
        }
        close(fd) ;
        fd = open("Main_fifo", O_RDONLY) ; 
        if (fd == -1) {
            printf("Couldn't open the file in read mode..") ;
            return 1; 
        }
        int what ; 
        if (read(fd,&what,sizeof(int)) ) {
            printf("The read index value is: %d\n",what) ; 
        }
        close(fd) ; 
    }
  clock_t t2 = clock();
  double time=(double) (t2-t1)/CLOCKS_PER_SEC;
  printf("Time needed %f\n",time);
    return 0 ;
}