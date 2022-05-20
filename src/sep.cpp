#include<Eigen/Eigen>
#include"sep.hpp"

Eigen::ArrayXi sep(Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1); //Se declaran las matrices con clusters nacientes en la izquierda y arriba.
  Eigen::ArrayXXi H = I.transpose();
  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0, 0);


  Eigen::ArrayXi V(2);

  V(0) = 0;
  V(1) = 0;

  for (int ii = 0; ii < L; ++ii) { //Vemos la última columna de la matriz de clusters nacientes a la izquierda, si encontramos un 1, quoere decir que hay un cluster horizontal, y asignamos al primer elemento de v el valor de 1.
    if (F(ii, L - 1) != 0) {
      V(0) = 1; 

      break;
    }
  }
  F.resize(0, 0);//Libreramos la memoria de F ya que no la usaremos más.

  for (int ii = 0; ii < L; ++ii) {//Realizamos lo mismo con la matriz de clusters nacientes arriba, pero ahora viendo abajo.
    if (J(ii, L - 1) != 0) {
      V(1) = 1;

      break;
    }
  }

  J.resize(0, 0); //Liberamos la memoria de J debido a que no la usaremos más.

  return V;//Retornamos el vector V 
}
