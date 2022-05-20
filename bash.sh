#!/bin/bash

#Ciclo para poder obtener los datos del programa
for size in 32 64 128 256 512
do
  for p in {0..1..0.05}
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

mv *.png ../Imagenes 
