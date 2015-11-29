/**
 * simple_write.c
 * The write system call.
 * Compilation: gcc -o simple_write simple_write.c
 * Created: 2015-11-16
 */



#include <unistd.h>
#include <stdlib.h>


/*
 * -----------------------------------------------------------------------------
 * #include <unistd.h>
 * size_t write(fildes, const void *buf, size_t nbytes);
 * -----------------------------------------------------------------------------
 *  Writes the first <nbytes> bytes from buf to the file associated with the
 *  file descriptor fildes.
 *
 * Return value
 *  Returns the number of bytes actually written. This may be less than <nbytes>
 *  if there has been an error in the file descriptor or if the underlying
 *  device driver is sensitive to block size. If the function returns 0, it
 *  means no data was written.
 *  Returns -1 if there has been an error in the write call, and the error will
 *  be specified in the errno global variable.
 * Note
 *  It is not necessarily an error if write report that it wrote fewer bytes
 *  than you asked it to.
 */

int main()
{
    if (write(1, "Here is some data\n", 18) != 18)
        write(2, "A write error has occurred on file descriptor 1\n", 46);

    exit(0);
}
