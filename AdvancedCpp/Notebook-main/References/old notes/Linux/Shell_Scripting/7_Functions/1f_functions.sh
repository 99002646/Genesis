#!/bin/sh

my_function()
{
  echo "my_function was called with : $@"
  x=2
}

echo "Script was called with $@"
x=1
echo "x is $x"
my_function you me and others
echo "x is $x"