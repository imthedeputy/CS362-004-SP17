#include "dominion.h"
#include <stdio.h>

int cmpGameState (struct gameState* gs1, struct gameState* gs2) {
	int i, j, k, l;

	if(gs1->numPlayers != gs2->numPlayers)
		return 0;
	else if(gs1->whoseTurn != gs2->whoseTurn)
		return 0;
	else if(gs1->outpostPlayed != gs2->outpostPlayed)
		return 0;
	else if(gs1->outpostTurn != gs2->outpostTurn)
		return 0;
	else if(gs1->phase != gs2->phase)
		return 0;
	else if(gs1->numActions != gs2->numActions)
		return 0;
	else if(gs1->coins != gs2->coins)
		return 0;
	else if(gs1->numBuys != gs2->numBuys)
		return 0;
	else if(gs1->playedCardCount != gs2->playedCardCount)
		return 0;

	for (i = 0; i <= treasure_map; i++) {
		if(gs1->supplyCount[i] != gs2->supplyCount[i])
			return 0;
		else if(gs1->embargoTokens[i] != gs2->embargoTokens[i])
			return 0;
	}

	for (i = 0; i < MAX_PLAYERS; i++) {
		if(gs1->handCount[i] != gs2->handCount[i])
			return 0;
		else if(gs1->deckCount[i] != gs2->deckCount[i])
			return 0;
		else if(gs1->discardCount[i] != gs2->discardCount[i])
			return 0;

		for (j = 0; j < gs1->handCount[i]; j++) {
			if(gs1->hand[i][j] != gs2->hand[i][j])
				return 0;
		}

		for (k = 0; k < gs1->deckCount[i]; k++) {
			if(gs1->deck[i][k] != gs2->deck[i][k])
				return 0;
		}

		for (l = 0; l < gs1->discardCount[i]; l++) {
			if(gs1->discard[i][l] != gs2->discard[i][l])
				return 0;
		}
	}

	for (i = 0; i < gs1->playedCardCount; i++) {
		if(gs1->playedCards[i] != gs2->playedCards[i])
			return 0;
	}

	return 1;
}

void printGameState(struct gameState* state1, struct gameState* state2) {
	printf("numPlayers: %d %d\n",state1->numPlayers,state2->numPlayers);
	printf("outpostPlayed: %d %d\n",state1->outpostPlayed,state2->outpostPlayed);
	printf("outpostTurn: %d %d\n",state1->outpostTurn,state2->outpostTurn);
	printf("whoseTurn: %d %d\n",state1->whoseTurn,state2->whoseTurn);
	printf("phase: %d %d\n",state1->phase,state2->phase);
	printf("numActions: %d %d\n",state1->numActions,state2->numActions);
	printf("coins: %d %d\n",state1->coins,state2->coins);
	printf("numBuys: %d %d\n",state1->numBuys,state2->numBuys);
}