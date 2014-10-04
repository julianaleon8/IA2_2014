all: main

main: perceptron.o  main.o

	g++  -std=c++11 -g -o main perceptron.o main.o

perceptron.o: perceptron.cpp perceptron.h

	g++  -std=c++11 -g -c perceptron.cpp

main.o: main.cpp perceptron.h

	g++  -std=c++11 -g -c main.cpp

clean:

	rm *.o *.exe main