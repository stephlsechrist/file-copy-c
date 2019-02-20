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
    char sizeOf[BUFF_MAX];

    // char arrays for file names
    // in slack channel, it was said that filenames
    // at most 255 bytes, and paths 4096 bytes
    char sourceFile[255];
    char destinationFile[255];

    printf("Welcome to the File Copy Program by Stephanie Sechrist!");
    printf("Enter the name of the file to copy from: ");
    scanf("%s", sourceFile);
    printf("Enter the name of the file to copy to: ");
    scanf("%s", destinationFile);


    // needs conditional and TBD to be changed
    printf("File Copy Successful, %d bytes copied", TBD);
    return 0;
}
