#include <iostream>

using namespace std;

char matrix[35][35]; //inicializamos la matriz con un numero mayor que el maximo de la matriz para hacer algo que mas adelante se explicara
int mInM1[] = {-1, 1, 0, 0}; //este arreglo junto con el otro de abajo sirven para recorrer la matriz en cruz
int mInM2[] = {0, 0, -1, 1};

//  void impMatriz(int tam){
//      for(int i = 0; i <= tam+1;i++){
// 	 for(int j = 0; j <= tam+1; j++){   //Metodo para ver la matriz
// 	     cout << matrix[i][j];
// 	 }
// 	 cout << endl;
//      }

//  }

void pintarMatriz(int r, int c, int tam){
  if(r < 0 || r >= tam + 1 || c < 0 || c >= tam + 1) return;
  if(matrix[r][c] != '.') return;  // Metodo para saber cuales son los espacios libres y alcanzables
  matrix[r][c] = 'v';              //
  for(int d = 0; d < 4;d++){
    pintarMatriz(r + mInM1[d], c + mInM2[d], tam);
  }
  return;
}

int countWalls(int tam) {

  int walls = 0;

  for (int i = 0; i <= tam; i++) {

    for (int j = 0; j <= tam; j++) {

      if (matrix[i][j] == 'v') {

	for (int q = 0; q < 4; q++) {

	  if (matrix[i + mInM1[q]][j + mInM2[q]] != 'v') {
	    if (matrix[i + mInM1[q]][j + mInM2[q]] != '.') {

	      walls++;

	      matrix[i + mInM1[q]][j + mInM2[q]] = 'k';

	    }
	  }
	}

      }
    }
  }

  return walls;
}

void llenarMatriz(){
  for (int i = 0; i < 35; i++) {
    for (int j = 0; j < 35; j++) {
      matrix[i][j] = '*'; //se llena la matriz con * que indican bordes o limites
    }
  }
}

int main () {

  llenarMatriz();

  int tamano;
  int contador = 1;
  string ent;

  cin >> tamano; //lectura del tamaño de la matriz

  getline(cin, ent);

  for (int m = 0; m < tamano; m++) { //Estos for son para leer los caracteres del laberinto

    getline(cin, ent);

    for (int z = 1; z <= ent.size(); z++) {

      matrix[contador][z] = ent[z - 1];
    }

    contador++;

  }

  pintarMatriz(1, 1, tamano);

  pintarMatriz(tamano, tamano, tamano);

    //imprimirMatriz(tam); //Imprimir matriz : se utilizo para descubrir errores de codigo

  int salida = countWalls(tamano) - 4;

  cout << salida * 9 << endl;

  //imprimirMatriz(tam);

  return 0;
}
