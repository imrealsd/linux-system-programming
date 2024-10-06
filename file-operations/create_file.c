/**
 * Using Open system call to create files with specific permission
 * Checking erros like - if file already exits
 */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>


int main(void)
{
    int file_descriptor = open("./my_file.txt", O_RDONLY|O_CREAT|O_EXCL, S_IRWXU|S_IRGRP|S_IROTH);

    if (file_descriptor != -1) {
        printf("File created successfully !! File Descriptor: %d\n", file_descriptor);
    } else {
        printf("Failed to create file: Error Number: %d\n", errno);
        perror("ERROR:");
    }
    close(file_descriptor);

    return 0;
}