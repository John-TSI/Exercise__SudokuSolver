#ifndef BOARD_HPP
#define BOARD_HPP

#include<array>
#include<cmath>


namespace _Sudoku
{
    static const int SIZE{9}, boxSIZE{ (int)sqrt(SIZE) };
    using board = std::array<std::array<int, SIZE>, SIZE>;

    static board puzzle
    {
        { {0,0,8, 0,0,0, 0,6,0},
          {0,0,4, 0,5,0, 0,1,0},
          {5,2,0, 0,0,0, 0,8,0},

          {0,0,9, 0,0,0, 0,0,0},
          {8,5,2, 6,0,0, 0,7,0},
          {1,0,0, 5,8,0, 0,0,0},

          {2,0,6, 0,0,1, 4,0,8},
          {0,0,0, 4,0,0, 7,0,0},
          {0,3,1, 0,7,5, 0,9,0} }
    };
}

#endif // BOARD_HPP