hoarding.out: main.o boardManager.o playerManager.o ruleManager.o
	gcc -g -Wall -Werror -o hoarding.out main.o boardManager.o playerManager.o ruleManager.o

main.o: main.c boardManager.h ruleManager.h playerManager.h structs.h
	gcc -g -Wall -Werror -c main.c

boardManager.o: boardManager.c boardManager.h structs.h
	gcc -g -Wall -Werror -c boardManager.c

playerManager.o: playerManager.c playerManager.h structs.h
	gcc -g -Wall -Werror -c playerManager.c

ruleManager.o: ruleManager.c ruleManager.h structs.h
	gcc -g -Wall -Werror -c ruleManager.c

clean:
	rm -fr *.o *.out