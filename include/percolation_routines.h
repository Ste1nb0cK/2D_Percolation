#ifndef PERCOLATION_ROUTINES_H_
#define PERCOLATION_ROUTINES_H_
#include<Eigen/Dense>
void hood(const Eigen::ArrayXXi& M, Eigen::ArrayXXi& F,
          int L, int ii, int jj, int target);
/*Esta función a partir de una casilla (i,
j) de la matriz M, crea una matriz F con un cluster formado por casillas con
el valor de "target" y todas las demás casillas fuera del cluster particular
son cero. */

Eigen::ArrayXXi Path(const Eigen::ArrayXXi& I, int L, int scanning,
     int target); /*Este método toma la matriz de entrada I y devuelve otra
                     matriz con todos los clusters del valor target
                     (percolantes o no) que inician en la arista izquierda si el
                     valor de scanning es 1, o desde la derecha si el valor de
                     scanning es 0. */

Eigen::ArrayXXi clouster_matrix(
    const Eigen::MatrixXi& I,
    int L); /*Este método toma la matriz I, y nos devuelve lo que llamé"la
               matriz de percolación, que estará llena con el número 2 en todas
               las casillas que hagan parte de un clouster percolante, los demás
               valores son ceros." */

Eigen::ArrayXXi cluster_matrix(const Eigen::ArrayXXi& I, int L);
bool Percolation(const Eigen::ArrayXXi& I,
                 int L); /*Este método recibe la matriz de percolación y nos
dice si existe un clouster percolante o no. */

/*EN la función main declaramos la probabilidad de llenado P, el tamaño de la
matriz L, y la semilla con la que crearemos los números aleatorios,
posteriormente declaramos la matrix M a la que le aplicamos el algoritmo de
llenado definido por la función fill(), luego, declaramos la función F a la que
le asignamos la matriz de percolación definida por la función clouster_matrix(),
se imprime la matriz original, la matriz de percolación, y si el sistema percola
o no, definido
por la función Percolation() aplicada a la matriz de percolación F. */



#endif // PERCOLATION_ROUTINES_H_
