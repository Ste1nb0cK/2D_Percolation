#!/usr/bin/env bash 


#specify to the compiler where to find the headers
SRC_DIR=../src
#compiler specifications
CXX=g++

$CXX -fsanitize=leak -fsanitize=address -fsanitize=leak -I "../include" -O0  $SRC_DIR/percolation_routines.cpp $SRC_DIR/fill.cpp $SRC_DIR/main_chrono.cpp -o chrono

for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.15; done > time_data01.txt 
for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.40; done > time_data02.txt 
for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.65; done > time_data03.txt
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.85; done > time_data04.txt

$CXX -fsanitize=leak -fsanitize=address -fsanitize=leak -I "../include"  -O1  $SRC_DIR/percolation_routines.cpp $SRC_DIR/fill.cpp $SRC_DIR/main_chrono.cpp  -o chrono

for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.15; done > time_data11.txt 
for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.40; done > time_data12.txt 
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.65; done > time_data13.txt
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.85; done > time_data14.txt


$CXX -fsanitize=leak -fsanitize=address -fsanitize=leak -I "../include" -O3 $SRC_DIR/percolation_routines.cpp $SRC_DIR/fill.cpp $SRC_DIR/main_chrono.cpp  -o chrono

for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.15; done > time_data31.txt 
for L in 2 4 8 16 32 64 128 256 512; do echo -n "$L    "; ./chrono $L 0.40; done > time_data32.txt 
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.65; done > time_data33.txt
for L in 2 4 8 16 32 64 128; do echo -n "$L    "; ./chrono $L 0.85; done > time_data34.txt

gnuplot <<EFM
load 'grafs.gp'
EFM

rm *.txt chrono





