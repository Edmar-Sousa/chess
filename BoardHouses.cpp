#include "BoardHouses.hpp"
#include <cstdint>
#include <ostream>
#include "Constants.hpp"

// [TODO] This not working
std::ostream& operator<<(std::ostream& os, BoardHouses house) {
    uint8_t file = house % COLS;
    char rank = (int) 'H' - (house / ROWS);

    os << rank << file;
    return os;
}
