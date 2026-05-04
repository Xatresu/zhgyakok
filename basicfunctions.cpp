#include <vector>
#include <algorithm>
//Fibonacci-sorozat (Iteratív)
long long fibonacci(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, next;
    for (int i = 2; i <= n; ++i) {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
};
//faktoriális
long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
};
//Átlag (Mean)
double mean(int arr[], int n) {
    if (n <= 0) return 0;
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / n;
}
//Medián (A középső elem)
//A mediánhoz rendezni kell az elemeket. Ha páros az elemszám, a két középső átlaga kell.
double median(int arr[], int n /*tömb mérete*/) {
    if (n <= 0) return 0;
    
    // Figyelem: ez módosítja az eredeti tömböt!
    std::sort(arr, arr + n); 
    
    if (n % 2 == 0) 
        return (arr[n/2 - 1] + arr[n/2]) / 2.0;
    else 
        return arr[n/2];
};
int binarySearch(int arr[], int n, int x) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
};
//Lnko
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
};
//Prim keresés
bool isPrime(int n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}