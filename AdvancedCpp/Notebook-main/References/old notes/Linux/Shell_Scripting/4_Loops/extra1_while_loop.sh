#!/bin/sh
INPUT=hello
while [ "$INPUT" != "quit" ]
do
  echo "Please type something in (quit to quit)"
  read INPUT
  echo "You typed: $INPUT"
done