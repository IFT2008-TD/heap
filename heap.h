//
// Created by Pascal Charpentier on 2024-11-15.
//

#ifndef HEAP_SEANCE_HEAP_H
#define HEAP_SEANCE_HEAP_H

#include <functional>
#include <vector>

/**
 * Template de classe heap.  Permet d'implanter un heap avec un ordre arbitraire.  Supporte les primitives:
 * construction: à-partir d'un vecteur de clés. \Theta(n)
 * inserer: insérer une nouvelle clé dans le heap.  Peut ou non être distincte. \Theta(log(n))
 * teteDeFile: lire l'élément en tête du heap sans modifier celui-ci. \Theta(1)
 * extraireTete: retirer l'élément en tête du heap. \Theta(log(n))
 * @tparam Cle Type des clés
 * @tparam Comparateur Objet fonctionnel Cle X Cle -> bool retournant true si cle1 précède cle2, false sinon.
 */
template <typename Cle, typename Comparateur = std::less<Cle>>
class Heap {
private:
    static size_t enfantGauche(size_t i) ;
    static size_t parent(size_t i) ;
    size_t dernierParent() const ;

    void percolerEnBas(size_t i) ;
    void percolerEnHaut(size_t i) ;

    void heapifier() ;

    bool invariant() const ;

public:
    explicit Heap(const std::vector<Cle>& v) ;
    Heap(const std::vector<Cle>& v, Comparateur objComp) ;

    Heap(const Heap& source) = default ;
    ~Heap() = default ;

    void inserer(const Cle& key) ;
    const Cle& teteDeFile() const ;
    void extraireTete() ;

    size_t taille() const ;
    bool estVide() const ;

private:
    size_t cardinal ;
    std::vector<Cle> heap ;
    Comparateur precede ;
};


template<typename K, typename Comp>
Heap<K, Comp>::Heap(const std::vector<K>& v) : cardinal(v.size()), heap(v) {
    heapifier() ;
    assert(invariant()) ;
}

template<typename K, typename Comp>
void Heap<K, Comp>::heapifier() {
    if (heap.size() < 2) return ;
    for (size_t i = 0; i <= dernierParent(); ++i) {
        percolerEnBas(dernierParent() - i) ;
    }
}

template<typename K, typename Comp>
size_t Heap<K, Comp>::enfantGauche(size_t i) {
    return 2 * i + 1 ;
}

template<typename K, typename Comp>
size_t Heap<K, Comp>::parent(size_t i) {
    return (i - 1) / 2 ;
}

template<typename K, typename Comp>
size_t Heap<K, Comp>::dernierParent() const {
    return cardinal / 2 - 1 ;
}

template<typename K, typename Comp>
void Heap<K, Comp>::percolerEnBas(size_t i) {
    size_t index_enfant = enfantGauche(i) ;
    while (index_enfant < cardinal) {
        if (index_enfant < cardinal - 1 && precede(heap.at(index_enfant + 1), heap.at(index_enfant)))
            ++ index_enfant ;
        if (precede(heap.at(index_enfant), heap.at(i))) {
            std::swap(heap.at(i), heap.at(index_enfant)) ;
            i = index_enfant ;
            index_enfant = enfantGauche(i) ;
        }
        else break ;
    }
}

template<typename K, typename Comp>
void Heap<K, Comp>::percolerEnHaut(size_t i) {
    size_t index_parent = parent(i) ;
    while (i > 0 && precede(heap.at(i), heap.at(index_parent))){
        std::swap(heap.at(index_parent), heap.at(i)) ;
        i = index_parent ;
        index_parent = parent(i) ;
    }
}

template<typename K, typename Comp>
bool Heap<K, Comp>::invariant() const {
    if (cardinal > heap.size()) return false ;
    if (cardinal < 2) return true ;
    for (size_t i = 0; i <= dernierParent(); ++i) {
        K parent_value = heap.at(i) ;
        size_t child_index = enfantGauche(i) ;
        if (precede(heap.at(child_index), parent_value)) return false ;
        if (child_index < cardinal - 1 && precede(heap.at(child_index + 1), parent_value)) return false ;
    }
    return true ;
}

template<typename K, typename Comparator_type>
void Heap<K, Comparator_type>::inserer(const K& key) {
    if (cardinal < heap.size()) heap.at(cardinal) = key ;
    else heap.push_back(key) ;
    ++ cardinal ;
    percolerEnHaut(cardinal - 1) ;

    assert(invariant()) ;
}

template<typename K, typename Comparator_type>
const K &Heap<K, Comparator_type>::teteDeFile() const {
    return heap.at(0) ;
}

template<typename K, typename Comparator_type>
size_t Heap<K, Comparator_type>::taille() const {
    return cardinal ;
}

template<typename K, typename Comparator_type>
bool Heap<K, Comparator_type>::estVide() const {
    return taille() == 0 ;
}

template<typename K, typename Comparator_type>
void Heap<K, Comparator_type>::extraireTete() {
    std::swap(heap.at(0), heap.at(cardinal - 1)) ;
    -- cardinal ;
    percolerEnBas(0) ;

    assert(invariant()) ;
}

template<typename Cle, typename Comparateur>
Heap<Cle, Comparateur>::Heap(const std::vector<Cle> &v, Comparateur objComp) : cardinal(v.size()), heap(v), precede(objComp) {
    heapifier() ;
    assert(invariant()) ;
}


#endif //HEAP_SEANCE_HEAP_H
