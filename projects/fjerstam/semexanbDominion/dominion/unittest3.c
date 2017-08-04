// unittest3.c
//
// Matt Fjerstad
// July 11, 2017
//
// This contains the unit tests for fullDeckCount and
// checks if the total number of cards between deck, hand
// and discard is correct

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
 * This test checks if the deck count is correct
 * based only on the Deck
 */
int testFullDeckCountDeck(){
    struct gameState g;
    
    g.handCount[0] = 0;
    g.discardCount[0] = 0;
    
    g.deckCount[0] = 5;
    g.deck[0][0] = curse;
    g.deck[0][1] = estate;
    g.deck[0][2] = duchy;
    g.deck[0][3] = estate;
    g.deck[0][4] = estate;
    
    int count = fullDeckCount(0, estate, &g);
    if(assertEquals(count, 3)){
        printf("fullDeckCount(): PASS when comprised of Deck\n");
        return 1;
    } else {
        printf("fullDeckCount(): FAIL when comprised of Deck\n");
        return 0;
    }
}

/*
 * This test checks if the deck count is correct
 * based only on the Hand
 */
int testFullDeckCountHand(){
    struct gameState g;
    
    g.handCount[0] = 5;
    g.hand[0][0] = curse;
    g.hand[0][1] = estate;
    g.hand[0][2] = duchy;
    g.hand[0][3] = duchy;
    g.hand[0][4] = duchy;
    
    g.discardCount[0] = 0;
    g.deckCount[0] = 0;
    
    int count = fullDeckCount(0, duchy, &g);
    if(assertEquals(count, 3)){
        printf("fullDeckCount(): PASS when comprised of Hand\n");
        return 1;
    } else {
        printf("fullDeckCount(): FAIL when comprised of Hand\n");
        return 0;
    }
}

/*
 * This test checks if the deck count is correct
 * based only on the Discard
 */
int testFullDeckCountDiscard(){
    struct gameState g;
    
    g.handCount[0] = 0;
    
    g.discardCount[0] = 5;
    g.discard[0][0] = province;
    g.discard[0][1] = estate;
    g.discard[0][2] = province;
    g.discard[0][3] = province;
    g.discard[0][4] = great_hall;
    
    g.deckCount[0] = 0;
    
    int count = fullDeckCount(0, province, &g);
    if(assertEquals(count, 3)){
        printf("fullDeckCount(): PASS when comprised of Discard\n");
        return 1;
    } else {
        printf("fullDeckCount(): FAIL when comprised of Discard\n");
        return 0;
    }
}

/*
 * This is the main function that will run all tests and report results
 */
int main(){
    printf("*************************\n");
    printf("* Unit Test 3 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testFullDeckCountDeck();
    passedTests += testFullDeckCountHand();
    passedTests += testFullDeckCountDiscard();
    
    int failedTests = 3 - passedTests;
    printf("*************************\n");
    printf("* Unit Test 3 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
