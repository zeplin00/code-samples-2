#include <iostream>
#include <forward_list>

using namespace std;

ostream& operator<< (ostream& os, const forward_list<int>& l)
{
  os << "Printing list: " ;

  for(auto &x : l) {
    os << x << " ";
  }

  os << endl;
}

forward_list<int> reverseList(forward_list<int> inp)
{
  forward_list<int> ret;

  for (auto &x : inp) {
    ret.push_front(x); 
  }

  return ret; 
}


int main (int argc, char **argv, char **envp)
{
  forward_list<int> inp = {1, 3, 4, 6, 7, 8};

  // Print inp
  cout << inp << endl;

  forward_list<int> ret = reverseList(inp);

  // Print ret
  cout << ret << endl;

  return(0);
}
