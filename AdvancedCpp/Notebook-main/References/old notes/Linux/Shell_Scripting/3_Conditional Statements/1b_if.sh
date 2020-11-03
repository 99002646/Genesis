#!/bin/sh
: '
This is an example of if condition
'
a=10
b=20

if test $a != $b
then 
	echo a equal to b
fi

if [ $a == $b ]
then
   echo "a is equal to b"
fi

if [[ $a != $b ]]
then
   echo "a is not equal to b"
fi