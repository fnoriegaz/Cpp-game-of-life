#!/bin/bash

clear
rm -v gameOfLife main.o Cells.o output.bin
g++ -g -c main.cpp
g++ -g -c Cells.cpp -fopenmp
g++ *.o -o gameOfLife -lgomp
./gameOfLife $1 $2 $3
# xmovie < output.bin n1=$1 n2=$2 n3=$3 loop=2 &
