#!/bin/sh
#Thie is how variables can be declared in shell
MY_MESSAGE="Hello World"
MY_SHORT_MESSAGE=hi
MY_NUMBER=1
MY_PI=3.142
MY_OTHER_PI="3.142"
MY_MIXED=123abc

MY_MESSAGE="Hello There!, What's your name?"
#Try without double quotes in the above line and observe what happens
echo $MY_MESSAGE
read NAME
echo "Welcome to shell scripting, $NAME"
