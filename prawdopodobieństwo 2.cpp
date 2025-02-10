#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

enum class Kolor{
    Czerwony,
    Zielony,
    Niebieski
};

string kolorNaString(Kolor kolor){
    switch(kolor){
        case Kolor::Czerwony: return "Czerwony";
        case Kolor::Zielony: return "Zielony";
        case Kolor::Niebieski: return "Niebieski";
        default: return "Nieznany";

    }
}

int main()
{
    Kolor kolor;
    for(int i=0; i<100; i++)
    {int liczba = rand()%100;
    
    if (liczba<30){
        kolor= Kolor::Czerwony;
    } else if (liczba <70){
        kolor=Kolor::Zielony;
    } else {
        kolor=Kolor::Niebieski;
    }
    cout << i << "Wylosowany kolor " << kolorNaString(kolor)<<endl;
    }
    return 0;
}