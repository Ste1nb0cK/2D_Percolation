#include "fill.h"
Eigen::ArrayXXi fill_array(int L, double p, int seed) {

  std::mt19937 gen(seed);
  std::bernoulli_distribution dis(p);
  Eigen::ArrayXXi A; // Declaramos un arreglo de tamaño LxL.
  A.resize(L, L);
  // for (int n = 0; n < L; n++) {
  //   for (int m = 0; m < L; m++) {
  //     M(m, n) = dis(gen);
  //   }
  // }
  for(int &x : A.reshaped()) x=dis(gen);
  return A;
}
