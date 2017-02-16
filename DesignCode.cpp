
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

  string s = "24";
  cout << stoi(s)+1 << endl;

  string str ("\"comentario\"");

  if (str.find("//") != string::npos)
  {
    cout << str.find("//") << endl;
    cout << str.find("\"") << endl;
    str[str.find("\"")] = ' ';
    cout << str.find("\"") << endl;
    cout << str[0] << endl;
  }

  string sLine;
  ifstream InputFile ("testsintags.src");

  if (InputFile.is_open())
  {
    while(getline(InputFile, sLine))
    {
      cout << sLine << endl;
      while(getline(InputFile, sLine))
      {
        if(true)
        {
          cout << sLine << endl;
          break;
        }
      }
    }
    InputFile.close();
  }
  else
  {
    cout << endl << " no existe\n\n";
  }

  return 0;
}
