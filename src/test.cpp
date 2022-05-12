#include <Eigen/Eigen>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <random>
#include "percolation_routines.h"
#include "fill.h"
#define CATCH_CONFIG_MAIN
#include "catch2/catch.hpp"


TEST_CASE("Mean of a vector is computed", "[clouster_matrix]", "[index_matrix]", "[Size_clouster]"){

  /*Matrices nulas (P=0)*/
  /////////////////////////////////////////////////////////////////////////////// 
  Eigen::ArrayXXi M1 = Eigen::ArrayXXi::Zero(10, 10);
  Eigen::ArrayXXi M2 = Eigen::ArrayXXi::Zero(100, 100);
  Eigen::ArrayXXi M3 = Eigen::ArrayXXi::Zero(500, 500);
  //////////////////////////////////////////////////////////////////////////////

  /*Matrices unitarias (P=1)*/
  /////////////////////////////////////////////////////////////////////////////// 
  Eigen::ArrayXXi N1 = Eigen::ArrayXXi::Ones(10, 10);
  Eigen::ArrayXXi N2 = Eigen::ArrayXXi::Ones(100, 100);
  Eigen::ArrayXXi N3 = Eigen::ArrayXXi::Ones(500, 500);
  //////////////////////////////////////////////////////////////////////////////

  

  
  










}
