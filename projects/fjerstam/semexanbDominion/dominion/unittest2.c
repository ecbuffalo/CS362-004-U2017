// unittest2.c
//
// Matt Fjerstad
// July 11, 2017
//
// This contains the unit tests for scoreFor function
// and tests if the score for a player is correct based
// on hand, discard and deck.

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
 * This test checks whether the score is correct
 * when comprised of the Hand
 */
int testScoreForHand(){
    struct gameState g;
    
    g.handCount[0] = 5;
    g.hand[0][0] = curse;
    g.hand[0][1] = estate;
    g.hand[0][2] = duchy;
    g.hand[0][3] = province;
    g.hand[0][4] = great_hall;
    
    g.discardCount[0] = 0;
    g.deckCount[0] = 0;
    
    int score = scoreFor(0, &g);
    if(assertEquals(score, 10)){
        printf("scoreFor(): PASS when comprised of Hand\n");
        return 1;
    } else {
        printf("scoreFor(): FAIL when comprised of Hand\n");
        return 0;
    }
}

/*
 * This test checks whether the score is correct
 * when comprised of the Discard
 */
int testScoreForDiscard(){
    struct gameState g;
    
    g.handCount[0] = 0;
    
    g.discardCount[0] = 5;
    g.discard[0][0] = curse;
    g.discard[0][1] = estate;
    g.discard[0][2] = duchy;
    g.discard[0][3] = province;
    g.discard[0][4] = great_hall;
    
    g.deckCount[0] = 0;
    
    int score = scoreFor(0, &g);
    if(assertEquals(score, 10)){
        printf("scoreFor(): PASS when comprised of Discard\n");
        return 1;
    } else {
        printf("scoreFor(): FAIL when comprised of Discard\n");
        return 0;
    }
}

/*
 * This test checks whether the score is correct
 * when comprised of the Deck
 */
int testScoreForDeck(){
    struct gameState g;
    
    g.handCount[0] = 0;
    g.discardCount[0] = 0;
    
    g.deckCount[0] = 5;
    g.deck[0][0] = curse;
    g.deck[0][1] = estate;
    g.deck[0][2] = duchy;
    g.deck[0][3] = province;
    g.deck[0][4] = great_hall;
    
    int score = scoreFor(0, &g);
    if(assertEquals(score, 10)){
        printf("scoreFor(): PASS when comprised of Deck\n");
        return 1;
    } else {
        printf("scoreFor(): FAIL when comprised of Deck\n");
        return 0;
    }
}


int main(){
    printf("*************************\n");
    printf("* Unit Test 2 starting...\n");
    printf("*************************\n");
    
    int passedTests = 0;
    passedTests += testScoreForHand();
    passedTests += testScoreForDiscard();
    passedTests += testScoreForDeck();
    
    int failedTests = 3 - passedTests;
    printf("*************************\n");
    printf("* Unit Test 2 ending...\n");
    printf("* %i Passed tests\n", passedTests);
    printf("* %i Failed tests\n", failedTests);
    printf("*************************\n");
    
}
