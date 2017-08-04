// randomtestadventurer.c
//
// Matt Fjerstad
// July 26, 2017
//
// This contains the random tests for the Adventurer card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This test checks the Adventurer card effect. The card adds the next
 * two treasure cards in the deck to the players hand.
 *
 */
int testAdventurer(int handCount) {
    int success;
    int endHandCount;
    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, salvager,
        great_hall, tribute, smithy};
    
    initializeGame(2, k, 1, &g);
    
    g.handCount[0] = handCount;
    
    int cardDrawn;
    int drawntreasure = 0;
    int z = 0;
    int temphand[MAX_HAND];
    
    success = playAdventurer(&g, 0, temphand, drawntreasure, cardDrawn, z);
    
    if (success > 0) {
        printf("adventuruerEffect(): FAIL when executing adventurer card\n");
        return 0;
    }
    
    endHandCount = g.handCount[0];
    
    if (endHandCount == (handCount+2)) {
        return 1;
    }else{
        return 0;
    }
    
}

/*
 * This function will loop over the number of times to perform a test
 * and randomly generate the inputs, keeping track of the passed tests
 */
int executeTests(int numTests){
    int i = 0;
    int testPassed;
    int totalPassed = 0;
    int handCount;
    
    while(i < numTests){
        handCount = rand() % MAX_HAND;
        testPassed = testAdventurer(handCount);
        if (testPassed > 0) {
            totalPassed++;
        }
        i++;
    }
    return totalPassed;
}

/*
 * This is the main function that will run all tests and report results
 */
int main() {
    int numTests = 1000;
    int passedTests = 0;
    int failedTests;
    srand(time(NULL));
    
    printf("*************************\n");
    printf("* Random Adventurer Test starting...\n");
    printf("* Performing %i tests...\n",numTests);
    printf("*************************\n");
    
    passedTests += executeTests(numTests);
    failedTests = numTests - passedTests;
    
    printf("*************************\n");
    printf("* Random Adventurer Test ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
