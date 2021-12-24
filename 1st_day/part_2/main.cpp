#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int comp_sums();
int len(int n);

int main()
{
  ifstream f1("input.txt");
  ofstream sumsFile("sums.txt");
  string line;
  int three_nums[3];
  int sum[2];
  int c_nums = 0, c_sums = 0;

  while( getline(f1, line) ){
    three_nums[c_nums] = stoi(line);
    c_nums++;

    if (c_nums == 3){
      sum[c_sums] = three_nums[0] + three_nums[1] + three_nums[2];
      sumsFile << sum[c_sums] << "\n";
      c_sums++;

      if (c_sums == 2) c_sums = 0;
      c_nums = 0;

      int sum_len = len(three_nums[1]) + len(three_nums[2]) + 2;
      f1.seekg(-sum_len, ios::cur);
    }

  }
  sumsFile.close();
  f1.close();
  cout << comp_sums() << endl;
  return 0;

}

int comp_sums()
{
  ifstream f1("sums.txt");
  string lines[2];
  int c = 0;

  while( getline(f1, lines[0]) && getline(f1, lines[1])){
    if (stoi(lines[1]) > stoi(lines[0])) c++;
    int len = lines[1].length()+1;
    f1.seekg(-len, ios::cur);
  }
  f1.close();
  return c;
}

int len(int n)
{
  int c = 0;
  while(n != 0){
    c++;
    n /= 10;
  }
  return c;
}
