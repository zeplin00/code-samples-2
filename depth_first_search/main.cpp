#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <utility>

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
  vector <bool> completed(size, false);

  stack<pair<int, int>> s;

  pair<int, int> p(0, 0);

  s.push(p);

  int f = 0;

  while (!s.empty()) {

    int vtx = s.top().first;
    int lvl = s.top().second;

    if (visited[vtx]) {

      completed[vtx] = true;

      cout << "Done exploring vtx = " << vtx << " at level = " << f++ << endl;

      s.pop();

    } else {

      visited[vtx] = true;
      cout << "Exploring vtx = " << vtx << endl;
  
      for(auto &x : adj_list[vtx]) {
        if (!visited[x]) {
	  pair<int, int> p(x, lvl+1);
          s.push(p);
  	  cout << "Found forward-edge to vtx = " << x << " From vtx = " << vtx << endl;
  
        } else if (completed[x]) {
          // Must be a cross edge
  	  //
  	  cout << "Found cross-edge to vtx = " << x << " From vtx = " << vtx << endl;
  
        } else {
          // Must be a cycle 
  	  //
  	  cout << "Found cycle to vtx = " << x << " From vtx = " << vtx << endl;
  	
        }
      } 

    }

  }
     
 
  return(0);
}
