#!/bin/bash

FILE=./ex3.txt
if [ ! -f $FILE ]; then
	echo 0 > $FILE
fi
for i in {1..20}
do
	value=$(tail -n 1 $FILE)
	value=$((value + 1))
	echo $value >> $FILE
done

