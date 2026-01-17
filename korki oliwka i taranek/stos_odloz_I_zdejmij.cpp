#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;
struct Node {
    int liczba;
    Node*next;
};
// struct Lista {
//     Node*head;
// };
// Lista stos;
Node*head=nullptr;
void odloz(int liczba) {
    Node*temp=stos.head;
    Node*nowy=new Node();
    nowy->liczba=liczba;
    nowy->next=temp;
    stos.head=nowyy;
}

int zdejmij() {
    if (head==nullptr) {
        cout<<"Pusty stos";
        return 0;
    }
    Node*temp=stos.head;
    int wartosc_glowy=temp->liczba;
    stos.head=temp->next;
    delete temp;
    return wartosc_glowy;
}



int main()
{

    return 0;
}