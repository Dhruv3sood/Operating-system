#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>

#define INP_SZE 1024
#define CMD_LNE 4096
#define ARGS_SZE 8
#define BREAKERS " \t\n"

int CngDir(char *args, char *arger);
int Echo(char **args);
char *ppwwdd(char *args);
char *PWD();

// thread and system for part 2
int threader(char **argv);

// file directory
char const *whereami;
// working directory
char *myself;
// fork and execute a new process

int diver(char **args)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        char *wHere = malloc(INP_SZE * sizeof(char));
        strcat(wHere, whereami);
        strcat(wHere, "/");
        strcat(wHere, args[0]);
        execl(wHere, wHere, myself, args[1], args[2], args[3], args[4], args[5], args[6], args[7], NULL);
        perror("clackalack");
        exit(-1);
    }
    else
    {
        pid_t kid = wait(NULL);
        if (kid == -1)
        {
            perror("clackalack");
            return -1;
        }
        return 0;
    }
    return 0;
}

// returns current folder name
char *whoami(char *dir)
{
    char *sacrifice = dir;
    char *me = NULL;
    int cnt = 1;
    while (sacrifice)
    {
        me = sacrifice;
        sacrifice = strchr(sacrifice, '/');
        if (sacrifice)
        {
            sacrifice++;
            cnt++;
        }
    }
    return me;
}

// calls cat command for documentation
int man_cat(char **khaanabadosh)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        char *convict = malloc(INP_SZE * sizeof(char));
        char *dog = malloc(INP_SZE * sizeof(char));
        strcat(convict, whereami);
        strcat(convict, "/");
        strcpy(dog, convict);
        strcat(dog, "cat");
        strcat(convict, "Documentations/");
        strcat(convict, khaanabadosh[1]);
        strcat(convict, ".txt");
        execl(dog, dog, convict, convict, NULL);
        perror("clackalack");
        exit(-1);
    }
    else
    {
        pid_t kid = wait(NULL);
        if (kid == -1)
        {
            perror("clackalack");
            return -1;
        }
        printf("\n");
        return 0;
    }
    return 0;
}

// breaks shell input about the spaces
char *cattle(char *brod, char *brooker)
{
    char *shruker = malloc(3 * sizeof(char));
    strcpy(shruker, brooker);
    if (strstr(brod, ">>"))
        strcat(shruker, ">");
    char *pieces = strtok(brod, brooker);
    char *vitality = malloc((strlen(brod) + 4) * sizeof(char));
    while (1)
    {
        strcat(vitality, pieces);
        pieces = strtok(NULL, brooker);
        if (!pieces)
            break;
        strcat(vitality, " ");
        strcat(vitality, shruker);
        strcat(vitality, " ");
    }
    return vitality;
}
char **prompt_breaker(char *argu)
{
    argu = cattle(argu, ">");
    int cnt = 2;
    char *mortality = malloc((strlen(argu) + 2) * sizeof(char));
    strcpy(mortality, argu);
    char *pieces = strtok(argu, BREAKERS);
    while (mortality)
    {
        mortality = strpbrk(mortality, BREAKERS);
        if (mortality)
        {
            mortality++;
            cnt++;
        }
    }
    int hen = 0;
    char **groin = malloc(cnt * sizeof(char *));
    while (pieces != NULL)
    {
        groin[hen] = pieces;
        hen++;
        pieces = strtok(NULL, BREAKERS);
    }
    return groin;
}

// checks for command
int prompt_chk(char **cmd)
{
    char *task = cmd[0];
    if (!strcmp(task, "clear"))
        printf("\e[1;1H\e[2J");
    else if (!strcmp(task, "pwd"))
        printf("%s\n", ppwwdd(cmd[1]));
    else if (!strcmp(task, "echo"))
        Echo(cmd);
    else if (!strcmp(task, "cd"))
        CngDir(cmd[1], cmd[2]);
    else if (!strcmp(task, "exit"))
    {
        printf("\x1B[33mProcess terminated with exit code\x1B[0m \x1B[32m0\x1B[0m\n");
        exit(0);
    }
    else if (!strcmp(task, "man"))
        man_cat(cmd);
    else if (strstr(task, "&t"))
        threader(cmd);
    else
        diver(cmd);
    return 0;
}

