// Victor Elizalde
// A00817586
// Clase que hacer todas las operaciones logicas para llegar al resultado.
// Febrero 1 del 2017

using namespace std;

//&p-Operation
//&b=5
class Operation {

  public:
		//&d=1
		void detectType(vector<Part> &vParts); //&m
		void printSummary(vector<Part> vParts, int iLDCTot); //%m
};

//&d=10

//&i
void Operation :: detectType(vector<Part> &vParts)
{
	for(int i = 0; i < vParts.size(); i++)
	{
		if (vParts[i].getDel() != 0)
		{
			vParts[i].setType("Base");
			vParts[i].setAdded(vParts[i].getTotal() - vParts[i].getBase() + vParts[i].getDel());
		}
		else if(vParts[i].getBase() != 0)
		{
			vParts[i].setType("Reused");
		}
		else
		{
			vParts[i].setType("New");
		}
	}
}


//&i
// Imprime la informacion general de todos los archivos juntos
void Operation :: printSummary(vector<Part> vParts, int iLDCTot)
{
	ofstream OutputFile;
	OutputFile.open ("Results.txt");

	cout << "PARTES BASE: " << endl;
	OutputFile << "PARTES BASE:" << endl;

	for(int i = 0;  i < vParts.size(); i++)
	{
		if(vParts[i].getType() == "Base")
		{
			cout << vParts[i].getName();
			cout << " T=" << vParts[i].getTotal(); //&m
			cout << ", I=" << vParts[i].getItems(); //&m
			cout << ", B=" << vParts[i].getBase(); //&m
			cout << ", D=" << vParts[i].getDel(); //&m
			cout << ", M=" << vParts[i].getMod();
			cout << ", A=" << vParts[i].getAdded() << endl;

			OutputFile << vParts[i].getName();
			OutputFile << " T=" << vParts[i].getTotal(); //&m
			OutputFile << ", I=" << vParts[i].getItems(); //&m
			OutputFile << ", B=" << vParts[i].getBase(); //&m
			OutputFile << ", D=" << vParts[i].getDel(); //&m
			OutputFile << ", M=" << vParts[i].getMod();
			OutputFile << ", A=" << vParts[i].getAdded() << endl;
		}
	}

	cout << "--------------------------------------------------" << endl;
	OutputFile << "--------------------------------------------------" << endl;

	cout << "PARTES NUEVAS: " << endl;
	OutputFile << "PARTES NUEVAS: " << endl;
	for(int i = 0;  i < vParts.size(); i++)
	{
		if(vParts[i].getType() == "New")
		{
			cout << vParts[i].getName();
			cout << " T=" << vParts[i].getTotal();
			cout << ", I=" << vParts[i].getItems() << endl;

			OutputFile << vParts[i].getName();
			OutputFile << " T=" << vParts[i].getTotal();
			OutputFile << ", I=" << vParts[i].getItems() << endl;
		}
	}

	cout << "--------------------------------------------------" << endl;
	OutputFile << "--------------------------------------------------" << endl;

	cout << "PARTES REUSADAS: " << endl;
	OutputFile << "PARTES REUSADAS: " << endl;

	for(int i = 0;  i < vParts.size(); i++)
	{
		if(vParts[i].getType() == "Reused")
		{
			cout << vParts[i].getName();
			cout << " T=" << vParts[i].getTotal();
			cout << ", I=" << vParts[i].getItems();
			cout << ", B=" << vParts[i].getBase() << endl;

			OutputFile << vParts[i].getName();
			OutputFile << " T=" << vParts[i].getTotal();
			OutputFile << ", I=" << vParts[i].getItems();
			OutputFile << ", B=" << vParts[i].getBase() << endl;
		}
	}

	cout << "--------------------------------------------------" << endl;
	OutputFile << "--------------------------------------------------" << endl;

	//&d=3
	cout << "Total de LDC=" << iLDCTot << endl; //&m
	OutputFile << "Total de LDC=" << iLDCTot << endl; //&m

	OutputFile.close();
}
