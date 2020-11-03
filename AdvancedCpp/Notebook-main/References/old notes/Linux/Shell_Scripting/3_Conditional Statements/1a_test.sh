#!/bin/bash

: '
This is an example uasage of test command
'
NAME=Bengaluru

test $NAME = "Bengaluru"
echo "Test1 command status = $?"

test $NAME = "Delhi"
echo "Test2 command status = $?"

test $NAME = Bengaluru && echo "Name is Bengaluru"

[ $NAME = Delhi ] || echo "Name is not Delhi"

if [ $NAME = Delhi ]
then 
	echo "Again Name is not Delhi"
fi