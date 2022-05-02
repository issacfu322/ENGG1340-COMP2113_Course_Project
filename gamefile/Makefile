FLAGS = -pedantic-errors -std=c++11

roll_dice.o: roll_dice.cpp roll_dice.h
	g++ $(FLAGS) -c $<

guess_num.o: guess_num.cpp guess_num.h
	g++ $(FLAGS) -c $<

battleship.o: battleship.cpp battleship.h
	g++ $(FLAGS) -c $<

blackjack.o: blackjack.cpp blackjack.h
	g++ $(FLAGS) -c $<
	
commonsensequestions.o: commonsensequestions.cpp commonsensequestions.h
	g++ $(FLAGS) -c $<

rockpaperscissors.o: rockpaperscissors.cpp rockpaperscissors.h
	g++ $(FLAGS) -c $<
	
main.o: main.cpp roll_dice.h guess_num.h battleship.h blackjack.h commonsensequestions.h rockpaperscissors.h
	g++ $(FLAGS) -c $<

main: main.o roll_dice.o guess_num.o battleship.o blackjack.o commonsensequestions.o rockpaperscissors.o
	g++ $^ -o $@

clean:
	rm -f *.o main

.PHONY: clean

