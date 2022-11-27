#include <iostream>
#include <memory>

using namespace std;

int main()
{
  int *p = new int[500];
  int *q = new int[500];

  unique_ptr<int[]> up {p};
  shared_ptr<int> sp {q};

  // Use sp
  //
  //
  //
  up[10] = 5;
   
  
  return 0;
}
