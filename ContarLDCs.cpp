#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#include "Part.h" //&m
#include "Operation.h"

//&d=4

//&i
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

//&p-main
//&b=44
// Control general del programa para obetener los datos y el resultado
int main () {

  int iNumberFiles, iNumArchivos = 0, iLDCTot = 0; //&m
	string sFileName, sLine;
  Operation oOperation;
  Part pPartAux; //&m
  vector<Part> vParts; //&m

	cout << "Cuantos archivos vas a analizar?\n";
	cin >> iNumberFiles;
	cout << "Dame el nombre de los archivos\n";


  for(int i = 0; i < iNumberFiles; i++)
  {
    cin >> sFileName;
    ifstream InputFile (sFileName);
    //&d=1

    if (InputFile.is_open())
    {
      while(getline(InputFile, sLine))
      {
        sLine = DeleteSpaces(sLine);

        if(sLine.find("/*") != string::npos)
        {
           if(!(sLine.find("*/") != string::npos))
           {
             while(getline(InputFile, sLine))
             {
               sLine = DeleteSpaces(sLine);
               if(sLine.find("*/") != string::npos)
               {
                 break;
               }
             }
           }
        }
        else if(sLine.find("//&") != string::npos)
        {
          if(sLine.find("//&") == 0)
          {
            //hacer accion correspondiente
          }
          else if(sLine.find("//") != 0)
          {
            //checa comillas
            //hacer accion correspondiente
          }
        }
        else if(sLine.find("//") != string::npos)
        {
          if(sLine.find("//") != 0)
          {
            iLDCTot++;
          }
        }
        else if(!(sLine.length() == 1))
        {
          iLDCTot++;
        }
        else
        {
          iLDCTot++;
        }
        //&d=1
      }
      vParts.push_back(pPartAux); //&m
      pPartAux.setName("N/A"); //&m
      pPartAux.setType("N/A"); //&m
      pPartAux.setItems(0); //&m
      pPartAux.setBase(0);
      pPartAux.setMod(0);
      pPartAux.setDel(0);
      pPartAux.setAdded(0);
      pPartAux.setTotal(0);
      pPartAux.set(0);
      InputFile.close();
    }
    else
    {
      cout << endl << sFileName << " no existe\n\n";
    }
  }


  // sort(vMyfiles.begin(), vMyfiles.end(), NumLines());
  //
  // iNumArchivos = vMyfiles.size();
  // for (int i = 0; i < vMyfiles.size(); i++)
  // {
  //   iLineasBlanco += vMyfiles[i].getLineasBlanco();
  //   iLineasNegro += vMyfiles[i].getLineasNegro();
  //   oOperation.printFiles(vMyfiles[i]);
  // }
  //
  // oOperation.printSummary(iNumArchivos, iLineasBlanco, iLineasNegro);
  return 0;
}
