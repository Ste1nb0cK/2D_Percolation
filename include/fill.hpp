#pragma once
#include <Eigen/Dense>
#include <random>
/*Función
que llena el arreglo con las casillas abiertas (1) y cerradas (0).*/
void fill_array(Eigen::ArrayXXi& A, int L, double p, int seed);
