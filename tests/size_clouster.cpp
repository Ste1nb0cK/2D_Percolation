#include "size_clouster.hpp"
#include<Eigen/Eigen>
#include <vector>
#include <bits/stdc++.h>

int Size_clouster(Eigen::ArrayXXi &I, int L) {

  std::vector<int> Elements;
  Elements.resize(L * L);
  std::vector<int> clousters_mass;
  clousters_mass.resize(L);
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L; ++jj) {

      Elements[ii * L + jj] = I(ii, jj);
    }
  }
  int target = 1;
  for (int ii = 0; ii < L; ++ii) {

    clousters_mass[ii] = std::count(Elements.begin(), Elements.end(), target);
    target++;
  }

  auto result = std::max_element(clousters_mass.begin(), clousters_mass.end());
  int index = std::distance(clousters_mass.begin(), result);
  return clousters_mass[index];
}