// shell
int run_terminal()
{
    while (1)
    {
        char *cutted = whoami(myself);
        char *argu = malloc(INP_SZE * sizeof(char));
        char **cmd = calloc(sizeof(char), ARGS_SZE);
        size_t sze = INP_SZE;
        printf("\x1b[31mNarotam_2021477\x1b[0m\x1b[36m /%s\x1b[0m\x1b[31m>\x1b[0m ", cutted);
        ssize_t inpsze = getline(&argu, &sze, stdin);
        if (argu[inpsze - 1] == '\n')
            argu[inpsze - 1] = '\0';
        if (strcmp(argu, ""))
            cmd = prompt_breaker(argu);
        if (cmd[0])
            prompt_chk(cmd);
        myself = PWD();
    }
    return 0;
}

// clackalack
int main(int argc, char const *argv[])
{
    whereami = PWD();
    myself = PWD();
    printf(" ");
    printf("\x1B[33mwelcome to\x1B[0m ");
    printf("\x1B[32mCLACKALACK\x1B[0m\n");
    run_terminal();
}

// pwd options
char *ppwwdd(char *dir)
{
    if (dir && !strcmp(dir, "-L"))
    {
    }
    else if (dir && !strcmp(dir, "-P"))
    {
        char *where = malloc(INP_SZE * sizeof(char));
        char *notu = getcwd(where, INP_SZE);
        if (!notu)
        {
            perror("clackalack");
            return NULL;
        }
        return where;
    }
    else if (dir)
    {
        return "clackalack: invalid option\nuse either -L or -P";
    }
    return getenv("PWD");
}

// pwd
char *PWD()
{
    char *where = malloc(INP_SZE * sizeof(char));
    char *notu = getcwd(where, INP_SZE);
    if (!notu)
    {
        perror("clackalack");
        return NULL;
    }
    return where;
}

// echo
int Echo(char **args)
{
    int i = 1;
    int optflag = 0;
    int nflag = 0;
    char *dumpr = args[i];
    char *spc = " ";
    while (dumpr)
    {
        i++;
        if (!strcmp(dumpr, "--") && !optflag)
            optflag = 1;
        else if (!strcmp(dumpr, "-n") && !optflag)
            nflag = 1;
        else if (!strcmp(dumpr, "-s") && !optflag)
            spc = "";
        else
        {
            optflag = 1;
            printf("%s%s", dumpr, spc);
        }
        dumpr = args[i];
    }
    if (!nflag)
        printf("\n");
    return 0;
}

// cd
int CngDir(char *dir, char *direr)
{
    if (dir)
    {

        if (!strcmp(dir, "~"))
        {
            int fruck = chdir(getenv("HOME"));
            if (fruck == -1)
            {
                perror("clackalack");
                return -1;
            }
            setenv("PWD", PWD(), 1);
            return 0;
        }
        else if (!strcmp(dir, "-P"))
        {
            if (direr)
            {
                char *wHere = malloc(INP_SZE * sizeof(char));
                strcat(wHere, PWD());
                strcat(wHere, "/");
                if (strchr(direr, '/') || strchr(direr, '.') || strchr(direr, '~'))
                {
                    printf("clackalack: Not a symbolic link\n");
                    return -1;
                }
                int fruck = chdir(direr);
                if (fruck == -1)
                {
                    perror("clackalack");
                    return -1;
                }
                strcat(wHere, direr);
                setenv("PWD", wHere, 1);
                return 0;
            }
        }
        int fruck = chdir(dir);
        if (dir && fruck == -1)
        {
            perror("clackalack");
            return -1;
        }
        setenv("PWD", PWD(), 1);
        return 0;
    }
    return 0;
}

// part 2 solution
void *syzler(void *sm)
{
    char *typest = (char *)sm;
    int boltz = system(typest);
    if (boltz)
    {
        return NULL;
    }
    return sm;
}
int threader(char **argv)
{
    char *wHere = malloc(CMD_LNE * sizeof(char));
    strcat(wHere, whereami);
    strcat(wHere, "/");
    argv[0][strlen(argv[0]) - 2] = '\0';
    strcat(wHere, argv[0]);
    strcat(wHere, " ");
    strcat(wHere, myself);
    int i = 1;
    while (argv[i])
    {
        strcat(wHere, " ");
        strcat(wHere, argv[i]);
        i++;
    }
    pthread_t thrd;
    int maad = pthread_create(&thrd, NULL, syzler, wHere);
    if (maad)
    {
        perror("clackalack");
        return -1;
    }
    int good = pthread_join(thrd, NULL);
    if (good)
    {
        perror("clackalack");
        return -1;
    }
    return 0;
}