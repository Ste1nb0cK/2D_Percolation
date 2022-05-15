#pragma once
#include<Eigen/Eigen>

void hood(const Eigen::ArrayXXi& I, Eigen::ArrayXXi& F,
          int L, int ii, int jj, int target, int New);
