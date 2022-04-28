#include <Eigen/Dense> //Matrix creation
#include <cmath>
#include <cstdlib> //for type conversions
#include <iostream>
#include <random> //random number generation
#include "check_count_single.hpp"
#include "create_filled_grid.hpp"

int main(int argc, char **argv) {
  const int L = std::atoi(argv[1]);
  const double p = std::atof(argv[2]);
  const int seed = std::atoi(argv[3]);
  Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A =
      create_filled_grid(L, p, seed);
  int n = 0;
  int m = 0;
  std::cout << A << std::endl;
  std::cout << count_neighbors(n, m, A) << std::endl;
  return 0;
}
