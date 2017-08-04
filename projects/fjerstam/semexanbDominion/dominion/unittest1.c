// unittest1.c
//
// Matt Fjerstad
// July 11, 2017
//
// This contains the unit tets for the function isGameOver
// and will test the various end game scenarios for Dominion.

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
 * This test is for if there are no Province
 * cards left. The game should be over.
 */
int testIsGameOverTrueNoProvinces() {
    struct gameState g;
    g.supplyCount[province] = 0;
    
    int result = isGameOver(&g);
    if(assertEquals(result,1)){
        printf("isGameOver(): PASS if no provinces\n");
        return 1;
    } else {
        printf("isGameOver(): FAIL if no provinces\n");
        return 0;
    }
}

/*
 * This test is for if there are 3 empty supply
 * piles. The game should be over.
 */
int testIsGameOverTrueThreeEmptyDecks() {
    int i;
    struct gameState g;
    
    // Initialize all the supply decks
    for (i = 0; i < 25; i++){
        g.supplyCount[i] = 10;
    }
    
    // Empty 3 decks. Not Province
    g.supplyCount[copper] = 0;
    g.supplyCount[estate] = 0;
    g.supplyCount[gold] = 0;
    
    
    int result = isGameOver(&g);
    if(assertEquals(result,1)){
        printf("isGameOver(): PASS if 3 empty supplies\n");
        return 1;
    } else {
        printf("isGameOver(): FAIL if 3 empty supplies\n");
        return 0;
    }
}

/*
 * This test is for if there are Provice cards left
 * and only 2 empty supply piles. The game should not be over.
 */
int testIsGameOverFalse(){
    int i;
    struct gameState g;
    
    // Initialize all the supply decks
    for (i = 0; i < 25; i++){
        g.supplyCount[i] = 10;
    }
    
    // Empty 2 decks. Not Province
    g.supplyCount[copper] = 0;
    g.supplyCount[gold] = 0;
    
    
    int result = isGameOver(&g);
    if(assertEquals(result,0)){
        printf("isGameOver(): PASS if game not over\n");
        return 1;
    } else {
        printf("isGameOver(): FAIL if game not over\n");
        return 0;
    }
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Unit Test 1 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testIsGameOverTrueNoProvinces();
    passedTests += testIsGameOverTrueThreeEmptyDecks();
    passedTests += testIsGameOverFalse();
    
    int failedTests = 3 - passedTests;
    printf("*************************\n");
    printf("* Unit Test 1 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
