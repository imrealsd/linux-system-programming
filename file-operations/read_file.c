/**
 * Using read system call to read files
 * read() returns number of bytes read, 0 if EOF reached, -1 for error
 */

#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>


int main(void)
{
    int file_descriptor = open("./my_file.txt", O_RDWR);
    unsigned int bytes_read;
    char buff[50] = {0};

    if (file_descriptor != -1) {
        printf("File opened successfully !! File Descriptor: %d\n", file_descriptor);
    } else {
        printf("Failed to open file: Error Number: %d\n", errno);
        perror("ERROR:");
    }

    bytes_read = read(file_descriptor, buff, 35);

    if (bytes_read != 1) {
        buff[bytes_read] = '\0';
        printf("File read successfully !!\n");
        printf("Data:%s\n", buff);
    } else {
        perror("ERROR:");
    }
    return 0;
}