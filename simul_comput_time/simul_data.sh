#!/usr/bin/env bash 

SRC_DIR=../src
CXX=g++

$CXX -fsanitize=leak -fsanitize=address -fsanitize=leak -I "../include" -O0  $SRC_DIR/percolation_routines.cpp $SRC_DIR/fill.cpp $SRC_DIR/main_chrono.cpp -o chrono

for L in 2 4 8 16 32 64 128 256 512 1024; do echo -n "$L    "; ./chrono $L 0.30; done > time_data01.txt 
for L in 2 4 8 16 32 64 128 256 512 1024; do echo -n "$L    "; ./chrono $L 0.60; done > time_data02.txt 
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.80; done > time_data03.txt

$CXX -fsanitize=leak -fsanitize=address -fsanitize=leak -I "../include"  -O1  $SRC_DIR/percolation_routines.cpp $SRC_DIR/fill.cpp $SRC_DIR/main_chrono.cpp  -o chrono

for L in 2 4 8 16 32 64 128 256 512 1024; do echo -n "$L    "; ./chrono $L 0.30; done > time_data11.txt 
for L in 2 4 8 16 32 64 128 256 512 1024; do echo -n "$L    "; ./chrono $L 0.60; done > time_data12.txt 
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.80; done > time_data13.txt


$CXX -fsanitize=leak -fsanitize=address -fsanitize=leak -I "../include" -O3 $SRC_DIR/percolation_routines.cpp $SRC_DIR/fill.cpp $SRC_DIR/main_chrono.cpp  -o chrono

for L in 2 4 8 16 32 64 128 256 512 1024; do echo -n "$L    "; ./chrono $L 0.30; done > time_data31.txt 
for L in 2 4 8 16 32 64 128 256 512 1024; do echo -n "$L    "; ./chrono $L 0.60; done > time_data32.txt 
for L in 2 4 8 16 32 64 128 256; do echo -n "$L    "; ./chrono $L 0.80; done > time_data33.txt


python3 grafs.py

mv *.png ../Imagenes

rm *.txt chrono





