# Files prioritaires

## IFT-2008: Travaux dirigés

### Introduction

Le présent projet contient une implantation élémentaire d'une file prioritaire par le biais d'un heap.
Ce heap est codé sous-forme d'un vecteur contenant des clés qui peuvent ou non être distinctes.

### Contenu du projet

- [ ] Fichier heap.h: Implantation du template de classe Heap
- [ ] Fichier main.cpp: démo illustrant comment instancier un heap avec le comparateur voulu
- [ ] Fichier test/tests_heap.cpp: tests unitaires

### Template de classe Heap

Ce template est instancié avec deux paramètres:
```Heap monHeap<TypeA, TypeB> ``` où:
- TypeA est les type de clé à stocker dans le Heap.
- TypeB est la relation d'ordre entre les clés.  C'est un objet appelable, ou fonctionnel de la forme: ```monObjet(clé1, clé2)``` qui doit retourner true si clé1 précède clé2.  TypeB est par défaut l'opérateur < et donc celui-ci doit être défini, sinon le template ne compile pas. 

### Démo dans main.cpp
Dans main.cpp on trouve trois exemples d'instanciation du template Heap:

- Avec la fonction d'ordre par défaut: donne un min-heap
- Avec la relation d'ordre >, par le biais d'un objet fonctionnel, donne un max-heap
- Avec une fonction lambda donnant aussi un max-heap.  Remarquer la syntaxe compliquée dans ce cas.

### Défis et exercices

Ce template sert à illustrer les concepts de base, et est peu utilisable tel quel.  
 - Les 
plus observateurs vont remarquer qu'il manque un primitive très importante:
```modifier_priorite(k, np)``` Cette primitive devrait permettre de retrouver la clé k et de lui assigner la nouvelle priorité np avec une complexité globale de log(n).  On ne
peut pas faire ça avec le heap actuel.  Quelles solutions peut-on apporter à ce problème?

 - Un aspect très important a aussi été escamoté: il n'y a aucune garantie que deux clés identiques restent dans l'ordre où elles ont été insérées.  Or une file prioritaire est avant tout une file, donc la propriété FIFO devrait être respectée en tout temps pour les clés de même priorité.  Y a-t-il une solution à ce problème?

