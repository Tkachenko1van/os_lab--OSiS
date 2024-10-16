#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    pid_t child_pid = fork(); //разделяем процесс
    //т.к. exec - блокирующий вызов (main остановился бы на этапе вызова функции execvp)

    if(child_pid==0)
    {
        //дочерний процесс вызывает функцию execvp - системный вызов exec с параметрами
        printf("Executing sequential_min_max\n");
        execvp("./bin/sequential_min_max", argv); //исполнить команду с наследованием аргументов
        //в текущем каталоге lab3/src выполняем команду ./bin/sequential_min_max
        //по стуи - исполнить программу sequential_min_max как если бы вводили в терминал команды
        printf("Done\n");
        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Waiting for child process to finish executing.\n");
        wait(NULL);
    }

    printf("Done Executing, leaving...");
    return 0;
}