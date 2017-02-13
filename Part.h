// Victor Elizalde
// A00817586
// Clase que guarda los atributos de un archivo.
// Febrero 1 del 2017

using namespace std;

class Part { //&m
//&b=

  public:

    Part();//&m
    Part(string sName);
    string getName(); //&m
    string getType(); //&m
    int getItems(); //&m
    int getBase();
    int getMod();
    int getDel();
    int getAdded();
    int getTotal();
    void setName(string sName); //&m
    void setType(string sType); //&m
    void setItems(int iItems); //&m
    void setBase(int iBase);
    void setMod(int iMod);
    void setDel(int iDel);
    void setAdded(int iAdded);
    void setTotal(int iTotal);
    //&d=1

  private:

    string sName; //&m
    string sType; //&m
    int iItems; //&m
    int iBase;
    int iMod;
    int iDel;
    int iAdded;
    int iTotal;

};

//&i
Part :: Part() //&m
{
  sName = "N/A";
  sType = "N/A";
  iItems = 0;
  iBase = 0;
  iMod = 0;
  iDel = 0;
  iAdded = 0;
  iTotal = 0;
}

//&i
Part :: Part(string sName)
{
  this -> sName = sName;
  sType = "N/A";
  iItems = 0;
  iBase = 0;
  iMod = 0;
  iDel = 0;
  iAdded = 0;
  iTotal = 0;
}

//&i
void Part :: setName(string sName) //&m
{
  this -> sName = sName;
}

//&i
void Part :: setType(string sType) //&m
{
  this -> sType = sType; //&m
}

//&i
void Part :: setItems(int iItems) //&m
{
  this -> iItems = iItems; //&m
}

//&i
void Part :: setBase(int iBase)
{
  this -> iBase = iBase;
}

//&i
void Part :: setMod(int iMod)
{
  this -> iMod = iMod;
}

//&i
void Part :: setDel(int iDel)
{
  this -> iDel = iDel;
}

//&i
void Part :: setAdded(int iAdded)
{
  this -> iAdded = iAdded;
}

//&i
void Part :: setTotal(int iTotal)
{
  this -> iTotal = iTotal;
}

//&i
string Part :: getName() //&m
{
  return sName;
}

//&i
string Part :: getType() //&m
{
  return sType; //&m
}

//&i
int Part :: getItems()
{
  return iItems;
}

//&i
int Part :: getBase()
{
  return iBase;
}

//&i
int Part :: getMod()
{
  return iMod;
}

//&i
int Part :: getDel()
{
  return iDel;
}

//&i
int Part :: getAdded()
{
  return iAdded;
}

//&i
int Part :: getTotal()
{
  return iTotal;
}

//&d=2
