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
void añadirEntrada(const string& nombreArchivo) {
    string texto, clave;
    cout << "Introduce el texto a cifrar: ";
    cin.ignore();
    getline(cin, texto);
    cout << "Introduzca la clave: ";
    cin >> clave;
    string textoCifrado = cifrarVigenere(texto, clave);
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo << "Texto original: " << texto << "\n";
        archivo << "Clave: " << clave << "\n";
        archivo << "Texto cifrado: " << textoCifrado << "\n\n";
        archivo.close();
        cout << "Entrada añadida correctamente." endl;
    }
    else {
        cout << "No se pudo abriri el archivo." << endl;
    }
}
