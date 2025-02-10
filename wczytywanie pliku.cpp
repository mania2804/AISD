PGM read_PGM() {
    ifstream file("lokomotywa.pgm", ios::binary);
    if (!file.is_open())
        throw runtime_error("Nie można otworzyć pliku.");
PGM
    file >> image.format;
    file >> image.width >> image.height;
    file >> image.max_gray;