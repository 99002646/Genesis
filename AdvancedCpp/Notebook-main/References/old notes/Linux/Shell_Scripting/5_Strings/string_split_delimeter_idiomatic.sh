#!/bin/bash
 
str="LearnABCtoABCSplitABCaABCString"
delimiter=ABC
s=$str$delimiter
array=();
while [[ $s ]]; do
    array+=( "${s%%"$delimiter"*}" );
    s=${s#*"$delimiter"};
done;
declare -p array
