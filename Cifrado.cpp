// Cifrado.cpp: define el punto de entrada de la aplicación.
//

// C++ code to implement Vigenere Cipher
using namespace std;
#include <string>
#include "Cifrado.h"
#include <iostream>
#include <fstream>
#include <vector>
 
void listaEntradas(const string& nombreArchivo) {
    ifstream archivo ("resultado.txt");
    if (archivo.is_open()) {
        string linea;
        int lineaNum = 1;
        while (getline(archivo, linea)) {
            cout << lineaNum++ << ":" << linea << endl;
        }
        archivo.close();
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
    ofstream archivo("resultado.txt", ios::app);
    if (archivo.is_open()) {
        archivo << "Texto original: " << texto << "\n";
        archivo << "Clave: " << clave << "\n";
        archivo << "Texto cifrado: " << textoCifrado << "\n\n";
        archivo.close();
        cout << "Entrada añadida correctamente." << endl;
    }
    else {
        cout << "No se pudo abriri el archivo." << endl;
    }
}
void borrarEntrada(const string& nombreArchivo) {
    ifstream archivo("resultado.txt");
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }
    vector<string> lineas;
    string linea;
    while (getline(archivo, linea)) {
        lineas.push_back(linea);
    }
    archivo.close();

    listaEntradas("resultado.txt");
    cout << "Introduce el número de la línea que deseas borrar: ";
    int numLinea;
    cin >> numLinea;

    if (numLinea < 1 || numLinea > static_cast<int>(lineas.size())) {
        cout << "Número de línea no válido." << endl;
        return;
    }

    ofstream archivoSalida("resultado.txt", ios::trunc);
    if (archivoSalida.is_open()) {
        for (size_t i = 0; i < lineas.size(); ++i) {
            if (i != static_cast<size_t>(numLinea - 1)) {
                archivoSalida << lineas[i] << endl;
            }
        }
        archivoSalida.close();
        cout << "Línea borrada correctamente." << endl;
    }
    else {
        cout << "No se pudo escribir en el archivo." << endl;
    }
}
void borrarArchivo(const string & nombreArchivo) {
    ofstream archivo("resultado.txt", ios::trunc);
    if (archivo.is_open()) {
        archivo.close();
        cout << "Archivo borrado correctamente." << endl;
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

