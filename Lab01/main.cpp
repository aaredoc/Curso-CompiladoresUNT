#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<string>expresionRegular = {"11*", "11*"};
const char ESTRELLA_KLEENE = '*';
const int CANTIDAD_LENGUAJES =  4;

void imprimePantalla(vector<string> cadena){
    for(string elemento : cadena){
        cout << elemento << endl;
    }
}

vector<string> procesarCadena(string cadena, int iCantidadLenguajes){
    vector<string>lenguajeGenerado;
    if(!cadena.contains(ESTRELLA_KLEENE)){
        lenguajeGenerado.push_back(cadena);
    }else{
        lenguajeGenerado.emplace_back("");
        cadena.erase(std::remove(cadena.begin(), cadena.end(), ESTRELLA_KLEENE), cadena.end());

            for(int iter = 0; iter < iCantidadLenguajes; iter++){
                vector<string>nuevoLenguaje;
                for(int iCaracter = 0; iCaracter < lenguajeGenerado.size(); iCaracter++){
                    if(cadena.size() > 1){
                        nuevoLenguaje.push_back(lenguajeGenerado.at(iCaracter) + cadena.at(0));
                        nuevoLenguaje.push_back(lenguajeGenerado.at(iCaracter) + cadena.at(1));
                    }else{
                        nuevoLenguaje.push_back(lenguajeGenerado.at(iCaracter) + cadena.at(0));
                    }
                }
                lenguajeGenerado = nuevoLenguaje;
            }
    }
    return lenguajeGenerado;
}

vector<string> armaLenguaje(vector<string>leng0, vector<string>leng1){
    vector<string>lenguajeArmado;
    if(leng0.size() > leng1.size()){
        for(int i = 0; i < leng0.size(); i++){
            if(leng1.size() == 1){
                lenguajeArmado.push_back(leng0.at(i) + leng1.at(0));
            }else{
                lenguajeArmado.push_back(leng0.at(i) + leng1.at(leng0.at(i).size()-1));
            }
        }
    }else if(leng0.size() < leng1.size()){
        for(int i = 0; i < leng1.size(); i++){
            if(leng0.size() == 1){
                lenguajeArmado.push_back(leng0.at(0) + leng1.at(i));
            }else{
                lenguajeArmado.push_back(leng0.at(leng1.at(i).size()-1) + leng1.at(i));
            }
        }
    }else{
        for(int i = 0; i < leng0.size(); i++){
            lenguajeArmado.push_back(leng0.at(i) + leng1.at(i));
        }
    }
    return lenguajeArmado;
}

int main()
{
    vector<string>leng0;
    vector<string>leng1;
    vector<string>lenguajeArmado;
    for(int iCantidadLenguajes = 0; iCantidadLenguajes < CANTIDAD_LENGUAJES; iCantidadLenguajes++) {                    // GENERA LA CANTIDAD DE LENGUAJES REQUERIDOS
        leng0 = procesarCadena(expresionRegular.at(0), iCantidadLenguajes);                                  // PROCESA CADENA EN LA POSICION 0 DE LA EXPRESION REGULAR
        leng1 = procesarCadena(expresionRegular.at(1), iCantidadLenguajes);                                  // PROCESA CADENA EN LA POSICION 1 DE LA EXPRESION REGULAR
        lenguajeArmado = armaLenguaje(leng0, leng1);                                                                    // CONCATENA AMBAS CADENAS PROCESADAS
        imprimePantalla(lenguajeArmado);                                                                        // IMPRIME EN PANTALLA EL RESULTADO
    }
    return 0;
}