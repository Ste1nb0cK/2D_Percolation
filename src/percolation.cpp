#include<Eigen/Eigen>
#include"percolation.hpp"

bool Percolation(const Eigen::ArrayXXi &I, int L) {

  int Per =
      0; /* Esta función está pensada para que reciba una matriz de percolación
          I, para saber si el sistema percola, simplemente miramos una frontera
          vertical y una horizontal, si encontramos un número diferente de cero,
          el sistema tiene que ser uno percolante. */
  for (int ii = 0; ii < L; ++ii) {
    if (I(L - 1, ii) != 0 || I(ii, L - 1) != 0) {
      Per = 1;

      break;
    }
  }

  if (Per != 0) {
    return true;
  }

  else {
    return false;
  }
}
