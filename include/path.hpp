#pragma once
#include "hood.hpp"
#include "Eigen/Eigen"

Eigen::ArrayXXi Path(const Eigen::ArrayXXi &I, int L, int scanning, int target, int New);

/*Este método toma la matriz de entrada I y devuelve otra matriz
 con todos los clousters del valor New (percolantes o no)
que inician en la arista izquierda si el valor de scanning es
1, o desde la derecha si el valor de scanning es 0. */
