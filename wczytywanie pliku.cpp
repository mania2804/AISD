ifstream file("slownik_11.txt" (mode) ios::binary ; // Otwieramy plik ze słownikiem
    if (!file.is_open()) {
        cerr << "Nie można otworzyć pliku!" << endl;
        return -1;