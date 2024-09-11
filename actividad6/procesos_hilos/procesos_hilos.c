#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *thread_function(void *arg) {
    printf("Thread created in process %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    // Primer fork
    pid = fork();
    if (pid == 0) { /* child process */
        // Segundo fork dentro del proceso hijo
        fork();
        printf("Process created with PID %d\n", getpid());

        // Crear un hilo en el proceso hijo
        pthread_create(&thread, NULL, thread_function, NULL);
        pthread_join(thread, NULL);  // Esperar a que el hilo termine
    }

    // Tercer fork, independiente del bloque anterior
    fork();
    printf("Process created with PID %d\n", getpid());

    // Esperar en el proceso padre para evitar la terminación temprana
    sleep(1); 

    return 0;
}
