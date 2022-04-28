#include "create_filled_grid.hpp"

Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>
create_filled_grid(const int L, const double p, const int seed) {
  Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A;
  A.resize(L, L);
  // random numbers engine
  std::mt19937_64 gen(seed);
  // probability distribution used in the filling
  std::bernoulli_distribution dist(p);
  // filling
  for (int n = 0; n < L; n++) {
    for (int m = 0; m < L; m++) {
      A(m, n) = dist(gen);
    }
  }
  return A;
}
