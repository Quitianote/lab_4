#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>

#define INF 999

using namespace std;

void printMatrix(int matrix[][99], int nV);//imprime la matriz
void floydWarshall(int graph[][99], int nV);//algoritmo de floyd
void leernodo(char reng[],map <string, vector<string>> &mapa,  map <string, int> &info, int ubi);//leer archivo de conexiones

class clase{
    private:
        bool aux;
<<<<<<< HEAD
        int tam;//cantidad de nodos
=======
        int cant_nod;//cantidad de nodos
>>>>>>> 7b6a42c405a0c036a20f15924510a57510611f28

    public:
        clase();
        clase(bool);//constructor booleano
        bool verificar_numero();//metodo para verificar si el usuario coloco la opcion correcta, recibe una matriz con los numeros y un numero con el tamaño de la matriz
<<<<<<< HEAD
        void settam(int _tam);
        int gettam();
        void crear_matriz(int _matriz[][99], map <string, vector<string>> &_nodos);//metodo que crea matriz a partir del mapa con los nodos
        void agregar_nodo(map <string, vector<string>> &_nodos, string nodo, int matriz[][99]);
=======
        void crear_matriz(int _matriz[][99], int tam, map <string, vector<string>> &_nodos);//metodo que crea matriz a partir del mapa con los nodos
>>>>>>> 7b6a42c405a0c036a20f15924510a57510611f28
        //puedo crear un metodo para escribir en el archivo a la hora de editar los nodos o mejor edito el mapa directamente, tiene que ser con punteros
        //puedo crear un metodo que verifique que mi nodo no quede desconectado de los demas

};

clase::clase(){}//metodo sin argumentos

clase::clase(bool _aux){//booleano
    aux = _aux;
}

<<<<<<< HEAD
void clase::settam(int _tam){
    tam = _tam;
}

int clase::gettam(){
    return tam;
}

void clase::crear_matriz(int _matriz[][99], map <string, vector<string>> &_nodos){//crear matriz para lo de floyd, pide el arreglo a modificar, la matriz donde se guardara los datos y el tamaño
=======
void clase::crear_matriz(int _matriz[][99], int tam, map <string, vector<string>> &_nodos){//crear matriz para lo de floyd, pide el arreglo a modificar, la matriz donde se guardara los datos y el tamaño
>>>>>>> 7b6a42c405a0c036a20f15924510a57510611f28
    int fil = 0;
    int col = 0;
    map<string,vector<string>>::iterator
      mit (_nodos.begin()),
      mend(_nodos.end());
        for(;mit!=mend;++mit){
            cout << mit->first << endl;
            for(vector<string>::iterator i= mit->second.begin(); i != mit->second.end() ;i++){
                cout<< "valor de i: " << *i<<endl;
                if(*i == "INF") _matriz[fil][col] = INF;//si es infinito
                else{
                    _matriz[fil][col] = stoi(*i);//cuando no es infinito
                }
                col ++;
            }
            fil ++;
            col = 0;
        }
}

<<<<<<< HEAD
void clase::agregar_nodo(map <string, vector<string>> &_nodos, string nodo,int matriz[][99]){//pido el mapa de los nodos, el nombre y las conexiones
    vector<string> vect;
    map<string,vector<string>>::iterator
      mit (_nodos.begin()),
      mend(_nodos.end());
    int i = 0;

    for(;mit!=mend;++mit){//recorrer mapa
        cout << mit->first << endl;
        if(matriz[0][i] == INF) _nodos[mit->first].push_back("INF");//si es INF
        else _nodos[mit->first].push_back(to_string(matriz[0][i]));//cuando es int

        i ++;
    }
    //ahora agregar vector
    for(i = 0; i < tam; i ++){//agrego los elementos de la matriz en un vector que luego sera agregado en el mapa
        vect.push_back(to_string(matriz[0][i]));
    }
    _nodos[nodo] = vect;


}









=======
>>>>>>> 7b6a42c405a0c036a20f15924510a57510611f28
int main(){
    ifstream archivo_nodos;
    char reng[256];
    int ubi = 0;//ubicacion de nodo en vector
    int cant_nod;
    int matriz[][99] = {};//matriz para floyd
    string nom;
    clase graph;


    map <string, vector<string>> nodos;//conexiones
    map <string, int> info;//donde tendre la ubiccaion de las conexiones en la matriz
    archivo_nodos.open("nodos.txt");

    while(archivo_nodos.good()){//leer archivo
        archivo_nodos.getline(reng, 256);
        leernodo(reng, nodos, info, ubi);
        ubi ++;
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

    map<string,int>::iterator
      it (info.begin()),
      end(info.end());
        for(;it!=end;++it){
            cout << it->first << endl;
            cout << info[it->first] << endl;
        }
<<<<<<< HEAD

    //ahora a calcular el camino mas rapido
    cant_nod = ubi;//la cantidad de nodos es ubim, ya que ubi aumenta de mas y consigue el valor de cant_nod, revisa la parte donde se lee el archivo
    graph.settam(cant_nod);
    graph.crear_matriz(matriz, nodos);

    printMatrix(matriz, graph.gettam());

    floydWarshall(matriz, graph.gettam());

    //ahora eliminar nodos o agregarlos
    //agregar nodos
    int prueba[][99] = {{INF, INF, 3, 2, 0}};

    nom = 'E';
    cout << "ANTES DE CREAR: " << endl;
    graph.agregar_nodo(nodos, nom, prueba);
    graph.settam(++cant_nod);
    cout << "despues de crear: " << endl;
    ubi = graph.gettam();
    info[nom] = ubi;//actualizando info
    graph.crear_matriz(matriz, nodos);//creando matriz para prueba
    printMatrix(matriz, graph.gettam());//imprimiendo matriz


=======
    //ahora a calcular el camino mas rapido
    cant_nod = ubi;//la cantidad de nodos es ubim, ya que ubi aumenta de mas y consigue el valor de cant_nod, revisa la parte donde se lee el archivo
    graph.crear_matriz(matriz, cant_nod, nodos);
    floydWarshall(matriz, cant_nod);
    //ahora eliminar nodos o agregarlos
>>>>>>> 7b6a42c405a0c036a20f15924510a57510611f28



    return 0;
}

void leernodo(char reng[],map <string, vector<string>> &mapa,  map <string, int> &info, int ubi){//leer renglon de nodos, es necesario el ampersan para editar directamente el mapa, eso encontre
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
            info[nom] = ubi;
            break;
        }
    }
}

//FLOYD ALGORITMO

void floydWarshall(int graph[][99], int nV) {
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
  //pasar todos los valores de matrix a graph(matriz original)
  for(int i = 0; i < nV; i ++){
      for(int j = 0; j < nV; j ++){
          graph[i][j] = matrix[i][j];
      }
  }

  printMatrix(matrix, nV);
}

void printMatrix(int matrix[][99], int nV) {
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


//METODOS DE LA CLASE "CLASE"


