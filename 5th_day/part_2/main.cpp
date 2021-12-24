#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <boost/algorithm/string.hpp>
using namespace std;
#define pair pair<int, int>

bool is_pairs_sorted(pair p1 , pair p2)
{
  if(p1.first < p2.first)
    return true;
  else if(p1.first == p2.first){
    if(p1.second <= p2.second)
      return true;
  }
  return false;
}

bool is_not_unique(pair p1, pair p2)
{
  return (p1.first == p2.first && p1.second == p2.second);
}

void expand(vector<pair> &Coordiantes)
{
  if(Coordiantes[0].first == Coordiantes[1].first)
  {
    if(Coordiantes[0].second+1 < Coordiantes[1].second){
      auto it = Coordiantes.begin();
      for(auto i = 0; Coordiantes[i].second+1 < Coordiantes[Coordiantes.size()-1].second; i++)
        it = Coordiantes.insert(++it, {Coordiantes[i].first, Coordiantes[i].second+1});
    }
  }
  else if(Coordiantes[0].second == Coordiantes[1].second)
  {
    if(Coordiantes[0].first+1 < Coordiantes[1].first){
      auto it = Coordiantes.begin();
      for(auto i = 0; Coordiantes[i].first+1 < Coordiantes[Coordiantes.size()-1].first; i++)
        it = Coordiantes.insert(++it, {Coordiantes[i].first+1, Coordiantes[i].second});
    }
  }
  else
  {
    if(Coordiantes[0].second > Coordiantes[1].second){
      auto it = Coordiantes.begin();
      for(auto i = 0; (Coordiantes[i].first+1 < Coordiantes[Coordiantes.size()-1].first)
          && (Coordiantes[i].second -1 > Coordiantes[Coordiantes.size()-1].second); i++){
        it = Coordiantes.insert(++it, {Coordiantes[i].first+1, Coordiantes[i].second -1});
      }
    }
    else{
      auto it = Coordiantes.begin();
      for(auto i = 0; (Coordiantes[i].first+1 < Coordiantes[Coordiantes.size()-1].first)
          && (Coordiantes[i].second+1 < Coordiantes[Coordiantes.size()-1].second); i++){
        it = Coordiantes.insert(++it, {Coordiantes[i].first+1, Coordiantes[i].second+1});
      }
    }
  }

}

void SplitCoordinatesFindNumberOfLines(int &num_line)
{
  ifstream in_file("input.txt");
  string line;
  ofstream temp("temp.txt", ios::trunc);

  while(getline(in_file, line)){
    num_line++;
    boost::replace_all(line, ",", " ");
    boost::replace_all(line, "->", "");

    temp << line << endl;
  }
  temp.close();
  in_file.close();
  remove("input.txt");
  rename("temp.txt","input.txt");
}

void ReadSortExpand(vector<vector<pair>> &numbers, int num_line)
{
  ifstream in_file("input.txt");
  for(auto row = 0; row < num_line; row++){
    for(auto p = 0; p < 2; p++){
      in_file >> numbers[row][p].first;
      in_file >> numbers[row][p].second;
    }
    sort(numbers[row].begin(), numbers[row].end(), is_pairs_sorted);
    expand(numbers[row]);
  }
}
int main()
{
  int num_line = 0;
  SplitCoordinatesFindNumberOfLines(num_line);

  vector<vector<pair>>numbers(num_line, vector<pair>(2));
  ReadSortExpand(numbers, num_line);

  vector<pair>::iterator ls;
  vector<pair>inters_v(26000);
  ls = inters_v.begin();
  for(auto row = 0; row < num_line -1; row++){
    for(auto next_row = row+1; next_row < num_line; next_row++){
      ls = set_intersection(numbers[row].begin(), numbers[row].end(),
                            numbers[next_row].begin(), numbers[next_row].end(), ls);
    }
  }
  inters_v.resize(ls - inters_v.begin());
  inters_v.shrink_to_fit();
  sort(inters_v.begin(), inters_v.end(), is_pairs_sorted);
  auto last = unique(inters_v.begin(), inters_v.end(), is_not_unique);
  inters_v.erase(last, inters_v.end());
  cout << inters_v.size() << endl;

  return 0;
}
