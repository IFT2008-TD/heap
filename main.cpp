#include <iostream>
#include "heap.h"

template <typename K>
struct MonComparateur {
    bool operator() (const K& a, const K& b) const {
        return a > b ;
    }
};

int main() {
    Heap<int> heapMin(std::vector<int> {6, 1, 8, 2, 4, 3, 9, 0}) ;
    Heap<int, MonComparateur<int> > heapMax(std::vector<int> {6, 1, 8, 2, 4, 3, 9, 0}) ;
    Heap<int, bool (*)(int, int) > heapMaxAlt(std::vector<int> {6, 1, 8, 2, 4, 3, 9, 0}, [](int a, int b) {return a > b ; }) ;

    std::cout << "Ordre de sortie dans le heap min: \n" ;
    while (!heapMin.estVide()) {
        std::cout << heapMin.teteDeFile() << "\n" ;
        heapMin.extraireTete() ;
    }

    std::cout << "Ordre de sortie dans le heap max: \n" ;
    while (!heapMax.estVide()) {
        std::cout << heapMax.teteDeFile() << "\n" ;
        heapMax.extraireTete() ;
    }

    std::cout << "Ordre de sortie dans le deuxième heap max: \n" ;
    while (!heapMaxAlt.estVide()) {
        std::cout << heapMaxAlt.teteDeFile() << "\n" ;
        heapMaxAlt.extraireTete() ;
    }

    return 0;
}
