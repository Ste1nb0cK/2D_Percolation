#!/bin/bash

#Ciclo para poder obtener los datos del programa
for size in 32 64 128 256 512
do
  for p in 0 0.05 0.1 0.15 0.2 0.25 0.3 0.35 0.4 0.45 0.5 0.55 0.555 0.56 0.565 0.57 0.575 0.58 0.585 0.59 0.595 0.6 0.605 0.61 0.615 0.62 0.625 0.63 0.635 0.64 0.645 0.65 0.7 0.75 0.78 0.8 0.85 0.9 0.95 1
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

#Elimina los archivos datos*.txt
rm datos*.txt
