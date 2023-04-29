#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#define INF 999

using namespace std;

void printMatrix(int matrix[][99]);//imprime la matriz
void floydWarshall(int graph[][99]);//algoritmo de floyd
void leernodo(char reng[],map <string, vector<string>> &mapa);//leer archivo de conexiones

class verificar{

};

int main(){
    ifstream archivo_nodos;
    char reng[256];
    int ubi = 0;//ubicacion de nodo en vector

    map <string, vector<string>> nodos;//conexiones
    map <string, int> info;//donde tendre la ubiccaion de las conexiones en la matriz
    archivo_nodos.open("nodos.txt");

    while(archivo_nodos.good()){
        archivo_nodos.getline(reng, 256);
        leernodo(reng, nodos);
        ubi ++;
        //aqui agrego el nombre del nodo(extraido del mapa nodos) con el valor de ubi
    }
    map<string,vector<string>>::iterator
      mit (nodos.begin()),
      mend(nodos.end());
        for(;mit!=mend;++mit){
            cout << mit->first << endl;
            for(vector<string>::iterator i= mit->second.begin(); i != mit->second.end() ;i++){
                cout<< *i<<endl;
            }
        }

    return 0;
}

void leernodo(char reng[],map <string, vector<string>> &mapa){//leer renglon de nodos, es necesario el ampersan para editar directamente el mapa, eso encontre
    int pos = 0;
    int cont = 4;
    bool aux = false;
    string nom = "";//string con nombre de conexion
    string cone = "";//string temporal donde estaran
    vector<string> nod;//vector con nodos

    for(int i = 0; i < 256; i ++){
        if(reng[i] == '*'){//nombre de nodo
            for(int a = i + 1; a < 256; a ++){//nombre de nodo
                if(reng[a] != ','){
                    nom.append(1, reng[a]);//armando nombre
                }
                else break;
            }
        }
        else if(reng[i] == ','){//conexiones
            for(int a = i + 1; a < 256; a ++){//creando conexiones
                if(reng[a] != ',' && reng[a] != '-'){//creando conexion, agrego los elementos en un string que luego agregare en el vector, el vector lo usare como matriz
                    if(reng[a] == '/') cone.append("INF");
                    else cone.append(1, reng[a]);
                }
                else{//finalizacion de creacion de valor de conexion
                    nod.push_back(cone);
                    cone = "";
                    break;
                }
            }
        }
        else if(reng[i] == '-'){
            mapa[nom] = nod;
            for(int i = 0; i < 4; i ++){
            }
            break;
        }
    }
}

//FLOYD ALGORITMO

void floydWarshall(int graph[][99]) {
  int nV = 4;
  int matrix[99][99], i, j, k;

  for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
      matrix[i][j] = graph[i][j];

  // Adding vertices individually
  for (k = 0; k < nV; k++) {
    for (i = 0; i < nV; i++) {
      for (j = 0; j < nV; j++) {
        if (matrix[i][k] + matrix[k][j] < matrix[i][j])
          matrix[i][j] = matrix[i][k] + matrix[k][j];
      }
    }
  }
  printMatrix(matrix);
}

void printMatrix(int matrix[][99]) {
  int nV = 4;
  for (int i = 0; i < nV; i++) {
    for (int j = 0; j < nV; j++) {
      if (matrix[i][j] == INF)
        printf("%4s", "INF");
      else
        printf("%4d", matrix[i][j]);
    }
    printf("\n");
  }
}
/*
int main() {
  int nV = 4;
  int graph[99][99] = {{0, 5, 3, INF},
             {5, 0, 1, INF},
             {3, 1, 0, 7},
             {INF, INF, 7, 0}};
  floydWarshall(graph);
}
*/
