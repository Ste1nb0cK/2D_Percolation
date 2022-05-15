#include<Eigen/Eigen>
#include "path.hpp"

Eigen::ArrayXXi Path(const Eigen::ArrayXXi &I, int L, int scanning, int target,
                     int New) {

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L, L);

  if (scanning == 1) {

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, 0, target, New);
    }
  }

  if (scanning == 0) {

    for (int ii = 0; ii < L; ++ii) {

      hood(I, F, L, ii, L - 1, target, New);
    }
  }

  return F;
}
