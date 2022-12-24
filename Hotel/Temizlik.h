#pragma warning(disable : 4996)
#include <iostream>
#ifndef TEMIZLIK_H
#define TEMIZLIK_H
#include <fstream>
#include <ctime>
#include "ListSakir.h"
#include "OdaIslem.h"
using namespace std;

class Temizlik
{
	int islemiYapanId;
	ListSakir list;
public:

	Temizlik() {}

	void temizlikMenu()
	{
		int islem;
		cout << "1~ Cikis Temizlik Kontrol\n" 
			<<  "2~ Ara Temizlik Kontrol\n" 
			<<  "Islem Seciniz: ";
		cin >> islem;
		switch (islem)
		{
		case 1:
			cikisTemizlikMenu();
			break;
		case 2:
			araTemizlikMenu();
			break;
		default:
			break;
		}
	}

	//Ekstra temizlik fonksiyonu friend fonksiyon olarak tanýmlandý
	//friend bool EkstraTemizlik(Oda* oda, bool ekstraTemizlik, string fileName);

	//Müsteri cikis yaptiktan sonra oda temizligi kontrolunu yapan fonksiyon
	
	void cikisTemizlikMenu()
	{
		OdaIslem* odaIslem = new OdaIslem();
		Oda* oda = new Oda();
		string odaNo;

		//DOLU ODALARI GOSTERDÝK
		odaIslem->doluOdaListele();
		cout << "Oda No Giriniz: ";
		cin >> odaNo;

		//Odanin dolu olup olmadýgýna baktýk
		if(odaIslem->getOdaDoluluk(odaNo) == 1)
		{
			int i = 0, index;
			string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + odaNo + ".txt";
			string line, arananData;
			ifstream read(odalarUrl);
			int doluluk = 0;
			while (getline(read, line))
			{
				if (i == 6) // 6 olmasinin sebebi odaNo.txt lerde 6. indis temizlik indisi
				{
					index = line.find(":");
					arananData = line.substr(index + 1);
					doluluk = stoi(arananData); //temizlik sonucu burda
				}
				i++;
			}
			read.close();
			oda->temizlik = doluluk;
			CikisTemizlikKontrol(oda, odaNo);
		}
	}
	
	bool CikisTemizlikKontrol(Oda* oda, string fileName) {
		string islemGecmisiOzel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\Temizlik\\temizlikIslemGecmisi.txt";
		string islemGecmisiGenel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
		string odaServisiIslemGecmisiTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\odaServisiIslemGecmisi.txt";
		string data;
		if (oda->temizlik)
		{
			cout << "Cikis temizlik kontrol islemi basarili: Oda Temiz!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz!", kontrolTarihi, islemiYapanId);
			data = "[CIKIS TEMIZLIK KONTROL] --> ODA NO: #" + fileName + " [PERSONEL ID] = "+ to_string(islemiYapanId) ;
			islemGecmisiYaz(islemGecmisiGenel, data);
			islemGecmisiYaz(islemGecmisiOzel, data);
			islemGecmisiYaz(odaServisiIslemGecmisiTxtUrl, data);
			return true;
		}
		else {
			cout << "Cikis temizlik kontrol islemi basarili: Oda Temiz Degil!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz Degil!", kontrolTarihi, islemiYapanId);
			return false;
		}
	}

	void araTemizlikMenu()
	{
		OdaIslem* odaIslem = new OdaIslem();
		Oda* oda = new Oda();
		string odaNo;

		//DOLU ODALARI GOSTERDÝK
		odaIslem->doluOdaListele();
		cout << "Oda No Giriniz: ";
		cin >> odaNo;

		//Odanin dolu olup olmadýgýna baktýk
		if (odaIslem->getOdaDoluluk(odaNo) == 1)
		{
			int i = 0, index;
			string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + odaNo + ".txt";
			string line, arananData;
			ifstream read(odalarUrl);
			int doluluk = 0;
			while (getline(read, line))
			{
				if (i == 7) // 7 olmasinin sebebi odaNo.txt lerde 7. indis ara temizlik indisi
				{
					index = line.find(":");
					arananData = line.substr(index + 1);
					doluluk = stoi(arananData); //temizlik sonucu burda
				}
				i++;
			}
			read.close();
			oda->temizlik = doluluk;
			araTemizlik(oda, odaNo);
		}
	}

	//Ara temizlik islemi yapan 
	bool araTemizlik(Oda* oda, string fileName) {
		string islemGecmisiOzel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\Temizlik\\temizlikIslemGecmisi.txt";
		string islemGecmisiGenel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
		string odaServisiIslemGecmisiTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\odaServisiIslemGecmisi.txt";
		string data;
		if (oda->temizlik == true)
		{
			cout << "Giris temizlik kontrol islemi basarili: Oda Temiz!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz!", kontrolTarihi, islemiYapanId);
			data = "[ARA TEMIZLIK KONTROL] --> ODA NO: #" + fileName + " [PERSONEL ID] = " + to_string(islemiYapanId);
			islemGecmisiYaz(islemGecmisiGenel, data);
			islemGecmisiYaz(islemGecmisiOzel, data);
			islemGecmisiYaz(odaServisiIslemGecmisiTxtUrl, data);
			return true;
		}
		else {
			cout << "Giris temizlik kontrol islemi basarili: Oda Temiz Degil!";
			cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
			cin >> islemiYapanId;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			list.pushBack("Temiz!", kontrolTarihi, islemiYapanId);
			return false;
		}
	}
	void dosyaOlustur(string fileName) {

		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation);
		file.close();
		cout << "Dosya Olustu!" << endl;
	}


	void islemGecmisiYaz(string url, string data)
	{
		ofstream write(url, ios::app);
		write << data << endl;
		write.close();
	}

	~Temizlik() {}

};

//Müsteri ekstra temizlik isterse bu fonksiyon çaðýrýlýr
//bool EkstraTemizlik(Oda* oda, bool ekstraTemizlik, string fileName) {
//	int islemiYapanId;
//	ListSakir list;
//	const double ekstraTemizlikUcreti = 499999.99;
//	if (oda->ekstraTemizlik == true)
//	{
//		cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
//		cin >> islemiYapanId;
//		time_t now = time(0);
//		char* kontrolTarihi = ctime(&now);
//		list.pushBack("Temiz Degil!", kontrolTarihi, islemiYapanId);
//		return true;
//
//	}
//	else {
//		return false;
//	}
//
//}
#endif