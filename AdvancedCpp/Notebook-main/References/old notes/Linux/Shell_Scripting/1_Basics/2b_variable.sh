#!/bin/bash
: '
Problem of not using {} with Variables
'
echo "What is your name?"
read USER_NAME
echo "Hello $USER_NAME"
echo "Create file called $USER_NAME_file"
touch $USER_NAME_file


echo "Creating another file called ${USER_NAME}_file1"
touch ${USER_NAME}_file1

echo "Creating another file called ${USER_NAME}_file1"
touch "${USER_NAME}_file2"
: ''