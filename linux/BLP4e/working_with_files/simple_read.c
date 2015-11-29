/**
 * simple_read.c
 * The read system call.
 * Compilation: gcc -o simple_read simple_read.c
 * Created: 2015-11-16
 */

#include <unistd.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 * #include <unistd.h>
 * size_t read(int fildes, void *buf, size_t nbytes);
 * -----------------------------------------------------------------------------
 *  The read system call reads up to nbytes of data from the file associated
 *  with the file descriptor fildes and places then in the data area buf.
 *
 * Return value
 *  Returns the number of data bytes actually read, which may be less than the
 *  number requested. If a read call returns 0, it reached the end of the file.
 *  Returns -1 if an error on the call has occurred.
 */

int main()
{
    char buffer[128];
    int nread;
    
    nread = read(0, buffer, 128);
    if (nread == -1)
        write(2, "A read error has occurred\n", 26);
    if (write(1, buffer, nread) != nread)
        write(2, "A write error has occurred\n", 27);

    exit(0);
}
