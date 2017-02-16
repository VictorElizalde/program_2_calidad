#include <iostream>
#include <fstream>
#include <vector>
#include <string>
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
  bool bPartFound = false;
	string sFileName, sLine, sAuxName;
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
            if(sLine.find("//&p-") != string::npos)
            {
              if(pPartAux.getName() == "N/A")
              {
                pPartAux.setName(sLine.substr(sLine.find("//&p-")+5,sLine.length()-sLine.find("//&p-")+4));
              }
              else
              {
                sAuxName = sLine.substr(sLine.find("//&p-")+5,sLine.length()-sLine.find("//&p-")+4);
                for(int i = 0; i < vParts.size(); i++)
                {
                  if(vParts[i].getName() == sAuxName)
                  {
                    vParts.push_back(pPartAux);
                    pPartAux.setName(sAuxName); //&m
                    pPartAux.setItems(vParts[i].getItems()); //&m
                    pPartAux.setBase(vParts[i].getBase()); //&m
                    pPartAux.setMod(vParts[i].getMod()); //&m
                    pPartAux.setDel(vParts[i].getDel());
                    pPartAux.setAdded(vParts[i].getAdded());
                    pPartAux.setTotal(vParts[i].getTotal());
                    vParts.erase(vParts.begin()+i);
                    bPartFound = true;
                  }
                }

                if(!bPartFound)
                {
                  vParts.push_back(pPartAux);
                  pPartAux.setName(sAuxName);
                  pPartAux.setItems(0);
                  pPartAux.setBase(0);
                  pPartAux.setMod(0);
                  pPartAux.setDel(0);
                  pPartAux.setAdded(0);
                  pPartAux.setTotal(0);
                  bPartFound = false;
                }
              }
            }
            else if(sLine.find("//&b=") != string::npos)
            {
              pPartAux.setBase(pPartAux.getBase() + stoi(sLine.substr(sLine.find("//&b=")+5, sLine.length()-sLine.find("//&b=")+4)));
            }
            else if(sLine.find("//&d=") != string::npos)
            {
              pPartAux.setDel(pPartAux.getDel() + stoi(sLine.substr(sLine.find("//&d=")+5, sLine.length()-sLine.find("//&d=")+4)));
            }
            else if(sLine.find("//&i") != string::npos)
            {
              pPartAux.setItems(pPartAux.getItems()+1);
            }
          }
          else if(sLine.find("//") != 0)
          {
            if(sLine.find("//&m") != string::npos)
            {
              if(sLine.find("//&m")+3 == sLine.length()-1)
              {
                pPartAux.setMod(pPartAux.getMod()+1);
              }
            }
          }
        }
        else if(sLine.find("//") != string::npos)
        {
          if(sLine.find("//") != 0)
          {
            if(pPartAux.getName() != "N/A")
            {
              pPartAux.setTotal(pPartAux.getTotal()+1);
            }
            iLDCTot++;
          }
        }
        else if(sLine.length() > 1)
        {
          if(pPartAux.getName() != "N/A")
          {
            pPartAux.setTotal(pPartAux.getTotal()+1);
          }
          iLDCTot++;
        }
        else
        {
          if(pPartAux.getName() != "N/A")
          {
            pPartAux.setTotal(pPartAux.getTotal()+1);
          }
          iLDCTot++;
        }
        //&d=1
      }
      InputFile.close();
    }
    else
    {
      cout << endl << sFileName << " no existe\n\n";
    }
  }


  vParts.push_back(pPartAux);

  for(int i = 0; i < vParts.size(); i++)
  {
    cout << "Parte: " << endl;
    cout << vParts[i].getName() << endl;
    cout << vParts[i].getType() << endl;
    cout << vParts[i].getItems() << endl;
    cout << vParts[i].getBase() << endl;
    cout << vParts[i].getDel() << endl;
    cout << vParts[i].getMod() << endl;
    cout << vParts[i].getAdded() << endl;
    cout << vParts[i].getTotal() << endl;
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
