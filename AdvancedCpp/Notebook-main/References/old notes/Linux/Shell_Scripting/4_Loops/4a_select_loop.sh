#!/bin/bash

select DAY in Mon Tue Wed Thu Fri Sat Sun exit
do
   case $DAY in
      Mon|Tue|Wed|Thu|Fri) echo "Working day" ;;
      Sat|Sun)    echo "Non working day"      ;;
      exit) break                               ;;
      *) echo "ERROR: Invalid selection"        ;;
   esac
done