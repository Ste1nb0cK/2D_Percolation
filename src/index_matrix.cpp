#include<Eigen/Eigen>
#include "index_matrix.hpp"

Eigen::ArrayXXi index_matrix(Eigen::ArrayXXi &I, int L) { //Se recibe una matriz de percolación

  Eigen::ArrayXi V_H_clouster_id = sep(I, L); //Se crea un vector que tendrá el valor de la función sep aplicada a I. 

  Eigen::ArrayXXi F = I; //Se crea una copia de la matriz de percolación.

  if (V_H_clouster_id(0) == 1 && V_H_clouster_id(1) == 0) { //Si se tiene una percolación puramente horizontal o puramente vertical, se llama a la función hood repetidas veces sobre el inicio de los clusters asignándole a cad acluster indpeendiente el valor de su respectivo contador, grantizando que la función F contendrá los clusters percolantes independientes indexados.
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

  return F; //Se retorna la función F con ls clusters indexados.
} 
