//
// Created by Pascal Charpentier on 2024-11-15.
//

#include "heap.h"
#include "gtest/gtest.h"

class TestHeap : public ::testing::Test {
protected:
    TestHeap() : h5(std::vector<int> {3, 1, 8, 6, 1}) {}

    Heap<int> h5 ;
};

TEST_F(TestHeap, h5_inserer_0_en_tete_0) {
    h5.inserer(0) ;
    EXPECT_EQ(0, h5.teteDeFile()) ;
}

TEST_F(TestHeap, h5_inserer_0_taille_6) {
    h5.inserer(0) ;
    EXPECT_EQ(6, h5.taille()) ;
}

TEST_F(TestHeap, h5_extractMin_taille_4) {
    h5.extraireTete() ;
    EXPECT_EQ(4, h5.taille()) ;
}

TEST_F(TestHeap, h5_extractMin_en_tete_1) {
    h5.extraireTete() ;
    EXPECT_EQ(1, h5.teteDeFile()) ;
}

TEST_F(TestHeap, h5_successive_extract_min_to_empty) {
    std::vector<int> values {1, 1, 3, 6, 8} ;
    for (size_t i = 0; i < 5; ++i) {
        EXPECT_EQ(values.at(i), h5.teteDeFile()) ;
        h5.extraireTete() ;
    }
    EXPECT_TRUE(h5.estVide()) ;
}