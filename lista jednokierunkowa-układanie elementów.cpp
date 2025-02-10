#include <iostream>
using namespace std;

// Struktura reprezentująca węzeł listy jednokierunkowej
struct Node {
    int data;               // Przechowuje wartość węzła
    Node* next;             // Wskaźnik na następny węzeł
    Node(int val) : data(val), next(nullptr) {} // Konstruktor inicjalizujący węzeł
};

// Funkcja wstawiająca nowy węzeł na koniec listy
void insert(Node*& head, int val) {
    Node* newNode = new Node(val); // Tworzenie nowego węzła
    if (!head) {                   // Jeśli lista jest pusta
        head = newNode;            // Nowy węzeł staje się głową listy
    } else {                       // Jeśli lista nie jest pusta
        Node* temp = head;
        while (temp->next) {       // Przechodzimy do ostatniego węzła
            temp = temp->next;
        }
        temp->next = newNode;      // Dodanie nowego węzła na końcu
    }
}

// Funkcja sortująca listę poprzez podział na liczby parzyste i nieparzyste
void sortList(Node*& head) {
    if (!head || !head->next) return; // Jeśli lista jest pusta lub jednoelementowa, kończymy

    Node *evenHead = nullptr, *evenTail = nullptr; // Listy dla liczb parzystych
    Node *oddHead = nullptr, *oddTail = nullptr;   // Listy dla liczb nieparzystych
    Node* current = head;

    // Podział listy na liczby parzyste i nieparzyste
    while (current) {
        Node* nextNode = current->next; // Zapamiętanie kolejnego węzła
        current->next = nullptr;        // Odłączenie bieżącego węzła

        if (current->data % 2 == 0) {   // Jeśli liczba jest parzysta
            if (!evenHead) evenHead = evenTail = current; // Pierwszy parzysty węzeł
            else {
                evenTail->next = current; // Dodanie do końca listy parzystych
                evenTail = evenTail->next;
            }
        } else {                        // Jeśli liczba jest nieparzysta
            if (!oddHead) oddHead = oddTail = current;   // Pierwszy nieparzysty węzeł
            else {
                oddTail->next = current; // Dodanie do końca listy nieparzystych
                oddTail = oddTail->next;
            }
        }
        current = nextNode; // Przejście do następnego węzła
    }

    // Funkcja do sortowania listy za pomocą sortowania bąbelkowego
    auto bubbleSort = [](Node* head) {
        if (!head) return head; // Jeśli lista jest pusta, zwracamy
        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            while (curr->next) {
                if (curr->data > curr->next->data) { // Zamiana, jeśli dane są w złej kolejności
                    swap(curr->data, curr->next->data);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped); // Powtarzamy, dopóki wykonujemy zamiany
        return head;
    };

    // Sortowanie list parzystych i nieparzystych
    evenHead = bubbleSort(evenHead);
    oddHead = bubbleSort(oddHead);

    // Łączenie posortowanych list parzystych i nieparzystych
    if (evenHead) {
        head = evenHead;
        evenTail->next = oddHead;
    } else {
        head = oddHead;
    }
}

// Funkcja wypisująca elementy listy
void printList(Node* head) {
    while (head) {
        cout << head->data << " "; // Wypisanie wartości węzła
        head = head->next;          // Przejście do następnego węzła
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Inicjalizacja pustej listy
    int n, val;
    cin >> n;             // Wczytanie liczby elementów

    // Wczytywanie elementów i wstawianie do listy
    for (int i = 0; i < n; i++) {
        cin >> val;
        insert(head, val);
    }

    sortList(head);   // Sortowanie listy
    printList(head);  // Wypisanie posortowanej listy

    return 0;
}
