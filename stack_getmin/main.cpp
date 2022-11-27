#include <iostream>
#include <stack>
#include <utility>

using namespace std;

class min_stack {

  stack <pair<int, int>> st;

public:
  
  min_stack() {}; ~min_stack() {};

  bool empty() {return (st.empty());}

  int get_min() { return (st.empty()? -1 : st.top().second); };

  void pop() {st.pop();}

  void push(int i) {

    int curr_min = get_min();

    int min = (st.empty()) ? i : (i<curr_min? i : curr_min);

    pair <int, int> p (i, min);

    st.push(p); 

    return;
  };

  int top() {

    if (st.empty()) return -1;

    return st.top().first;

  }

};

int main(int argc, char **argv, char **envp)
{
  min_stack st;

  st.push(2);
  st.push(-22);
  st.push(0);
  st.push(9);

  cout << "Min = " << st.get_min() << endl;

  return (0);
}
