// cardtest1.c
//
// Matt Fjerstad
// July 11, 2017
//
// This contains the unit tests for the Smithy card.
//
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
 * This test checks to make sure after a game is intialized,
 * when a player plays the Smithy card they have a hand count
 * 2 greater than before. (+3 draw cards -1 discard Smithy)
 */
int testSmithEffect(){
    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, salvager,
        great_hall, tribute, smithy};
    initializeGame(2, k, 1, &g);
    
    int startHandCount = g.handCount[0];
    printf("Testing Smithy. Player starting with %i cards\n", startHandCount);
    
    int success = playSmithy(&g, 0, 0);
    
    if (success > 0) {
        printf("smithEffect(): FAIL when executing smithy card\n");
        return 0;
    }
    
    int endHandCount = g.handCount[0];
    printf("Player ended with %i cards\n", endHandCount);
    int passed = assertEquals(endHandCount, startHandCount+2);
    if (passed){
        printf("smithEffect(): PASS when executing smithy card\n");
    } else {
        printf("smithEffect(): FAIL when executing smithy card\n");
    }
    return passed;
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Card Test 1 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testSmithEffect();
    
    int failedTests = 1 - passedTests;
    printf("*************************\n");
    printf("* Card Test 1 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
