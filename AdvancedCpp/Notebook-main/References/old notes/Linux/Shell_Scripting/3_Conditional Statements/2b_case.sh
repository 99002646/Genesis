#!/bin/bash
echo "enter a day value"
read day

case $day in
	1|s|"sun") echo "sunday";
	   echo "holiday";;
	2|m|"mon") echo "monday"; echo "work starts";;
	3) echo "tuesday"; date ;;
	4) echo "wednesday";;
	5) echo "thursday";;
	6) echo "friday";;
	7) echo "saturday";;
	*) echo "invalid option";;
esac
