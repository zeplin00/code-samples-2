#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

int main()
{

  int size = 100;

  vector<list<int>> adj_list(size);

  adj_list = {
   {1, 3 },
   {2, 3},	  
   {3},
   {0, 3}
  };

  vector <bool> visited(size, false);

  queue<tuple<int, int, int>> q;

  tuple<int, int, int> t(0, 0, 0);

  q.push(t);

  visited[0] = true;

  while (!q.empty()) {

    int vtx = get<0> (q.front());
    int dist = get<1> (q.front());

    cout << "Popping vtx = " << vtx << " at dist = " << dist << endl;

    q.pop();
  
    for(auto &x : adj_list[vtx]) {
      if (!visited[x]) {
        tuple<int, int, int> t(x, dist+1, vtx);
        q.push(t);
	cout << "Visiting vtx = " << x << endl;
	visited[x] = true;
      }
    } 

  }
     
 
  return(0);
}
