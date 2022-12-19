#include<iostream>
#include<fstream>

#ifndef TURIZM_H
#define TURIZM_H
#include<string>
#include "Kupon.h"
using namespace std;

class AbsTurizm {
public:
	virtual void kuponIleRezervasyonIslemMenusu() = 0;
	virtual void kuponsuzRezervasyonIslemMenusu() = 0;
};

class Turizm : public AbsTurizm
{
	//Kupon* kupon;
	string hotelAdi;
public:
	Turizm()
	{
		this->hotelAdi = "TUZLU HOTEL";
		//this->kupon = &k;
	}
	string getHotelAdi() { return hotelAdi; }
	inline void turizmIslem();
	inline void kuponIleRezervasyonIslemMenusu();
	inline void kuponsuzRezervasyonIslemMenusu();
};


void Turizm::turizmIslem()
{
	int islem;
	cout << "1~ Kupon Ile Rezervasyon\n"
		<< "2~ Kuponsuz Rezervasyon" << endl;
	cout << "Islem seciniz: ";
	cin >> islem;
	switch (islem)
	{
	case 1:
		kuponIleRezervasyonIslemMenusu();
		break;
	case 2:
		kuponsuzRezervasyonIslemMenusu();
		break;
	default:
		cout << "HATALI TUSLAMA" << endl;
		break;
	}
}

void Turizm::kuponIleRezervasyonIslemMenusu()
{
	Kupon* kupon = new Kupon();
	int kuponSayisi = kupon->kuponSayisi;
	string* kuponlar = new string[kuponSayisi];
	string kuponAdi;
	cout << "Mevcut Kuponunuzu yaziniz: ";
	cin >> kuponAdi;

	ifstream read(kupon->tumKuponlarUrl); //tumKuponlar.txt den var olan kuponlarý bulduk
	string line;
	int i = 0;
	while (getline(read, line))
	{
		*(kuponlar + i) = line;
		i++;
	}
	read.close();

	int indirim = 0;
	for(int i=0;i<kuponSayisi;i++)
	{
		if(kuponlar[i]._Equal(kuponAdi))
		{
			ifstream rd(kupon->kuponDosyaUrl.append(kuponAdi+".txt").c_str());
			string ln;
			while(getline(rd,ln))
			{
				indirim += stoi(ln);
			}
			rd.close();
			break;
		}
	}
	cout << "INDIRIMINIZ: %" << indirim << endl;
	//KALAN ODA ALMA KISMI ODALAR TANIMLANDIKTAN SONRA YAPILACAK
}

void Turizm::kuponsuzRezervasyonIslemMenusu()
{
	//BU KISIM ODALAR TANIMLANDIKTAN SONRA YAPILACAK
}
#endif // !TURIZM_H