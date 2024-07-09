#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>

#define SIZEST 128

// yup coped it from mkdir
char *formater(const char *argu)
{
    char *tmp = malloc((strlen(argu) + 2) * sizeof(char));
    strcpy(tmp, argu);
    char *formager = malloc(SIZEST * sizeof(char));
    char *pieces = strtok(tmp, "%");
    while (pieces != NULL)
    {
        strcat(formager, "%");
        strcat(formager, pieces);
        pieces = strtok(NULL, "%");
        strcat(formager, " ");
    }
    return formager;
}
int main(int argc, char const *argv[])
{
    char *rolex = malloc(SIZEST * sizeof(char));
    rolex = "%a %d %b %X %Z %Y";
    int f_flg = 0;
    int r_flg = 0;
    struct stat history;
    int i = 2;
    while (argv[i] && argv[i][0] == '-')
    {
        if (strcmp(argv[i], "-f") == 0)
            f_flg = 1;
        else if (strcmp(argv[i], "-r") == 0)
            r_flg = 1;
        else
        {
            printf("clackalack: invalid option\nuse either -f or -r\n");
            return -1;
        }
        i++;
    }
    if (f_flg && r_flg)
    {
        printf("clackalack: date can only take one argument at a time\n");
    }
    if (f_flg)
        rolex = formater(argv[i]);

    else if (r_flg)
    {
        int rozes = stat(argv[i], &history);
        if (rozes)
        {
            perror("clackalack");
            return -1;
        }
        printf("last modified : %s", ctime(&history.st_mtime));
        return 0;
    }
    time_t *when = malloc(sizeof(time_t));
    time(when);
    struct tm *very_well = localtime(when);
    size_t ever = SIZEST;
    char *lullaby = malloc(SIZEST * sizeof(char));
    ever = strftime(lullaby, ever, rolex, very_well);
    printf("%s\n", lullaby);
    return 0;
}
