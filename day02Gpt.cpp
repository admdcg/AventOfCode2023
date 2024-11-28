#include <iostream>
#include <string>
#include <unordered_map>
#include <cctype> // Para isdigit
#include <fstream>

using namespace std;

// Función para identificar si una palabra es un número escrito
int wordToDigit(const string &word) {
    static unordered_map<string, int> wordToNum = {
        {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
        {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };

    auto it = wordToNum.find(word);
    return (it != wordToNum.end()) ? it->second : -1;
}

// Función principal
int main() {
    string line;
    int totalSum = 0;
    std::ifstream inFile;

    inFile.open("dia02Test.txt");
	if (!inFile) {
		std::cout << "Unable to open file";
		return EXIT_FAILURE;  // terminate with error
	}    
    

    // Leer las líneas hasta que el usuario introduzca "FIN"
    while (getline(inFile, line)) {
        if (line == "FIN") break;

        int firstDigit = -1, lastDigit = -1;
        string currentWord = "";

        // Procesar la línea carácter por carácter
        for (size_t i = 0; i <= line.length(); ++i) {
            char c = (i < line.length()) ? line[i] : ' '; // Añadir un espacio al final para procesar la última palabra

            if (isalpha(c)) {
                currentWord += c; // Construir una palabra
            } else {
                if (!currentWord.empty()) {
                    // Verificar si la palabra es un número escrito
                    int num = wordToDigit(currentWord);
                    if (num != -1) {
                        if (firstDigit == -1) {
                            firstDigit = num; // Guardar el primer "dígito"
                        }
                        lastDigit = num; // Actualizar el último "dígito"
                    }
                    currentWord = ""; // Reiniciar la palabra actual
                }
                if (isdigit(c)) {
                    int num = c - '0'; // Convertir el carácter a número
                    if (firstDigit == -1) {
                        firstDigit = num; // Guardar el primer "dígito"
                    }
                    lastDigit = num; // Actualizar el último "dígito"
                }
            }
        }

        // Si encontramos ambos dígitos, calcular el valor de calibración
        if (firstDigit != -1 && lastDigit != -1) {
            int calibrationValue = firstDigit * 10 + lastDigit;
            totalSum += calibrationValue;
        }
    }

    cout << "La suma total de los valores de calibración es: " << totalSum << endl;

    return 0;
}
