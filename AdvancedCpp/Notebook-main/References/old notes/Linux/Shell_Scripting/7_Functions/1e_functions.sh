#!/bin/bash
 
# override 'echo' command to add date and time 
echo () {
    builtin echo -n `date +"[%m-%d %H:%M:%S]"` ": "
    builtin echo $1
}
builtin echo "This is an example of function override"
echo "This is output from overridden function"
