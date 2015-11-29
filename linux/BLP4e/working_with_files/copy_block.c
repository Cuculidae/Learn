/**
 * copy_block.c
 * A second file copy program.
 * Compilation: gcc -o copy_block copy_block.c
 * Created: 2015-11-16
 */

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    /* Improve matters by copying in larger blocks.
     */
    char block[1024];
    int in, out;
    int nread;

    in = open("file.in", O_RDONLY);
    out = open("file.out", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    while ((nread = read(in, block, sizeof(block))) > 0) {
            write(out, block, nread);
    }

    exit(0);
}
