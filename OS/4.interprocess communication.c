#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"

int main() {
    
    mkfifo(FIFO_FILE, S_IRUSR | S_IWUSR);

    
    if (fork() == 0) {
        int fd = open(FIFO_FILE, O_WRONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        
        char message[] = "Hello from the writer process!";
        write(fd, message, sizeof(message));

        
        close(fd);

        exit(EXIT_SUCCESS);
    }

    
    else {
        int fd = open(FIFO_FILE, O_RDONLY);
        if (fd == -1) {
            perror("open");
            exit(EXIT_FAILURE);
        }

        
        char buffer[100];
        read(fd, buffer, sizeof(buffer));
        printf("Reader Process: Received message - %s\n", buffer);

        
        close(fd);

        
        unlink(FIFO_FILE);

        exit(EXIT_SUCCESS);
    }

    return 0;
}