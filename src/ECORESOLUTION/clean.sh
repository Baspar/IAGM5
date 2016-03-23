#!/bin/bash
nbTest=3

for dir in Eco*
do
    cd $dir
    echo -n "$dir : Clean en cours... "
    make clean>> /dev/null && {
        echo "OK"
    } || echo "FAIL"
    cd ..
done
