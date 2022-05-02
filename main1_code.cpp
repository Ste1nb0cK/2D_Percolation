#include <Eigen/Eigen>
#include <cmath>
#include <iostream>
#include <random>
#include<cstdlib>

Eigen::MatrixXi fill(int L, double P, double seed);
void hood( Eigen::Ref<Eigen::MatrixXi> I,  Eigen::Ref<Eigen::MatrixXi> F, int L, int ii, int jj, int target);
bool Percolation(Eigen::Ref< Eigen::MatrixXi> I, int L);
Eigen::MatrixXi Path(Eigen::Ref< Eigen::MatrixXi> I, int L, int scanning, int target);
Eigen::MatrixXi clouster_matrix(Eigen::Ref< Eigen::MatrixXi> I, int L);

int main(int argc, char *argv[]) {

   double P = std::atof(argv[1]);
   int L = std::atoi(argv[2]);
   double seed= std::atof(argv[3]);
   Eigen::MatrixXi M = fill(L, P, seed);
   Eigen::MatrixXi F(L,L);
   F=clouster_matrix(M, L);

   std::cout<<"La matriz original es"<<std::endl<<M<<std::endl<<"La matriz de caminos es"<<std::endl<<F<<std::endl<<"¿EL sistema percola?"<<std::endl;

   int a = 0; 

   for(int ii =0; ii<L; ++ii){

     if(F(ii, 0)==2 || F(0, ii)==2 ){a=1;}

   }

   if (a !=0){ std::cout<<"sikas"<<std::endl;}


      

  return 0;
}


//////////////////////////////////////////////////////////////////////////


Eigen::MatrixXi fill(int L, double P, double seed){

std::mt19937 gen(seed);
std::uniform_real_distribution<> dis(0.0, 1.0);


Eigen::MatrixXi M(L, L); //Declaramos una matriz de tamaño LxL.
  for (int ii = 0; ii < L; ++ii) {
    for (int jj = 0; jj < L; ++jj) { /*Comenzamos a recorrer la matriz, llenamos sus elementos con un número aleatorio entre 0 y 1,                                           si este es mayor que P asignamos un cero, y si este es menor asignamos un 1.*/ 

      double r = dis(gen);
    
      if (r <= P) {
        M(ii, jj) = 1;
      } else {

        M(ii, jj) = 0;
      }
    }
  }

 

  return M;
}

///////////////////////////////////////////////////////////////////////

void hood( Eigen::Ref<Eigen::MatrixXi> I,  Eigen::Ref<Eigen::MatrixXi> F, int L, int ii, int jj, int target){

  if (ii>=L || ii<0 || jj>=L || jj<0 || I(ii,jj)!=target || F(ii,jj)==target) {return;}  


  F(ii,jj)=target;
  
  

  hood(I, F, L, ii+1, jj, target);
  hood(I, F, L, ii-1, jj, target);
   hood(I, F, L, ii, jj+1, target);
   hood(I, F, L, ii, jj-1, target);
}
//////////////////////////////////////////////////////////////////////////////

bool Percolation(Eigen::Ref<Eigen::MatrixXi> I, int L){

  Eigen::MatrixXi F(L, L);
  F = clouster_matrix(I, L);
  int cont = 0;
  for (int ii =0; ii<L; ++ii ){
    if (F(0,ii)==2){return true;}
  }
    for (int jj =0; jj<L; ++jj){


      if (F(jj, 0)==2){return true;}
  
  }
 

}


//////////////////////////////////////////////////////////////////////////
Eigen::MatrixXi Path(Eigen::Ref< Eigen::MatrixXi> I, int L, int scanning, int target){


  Eigen::MatrixXi F(L,L);

  if (scanning==1){

  for (int ii=0; ii<L; ++ii){

    hood(I, F, L, ii, 0, target);
}
  }

  if( scanning ==0 ){

     for (int ii=0; ii<L; ++ii){

       hood(I, F, L, ii, L-1, target);
}


  }

  
  return F;

} 


Eigen::MatrixXi clouster_matrix(Eigen::Ref< Eigen::MatrixXi> I, int L){

  Eigen::MatrixXi F(L,L);
  F = Path(I, L, 1, 1);
  Eigen::MatrixXi H(L,L);
  H= I.transpose();

  Eigen::MatrixXi J(L,L);
  J = Path(H, L, 1, 1);
  Eigen::MatrixXi med(L, L);
  med= F + J.transpose();

  Eigen::MatrixXi F1(L,L);
  F1 = Path(med, L, 0, 2);
  Eigen::MatrixXi H1(L,L);
  H1= med.transpose();

  Eigen::MatrixXi J1(L,L);
  J1 = Path(H, L, 0, 2 );
  Eigen::MatrixXi PATH(L, L);
  PATH= F1 + J1.transpose();

  


  return PATH;
    


}
