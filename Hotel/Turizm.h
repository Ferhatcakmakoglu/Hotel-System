#include<iostream>
#include<fstream>

#ifndef TURIZM_H
#define TURIZM_H
#include<string>
#include "Kupon.h"
#include "OdaIslem.h"
#include "Node.h"
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
	inline void kuponIleRezervasyonIslemMenusu() override;
	inline void kuponsuzRezervasyonIslemMenusu() override;
	inline void rezerveEt(string,int);
	inline void dosyayaYaz(string,string);

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
	OdaIslem* odaIslem = new OdaIslem();
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
	odaIslem->bosOdaListele(); // bos odalar listelendi
	string odaNo;
	cout << "Lutfen istediginiz odanin OdaNo'sunu yaziniz (orn: A-20): ";
	cin >> odaNo;
	rezerveEt(odaNo,indirim);
}

void Turizm::kuponsuzRezervasyonIslemMenusu()
{
	OdaIslem* odaIslem = new OdaIslem();
	odaIslem->bosOdaListele(); //bos odalar listelendi
	string odaNo;
	cout << "Lutfen istediginiz odanin OdaNo'sunu yaziniz (orn: A-20): ";
	cin >> odaNo;

	rezerveEt(odaNo, 0); 
}

void Turizm::rezerveEt(string odaNo,int indirim)
{
	Node* odaBilgileri = new Node();

	int i = 0,index;
	int odaTutari;
	string ozelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\odaIslemGecmisi.txt";
	string genelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
	string odaNoUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + odaNo + ".txt";
	string line,newString,arananData;
	ifstream read(odaNoUrl);
	while(getline(read,line))
	{
		if(i == 4)
		{
			index = line.find(":");
			arananData = line.substr(index + 1);
			odaTutari = stoi(arananData);
		}
		
		if (i == 5) // 5 olmasinin sebebi odaNo.txt lerde 5. indis doluluk boslugun indisi
		{
			newString = "DOLULUK :1";
			odaBilgileri->add(odaBilgileri,newString); // 5. indis doluluk bosluk, onu degistirdik
		}
		else
		{
			odaBilgileri->add(odaBilgileri, line); //rezerve edilecek odayi linkedList'e geçirdik
		}
		i++;
		
	}
	read.close();

	int indirimliFiyat = odaTutari - ((odaTutari * indirim) / 100); //yeni oda fiyati hesaplandi
	remove(odaNoUrl.c_str()); // odaNo.txt yi sildik
	odaBilgileri->writeNodeToFile(odaBilgileri, odaNoUrl); // odayi tekrar olusturup, dolu olarak güncelledik
	dosyayaYaz(odaNoUrl, to_string(indirimliFiyat));
	cout << "[" << odaNo << "] ODASINA REZERVASYON ISLEMINIZ BASARILI" << endl;
	string islemGecmisiMesaji = "["+odaNo + "] NO'LU ODA REZERVE EDILDI";
	dosyayaYaz(ozelIslemGecmisiUrl,islemGecmisiMesaji);
	dosyayaYaz(genelIslemGecmisiUrl, islemGecmisiMesaji);
}

void Turizm::dosyayaYaz(string url, string data)
{
	ofstream write(url, ios::app);
	write << data << endl;
	write.close();
}

#endif // !TURIZM_H