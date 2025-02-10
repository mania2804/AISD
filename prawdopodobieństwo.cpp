#include <iostream>
#include <ctime>
using namespace std;

int p_zielony = 60;
int p_zolty = 30;
int p_czerwony = 10;

enum class Piorytet {
    Zielony, Zolty, Czerwony
};

int get_random_number(int from, int to) {
    //inaczej int liczba=rand()%100;
    return rand() % (to - from + 1) + from; //return liczba
}

Piorytet* piorytety(int n) {
    Piorytet *tab = new Piorytet[n];

    for (int i=0; i<n; i++) {
        int number = get_random_number(1, 100);
        if (number <= p_zielony) { // zielony
            tab[i] = Piorytet::Zielony;
        } else if (number > p_zielony && number <=p_zielony+p_zolty) { // zolty
            tab[i] = Piorytet::Zolty;
        } else { // czerwony
            tab[i] = Piorytet::Czerwony;
        }
    }

    return tab;
}

int main(int argc, char* argv[]) {
    srand(time(0));

    int n = 20;
    Piorytet* response = piorytety(n);

    return 0;
}