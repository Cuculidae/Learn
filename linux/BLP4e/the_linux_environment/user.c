/**
 * user.c
 * Program which extracts some user information from the password database.
 * Compilation: gcc -o user user.c
 * Created: 2015-11-20
 */

#include <sys/types.h>
#include <pwd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <unistd.h>
 *  uid_t getuid(void);
 *  char *getlogin(void);
 * -----------------------------------------------------------------------------
 *  The getuid function returns the UID with which the program is associated.
 *  This is usually the UID of the user who started the program.
 *  The getlogin() function returns the login name associated with ther current
 *  user.
 *
 * -----------------------------------------------------------------------------
 *  #include <sys/types.h>
 *  #include <pwd.h>
 *  struct passwd *getpwuid(uid_t uid);
 *  struct passwd *getpwnam(const char *name);
 * -----------------------------------------------------------------------------
 *  The password database structure, passwd, defined in pwd.h includes the
 *  following members:
 *  ............................................................................
 *   char *pw_name      The user's login name
 *  ............................................................................
 *   uid_t pw_uid       The UID number
 *  ............................................................................
 *   gid_t pw_gid       The GID number
 *  ............................................................................
 *   char *pw_dir       The user's home directory
 *  ............................................................................
 *   char *pw_gecos     The user's full name
 *  ............................................................................
 *   char *pw_shell     The user's default shell
 *  ............................................................................
 * Some Unix systems may use a different name for the field for the user's full
 * name: on some systems, it's pw_gecos, as on Linux, and on others, it's
 * pw_comment. This means that we can't recommend its use.
 *
 * The getpwuid and getpwnam functions both return a pointer to a passwd
 * structure corresponding to a user. The user is identified by UID for getpwuid
 * and by login name for getpwnam. The both return a null pointer and set errno
 * on error.
 */

int main()
{
    uid_t uid;
    gid_t gid;

    struct passwd *pw;
    uid = getuid();
    gid = getuid();

    printf("User is %s\n", getlogin());

    printf("User IDs: uid=%d, gid=%d\n", uid, gid);

    pw = getpwuid(uid);
    printf("UID passwd entry:\n name=%s, uid=%d, gid=%d, home=%s, shell=%s\n",
            pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);

    pw = getpwnam("root");
    if (pw) {
        printf("root passwd entry:\n");
        printf("name=%s, uid=%d, gid=%d, home=%s, shell=%s\n",
                pw->pw_name, pw->pw_uid, pw->pw_gid, pw->pw_dir, pw->pw_shell);
    }
    else {
        fprintf(stderr, "root user doesn't exist\n");
    }

    exit(0);
}
