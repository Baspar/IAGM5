#!/bin/bash
isOk=0
while [ $isOk -eq 0 ]
do
	mode=$(zenity  --list --column="Version"  AlgoGen AStar EcoResolution)
	isOk=$?
	mode=$(echo $mode | cut -d'|' -f1)
	if [ $isOk -eq 0 ]
	then
		test="X"
		while [ "$test" != "" ]
		do
			test=$(zenity  --list --column="Version"  Grille4x4 Grille9x9)
			if [ "$test" != "" ]
			then
				test=$(echo $test | cut -d'|' -f1)

				if [ "$test" == "Grille4x4" ]
				then
					cp Test/tresFacile.txt $mode/test.txt
				elif [ "$test" == "Grille9x9" ]
				then
					cp Test/facile.txt $mode/test.txt
				fi

				cd $mode
				./main
				rm test.txt
				cd ..
			fi
		done
	else
		exit 0
	fi
done
