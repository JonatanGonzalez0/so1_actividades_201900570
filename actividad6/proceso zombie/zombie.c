#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>

int main() {
    pid_t pid = fork();  // Crear un proceso hijo

    if (pid > 0) {
        // Este es el proceso padre
        printf("Proceso padre: %d\n", getpid());
        printf("Proceso hijo zombie: %d\n", pid);

        // El padre duerme indefinidamente sin llamar a wait(), lo que dejará al hijo como zombie
        sleep(60);

    } else if (pid == 0) {
        // Este es el proceso hijo
        printf("Proceso hijo: %d\n", getpid());
        sleep(1);  // Simula algún trabajo del hijo
        exit(0);   // El hijo termina, pero el padre no recoge su estado
    } else {
        perror("fork");
        exit(1);
    }

    return 0;
}
