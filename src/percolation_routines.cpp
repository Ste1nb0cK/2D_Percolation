#include "percolation_routines.hpp"

///////////////////////////////////////////////////////////////////////

void hood(const Eigen::ArrayXXi& I, Eigen::ArrayXXi& F,
          int L, int ii, int jj, int target, int New) {

  if (ii >= L || ii < 0 || jj >= L || jj < 0){return;}
  if( I(ii, jj) != target ||F(ii, jj) == New) {return;}
      /*Si el índice está fuera de los límites, si
      la matriz I no tiene el valor del target, o si F ya tiene el valor del
      target, acabamos la función, si no es así, llenamos F con el valor del
      target, y luego llamamos a la función para sus vecinos garantizando la
      creación del clouster.  */

  F(ii, jj) = New;

  hood(I, F, L, ii + 1, jj, target, New);
  hood(I, F, L, ii - 1, jj, target, New);
  hood(I, F, L, ii, jj + 1, target, New);
  hood(I, F, L, ii, jj - 1, target, New);
}
////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////
Eigen::ArrayXXi Path(const Eigen::ArrayXXi& I, int L, int scanning,
                     int target, int New) {

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L,L);
                    /*Se crea una matriz de ceros F, la cual se llenará con
                         todos los clusters que nacen en la frontera izquierda
                         si scanning==1, para eso se usa la función hood, si
                         scanning==0 se hace los mismo pero desde la derecha. */
  
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
///////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
Eigen::ArrayXXi clouster_matrix(const Eigen::ArrayXXi& I, int L) {

  Eigen::ArrayXXi F =Eigen::ArrayXXi::Zero(L,L); // Creamos F llena de ceros.

  F = Path(I, L, 1, 1, 1); // Se crean los caminos de números 1 desde la izquierda
                        // de la matriz que hay en la matriz I.
  Eigen::ArrayXXi H = I.transpose();
  //H = I.transpose(); // Declaramos H, que será la transpuesta de I, esto para
                     // identificar los clusters verticales usando el mismo alg
                     // oritmo,

  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0,0);
  //J = Path(H, L, 1,
    //       1); // Se crean los caminos de números desde la izquerda de la
               // transpuesta de I, lo cual es equivalente a crearlos de sde la
               // parte de arriba de I.

  //Eigen::ArrayXXi med(
    //  L, L); // Para crear la matriz percolante sumamos F y la transpuesta de F,
             // las casillas que hagan parte de un cluster, al sumarlas, el
             // resultado debe ser 2, sin embargo esto no es suficiente, porque
             // aún pueden haber clousters que no
             // son percolantes.
  Eigen::ArrayXXi med = F + J.transpose();
 

  int Vclouster_id=0;                               //Puede suceder que tengamos clousters puramente verticales y puramente
                                                    // verticales que no toquen las fronteras laterales, un ejemplo sería
                                                    //una linea recta que atravieza la matriz, para identificar estos clousters
  int Hclouster_id=0;                               //recorremos la última columna de F y J, y vemos que si son nulas alguna de las
                                                    //dos, los identificadores (Vclouster_id y Hclouster_id) se quedarán nulos, y por
                                                    //ende, debemos retornar una matriz de percolación diferente.

  for(int ii=0; ii<L; ++ii){

    if(F(ii, L-1)!=0){Vclouster_id=1;}
    if(J(ii, L-1)!=0){Hclouster_id=1;}
  }

  if(Vclouster_id==0){med = 2*J;
    J.resize(0,0);
    return Path(med,L, 0, 2, 1).transpose();}

  if(Hclouster_id==0){med = 2*F;
    F.resize(0,0);
    return Path(med, L, 0, 2, 1);}


  J.resize(0,0);
  F.resize(0,0);


  Eigen::ArrayXXi F1 = Path(med, L, 0, 2, 1);
      // Para solucionar esto, creamos una matriz F1, que tomará la
          // matriz med y le creará los caminos buscando el número 2 pero
          // desde la derecha, grantizando que esos caminos solo pueden
          // corresponder a clusters percolantes,
          // por ende F1 será la matriz de percolación, nótese que si el
          // sistema no percola, la matriz F1 será nula.
  return F1;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////

bool Percolation(const Eigen::ArrayXXi& I, int L) {

  int per = 0;
      /* Esta función está pensada para que reciba una matriz de percolación
         I, para saber si el sistema percola, simplemente miramos una frontera
         vertical y una horizontal, si encontramos un número diferente de cero,
         el sistema tiene que ser uno percolante. */
  for (int ii = 0; ii < L; ++ii) {
    if (I(L - 1, ii) != 0 || I(ii, L - 1) != 0) {
      per = 1;

      break;
    }
  }

  if (per != 0) {
    return true;
  }

  else {
    return false;
  }
}





Eigen::ArrayXi sep(const Eigen::ArrayXXi &I, int L) {

  Eigen::ArrayXXi F = Path(I, L, 1, 1, 1);
  Eigen::ArrayXXi H = I.transpose();
  Eigen::ArrayXXi J = Path(H, L, 1, 1, 1);
  H.resize(0, 0);
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

Eigen::ArrayXXi index_matrix(const Eigen::ArrayXXi &I, int L) {

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

int Size_clouster(const Eigen::ArrayXXi &I, int L) {

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
