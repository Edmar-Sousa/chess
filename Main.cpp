#include "Board.hpp"
#include "UI.hpp"


int main(int argc, char ** argv)
{
    Board board;
    UI ui(board);

    ui.drawBoard();

    return 0;
}
