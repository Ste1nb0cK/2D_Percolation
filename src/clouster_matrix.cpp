#include<Eigen/Eigen>
#include "clouster_matrix.hpp"

Eigen::ArrayXXi clouster_matrix(const Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1);
  Eigen::ArrayXXi H = I.transpose();
  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0, 0);
  Eigen::ArrayXXi med = F + J.transpose();
  int Vclouster_id = 0;
  int Hclouster_id = 0;
  for (int ii = 0; ii < L; ++ii) {

    if (F(ii, L - 1) != 0) {
      Vclouster_id = 1;
    }
    if (J(ii, L - 1) != 0) {
      Hclouster_id = 1;
    }
  }

  if (Vclouster_id == 0) {
    med = 2 * J;
    J.resize(0, 0);
    return Path(med, L, 0, 2, 1).transpose();
  }

  if (Hclouster_id == 0) {
    med = 2 * F;
    F.resize(0, 0);
    return Path(med, L, 0, 2, 1);
  }

  J.resize(0, 0);
  F.resize(0, 0);

  Eigen::ArrayXXi F1 = Path(med, L, 0, 2, 1);

  return F1;
}
