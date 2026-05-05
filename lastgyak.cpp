#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

// ---------------------------------------------------------
// 1. Feladat: Két szám közötti legnagyobb Fibonacci szám
// (Ebben eredetileg sem volt vektor)
// ---------------------------------------------------------
int maxFibonacci(int a, int b) {
    int start = min(a, b);
    int end = max(a, b);

    int f1 = 0, f2 = 1, f3 = 1;
    int max_fib = -1;

    if (start <= 0 && end >= 0) {
        max_fib = 0;
    }

    while (f3 <= end) {
        if (f3 >= start) {
            max_fib = f3;
        }
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }

    return max_fib;
}

// ---------------------------------------------------------
// 2. Feladat: 10x10-es tömb soronkénti átlagai
// ---------------------------------------------------------
double* sorAtlag(int matrix[10][10]) {
    // Marad a dinamikus tömb (new), mert a vektor tilos, 
    // de a visszaadott értéknek léteznie kell a függvény után is.
    double* atlagok = new double[10];

    for (int i = 0; i < 10; i++) {
        double sum = 0;
        for (int j = 0; j < 10; j++) {
            sum += matrix[i][j];
        }
        atlagok[i] = sum / 10.0;
    }

    return atlagok;
}

// ---------------------------------------------------------
// 3. Feladat: Stringek bekérése és a legkisebb/legnagyobb kiválasztása
// (Ebben eredetileg sem volt vektor)
// ---------------------------------------------------------
void feladat3() {
    int n;
    cout << "Kerek egy egesz szamot (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Nincs bekerendo string.\n";
        return;
    }

    string s, legrovidebb, leghosszabb;
    cout << "Kerek " << n << " db szokoz nelkuli stringet:\n";

    cin >> s;
    legrovidebb = s;
    leghosszabb = s;

    for (int i = 1; i < n; i++) {
        cin >> s;
        if (s.length() < legrovidebb.length()) {
            legrovidebb = s;
        }
        if (s.length() > leghosszabb.length()) {
            leghosszabb = s;
        }
    }

    cout << "A legrovidebb string: " << legrovidebb << "\n";
    cout << "A leghosszabb string: " << leghosszabb << "\n";
}

// ---------------------------------------------------------
// 4. Feladat: Doboz struktúra és torony magassága
// ---------------------------------------------------------
struct Doboz {
    double szelesseg;
    double magassag;
    double melyseg;
};

void feladat4() {
    // Statikus tömböt használunk vektor helyett
    Doboz dobozok[5] = {
        {10.0, 5.5, 10.0},
        {8.0, 3.2, 8.0},
        {15.0, 10.0, 15.0},
        {5.0, 2.5, 5.0},
        {12.0, 7.3, 12.0}
    };

    double osszMagassag = 0;
    for (int i = 0; i < 5; i++) {
        osszMagassag += dobozok[i].magassag;
    }

    cout << "A torony magassaga: " << osszMagassag << "\n";
}

// ---------------------------------------------------------
// 5. Feladat: Fájl beolvasása adatszerkezetbe vektor nélkül
// ---------------------------------------------------------
void feladat5() {
    ifstream be("randomok.txt");
    ofstream ki("kisebb.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a randomok.txt fajlt!\n";
        return;
    }

    // Vektor helyett fix méretű 2D tömböt használunk.
    // Tegyük fel, hogy max 100 sor és soronként max 100 szám van.
    const int MAX_SOR = 100;
    const int MAX_OSZLOP = 100;
    int adatok[MAX_SOR][MAX_OSZLOP];
    int oszlopSzamok[MAX_SOR]; // Tárolja, hogy az adott sorban hány elem van
    int sorokSzama = 0;

    string sor;
    // 1. Fázis: Beolvasás a 2D tömbbe
    while (getline(be, sor) && sorokSzama < MAX_SOR) {
        if (sor.empty()) continue;

        stringstream ss(sor);
        int szam;
        int aktualisOszlop = 0;

        while (ss >> szam && aktualisOszlop < MAX_OSZLOP) {
            adatok[sorokSzama][aktualisOszlop] = szam;
            aktualisOszlop++;
        }
        oszlopSzamok[sorokSzama] = aktualisOszlop;
        sorokSzama++;
    }

    // 2. Fázis: Feldolgozás
    for (int i = 0; i < sorokSzama; i++) {
        if (oszlopSzamok[i] == 0) continue;

        double sum = 0;
        for (int j = 0; j < oszlopSzamok[i]; j++) {
            sum += adatok[i][j];
        }

        double atlag = sum / oszlopSzamok[i];

        if (atlag < 37.0) {
            ki << "Igen\n";
        } else {
            ki << "Nem\n";
        }
    }

    be.close();
    ki.close();
    cout << "A kisebb.txt fajl elkeszult.\n";
}

// ---------------------------------------------------------
// Főprogram
// ---------------------------------------------------------
int main() {
    // Tesztelés (opcionális)
    cout << "1. feladat: " << maxFibonacci(10, 50) << "\n";
    
    int matrix[10][10] = {0};
    matrix[0][0] = 50; matrix[0][1] = 50; 
    double* atlagok = sorAtlag(matrix);
    cout << "2. feladat (0. sor): " << atlagok[0] << "\n";
    delete[] atlagok;

    feladat4();
    // feladat5(); // Csak ha létezik a fájl

    return 0;
}