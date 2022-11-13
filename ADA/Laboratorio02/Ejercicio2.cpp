// Estudiante: Gustavo Eduardo ORDOÑO POMA
// CUI: 20213036
// Laboratorio02 - Importancia de los algoritmos en la solución de problemas
// Fecha: 03/10/2022

#include <iostream>

using namespace std;

string s;
int vowelCount[5];
void getInputData();
void filterVowels();
void showVowelFrequency();

int main() {
    getInputData();
    filterVowels();
    showVowelFrequency();
    
    return 0;
}

void getInputData() {
    cout << "Cadena: ";
    getline(cin, s);
}

void filterVowels() {
    char letters[s.length()];
    for(int i = 0; i < s.length(); i++) {
        letters[i] = s[i];
    }
    
    char *p = letters;
    for(int i = 0; i < s.length(); i++) {
        const char letter = *(p + i);
        switch(tolower(letter)) {
            case 'a':
                vowelCount[0]++;
                break;
            case 'e':
                vowelCount[1]++;
                break;
            case 'i':
                vowelCount[2]++;
                break;
            case 'o':
                vowelCount[3]++;
                break;
            case 'u':
                vowelCount[4]++;
        }
    }
}

void showVowelFrequency() {
    cout << "Frecuencias: " << endl;
    cout << "a: " << vowelCount[0] << endl;
    cout << "e: " << vowelCount[1] << endl;
    cout << "i: " << vowelCount[2] << endl;
    cout << "o: " << vowelCount[3] << endl;
    cout << "u: " << vowelCount[4] << endl;
}