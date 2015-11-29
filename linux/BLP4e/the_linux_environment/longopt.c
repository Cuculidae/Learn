/**
 * longopt.c
 * GNU extension getopt_long.
 * Compilation: gcc -o longopt longopt.c
 * Created: 2015-11-19
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define _GNU_SOURCE
#include <getopt.h>

/*
 * The GNU C library contains a version of getopt called getopt_long that
 * accepts so-called long arguments that are introduced with a double dash.
 * -----------------------------------------------------------------------------
 *  #define _GNU_SOURCE
 *  #include <getopt.h>
 *  int getopt_long(int argc, char *argv[], const char *optstring,
 *                  const struct option *longopts, int *longindex);
 * -----------------------------------------------------------------------------
 *  struct option {
 *      const char *name;
 *      int has_flag;
 *      int *flag;
 *      int val;
 *  };
 *  ............................................................................
 *  name    The name of the long option. Abbreviations will be accepted as long
 *          as they cannot be confused with other options.
 *  has_arg Whether this option takes an argument. Set to 0 for options that do
 *          not take an argument, 1 for options that must have a value, and 2
 *          for those that have an optional argument.
 *  flag    Set to NULL to have getopt_long return the value given in val when
 *          this option is found. Otherwise, getopt_long returns 0 and writes
 *          the value of val into the variable pointed by flag.
 *  val     The value getopt_long is to return for this option.
 *  ............................................................................
 * 
 *
 * Both the long options and the original single character options can be mixed.
 * As long as they remain distinguishable, long options can be abbreviated. Long
 * options that take an argument can be given as a single in the form
 * --option=value.
 */

int main(int argc, char *argv[])
{
    int opt;
    struct option longopts[] = {
        {"initialize", 0, NULL, 'i'},
        {"file", 1, NULL, 'f'},
        {"list", 0, NULL, 'l'},
        {"restart", 0, NULL, 'r'},
        {0,0,0,0}};

    while ((opt = getopt_long(argc, argv, ":if:lr", longopts, NULL)) != -1) {
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
    for (; optind < argc; ++optind)
        printf("argument: %s\n", argv[optind]);

    exit(0);
}
