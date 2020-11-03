#!/bin/sh
: '
Looping/ Shifting through the Arguments passed
'
while [ "$#" -gt "0" ]
do
  echo "Argument is $1"
  shift
done 