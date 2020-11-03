#!/bin/bash

#Appending str2 to str1. [str1 = str1 + str2]
str1="Learn"
str2=" Bash Scripting"
str1+=$str2
echo $str1

#Keep two string variables side by side
str1="Learn"
str2=" Bash Scripting"
str3=$str1$str2
echo $str3

#Use a string variable in another string
str1="Learn"
str2="$str1 Bash Scripting"
echo $str2

num=100
str1="Learn"
str2="$str1 Bash Scripting:$num"

echo $str2
