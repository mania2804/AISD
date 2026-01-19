#include <iostream>

using namespace std;

// Struktura zawierająca TYLKO dane i wskaźnik na następny element
struct Element {
    int dane;
    Element* nastepny;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    Element* glowa = nullptr;
    Element* ogon = nullptr;

    // 1. Wczytywanie n liczb i tworzenie listy
    for (int i = 0; i < n; ++i) {
        int wartosc;
        if (cin >> wartosc) {
            Element* nowy = new Element;
            nowy->dane = wartosc;
            nowy->nastepny = nullptr;

            if (glowa == nullptr) {
                glowa = nowy;
                ogon = nowy;
            } else {
                ogon->nastepny = nowy;
                ogon = nowy;
            }
        }
    }

    // 2. Sortowanie nierosnące (bąbelkowe na wartościach)
    if (glowa != nullptr) {
        bool zamieniono;
        do {
            zamieniono = false;
            Element* obecny = glowa;
            while (obecny->nastepny != nullptr) {
                if (obecny->dane < obecny->nastepny->dane) {
                    // Zamiana samych danych (intów) wewnątrz węzłów
                    int temp = obecny->dane;
                    obecny->dane = obecny->nastepny->dane;
                    obecny->nastepny->dane = temp;
                    zamieniono = true;
                }
                obecny = obecny->nastepny;
            }
        } while (zamieniono);
    }

    // 3. Usuwanie elementów parzystych
    Element* obecny = glowa;
    Element* poprzedni = nullptr;

    while (obecny != nullptr) {
        if (obecny->dane % 2 == 0) {
            Element* do_usuniecia = obecny;
            if (poprzedni == nullptr) {
                // Usuwamy głowę listy
                glowa = obecny->nastepny;
                obecny = glowa;
            } else {
                // Usuwamy element ze środka lub końca
                poprzedni->nastepny = obecny->nastepny;
                obecny = poprzedni->nastepny;
            }
            delete do_usuniecia;
        } else {
            // Element jest nieparzysty, idziemy dalej
            poprzedni = obecny;
            obecny = obecny->nastepny;
        }
    }

    // 4. Zliczanie pozostałych elementów
    int licznik = 0;
    Element* temp = glowa;
    while (temp != nullptr) {
        licznik++;
        temp = temp->nastepny;
    }

    // 5. Wypisanie wyniku
    cout << licznik;
    temp = glowa;
    while (temp != nullptr) {
        cout << " " << temp->dane;
        temp = temp->nastepny;
    }
    cout << endl;

    // 6. Zwolnienie pamięci pozostałej listy
    while (glowa != nullptr) {
        Element* nastepny = glowa->nastepny;
        delete glowa;
        glowa = nastepny;
    }

    return 0;
}