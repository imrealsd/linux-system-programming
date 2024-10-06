/**
 * Using lseek() to move cursor
 */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(void)
{   
    // Create a file and write
    int file_descriptor = open("./my_file.txt", O_RDWR|O_CREAT|O_EXCL, S_IRWXU|S_IRGRP|S_IROTH);

    // Append to an existing file
    // int file_descriptor = open("./my_file.txt", O_RDWR|O_APPEND, S_IRWXU|S_IRGRP|S_IROTH);

    char write_buff[100] = "Linux System Programming\n";
    char read_buff[100] = {0};
    __ssize_t bytes;
    off_t offset;

    if (file_descriptor != -1) {
        printf("File created successfully !! File Descriptor: %d\n", file_descriptor);
    } else {
        printf("Failed to create file: Error Number: %d\n", errno);
        perror("ERROR:");
    }

    bytes = write(file_descriptor, write_buff, strlen(write_buff));

    if (bytes != -1) {
        printf("%lu bytes written successfully !!\n", bytes);
    } else {
        printf("Error Number:%d\n", errno);
        perror("ERROR");
    }

    offset = lseek(file_descriptor, 6, SEEK_SET);
    bytes = read(file_descriptor, read_buff, 6);

    if (bytes != 1) {
        printf("File Read Successfully !!\n");
        printf("Data: %s\n", read_buff);
    }

    close(file_descriptor);
    
    return 0;
}