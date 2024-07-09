#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int reapear(char const *argv[])
{
    int f_flg = 0;
    int v_flg = 0;
    int i = 2;
    char *bark_bark = malloc((strlen(argv[i]) + 2) * sizeof(char));
    while (argv[i] && argv[i][0] == '-')
    {
        if (strcmp(argv[i], "-f") == 0)
            f_flg = 1;
        else if (strcmp(argv[i], "-v") == 0)
            v_flg = 1;
        else
        {
            printf("clackalack: invalid option\nuse either -f or -v\n");
            return -1;
        }
        i++;
    }
    if (!argv[i])
    {
        printf("clackalack: enter a file name\n");

        return -1;
    }
    int reter;
    if (f_flg)
    {
        reter = remove(argv[i]);
    }
    else
        reter = unlink(argv[i]);

    if (reter)
    {
        perror("clackalack");
        return -1;
    }
    if (v_flg)
    {
        strcpy(bark_bark, argv[i]);
        char *pieces = strtok(bark_bark, "/");
        char *reeses;
        while (pieces != NULL)
        {
            reeses = pieces;
            pieces = strtok(NULL, "/");
        }
        printf("%s\n", reeses);
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    return reapear(argv);
}
