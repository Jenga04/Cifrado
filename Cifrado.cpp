// Cifrado.cpp: define el punto de entrada de la aplicación.
//

// C++ code to implement Vigenere Cipher
using namespace std;
#include <string>
#include "Cifrado.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
	
	ifstream file("comida.txt");
	string comida;
	file >> comida;
	cout << "Has comido :" << comida << endl;
	file.close();
}