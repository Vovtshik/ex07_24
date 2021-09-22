/*ex07_24.cpp*/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <iomanip>
using std::setw;

bool correctness_of_the_course(int[][8], int, int);
void show_board(int[][8], int, int);

int main()
{
   const int number_of_cells_vertically = 8;
   const int number_of_cells_horizontally = 8;
   const int maximum_number_of_moves = 64;
   
   int startcurrentRow = 7;
   int startcurrentColumn = 7;
   int currentRow = startcurrentRow;
   int currentColumn = startcurrentColumn;
   int moveNumber = 0;

   int board[number_of_cells_horizontally][number_of_cells_vertically] = {0};
   board[startcurrentRow][startcurrentColumn] = 65;

   int accessibility[number_of_cells_horizontally][number_of_cells_vertically] =
   {
    2, 3, 4, 4, 4, 4, 3, 2,
    3, 4, 6, 6, 6, 6, 4, 3,
    4, 6, 8, 8, 8, 8, 6, 4,
    4, 6, 8, 8, 8, 8, 6, 4,
    4, 6, 8, 8, 8, 8, 6, 4,
    4, 6, 8, 8, 8, 8, 6, 4,
    3, 4, 6, 6, 6, 6, 4, 3,
    2, 3, 4, 4, 4, 4, 3, 2
   };
   accessibility[currentRow][currentColumn]--;

   int gorizontal[] = {2, 1, -1, -2, -2, -1, 1, 2};
   int vertical[] = {-1, -2, -2, -1, 1, 2, 2, 1};

   int temp_sell;

   for(int i = 0; i < maximum_number_of_moves; i++)
   {
      temp_sell = 9;

      for(int j = 0; j < 7; j++)
      {
         if(correctness_of_the_course(board, currentRow + vertical[j], currentColumn + gorizontal[j]))
	     {
            if(accessibility[ currentRow + vertical[j] ][ currentColumn + gorizontal[j] ] >= temp_sell)
	           accessibility[ currentRow + vertical[j] ][ currentColumn + gorizontal[j] ]--;
            else
            {
                //temp_sell = accessibility[currentRow + vertical[j]][currentColumn + gorizontal[j]];
                temp_sell = j;
                accessibility[currentRow + vertical[j]][currentColumn + gorizontal[j]]--;
            }
	     }
      }

      if(temp_sell == 9)
      {
         show_board(board, startcurrentRow, startcurrentColumn);
	     cout << endl << "The chess knight made " << moveNumber << " moves\n";
	     return 0;
      }
      
      currentColumn += gorizontal[temp_sell];
      currentRow += vertical[temp_sell];
      board[currentRow][currentColumn] = i + 1;
      moveNumber++;
   }

   show_board(board, startcurrentRow, startcurrentColumn);
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

void show_board(int B[][8], int sCR, int SCC)
{
    cout << "\n      0   1   2   3   4   5   6   7   \n" ;
    cout << "                                   \n";
   for(int i = 0; i < 8; i++)
   {
       cout << "    |---|---|---|---|---|---|---|---|\n";
       cout << i << "   |";
       for (int j = 0; j < 8; j++)
       {
           if (i == sCR && j == SCC)
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
