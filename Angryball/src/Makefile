FLAGS = -pedantic-errors -std=c++11

main: BallCollision.o BrickGenerator.o main.o
	g++ $(FLAGS) BallCollision.o BrickGenerator.o main.o -o main -lncurses

main.o: main.cpp ../include/BallCollision.h ../include/BrickGenerator.h
	g++ $(FLAGS) -c main.cpp

BallCollision.o: BallCollision.cpp ../include/BallCollision.h ../include/BrickGenerator.h
	g++ $(FLAGS) -c BallCollision.cpp

BrickGenerator.o: BrickGenerator.cpp ../include/BrickGenerator.h
	g++ $(FLAGS) -c BrickGenerator.cpp

clean:
	rm -f main BallCollision.o BrickGenerator.o main.o

.PHONY: clean