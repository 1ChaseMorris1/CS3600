#include <iostream>
#include <iomanip>
#include "knights_tour.h"
using namespace std;

KnightsTour::KnightsTour(int board_size) {
  this->board_size = board_size;

  this->board.resize(board_size);
  for (int i = 0; i < board_size; ++i) {
    this->board[i].resize(board_size);
  }
}

void KnightsTour::print() {
  for (int i = 0; i < this->board_size; i++) {
    for (int j = 0; j < this->board_size; j++)
      cout << setw(4) << this->board[i][j] << " ";
    cout << endl;
  }
  cout << endl << endl;
}

// Function: get_moves()
//    Desc: Get the row and column indices of all valid
//          knight moves reachable from position row, col.
//          An invalid move would be one that sends the
//          knight off the edge of the board or
//          to a position that has already been visited.
//          
//    int row         - Current row position of knight.
//    int col         - Current column position of knight.
//    int row_moves[] - Array to store row indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int col_moves[] - Array to store column indices
//                      of all valid new moves reachable from
//                      the current position row, col.
//    int num_moves -   Number of valid moves found. Corresponds
//                      to the sizes of row_moves and col_moves.

void KnightsTour::get_moves(
  int row, int col, 
  int row_moves[], int col_moves[], int& num_moves
) {

// goes through eight possible locations that the knight can move
  for(int i = 0; i < 8; i++){ 

    switch(i){ 
      case 0:
        col = col + 2; 
        --row;
      break;
      case 1:
        row = row + 2;
      break; 
      case 2:
        --col; 
        ++row;
      break;
      case 3: 
        col = col - 2;
      break; 
      case 4:
        --col;
        --row;
      break;
      case 5: 
        row = row - 2;
      break; 
      case 6:
        ++col;
        --row;
      break;
      case 7:
        col = col + 2;
      break;
    } 

// checks to make sure the move is not out of bounds and that the board location is 0. 
    if((row < board_size && row >= 0) && (col < board_size && col >= 0)) {
      if(board[row][col] == 0){ 
        col_moves[num_moves] = col; 
        row_moves[num_moves] = row;
        ++num_moves; 
      } 
    }
  }

}

// Function: move() --> Recursive
//     int row        - Current row position of knight.
//     int col        - Current column position of knight.
//     int& m         - Current move id in tour.
//                      Stored in board at position
//                      row, col.
//     int& num_tours - Total number of tours found.

void KnightsTour::move(int row, int col, int& m, int& num_tours) {

// saves the varaibles when passed in the move function. 
  int row_moves[8] = {}; 
  int col_moves[8] = {}; 
  int *num_moves = new int(0);

  ++m;
  board[row][col] = m; 

// if m = 25 print the board
  if(m == (board_size * board_size)){ 
    print();
    ++num_tours;  
  } else { 

    get_moves(row,col,row_moves,col_moves, *num_moves); 

// for every move found, move again. 
    for(int i = 0; i < *num_moves; i++){    
      move(row_moves[i],col_moves[i],m,num_tours);
    }

  } 
  
--m;
board[row][col] = 0;

}

int KnightsTour::generate(int row, int col) {
  int m = 0;
  int num_tours = 0;

  move(row, col, m, num_tours);

  return num_tours;
}
