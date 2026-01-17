#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstdio>
#include <fstream>


using namespace std;

struct Claster {
    int size;
    unsigned char color;
};

struct Pixel {
    int x;
    int y;
};

struct Node {
    int liczba;
    Node*next;
};

//bfs dla danego koloru
//char**img - tablica z koloroami
// bool**visited - odwiedzone pola z koloem
//Pixel*start - pixel startu
Claster claster_bfs(char **img, bool**visited,Pixel*start, int w, int h) {

    queue<Pixel> next_pixels;
    next_pixels.push(start);

    Claster new_claster = {0, img[start.y][start.x]};

    while (!next_pixels.empty()) {
        Pixel *pi = next_pixels.front();
        next_pixels.pop();

        if (visited[pi.y][pi.x]) {
            continue;
        }
        new_claster.size+=1;
        visited[pi.y][pi.x]=true; //tam juz bylismy

        if (pi.x+1>=w-1&&img[pi.y][pi.x+1]==new_claster.color) {
            Pixel right {pi.x+1, pi.y};
            next_pixels.push(pi);
        }
        if (pi.x-1>=0&&img[pi.y][pi.x-1]==new_claster.color) {
            Pixel left {pi.x-1, pi.y};
            next_pixels.push(pi);
        }
        if (pi.y+1<=h-1&&img[pi.y+1][pi.x]==new_claster.color) {
            Pixel top {pi.x, pi.y+1};
            next_pixels.push(pi);
        }
        if (pi.y-1>=0&&img[pi.y-1][pi.x]==new_claster.color) {
            Pixel bottom {pi.x, pi.y-1};
            next_pixels.push(pi);
        }


    }
    return new_claster;
}
// find kolor (szuka nowych kolorów)

vector<Claster> find_claster(char** img, int w, int h) {
    vector<Claster> clasters;;
    bool**visited = new bool*[h];
    for (int i = 0; i < h; i++) {
        visited[i] = new bool[w];
        for (int j=0; j<w; j++) {
            visited[i][j] = false;
        }
    }

    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            if (visited[i][j]) {
                continue;
            }
            Pixel current={j,i};
            Claster new_claster= claster_bfs(img, visited, current, w, h);
            clasters.push_back(new_claster);
        }
    }
    return clasters;
}

int main() {
    fstream obraz("mini.pgm");
    if (!obraz.is_open()) {
        cout<<"Nie udalo sie otworzyc pliku!"<<endl;
        return 1;
    }
    string format;
    int w, h,skala;

    obraz>>format;
    obraz>>w;
    obraz>>h;
    obraz>>skala;

    cout<<endl<<format<<endl<<w<<endl<<h<<endl<<skala<<endl;

    char**img=new char*[h];

    for (int i=0; i<h; i++) {
        img[i]=new char[w];
    }
    //wczytywanie obrazka do tablicy
    for (int i=0; i<h; i++) {
        for (int j=0; j<w; j++) {
            int val;
            obraz>>val;
            img[i][j]=(char)val;
        }
    }

    vector<Claster>wyniki=find_claster(img, w, h);
    cout<<"Znaleziono "<< wyniki.size()<<" klastrów."<<endl;
    for (auto const& c : wyniki) {
        cout << "Kolor: " << (int)c.color << " Wielkosc: " << c.size << endl;
    }

    return 0;
}