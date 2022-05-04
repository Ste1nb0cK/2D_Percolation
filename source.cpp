#include <Eigen/Eigen>
#include <cmath>
#include <iostream>
#include <random>
#include<cstdlib>

/*Trataré de explicar todo para que se entienda lo mejor prosible, soy consciente de que hay muchas mejoras de estilo en el código, obviamente esto hay que corregirlo pero por ahora tenemos esto y creo que tenemos casi lista la implementación para ponernos a hacer medidas y demás.*/

Eigen::MatrixXd fill(int L, double P, double seed);/*Función que llena la matriz con las casillas abiertas (1) y cerradas (0). */

void hood(const  Eigen::MatrixXd & I,  Eigen::Ref<Eigen::MatrixXi> F, int L, int ii, int jj, int target);/*Esta función a partir de una casilla (i, j) de la matriz I, crea una matriz F con un clouster formado por casillas con el valor de "target" y todas las demás casillas fuera del clouster particular son ceros. */

Eigen::MatrixXd Path(const Eigen::MatrixXd &I, int L, int scanning, int target);/*Este método toma la matriz de entrada I y devuelve otra matriz con todos los clousters del valor target (percolantes o no) que inician en la arista izquierda si el valor de scanning es 1, o desde la derecha si el valor de scanning es 0. */

Eigen::MatrixXd clouster_matrix(const Eigen::MatrixXd & I, int L);/*Este método toma la matriz I, y nos devuelve lo que llamé"la matriz de percolación, que estará llena con el número 2 en todas las casillas que hagan parte de un clouster percolante, los demás valores son ceros." */

bool Percolation(const Eigen::MatrixXd &I, int L); /*Este método recibe la matriz de percolación y nos dice si existe un 
clouster percolante o no. */

/*EN la función main declaramos la probabilidad de llenado P, el tamaño de la matriz L, y la semilla con la que crearemos 
los números aleatorios, posteriormente declaramos la matrix M a la que le aplicamos el algoritmo de llenado definido por 
la función fill(), luego, declaramos la función F a la que le asignamos la matriz de percolación definida por la función 
clouster_matrix(), se imprime la matriz original, la matriz de percolación, y si el sistema percola o no, definido
por la función Percolation() aplicada a la matriz de percolación F. */


int main(int argc, char *argv[]) {

   double P = std::atof(argv[1]);
   int L = std::atoi(argv[2]);
   double seed= std::atof(argv[3]);

 
   
   /*  Eigen::MatrixXd M(L, L);
   M = fill(L, P, seed);
   M.resize(L, L);*/
   

     Eigen::MatrixXd M(L, L);
   for(int ii =0; ii<L; ++ii){
     for(int jj = 0; jj < L; ++jj){

       if( ii==5) {M(ii, jj)= 1;}else{ M(ii, jj)=0;}

     }
     }
   
    Eigen::MatrixXd F(L,L);
  
    F=clouster_matrix(M, L);
    F.resize(L, L);
  

   std::cout<<"La matriz original es"<<std::endl<<M<<std::endl<<"La matriz de percolación es"<<std::endl<<F<<std::endl<<"¿EL sistema percola?"<<std::endl<<Percolation(F, L)<<std::endl;

    

  


      

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

void hood( const Eigen::MatrixXd &I,  Eigen::Ref<Eigen::MatrixXd> F, int L, int ii, int jj, int target){

  if (ii>=L || ii<0 || jj>=L || jj<0){return;}
  if(I(ii,jj)!=target || F(ii,jj)==target) {return;} /*Si el índice está fuera de los límites, si
                                                                                          la matriz I no tiene el valor del target, o                                                                                            si F ya tiene el valor del target, acabamos                                                                                            la función, si no es así, llenamos F con 
                                                                                         el valor del target, y luego llamamos 
                                                                                          a la función para sus vecinos garantizando
                                                                                          la creación del clouster.  */


  F(ii,jj)=target;
  
  

  hood(I, F, L, ii+1, jj, target);
  hood(I, F, L, ii-1, jj, target);
  hood(I, F, L, ii, jj+1, target);
  hood(I, F, L, ii, jj-1, target);
}
////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////
Eigen::MatrixXd Path(const Eigen::MatrixXd &I, int L, int scanning, int target){


  Eigen::MatrixXd F(L,L);
  for (int ii=0; ii<L; ++ii){
    for(int jj =0; jj<L; ++jj){


      F(ii, jj)=0;
    }



  }
                                                      /*Se crea una matriz de ceros F, la cual se llenará con todos los clousters
                                                      que nacen en la frontera izquierda si scanning==1, para eso se usa la 
                                                      función hood, si scanning==0 se hace los mismo pero desde la derecha. */         
                                                      
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
///////////////////////////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////////////////////////////
Eigen::MatrixXd clouster_matrix(const Eigen::MatrixXd &I, int L){

  Eigen::MatrixXd F(L,L);//Creamos F llena de ceros.

  F = Path(I, L, 1, 1); //Se crean los caminos de números 1 desde la izquierda de la matriz que hay en la matriz I.

  Eigen::MatrixXd H(L,L);
  H= I.transpose();      

  Eigen::MatrixXd J(L,L);
  J = Path(H, L, 1, 1);
  Eigen::MatrixXd med(L, L);
  Eigen::MatrixXd F1(L,L);
  int Vclouster=0;
  int Hclouster=0;
  
  med = F + J.transpose();
  F1 = Path(med, L, 0, 2);

  for(int ii=0; ii<L; ++ii){

    if(F(ii, L-1)!=0){Vclouster=1;}
    if(J(ii, L-1)!=0){Hclouster=1;}
  }

  if(Vclouster==0){med = 2*J;
    return Path(med,L, 0, 2).transpose();}

    if(Hclouster==0){med = 2*F;
    return Path(med, L, 0, 2);}
  


   


  return F1;
  
  

 

                                  


  


  
    


}
//////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////

bool Percolation( const Eigen::MatrixXd &I, int L){
  
  int cont = 0;                                         /* Esta función está pensada para que reciba una matriz de percolación I, para
                                                        saber si el sistema percola, simplemente miramos una frontera vertical 
                                                        y una horizontal, si encontramos un número diferente de cero, el sistema 
                                                        tiene que ser uno percolante. */
  for (int ii =0; ii<L; ++ii ){
    if ( I(L-1, ii)!=0 || I(ii, L-1)!=0){cont = 1;

      break;

    }
  }

  if(cont!=0){return true;}

  else{return false;}
}
