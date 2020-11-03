#!/bin/sh

my_function () 
{
   echo "Params are: $1 $2"
   return 10
}

my_function Hi Hello

echo "Return value is $?"