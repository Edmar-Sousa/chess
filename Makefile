all:
	g++ -c Board.cpp -o build/board.o
	g++ -c UI.cpp -o build/ui.o
	g++ -c BoardHouses.cpp -o build/boardhouses.o

	g++ Main.cpp build/*.o -o build/Main -lraylib -lm -ldl -lpthread -lGL