# CSC 415 - Project 2 - File copy

## Student Name : Stephanie Sechrist

## Student ID   : 918679078

## Build Instructions

## Run Instructions

## strace/dtruss output (annotation surrounded by ** [NOTE] **
```
csc415@csc415:~/Documents/HW2/csc415-p2-stephlsechrist$ strace ./fc
execve("./fc", ["./fc"], 0x7ffdf653c8c0 /* 49 vars */) = 0
        ** execve() executes ./fc. no error **
brk(NULL)                               = 0x55e1f04b5000
        ** returns address where heap memory ends **
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
        ** accdg to slack, typical error; trying to access library **
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
        ** accdg to slack, typical error; trying to access library **
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
        ** opens file relative to working directory; attaches to file descriptor (fd) 3 **
fstat(3, {st_mode=S_IFREG|0644, st_size=99351, ...}) = 0
        ** successfully receive info about file specified by fd 3 **
mmap(NULL, 99351, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7fb6a0bc3000
        ** kernel choosing address to map fd 3 to virtual address space of calling process; set to read ** 
        ** returns pointer (memory adress) to mapped area **
close(3)                                = 0
        ** close fd 3; releases 3 to be reused as different fd **
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
        ** accdg to slack, typical error; trying to access library **
openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
        ** opens file relative to working directory; attaches to fd 3 **
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\260\34\2\0\0\0\0\0"..., 832) = 832
        ** read 832 bits from fd 3 **
fstat(3, {st_mode=S_IFREG|0755, st_size=2030544, ...}) = 0
        ** successfully receive info about file specified by fd 3 **
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7fb6a0bc1000
        ** kernel choosing address to map fd errors to virtual address space of calling process?; set to read and write ** 
        ** returns pointer (memory adress) to mapped area **
        ** not sure what file descriptor -1 is **
mmap(NULL, 4131552, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7fb6a05c4000
        ** kernel choosing address to map fd 3 to virtual address space of calling process; set to read and execute ** 
        ** returns pointer (memory adress) to mapped area **
mprotect(0x7fb6a07ab000, 2097152, PROT_NONE) = 0
        ** successfully change access protection at mem address specified so memory cannot be accessed at all **
mmap(0x7fb6a09ab000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1e7000) = 0x7fb6a09ab000
        ** map fd 3 to address just protected; set to read and write; MAP_PRIVATE does not allow changed to ** 
        ** carry to underlying file; returns pointer (memory adress) to mapped area **
mmap(0x7fb6a09b1000, 15072, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7fb6a09b1000
        ** map error to address specified? not sure what file descriptor -1 is **
close(3)                                = 0
        ** close fd 3; releases 3 to be reused as different fd **
arch_prctl(ARCH_SET_FS, 0x7fb6a0bc2500) = 0
        ** set 64-bit base for FS register to specified address **
mprotect(0x7fb6a09ab000, 16384, PROT_READ) = 0
        ** successfully change access protection at mem address specified so memory can be read **
mprotect(0x55e1ee4ca000, 4096, PROT_READ) = 0
        ** successfully change access protection at mem address specified so memory can be read **
mprotect(0x7fb6a0bdc000, 4096, PROT_READ) = 0
        ** successfully change access protection at mem address specified so memory can be read **
munmap(0x7fb6a0bc3000, 99351)           = 0
        ** unmap at memory address for length specified **
fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
        ** retrieves stat structure about stdout (fd 1)**
brk(NULL)                               = 0x55e1f04b5000
        ** returns address where heap memory ends **
brk(0x55e1f04d6000)                     = 0x55e1f04d6000
        ** changes location of program break, defining end of process's data segment at this mem address **
        ** successfully allocates memory to the process **
write(1, "Welcome to the File Copy Program"..., 56Welcome to the File Copy Program by Stephanie Sechrist!
) = 56
        ** writes message of 56 bytes to stdout (specified by fd 1) **
write(1, "Enter the name of the file to co"..., 42Enter the name of the file to copy from: 
) = 42
        ** writes message of 42 bytes to stdout (specified by fd 1) **
fstat(0, {st_mode=S_IFCHR|0620, st_rdev=makedev(136, 0), ...}) = 0
        ** retrieves stat structure about stdin (fd 0) **
read(0, README.MD
"README.MD\n", 1024)            = 10
        ** reads 10 bytes from stdin (out of 1024 possible bytes) **
write(1, "Enter the name of the file to co"..., 40Enter the name of the file to copy to: 
) = 40
        ** writes message of 40 bytes to stdout **
read(0, readMeTest
"readMeTest\n", 1024)           = 11
        ** reads 11 bytes from stdin **
openat(AT_FDCWD, "README.MD", O_RDONLY) = 3
        ** opens file relative to working directory; attaches to fd 3 as read only**
openat(AT_FDCWD, "readMeTest", O_WRONLY|O_CREAT|O_TRUNC, 0666) = 4
        ** opens file relative to working directory; attaches to fd 4 as write only **
        ** if file doesn't exist, creates it with given permissions **
        ** if file has content, truncates it to length 0 **
        
        ** what follows is the reading of the source file and the writing **
        ** to the destination file **
        ** reads from fd 3, writes to fd 4 **
        ** buffer size specified in project is 21 bytes, so does up to 21 bytes until **
        ** read gets to end **
        ** write will write same bytes that were read **
read(3, "# CSC 415 - Project 2", 21)    = 21
write(4, "# CSC 415 - Project 2", 21)   = 21
read(3, " - File copy\r\n\r\n## St", 21) = 21
write(4, " - File copy\r\n\r\n## St", 21) = 21
read(3, "udent Name : Stephani", 21)    = 21
write(4, "udent Name : Stephani", 21)   = 21
read(3, "e Sechrist\n\r\n## Stude", 21) = 21
write(4, "e Sechrist\n\r\n## Stude", 21) = 21
read(3, "nt ID   : 918679078\r\n", 21)  = 21
write(4, "nt ID   : 918679078\r\n", 21) = 21
read(3, "\r\n## Build Instructio", 21)  = 21
write(4, "\r\n## Build Instructio", 21) = 21
read(3, "ns\r\n\r\n## Run Instruct", 21) = 21
write(4, "ns\r\n\r\n## Run Instruct", 21) = 21
read(3, "ions\r\n\r\n## strace/dtr", 21) = 21
write(4, "ions\r\n\r\n## strace/dtr", 21) = 21
read(3, "uss output\r\n", 21)           = 12
write(4, "uss output\r\n", 12)          = 12
read(3, "", 21)                         = 0
        ** read has reached end and returns 0 for 0 bytes read **
close(3)                                = 0
        ** close fd 3; releases 3 to be reused as different fd **
close(4)                                = 0
        ** close fd 4; releases 4 to be reused as different fd **
write(1, "File Copy Successful, 180 bytes "..., 39File Copy Successful, 180 bytes copied
) = 39
        ** write message of 39 bytes to stdout **
lseek(0, -1, SEEK_CUR)                  = -1 ESPIPE (Illegal seek)
        ** accdg to slack, typical error; stdin (fd 0) is associated with a pipe **
exit_group(0)                           = ?
        ** exits all threads in process **
+++ exited with 0 +++

csc415@csc415:~/Documents/HW2/csc415-p2-stephlsechrist$ strace -c ./fc
Welcome to the File Copy Program by Stephanie Sechrist!
Enter the name of the file to copy from: 
README.MD
Enter the name of the file to copy to: 
readMeTest
File Copy Successful, 180 bytes copied
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
  0.00    0.000000           0        13           read
  0.00    0.000000           0        13           write
  0.00    0.000000           0         4           close
  0.00    0.000000           0         4           fstat
  0.00    0.000000           0         1         1 lseek
  0.00    0.000000           0         5           mmap
  0.00    0.000000           0         4           mprotect
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         3           brk
  0.00    0.000000           0         3         3 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           arch_prctl
  0.00    0.000000           0         4           openat
------ ----------- ----------- --------- --------- ----------------
100.00    0.000000                    57         4 total
```


