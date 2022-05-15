#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include "clouster_matrix.hpp"
#include "index_matrix.hpp"
#include "fill.hpp"
#include "percolation.hpp"
#include "size_clouster.hpp"


int main(int argc, char *argv[]) {

   const int L = std::atoi(argv[1]);
   const double p = std::atof(argv[2]);
   const double seed = std::atof(argv[3]);
  
  
  Eigen::ArrayXXi M = Eigen::ArrayXXi::Zero(L,L);
  fill_array(M, L, p, seed);
 
  
   
  

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L, L) ;
  F = clouster_matrix(M, L);


  Eigen::ArrayXXi G = Eigen::ArrayXXi::Zero(L, L) ;

  G = index_matrix(F, L);
  F.resize(0,0);

  

  std::cout << "La matriz original es" << std::endl << M << std::endl
  << "La matriz de percolación indexada es" << std::endl
  << G << std::endl
  << "¿EL sistema percola?" << std::endl
  << Percolation(G, L) << std::endl
  <<"EL tamaño del clouster percolante más grande es"<<std::endl
	    <<Size_clouster(G, L)<<std::endl;

  return 0;
}
