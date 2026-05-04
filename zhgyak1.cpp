#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

// 1. FELADAT: Armstrong-szám ellenőrzése
//Írjon egy függvényt, amely egy háromjegyű egész számot kap paraméterként, 
//és eldönti, hogy az Armstrong-szám-e. (Egy szám Armstrong-szám, ha 
//számjegyeinek köbének összege egyenlő a számmal. Pl.: $153 = 1^3 + 5^3 + 3^3$). A függvény térjen vissza logikai értékkel.
bool isArmstrong(int n) {
    if (n < 100 || n > 999) return false;
    int eredeti = n;
    int osszeg = 0;
    while (n > 0) {
        int szamjegy = n % 10;
        osszeg += pow(szamjegy, 3);
        n /= 10;
    }
    return osszeg == eredeti;
}
/*
Írjon egy függvényt, amely egy $4 \times 6$-os egész mátrixot kap paraméterként. 
A függvény számítsa ki a mátrix "keretén" (azaz az első sor, az 
utolsó sor, az első oszlop és az utolsó oszlop) található elemek összegét. Ügyeljen rá, hogy a sarkokat ne számolja kétszer!*/
// 2. FELADAT: Mátrix keret összege
int keretOsszeg(int mat[4][6]) {
    int osszeg = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            if (i == 0 || i == 3 || j == 0 || j == 5) {
                osszeg += mat[i][j];
            }
        }
    }
    return osszeg;
}

// 4. FELADAT: Könyv struktúra
struct Konyv {
    string szerzo;
    string cim;
    int oldalszam;
};

int main() {
    /*
    Kérjen be a felhasználótól egy stringet. 
    Számolja meg, hány magánhangzó (a, e, i, o, u - kis- és nagybetű is) 
    található benne, és írja ki az eredményt.*/
    // 3. FELADAT: Magánhangzók számlálása
    cout << "--- 3. feladat ---" << endl;
    string szoveg;
    cout << "Adj meg egy szoveget: ";
    getline(cin, szoveg);
    int vokalok = 0;
    string maganhangzok = "aeiouAEIOU";
    for (char c : szoveg) {
        if (maganhangzok.find(c) != string::npos) {
            vokalok++;
        }
    }
    cout << "Maganhangzok szama: " << vokalok << endl;

    // 4. FELADAT: Könyvek bekérése
    cout << "\n--- 4. feladat ---" << endl;
    Konyv konyvtar[3];
    int maxIndex = 0;
    for (int i = 0; i < 3; i++) {
        cout << i+1 << ". konyv szerzoje: ";
        getline(cin, konyvtar[i].szerzo);
        cout << "Cime: ";
        getline(cin, konyvtar[i].cim);
        cout << "Oldalszam: ";
        cin >> konyvtar[i].oldalszam;
        cin.ignore();
        if (konyvtar[i].oldalszam > konyvtar[maxIndex].oldalszam) {
            maxIndex = i;
        }
    }
    cout << "Legretesebb konyv: " << konyvtar[maxIndex].szerzo << ": " << konyvtar[maxIndex].cim << endl;

    // 5. FELADAT: Hőmérséklet szűrés
    /*
    Olvassa be a meresek.txt fájlt, ahol minden sorban egy valós szám (hőmérséklet) szerepel. 
    Válogassa ki azokat a méréseket, amelyek 0 és 30 fok közé esnek,
     és írja ki őket a normal.txt fájlba. A program végén írja ki a konzolra, hány mérést talált alkalmasnak*/
    cout << "\n--- 5. feladat ---" << endl;
    ifstream be("meresek.txt");
    ofstream ki("normal.txt");
    int db = 0;
    double temp;
    if (be.is_open()) {
        while (be >> temp) {
            if (temp >= 0 && temp <= 30) {
                ki << temp << endl;
                db++;
            }
        }
        be.close();
        ki.close();
        cout << "Szurt meresek szama: " << db << endl;
    } else {
        cout << "Hiba: meresek.txt hianyzik!" << endl;
    }

    return 0;
}