// cardtest3.c
//
// Matt Fjerstad
// July 13, 2017
//
// This contains the unit tests for the Village card. The card give
// +1 card and +2 actions
//

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
 * This test checks the Village card effect. Player should get +1 card
 * and +2 action
 */
int testVillage() {
    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, salvager,
        great_hall, tribute, smithy};
    initializeGame(2, k, 1, &g);
    
    int startHandCount = g.handCount[0];
    int startActionCount = g.numActions;
    printf("Testing Village. Player starting with %i cards and %i actions\n", startHandCount, startActionCount);
    
    int success = playVillage(&g, 0, 0);
    
    if (success > 0) {
        printf("villageEffect(): FAIL when executing village card\n");
        return 0;
    }
    
    int endHandCount = g.handCount[0];
    int endActionCount = g.numActions;
    
    int correctHandCount = assertEquals(startHandCount, endHandCount);
    int correctActionCount = assertEquals(startActionCount+2, endActionCount);
    
    if(correctHandCount && correctActionCount){
        printf("villageEffect(): PASS when executing village card\n");
        return 1;
    } else {
        printf("villageEffect(): FAIL when executing village card\n");
        return 0;
    }
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Card Test 3 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testVillage();
    
    int failedTests = 1 - passedTests;
    printf("*************************\n");
    printf("* Card Test 3 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
