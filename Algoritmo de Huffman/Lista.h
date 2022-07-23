//#pragma once
//#ifndef LISTA_H_INCLUDE
//#define LISTA_H_INCLUDE
//
//#include <iostream>
//#include <conio.h>
//using namespace std;
//
//template <typename T, typename F>
//struct NodoLista {
//	T dato;
//	F sdato;
//	NodoLista<T> *next;
//	NodoLista(T dato, F sdato)
//	{
//		this->sdato = sdato;
//		this->dato = dato;
//		next = nullptr;
//	}
//};
//
//template <class T, class F>
//class Lista {
//private:
//	NodoLista<T, F> *primero;
//public:
//	Lista() { primero = nullptr; }
//
//	void agregar_al_inicio(T);
//	void agregar_al_final(T);
//	void eliminar_por_valor(T);
//	void imprimir();
//};
//
//template <typename T, typename F>
//void Lista<T, F>::agregar_al_final(T dato) {
//	if (primero == nullptr) {
//		primero = new NodoLista<T, F>(dato);
//		return;
//	}
//	NodoLista<T, F>*actual = primero;
//	while (actual->next != nullptr) {
//		actual = actual->next;
//	}
//	actual->next = new NodoLista<T, F>(dato);
//}
//
//template <typename T, typename F>
//void Lista<T, F>::agregar_al_inicio(T dato) {
//	NodoLista<T, F> *nuevo = new NodoLista<T, F>(dato);
//	nuevo->next = primero;
//	primero = nuevo;
//}
//
//template <typename T, typename F>
//void Lista<T, F>::eliminar_por_valor(T dato) {
//	if (primero == nullptr)
//		return;
//	if (primero->dato == dato) {
//		primero = primero->next;
//		return;
//	}
//	NodoLista<T, F> *actual = primero;
//	while (actual->next != nullptr) {
//		if (actual->next->dato == dato) {
//			actual->next = actual->next->next;
//			return;
//		}
//		actual = actual->next;
//	}
//}
//
//template <typename T, typename F>
//void Lista<T, F>::imprimir() {
//	NodoLista<T, F> *actual = primero;
//	while (actual != nullptr) {
//		cout << actual->dato << "->" << endl;
//		actual = actual->next;
//	}
//}
//
//#endif // !LISTA_H_INCLUDE