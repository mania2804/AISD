#include <stdio.h>
#include <stdlib.h>

// Pomocnicza funkcja rekurencyjna do zliczania pikseli w jednej sali
int zlicz_sale(unsigned char *obraz, int w, int h, int x, int y) {
    if (x < 0 || x >= w || y < 0 || y >= h || obraz[y * w + x] != 255) {
        return 0;
    }

    // Zaznaczamy piksel jako odwiedzony (czyścimy go)
    obraz[y * w + x] = 0;

    // Rekurencyjnie sumujemy sąsiednie piksele (tylko boki, nie rogi)
    return 1 + zlicz_sale(obraz, w, h, x + 1, y)
             + zlicz_sale(obraz, w, h, x - 1, y)
             + zlicz_sale(obraz, w, h, x, y + 1)
             + zlicz_sale(obraz, w, h, x, y - 1);
}

int ilu_pacjentow(const char *sciezka) {
    FILE *f = fopen(sciezka, "rb");
    if (!f) return 0;

    char magic[3];
    int szer, wys, max_val;

    // Wczytanie nagłówka PGM P5
    if (fscanf(f, "%2s %d %d %d", magic, &szer, &wys, &max_val) != 4) {
        fclose(f);
        return 0;
    }
    fgetc(f); // Pomiń pojedynczy znak białej spacji po nagłówku

    int rozmiar = szer * wys;
    unsigned char *dane = (unsigned char *)malloc(rozmiar);
    if (!dane) {
        fclose(f);
        return 0;
    }

    if (fread(dane, 1, rozmiar, f) != (size_t)rozmiar) {
        free(dane);
        fclose(f);
        return 0;
    }
    fclose(f);

    int suma_pacjentow = 0;

    // Przeszukiwanie obrazu w poszukiwaniu białych pikseli (początków sal)
    for (int y = 0; y < wys; y++) {
        for (int x = 0; x < szer; x++) {
            if (dane[y * szer + x] == 255) {
                // Znaleźliśmy nową salę - obliczamy jej rozmiar w pikselach
                int piksele_sali = zlicz_sale(dane, szer, wys, x, y);

                // 1 piksel = 0.01m2. 6m2 = 600 pikseli.
                suma_pacjentow += (piksele_sali / 600);
            }
        }
    }

    free(dane);
    return suma_pacjentow;
}