#pragma warning(disable : 4996)
#include <iostream>
#ifndef ODASERVISI_H
#define ODASERVISI_H
#include "OdaIslem.h"
#include "ListSakir.h"
#include <fstream>
#include <ctime>
using namespace std;

class OdaServisi {
	string odaNo;
	int islemiYapanId;
	char* kontrolTarihi;
protected:
	double fiyat;
public:
	string gida, gida1;
	ListSakir list;
	ListSakir list1;

	// OdaServisi classinin constructori parametreli
	/*OdaServisi(string odaNo, int islemiYapanId, char* kontrolTarihi){
		this->odaNo = odaNo;
		this->islemiYapanId;
		this->kontrolTarihi;
	}*/

	// OdaServisi classinin constructori parametresiz
	OdaServisi() {}


	void odaServisiMenu() {
		int islem;
		cout << "1# Acik Bufe Gida Ekle\n"
			<< "2# Acik Bufe Gidalari Listele\n"
			<< "3# Mini Bar Gida Ekle\n"
			<< "4# Ozel Talep Olustur\n"
			<< "Islmeniniz: ";
		cin >> islem;

		switch (islem)
		{
		case 1:
			acikBufeGidaEkle();
			break;
		case 2:
			acikBufeGidaYazdir();
			break;
		case 3:
			miniBarGidaEkle();
			break;
		case 4:
			ozelTalepOlustur();
			break;
		default:
			cout << "HATALI TUSLAMA" << endl;
			break;
		}
	}

	// Dosya olusturma fonksiyonu
	void dosyaOlustur(string fileName) {

		string fileLocation = "C:\\C++\\DonemProje\\HotelService\\Data\\" + fileName + ".txt";
		ofstream file(fileLocation);
		file.close();
		cout << "Dosya Olustu!" << endl;
	}


	// Acik bufeye gida ekleme fonksiyonu
	void acikBufeGidaEkle() {
		cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
		/*
			personelleri listeleme yapýlacak burda
		*/
		cin >> islemiYapanId;

		while (gida != "0") {
			cout << "Gidayi Giriniz(Ekleme isleminden cikmak icin 0'a basin):";
			cin >> gida;
			if (gida != "0")
			{
				time_t now = time(0);
				char* kontrolTarihi = ctime(&now);
				list.pushBack(gida, kontrolTarihi, islemiYapanId);
			}
		}

		acikBufeGidaEkleText("acikBufeGidalar");
		cout << endl;
	}

	// acikBufeGidaEkle fonksiyonunun kullanabilmesi icin texte gidalari yazdiran fonksiyon
	void acikBufeGidaEkleText(string fileName)
	{
		string ozelIslemGecmisiTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\odaServisiIslemGecmisi.txt";
		string genelIslemGecmisi = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
		string odaServisilIslemGecmisi = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\OdaServisi\\gidalarIslemGecmisi.txt";
		
		string fileLocation = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\OdaServisi\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);
		string islemGecmisiMesaj;

