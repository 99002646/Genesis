#!/bin/bash

#Replace first occurrence of substring with replacement
STRING1="to be or not to be"
echo "Line 1: ${STRING1[@]/be/eat}"


#Replace all occurrences of substring
STRING2="to be or not to be"
echo "Line 2: ${STRING2[@]//be/eat} "


#Delete all occurrences of substring (replace with empty string)
STRING3="to be or not to be"
echo "Line 3: ${STRING3[@]// not/}"


#Replace occurrence of substring if at the beginning of $STRING
STRING4="to be or not to be"
echo "Line 4: ${STRING4[@]/#to be/eat now}"


#Replace occurrence of substring if at the end of $STRING
STRING5="to be or not to be"
echo "Line 5: ${STRING5[@]/%be/eat}"


#Replace occurrence of substring with shell command output
STRING6="to be or not to be"
echo "Line 6: ${STRING6[@]/%be/be on $(date +%Y-%m-%d)}"