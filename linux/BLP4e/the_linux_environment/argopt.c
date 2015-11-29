/**
 * argopt.c
 * Compilation: gcc -o argopt argopt.c
 * Created: 2015-11-19
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
 * -----------------------------------------------------------------------------
 *  #include <unistd.h>
 *  int getopt(int argc, char *const argv[], const char *optstring)
 *  extern char *optarg;
 *  extern int opind, opterr, optopt;
 * -----------------------------------------------------------------------------
 *  The parameter argc and argv are the argument count and argument array as
 *  passed to main(). The argument optstring is simply a list of characters,
 *  each representing a single character option. If a character is followed by a
 *  colon, it indicates that the option has an associted value that will be
 *  taken as the next argument.
 *
 *  The variable optind is the index of the next element of the argv[] array
 *  vector to be processed. It shall be initialized to 1 by the system.
 *
 *  The return result for getopt is the next option character found in the argv
 *  array (if there is one).
 *   # If the option takes a value, that value is pointed to by the external
 *     variable optarg.
 *   # getopt returns -1 when there are no more options to process. A special
 *     argument, --, will cause getopt to stop scanning for options.
 *   # getopt returns ? if there is an unrecognized option, which it stores in
 *     the external variable optopt.
 *   # If an option requires a value and no value is given, getopt normally
 *     returns ?. By placing a colon as the first character of the options
 *     string, getopt returns : instead of ? when no value is given.
 *
 * Posix versions of getopt will stop at the first non-option argument,
 * returning -1 and setting optind. Linux version of getopt can process options
 * wherever they occur in the program arguments. Note that, in this case, getopt
 * effectively rewrites the argv array so that all of the non-option arguments
 * are presented together, starting at argv[optind]. For the GNU version of
 * getopt, this behavior is controlled by the POSIXLY_CORRECT environment
 * variable.
 */

int main(int argc, char *argv[])
{
    int opt;

    while ((opt = getopt(argc, argv, ":if:lr")) != -1) {
        switch (opt) {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("filename: %s\n", optarg);
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }
    for (; optind < argc; optind++) 
        printf("argument: %s\n", argv[optind]);

    exit(0);
}
