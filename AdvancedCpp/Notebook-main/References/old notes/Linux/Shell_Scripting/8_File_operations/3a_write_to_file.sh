#!/bin/bash
 
LOG_FILE="../test_files/log_file.txt"

# create log file or overrite if already present
printf "Log File - " > $LOG_FILE
 
# append date to log file
date >> $LOG_FILE
 
x=$(( 3 + 1 ))
# append some data to log file
echo value of x is $x >> $LOG_FILE

#File will be created and written under path specified by LOG_FILE