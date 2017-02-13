
#include<iostream>
using namespace std;

int main()
{
  string str ("\"comen//tario\"");

  if (str.find("//") != string::npos)
  {
    cout << str.find("//") << endl;
    cout << str.find("\"") << endl;
    str[str.find("\"")] = ' ';
    cout << str.find("\"") << endl;
    // cout << str[0] << endl;
  }

  return 0;
}
