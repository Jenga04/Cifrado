// Cifrado.cpp: define el punto de entrada de la aplicación.
//

// C++ code to implement Vigenere Cipher
using namespace std;
#include <string>
#include "Cifrado.h"
#include <iostream>
#include <fstream>
#include <vector>
 
void listaEntradas(const string& archivo) {
    ifstream inputFile(archivo);
    if (inputFile.is_open()) {
        string linea;
        cout << "Estas son tus entradas: " << endl;
        while (getline(inputFile, linea)) {
            cout << linea << endl;
        }
        inputFile.close();
    }
    else {
        cout << "El archivo no existe" << endl;
    }
}