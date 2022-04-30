#pragma once
#include <random>
#include <Eigen/Dense>
/*fill_boolean(const int L, double p, int seed)
 *DESCRIPTION: Creates an LxL matrix and fills it with boolean values
 *according to a Bernoulli distribution with success probability p.
 *INPUT: const int L. Array size.
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

Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic>
create_filled_grid(const int L, const double p, const int seed);
