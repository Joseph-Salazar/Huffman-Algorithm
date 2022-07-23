#include <iostream>
#include <conio.h>
#include <string>
#include <vector>

using namespace std;

struct conteo {
	int freq;
	char letra;
	conteo()
	{
		
	}
};

struct NodoArbol {
	conteo dato;
	int id;
	NodoArbol *left;
	NodoArbol *right;

	NodoArbol(conteo dato)
	{
		this->dato.freq = dato.freq;
		this->dato.letra = dato.letra;
		left = nullptr;
		right = nullptr;
	}
	NodoArbol()
	{

	}

};

struct Arbol {
	NodoArbol *raiz;
	Arbol(conteo dato)
	{
		raiz = new NodoArbol(dato);
		raiz->left = new NodoArbol(dato);
		raiz->right = new NodoArbol(dato);
	}

	Arbol()
	{
		raiz = new NodoArbol();
		raiz->left = new NodoArbol();
		raiz->right = new NodoArbol();
	}

	void superPrint(NodoArbol*);
	void superPrint();
	void MostrarArbol(NodoArbol*, int);
	void MostrarArbol();
	void deleteleafs();
	NodoArbol *deleteleafs(NodoArbol*);
	void printHojas(NodoArbol*);
	void printHojas();
	void Decodificarr(string, int);
	void paths(NodoArbol*, int[], int);
	void printPaths(NodoArbol*);
	void printPaths()
	{
		printPaths(raiz);
	}
	void Decodificar(NodoArbol*, string, int);
	void Decodificar(string);

	bool isLeaf(NodoArbol*nodo)
	{
		if (nodo->left == nullptr && nodo->right == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

string codigoHuffman = "";

void Arbol::Decodificar(NodoArbol* root, string codigo, int i)
{
	for (int j = 0; j < codigo.length(); j++)
	{
		while (!isLeaf(root))
		{
			if (codigo[i] == '0')
			{
				root = root->left;
				if (!root->left && !root->right)
				{
					cout << root->dato.letra;
				}
				i++;
			}
			else if (codigo[i] == '1')
			{
				root = root->right;
				if (!root->left && !root->right)
				{
					cout << root->dato.letra;
				}
				i++;
			}
		}
		root = raiz;
	}
}

void Arbol::Decodificarr(string cadena, int i)
{
	for (int i = 0; i < cadena.length(); i++)
	{
		cout << cadena[i];
	}
}

void Arbol::Decodificar(string someString)
{
	Decodificar(raiz, someString, 0);
}

void printArray(int camino[], int lon)
{
	for (int i = 1; i < lon; i++)
	{
		cout << camino[i] << " ";
		if (camino[i] == 1)
		{
			codigoHuffman += "1";
		}
		if (camino[i] == 0)
		{
			codigoHuffman += "0";
		}
	}
	cout << endl;
}

void Arbol::paths(NodoArbol* node, int camino[], int longitud)
{
	if (node == nullptr)
	{
		return;
	}
	camino[longitud] = node->id;
	longitud++;

	if (node->left == nullptr && node->right == nullptr)
	{
		printArray(camino, longitud);
	}
	else
	{
		paths(node->left, camino, longitud);
		paths(node->right, camino, longitud);
	}
}

void Arbol::printPaths(NodoArbol* node)
{
	int path[1000];
	paths(node, path, 0);
}

void Arbol::printHojas()
{
	printHojas(raiz);
}

void Arbol::printHojas(NodoArbol*root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		if (!root->left && !root->right)
		{
			cout << root->dato.letra << ", ";
			return;
		}

		if (root->left != nullptr)
		{
			cout << "0";
			printHojas(root->left);
		}
		if (root->right != nullptr)
		{
			cout << "1";
			printHojas(root->right);
		}
	}
}

void Arbol::deleteleafs()
{
	deleteleafs(raiz);
}

NodoArbol *Arbol::deleteleafs(NodoArbol* root)
{
	if (root == nullptr)
		return nullptr;
	if (root->left == nullptr && root->right == nullptr) {
		delete root;
		return nullptr;
	}
	root->left = deleteleafs(root->left);
	root->right = deleteleafs(root->right);
	return root;
}

void Arbol::MostrarArbol()
{
	MostrarArbol(raiz, 0);
}

void Arbol::MostrarArbol(NodoArbol*root, int cont)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		MostrarArbol(root->right, cont + 1);
		for (int i = 0; i < cont; i++)
		{
			cout << "  ";
		}
		cout << root->dato.letra<< endl;
		MostrarArbol(root->left, cont + 1);
	}
}

void Arbol::superPrint()
{
	superPrint(raiz);
}

void Arbol::superPrint(NodoArbol *root)
{
	if (root == nullptr)
	{
		return;
	}

	if (root->left != nullptr)
	{
		cout << "0";
		superPrint(root->left);
	}
	if (root->right != nullptr)
	{
		cout << "1";
		superPrint(root->right);
	}

	if ((root->left == nullptr) && (root->right == nullptr))
	{
		return;
	}
}

