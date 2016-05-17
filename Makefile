main : main.o hugeInt.o
		g++ -o main main.o hugeInt.o

hugeInt.o : hugeInt.cpp hugeInt.h
		g++ -c hugeInt.cpp

main.o : main.cpp hugeInt.h
		g++ -c main.cpp

clean : 
		rm hugeInt *.o
