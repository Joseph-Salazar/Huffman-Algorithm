#pragma once
#ifndef LISTA_H_INCLUDE
#define LISTA_H_INCLUDE

#include <iostream>
#include <conio.h>
using namespace std;

struct conteo {
	int freq;
	char letra;
	conteo()
	{
		freq = 0;
	}
};

struct NodoArbol {
	conteo dato;
	int id;
	NodoArbol *left;
	NodoArbol *right;

	NodoArbol(conteo dato)
	{
		this->dato = dato;
		left = nullptr;
		right = nullptr;
	}
	NodoArbol()
	{

	}
};

class Arbol {
public:
	Arbol(conteo dato)
	{
		raiz = new NodoArbol(dato);
	}

	Arbol()
	{

	}
	~Arbol();

	void insert(conteo key);
	NodoArbol *search(conteo key);
	void destroy_tree();
	void inorder_print();

	void destroy_tree(NodoArbol *leaf);
	void insert(conteo key, NodoArbol *leaf);
	NodoArbol *search(conteo key, NodoArbol *leaf);
	void inorder_print(NodoArbol *leaf);

	NodoArbol *raiz;
};


Arbol::~Arbol() {
	destroy_tree();
}

void Arbol::destroy_tree(NodoArbol *leaf) {
	if (leaf != nullptr) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

//NodoArbol *Arbol::search(conteo key, NodoArbol *leaf) {
//	if (leaf != nullptr) {
//		if (key == leaf->value)
//		{
//			return leaf;
//		}
//		if (key < leaf->value) 
//		{
//			return search(key, leaf->left);
//		}
//		else
//		{
//			return search(key, leaf->right);
//		}
//	}
//	else {
//		return nullptr;
//	}
//}

//NodoArbol *Arbol::search(conteo key) {
//	return search(key, Raiz);
//}

void Arbol::destroy_tree() {
	destroy_tree(raiz);
}

void Arbol::inorder_print() {
	inorder_print(raiz);
	cout << "\n";
}

void Arbol::inorder_print(NodoArbol *leaf) {
	if (leaf != nullptr) {
		inorder_print(leaf->left);
		cout << leaf->dato.freq << "," << leaf->dato.letra;
		inorder_print(leaf->right);
	}
}

//////////////// Lista


struct Nodo {
	NodoArbol *dato;
	Nodo *next;
	Nodo(NodoArbol *dato)
	{
		this->dato = dato;
		next = nullptr;
	}
	Nodo()
	{

	}
};

class Lista {
private:
	Nodo *primero;
	int lon;
public:
	Lista() { primero = nullptr; lon = 0; }

	void agregar_al_inicio(Nodo);
	void agregar_al_final(Nodo);
	void imprimir();
	void Recursivo(Nodo*);
	void Eliminar();
	void Recursivo();
	void Recorrer(NodoArbol*);
	void Recorrer();
};

void Lista::Recorrer()
{
	Recorrer(primero->dato);
}

void Lista::Recorrer(NodoArbol* raiz)
{
	if (raiz->left == nullptr && raiz->right == nullptr)
	{
		cout << raiz->dato.letra;
		return;
	}
	else
	{
		if (raiz->left != nullptr)
		{
			cout << "0";
			Recorrer(raiz->left);
		}
		if (raiz->right != nullptr)
		{
			cout << "1";
			Recorrer(raiz->right);
		}
		
	}
}

void Lista::Recursivo()
{
	Recursivo(primero);
}

void Lista::Recursivo(Nodo *nodo)
{
	/*if (lon == 1)
	{
		return;
	}
	else
	{
		conteo aux;
		if (nodo->next != nullptr && nodo!=nullptr)
		{
			aux.freq = nodo->dato->dato.freq + nodo->next->dato->dato.freq;
			aux.letra = '-';
		}

		NodoArbol *agregar = new NodoArbol(aux);
		Nodo *nuevo = new Nodo(agregar);


		nuevo->dato->left = nodo->dato;
		nuevo->dato->left->id = 0;
		nuevo->dato->right = nodo->next->dato;
		nuevo->dato->right->id = 1;

		agregar_al_inicio(*nuevo);
		if (lon != 1)
		{
			Eliminar(); Eliminar();
		}
		if (lon == 2)
		{
			Eliminar();
		}
		Recursivo(nodo->next);
	}	*/


}

void Lista::Eliminar()
{
	primero = primero->next;
	lon--;
}

//void Lista::agregar_al_final(Nodo dato) {
//	if (primero == nullptr) 
//	{
//		primero = new Nodo(dato);
//		lon++;
//		return;
//	}
//	else
//	{
//		Nodo *actual = primero;
//		while (actual->next != nullptr)
//		{
//			actual = actual->next;
//		}
//		lon++;
//		actual->next = new Nodo(dato);
//	}
//}

void Lista::agregar_al_inicio(Nodo dato) {
	Nodo *nuevo = new Nodo(dato);
	nuevo->next = primero;
	primero = nuevo;
}

void Lista::imprimir() {
	Nodo *actual = primero;
	while (actual != nullptr) {
		cout << actual->dato->id;
		actual = actual->next;
	}
}

#endif // !LISTA_H_INCLUDE