#pragma once
#include<Eigen/Eigen>

void hood(const Eigen::ArrayXXi& I, Eigen::ArrayXXi& F,
          int L, int ii, int jj, int target, int New);

/*Esta función a partir de una casilla (i, j) de la matriz
 I, crea una matriz F con un clouster formado por casillas
 con el valor de "New" y todas las demás casillas fuera
 del clouster particular son ceros. */
