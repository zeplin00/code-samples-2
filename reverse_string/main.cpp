#include <iostream>
#include <string>

using namespace std;

void reverse_substr(string &s, int st, int end)
{

  // Bounds error checks
  //
  //
  
  for (;st<end;st++, end--) {
    char t = s[st];
    s[st] = s[end];
    s[end] = t;
  }

  return;

}

bool is_wordchar(char c)
{
  // Complete
  //
  if (c == ' ' || c == '\0') return false;
  return true;
}
  

void reverse_string(string &s)
{

  reverse_substr(s, 0, s.size()-1);    

  cout << "Intermediate: " << s << endl;

  // Reverse each word
  //
  int st=0, end=0;

  int len = s.size();

  while (st<len) {

    while (st<len && !is_wordchar(s[st]) ) st++;

    end=st+1;

    while (end<len && is_wordchar(s[end])) end++;

    if (end<=len) reverse_substr(s, st, end-1);

    st=end;

  }	  

  return;
}

int main(int argc, char **argv, char **envp)
{
  string s = "This is a test";

  cout << "Original: " << s << endl;

  reverse_string(s);

  cout << "Final: " << s << endl;

  return 0;
}
