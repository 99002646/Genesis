#!/bin/sh


count=10
i=20
 
# until loop with single condition
until [ $i -lt $count ]; do
   echo "Count = $i"
   let i--
done



a=0
until [ ! $a -lt 10 ]
do
   echo "A = $a"
   a=`expr $a + 1`
done
