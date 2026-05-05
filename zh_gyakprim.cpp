#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;


//elso feladat
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int primDb(int a, int b) {
    int start = min(a, b);
    int end = max(a, b);
    int count = 0;


    for (int i = start; i <= end; i++) {
        if (isPrime(i)) {
            count++;
        }
    }
    return count;
}
//masodik feladat
int* sorMin(int matrix[4][4]) {
    int* minek = new int[4];
    for (int i = 0; i < 10; i++) {
        int minVal = matrix[0][i];
        for (int j = 1; j < 10; j++) {
            if (matrix[j][i] < minVal) {
                minVal = matrix[j][i];
            }
        }
        minek[i] = minVal;
    }
    return minek;
}

//harmadik feladat
void muvelet(int& a, string muv, int b) {
    if (muv == "+") {
        a += b;
    } else if (muv == "-") {
        a -= b;
    } else if (muv == "*") {
        a *= b;
        }
    }

void feladat5() {
    ifstream be("szamok.txt");
    ofstream ki("kisebbek.txt");

    if (!be.is_open()) {
        cout << "Nem sikerult megnyitni a szamok.txt fajlt!\n";
        return;
    }
    int matrix[5][5];
    string sor;
    int i = 0;
    while (getline(be, sor) && i < 5) {
        if (sor.empty()) continue;
        stringstream ss(sor);
        for (int j = 0; j < 5; j++) {
            ss >> matrix[i][j];
        }
        i++;
    }


    long long szorzat1 = 1;
    long long szorzat2 = 1;

    vector<int> atlo1_elemek;
    vector<int> atlo2_elemek;

    for (int k = 0; k < 5; k++) {
        atlo1_elemek.push_back(matrix[k][k]);
        szorzat1 *= matrix[k][k];

        atlo2_elemek.push_back(matrix[k][4 - k]);
        szorzat2 *= matrix[k][4 - k];
    }
    if (szorzat1 < szorzat2) {
        for (int elem : atlo1_elemek) {
            ki << elem << " ";
        }
    } else if (szorzat2 < szorzat1) {
        for (int elem : atlo2_elemek) {
            ki << elem << " ";
        }
    } else {
        ki << "A ket atlo szorzata egyenlo.";
    }

    be.close();
    ki.close();
    cout << "A kisebbek.txt fajl elkeszult.\n";
}


int main() {
    //negyedik feladat
    vector<int> szamok(8);
    bool vanNagyobb = false;

  cout << "Kerem adjon meg 8 egesz szamot:" << endl;

    for (int i = 0; i < 8; ++i) {
       cout << i + 1 << ". szam: ";
        cin >> szamok[i];


        if (szamok[i] > 100) {
            vanNagyobb = true;
        }
    }

   cout << "-------------------" << endl;
    if (vanNagyobb) {
        cout << "Igen, van 100-nal nagyobb szam a megadottak kozott." << endl;
    } else {
        cout << "Nem, nincs 100-nal nagyobb szam a megadottak kozott." << endl;
    }


    cout<<"Adjon meg egy szamot: ";
    int l;
    cin>>l;
    cout<<"Adjon meg egy muveleti jelet(+,-,*): ";
    string muv;
    cin>> muv;
    cout<<"Adjon meg egy szamot megint: ";
    int b;
    cin>> b;
    cout << "3. feladat: Eredeti ertek: " << l << "\n";
    muvelet(l, muv, b);
    cout << "Muvelet  utan: " << l << "\n\n";
    cout << "5. feladat...\n";
    feladat5();


}

