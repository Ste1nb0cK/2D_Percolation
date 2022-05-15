#include<Eigen/Eigen>
#include "index_matrix.hpp"

Eigen::ArrayXXi index_matrix(Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXi V_H_clouster_id = sep(I, L);

  Eigen::ArrayXXi F = I;

  if (V_H_clouster_id(0) == 1 && V_H_clouster_id(1) == 0) {
    int counterh = 1;

    for (int ii = 0; ii < L; ++ii) {

      if (F(ii, 0) == 1) {
        hood(I, F, L, ii, 0, 1, counterh);
        ++counterh;
      }
    }
  }

  if (V_H_clouster_id(0) == 0 && V_H_clouster_id(1) == 1) {
    F = I.transpose();
    Eigen::ArrayXXi H = I.transpose();
    int counterv = 1;
    for (int ii = 0; ii < L; ++ii) {

      if (F(ii, 0) == 1) {
        hood(H, F, L, ii, 0, 1, counterv);
        ++counterv;
      }
    }

    return F.transpose();
  }

  return F;
}
