#include <iostream>
#include <fstream>
#include <filesystem>
#include <math.h>
using namespace std;
void copy_files(string src_file, string dst_file);
int bin2dec(string);

int main()
{
  int counts[2];
  for(int c = 0; c < 2; c++){
    copy_files("input.txt", "result.txt");
    for(int i = 0; i < 12; i++){
      fill(begin(counts), end(counts), 0);

      fstream res_file("result.txt", ios::in | ios::out);
      string lines;
      ofstream temp("temp.txt", ios::trunc);

      while( getline(res_file, lines) ) {
          if(lines[i] == '0')
            counts[0]++;
          else
            counts[1]++;
        }
      res_file.clear();
      res_file.seekg(0);

      if(counts[0] > counts[1]){
        while( getline(res_file, lines) ) {
          if(lines[i] == '0' && c == 0)
            temp << lines << endl;
          else if(lines[i] == '1' && c == 1){
            temp << lines << endl;
          }
        }
      }
      else{
        while( getline(res_file, lines) ) {
          if(lines[i] == '1' && c == 0)
            temp << lines << endl;
          else if(lines[i] == '0' && c == 1){
            temp << lines << endl;
          }
        }
      }
      temp.close();
      res_file.close();
      filesystem :: path tmp_path { "./temp.txt"};
      if(!filesystem::is_empty(tmp_path)){
        remove("result.txt");
        rename("temp.txt", "result.txt");
      }
    }
    if (c == 0)
      copy_files("result.txt", "oxygen.txt");
    else if (c == 1)
      copy_files("result.txt", "co2.txt");
  }
  remove("result.txt");
  remove("temp.txt");

  cout << bin2dec("oxygen.txt") * bin2dec("co2.txt") << endl;

  return 0;
}

void copy_files(string src_file, string dst_file){
  ifstream src(src_file, ios::binary);
  ofstream dst(dst_file, ios::binary | ios::trunc);

  dst << src.rdbuf();
}

int bin2dec(string filename){
  ifstream file(filename);
  string bin;
  getline(file, bin);
  file.close();

  int dec = 0;
  for(int i = 0, j = bin.length() - 1; j >= 0 ; j--, i++)
    dec += (bin[j] - '0') * pow(2, i);

  return dec;
}
