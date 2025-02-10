#include <iostream>
#include <vector>

int f_iterative(int x) {
    if (x > 50) {
        return 9;
    }
    
    std::vector<int> values(51, 0);  // Inicjalizacja wektora dla x od 0 do 50
    
    // Wypełnij wartości dla x > 20
    for (int i = 51; i <= 100; ++i) {
        values[i] = 9;
    }
    
    // Oblicz wartości dla x od 20 do 0
    for (int i = 50; i >= 0; --i) {
        if (i > 20) {
            values[i] = 9;
        } else {
            values[i] = 5 * values[i + 3] + 7;
        }
    }
    
    return values[x];
}

int main() {
    for (int x = 0; x < 20; ++x) {
        std::cout << "f(" << x << ") = " << f_iterative(x) << std::endl;
    }
    
    return 0;
}