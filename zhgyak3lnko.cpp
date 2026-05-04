/*
1. Legnagyobb közös osztó: Írjon egy függvényt, amely két pozitív egész számot kap paraméterként,
 és visszatér a két szám legnagyobb közös osztójával (LNKO).
 
2. Mátrix oszlopösszegek: Írjon egy függvényt, amely egy 6x6 -os egész számokat tartalmazó mátrixot
  és egy 6 elemű egydimenziós tömböt kap paraméterként. 
  A függvény számítsa ki a mátrix oszloponkénti összegeit, és tárolja el őket az egydimenziós tömbben.
  
3. Kezdőbetű ellenőrzés: Kérjen be a felhasználótól egy n egész számot,
   majd pontosan $n$ darab szót. Írja ki a képernyőre azokat a szavakat,
    amelyek 'A' vagy 'a' betűvel kezdődnek.

4. Struktúra - Autók: Hozzon létre egy Auto nevű struktúrát, amely tárolja az autó márkáját (string), gyártási évét (egész)
 és az árát (egész). Hozzon létre egy 5 elemű tömböt autókkal. Keresse meg és írja ki a legfiatalabb (legnagyobb gyártási évvel
  rendelkező) autó márkáját és árát.
5. Fájlkezelés és szűrés: Olvassa be a szamok.txt fájlt, amely tetszőleges mennyiségű 
egész számot tartalmaz. Válogassa ki a páros számokat, és írja őket a parosak.txt fájlba.
 A kimeneti fájl legutolsó sorába írja bele a beolvasott összes szám átlagát is!
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// 1. FELADAT: Legnagyobb közös osztó (Euklideszi algoritmus)
int lnko(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// 2. FELADAT: Oszlopösszegek számítása
void oszlopOsszegek(int matrix[6][6], int eredmeny[6]) {
    for (int j = 0; j < 6; j++) {
        int szumma = 0;
        for (int i = 0; i < 6; i++) {
            szumma += matrix[i][j];
        }
        eredmeny[j] = szumma;
    }
}

// 4. FELADAT: Struktúra definíció
struct Auto {
    string marka;
    int evjarat;
    int ar;
};

int main() {
    // 3. FELADAT: Szavak szűrése
    cout << "--- 3. feladat ---" << endl;
    int n;
    cout << "Hany szot szeretnel megadni? ";
    cin >> n;
    vector<string> talalatok;
    for (int i = 0; i < n; i++) {
        string szo;
        cin >> szo;
        if (!szo.empty() && (szo[0] == 'A' || szo[0] == 'a')) {
            talalatok.push_back(szo);
        }
    }
    cout << "A-val kezdodo szavak: ";
    for (const string& s : talalatok) cout << s << " ";
    cout << endl;

    // 4. FELADAT: Legfiatalabb autó keresése
    cout << "\n--- 4. feladat ---" << endl;
    Auto flotta[5] = {
        {"Suzuki", 2010, 1500000},
        {"Audi", 2022, 12000000},
        {"Opel", 2005, 600000},
        {"Tesla", 2023, 18000000},
        {"Ford", 2018, 4500000}
    };

    int legfiatalabbIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (flotta[i].evjarat > flotta[legfiatalabbIndex].evjarat) {
            legfiatalabbIndex = i;
        }
    }
    cout << "Legfiatalabb auto: " << flotta[legfiatalabbIndex].marka 
         << " (Ar: " << flotta[legfiatalabbIndex].ar << " Ft)" << endl;

    // 5. FELADAT: Fájlkezelés és átlagszámítás
    cout << "\n--- 5. feladat ---" << endl;
    ifstream be("szamok.txt");
    ofstream ki("parosak.txt");

    if (be.is_open() && ki.is_open()) {
        int szam;
        double osszeg = 0;
        int darab = 0;
        
        while (be >> szam) {
            osszeg += szam;
            darab++;
            if (szam % 2 == 0) {
                ki << szam << " ";
            }
        }
        
        if (darab > 0) {
            ki << "\nAtlag: " << osszeg / darab << endl;
        }
        
        be.close();
        ki.close();
        cout << "Fajlmuveletek kesz." << endl;
    } else {
        cout << "Hiba a fajlok megnyitasakor!" << endl;
    }

    return 0;
}