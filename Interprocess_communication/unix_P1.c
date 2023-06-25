
// SERVER
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#define NAME "/tmp/socket_IPC"
#include <unistd.h>
#include <time.h>
char arr[60][20];
void random_string_generator() {
    static char x[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    for (int i = 0 ; i<50 ; i++){
        char ans[20];
        for (int j = 0 ; j < 10 ; j++) {    
            int num = (rand() % 50);
            // int num = (rand() % 26+97);
            ans[j] = x[num];
        }
        ans[10] = '\n';
        ans[11] = '\0';
        strcpy(arr[i], ans);
    }       
}
int main(int argc, char *argv[])
{
  clock_t t1 = clock();
  random_string_generator();
    struct sockaddr_un name;
#if 0  
    struct sockaddr_un {
        sa_family_t sun_family;           
        char sun_path[108];         
    };
#endif
    char buffer[512];
    unlink(NAME);
    int socket_con = socket(AF_UNIX, SOCK_STREAM, 0);
    if (socket_con == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    memset(&name, 0, sizeof(struct sockaddr_un));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, NAME, sizeof(name.sun_path) - 1);
    int bind_return = bind(socket_con, (const struct sockaddr *)&name, sizeof(struct sockaddr_un));
    if (bind_return == -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    bind_return = listen(socket_con, 20);
    if (bind_return == -1)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    for (;;)
    {
        int data = accept(socket_con, NULL, NULL);
        if (data == -1)
        {
            perror("accepted");
            exit(EXIT_FAILURE);
        }
        int ctr = 0;
        for (int i = 0 ; i<10 ; i++) {
            ctr+=1;
            char tok[512];
            strcpy(tok, arr[5*i]);
            strcat(tok, arr[(5*i)+1]);
            strcat(tok, arr[(5*i)+2]);
            strcat(tok, arr[(5*i)+3]);
            strcat(tok, arr[(5*i)+4]);
            bind_return = write(data, &tok, sizeof(tok));
            if (bind_return == -1)
            {
                perror("write\n");
            }
            memset(buffer, 0, 512);
            bind_return = read(data, buffer, 512);
            printf("The highest ID received from P2 for batch no %d is %s, and is being printed in function P1.\n", i+1, buffer);

        }
        if (ctr==9){
            close(data);
            break;
        }
     
    }
    clock_t t2 = clock();
    double time=(double) (t2-t1)/CLOCKS_PER_SEC;
    printf("Time needed %f\n",time);
    close(socket_con);
    unlink(NAME);
    exit(EXIT_SUCCESS);

}