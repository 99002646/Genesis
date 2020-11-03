#!/bin/bash
INPUT="$1"
# counter 
a_count=0
b_count=0
c_count=0
 
# Make sure file name supplied
[ $# -eq 0 ] && { echo "Usage: $0 filename"; exit 1; }
 
# Make sure file exits else exit 
[ ! -f $INPUT ] && { echo "$0: file $INPUT not found."; exit 2; }
 
# the while loop, read one char at a time
while IFS= read -r -n1 c
do
	# counter letter a, b, c
	[ "$c" == "a" ] && (( a_count++ ))
	[ "$c" == "b" ] && (( b_count++ ))
	[ "$c" == "c" ] && (( c_count++ ))
done < "$INPUT"
 
echo "Letter counter stats:"
echo "a = $a_count"
echo "b = $b_count"
echo "c = $c_count"