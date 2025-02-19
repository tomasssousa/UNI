// By: Gonçalo Leão
// Updated by DA 24/25 Team

#include <vector>
#include <algorithm> // for sort
#include <bitset>
#include <cmath>

unsigned int knapsackBF(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    unsigned int totalCombs = pow(2,n);
    unsigned int maxV = 0;

    for(unsigned int i = 0; i < totalCombs; i++) {
          std::bitset<25> binarySubset(i);
          unsigned int totalV = 0;
          unsigned int totalW = 0;
          for(unsigned int j = 0; j < n; j++) {
            totalV += values[j] * binarySubset[j];
            totalW += weights[j] * binarySubset[j];
          }
          if(totalW <= maxWeight) {
              if(totalV > maxV) {
                  maxV = totalV;
                  for (int i = 0; i < n; i++) {
                      if (binarySubset[i] == 0) {usedItems[i] = false;}
                      else {usedItems[i] = true;}
                  }
              }
          }
    }
    return maxV;
}

// does not guarantee the optimal solution in the current form
unsigned int knapsackGreedyValue(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {
    int maxV = 0;
    bool sol = false;

    return maxV;
}

// does not guarantee the optimal solution in the current form
unsigned int knapsackGreedyWeight(unsigned int values[], unsigned int weights[], unsigned int n, unsigned int maxWeight, bool usedItems[]) {

    return maxV;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP2_Ex3, testKnapsack_4items) {
    const unsigned int n = 4;
    {
        unsigned int values[n] = {10, 7, 11, 15};
        unsigned int weights[n] = {1, 2, 1, 3};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 5, usedItems), 36);
        EXPECT_EQ(usedItems[0], true);
        EXPECT_EQ(usedItems[1], false);
        EXPECT_EQ(usedItems[2], true);
        EXPECT_EQ(usedItems[3], true);
    }

    {
        unsigned int values[n] = {3, 4, 5, 6};
        unsigned int weights[n] = {2, 3, 4, 5};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 5, usedItems), 7);
        EXPECT_EQ(usedItems[0], true);
        EXPECT_EQ(usedItems[1], true);
        EXPECT_EQ(usedItems[2], false);
        EXPECT_EQ(usedItems[3], false);
    }
}

// this test is expected to fail
TEST(TP2_Ex3, testKnapsack_4items_greedy_fail) {
    const unsigned int n = 4;
    {
        unsigned int values[n] = {10, 7, 11, 15};
        unsigned int weights[n] = {1, 2, 1, 5};
        bool usedItems[n];

        EXPECT_EQ(knapsackGreedyValue(values, weights, n, 5, usedItems), 28);
        weights[0]=1;
        weights[1]=1;
        weights[3]=3;
        EXPECT_EQ(knapsackGreedyWeight(values, weights, n, 5, usedItems), 36);

    }
}


TEST(TP2_Ex3, testKnapsack_5items) {
    const unsigned int n = 5;
    {
        unsigned int values[n] = {1, 2, 5, 9, 4};
        unsigned int weights[n] = {2, 3, 3, 4, 6};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 10, usedItems), 16);
        EXPECT_EQ(usedItems[0], false);
        EXPECT_EQ(usedItems[1], true);
        EXPECT_EQ(usedItems[2], true);
        EXPECT_EQ(usedItems[3], true);
        EXPECT_EQ(usedItems[4], false);
    }
}


TEST(TP2_Ex3, testKnapsack_40items) {
    const unsigned int n = 20;
    {
        unsigned int values[n] = {1, 2, 5, 9, 4, 1,  2, 3, 8, 4,12, 20,
                                  1, 4, 4 ,3, 3, 6, 6, 4};
        unsigned int weights[n] = {2, 3, 3, 4, 4,3, 2, 1, 4, 6,10, 10, 3, 1, 6,2, 3, 3, 4, 6};
        bool usedItems[n];

        EXPECT_EQ(knapsackBF(values, weights, n, 10, usedItems), 24);

    }
}