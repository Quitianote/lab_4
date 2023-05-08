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

        int tam;//cantidad de nodos

        int cant_nod;//cantidad de nodos


    public:
        clase();
        clase(bool);//constructor booleano

        int gettam();

        bool verificar_numero();//metodo para verificar si el usuario coloco la opcion correcta, recibe una matriz con los numeros y un numero con el tamaño de la matriz
        bool solitario(map<string, vector<string> > &_nodos, map<string, int> &info, string nodo);

        void settam(int _tam);
        void agregar_nodo(map <string, vector<string>> &_nodos, string nodo, int matriz[][99]);
        void eliminar_nodo(map <string, vector<string>> &_nodos, map <string, int> &info, string nodo);
        void crear_matriz(int _matriz[][99], map <string, vector<string>> &_nodos);//metodo que crea matriz a partir del mapa con los nodos


};



int main(){
    ifstream archivo_nodos;
    ifstream red;
    ofstream modifi;
    char reng[256];
    int conexion = 0;
    int ubi = 0;//ubicacion de nodo en vector
    int cant_nod;
    int matriz[][99] = {};//matriz para floyd
    int conexiones[][99] = {};//matriz para el nodo que se vaya a agregar
    string nom;
    string opcion;
    string nom_red;
    clase graph;


    map <string, vector<string>> nodos;//conexiones
    map <string, int> info;//donde tendre la ubiccaion de las conexiones en la matriz
/*
    archivo_nodos.open("nodos.txt");

    while(archivo_nodos.good()){//leer archivo
        archivo_nodos.getline(reng, 256);
        leernodo(reng, nodos, info, ubi);
        ubi ++;
    }
    map<string,vector<string>>::iterator//imprimir el mapa
      mit (nodos.begin()),
      mend(nodos.end());
        for(;mit!=mend;++mit){
            cout << mit->first << endl;
            for(vector<string>::iterator i= mit->second.begin(); i != mit->second.end() ;i++){
                cout<< *i<<endl;
            }
        }
    cout << "info" << endl;//imprimir info
    map<string,int>::iterator
      it (info.begin()),
      end(info.end());
        for(;it!=end;++it){
            cout << it->first << endl;
            cout << info[it->first] << endl;
        }
*/
//AQUI COMIENZO LAS PRUEBAAAAAAAAAAAAAAAAAAS
    //ahora a calcular el camino mas rapido
/*    cant_nod = ubi;//la cantidad de nodos es ubi, ya que ubi aumenta de mas y consigue el valor de cant_nod, revisa la parte donde se lee el archivo
    graph.settam(cant_nod);
    graph.crear_matriz(matriz, nodos);

    printMatrix(matriz, graph.gettam());

    floydWarshall(matriz, graph.gettam());
*///calculos de prueba con la CLASEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
    /*

    //ahora eliminar nodos o agregarlos
    //agregar nodos
    int prueba[][99] = {{INF, INF, 3, 2, 0}};

    nom = 'E';
    cout << "ANTES DE CREAR: " << endl;
    graph.agregar_nodo(nodos, nom, prueba);
    graph.settam((1 + graph.gettam()));
    cout << "despues de crear: " << endl;
    cout << "UBI: " << ubi << endl;
    ubi = (graph.gettam() - 1);
    info[nom] = ubi;//actualizando info
    graph.crear_matriz(matriz, nodos);//creando matriz para prueba
    printMatrix(matriz, graph.gettam());//imprimiendo matriz



    //ahora a calcular el camino mas rapido
    cant_nod = ubi;//la cantidad de nodos es ubim, ya que ubi aumenta de mas y consigue el valor de cant_nod, revisa la parte donde se lee el archivo
    graph.crear_matriz(matriz, nodos);

    floydWarshall(matriz, cant_nod);
    //ahora eliminar nodos o agregarlos
    nom = 'A';

    graph.eliminar_nodo(nodos, info, nom);
    graph.settam((graph.gettam() - 1));
    graph.crear_matriz(matriz, nodos);

    printMatrix(matriz, graph.gettam());

    //AGREGANDO OTRO NODO PARA PRUEBAS CON NODOS SOLITARIOS
    nom = 'F';
    int prueba2[][99] = {{5, INF, INF, INF, 0}};
    graph.agregar_nodo(nodos, nom, prueba2);
    info[nom] = graph.gettam();//agrego nuevo nodo a info
    graph.settam((graph.gettam( )+ 1));//aumento el tamaño de tam

    cout << "info 2 " << endl;
    it = info.begin();
    for(;it!=end;++it){
        cout << it->first << endl;
        cout << info[it->first] << endl;
    }
    nom = 'B';
    bool aux = graph.solitario(nodos, info, nom);
    if(aux)cout << "se puede eliminar: " << endl;
    else cout << "no se puede eliminar: " << endl;
*/


    //creando menu
    while(true){
        clase matrix;
        cout << "**********MENU***********" << endl << "Ingrese nombre de archivo o '0' si desea salir: ";cin >> nom_red;

        if(nom_red != "0"){
                red.open(nom_red);

                while(red.good()){//leer archivo
                    red.getline(reng, 256);
                    leernodo(reng, nodos, info, ubi);
                    ubi ++;
                }

                matrix.settam(ubi);
                matrix.crear_matriz(matriz, nodos);

                cout << endl;

                map<string,vector<string>>::iterator//imprimir el mapa
                  mit (nodos.begin()),
                  mend(nodos.end());
                    for(;mit!=mend;++mit){
                        cout << "---" << mit->first ;
                    }
                    cout << endl;

                printMatrix(matriz, matrix.gettam());

                cout << endl;

                while(true){

                    cout << "Ingrese: " << endl << "'0' si desea volver." << endl << "'1' si desea calcular la matriz con los caminos mas rapidos." << endl << "'2' si desea agregar un nodo." << endl << "'3' si desea eliminar un nodo." << endl << "'4' si desea conocer el coste de enviar un paquete de origen a uno destino." << endl << "'5' si desea conocer el coste EFICIENTE para enviar un paquete de un origen a un destino." << endl << "'6' si desea imprimir la matriz normal" << endl << endl; cin >> opcion;

                    if(opcion == "0"){//volver
                        map<string,vector<string>>::iterator//escribo mapa en archivo de nodos
                          ites (nodos.begin()),
                          endes(nodos.end());

                        red.close();
                        modifi.open(nom_red);
                        while(ites != endes){
                            modifi << '*';
                            modifi << ites->first;
                            for(vector<string>::iterator elem = ites->second.begin(); elem != ites->second.end(); elem ++){
                                cout << *elem;
                                cout << endl;
                                modifi << ',';
                                if(*elem != "INF" && *elem != "999") modifi << *elem;
                                else modifi << '/';
                            }
                            modifi << '-';
                            modifi << '\n';
                            ites ++;
                        }

                        modifi.close();

                        nodos.clear();
                        info.clear();
                        break;
                    }
                    else if(opcion == "1"){//calcular camino mas rapido
                        cout << endl;

                        mit = nodos.begin();
                        //imprimir mapa
                        for(;mit!=mend;++mit){
                            cout << "---" << mit->first ;
                        }
                        cout << endl;

                        floydWarshall(matriz, matrix.gettam());

                        cout << endl;
                    }
                    else if(opcion == "2"){//agregar nodo
                        int i = 1;
                        cout << "Ingrese nombre del nodo: ";cin >> nom;
                        mit = (nodos.begin());
                        cout << "Ingrese coste de conexion con el nodo " << mit->first << " (si el coste es infinito escribir 999): ";cin >> conexion;
                        int temp = conexion;//forma que encontre para solucionar problema con primer elemento
                        mit ++;
                        for(; mit != mend; mit ++){
                            cout << "Ingrese coste de conexion con el nodo " << mit->first << " (si el coste es infinito escribir 999): ";cin >> conexion;
                            conexiones[0][i] = conexion;
                            i ++;

                        }
                        conexiones[0][0] = temp;
                        conexiones[0][i] = 0;

                        cout << endl;

                        info[nom] = graph.gettam();
                        matrix.settam((matrix.gettam() + 1));
                        matrix.agregar_nodo(nodos, nom, conexiones);
                        matrix.crear_matriz(matriz, nodos);
                        map<string,vector<string>>::iterator//imprimir el mapa
                          mit (nodos.begin()),
                          mend(nodos.end());
                            for(;mit!=mend;++mit){
                                cout << "---" << mit->first ;
                            }
                            cout << endl;
                        printMatrix(matriz, matrix.gettam());

                        cout << endl;
                    }
                    else if(opcion == "3"){//eliminar nodo
                        bool aux = false;
                        mit = (nodos.begin());

                        cout << endl;
                        cout << "Ingrese nombre del nodo a eliminar: ";cin >> nom;
                        aux = matrix.solitario(nodos, info, nom);

                        while(!aux){
                            cout << "ERROR::El nodo esta anidado a un nodo solitario: ";cin >> nom;
                            aux = matrix.solitario(nodos, info, nom);
                        }

                        matrix.eliminar_nodo(nodos, info, nom);
                        matrix.settam((matrix.gettam() - 1));
                        matrix.crear_matriz(matriz, nodos);

                        cout << endl;

                        map<string,vector<string>>::iterator//imprimir el mapa
                          mit (nodos.begin()),
                          mend(nodos.end());
                            for(;mit!=mend;++mit){
                                cout << "---" << mit->first ;
                            }
                            cout << endl;
                        printMatrix(matriz, matrix.gettam());

                        cout << endl;

                    }
                    else if(opcion == "4"){//conocer coste de envio

                    }
                    else if(opcion == "5"){//conocer coste de envio EFICIENTE

                    }


            }
        }
        else break;
    }

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

//METODOS DE LA CLASE "CLASE"


clase::clase(){}//metodo sin argumentos

clase::clase(bool _aux){//booleano
    aux = _aux;
}


void clase::settam(int _tam){
    tam = _tam;
}

int clase::gettam(){
    return tam;
}

bool clase::solitario(map<string, vector<string> > &_nodos, map<string, int> &info, string nodo){
    int pos = 0;
    int cont = 0;
    size_t j = 0;

    cout << "SOLITARIO;; " << endl;

    map<string,int>::iterator
        it (info.begin()),
        end (info.end());
    for (size_t i = 0; i < _nodos[nodo].size(); i ++) {//size_t tipo de dato que almacena tamaños de arreglos y esas cosas
        if(_nodos[nodo][i] != "0" && _nodos[nodo][i] != "INF" && _nodos[nodo][i] != "999"){//si la conexion es diferente de 0 y diferente de infinito
            for (; it != end; it ++){//recorriendo info
                if(info[it->first] == pos){//mirando si la posicion del nodo es la misma que la del nodo que esta conectado al nodo que voy a eliminar
                    for (; j < _nodos[it->first].size(); j ++){//recorro el vector para mirar si esta conectado solo a ese nodo o a mas nodos
                        if(_nodos[it->first][j] == "INF" || _nodos[it->first][j] == "999") cont ++;
                    }
                    if(tam - cont == 2) return false;
                    pos ++;
                    cont = 0;
                    break;
                }
            }
            j = 0;
            it = (info.begin());
        }
        else{
            pos ++;
        }
    }
    return true;
}

void clase::crear_matriz(int _matriz[][99], map <string, vector<string>> &_nodos){//crear matriz para lo de floyd, pide el arreglo a modificar, la matriz donde se guardara los datos y el tamaño

    int fil = 0;
    int col = 0;

    cout << "CREAR MATRIZ;; " << endl;

    map<string,vector<string>>::iterator
      mit (_nodos.begin()),
      mend(_nodos.end());
        for(;mit!=mend;++mit){
            for(vector<string>::iterator i= mit->second.begin(); i != mit->second.end() ;i++){
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


void clase::agregar_nodo(map <string, vector<string>> &_nodos, string nodo,int matriz[][99]){//pido el mapa de los nodos, el nombre y las conexiones
    vector<string> vect;
    map<string,vector<string>>::iterator
      mit (_nodos.begin()),
      mend(_nodos.end());
    int i = 0;

    cout << "AGREGAR NODO;; " << endl;

    for(;mit!=mend;++mit){//recorrer mapa
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

void clase::eliminar_nodo(map<string, vector<string> > &_nodos, map<string, int> &info, string nodo){
    int pos = 0;
    bool aux = false;

    cout << "ELIMINAR NODO;; " << endl;

    _nodos.erase(nodo);
    map<string,vector<string>>::iterator
      mit (_nodos.begin()),
      mend(_nodos.end());
        for(;mit!=mend;++mit){
            for(vector<string>::iterator i= mit->second.begin(); i != mit->second.end() ;i++){
                if(pos == info[nodo]){
                    _nodos[mit->first].erase(i);
                    break;
                }
                pos ++;
            }
            pos = 0;
        }

    pos = info[nodo];//obtengo posicion del nodo que elimine
    info.erase(nodo);//elimino nodo de informacion
    map<string,int>::iterator//modificando ubicaciones de nodos en info
        it (info.begin()),
        end (info.end());
        for(;it != end; it ++){
            if(aux || info[it->first] == ++pos){
                info[it->first] --;
                aux = true;
            }
        }
    cout << "FINALIZO CORRECTAMENTE" << endl;
}

