#include "check_count_single.hpp"
#include "create_filled_grid.hpp"
#include "vertical_routines.hpp"
#include <Eigen/Dense> //Array creation
#include <cmath>
#include <cstdlib> //for type conversions
#include <iostream>
#include <random> //random number generation
#include <fstream> //files manipulation
#include <string>

// void identify_vertical_subclusters(
  // Eigen::Array<bool, Eigen::Dynamic, 1> column, std::string filename);

int main(int argc, char **argv) {
  const int L = std::atoi(argv[1]);
  const double p = std::atof(argv[2]);
  const int seed = std::atoi(argv[3]);
  Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A =
      create_filled_grid(L, p, seed);
  const int n = 0;
  const int m = 0;
  std::cout << "Generated Array. L=" << L << "\t"
            << "p=" << p << "\t"
            << "seed=" << seed << std::endl;
  std::cout << A << std::endl;
  std::cout << "Neighbors count of the element (" << n << "," << m
            << ")=" << count_neighbors(n, m, A) << std::endl;
  std::cout << "Check up neighbor =" << check_up_neighbor(n, m, A) << std::endl;
  std::cout << "Check down neighbor =" << check_down_neighbor(n, m, A)
            << std::endl;
  std::cout << "Check right neighbor =" << check_right_neighbor(n, m, A)
            << std::endl;
  std::cout << "Check left neighbor =" << check_left_neighbor(n, m, A)
            << std::endl;
  std::cout << "Vertical down subcluster size ="
            << count_vertical_subcluster_down(n, m, A) << std::endl;
  std::string filename_n_vertical = std::to_string(n)+ "_vertical";
  std::cout << "Column to identify" << std::endl;
  std::cout << A.col(n) << std::endl;
  identify_vertical_subclusters(A.col(n), filename_n_vertical);
  std::cout << "Created the file with the subclusters of the " <<n
            <<"-th column with the name " << filename_n_vertical << std::endl;
  return 0;
}

