#!/bin/bash
nbTest=3

for dir in Eco*
do
    cd $dir
    echo -n "$dir : Make en cours... "
    make >> /dev/null && {
        echo "OK"
        rm -rf results/
        mkdir results
        for test in JeuDeTest/*
        do
            for i in $(seq 1 $nbTest)
            do
                echo -n "  $(basename $test) $i/$nbTest..."
                T="$(date +%s%N)"

                #Commande muette
                cat $test | ./main >> /dev/null || echo "ERREUR"

                #Commande verbeuse
                #cat $test | ./main

                T="$(( ($(date +%s%N)-T) / 1000000 ))"
                echo "$T millisecondes"
                echo $T >> results/$(basename "$test")
            done

            cat results/$(basename $test) | sort -n > results/$(basename $test)Sort

            min=$(cat results/$(basename $test)Sort | head -n 1)
            max=$(cat results/$(basename $test)Sort | tail -n 1)

            moy=0
            while read line
            do
                moy=$((moy + line))
            done <  results/$(basename $test)Sort
            
            moy=$((moy/nbTest))
            echo "  min: $min, max: $max, moy: $moy"
        done
    } || echo "FAIL"
    cd ..
done
