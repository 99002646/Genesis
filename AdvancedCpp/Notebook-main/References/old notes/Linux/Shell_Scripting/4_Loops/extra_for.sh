#!/bin/bash
sum=0
n=10
for((i=1;$i<$n;i++))
do
	let sum=sum+$i
done
echo "sum is $sum"
