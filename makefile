TARGET = Zadanie1-3-output
CC = g++

$(TARGET) : Zadanie1-3.o sorts.o
	$(CC) Zadanie1-3.o sorts.o -o $(TARGET)

Zadanie1-3.o : Zadanie1-3.cpp
	$(CC) -c Zadanie1-3.cpp -o Zadanie1-3.o

sorts.o : sorts.cpp
	$(CC) -c sorts.cpp -o sorts.o

clean : 
	rm $(TARGET) *.o 

