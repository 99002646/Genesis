#! /bin/bash
 
: '
This is an example of array in shell script
' 
i=0
LIST_OF_FILES=()
while read -r line
do
    LIST_OF_FILES[ $i ]="$line" 
    (( i++ ))
done < <(ls -ltr)
 
for fn in "${LIST_OF_FILES[@]}"
do
    echo $fn
done
