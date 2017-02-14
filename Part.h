// Victor Elizalde
// A00817586
// Clase que guarda los atributos de una parte.
// Febrero 13 del 2017

using namespace std;

//&p-Part
//&b=6
class Part { //&m

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

void Part :: setName(string sName) //&m
{
  this -> sName = sName;
}

void Part :: setType(string sType) //&m
{
  this -> sType = sType; //&m
}

void Part :: setItems(int iItems) //&m
{
  this -> iItems = iItems; //&m
}

void Part :: setBase(int iBase)
{
  this -> iBase = iBase;
}

void Part :: setMod(int iMod)
{
  this -> iMod = iMod;
}

void Part :: setDel(int iDel)
{
  this -> iDel = iDel;
}

void Part :: setAdded(int iAdded)
{
  this -> iAdded = iAdded;
}

void Part :: setTotal(int iTotal)
{
  this -> iTotal = iTotal;
}

string Part :: getName() //&m
{
  return sName;
}

string Part :: getType() //&m
{
  return sType; //&m
}

int Part :: getItems()
{
  return iItems;
}

int Part :: getBase()
{
  return iBase;
}

int Part :: getMod()
{
  return iMod;
}

int Part :: getDel()
{
  return iDel;
}

int Part :: getAdded()
{
  return iAdded;
}

int Part :: getTotal()
{
  return iTotal;
}

//&d=2
