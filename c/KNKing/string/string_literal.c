/**
 * Chapter 13 String
 * string_literal.c
 * Demonstrate how the compiler process string literal
 * Compilation: gcc -E string_literal.c
 * Created: 2015-08-27
 */

/* string literals are not modifiable */

char *p = "one";
char name[5] = "two";

void f(void)
{
    char *p = "three";
    char name[5] = "four";
}
