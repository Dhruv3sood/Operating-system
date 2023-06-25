// CLIENT
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <time.h>
#define NAME "/tmp/socket_IPC"
int main(int argc, char *argv[])
{
  clock_t t1 = clock();
    struct sockaddr_un address;
    char buffer[512];
    int data = socket(AF_UNIX, SOCK_STREAM, 0);
    if (data == -1)
    {
        perror("error socket");
        exit(EXIT_FAILURE);
    }
    memset(&address, 0, sizeof(struct sockaddr_un));
    address.sun_family = AF_UNIX;
    strncpy(address.sun_path, NAME, sizeof(address.sun_path) - 1);
    int ret = connect(data, (const struct sockaddr *)&address, sizeof(struct sockaddr_un));
    if (ret == -1)
    {
        fprintf(stderr, "The server is down.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0 ; i<10 ; i++) {
        ret = read(data, buffer, 512);
        printf("\n");
        printf("Batch no %d start\n", i+1);
        printf("\n");
        printf("%s\n", buffer);
        printf("Batch no %d complete\n", i+1);
        printf("\n");
        printf("----------------------------\n");
        if (ret == -1)
        {
            perror("read");
            exit(EXIT_FAILURE);
        }
        char tokkk[2];
        int z = (5*(i+1))-1;
        sprintf(tokkk, "%d", z);
        ret = write(data, tokkk, sizeof(tokkk));
        if (ret == -1)
        {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }
  clock_t t2 = clock();
  double time=(double) (t2-t1)/CLOCKS_PER_SEC;
  printf("Time needed %f\n",time);
    close(data);
    exit(EXIT_SUCCESS);
}