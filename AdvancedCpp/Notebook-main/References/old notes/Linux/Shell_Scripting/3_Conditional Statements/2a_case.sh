#!/bin/bash
 
time=12
 
# if condition is true
case $time in
	9) echo Good Morning! ;;
	12) echo Good Noon!    ;;
	17) echo Good Evening! ;;
	21) echo Good Night!   ;;
	*)  echo Good day	;;
esac
