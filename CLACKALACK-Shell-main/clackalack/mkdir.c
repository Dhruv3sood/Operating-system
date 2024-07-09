#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// coped it from threader
char **prompt_breaker(char *argu, int crude)
{
    if (!crude)
    {
        char **trudth = malloc(2 * sizeof(char *));
        trudth[0] = argu;
        trudth[1] = NULL;
        return trudth;
    }
    char *mortality = malloc((strlen(argu) + 2) * sizeof(char));
    strcpy(mortality, argu);
    char *pieces = strtok(argu, "/");
    int cnt = 2;
    while (mortality)
    {
        mortality = strchr(mortality, '/');
        if (mortality)
        {
            mortality++;
            cnt++;
        }
    }
    int hen = 0;
    char **groin = malloc((cnt + 1) * sizeof(char *));
    while (pieces != NULL)
    {
        groin[hen] = pieces;
        hen++;
        pieces = strtok(NULL, "/");
    }
    groin[cnt + 1] = NULL;
    return groin;
}

int slice_n_serve(char const *crola[])
{
    int v_flg = 0;
    int p_flg = 0;
    int i = 2;
    while (crola[i] && crola[i][0] == '-')
    {
        if (strcmp(crola[i], "-p") == 0)
            p_flg = 1;
        else if (strcmp(crola[i], "-v") == 0)
            v_flg = 1;
        else
        {
            printf("clackalack: invalid option\nuse either -p or -v\n");
            return -1;
        }
        i++;
    }
    if (!crola[i])
    {
        printf("clackalack: enter a file name\n");
        return -1;
    }
    while (crola[i])
    {
        char *alorc = malloc((strlen(crola[i]) + 2) * sizeof(char));
        strcpy(alorc, crola[i]);
        char **corola = prompt_breaker(alorc, p_flg);
        int j = 0;
        int plox = 0;
        if (v_flg)
        {
            char *verbose = malloc(1000 * sizeof(char));
            while (corola[j])
            {
                strcat(verbose, corola[j]);
                plox = mkdir(verbose, 0777);
                if (plox == -1 && !(corola[j + 1]))
                {
                    perror("clackalack");
                    return -1;
                }
                if (plox != -1)
                    printf("%s\n", verbose);
                strcat(verbose, "/");
                j++;
            }
        }
        else
        {
            char *verbose = malloc(1000 * sizeof(char));
            while (corola[j])
            {
                strcat(verbose, corola[j]);
                plox = mkdir(verbose, 0777);
                if (plox == -1 && !(corola[j + 1]))
                {
                    perror("clackalack");
                    return -1;
                }
                strcat(verbose, "/");
                j++;
            }
        }
        i++;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    return slice_n_serve(argv);
}