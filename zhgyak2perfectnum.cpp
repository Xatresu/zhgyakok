/*
1. Tökéletes számok: Írjon egy függvényt, amely egy egész számot kap paraméterként, 
és eldönti, hogy az adott szám tökéletes szám-e. (Tökéletes szám az, amely megegyezik az önmagánál kisebb osztóinak összegével.
 Pl.: $6 = 1 + 2 + 3$). A függvény logikai (bool) értékkel térjen vissza.Mátrix főátló és mellékátló: 
 
2. Írjon egy függvényt, amely egy $5 \times 5$-ös egész mátrixot kap paraméterként. 
 A függvény számítsa ki a főátlóban és a mellékátlóban lévő elemek összegét külön-külön, majd térjen vissza a kettő közül 
 a nagyobbal.
 
3. Karaktercsere: Kérjen be a felhasználótól egy mondatot (szóközöket is tartalmazhat!). 
 Alakítsa át a szöveget úgy, hogy minden szóköz helyett alulvonás (_) szerepeljen, és 
 írja ki az eredményt csupa nagybetűvel.
 
 4. Osztály - Diákok: Hozzon létre egy Diak osztályt vagy struktúrát: név (string), 
 neptun kód (string), és egy 3 elemű tömb az utolsó három jegyének. Hozzon létre egy 3 fős csoportot (tömböt). 
 Számítsa ki és írja ki minden diák nevét és a jegyeinek átlagát.
 
 5. Fájlkezelés - Leghosszabb sor: Olvassa be a szoveg.txt fájlt. 
 Keresse meg a leghosszabb (legtöbb karakterből álló) sort a fájlban, 
 és írja ki annak tartalmát és karakterszámát egy leghosszabb.txt nevű fájlba.*/

 #include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// 1. FELADAT: Tökéletes szám ellenőrzése
bool isTokeletes(int n) {
    if (n < 2) return false;
    int osszeg = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) osszeg += i;
    }
    return osszeg == n;
}

// 2. FELADAT: Átlók összege
int nagyobbAtlo(int mat[5][5]) {
    int foAtlo = 0, mellekAtlo = 0;
    for (int i = 0; i < 5; i++) {
        foAtlo += mat[i][i];
        mellekAtlo += mat[i][4 - i];
    }
    return (foAtlo > mellekAtlo) ? foAtlo : mellekAtlo;
}

// 4. FELADAT: Diák struktúra
struct Diak {
    string nev;
    string neptun;
    int jegyek[3];
};

int main() {
    // 3. FELADAT: Karaktercsere és nagybetű
    cout << "--- 3. feladat ---" << endl;
    string mondat;
    cout << "Adj meg egy mondatot: ";
    cin.ignore(); // Előző cin-ek utáni puffer ürítése
    getline(cin, mondat);
    
    for (int i = 0; i < mondat.length(); i++) {
        if (mondat[i] == ' ') mondat[i] = '_';
        mondat[i] = toupper(mondat[i]);
    }
    cout << "Modositott mondat: " << mondat << endl;

    // 4. FELADAT: Diák átlagok
    cout << "\n--- 4. feladat ---" << endl;
    Diak csoport[3] = {
        {"Kovacs Janos", "ABC123", {5, 4, 5}},
        {"Nagy Anna", "XYZ789", {3, 5, 2}},
        {"Kiss Bela", "QWE456", {4, 4, 3}}
    };

    for (int i = 0; i < 3; i++) {
        double atlag = (csoport[i].jegyek[0] + csoport[i].jegyek[1] + csoport[i].jegyek[2]) / 3.0;
        cout << csoport[i].nev << " atlaga: " << atlag << endl;
    }

    // 5. FELADAT: Leghosszabb sor keresése
    cout << "\n--- 5. feladat ---" << endl;
    ifstream be("szoveg.txt");
    ofstream ki("leghosszabb.txt");

    if (be.is_open()) {
        string sor, maxSor = "";
        while (getline(be, sor)) {
            if (sor.length() > maxSor.length()) {
                maxSor = sor;
            }
        }
        ki << "Hossz: " << maxSor.length() << endl;
        ki << "Tartalom: " << maxSor << endl;
        be.close();
        ki.close();
        cout << "Fajlkezeles kesz." << endl;
    } else {
        cout << "Hiba: szoveg.txt nem talalhato!" << endl;
    }

    return 0;
}