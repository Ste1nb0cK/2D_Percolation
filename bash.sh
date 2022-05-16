#!/bin/bash
for size in 32 64 128 256 512
do
  for p in 0 0.05 0.1 0.15 0.2 0.25 0.3 0.35 0.4 0.45 0.5 0.55 0.56 0.57 0.58 0.59 0.6 0.61 0.62 0.63 0.64 0.65 0.7 0.75 0.78 0.79
  do
    for n in {1..10}
    do
      ./foo $size $p $n >> datos$size.txt
    done
  done
done
