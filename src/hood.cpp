#include "hood.hpp"
#include "Eigen/Eigen"

void hood(const Eigen::ArrayXXi& I, Eigen::ArrayXXi& F, //La función recibe la matriz de estudio y una matriz de escritura F.
          int L, int ii, int jj, int target, int New) {

  if (ii >= L || ii < 0 || jj >= L || jj < 0){return;}
  if( I(ii, jj) != target ||F(ii, jj) == New) {return;}
      /*Si el índice está fuera de los límites, si
      la matriz I no tiene el valor del target, o si F ya tiene el valor del
      target, acabamos la función, si no es así, llenamos F con el valor del
      New, y luego llamamos a la función para sus vecinos garantizando la
      creación del clouster.  */

  F(ii, jj) = New;

  hood(I, F, L, ii + 1, jj, target, New);
  hood(I, F, L, ii - 1, jj, target, New);
  hood(I, F, L, ii, jj + 1, target, New);
  hood(I, F, L, ii, jj - 1, target, New);
}
