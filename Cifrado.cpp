// Cifrado.cpp: define el punto de entrada de la aplicación.
//

// C++ code to implement Vigenere Cipher
using namespace std;
#include <string>
#include "Cifrado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Windows.h"

string cifrado(const string& texto, const string& clave) {
    string textoCifrado = texto;
    int n = clave.length();

    for (size_t i = 0; i < texto.length(); ++i) {
        if (isalpha(texto[i])) {
            char base = isupper(texto[i]) ? 'A' : 'a';
            char baseClave = isupper(clave[i % n]) ? 'A' : 'a';
            textoCifrado[i] = ((texto[i] - base + (clave[i % n] - baseClave)) % 26) + base;
        }
    }
    return textoCifrado;
}
 
void listaEntradas(const string& nombreArchivo) {
    ifstream archivo (nombreArchivo);
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
    string textoCifrado = cifrado(texto, clave);
    ofstream archivo(nombreArchivo, ios::app);
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
    ifstream archivo(nombreArchivo);
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

    listaEntradas(nombreArchivo);
    cout << "Introduce el número de la línea que deseas borrar: ";
    int numLinea;
    cin >> numLinea;

    if (numLinea < 1 || numLinea > static_cast<int>(lineas.size())) {
        cout << "Número de línea no válido." << endl;
        return;
    }

    ofstream archivoSalida(nombreArchivo, ios::trunc);
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
    ofstream archivo(nombreArchivo, ios::trunc);
    if (archivo.is_open()) {
        archivo.close();
        cout << "Archivo borrado correctamente." << endl;
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
int main() {
    SetConsoleOutputCP(1252);
    string nombreArchivo = "resultado.txt";
    int opcion;

    do {
        cout << "\n Menú" << endl;
        cout << "1: Lista de entradas" << endl;
        cout << "2: Añadir entrada" << endl;
        cout << "3: Borrar entrada" << endl;
        cout << "4: Borrar archivo" << endl;
        cout << "0: Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            listaEntradas(nombreArchivo);
            break;
        case 2:
            añadirEntrada(nombreArchivo);
            break;
        case 3:
            borrarEntrada(nombreArchivo);
            break;
        case 4:
            borrarArchivo(nombreArchivo);
            break;
        case 0:
            cout << "Saliendo del programa." << endl;
            break;
        default:
            cout << "Opción no disponible, por favor, elija una opción válida" << endl;
        }
    } while (opcion != 0);

    return 0;
}

