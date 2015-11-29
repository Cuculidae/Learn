/**
 * passwd.c
 * Scanning the password database passwd.
 * Compilation: gcc -o passwd passwd.c
 * Created: 2015-11-20
 */

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <pwd.h>
 *  #include <sys/types.h>
 *
 *  void endpwent(void);
 *  struct passwd *getpwent(void);
 *  void setpwent(void);
 * -----------------------------------------------------------------------------
 *  The getpwent function returns each user information entry in turn. When none
 *  remain, it returns a null pointer. 
 *  You can use the endpwent function to terminate processing once sufficient 
 *  entries have been scanned.
 *  The setpwent function resets the position in the password file to the start
 *  so that a new scan can be started with next call to getpwent.
 */

int main()
{
    struct passwd *pw;

    while (pw = getpwent()) {
        printf("%s:x:%d:%d:%s:%s:%s\n",
                pw->pw_name, pw->pw_uid, pw->pw_gid, 
                pw->pw_dir, pw->pw_gecos, pw->pw_shell);
    }
    endpwent();

    exit(0);
}
