/* ***********************************
filecopy.c compiles to fc

Created By: Stephanie Sechrist
Last Modified: February 21, 2019

The program takes a file from user input
and copies into a file specified by the user
in the current working directory.
If the file to be copied to does not exist,
it is created with read and write permissions. 
If the file to be copied to does exist, it is
overwritten with the new content. 
************************************** */

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

    sourceFileDescriptor = open(sourceFile, O_RDONLY);
    // if sourceFileDescriptor negative, open of sourceFile
    // returned negative. error
    if (sourceFileDescriptor < 0){
        perror("Open file to be copied failed");
        return -45;
    }


//    destFileDescriptor = creat(destFile, 0666);
    destFileDescriptor = open(destFile, O_CREAT | O_WRONLY | O_TRUNC, 0666);
    // if destFile does not exist, it will be created.; but
    // if desteFileDescriptor negative, open of desteFile
    // returned negative. error
    if (destFileDescriptor < 0){
        perror("Open file to be copied to failed");
        return -45;
    }

    // bytesRead will contain how many bytes read from sourceFile with read
    // will be negative if read encountered an error.
    ssize_t bytesRead = read(sourceFileDescriptor, buffer, sizeof(buffer));

    int totalBytes = 0;
    // while loop makes sure read does not error
    while ( bytesRead > 0 ){
        // bytesCopied will contain how many bytes copied to destFile with write
        // will be negative if write encountered an error
        // will copy number of bytes read (cast bytesRead from signed to unsigned int)
        ssize_t bytesCopied = write(destFileDescriptor, buffer, (size_t)bytesRead);

        // keep track of totalBytes to show user
        totalBytes += (size_t)bytesCopied;

        // bytes copied should equal bytes read
        // if not, error occured during copy.
        if (bytesCopied != bytesRead){
            perror("There was an error during copy");
            return -45;
        }

        // read more of sourceFile
        bytesRead = read(sourceFileDescriptor, buffer, sizeof(buffer));

    }

    // if while loop exits because bytesRead < 0, then
    // copy not successful
    // successful copy when while loop exits when bytesRead = 0
    if (bytesRead < 0){
        perror("There was an error during copy");
        return -45;
    }

    // close file descriptors so they may be reused
    close(sourceFileDescriptor);
    close(destFileDescriptor);

    // if gotten to this point, successful
    printf("File Copy Successful, %d bytes copied\n", totalBytes);
    return 0;
}
