/**
 * printdir.c
 */

#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>


/*
 * The directory functions are declared in a header file <dirent.h>. They use a
 * structure, DIR, as a basis for directory manipulation. A pointer to this
 * structure, called a directory stream (a DIR*), acts in much the same way as a
 * file stream (FILE*) does for regular file manipulation. Directory entries
 * themselves are returned in dirent structures, also declared in <dirent.h>.
 *
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <dirent.h>
 *  DIR *opendir(const char *name);
 * -----------------------------------------------------------------------------
 *  The opendir function opens a directory and establishes a directory stream.
 *  If successful, it returns a pointer to a DIR structure. Returns null pointer
 *  on failure.
 *  Note that a directory stream uses a low-level file descriptor to access the
 *  directory itself, so opendir could fail with too many open files.
 *
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <dirent.h>
 *  struct dirent *readdir(DIR *dirp);
 * -----------------------------------------------------------------------------
 *  The readdir function returns a pointer to a structure detailing the next
 *  directory entry in the directory stream dirp. Successive calls to readdir
 *  return further directory entries. On error, and at the end of the directory,
 *  readdir returns NULL. POSIX-compliant systems leave errno unchanged when
 *  returning NULL at the end of directory and set it when an error occurs.
 *  Note that readdir scanning isn't guaranteed to list all the files (and
 *  subdirectories) in a directory if there are other processes creating and
 *  deleting files in the directory at the same time.
 *  The dirent structure containing directory entry details includes the
 *  following entries:
 *      ino_t d_ino:    The inode of the file
 *      char  d_name:   The name of the file
 *
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <dirent.h>
 *  long int telldir(DIR *dirp);
 * -----------------------------------------------------------------------------
 *  The telldir function returns a value that records the current position in a
 *  directory stream. You can use this in subsequent calls to seekdir to reset a
 *  directory scan to the current position.
 *
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <dirent.h>
 *  void seekdir(DIR *dirp, long int loc);
 * -----------------------------------------------------------------------------
 *  The seekdir function sets the directory entry pointer in the directory
 *  stream given by dirp. The value of loc, used to set the position, should
 *  have been obtained from a prior call to telldir.
 *
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <dirent.h>
 *  int closedir(DIR *dirp);
 * -----------------------------------------------------------------------------
 *  The closedir function closes a directory stream and frees up the resources
 *  associated with it. It returns 0 on success and -1 if there is an error.
 */

/* Prints the directory and recurse for subdirectories using the depth parameter
 * for indentation.
 * Each file in a directory is listed on a line by itself. Each subdirectory has
 * its name followed by a slash and the files listed in it are indented by four
 * spaces.
 */
void printdir(char *dir, int depth)
{
    DIR *dp;
    struct dirent *entry;
    struct stat statbuf;

    if ((dp = opendir(dir)) == NULL) {
        fprintf(stderr, "cannot open directory: %s\n", dir);
        return;
    }
    chdir(dir);
    while ((entry = readdir(dp)) != NULL) {
        lstat(entry->d_name, &statbuf);
        if (S_ISDIR(statbuf.st_mode)) {
            /* Found a directory, but ignore . and .. */
            if (strcmp(".", entry->d_name) == 0 ||
                strcmp("..", entry->d_name) == 0)
                continue;
            printf("%*s%s/\n", depth, "", entry->d_name);
            /* Recurse at a new indent level */
            printdir(entry->d_name, depth+4);
        }
        else printf("%*s%s\n", depth, "", entry->d_name);
    }
    chdir("..");
    closedir(dp);
}

int main(int argc, char* argv[])
{
    char *topdir = ".";
    if (argc >= 2)
        topdir = argv[1];

    printf("Directory scan of %s\n", topdir);
    printdir(topdir, 0);
    printf("done.\n");

    exit(0);
}
