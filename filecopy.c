#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <printf.h> // included to use printf statements for prompts
//You may also add more include directives as well.

// THIS VALUE CANNOT BE CHANGED.
// You should use this value when creating your buffer.
// And also to limit the amount of bytes each read CAN do.
#define BUFF_MAX 21
// ABOVE VALUE CANNOT BE CHANGED //



int
main(int argc, char const *argv[])
{
    char buffer[BUFF_MAX];

    // char arrays for file names
    // in slack channel, it was said that filenames
    // at most 255 bytes, and paths 4096 bytes
    char sourceFile[255];
    char destFile[255];

    // open(const char *pathname, int flags, mode_t mode): int
    // creat(const char *pathname, mode_t mode): int
    // creat same as open() w/ flags O_CREAT | O_WRONLY | O_TRUNC
    // store in variables below for source & destination
    // -1 is returned if error occurred
    int sourceFileDescriptor;
    int destFileDescriptor;

    // will use file descriptor in read command
    // read(int fd, void *buf, size_t count)
    // returns ssize_t: -1 if not success, # of bytes if success
    //                  0 means end of file, so while loops quits
    // fd is file descriptor
    // *buf is buffer
    // count is the size of buffer

    // write(int fd, const void *buf, size_t count): ssize_t
    // writes up to # of bytes represented by count from buf
    // starting at buf to file descriptor fd
    // on success, # of bytes written returned
    // 0 if none, on err, -1; set errno
    printf("Welcome to the File Copy Program by Stephanie Sechrist!\n");
    printf("Enter the name of the file to copy from: \n");
    scanf("%s", sourceFile);
    printf("Enter the name of the file to copy to: \n");
    scanf("%s", destFile);

//    sourceFileDescriptor = creat(sourceFile, 0666);
    sourceFileDescriptor = open(sourceFile, O_RDONLY);
    printf("source file descriptor made\n");
    if (sourceFileDescriptor < 0){
        perror("Open file to be copied failed.\n");
        return -45;
    }

    printf("source file successfully opened\n");

//    destFileDescriptor = creat(destFile, 0666);
    destFileDescriptor = open(destFile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    if (destFileDescriptor < 0){
        perror("Open file to be copied to failed.\n");
        return -45;
    }

    printf("destination file successfully opened or created\n");

    ssize_t bytesRead = read(sourceFileDescriptor, buffer, sizeof(buffer));
    printf("read success before while loop\n");

    int totalBytes = 0;
    while ( bytesRead > 0 ){
        printf("enter while loop\n");
        ssize_t bytesCopied = write(destFileDescriptor, buffer, (size_t)bytesRead);
        printf("write to dest file success\n");
        totalBytes += (size_t)bytesCopied;

        printf("total bytes copied so far: %d\n", totalBytes);

        if (bytesCopied != bytesRead){
            printf("bytes copied != bytes read\n");
            perror("There was an error during copy.\n");
            return -45;
        }

        bytesRead = read(sourceFileDescriptor, buffer, sizeof(buffer));
        printf("updated bytes read, read more of file.\n");

    }
    printf("exited while loop\n");

    if (bytesRead < 0){
        perror("Error after while loop.\n");
        return -45;
    }

    close(sourceFileDescriptor);
    printf("source file descriptor closed\n");
    close(destFileDescriptor);
    printf("destination file descriptor closed\n");

    // if gotten to this point, successful
    printf("File Copy Successful, %d bytes copied\n", totalBytes);
    return 0;
}
