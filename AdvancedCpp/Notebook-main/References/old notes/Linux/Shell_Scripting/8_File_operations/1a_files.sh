#!/bin/bash
for p in `ls`
do
	if [ -f $p ]
	then
		echo "$p is regular file"
	elif [ -d $p ]
	then
		echo "$p is a directory"
	else
		echo "$p is a special file"
	fi
done
