#include<iostream>
#include<iomanip>
#include"../inc/utility.hpp"

using _Sudoku::coords; using _Sudoku::board;


// --- output ---
void _Sudoku::PrintBoard(const board& brd)
{
    std::cout << '\n';
    for(int row{0}; row<SIZE; ++row)
    { 
        std::cout << ( (row%3 == 0 && row != 0) ? "\n" : "");
        for(int col{0}; col<SIZE; ++col)
        {
            std::cout << ( (col%3 == 0 && col != 0) ? " " : "");

            (brd[row][col] == 0)
            ? std::cout << std::setw(2) << "~"
            : std::cout << std::setw(2) << brd[row][col];
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void _Sudoku::FailureStatement()
{
    std::cout << "Unable to generate a solution.\n";
}


// --- misc ---
coords _Sudoku::FindBoxCoords(const int row, const int col)
{
    return (coords) {row - (row % boxSIZE), col - (col % boxSIZE)};
}


// --- check placements ---
bool _Sudoku::ValidRowPlacement(const board& brd, const int row, const int num)
{
    for(int col{0}; col < SIZE; ++col)
    {
        if(brd[row][col] == num) { return false; }
    }
    return true;
}

bool _Sudoku::ValidColPlacement(const board& brd, const int col, const int num)
{
    for(int row{0}; row < SIZE; ++row)
    {
        if(brd[row][col] == num) { return false; }
    }
    return true;
}

bool _Sudoku::ValidBoxPlacement(const board& brd, const int row, const int col, const int num)
{
    coords boxCoords = FindBoxCoords(row, col);
    for(int r = boxCoords[0]; r < boxCoords[0] + boxSIZE; ++r)
    {
        for(int c = boxCoords[1]; c < boxCoords[1] + boxSIZE; ++c)
        {
            if(brd[r][c] == num) { return false; }
        }
    }
    return true;
}

bool _Sudoku::ValidPlacement(const board& brd, const int row, const int col, const int num)
{
    return 
    ValidRowPlacement(brd, row, num) &&
    ValidColPlacement(brd, col, num) &&
    ValidBoxPlacement(brd, row, col, num);
}


// --- recursive solve ---
bool _Sudoku::SolutionFound(board& brd)
{
    for(int row{0}; row < SIZE; ++row)
    {
        for(int col{0}; col < SIZE; ++col)
        {
            if(brd[row][col] == 0)
            {
                for(int guess = 1; guess <= SIZE; ++guess)
                {
                    if(ValidPlacement(brd, row, col, guess))
                    {
                        brd[row][col] = guess;
                        if(SolutionFound(brd)) { return true; }
                        else{ brd[row][col] = 0; }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void _Sudoku::Solve(board& brd)
{
    PrintBoard(brd);
    (SolutionFound(brd)) ? PrintBoard(brd) : FailureStatement();
}