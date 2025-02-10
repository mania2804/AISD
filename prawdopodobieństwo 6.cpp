#include <iostream>
#include <cstdlib>   // do rand()
#include <ctime>     // do time()

using namespace std;

// Enum reprezentujący kolory kul
enum class Kolor {
    Czarny,
    Bialy,
    Zielony,
    Szary,
    Niebieski
};

// Funkcja zamieniająca enum na string do wyświetlania
string kolorNaString(Kolor kolor) {
    switch (kolor) {
        case Kolor::Czarny: return "Czarny";
        case Kolor::Bialy: return "Bialy";
        case Kolor::Zielony: return "Zielony";
        case Kolor::Szary: return "Szary";
        case Kolor::Niebieski: return "Niebieski";
        default: return "Nieznany";
    }
}

// Funkcja losująca kulę z urny z prawidłowym rozkładem
Kolor losujKule() {
    int liczba = rand() % 120; // Losujemy liczbę z zakresu 0-119

    if (liczba < 50) return Kolor::Czarny;          // 50 kul czarnych (0-49)
    else if (liczba < 80) return Kolor::Bialy;      // 30 kul białych (50-79)
    else if (liczba < 100) return Kolor::Zielony;   // 20 kul zielonych (80-99)
    else if (liczba < 110) return Kolor::Szary;     // 10 kul szarych (100-109)
    else return Kolor::Niebieski;                   // 10 kul niebieskich (110-119)
}

int main() {
    srand(time(0)); // Inicjalizacja generatora liczb losowych

    // Losowanie dwóch kul
    Kolor kula1 = losujKule();
    Kolor kula2 = losujKule();

    // Wypisanie wyników
    cout << kolorNaString(kula1) << " " << kolorNaString(kula2) << endl;

    return 0;
}
