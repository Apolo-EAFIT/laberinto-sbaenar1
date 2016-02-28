#include <iostream>

using namespace std;

char matriz[35][35]; //inicializamos la matriz con un numero mayor que el maximo de la matriz para hacer algo que mas adelante se explicara
int dr[] = {-1,1,0,0}; //este arreglo junto con el otro de abajo sirven para recorrer la matriz en cruz
int dc[] = {0,0,-1,1};

void imprimirMatriz(int tam){
    for(int i = 0; i <= tam+1;i++){
        for(int j = 0; j <= tam+1; j++){   //Metodo para ver la matriz
            cout << matriz[i][j];
        }
        cout << endl;
    }

}

void floodfill(int r,int c, int tam){
    if(r < 0 || r >= tam + 1 || c < 0 || c >= tam + 1) return;
    if(matriz[r][c] != '.') return;  // Metodo para saber cuales son 
    matriz[r][c] = 'v';              //
    for(int d = 0; d < 4;d++){
        floodfill(r + dr[d], c + dc[d],tam);
    }
    return;
}

int countWalls(int tam) {

    int walls = 0;

    for (int i = 0; i <= tam; i++) {

        for (int j = 0; j <= tam; j++) {

            if (matriz[i][j] == 'v') {

                for (int q = 0; q < 4; q++) {

                    if (matriz[i + dr[q]][j + dc[q]] != 'v' && matriz[i + dr[q]][j + dc[q]] != '.') {

                        walls++;

                        matriz[i + dr[q]][j + dc[q]] = 'k';

                    }
                }

            }
        }
    }

    return walls;
}

int main () {

    for (int i = 0; i < 35; i++) {
        for (int j = 0; j < 35; j++) {
            matriz[i][j] = '*'; //se llena la matriz con . que indican bordes o limites
        }
    }

    int tam;
    int contador = 1;
    string entrada;

    cin >> tam; //lectura del tamaño de la matriz

    getline(cin, entrada);

    for (int m = 0; m < tam; m++) { //Estos for son para leer los caracteres del laberinto

        getline(cin, entrada);

        for (int z = 1; z <= entrada.size(); z++) {

            matriz[contador][z] = entrada[z-1];
        }

        contador++;

    }

    floodfill(1,1,tam);
    floodfill(tam,tam,tam);
    //imprimirMatriz(tam); //Imprimir matriz : se utilizo para descubrir errores de codigo
    int salida = countWalls(tam) - 4;
    cout << salida * 9 << endl;
    //imprimirMatriz(tam);

    return 0;
}
