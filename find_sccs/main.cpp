#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <utility>

using namespace std;

list<int> dfs(vector<list<int>> &adj_list, int st, vector<bool> &visited, vector<bool> &completed)
{
  list<int> finish;	

  stack<pair<int, int>> s;

  pair<int, int> p(st, 0);

  if (completed[st]) return finish;

  s.push(p);

  int f = 0;

  while (!s.empty()) {

    int vtx = s.top().first;

    int lvl = s.top().second;

    if (visited[vtx]) {

      completed[vtx] = true;

      cout << "Done exploring vtx = " << vtx << " at finish = " << f++ << endl;

      finish.push_front(vtx);

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
     
 
  return (finish);
}

vector<list<int>> reverse_graph(vector<list<int>> adj_list, int size)
{
  vector<list<int>> ret (size);

  int vtx = 0;

  for (auto &x : adj_list) {
    for (auto &y : x) {
      ret[y].push_front(vtx);  
      cout << "Adding " << y << " -> " << vtx << endl;
    }
    vtx++;
  }

  return ret;
}


int main()
{
  int size = 100;

  vector<list<int>> adj_list(size);
  
  adj_list = {
     {1, 3 },
     {2, 3},	  
     {3},
     {3, 1}
  };

  vector <bool> visited(size, false);

  vector <bool> completed(size, false);

  list<int> finish = dfs(adj_list, 0, visited, completed);

  vector<list<int>> radj_list = reverse_graph(adj_list, size);

  vector <bool> rvisited(size, false);

  vector <bool> rcompleted(size, false);

  for (auto &x : finish) {

    if (rcompleted[x]) continue;

    // DFS from x
    //
    cout << endl << "Finding SCC: " << endl;

    list<int> scc = dfs(radj_list, x, rvisited, rcompleted);

    cout << "Found SCC " << endl;
  }

  return(0);
}