void Huffman(vector<Arbol*> *root, int i)
{
	if (root->size()==1)
	{
		return;
	}
	else
	{
		Arbol *nuevo = new Arbol();

		nuevo->raiz->id = -1;
		nuevo->raiz->dato.freq = root->at(i)->raiz->dato.freq+root->at(i+1)->raiz->dato.freq;
		nuevo->raiz->dato.letra = '-';
		
		root->at(0)->raiz->id = 0;
		root->at(1)->raiz->id = 1;
		nuevo->raiz->left = root->at(0)->raiz;
		nuevo->raiz->right = root->at(1)->raiz;

		root->push_back(nuevo);

		root->erase(root->begin()+0); root->erase(root->begin() + 0);
		Huffman(root, 0);
	}
}

using namespace System;

int main()
{
	conteo arr[27];
	string cadena = "algoritmo";
	string secondstring = cadena;
	conteo aux;
	string sin_ocurrencias = "";

	vector<Arbol*>*vec = new vector<Arbol*>();

	int below_zero = 0;
	int size = 0;
	int j = 0;

	for (int i = 0; i < 27; i++)
	{
		arr[i].freq = 0; //inicializar en 0
	}

	for (int i = 0; i < cadena.length(); i++)
	{
		switch (cadena[i])
		{
		case 'a':
			arr[0].freq++;
			arr[0].letra = 'a';
			break;
		case 'b':
			arr[1].freq++;
			arr[1].letra = 'b';
			break;
		case 'c':
			arr[2].freq++;
			arr[2].letra = 'c';
			break;
		case 'd':
			arr[3].freq++;
			arr[3].letra = 'd';
			break;
		case 'e':
			arr[4].freq++;
			arr[4].letra = 'e';
			break;
		case 'f':
			arr[5].freq++;
			arr[5].letra = 'f';
			break;
		case 'g':
			arr[6].letra = 'g';
			arr[6].freq++;
			break;
		case 'h':
			arr[7].freq++;
			arr[7].letra = 'h';
			break;
		case 'i':
			arr[8].freq++;
			arr[8].letra = 'i';
			break;
		case 'j':
			arr[9].freq++;
			arr[9].letra = 'j';
			break;
		case 'k':
			arr[10].freq++;
			arr[10].letra = 'k';
			break;
		case 'l':
			arr[11].freq++;
			arr[11].letra = 'l';
			break;
		case 'm':
			arr[12].freq++;
			arr[12].letra = 'm';
			break;
		case 'n':
			arr[13].freq++;
			arr[13].letra = 'n';
			break;
		case 'o':
			arr[14].freq++;
			arr[14].letra = 'o';
			break;
		case 'p':
			arr[15].freq++;
			arr[15].letra = 'p';
			break;
		case 'q':
			arr[16].freq++;
			arr[16].letra = 'q';
			break;
		case 'r':
			arr[17].freq++;
			arr[17].letra = 'r';
			break;
		case 's':
			arr[18].freq++;
			arr[18].letra = 's';
			break;
		case 't':
			arr[19].freq++;
			arr[19].letra = 't';
			break;
		case 'u':
			arr[20].freq++;
			arr[20].letra = 'u';
			break;
		case 'v':
			arr[21].freq++;
			arr[21].letra = 'v';
			break;
		case 'w':
			arr[22].freq++;
			arr[22].letra = 'w';
			break;
		case 'x':
			arr[23].freq++;
			arr[23].letra = 'x';
			break;
		case 'y':
			arr[24].freq++;
			arr[24].letra = 'y';
			break;
		case 'z':
			arr[25].freq++;
			arr[25].letra = 'z';
			break;
		case ' ':
			arr[26].freq++;
			arr[26].letra = ' ';
		}
	}

	for (int i = 0; i < 27; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (arr[i].freq < arr[j].freq)
			{
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i].freq == 0)
		{
			below_zero++;
		}
	}

	for (int i = below_zero; i < 27 + below_zero; i++, j++)
	{
		arr[j] = arr[i];
	}

	for (int i = 0; i < 27 - below_zero; i++)
	{
		size++;
	}


	for (int i = 0; i < size; i++)
	{
		Arbol *nuevo = new Arbol(arr[i]);
		vec->push_back(nuevo);
		sin_ocurrencias += vec->at(i)->raiz->dato.letra;
	}

	Huffman(vec, 0);

	vec->at(0)->deleteleafs();
	vec->at(0)->MostrarArbol();

	cout << endl << endl;

	vec->at(0)->printPaths();
	
	cout << endl<<endl;

	cout << codigoHuffman;
	cout << endl;

	vec->at(0)->Decodificarr(secondstring, 0);

	_getch();
}