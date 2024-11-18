#include <iostream>
#include "heap.h"

template <typename K>
struct MonComparateur {
    bool operator() (const K& a, const K& b) const {
        return a > b ;
    }
};

/*
 * Ce programme démontre les manières de créer un heap avec un objet fonctionnel représentant l'ordre des clés.
 * Dans le premier exemple, le paramètre de type Comparateur n'est pas précisé, le compilateur utilise donc
 * le type par défaut std::less qui va retourner l'opérateur < du type clé.
 *
 * Dans le deuxième exemple, on a créé un heap max avec un objet fonction déclaré plus haut.  C'est la manière la
 * plus intuitive de procéder.
 *
 * Dans le troisième exemple on a créé un heap max avec une expression lambda.  Remarquer la syntaxe compliquée dans
 * la déclaration des types du heap...
 */
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
