#pragma once
#include<Eigen/Eigen>

bool Percolation(const Eigen::ArrayXXi &I, int L);
/*Este método recibe la
matriz de percolación y nos dice si existe un clouster percolante o no. */

