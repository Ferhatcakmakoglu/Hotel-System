#pragma warning(disable : 4996)
#include <iostream>
#ifndef ListSakirSAKIR_H
#define ListSakirSAKIR_H
#include "NodeSakir.h"
#include <ctime>
using namespace std;

class ListSakir {
	NodeSakir* root;
public:
	ListSakir() : root(NULL) { }

	NodeSakir* begin() const { return root; }
	NodeSakir* end() const { return NULL; }
	bool isEmpty() const { return begin() == end(); }

	//ListSakireye �r�n eklemek i�in kullan�lan fonksiyon 4 parametreli
	void pushBack(const string& deger, char* kontrolTarihi, int islemiYapanId, const double& deger2) {

		if (isEmpty()) // ListSakire bos mu diye kontrol eden blok
		{
			root = new NodeSakir(deger, kontrolTarihi, islemiYapanId, deger2);
		}
		else
		{
			NodeSakir* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new NodeSakir(deger, kontrolTarihi, islemiYapanId, deger2);
		}

	}

	//ListSakireye �r�n eklemek i�in kullanilan fonksiyon 3 parametreli
	void pushBack(const string& deger, char* kontrolTarihi, int islemiYapanId) {

		if (isEmpty())// ListSakire bo� mu diye kontrol eden blok
		{
			root = new NodeSakir(deger, kontrolTarihi, islemiYapanId);
		}
		else {
			NodeSakir* tmp = begin();
			while (tmp->next != end()) {
				tmp = tmp->next;
			}
			tmp->next = new NodeSakir(deger, kontrolTarihi, islemiYapanId);
		}

	}

	void print()
	{
		NodeSakir* temp = root;
		while (temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}


	//destructor
	~ListSakir() {}

};
#endif 