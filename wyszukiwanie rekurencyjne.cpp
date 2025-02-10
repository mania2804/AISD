#include <iostream>
#include <string>
using namespace std;

struct Pacjent {
    string nazwisko;
    // Można dodać inne pola, np. imię, wiek itp.
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

int main() {
    Pacjent pacjenci[] = { {"Adams"}, {"Biel"}, {"Kowalski"}, {"Nowak"}, {"Zielinski"} };
    int n = sizeof(pacjenci) / sizeof(pacjenci[0]);

    string szukaneNazwisko = "Nowak";
    if (wyszukiwanie(pacjenci, n, szukaneNazwisko)) {
        cout << "Nazwisko " << szukaneNazwisko << " znajduje się w tablicy." << endl;
    } else {
        cout << "Nazwisko " << szukaneNazwisko << " nie znajduje się w tablicy." << endl;
    }

    return 0;
}
