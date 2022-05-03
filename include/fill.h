#pragma once
#include <Eigen/Dense>
#include <random>
/*Función
que llena el arreglo con las casillas abiertas (1) y cerradas (0).*/
Eigen::ArrayXXi fill_array(int L, double p, int seed);
