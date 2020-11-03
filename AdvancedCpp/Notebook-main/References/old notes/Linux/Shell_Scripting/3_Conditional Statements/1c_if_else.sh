#!/bin/sh

: '
This is an example of if else condition
'
echo “How old are you\?”
read age


if [ ${age} -ge 21 ] ; then
	echo “Indian Citizens are legally allowed to Marry after 21”
else
	echo “Indian Citizens are legally not allowed to Marry before 21”
fi