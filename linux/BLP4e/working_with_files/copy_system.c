/**
 * copy_system.c
 * A file copy program.
 * Compilation: gcc -o copy_system copy_systerm.c
 * Created: 2015-11-16
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

/* Note that the #include <unistd.h> line must come first, because it defines
 * flags regarding POSIX compliance that may affect other include files.
 *
 * When a program starts, it usually has three of these descriptors already
 * opened:
 *  0: Standard input
 *  1: Standard output
 *  2: Standard error
 * You can associate other file descriptors with files and devices by using the
 * open system call.
 *
 * When a program exits, all open file descriptors are automatically closed, so
 * you don't need to close them explicitly. This won't be the case, however,
 * when you're dealing with buffered output.
 */

int main()
{
    // copy one file to another, character by character
    // assume that the input file exists and the output  file dose not.
    char c;
    int in, out;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    while (read(in, &c, 1) == 1)
        write(out, &c, 1);  // a lot of system calls, consume virtually all the CPU time

    exit(0);
}
