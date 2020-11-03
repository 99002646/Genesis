#!/bin/sh
#Comment

echo "Multi line comments"

echo "Line 1"

: '
This is a method of multi line comment
echo "Line 2"
echo "Line 3"
echo "Line 4"
'
echo "Line 5"

<<Anything
This is another method of multi line comment
echo "Line 6"
echo "Line 7"
echo "Line 8"
Anything

echo "Line 9"