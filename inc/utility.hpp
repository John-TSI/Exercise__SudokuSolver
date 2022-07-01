#ifndef UTILITY_HPP
#define UTILITY_HPP

#include"board.hpp"


namespace _Sudoku
{
    using coords = std::array<int,2>;


    // --- output ---
    void PrintBoard(const board&);
    void FailureStatement();

    // --- misc ---
    coords FindBoxCoords(const int, const int); // row,col

    // --- check placements ---
    bool ValidRowPlacement(const board&, const int, const int); // row,num
    bool ValidColPlacement(const board&, const int, const int); // col,num
    bool ValidBoxPlacement(const board&, const int, const int, const int); // row,col,num
    bool ValidPlacement(const board&, const int, const int, const int); // row,col,num

    // --- recursive solve ---
    bool SolutionFound(board&);
    void Solve(board&);
}

#endif // UTILITY_HPP