#!/bin/bash

for I in A B C D
do
	echo -n "$I:"
	for J in `seq 10`
		do
			if [ $J -eq 5 ]; then
				#break
				break 2
			fi
			echo -n " $J"
		done
		echo "\n"
	done
done
echo

