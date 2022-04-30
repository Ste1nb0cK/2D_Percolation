#include <Eigen/Eigen>
#include <cmath>
#include <iostream>
#include <random>
#include<cstdlib>

Eigen::MatrixXd fill(int L, double P, double seed);
void hood( Eigen::Ref<Eigen::MatrixXd> I,  Eigen::Ref<Eigen::MatrixXd> F, int L, int ii, int jj);
bool Percolation(Eigen::Ref< Eigen::MatrixXd> I, int L);
Eigen::MatrixXd Path(Eigen::Ref< Eigen::MatrixXd> I, int L);


int main(int argc, char *argv[]) {

   double P = std::atof(argv[1]);
   int L = std::atoi(argv[2]);
   double seed= std::atof(argv[3]);
   Eigen::MatrixXd M = fill(L, P, seed);
   Eigen::MatrixXd F(L,L);
   F=Path(M, L);

   std::cout<<"La matriz original es"<<std::endl<<M<<std::endl<<"La matriz de caminos es"<<std::endl<<F<<std::endl<<"¿EL sistema percola?"<<std::endl;

   std::cout<<Percolation(M, L)<<std::endl;
  
  
  

      

  return 0;
}


//////////////////////////////////////////////////////////////////////////


Eigen::MatrixXd fill(int L, double P, double seed){

std::mt19937 gen(seed);
std::uniform_real_distribution<> dis(0.0, 1.0);


Eigen::MatrixXd M(L, L); //Declaramos una matriz de tamaño LxL.
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L; ++jj) { /*Comenzamos a recorrer la matriz, llenamos sus elementos con un número aleatorio entre 0 y 1,                                           si este es mayor que P asignamos un cero, y si este es menor asignamos un 1.*/ 

      double r = dis(gen);
      M(ii, jj) = r;
      if (M(ii, jj) <= P) {
        M(ii, jj) = 1;
      } else {

        M(ii, jj) = 0;
      }
    }
  }

 

  return M;
}

///////////////////////////////////////////////////////////////////////

void hood( Eigen::Ref<Eigen::MatrixXd> I,  Eigen::Ref<Eigen::MatrixXd> F, int L, int ii, int jj){

  if (ii>=L || ii<0 || jj>=L || jj<0 || I(ii,jj)==0 || F(ii,jj)==1) {return;}  

  else {F(ii, jj)==1;}

  F(ii,jj)=1;
  
  

   hood(I, F, L, ii+1, jj);
   hood(I, F, L, ii-1, jj);
   hood(I, F, L, ii, jj+1);
   hood(I, F, L, ii, jj-1);
}
//////////////////////////////////////////////////////////////////////////////

bool Percolation(Eigen::Ref<Eigen::MatrixXd> I, int L){


  Eigen::MatrixXd F(L,L);
  F = Path(I, L);
  Eigen::MatrixXd H = I.transpose();

  Eigen::MatrixXd J(L,L);
  J = Path(H, L);
  for (int ii =0; ii<L; ++ii){

    if (F(ii, L-1)==1 || J(ii, L-1)==1 ){

      return true;}
  }

  return false;

  }


//////////////////////////////////////////////////////////////////////////
Eigen::MatrixXd Path(Eigen::Ref< Eigen::MatrixXd> I, int L){


  Eigen::MatrixXd F(L,L);

  for (int ii=0; ii<L; ++ii){

    hood(I, F, L, ii, 0);
}

  return F;

} 
