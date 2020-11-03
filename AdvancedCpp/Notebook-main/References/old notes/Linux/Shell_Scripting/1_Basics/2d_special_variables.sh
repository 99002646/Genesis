#!/bin/bash

: '
To see the difference between $* and $@, run script with params:
one two "three four"
'

echo -e "\nUsing \$*:"
for arg in $*; do echo "<$arg>"; done

echo -e "\nWith \$@:"
for arg in $@; do echo "<$arg>"; done
echo -e "\n"

echo "With \"\$*\":"
for arg in "$*"; do echo "<$arg>"; done
echo -e "\n"

echo "With \"\$@\":"
for arg in "$@"; do echo "<$arg>"; done