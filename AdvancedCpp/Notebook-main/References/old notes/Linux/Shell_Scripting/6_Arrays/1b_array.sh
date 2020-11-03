#!/bin/bash

echo "This is an exmaple of array in Shell"

employee=(ps_num name email_id)
echo "@Array employee is"
echo "${employee[@]}"
echo "*Array employee is"
echo "${employee[*]}"
employee[2]=address
echo 