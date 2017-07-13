// cardtest4.c
//
// Matt Fjerstad
// July 13, 2017
//
// This contains the unit tests for the Adventurer card. The adventurer card
// adds the next two treasure cards to the hand.
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
 * This test checks the Adventurer card effect. The card adds the next
 * two treasure cards in the deck to the players hand.
 *
 */
int testAdventurer() {
    struct gameState g;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, salvager,
        great_hall, tribute, smithy};
    initializeGame(2, k, 1, &g);
    
    int startHandCount = g.handCount[0];
    printf("Testing Adventurer. Player starting with %i cards\n", startHandCount);
    
    int success = adventurerEffect(0, &g);
    
    if (success > 0) {
        printf("adventurerEffect(): FAIL when executing adventurer card\n");
        return 0;
    }
    
    int endHandCount = g.handCount[0];
    
    if(assertEquals(startHandCount+2,endHandCount)){
        printf("adventurerEffect(): PASS when executing adventurer card\n");
        return 1;
    } else {
        printf("adventurerEffect(): FAIL when executing adventurer card\n");
        return 0;
    }
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Card Test 4 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testAdventurer();
    
    int failedTests = 1 - passedTests;
    printf("*************************\n");
    printf("* Card Test 4 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
