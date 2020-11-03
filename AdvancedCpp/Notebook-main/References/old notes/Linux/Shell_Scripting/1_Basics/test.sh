#! /bin/bash
 
echo Welcome to learn Bash Scripting.
 
echo For an example we shall list files in the current directory
 
i=0
array=()
while read -r line
do
    array[ $i ]="$line" 
    (( i++ ))
done < < (ls -lt)
 
for fn in "${array[@]}"
do
    echo $fn
done
