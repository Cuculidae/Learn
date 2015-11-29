/**
 * open_close.c
 * The open and close system call.
 * Compilation: gcc -o open_close open_close.c
 * Created: 2015-11-16
 */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 * #include <fcntl.h>
 * #include <sys/types.h>
 * #include <sys/stat.h>
 * int open(const char *path, int oflags);
 * int open(const char *path, int oflags, mode_t mode);
 * -----------------------------------------------------------------------------
 *  Strictly speaking, you don't need to include <sys/types.h> and <sys/stat.h>
 *  to use open on systems that comply with POSIX standards, but they may be
 *  necessary on some UNIX systems.
 *
 * Parameters
 *  The name of the file or device to be opened is passed as a parameter, path.
 *  The oflags are specified as a combination of a mandatory file access mode
 *  and other optional modes.
 *  Mandatory file access mode:
 * -----------------------------------------------------------------------------
 *  O_RDONLY    Open for read-only
 *  O_WRONLY    Open for write-only
 *  O_RDWR      Open for reading and writing
 * -----------------------------------------------------------------------------
 *  Optional modes:
 * -----------------------------------------------------------------------------
 *  O_APPEND    Place written data at the end of the file
 *  O_TRUNC     Set the length of the file to zero, discarding existing contents
 *  O_CREAT     Creates the file, if necessary, with permissions given in mode.
 *  O_EXCL      Used with O_CREAT, ensures that the caller creates the file. The
 *              open is atomic; if the file exists, open will fail.
 * -----------------------------------------------------------------------------
 *  When you create a file using the O_CREAT flag with open, you must use the
 *  three parameter-form. mode, the third parameter, specifies the initial
 *  permission of the file created.
 *  There are a couple of factors that may affect the file permissions. First,
 *  the permissions specified are used only if the file is being created.
 *  Second, the user mask (specified by the shell's umask command) affects the
 *  created file's permissions. The mode value given in the open call is ANDed
 *  with the inverse of the user mask value at runtime.
 * -----------------------------------------------------------------------------
 *  Defined in header <sys/stat.h>
 *  S_IRUSR     Read permission, owner
 *  S_IWUSR     Write permission, owner
 *  S_IXUSR     Execute permission, owner
 *  S_IRGRP     Read permission, group
 *  S_IWGRP     Write permission, group
 *  S_IXGRP     Execute permission, group
 *  S_IROTH     Read permission, other
 *  S_IWOTH     Write permission, other
 *  S_IXOTH     Execute permission, other
 * -----------------------------------------------------------------------------
 * Return value
 *  If successful, it returns a file descritor which is unique and isn't shared
 *  by any other processes that may be running. If two programs have a file open
 *  at the same time, they maintain distinct file descriptors and their data
 *  will overwrite each other. You can prevent unwanted clashes of this sort by
 *  using file locking. The new file descriptor is always nonnegative and is 
 *  always the lowest-numbered unused descriptor.
 *  If it fails, return -1 and sets the global variable errno.
 * Note
 *  There is also a creat call standarlized by POSIX, but it is not often used.
 *  creat doesn't only create the file, as one might expect, but also opens it.
 *  It is the equivalent of calling open with oflags equal to
 *  O_CREAT|O_WRONLY|O_TRUNC.
 *  The number of files that any one running program may have open at once is
 *  limited. The limit, usually is defined by the constant OPEN_MAX in limits.h,
 *  varies from system to system, but POSIX requires that it be at least 16.
 *  This limit may itself be subject to local system-wide limits so that a
 *  program may not always be able to open this many files. On Linux, the limit
 *  may be changed at runtime so OPEN_MAX is not a constant. It typically starts
 *  out at 256.
 *
 *
 * -----------------------------------------------------------------------------
 *  #include <unistd.h>
 *  int close(int fildes);
 * -----------------------------------------------------------------------------
 *  close terminate the association between a file descriptor, fildes, and its
 *  file. The file descriptor becomes available for reuse. It returns 0 if
 *  successful and -1 on error.
 *  Note that it can be important to check the return result from close. Some
 *  file systems, particularly networked ones, may not report an error writing
 *  to a file until the file is closed, because data may not have been confirmed
 *  as written when writes are performed.
 */

int main()
{
    exit(0);
}
