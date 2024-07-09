#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define LNG_WORD 256
#define LN_SZE 1024

FILE *filing(char const *argv, char *swung)
{
    if (!argv)
    {
        printf("clackalack: enter a filename");
        return NULL;
    }
    FILE *gm = NULL;
    if (swung)
        gm = fopen(argv, swung);
    if (!gm)
    {
        perror("clackalack");
        return NULL;
    }
    return gm;
}

int file_smith(char const *argv[])
{
    int i = 2;
    int l_flg = 0;
    int wut = 0;
    FILE *frile = NULL;
    while (argv[i])
    {
        if (!strcmp(argv[i], "-n"))
        {
            if (!l_flg)
                l_flg = 1;
        }
        else if (!strcmp(argv[i], "-b"))
            l_flg = 2;
        else if (argv[i][0] == '-')
        {
            printf("clackalack: invalid option\nuse either -n or -b\n");
            return -1;
        }
        else if (!strcmp(argv[i], ">>"))
        {
            if (frile)
            {
                FILE *plagger = filing(argv[++i], "a");
                char plg_char = fgetc(frile);
                if (!plg_char)
                {
                    perror("clackalack");
                    return -1;
                }
                while (plg_char != EOF)
                {
                    fputc(plg_char, plagger);
                    plg_char = fgetc(frile);
                }
                return 0;
            }
            frile = filing(argv[++i], "a");
            if (!frile)
                return -1;
            while (1)
            {
                char hartt = getchar();
                if (!hartt)
                {
                    perror("clackalack");
                    return -1;
                }
                if (hartt == EOF)
                    break;
                fprintf(frile, "%c", hartt);
            }
        }
        else if (!strcmp(argv[i], ">"))
        {
            if (frile)
            {
                FILE *plagger = filing(argv[++i], "w");
                char plg_char = fgetc(frile);
                if (!plg_char)
                {
                    perror("clackalack");
                    return -1;
                }
                while (plg_char != EOF)
                {
                    fputc(plg_char, plagger);
                    plg_char = fgetc(frile);
                }
                return 0;
            }
            frile = filing(argv[++i], "w");
            if (!frile)
                return -1;
            while (1)
            {
                char hartt = getchar();
                if (!hartt)
                {
                    perror("clackalack");
                    return -1;
                }
                if (hartt == EOF)
                    break;
                fprintf(frile, "%c", hartt);
            }
        }
        else
        {
            frile = filing(argv[i], "r");
            if (!frile)
                return -1;
            if (!argv[i + 1] || strcmp(argv[i + 1], ">") && strcmp(argv[i + 1], ">>"))
            {
                int ls = 1;
                while (1)
                {
                    char *glorck = malloc(LN_SZE * sizeof(char));
                    if (!fgets(glorck, LN_SZE, frile))
                        break;
                    if (l_flg == 1)
                    {
                        printf("\t%d ", ls);
                        ls++;
                        printf("%s", glorck);
                    }
                    else if (l_flg && strcmp(glorck, "\n"))
                    {
                        printf("\t%d ", ls);
                        ls++;
                        printf("%s", glorck);
                    }
                    else
                        printf("%s", glorck);
                }
            }
        }
        i++;
    }

    return 0;
}
int main(int argc, char const *argv[])
{
    file_smith(argv);
    return 0;
}
