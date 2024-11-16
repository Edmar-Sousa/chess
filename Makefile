all:
	g++ -c Board.cpp -o build/board.o

	g++ Main.cpp build/*.o -o build/Main