#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([hello-world], [1.0], [59949011@qq.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

AC_CONFIG_SRCDIR([src/main.c])

#  the configure script to create a config.h file
# gathering ‘#define’s defined by other macros in configure.ac.
AC_CONFIG_HEADERS([config.h])

# declares the list of files that configure should create from their *.in templates
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/p1/Makefile
 src/p2/Makefile
])
# Checks for programs.
# The AC_PROG_CC line causes the configure script to search for
# a C compiler and define the variable CC with its name.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# a closing command that actually produces the part of the script in charge of
# creating the files registered with AC_CONFIG_HEADERS and AC_CONFIG_FILES.
AC_OUTPUT
