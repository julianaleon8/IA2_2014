all: main

main: dataReader.o  network.o main.o

	g++ -std=c++11 -O2 -o main dataReader.o main.o network.o

dataReader.o: dataReader.cpp dataReader.h

	g++ -std=c++11 -O2 -c dataReader.cpp

network.o: network.cpp network.h

	g++ -std=c++11 -O2 -c network.cpp


main.o: main.cpp dataReader.h

	g++ -std=c++11 -O2 -c main.cpp


clean:

	rm *.o  main
