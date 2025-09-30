#include <iostream>
#include "maze.hpp"


int main() {
    char mazeArr[ROWS][COLS] = {
        {'X','X','X','X','X'},
        {'X',' ',' ',' ','X'},
        {'X',' ','X',' ','X'},
        {'X',' ','X',' ','X'},
        {'X','E','X','X','X'}
    };

    bool found = maze(mazeArr, 1, 1); // start fra (1,1)

    if (found)
        std::cout << "En sti til E blev fundet!\n";
    else
        std::cout << "Ingen sti til E findes.\n";

    return 0;
}