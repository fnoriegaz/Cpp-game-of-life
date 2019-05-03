#!/bin/bash

clear
rm -v gameOfLife main.o Cells.o output.bin
g++ -g -c main.cpp;
g++ -g -c Cells.cpp;
g++ *.o -o gameOfLife
./gameOfLife $1 $2 $3
clear
# xmovie < output.bin n1=$1 n2=$2 n3=$3 loop=2 &
