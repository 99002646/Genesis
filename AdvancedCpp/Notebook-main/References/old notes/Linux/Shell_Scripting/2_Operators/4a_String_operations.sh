#!/bin/sh

: '
String Operators
=        ==> Check if Strings are Equal 
!=       ==> Check if Strings are Not Equal 
-z       ==> Check if supplied string size is zero
-n       ==> Check if supplied string size is non zero 
string   ==> Checks if string is empty
'
a=""
b="efg"

if [ $a = $b ]
then
   echo "$a = $b : a is equal to b"
else
   echo "$a = $b: a is not equal to b"
fi

if [ $a != $b ]
then
   echo "$a != $b : a is not equal to b"
else
   echo "$a != $b: a is equal to b"
fi

if [ -z $a ]
then
   echo "-z $a : string length is zero"
else
   echo "-z $a : string length is not zero"
fi

if [ -n $a ]
then
   echo "-n $a : string length is not zero"
else
   echo "-n $a : string length is zero"
fi

if [ $a ]
then
   echo "$a : string is not empty"
else
   echo "$a : string is empty"
fi