// randomtestcard2.c
//
// Matt Fjerstad
// July 26, 2017
//
// This contains the random tests for the Village card

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This test checks the Village card effect. Player should get +1 card
 * and +2 action but discards the Village card and uses one action
 * so hand count should stay the same and action count will be +1.
 */
int testVillage(int handCount, int numActions) {
    int success;
    int endHandCount;
    int endNumActions;
    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, salvager,
        great_hall, tribute, smithy};
    
    initializeGame(2, k, 1, &g);
    
    g.handCount[0] = handCount;
    g.numActions = numActions;
    
    success = playVillage(&g, 0, 0);
    
    if (success > 0) {
        printf("villageEffect(): FAIL when executing villages card\n");
        return 0;
    }
    
    endHandCount = g.handCount[0];
    endNumActions = g.numActions;
    
    if (endHandCount == handCount && endNumActions == (numActions+1)) {
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
    int numActions;
    
    while(i < numTests){
        handCount = rand() % MAX_HAND;
        numActions = rand() % 5;
        testPassed = testVillage(handCount, numActions);
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
    printf("* Random Card Test 2 starting...\n");
    printf("* Testing Village card...\n");
    printf("* Performing %i tests...\n",numTests);
    printf("*************************\n");
    
    passedTests += executeTests(numTests);
    failedTests = numTests - passedTests;
    
    printf("*************************\n");
    printf("* Random Card Test 2 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
