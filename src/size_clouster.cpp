#include "size_clouster.hpp"
#include<Eigen/Eigen>
#include <vector>
#include <bits/stdc++.h>

int Size_clouster(Eigen::ArrayXXi &I, int L) {//Se recibe la matrix indexada. 

  std::vector<int> Elements; //Se crea un vector llamado elementos de tamaño L*L
  Elements.resize(L * L);
  std::vector<int> clousters_mass; //Se crea el vector cluster_mass que tendrá como elementos el tamaño de cada cluster percolante.
  clousters_mass.resize(L);
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L; ++jj) {

      Elements[ii * L + jj] = I(ii, jj); //Se mapea la matriz indexada al vector elements.
    }
  }
  int target = 1;
  for (int ii = 0; ii < L; ++ii) {

    clousters_mass[ii] = std::count(Elements.begin(), Elements.end(), target); //Se usa la función count para llenar el vector cluster_mass con el tamaño de cada cluster percolante.
    target++;
  }

  auto result = std::max_element(clousters_mass.begin(), clousters_mass.end());
  int index = std::distance(clousters_mass.begin(), result);
  return clousters_mass[index]; //Se devuelve el elemento más grande del vector clouster_mass, el tamaño del cluster percolante más grande.
}
