#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include "percolation_routines.h"
#include "fill.h"

int main(int argc, char *argv[]) {

  const int L = std::atoi(argv[1]);
  const double p = std::atof(argv[2]);
  const double seed = std::atof(argv[3]);
  Eigen::ArrayXXi M;
  M = fill_array(L, p, seed);
  Eigen::MatrixXi F(L, L);
  F = cluster_matrix(M, L);

  std::cout << "La matriz original es" << std::endl << M << std::endl
  << "La matriz de percolación es" << std::endl
  << F << std::endl
  << "¿EL sistema percola?" << std::endl
  << Percolation(F, L) << std::endl;

  return 0;
}
