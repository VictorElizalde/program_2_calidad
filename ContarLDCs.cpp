#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "File.h"
#include "Operation.h"

// Struct para poder ordenar el vector de acuerdo al atributo getLineasNegro
// Los parametros son los 2 files a comparar
struct NumLines{
    inline bool operator() (File &fFile1, File &fFile2) {
        return (fFile1.getLineasNegro() < fFile2.getLineasNegro());
    }
};

// Funcion que elimina todos los espacios en blanco de una linea
// Recibe de parametro la linea a limpiar
string DeleteSpaces(string sLine)
{
  string sAux = "";

  for(int i = 0; i < sLine.length(); i++)
  {
    if(sLine[i] != ' ' && sLine[i] != '\t' && sLine[i] != '\r' && sLine[i] != '\v')
    {
      sAux += sLine[i];
    }
  }

  return sAux;
}

// Control general del programa para obetener los datos y el resultado
int main () {

  int iNumberFiles, iNumArchivos = 0, iLineasBlanco = 0, iLineasNegro = 0;
	string sFileName, sLine;
  Operation oOperation;
  File fFileAux;
  vector<File> vMyfiles;

	cout << "Cuantos archivos vas a analizar?\n";
	cin >> iNumberFiles;
	cout << "Dame el nombre de los archivos\n";


  for(int i = 0; i < iNumberFiles; i++)
  {
    cin >> sFileName;
    ifstream InputFile (sFileName);
    fFileAux.setName(sFileName);

    if (InputFile.is_open())
    {
      while(getline(InputFile, sLine))
      {
        sLine = DeleteSpaces(sLine);
        oOperation.countLines(fFileAux, sLine);
      }
      vMyfiles.push_back(fFileAux);
      fFileAux.setName("N/A");
      fFileAux.setLineasBlanco(0);
      fFileAux.setLineasNegro(0);
      InputFile.close();
    }
    else
    {
      cout << endl << sFileName << " no existe\n\n";
    }
  }


  sort(vMyfiles.begin(), vMyfiles.end(), NumLines());

  iNumArchivos = vMyfiles.size();
  for (int i = 0; i < vMyfiles.size(); i++)
  {
    iLineasBlanco += vMyfiles[i].getLineasBlanco();
    iLineasNegro += vMyfiles[i].getLineasNegro();
    oOperation.printFiles(vMyfiles[i]);
  }

  oOperation.printSummary(iNumArchivos, iLineasBlanco, iLineasNegro);
  return 0;
}
