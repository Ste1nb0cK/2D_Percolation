#pragma once
#include "sep.hpp"
#include "hood.hpp"
#include<Eigen/Eigen>

Eigen::ArrayXXi index_matrix(Eigen::ArrayXXi &I, int L);

/*Esta función recibe la matriz de percolación y la procesa devolveindo una matriz en la que cada cluster percolante tiene un número entero como identificador*/ 
