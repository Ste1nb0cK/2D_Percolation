#include<Eigen/Eigen>
#include"sep.hpp"

Eigen::ArrayXi sep(Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1);
  Eigen::ArrayXXi H = I.transpose();
  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0, 0);

  int ver = 0;
  int hor = 0;
  int per = 0;
  Eigen::ArrayXi V(2);
  V(0) = 0;
  V(1) = 0;

  for (int ii = 0; ii < L; ++ii) {
    if (F(ii, L - 1) != 0) {
      V(0) = 1;

      break;
    }
  }
  F.resize(0, 0);

  for (int ii = 0; ii < L; ++ii) {
    if (J(ii, L - 1) != 0) {
      V(1) = 1;

      break;
    }
  }

  J.resize(0, 0);

  return V;
}
