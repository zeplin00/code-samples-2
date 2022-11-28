#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Dummy comment
//

// Another dummy comment
//

int main()
{

  vector<int> v = {2, 3, 4, 5 ,6 ,7, 2, 3,4, 5, 1, 1, 1, 1, 1,1, 1};		

  map<int, int> hist;

  for (auto &x : v) { hist[x]++; }

  for (auto &x : hist) { cout << "freq of " << x.first << " = " << x.second << endl; }

  return 0;
}
