#!/bin/bash

#Ciclo para poder obtener los datos del programa
for size in 32 64 128 256 512
do
  for p in 0.550 0.555 0.560 0.5625 0.565 0.5675 0.570 0.575 0.560 0.565
  do
    for n in {1..10}
    do
      ./foo $size $p $n >> datos$size.txt
    done
  done
done

#ejecución de los scripts de python
python3 results/graficacluster.py
python3 results/graficaprobabilidad.py
