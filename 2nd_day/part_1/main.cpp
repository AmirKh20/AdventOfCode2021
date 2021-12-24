#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  string lines;
  int c_f = 0, c_d = 0, c_u = 0;
  ifstream in_file("input.txt");

  while( getline(in_file, lines) ){
    if(lines[0] == 'f')
      c_f += lines[8] - '0';
    else if(lines[0] == 'd')
      c_d += lines[5] - '0';
    else if(lines[0] == 'u')
      c_u += lines[3] - '0';
  }
  cout << c_f * (c_d - c_u) << endl;
  in_file.close();

  return 0;

}
