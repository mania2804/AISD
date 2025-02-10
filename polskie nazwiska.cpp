
==================POLSKIE NAZWISKA===========================================
#include <iostream>
#include <fstream>

bool czy_polskie_znaki(char znak) {
    // Tablica zawierająca polskie znaki diakrytyczne, zarówno małe, jak i duże litery
    const char polskie_znaki[] = "ąćęłńóśżźĄĆĘŁŃÓŚŻŹ";
    
    // Sprawdzamy, czy dany znak występuje w tablicy polskich znaków
    for (int i = 0; polskie_znaki[i] != '\0'; ++i) {
        if (znak == polskie_znaki[i]) {
            return true;
        }
    }
    return false;
}

int policz_polskie_nazwiska(const char* sciezka) {
    std::ifstream plik(sciezka, std::ios::binary);
    
    if (!plik.is_open()) {
        std::cerr << "Nie mozna otworzyc pliku!" << std::endl;
        return -1;
    }

    int liczba_nazwisk = 0;
    char znak;
    bool zawiera_polskie_znaki;
    
    // Odczytujemy plik znak po znaku
    while (plik.get(znak)) {
        // Inicjalizujemy flagę do sprawdzania, czy dane nazwisko zawiera polski znak
        zawiera_polskie_znaki = false;

        // Czytamy całe nazwisko (do napotkania znaku nowej linii lub końca pliku)
        while (plik.get(znak) && znak != '\n' && znak != '\r') {
            if (czy_polskie_znaki(znak)) {
                zawiera_polskie_znaki = true;
            }
        }

        // Jeżeli znaleziono polski znak, zwiększamy licznik
        if (zawiera_polskie_znaki) {
            ++liczba_nazwisk;
        }

        // Sprawdzamy, czy napotkaliśmy koniec pliku
        if (plik.eof()) break;
    }

    plik.close();
    return liczba_nazwisk;
}

int main() {
    const char* sciezka = "nazwiska.txt"; // Przykładowa ścieżka do pliku
    int wynik = policz_polskie_nazwiska(sciezka);
    
    if (wynik != -1) {
        std::cout << "Liczba nazwisk zawierajacych polskie znaki: " << wynik << std::endl;
    }
    
    return 0;
}