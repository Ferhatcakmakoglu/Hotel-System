#pragma warning(disable : 4996)
#include <iostream>
#ifndef NODESAKIR_H
#define NODESAKIR_H
#include <ctime>

using namespace std;

class NodeSakir {
public:
	string data;

	double fiyat;
	NodeSakir* next;
	char* kontrolTarihi;
	int islemiYapanId;

	//Node classinin constructor'i
	NodeSakir(const string& data = "", char* kontrolTarihi = 0, int islemiYapanId = 0, const double& fiyat = 0, NodeSakir* next = NULL) :data(data), kontrolTarihi(kontrolTarihi),
		islemiYapanId(islemiYapanId), fiyat(fiyat), next(next) {	}



	//~Node() {}

};
#endif