#include <iostream>
#include <fstream>
#include <vector>
#include <regex>
using namespace std;

int main()
{
  ifstream in_file("input.txt");
  string line;
  ofstream temp("temp.txt", ios::trunc);

  int num_line = 0;
  while(getline(in_file, line)){
    num_line++;
    line = std::regex_replace(line, std::regex(","), " ");
    line = std::regex_replace(line, std::regex("->"), "");
    temp << line << endl;
  }
  temp.close();
  in_file.close();
  remove("input.txt");
  rename("temp.txt","input.txt");

  in_file.open("input.txt");
  vector<vector<int>> numbers(num_line, vector<int>(4));
  for(int row = 0; row < num_line; row++){
    for(int col = 0; col < 4; col++)
      in_file >> numbers[row][col];
  }
  in_file.close();

  for(size_t row = 0; row < numbers.size(); row++){
    if (numbers[row][0] > numbers[row][2])
      std::swap(numbers[row][0], numbers[row][2]);
    if (numbers[row][1] > numbers[row][3])
      std::swap(numbers[row][1], numbers[row][3]);
    if (numbers[row][0] != numbers[row][2] && numbers[row][1] != numbers[row][3]){
      numbers.erase(numbers.begin() + row);
      row--;
    }
  }

  int x1,y1,x2,y2;
  vector<vector<int>> counts(1000, vector<int>(1000,0));
  for(size_t line = 0; line < numbers.size(); line++){
    x1 = numbers[line][0]; y1 = numbers[line][1]; x2 = numbers[line][2]; y2 = numbers[line][3];
    if(y1 == y2){
      while(x1 <= x2){
        counts[x1][y1]++;
        x1++;
      }
    }
    else if(x1 == x2){
      while(y1 <= y2){
        counts[x1][y1]++;
        y1++;
      }
    }
  }
  int sum = 0;
  for(size_t row = 0; row < 1000; row++){
    for(int col = 0; col < 1000; col++)
      if (counts[row][col] >= 2) sum += 1;
  }
  cout << sum << endl;

  return 0;
}
