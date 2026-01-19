#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct Person {
    string date;
    string pesel;
    string fullname;
};

struct Node {
    Person* person;
    Node* next_alf = nullptr;
    Node*next_wiek=nullptr;
    Node*next_wizyta=nullptr;
};

Node* head_alfabetycznie = nullptr;
Node* head_wiekiem = nullptr;
Node* head_wizytami = nullptr;

void dodaj(string data, string godzina, string pesel, string imie, string nazwisko) {
    Person* person = new Person;
    person->date = data + " " + godzina;
    person->pesel = pesel;
    person->fullname = nazwisko + " " + imie ;

    if (head_alfabetycznie == nullptr) {
        Node* head = new Node;
        head->person = person;
        head_alfabetycznie = head;
    } else {
        Node* temp = head_alfabetycznie;

        if (temp->person->fullname > person->fullname) {
            Node* new_node = new Node;
            new_node->person = person;
            new_node->next = head_alfabetycznie;
            head_alfabetycznie = new_node;
            return;
        }

        while (temp->next != nullptr) {
            if (temp->person->fullname < person->fullname && person->fullname <= temp->next->person->fullname) {
                Node* new_node = new Node;
                new_node->person = person;

                new_node->next = temp->next;
                temp->next = new_node;
                return;
            } else {
                temp = temp->next;
            }
        }
        Node* new_node = new Node;
        new_node->person = person;
        temp->next = new_node;
    }
}

void wypisz() {
    Node *temp = head_alfabetycznie;
    while (temp != nullptr) {
        cout << temp->person->fullname << endl;
        temp = temp->next;
    }
}

void usun() {

}

int main(int argc, char* argv[]) {
    // ifstream file("pacjenci_10.txt"); //argv[1]
    //
    // std::string date1 = "2024-01-09 12:30";
    // std::string date2 = "2024-01-03 10:45";
    // if (date1 < date2) {
    //     cout << "date1 < date2" << endl;
    // }
    // else {
    //     cout << "date1 > date2" << endl;
    // }

    string line;

    while(getline(file, line)) {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "dodaj") {
            string data, godzina, nazwisko, imie, pesel;
            ss >> data >> godzina >> pesel >> imie >> nazwisko;
            dodaj(data, godzina, pesel, imie, nazwisko);

        } else if (command == "wypisz") {
            cout << "wypisz" << endl;
        } else if (command == "usun") {
            cout << "usun" << endl;
        }
    }

    wypisz();

    return 0;
}