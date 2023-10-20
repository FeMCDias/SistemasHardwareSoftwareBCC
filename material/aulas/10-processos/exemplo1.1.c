#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t pai, filho;
    int id = 0;

    for (int i = 0; i < 8; i++) {
        filho = fork();
        if (filho == 0) {
            // processo filho aqui
            id = i + 1;
            break;
        }
    }

    if (id == 0) {
        // processo pai aqui!
        pai = getpid();
        printf("Eu sou o processo pai, pid=%d, meu id do programa é %d\n", pai, id);
    } else {
        // processo filho aqui
        pai = getppid();
        filho = getpid();
        printf("Eu sou um processo filho, pid=%d, ppid=%d, meu id do programa é %d\n", filho, pai, id);
    }

    return 0;
}

