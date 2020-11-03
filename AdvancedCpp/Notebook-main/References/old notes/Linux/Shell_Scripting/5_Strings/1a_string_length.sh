#!/bin/bash
 
STRING="Good morning"
LENGTH1=${#STRING}
echo "Method 1: Length of '$STRING' is $LENGTH1"

LENGTH2=`expr length "$STRING"`
echo "Method 2: Length of '$STRING' is $LENGTH2"

LENGTH3=`expr "$STRING" : '.*'`
echo "Method 3: Length of '$STRING' is $LENGTH3"