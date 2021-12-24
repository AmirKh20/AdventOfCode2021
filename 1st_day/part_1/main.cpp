/* Count the number of increased depths from file input.txt */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
  ifstream f1("input.txt");
  string lines[2];
  int c = 0;

  while( getline(f1, lines[0]) && getline(f1, lines[1])){
    if (stoi(lines[1]) > stoi(lines[0])) c++;
    int len = lines[1].length()+1;
    f1.seekg(-len, ios::cur);
  }
  cout << c << endl;
  f1.close();
  return 0;
}
