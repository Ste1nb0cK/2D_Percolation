//Este main fue realizado temporalmente como una variacion a 'main1_code' para calcular el tiempo de computo promedio

#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include "percolation_routines.hpp"
#include "fill.hpp"
#include <chrono>
#include <vector>
#include <numeric>

double time_wasted(int L, double p, int seed);

int main(int argc, char *argv[]) {

   const int L = std::atoi(argv[1]);
   const double p=std::atof(argv[2]);
   const int seed =10;
   srand(seed); //control de la semilla
  
   std::vector<double> tiempos;
   
  
  for(int nn=0;nn<12;nn++){ //Cantidad de datos tomados
  	tiempos.push_back(time_wasted(L,p,seed)); //guardado de tiempos
  }
  
  double mean=std::accumulate(tiempos.begin(),tiempos.end(),0.0)/tiempos.size(); //calculo promedio
  double stdev=std::sqrt(std::inner_product(tiempos.begin(),tiempos.end(),tiempos.begin(),0.0)/tiempos.size() - std::pow(mean,2)); //calculo desviación estandar

  std::cout<< mean <<"\t"<< stdev  <<std::endl;
  

  return 0;
}

double time_wasted(int L, double p, int seed){

  auto start = std::chrono::steady_clock::now();
  
  Eigen::ArrayXXi M = Eigen::ArrayXXi::Zero(L,L);
  fill_array(M, L, p, seed);
  

  Eigen::ArrayXXi F = Eigen::ArrayXXi::Zero(L, L) ;
  F = clouster_matrix(M, L);


  Eigen::ArrayXXi G = Eigen::ArrayXXi::Zero(L, L) ;

  G = index_matrix(F, L);
  F.resize(0,0);

  int perc=Percolation(G, L); //Variable usada para calcular la funcion Percolation
  int persize=Size_clouster(G, L); //Variable usada para calcular la funcion Size_clouster

		 
  auto end = std::chrono::steady_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  return elapsed_seconds.count();
}
