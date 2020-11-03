#!/bin/sh

my_function1 () {
   echo "Inside my_function1"
   my_function2
}

my_function2 () {
   echo "Inside my_function2"
}

# Calling function one.
my_function1


: '
Function definition can be added inside .profile file
to make them available at login.
Can also source the current script using

source script
	or
. script

Once this is done, function can be called directly from shell.

To remove a function definition from shell, use
unset -f function_name
'