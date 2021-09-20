/*ex07_24.cpp*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

bool correctness_of_the_course(int[][8], int, int);
void show_board(int[][8]);

int main()
{
   const int number_of_cells_vertically = 8;
   const int number_of_cells_horizontally = 8;
   const int maximum_number_of_moves = 64;
   
   int currentRow = 3;
   int currentColumn = 4;
   int moveNumber = 0;

   int board[number_of_cells_horizontally][number_of_cells_vertically] = {0};
   board[3][4] = 65;
   int gorizontal[] = {2, 1, -1, -2, -2, -1, 1, 2};
   int vertical[] = {-1, -2, -2, -1, 1, 2, 2, 1};

   for(int i = 0; i < maximum_number_of_moves; i++)
   {
      for(int j = 0; j < 7; j++)
      {
         if(correctness_of_the_course(board, currentRow + vertical[j], currentColumn + gorizontal[j]))
         { 
            currentColumn += gorizontal[j];
            currentRow += vertical[j];
     	    board[currentRow][currentColumn] = i + 1;
    	    moveNumber++;
            break;
         }
         if (j == 6)
         {
             show_board(board);
             cout << endl << "The chess knight made " << moveNumber << " moves\n";
             return 0;
         }
      }
   }

   show_board(board);
   cout << endl << "About a miracle! The chess knight has bypassed all " << moveNumber << " squares of the board! \n";

   return 0;
}

bool correctness_of_the_course(int B[][8], int current_R, int current_C)
{
   if(!B[current_R][current_C] && current_R >= 0 && current_R <= 7 && current_C >= 0 && current_C <= 7)
      return true;
   else
      return false;
}

void show_board(int B[][8])
{
    cout << "\n      0   1   2   3   4   5   6   7   \n" ;
    cout << "                                   \n";
   for(int i = 0; i < 8; i++)
   {
       cout << "    |---|---|---|---|---|---|---|---|\n";
       cout << i << "   |";
       for (int j = 0; j < 8; j++)
       {
           if (i == 3 && j == 4)
               cout << " k " << "|";
           else if (B[i][j] == 0)
               cout << "   |";
           else    
               cout << setw(3) << B[i][j] << "|";
       }
       cout << endl;
   }
   cout << "    |---|---|---|---|---|---|---|---|\n";
}
