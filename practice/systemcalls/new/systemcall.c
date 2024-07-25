#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
 
int main() {
    int fd, n;
    char buffer[BUFFER_SIZE];
    // Open the file in read-write mode
    fd = open("input.txt", O_RDWR);
    if (fd == -1) {
        printf("Error opening file");
        return 1;
    }
    // Read from the file
    while ((n = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        for (int i = 0; i < n; i++) 
        {
            if (isupper(buffer[i])) 
            {
                buffer[i] = tolower(buffer[i]);
            }
        }
        // Set the file pointer to the beginning of the file
        lseek(fd, -n, SEEK_CUR);
        // Write back to the file
        if (write(fd, buffer, n) != n) 
        {        
            printf("Error writing to file");
            return 1;
        }
    }
    // Close the file
    if (close(fd) == -1) {
        printf("Error closing file");
        return 1;
    }
    printf("File contents modified successfully!\n");
    return 0;
}
