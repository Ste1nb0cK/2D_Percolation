#include <Eigen/Dense> //Matrix creation
#include <cmath>
#include <cstdlib> //for type conversions
#include <iostream>
#include <random> //random number generation
/*fill_boolean(const int L, double p, int seed)
 *DESCRIPTION: Creates an LxL matrix and fills it with boolean values
 *according to a Bernoulli distribution with success probability p.
 *INPUT: const int L. Matrix size.
 *       double p. Success probability characterizing the Bernoulli
 *                 distribution.
 *       int seed. Seed to use in the sampling of the probability
 *                 distribution. The random number generator is the
 *                 64-bit Mersenne Twister.
 *OUTPUT: a LxL matrix (of the Eigen Library) filled with booleans
 *        according to the given seed and probability.*/

Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>
create_filled_grid(const int L, const double p, const int seed);

int main(int argc, char **argv) {
  const int L = std::atoi(argv[1]);
  const double p = std::atof(argv[2]);
  const int seed = std::atoi(argv[3]);
  Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A =
      create_filled_grid(L, p, seed);
  std::cout << A << std::endl;
  return 0;
}

Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>
create_filled_grid(const int L, const double p, const int seed) {
  Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A;
  A.resize(L, L);
  // random numbers engine
  std::mt19937_64 gen(seed);
  // probability distribution used in the filling
  std::bernoulli_distribution dist(p);
  // filling
  for (int m = 0; m < L; m++) {
    for (int n = 0; n < L; n++) {
      A(m, n) = dist(gen);
    }
  }
  return A;
}
