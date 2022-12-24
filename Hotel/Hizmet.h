#include <iostream>
#include <string>
#include "Temizlik.h"
#include "OdaServisi.h"
using namespace std;
#ifndef HIZMET_H
#define HIZMET_H
class Hizmet
{
public:
	int islemiYapanId;
	char* kontrolTarihi;

	//Hizmet classinin parametreli constructori
	Hizmet(int islemiYapanId, char* kontrolTarihi) {
		this->islemiYapanId = islemiYapanId;
		this->kontrolTarihi = kontrolTarihi;
	}

	void hizmetMenu()
	{
		Temizlik* temizlik = new Temizlik();
		OdaServisi* odaServisi = new OdaServisi();
		int islem;
		cout << "1~ Temizlik Islemleri\n"
			<< "2~ Oda Servisi Bolumu\n"
			<< "Isleminiz: ";
		cin >> islem;
		switch (islem)
		{
		case 1:
			temizlik->temizlikMenu();
			break;
		case 2:
			odaServisi->odaServisiMenu();
			break;
		default:
			cout << "Hatali Tuslama" << endl;
			break;
		}
	}

	//Hizmet classinin parametresiz constructori
	Hizmet() {}

};
#endif 
