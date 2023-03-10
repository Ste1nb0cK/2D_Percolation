# Simulation of 2D site-percolation
We implemented a recursion routine to identify  percolating clusters in square 2D lattices. Then this was used to study the problem of 2D site-percolation, in particular the determination of the percolation probability as function of size and filling probability. All the details of the algorithms used and the results can be found in main.pdf (text in spanish).

## Dependencies
-Spack 0.18.0.dev0

-Catch2.13.8

-Eigen 3.4.0

## Building the project
The main executable is called foo and receives arguments in the order size, filling-probability, seed to use in the filling. To build this executable it is necessary to have Eigen loaded via Spack and Catch2 in case you want to execute and build the tests. Once this libraries are loaded it suffices to run make in the folder and the whole proyect will be compiled.

## Makefile targets
It is possible to execute some task directly from the make file by directly calling the target with make {task}. Below all of this  possible targets are listed.

### make clean
This completly cleans the directory of any .o or executable, including those in the tests directory.

### make format
This applies clang-format with format GNU to all the .cpp and .hpp in the directories include and src.

### make debug
This compiles the whole proyect using debug flags and the executable created is called foo_debug. Automatically you will be asked to provide input data for a debugging session in gdb, that will be launched after all the inputs are provided.

### make report
Generates a pdf from the .tex.
### make simu1

runs the simulation with $L=4$, $p=0.6$ and seed$=1$

### make profile
Creates a profiling of the code using gprof for the case $L=8$, $p=0.5$, seed=$2$. All the generated data and plots can be found in simul_comput_time

### make test
Runs the tests and compiles them if necessary. The tests were written using catch2 and can be found in the tests directory.

## Stats generation
Statistics about the programm can be generated by running the bash scripts bash.sh and boundary.sh scripts, the basically run the simulation for multiple sizes, probabilities and seeds, and at the end create an statistical analysis of them. The difference lies in that bash.sh goes from 0 to 1 in steps o 0.05 and boundary takes 10 values in the interval [0.55, 0.58] 
