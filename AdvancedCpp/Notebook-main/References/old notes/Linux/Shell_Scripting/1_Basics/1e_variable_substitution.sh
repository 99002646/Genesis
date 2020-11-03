#!/bin/bash

<<Var1
${var}
Substitute the value of var.	
Var1

<<Var2
${var:-word}
If var is null or unset, word is substituted for var. 
The value of var does not change.
Var2

<< Var3
${var:=word}
If var is null or unset, var is set to the value of word.
Var3

<< Var4
${var:?message}
If var is null or unset, message is printed to standard error. 
This checks that variables are set correctly. 	
Var4

<< Var5
${var:+word}
If var is set, word is substituted for var. 
The value of var does not change.
Var5

echo ${var:-"Variable is not set"}
echo "1 - Value of var is ${var}"

echo ${var:="Variable is not set"}
echo "2 - Value of var is ${var}"

unset var
echo ${var:+"This is default value"}
echo "3 - Value of var is $var"

var="Prefix"
echo ${var:+"This is default value"}
echo "4 - Value of var is $var"

echo ${var:?"Print this message"}
echo "5 - Value of var is ${var}"