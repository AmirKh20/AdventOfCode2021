#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
bool check(int mat_c, vector< vector< vector<int> > > game_board);

int main()
{
  ifstream in_file("input.txt");
  string str;
  vector <int> numbers;

  //Read the numbers from first line of the file into a vector
  while(getline(in_file, str, ',') && str[0] != '\n')
    numbers.push_back(stoi(str));

  //Finding the number of game boards in the file
  int mat_c = 0;
  in_file.seekg(0);
  while(getline(in_file, str)){
    if(str[0] == '\0')
      mat_c++;
  }

  in_file.clear();
  in_file.seekg(0);
  getline(in_file, str);

  vector< vector< vector<int> > > game_board(mat_c , vector< vector<int> > (5, vector<int> (5) ) );
  //Read the game boards from input file
  for(int m = 0; m < mat_c; m++){
    for(int row = 0; row < 5; row++){
      for(int col = 0; col < 5; col++){
        in_file >> game_board[m][row][col];
      }
    }
  }

  for(size_t i = 0; i < numbers.size(); i++){
    for(int m = 0; m < mat_c; m++){
      for(int row = 0; row < 5; row++){
        vector<int>::iterator it = find(game_board[m][row].begin(), game_board[m][row].end(), numbers[i]);
        if(it != game_board[m][row].end()){
          int col = distance(game_board[m][row].begin(), it);
          game_board[m][row][col] = 100;

          if(check(mat_c, game_board)){
            int sum = 0;
            for(int row = 0; row < 5; row++){
              for(int col = 0; col < 5; col++){
                if(game_board[m][row][col] != 100)
                  sum += game_board[m][row][col];
              }
            }
            cout << sum * numbers[i] << endl;
            exit(0);
          }

        }
      }
    }
  }

  return 0;
}

bool check(int mat_c, vector< vector< vector<int> > > game_board){
  int c2 = 0;
  for(int m = 0; m < mat_c; m++){
    for(int row = 0; row < 5; row++){
      int c = 0;
      for(int col = 0; col < 5; col++){
        if(game_board[m][row][col] == 100)
          c++;
      }
      if(c == 5){
        c2++;
        goto here;
      }
    }
    for(int col = 0; col < 5; col++){
      int c = 0;
      for(int row = 0; row < 5; row++){
        if(game_board[m][row][col] == 100)
          c++;
      }
      if(c == 5){
        c2++;
        break;
      }
    }
here:
    if(c2 == mat_c)
      return true;
  }
  return false;
}
