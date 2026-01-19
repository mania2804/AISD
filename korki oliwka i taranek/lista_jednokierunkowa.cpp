#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct Node {
    int liczba;
    Node* next = nullptr;
};


void wypisz_rekurencyjnie(Node* node) {
    if (node == nullptr) return;
    wypisz_rekurencyjnie(node->next);
    cout << setw(3) << node->liczba ;

}

void dodaj(Node* &head, int liczba) {
    Node* nowy = new Node{liczba, nullptr};
    if (head == nullptr) {
        head = nowy;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nowy;
    }
}

void wstaw(Node* &head, int liczba, int pozycja) {
    if (pozycja < 0) return;
    if (pozycja == 0) {
        head = new Node{liczba, head};
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pozycja - 1 && temp != nullptr; i++) temp = temp->next;

    if (temp == nullptr) return;
    temp->next = new Node{liczba, temp->next};
}

void usun(Node* &head, int pozycja) {
    if (head == nullptr || pozycja < 0) return;
    if (pozycja == 0) {
        Node* doUsuniecia = head;
        head = head->next;
        delete doUsuniecia;
        return;
    }
    Node* temp = head;
    for (int i = 0; i < pozycja - 1 && temp->next != nullptr; i++) temp = temp->next;

    if (temp->next == nullptr) return;
    Node* doUsuniecia = temp->next;
    temp->next = doUsuniecia->next;
    delete doUsuniecia;
}

void wyczysc(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void wypisz(Node* head) {
    Node* temp = head;
    cout << "[ " ;
    while (temp != nullptr) {
        cout << setw(3) << temp->liczba;
        temp = temp->next;
    }
    cout << " ] "<< endl;
}

void wypisz_odwrotnie(Node* head) {
    cout<<"[ ";
    wypisz_rekurencyjnie(head);
    cout <<" ]"<< endl;
}

void zamien(Node* &head, int p1, int p2) {
    if (p1 == p2 || head == nullptr) return;
    if (p1 > p2) swap(p1, p2);

    Node *prev1 = nullptr, *curr1 = head;
    for (int i = 0; i < p1 && curr1 != nullptr; i++) {
        prev1 = curr1;
        curr1 = curr1->next;
    }

    Node *prev2 = nullptr, *curr2 = head;
    for (int i = 0; i < p2 && curr2 != nullptr; i++) {
        prev2 = curr2;
        curr2 = curr2->next;
    }

    if (!curr1 || !curr2) return;

    if (prev1) prev1->next = curr2;
    else head = curr2;

    if (prev2) prev2->next = curr1;
    else head = curr1;

    Node* temp = curr1->next;
    curr1->next = curr2->next;
    curr2->next = temp;
}

int main(int argc, char* argv[]) {
    if (argc != 2) return 1;

    ifstream plik(argv[1]);
    if (!plik.is_open()) return 1;

    // ifstream plik("10.txt");
    // if (!plik.is_open()) {
    //     cout<<"Nie można otworzyc pliku";
    //     return 1;
    // }
    Node* head = nullptr;
    string komenda;
    while (plik >> komenda) {
        if (komenda == "dodaj") {
            int n; plik >> n; dodaj(head, n);
        } else if (komenda == "wstaw") {
            int n, p; plik >> n >> p; wstaw(head, n, p);
        } else if (komenda == "usun") {
            int p; plik >> p; usun(head, p);
        } else if (komenda == "wyczysc") {
            wyczysc(head);
        } else if (komenda == "wypisz") {
            wypisz(head);
        } else if (komenda == "wypisz_odwrotnie") {
            wypisz_odwrotnie(head);
        } else if (komenda == "zamien") {
            int p1, p2; plik >> p1 >> p2; zamien(head, p1, p2);
        }
    }
    wyczysc(head);
    return 0;
}