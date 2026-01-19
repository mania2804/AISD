#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


struct Node {
    int liczba;
    Node* next = nullptr;
    Node* prev = nullptr;
};



void wyczysc(Node* &head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void wypisz(Node* head) {
    cout << "[ ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << setw(3) << temp->liczba;
        temp = temp->next;
    }
    cout << " ]" << endl;
}

void wypisz_odwrotnie(Node* head) {
    cout << "[ ";
    if (head != nullptr) {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;

        while (temp != nullptr) {
            cout << setw(3) << temp->liczba;
            temp = temp->prev;
        }
    }
    cout << " ]" << endl;
}



void dodaj(Node* &head, int liczba) {
    Node* nowy = new Node{liczba, nullptr, nullptr};
    if (head == nullptr) {
        head = nowy;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = nowy;
        nowy->prev = temp;
    }
}

void wstaw(Node* &head, int liczba, int pozycja) {
    if (pozycja < 0) return;

    Node* nowy = new Node{liczba, nullptr, nullptr};

    if (pozycja == 0) {
        nowy->next = head;
        if (head != nullptr) head->prev = nowy;
        head = nowy;
        return;
    }

    Node* temp = head;
    for (int i = 0; i < pozycja - 1 && temp != nullptr; i++) temp = temp->next;

    if (temp == nullptr) {
        delete nowy;
        return;
    }

    nowy->next = temp->next;
    nowy->prev = temp;
    if (temp->next != nullptr) temp->next->prev = nowy;
    temp->next = nowy;
}



void usun(Node* &head, int pozycja) {
    if (head == nullptr || pozycja < 0) return;

    Node* temp = head;
    for (int i = 0; i < pozycja && temp != nullptr; i++) temp = temp->next;

    if (temp == nullptr) return;

    if (temp->prev != nullptr) temp->prev->next = temp->next;
    else head = temp->next;

    if (temp->next != nullptr) temp->next->prev = temp->prev;

    delete temp;
}

void zamien(Node* &head, int p1, int p2) {
    if (p1 == p2 || head == nullptr) return;

    Node* node1 = head;
    for (int i = 0; i < p1 && node1 != nullptr; i++) node1 = node1->next;

    Node* node2 = head;
    for (int i = 0; i < p2 && node2 != nullptr; i++) node2 = node2->next;

    if (!node1 || !node2) return;

    int tempVal = node1->liczba;
    node1->liczba = node2->liczba;
    node2->liczba = tempVal;
}


int main(int argc, char* argv[]) {
    if (argc != 2) return 1;

    ifstream plik(argv[1]);
    if (!plik.is_open()) return 1;

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
    plik.close();
    return 0;
}