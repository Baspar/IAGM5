#!/bin/bash
for i in *.cpp
do
    echo $i
    g++ -c --std=c++11 $i
done
rm Sudokus.o
g++ --std=c++11 Sudokus.cpp *.o
