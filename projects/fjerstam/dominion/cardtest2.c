// cardtest2.c
//
// Matt Fjerstad
// July 13, 2017
//
// This contains the unit tests for the Great Hall card. The card
// gives +1 action and +1 card
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
 * The test checks the Great Hall card effect. Player should get +1 card
 * and +1 action but discards the Great Hall card
 * so hand count should stay the same with action being +1.
 */
int testGreatHall() {
    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, salvager,
        great_hall, tribute, smithy};
    initializeGame(2, k, 1, &g);
    
    int startHandCount = g.handCount[0];
    g.numActions = 3; // Start with non-standard number of actions
    int startActionCount = g.numActions;
    printf("Testing Great Hall. Player starting with %i cards and %i actions\n", startHandCount, startActionCount);
    
    int success = greatHallEffect(0, 0, &g);
    
    if (success > 0) {
        printf("greatHallEffect(): FAIL when executing great hall card\n");
        return 0;
    }
    
    int endHandCount = g.handCount[0];
    int endActionCount = g.numActions;
    
    int correctHandCount = assertEquals(startHandCount, endHandCount);
    int correctActionCount = assertEquals(startActionCount+1, endActionCount);
    
    if(correctHandCount && correctActionCount){
        printf("greatHallEffect(): PASS when executing great hall card\n");
        return 1;
    } else {
        printf("greatHallEffect(): FAIL when executing great hall card\n");
        return 0;
    }
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Card Test 2 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testGreatHall();
    
    int failedTests = 1 - passedTests;
    printf("*************************\n");
    printf("* Card Test 2 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
