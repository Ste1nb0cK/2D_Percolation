#include "vertical_routines.hpp"

int count_vertical_subcluster_down(
    int n, int m, Eigen::Array<bool, Eigen::Dynamic, Eigen::Dynamic> A) {
  // IT IS ASSUMED THAT THE ELEMENT WE ARE PASSING IS ENDEED FILLED
  int L = A.rows();
  // at least 1 will be returned
  int counter = 0;
  for (int k = 0; (A(n + k, m)) & (n + k < L); k++) {
    counter++;
  }
  return counter;
}

void identify_vertical_subclusters(
  Eigen::Array<bool, Eigen::Dynamic, 1> column, std::string filename){
  int L = column.rows();
  //open the file to which the information will be written
  std::fstream my_file;
  my_file.open(filename, std::ios::out); if (!my_file) {
    std::cout << "File not created!";
	}
  my_file << "position"<<"\t"<<"head_position\n";

  for(int k=0; k<L; k++){
    if(column(k)){
      int size = count_vertical_subcluster_down(k, 0, column);
      my_file << k << "\t" << size << "\n";
      k += size;
    }
  }
  my_file.close();
  return;
}
