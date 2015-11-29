bill.o: bill.c
	gcc -c bill.c
fred.o: fred.c
	gcc -c fred.c


# create static library
# A library filename always starts with lib. Then follows the part indicating
# what library this is (like c for the C library, or m for the mathematical
# library). The last part of the name starts with a dot(.), and specifies the
# type of the library:
# 	.a for tranditional, static libraries
# 	.so for shared libraries
libfoo.a: bill.o fred.o
	ar crv libfoo.a bill.o fred.o	# use ar program to create a static library 
	ranlib libfoo.a					# create a table of contents (not necessary in Linux)

# create the program
program: program.c libfoo.a
	gcc -o program program.c -L. -lfoo	#
