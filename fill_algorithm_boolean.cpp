#include <Eigen/Dense> //Matrix creation
#include <cmath>
#include <cstdlib> //for type conversions
#include <iostream>
#include <tuple>
#include <random> //random number generation
/*fill_boolean(const int L, double p, int seed)
 *DESCRIPTION: Creates an LxL matrix and fills it with boolean values
 *according to a Bernoulli distribution with success probability p.
 *INPUT: const int L. Matrix size.
 *
 *       double p. Success probability characterizing the Bernoulli
 *                 distribution.
 *
 *       int seed. Seed to use in the sampling of the probability
 *                 distribution. The random number generator is the
 *                 64-bit Mersenne Twister.
 *
 *OUTPUT: a LxL matrix (of the Eigen Library) filled with booleans
 *        according to the given seed and probability.*/

Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>
create_filled_grid(const int L, const double p, const int seed);

/* check_up_neighbor( int n, int m,
 *                     Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the up neighbor for a determined element of a given
 *            matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no upper neighbor.
 *
             */
bool check_up_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A
                          );
/* check_up_neighbor( int n, int m,
 *                     Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the down neighbor for a determined element of a given
 *            matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no down neighbor.
 *
             */
bool check_down_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A
                          );
/* check_up_neighbor( int n, int m,
 *                    Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the right neighbor for a determined element of a given
 *             matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no right neighbor.
 *
             */
bool check_right_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A
                          );
/* check_up_neighbor( int n, int m,
 *                     Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic>);
 *DESCRIPTION: Checks if the left neighbor for a determined element of a given
 *              matrix is filled.
 *INPUT: int n. Column coordinate of the element.
 *
 *      int m. Row coordinate of the element.
 *
 *      Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A. The matrix to
 *      which the element belongs.
 *
 *Output: Returns a bool true in case it is filled, and false if it is not
 *        or there is no right neighbor.
 *
             */
bool check_left_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A
                          );


int main(int argc, char **argv) {
  const int L = std::atoi(argv[1]);
  const double p = std::atof(argv[2]);
  const int seed = std::atoi(argv[3]);
  Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A =
    create_filled_grid(L, p, seed);
  int n = 2;
  int m = 2;
  std::cout << A << std::endl;
  std::cout << check_up_neighbor(n,m,A) << std::endl;
  std::cout << check_down_neighbor(n,m,A) << std::endl;
  std::cout << check_right_neighbor(n,m,A) << std::endl;
  std::cout << check_left_neighbor(n,m,A) << std::endl;
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

bool check_up_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A)
{
  if (n==0){return 0;}
  else {
    return A(n-1,m);
  }
}

bool check_down_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A)
{
  int L = A.rows();
  if (n==L-1){return 0;}
  else {
    return A(n+1,m);
  }
}

bool check_right_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A)
{
  int L = A.cols();
  if (m==L-1){return 0;}
  else {
    return A(n,m+1);
  }
}

bool check_left_neighbor(int n, int m,
                          Eigen::Matrix<bool, Eigen::Dynamic, Eigen::Dynamic> A)
{
  if (m==0){return 0;}
  else {
    return A(n,m-1);
  }
}
