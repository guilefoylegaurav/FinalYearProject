#include <iostream>
#include <vector>
#include <fstream> 

using namespace std;
vector<pair<int, int>> generatePoints(int radius); 
int main() {
  int radius, x, y; 
  ofstream fout;
	fout.open("output.csv");
  cout << "Enter radius \n"; 
  cin >> radius; 
  vector<pair<int, int>> circle = generatePoints(radius); 
	for(auto p : circle) {
    x = p.first; 
    y = p.second; 
    fout << x << "," << y << endl; 
  }
	fout.close();
	return 0;
}
vector<pair<int, int>> generatePoints(int r) {
  
  int i = 0, j = r, s = 0, w = r-1, psum = 0, csum = 0, k = 0; 
  vector<int> previous(10000,0); 
  vector<pair<int, int>> circle; 
  int l = w << 2; 
  int count = 0; 
  while (j >= i) {
    do {
      circle.push_back(make_pair(i, j)); 
      count++; 
      s += i; 
      i++; 
      s += i; 
    } while (s <= w); 
    psum += previous[k]; 
    csum += count; 
    if (psum < csum) {
      i--; 
      j--; 
      circle.push_back(make_pair(i, j));
    }
    previous[k] = count; 
    k++; 
    w += l; 
    l -= 2; 
}
  return circle; 
  
}