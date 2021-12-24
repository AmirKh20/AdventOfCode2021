#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string lines;
  int c_f = 0, aim = 0, depth = 0;
  ifstream in_file("input.txt");

  while( getline(in_file, lines) ){
    if(lines[0] == 'f'){
      c_f += lines[8] - '0';
      depth += aim * (lines[8] - '0');
    }
    else if(lines[0] == 'd')
      aim += lines[5] - '0';
    else if(lines[0] == 'u')
      aim -= lines[3] - '0';
  }
  cout << c_f * depth << endl;
  in_file.close();

  return 0;

}
