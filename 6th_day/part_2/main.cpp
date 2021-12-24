#include <iostream>
#include <map>
#include <vector>
#include <algorithm> //count
using namespace std;

int main(){
  vector<int> lanternfishs{1,1,1,1,3,1,4,1,4,1,1,2,5,2,5,1,1,1,4,3,1,4,1,1,1,1,1,1,1,2,1,2,4,1,1,1,1,1,1,1,3,1,1,5,1,1,2,1,5,1,1,1,1,1,1,1,1,4,3,1,1,1,2,1,1,5,2,1,1,1,1,4,5,1,1,2,4,1,1,1,5,1,1,1,1,5,1,3,1,1,4,2,1,5,1,2,1,1,1,1,1,3,3,1,5,1,1,1,1,3,1,1,1,4,1,1,1,4,1,4,3,1,1,1,4,1,2,1,1,1,2,1,1,1,1,5,1,1,3,5,1,1,5,2,1,1,1,1,1,4,4,1,1,2,1,1,1,4,1,1,1,1,5,3,1,1,1,5,1,1,1,4,1,4,1,1,1,5,1,1,3,2,2,1,1,1,4,1,3,1,1,1,2,1,3,1,1,1,1,4,1,1,1,1,2,1,4,1,1,1,1,1,4,1,1,2,4,2,1,2,3,1,3,1,1,2,1,1,1,3,1,1,3,1,1,4,1,3,1,1,2,1,1,1,4,1,1,3,1,1,5,1,1,3,1,1,1,1,5,1,1,1,1,1,2,3,4,1,1,1,1,1,2,1,1,1,1,1,1,1,3,2,2,1,3,5,1,1,4,4,1,3,4,1,2,4,1,1,3,1};
  map<int, unsigned long long int> X, Y;

  for(int n = 0; n <= 8; n++){
    int c = count(lanternfishs.begin(), lanternfishs.end(), n);
    X.insert(pair<int, unsigned long long int>(n, c));
    Y.insert(pair<int, unsigned long long int>(n, 0));
  }

  for(int day = 0; day < 256; day++){
    for(auto it : X){
      if(it.second != 0){
        if (it.first == 0){
          Y[6] += it.second;
          Y[8] += it.second;
        }
        else
          Y[it.first - 1] += it.second;
      }
    }
    X = Y;
    for(int n = 0; n <= 8; n++)
      Y[n] = 0;
  }

  unsigned long long int sum = 0;
  for(auto i : X)
    sum += i.second;
  cout << sum << endl;

  return 0;
}