		NodeSakir* tmp = list.begin();
		time_t now = time(0);
		char* kontrolTarihi = ctime(&now);
		file << "\nIslemi Yapan Kisinin ID'si: " << tmp->islemiYapanId << endl;
		while (tmp != list.end())
		{
			file << tmp->data << " | Islem Tarihi: " << tmp->kontrolTarihi;
			islemGecmisiMesaj = "[ ACIK BUFE EKLEME ] - ID[ " + to_string(islemiYapanId) + " ] --> "
				+ "TARIH = " + kontrolTarihi + ", URUN VE TUTAR = [" + tmp->data + " - " + to_string(fiyat) + "]";
			tmp = tmp->next;
			
			islemGecmisiYaz(ozelIslemGecmisiTxtUrl, islemGecmisiMesaj);
			islemGecmisiYaz(genelIslemGecmisi, islemGecmisiMesaj);
			islemGecmisiYaz(odaServisilIslemGecmisi, islemGecmisiMesaj);
		}
		cout << "GIDALAR EKLENDI" << endl;
		file.close();
	}

	// Acik bufeye eklenen gidalari yazdirir
	void acikBufeGidaYazdir() {
		cout << "Acik bufedeki gidalar:\n";

		string url = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\OdaServisi\\acikBufeGidalar.txt";
		ifstream read(url);
		string line;
		int i = 1;
		while (getline(read, line))
		{
			cout << line << endl;
		}
	}

	// Mini bara gida ekleme fonksiyonu
	void miniBarGidaEkle() {
		string ozelIslemGecmisiTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\OdaServisi\\gidalarIslemGecmisi.txt";
		string genelIslemGecmisi = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";


		cout << "\nIslemi Gerceklestiren Kisinin ID'si: ";
		cin >> islemiYapanId;

		while (gida1 != "0") {
			cout << "Gidayi giriniz(Ekleme isleminden cikmak icin 0'e basin):";
			cin >> gida1;
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);
			string islemGecmisiMesaj;
			if (gida1 != "0")
			{
				cout << "Eklediginiz gidanin fiyatini giriniz:";
				cin >> fiyat;
				list1.pushBack(gida1, kontrolTarihi, islemiYapanId, fiyat);
				islemGecmisiMesaj = "[ MINI BAR EKLEME ] - ID[ " + to_string(islemiYapanId) + " ] --> "
					+ "TARIH = " + kontrolTarihi + ", URUN VE TUTAR = ["+gida1 +" - " + to_string(fiyat)+"]";
				islemGecmisiYaz(ozelIslemGecmisiTxtUrl, islemGecmisiMesaj);
				islemGecmisiYaz(genelIslemGecmisi, islemGecmisiMesaj);
			}
		}
		miniBarGidaEkleText("miniBarGidalar");
		cout << endl;
	}

	// miniBarGidaEkle fonksiyonunun kullanabilmesi icin texte gidalari yazdiran fonksiyon
	void miniBarGidaEkleText(string fileName) {
		string miniBarIslemGecmisiTxt = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\OdaServisi\\gidalarIslemGecmisi.txt";
		string fileLocation = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\OdaServisi\\" + fileName + ".txt";
		ofstream file(fileLocation, ios::app);

		NodeSakir* tmp = list1.begin();
		file << "\nIslemi Yapan Kisinin ID'si: " << tmp->islemiYapanId << endl;
		while (tmp != list1.end()) {
			file << tmp->data << " Fiyati:" << tmp->fiyat << " | Islem Tarihi: " << tmp->kontrolTarihi;
			tmp = tmp->next;
		}
		file.close();
		
		cout << "MiniBar Gidalari Eklendi" << endl;
	}

	// Mini bara eklenen gidalari yazdirir
	void miniBarGidaYazdir() {
		cout << "Mini bardaki gidalar:\n";
		NodeSakir* tmp = list1.begin();
		while (tmp != list1.end()) {
			cout << tmp->data << " Fiyati:" << tmp->fiyat << endl;
			tmp = tmp->next;
		}
	}

	void ozelTalepOlustur()
	{
		OdaIslem* odaIslem = new OdaIslem();
		string ozelIslemGecmisiTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\odaServisiIslemGecmisi.txt";
		string genelIslemGecmisi = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
		string talep, aciklama, odaNo;
		string islemGecmisiMesaji;
		double tutar;

		//DOLU ODALAR BURADA LÝSTELENECEK
		odaIslem->doluOdaListele();

		cout << "Lutfen Oda No'nuzu giriniz: ";
		cin >> odaNo;

		/*
			BU KISIMDA GÝRÝLEN odaNo kontrol edilecek.
			Yazýlan odaNo database de mevcut ve dolu mu diye
		*/
		if(odaIslem->getOdaDoluluk(odaNo) == 1)
		{
			cout << "Ozel Talep Turu: ";
			cin >> talep;
			cout << "Talep Aciklamasi: ";
			cin >> aciklama;
			cout << "Talep Maaliyeti";
			cin >> tutar;



			int islem = ozelTalepCevap(tutar, odaNo, talep);
			if (islem)
			{
				islemGecmisiMesaji = odaNo + " NO'LU ODA " + talep + " OZEL TALEBI ETMISTIR! TUTAR = " + to_string(tutar);
				islemGecmisiYaz(genelIslemGecmisi, islemGecmisiMesaji);
				islemGecmisiYaz(ozelIslemGecmisiTxtUrl, islemGecmisiMesaji);

				cout << "TALEBINIZ BASARIYLA OLUSTURULDU" << endl;
			}
			else
			{
				time_t now = time(0);
				char* kontrolTarihi = ctime(&now);

				string date(kontrolTarihi);
				string info = talep + " --> [ " + to_string(fiyat) + "TL]";
				islemGecmisiMesaji = info + "\nIslemi Gerceklestiren Kisinin ID'si: " + to_string(islemiYapanId) + "\n"
					+ "\nIslem Onaylanmadi" + " | Islem Tarihi: " + date;

				islemGecmisiYaz(genelIslemGecmisi, islemGecmisiMesaji);
				islemGecmisiYaz(ozelIslemGecmisiTxtUrl, islemGecmisiMesaji);
				cout << "TALEP OLUSTURMA ISLEMINIZ REDDEDILDI! " << endl;
			}
		}
		else
		{
			cout << "GIRILEN ODA NO DOLU DEGIL!" << endl;
		}
	}


	// Musteri ozel talep belirtirse onaylama fonksiyonu
	bool ozelTalepCevap(double fiyat, string fileName, string talep) {
		string ozelIslemGecmisiTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Hizmet\\odaServisiIslemGecmisi.txt";
		string genelIslemGecmisi = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";

		string fileLocation = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + fileName + ".txt";
		string data;

		int onay;
		this->fiyat = fiyat;
		cout << "Talebinizin bedeli: " << fiyat << "'TL dir." << endl;
		cout << "Onayliyorsaniz 1 Onaylamiyorsaniz 0 yaziniz: ";
		cin >> onay;

		if (onay == 1)
		{
			time_t now = time(0);
			char* kontrolTarihi = ctime(&now);

			cout << "Islemi Gerceklestiren Kisinin ID'si: ";
			/*
				BURADA PERSONELLER VE ID LERÝ LÝSTELENECEK
			*/
			cin >> islemiYapanId;

			string info = talep + " --> [ " + to_string(fiyat) + "TL]";
			string kontrolZamani(kontrolTarihi);
			string info2 = info + "\n" + "Islemi Gerceklestiren Kisinin ID'si: " + to_string(islemiYapanId)
				+ "\n Islem Onaylandi" + " | Islem Tarihi: " + kontrolZamani;
			writeToFile(fileName, info2);
			return true;
		}
		else {

			return false;
		}
	}

	void islemGecmisiYaz(string url, string data)
	{
		ofstream write(url, ios::app);
		write << data << endl;
		write.close();
	}


	void writeToFile(string fileName, string data)
	{
		string dosyaUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + fileName + ".txt";
		ofstream write(dosyaUrl, ios::app);
		write << data << endl;
		write.close();
	}
};

#endif