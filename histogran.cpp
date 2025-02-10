#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Pacjent {
    string nazwisko;
    int waga; // Dodane pole do przechowywania wagi pacjenta
};

bool wyszukiwanieRekurencyjne(Pacjent* pacjenci, int lewy, int prawy, const string& nazwisko) {
    if (lewy > prawy) {
        return false;
    }

    int srodek = lewy + (prawy - lewy) / 2;

    if (pacjenci[srodek].nazwisko == nazwisko) {
        return true;
    } else if (pacjenci[srodek].nazwisko > nazwisko) {
        return wyszukiwanieRekurencyjne(pacjenci, lewy, srodek - 1, nazwisko);
    } else {
        return wyszukiwanieRekurencyjne(pacjenci, srodek + 1, prawy, nazwisko);
    }
}

bool wyszukiwanie(Pacjent* pacjenci, int n, const string& nazwisko) {
    return wyszukiwanieRekurencyjne(pacjenci, 0, n - 1, nazwisko);
}

int* histogram_wagi(Pacjent* pacjenci, int n, int bin) {
    int* histogram = new int[bin]{};

    int min_waga = pacjenci[0].waga;
    int max_waga = pacjenci[0].waga;

    // Znalezienie minimalnej i maksymalnej wagi
    for (int i = 1; i < n; i++) {
        min_waga = min(min_waga, pacjenci[i].waga);
        max_waga = max(max_waga, pacjenci[i].waga);
    }

    double bin_size = (double)(max_waga - min_waga + 1) / bin;

    // Przypisanie wag do odpowiednich binów
    for (int i = 0; i < n; i++) {
        int index = (int)((pacjenci[i].waga - min_waga) / bin_size);
        if (index == bin) index--; // Upewnienie się, że indeks nie przekroczy liczby binów
        histogram[index]++;
    }

    return histogram;
}

int main() {
    Pacjent pacjenci[] = { {"Adams", 55}, {"Biel", 70}, {"Kowalski", 80}, {"Nowak", 65}, {"Zielinski", 90} };
    int n = sizeof(pacjenci) / sizeof(pacjenci[0]);

    string szukaneNazwisko = "Nowak";
    if (wyszukiwanie(pacjenci, n, szukaneNazwisko)) {
        cout << "Nazwisko " << szukaneNazwisko << " znajduje się w tablicy." << endl;
    } else {
        cout << "Nazwisko " << szukaneNazwisko << " nie znajduje się w tablicy." << endl;
    }

    int bin = 4;
    int* histogram = histogram_wagi(pacjenci, n, bin);

    cout << "Histogram wag:" << endl;
    for (int i = 0; i < bin; i++) {
        cout << "Bin " << i << ": " << histogram[i] << endl;
    }

    delete[] histogram;
    return 0;
}
