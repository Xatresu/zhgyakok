#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// --- 1. FELADAT ---
// Prímszám-ellenőrző segédfüggvény
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// A kért függvény: prímek száma két szám között
int countPrimesBetween(int a, int b) {
    int count = 0;
    int start = min(a, b);
    int end = max(a, b);
    for (int i = start; i <= end; ++i) {
        if (isPrime(i)) count++;
    }
    return count;
}

// --- 2. FELADAT ---
// Oszlopminimumok meghatározása
// Megjegyzés: C++-ban tömböt közvetlenül nem lehet visszadni, 
// ezért dinamikus tömböt (vagy vektort) használunk.
// A visszatérési érték void, mert a 'mins' tömböt helyben módosítjuk
void columnMinimums(int matrix[4][4], int mins[4]) {
    for (int j = 0; j < 4; ++j) {
        int minVal = matrix[0][j];
        for (int i = 1; i < 4; ++i) {
            if (matrix[i][j] < minVal) {
                minVal = matrix[i][j];
            }
        };
        mins[j] = minVal;
    }
}

// --- 3. FELADAT ---
void muvelet(int &eredmeny, char op, int operandus) {
    switch (op) {
        case '+': eredmeny += operandus; break;
        case '-': eredmeny -= operandus; break;
        case '*': eredmeny *= operandus; break;
        default: cout << "Ismeretlen muvelet!" << endl;
    }
}

// --- 4. FELADAT ---
void checkEightNumbers() {
    int num;
    bool found = false;
    cout << "Kerjuk, adjon meg 8 egesz szamot: " << endl;
    for (int i = 0; i < 8; ++i) {
        cin >> num;
        if (num > 100) {
            found = true;
        }
    }
    if (found) {
        cout << "Van 100-nal nagyobb ertek a megadott szamok kozott." << endl;
    } else {
        cout << "Nincs 100-nal nagyobb ertek a megadott szamok kozott." << endl;
    }
}

// --- 5. FELADAT ---
void matrixFileProcessing() {
    ifstream inputFile("szamok.txt");
    if (!inputFile) {
        cout << "Hiba: A szamok.txt nem talalhato!" << endl;
        return;
    }

    int matrix[5][5];
    vector<int> diagonal;

    // Beolvasás és főátló kinyerése
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            inputFile >> matrix[i][j];
            if (i == j) {
                diagonal.push_back(matrix[i][j]);
            }
        }
    }
    inputFile.close();

    // Medián meghatározása (5 elem esetén a 3. elem a sorbarendezés után)
    sort(diagonal.begin(), diagonal.end());
    int median = diagonal[2];
    cout << "A foatlo elemeinek medianja: " << median << endl;

    ofstream outputFile("kisebbek.txt");
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (matrix[i][j] < median) {
                outputFile << matrix[i][j] << " ";
            }
        }
    }
    outputFile.close();
    cout << "A mediannal kisebb elemek mentve a kisebbek.txt-be." << endl;
}
int matrix[4][4] = {
    {5, 2, 9, 1},
    {3, 8, 6, 4},
    {7, 0, 11, 10},
    {12, 14, 13, 15}
};

int main() {
    int matrix[4][4] = {
    {5, 2, 9, 1},
    {3, 8, 6, 4},
    {7, 0, 11, 10},
    {12, 14, 13, 15}};
    int eredmeny[4];
    checkEightNumbers();
    matrixFileProcessing();
    columnMinimums(matrix, eredmeny);
    for (int i = 0; i < 4; ++i) {
        cout << eredmeny[i] << " ";
    };
    return 0;
}