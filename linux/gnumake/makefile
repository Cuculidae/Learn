# Any variable set in the environment when GNU make is started will be available
# as a GNU make variable inside the makefile.
$(info $(FOO))	# output foo if FOO is set in the environment to foo

$(info $(FOO) $(origin FOO))	# possible output foo environment

# A varaible imported from the environment can be overridden inside the makefile
FOO=bar
$(info $(FOO) $(origin FOO))	# output bar file

# It's possible to prevent a definition in a makefile from overriding the
# environment by specifying the -e option on the command line of GNU make.

# override directive
# Guarantee that the variable gets its value inside the makefile 
override FOO=bar
$(info $(FOO) $(origin FOO))	# ouput bar override

# The override directive beats the command line,
# which beats environment overrides ( the -e option),
# which beats variables defines in a makefile,
# which beats the original environment.
