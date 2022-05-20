#pragma once
#include "path.hpp"
#include<Eigen/Eigen>

Eigen::ArrayXi sep(Eigen::ArrayXXi &I, int L);

/*Esta función recibe la matriz de percolación y devuelce un array unidimensional de dos elementos que determinan si el si el sistema presenta percolación combina, vertical u horizontal.*/
