#!/bin/bash
nbTest=10

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
                #cat $test | ./main >> /dev/null

                #Commande verbeuse
                #cat $test | ./main

                T="$(( ($(date +%s%N)-T) / 1000000000 ))"
                echo "$T secondes"
                echo $T >> results/$(basename "$test")
            done
        done

        cat results/$(basename $test) | sort > results/$(basename $test)
    } || echo "FAIL"
    cd ..
done
