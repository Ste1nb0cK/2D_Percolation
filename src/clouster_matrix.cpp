#include<Eigen/Eigen>
#include "clouster_matrix.hpp"

//Se recibe la matriz de estudio.
Eigen::ArrayXXi clouster_matrix(const Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1); //Se declara F y se acciona path buscandoel 1, reescribiendo el 1 de izquierda a derecha.

  Eigen::ArrayXXi H = I.transpose(); //Para detectar los clusters verticales basta con estudiar la transpuesta de I.

  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1); //Se aplica path a I transpuesta buscando 1 y reescribiendo 1 de izquierda a derecha, lo cual
                                           // es quivalente a escanear de arriba a abajo en I.


  H.resize(0, 0);//Liberamos la memoria de H ya que no la volveremos a usar.

  Eigen::ArrayXXi med = F + J.transpose(); //Se declara una nueva matriz que será la suma de la matriz con clusters verticales y los clusters horizonateles, grantizando que, las zonas en donde se tenga un dos corresponderán a clusters percolantes. 
                                          
                                         







  int Vclouster_id = 0; //Declaramos enteros que nos ayudan a verificar si se tienen clusters puramente verticales o puramente horizontales.                 
  int Hclouster_id = 0; 
  for (int ii = 0; ii < L; ++ii) {

    if (F(ii, L - 1) != 0) {
      Vclouster_id = 1;
    }
    if (J(ii, L - 1) != 0) {
      Hclouster_id = 1;
    }
  }

  if (Vclouster_id == 0) { //Si se tienen clusters puramente verticales, limpiamos, devolvemos la matriz med escaneada de derecha a izquierda con el valor de New igual a 1. 
    med = 2 * J;
    J.resize(0, 0);
    return Path(med, L, 0, 2, 1).transpose();
  }

  if (Hclouster_id == 0) { //SI se tienen clusters puramente horizontales realizamos lo mismo.
    med = 2 * F;
    F.resize(0, 0);
    return Path(med, L, 0, 2, 1);
  }

  J.resize(0, 0);
  F.resize(0, 0);

  Eigen::ArrayXXi F1 = Path(med, L, 0, 2, 1);//En caso de que no se tengan clusters o se tengan verticilaes y horizontales al tiempo (es decir, uno solo) se llama al método path de derecha a izquierda buscando el 2 y escribiendo un 1, esto nos garantiza que F1 contiene casillas abiertas que pertenecen únicamente al cluster percolante.

  return F1;
}
