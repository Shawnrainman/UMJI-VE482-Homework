#!/bin/bash

FILE=./ex3.txt
if [ ! -f $FILE ]; then
        echo 0 > $FILE
fi
for i in {1..20}
do
	(
	flock -n -x 9
	value=$(tail -n 1 $FILE)
        value=$((value + 1))
        echo $value >> $FILE
	) 9>>$FILE
done

