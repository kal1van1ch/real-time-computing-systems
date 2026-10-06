#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_COUNT 200

void ChildProcess(void);
void ParentProcess(void);

int main(void) {
    int pid;

    pid = fork();

    if (pid != 0) {
        ParentProcess();
    }
    else {
        ChildProcess();
    }

    return 0;
}

void ChildProcess() {
    for (int i = 0; i < MAX_COUNT; i++) {
        printf("This line is from child, value = %d\n", i);
    }
}

void ParentProcess() {
    int file = open("parent_output.txt",
                  O_WRONLY | O_CREAT | O_TRUNC,
                  0644);

    dup2(file, 1);
    close(file);

    for (int i = 0; i < MAX_COUNT; i++) {
        printf("This line is from parent, value = %d\n", i);
    }
}
