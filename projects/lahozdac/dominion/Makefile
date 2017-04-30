CFLAGS = -Wall -fpic -coverage
TESTSOURCES = dominion.o rngs.o unitTestUtilities.o unittest1.o unittest2.o unittest3.o unittest4.o cardtest1.o cardtest2.o cardtest3.o cardtest4.o

rngs.o: rngs.h rngs.c
	gcc -c rngs.c -g  $(CFLAGS)

dominion.o: dominion.h dominion.c rngs.o
	gcc -c dominion.c -g  $(CFLAGS)

playdom: dominion.o playdom.c
	gcc -o playdom playdom.c -g dominion.o rngs.o $(CFLAGS) -lm

testDrawCard: testDrawCard.c dominion.o rngs.o
	gcc -o testDrawCard -g  testDrawCard.c dominion.o rngs.o $(CFLAGS) -lm

badTestDrawCard: badTestDrawCard.c dominion.o rngs.o
	gcc -o badTestDrawCard -g  badTestDrawCard.c dominion.o rngs.o $(CFLAGS) -lm

testBuyCard: testBuyCard.c dominion.o rngs.o
	gcc -o testBuyCard -g  testBuyCard.c dominion.o rngs.o $(CFLAGS) -lm

testAll: dominion.o testSuite.c
	gcc -o testSuite testSuite.c -g  dominion.o rngs.o $(CFLAGS) -lm

interface.o: interface.h interface.c
	gcc -c interface.c -g  $(CFLAGS)

runtests: unittest
	./unittest &> unittestresult.out
	gcov -b dominion.c >> unittestresult.out
	cat dominion.c.gcov >> unittestresult.out

unittest: unitTestMain.c unitTestUtilities.h unitTest.h dominion.h ${TESTSOURCES}
	gcc -o unittest unitTestMain.c ${TESTSOURCES} $(CFLAGS) -lm

unitTestUtilities.o: unitTestUtilities.h unitTestUtilities.c
	gcc -c unitTestUtilities.c -g $(CFLAGS)

unittest1.o: unittest1.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c unittest1.c -g $(CFLAGS)

unittest2.o: unittest2.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c unittest2.c -g $(CFLAGS)

unittest3.o: unittest3.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c unittest3.c -g $(CFLAGS)

unittest4.o: unittest4.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c unittest4.c -g $(CFLAGS)

cardtest1.o: cardtest1.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c cardtest1.c -g $(CFLAGS)

cardtest2.o: cardtest2.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c cardtest2.c -g $(CFLAGS)

cardtest3.o: cardtest3.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c cardtest3.c -g $(CFLAGS)

cardtest4.o: cardtest4.c unitTest.h unitTestUtilities.h unitTestUtilities.c
	gcc -c cardtest4.c -g $(CFLAGS)

player: player.c interface.o
	gcc -o player player.c -g  dominion.o rngs.o interface.o $(CFLAGS) -lm

all: playdom player

clean:
	rm -f *.o playdom testDrawCard badTestDrawCard testSuite unittest player *.out *.gcov *.gcda *.gcno *.so
