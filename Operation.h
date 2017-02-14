// Victor Elizalde
// A00817586
// Clase que hacer todas las operaciones logicas para llegar al resultado.
// Febrero 1 del 2017

using namespace std;

class Operation {

  public:
		//&d=1
		void printPart(Part &pPart); //&m
		void printSummary(int iNumArchivos, int iLineasBlanco, int iLineasNegro); //%m
};

//&d=10

// Imprime la informacion general de todos los archivos juntos
void Operation :: printSummary(vector<Part> vParts, int iLDCTot)
{
	cout << "PARTES BASE: " << endl;
	for(int i = 0;  i < vParts.size(); i++)
	{
		if(vParts[i].getType() == "Base")
		{
			cout << vParts[i].getName();
			cout << " T=" << vParts[i].getTotal();
			cout << ", I=" << vParts[i].getItems();
			cout << ", B=" << vParts[i].getBase();
			cout << ", D=" << vParts[i].getDel();
			cout << ", M=" << vParts[i].getMod();
			cout << ", A=" << vParts[i].getAdded() << endl;
		}
		myvector.erase(myvector.begin()+i);
	}

	cout << "--------------------------------------------------" << endl;

	cout << "PARTES NUEVAS: " << endl;
	for(int i = 0;  i < vParts.size(); i++)
	{
		if(vParts[i].getType() == "New")
		{
			cout << vParts[i].getName();
			cout << " T=" << vParts[i].getTotal();
			cout << ", I=" << vParts[i].getItems() << endl;
		}
		myvector.erase(myvector.begin()+i);
	}

	cout << "--------------------------------------------------" << endl;

	cout << "PARTES REUSADAS: " << endl;
	for(int i = 0;  i < vParts.size(); i++)
	{
		if(vParts[i].getType() == "Reused")
		{
			cout << vParts[i].getName();
			cout << " T=" << vParts[i].getTotal();
			cout << ", I=" << vParts[i].getItems();
			cout << ", B=" << vParts[i].getBase() << endl;
		}
		myvector.erase(myvector.begin()+i);
	}

	cout << "--------------------------------------------------" << endl;

	//&d=3
	cout << "Total de LDC=" << iLDCTot << endl; //&m
}
