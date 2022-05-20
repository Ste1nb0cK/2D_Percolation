#pragma once
#include<Eigen/Eigen>
#include "path.hpp"

Eigen::ArrayXXi clouster_matrix(const Eigen::ArrayXXi &I, int L);

/*Este método toma la matriz I, y nos devuelve lo que llamé la
               matriz de percolación, que estará llena con el número 1 en todas
               las casillas que hagan parte de un clouster percolante, los demás
               valores son ceros. */
