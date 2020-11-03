#!/bin/bash
echo "This is a example for Arithmetic in Shell"

echo "Enter number1"
read num1
echo "Enter number1"
read num2

echo "$num1+$num2= `expr $num1 + $num2`"
echo "$num1-$num2= `expr $num1 - $num2`"
echo "$num1*$num2= `expr $num1 \* $num2`"

echo "expr => $num1/$num2= `expr $num1 / $num2`"

let l_div=$num1/$num2
echo "let  => $num1/$num2= $l_div"

bc_div=`echo "scale=2; $num1 / $num2" | bc`
echo "bc   => $num1/$num2= $bc_div"

posix_div=$(($num1/$num2))

echo "posix   => $num1/$num2= $posix_div"

exit 0