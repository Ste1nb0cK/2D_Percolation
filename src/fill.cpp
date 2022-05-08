#include "fill.h"
void fill_array(Eigen::ArrayXXi& A,int L, double p, int seed) {
  std::mt19937 gen(seed);
  std::bernoulli_distribution dis(p);
  for(int &x : A.reshaped()) x=dis(gen);
  return;
}
