/**
 * Using Open system call to open existing files
 * Pritning file descriptors if opening is success else printing erros like -
 * file not exists, permission denied e.t.c
 */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>


int main(void)
{
    int file_descriptor = open("./my_file.txt", O_RDWR);

    if (file_descriptor != -1) {
        printf("File opened successfully !! File Descriptor: %d\n", file_descriptor);
    } else {
        printf("Failed to open file: Error Number: %d\n", errno);
        perror("ERROR:");
    }

    return 0;
}