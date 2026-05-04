//1. Alapvető bejárások
//Sorfolytonos bejárás 
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        cout << matrix[i][j] << " ";
    }
}
//Oszlopfolytonos bejárásC++
for (int j = 0; j < N; ++j) {
    for (int i = 0; i < N; ++i) {
        cout << matrix[i][j] << " ";
    }
}
//2. Átlós bejárásokFőátló (Bal felső -> Jobb alsó)Ahol az indexek megegyeznek: i = jC++
for (int i = 0; i < N; ++i) {
    cout << matrix[i][i] << " ";
}
//Mellékátló (Jobb felső -> Bal alsó)Ahol az indexek összege: i + j = N - 1 C++
for (int i = 0; i < N; ++i) {
    cout << matrix[i][N - 1 - i] << " ";
}
//3. Háromszög és Keret bejárásokFőátló feletti háromszög (Felső háromszög)C++
for (int i = 0; i < N; ++i) {
    for (int j = i; j < N; ++j) { // j az i-től indul
        cout << matrix[i][j] << " ";
    }
}
//Keret (Szélek) bejárásaHasznos képfeldolgozásnál vagy határfeltételeknél.C++
for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
        if (i == 0 || i == N-1 || j == 0 || j == N-1) {
            cout << matrix[i][j] << " ";
        }
    }
}
//4. Speciális/Kreatív bejárások"Kígyó" vonal (S-alak)Minden második sort megfordítunk.C++
for (int i = 0; i < N; ++i) {
    if (i % 2 == 0) {
        for (int j = 0; j < N; ++j) cout << matrix[i][j] << " ";
    } else {
        for (int j = N - 1; j >= 0; --j) cout << matrix[i][j] << " ";
    }
}
//Spirális bejárás (Kívülről befelé)Ez egy klasszikus interjú kérdés. Négy mutatót (top, bottom, left, right) használunk.C++int T = 0, B = N - 1, L = 0, R = N - 1;
while (T <= B && L <= R) {
    for (int i = L; i <= R; ++i) cout << matrix[T][i] << " "; T++; // Felső sor balról jobbra
    for (int i = T; i <= B; ++i) cout << matrix[i][R] << " "; R--; // Jobb oszlop fentről le
    if (T <= B) {
        for (int i = R; i >= L; --i) cout << matrix[B][i] << " "; B--; // Alsó sor jobbról balra
    }
    if (L <= R) {
        for (int i = B; i >= T; --i) cout << matrix[i][L] << " "; L++; // Bal oszlop lentről fel
    }
}