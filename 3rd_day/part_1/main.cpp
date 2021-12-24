#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
using namespace std;
int bin2dec(string);

int main()
{
  int counts[2][12];
  fill(begin(counts[0]), end(counts[0]), 0);
  fill(begin(counts[1]), end(counts[1]), 0);

  ifstream in_file("input.txt");
  string lines;

  while( getline(in_file, lines) ) {
    for(int i = 0; i < 12; i++) {
      if(lines[i] == '0')
        counts[0][i]++;
      else
        counts[1][i]++;
    }
  }
  stringstream gama_ss;
  stringstream eps_ss;
  for(int i = 0; i < 12; i++){
    if (counts[0][i] > counts[1][i]){
      gama_ss << 0;
      eps_ss << 1;
    }
    else{
      gama_ss << 1;
      eps_ss << 0;
    }
  }
  cout << bin2dec(gama_ss.str()) * bin2dec(eps_ss.str()) << endl;
  in_file.close();
  return 0;
}

int bin2dec(string bin){
  int dec = 0;

  for(int i = 0, j = bin.length() - 1; j >= 0 ; j--, i++)
    dec += (bin[j] - '0') * pow(2, i);

  return dec;
}
