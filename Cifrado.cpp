#include <string>
#include "Cifrado.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Windows.h"
using namespace std;

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

void listaEntradas(const vector<string>& entradas) {
    if (entradas.empty()) {
        cout << "No hay entrada disponible." << endl;
    }
    else {
        for (size_t i = 0; i < entradas.size(); i++) {
            cout << i + 1 << ":" << entradas[i] << endl;
        }
    }       
}
void añadirEntrada(const string& nombreArchivo, vector<string>& entradas) {
    string texto, clave;
    cout << "Introduce el texto a cifrar: ";
    cin.ignore();
    getline(cin, texto);
    cout << "Introduzca la clave: ";
    cin >> clave;
    string textoCifrado = cifrado(texto, clave);
    entradas.push_back(texto);
    ofstream archivo(nombreArchivo, ios::app);
    if (archivo.is_open()) {
        archivo << textoCifrado << endl;
        archivo.close();
        cout << "Entrada añadida correctamente." << endl;
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
void borrarEntrada(const string& nombreArchivo, vector<string>& entradas) {
    if (entradas.empty()) {
        cout << "No hay entradas para borrar." << endl;
        return;
    }

    listaEntradas(entradas);
    cout << "Introduce el número de la entrada que deseas borrar: ";
    int numEntrada;
    cin >> numEntrada;

    if (numEntrada < 1 || numEntrada > static_cast<int>(entradas.size())) {
        cout << "Número de entrada no válido." << endl;
        return;
    }

    entradas.erase(entradas.begin() + (numEntrada - 1));

    ofstream archivo(nombreArchivo, ios::trunc);
    if (archivo.is_open()) {
        for (const string& entrada : entradas) {
            string textoCifrado = cifrado (entrada, "clavePorDefecto"); 
            archivo << textoCifrado << endl;
        }
        archivo.close();
        cout << "Entrada borrada correctamente." << endl;
    }
    else {
        cout << "No se pudo escribir en el archivo." << endl;
    }
}
void borrarArchivo(const string& nombreArchivo, vector<string>& entradas) {
    ofstream archivo(nombreArchivo, ios::trunc);
    if (archivo.is_open()) {
        archivo.close();
        entradas.clear();
        cout << "Archivo borrado correctamente." << endl;
    }
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}
void mostrarMenú() {
    cout << "\n Menú" << endl;
    cout << "1: Lista de entradas" << endl;
    cout << "2: Añadir entrada" << endl;
    cout << "3: Borrar entrada" << endl;
    cout << "4: Borrar archivo" << endl;
    cout << "0: Salir" << endl;
    cout << "Seleccione una opción: ";
}
int main() {
    SetConsoleOutputCP(1252);
    string nombreArchivo = "resultado.txt";
    vector <string> entradas;
    int opcion;

    do {
        mostrarMenú();
        cin >> opcion;

        switch (opcion) {
        case 1:
            listaEntradas(entradas);
            break;
        case 2:
            añadirEntrada(nombreArchivo, entradas);
            break;
        case 3:
            borrarEntrada(nombreArchivo, entradas);
            break;
        case 4:
            borrarArchivo(nombreArchivo, entradas);
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
