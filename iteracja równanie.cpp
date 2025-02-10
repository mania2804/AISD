include <iostream>
using namespace std;

// Funkcja iteracyjna do obliczania wartości f(x)
int iterative_f(int x) {
    int f[100]; // Tablica do przechowywania wartości f(x)

    // Inicjalizacja wartości f(x) dla x > 50
    for (int i = 51; i < 100; i++) {
        f[i] = 9;
    }

    // Obliczanie wartości f(x) od 50 w dół do 0
    for (int i = 50; i >= 0; i--) {
        if (i <= 20) {
            f[i] = 5 * f[i + 3] + 7; // Zgodnie z podanym wzorem
        } else {
            f[i] = f[i + 3]; // Dla 20 < x <= 50
        }
    }

    return f[x]; // Zwracanie wartości f(x)
}

int main() {
    // Wypisanie wartości f(x) dla x od 0 do 19
    for (int x = 0; x <= 19; ++x) {
        cout << "f(" << x << ") = " << iterative_f(x) << endl;
    }
    return 0;
}
