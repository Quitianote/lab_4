#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main(){
    ifstream archivo_nodos;
    map <char, vector<char>> nodos;

    archivo_nodos.open("nodos.txt");

    cout << "Hello World!" << endl;
    return 0;
}

void leernodo(char reng[], map <string, int>& mapa, char codi[]){//leer renglon de nodos
    int pos = 0;
    int cont = 4;
    bool aux = false;

    for(int i = 0; i < 256; i ++){
        if(reng[i] == '*'){//codigo
            for(int a = i + 1; a < 256; a ++){//creando codigo
                if(reng[a] != '!'){
                    mat[0][pos] = reng[a];//posicion en la matriz
                    //cout << mat[0] << " codigo" << endl;
                    char temp1 = mat[0][pos];
                    char temp2 = codi[pos];
                    if(temp1 != temp2) return false;
                    pos ++;

                }
                else break;
            }
        }
        else if(reng[i] == '!'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando nombre de materia
                if(reng[a] != '#'){
                    //cout << mat[1] << " nombre1" << endl;
                    //cout << reng[a] << " letra de renglon" << endl;
                    mat[1][pos] = reng[a];
                   // cout << a << " a" << endl;
                   // cout << mat[1] << " nombre" << endl;
                    pos ++;//posicion en la matriz
                }
                else{
                    mat[1][pos] = '\0';
                    break;
                }

            }
        }
        else if(reng[i] == '#'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando numero de horas docente
                if(reng[a] != '?'){
                    mat[2][pos] = reng[a];
                    //cout << a << " a" << endl;
                    //cout << mat[2] << " numero" << endl;
                    pos ++;//posicion en matriz
                }
                else break;
            }
        }
        else if(reng[i] == '?'){
            pos = 0;
            for(int a = i + 1; a < 256; a ++){//creando creditos
                if(reng[a] != '/'){
                    mat[3][pos] = reng[a];
                   // cout << a << " a" << endl;
                    //cout << mat[3] << " numero" << endl;
                    pos ++;//posicion en matriz
                }
                else break;
            }
        }
        else if(reng[i] == '-'){//final de materia
            break;
        }
    }
    return true;
}
