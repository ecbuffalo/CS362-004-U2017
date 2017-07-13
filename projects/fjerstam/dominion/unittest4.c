// unittest4.c
//
// Matt Fjerstad
// July 11, 2017
//
// This contains the unit tests for updateCoins and
// verifies that the sum of coins in the player's hand
// is correct

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int assertEquals(int first, int second) {
    printf("Comparing %i and %i\n", first, second);
    if (first == second) {
        return 1;
    } else {
        return 0;
    }
}

/*
 * This test covers when the player has
 * multiple coin types in hand
 */
int testUpdateCoinsAll(){
    struct gameState g;
    
    g.handCount[0] = 5;
    g.hand[0][0] = curse;
    g.hand[0][1] = estate;
    g.hand[0][2] = copper;
    g.hand[0][3] = silver;
    g.hand[0][4] = gold;
    
    updateCoins(0, &g, 0);
    
    if(assertEquals(g.coins, 6)){
        printf("updateCoins(): PASS for multiple coin types\n");
        return 1;
    } else {
        printf("updateCoins(): FAIL for multiple coin types\n");
        return 1;
    }
}

/*
 * This test covers when the player has
 * multiple coppers in hand
 */
int testUpdateCoinsCopper(){
    struct gameState g;
    
    g.handCount[0] = 5;
    g.hand[0][0] = curse;
    g.hand[0][1] = estate;
    g.hand[0][2] = copper;
    g.hand[0][3] = copper;
    g.hand[0][4] = copper;
    
    updateCoins(0, &g, 0);
    
    if(assertEquals(g.coins, 3)){
        printf("updateCoins(): PASS for multiple copper coins\n");
        return 1;
    } else {
        printf("updateCoins(): FAIL for multiple copper coins\n");
        return 1;
    }
}

/*
 * This test covers when the player has
 * multiple silvers in hand
 */
int testUpdateCoinsSilver(){
    struct gameState g;
    
    g.handCount[0] = 5;
    g.hand[0][0] = curse;
    g.hand[0][1] = estate;
    g.hand[0][2] = silver;
    g.hand[0][3] = silver;
    g.hand[0][4] = silver;
    
    updateCoins(0, &g, 0);
    
    if(assertEquals(g.coins, 6)){
        printf("updateCoins(): PASS for multiple silver coins\n");
        return 1;
    } else {
        printf("updateCoins(): FAIL for multiple silver coins\n");
        return 1;
    }
}

/*
 * This test covers when the player has
 * multiple golds in hand
 */
int testUpdateCoinsGold(){
    struct gameState g;
    
    g.handCount[0] = 5;
    g.hand[0][0] = curse;
    g.hand[0][1] = estate;
    g.hand[0][2] = gold;
    g.hand[0][3] = gold;
    g.hand[0][4] = gold;
    
    updateCoins(0, &g, 0);
    
    if(assertEquals(g.coins, 9)){
        printf("updateCoins(): PASS for multiple gold coins\n");
        return 1;
    } else {
        printf("updateCoins(): FAIL for multiple gold coins\n");
        return 1;
    }
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Unit Test 4 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testUpdateCoinsAll();
    passedTests += testUpdateCoinsCopper();
    passedTests += testUpdateCoinsSilver();
    passedTests += testUpdateCoinsGold();
    
    int failedTests = 4 - passedTests;
    printf("*************************\n");
    printf("* Unit Test 4 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
