#include<iostream>
#include<fstream>
#include<string>
#include "Turizm.h"
#ifndef KUPON_H
#define KUPON_H

using namespace std;

class AbsKupon {
public:
	virtual void kuponEkle() = 0;
	virtual void kuponSil() = 0;
	virtual void kuponlariListele() = 0;
};

class Kupon : public AbsKupon
{
	
	int kuponSayisi; //kuponlari listele ile aldýk degeri
	string kuponDosyaUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Kuponlar\\";
	string tumKuponlarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Kuponlar\\KUPONLAR.txt";
	string kuponIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Kuponlar\\kuponIslemGecmisi.txt";
	string genelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
public:
	friend class Turizm; //kupon adreslerine ulasabilmek icin
	Kupon()
	{
		kuponSayisiHesapla(); //kupon sayisini bulduk
	}
	inline void kuponIslem();
	inline void kuponEkle();
	inline void kuponSil();
	inline void kuponlariListele();
	inline void kuponSayisiHesapla();
	inline void islemGecmisineYaz(string,string);
};

void Kupon::kuponIslem()
{
	int islem;
	cout << "#1 Kupon Ekle\n"
		<< "#2 Kupon Sil\n"
		<< "#3 Kuponlari Listele" << endl;
	cout << "Islem seciniz: ";
	cin >> islem;
	switch (islem)
	{
	case 1:
		kuponEkle();
		break;
	case 2:
		kuponSil();
		break;
	case 3:
		kuponlariListele();
		break;
	default:
		cout << "Hatali Tuslama" << endl;
		break;
	}
}

void Kupon::kuponEkle()
{
	string kuponAdi;
	int kuponTutari;
	cout << "Kupon Adi: ";
	cin >> kuponAdi;
	cout << "Kupon Tutari: ";
	cin >> kuponTutari;

	string kuponTxt = kuponDosyaUrl.append(kuponAdi+".txt"); //kupona özel txt acýldý
	ofstream write(kuponTxt);
	write << kuponTutari;
	write.close();

	ofstream writeKuponlar(tumKuponlarUrl,ios::app); // tumKuponlar a yazýldý
	writeKuponlar << kuponAdi << endl;
	writeKuponlar.close();
	cout << kuponAdi << " kuponu sisteme eklendi!" << endl;
	string islemGecmisiMesaji = "Sisteme " + kuponAdi + " Kupon Eklendi. TUTAR: %" + to_string(kuponTutari);
	islemGecmisineYaz(kuponIslemGecmisiUrl,islemGecmisiMesaji);
	islemGecmisineYaz(genelIslemGecmisiUrl, islemGecmisiMesaji);
	kuponSayisiHesapla(); //yeni kupon sayisi hesaplandi
}
void Kupon::kuponSil()
{
	//kuponSayisiHesapla();//yeni kupon sayisi hesaplandi
	string* kuponlar = new string[kuponSayisi];
	int no;
	kuponlariListele();
	cout << "Lutfen Silmek istediginiz Kupon Numarasini Giriniz: ";
	cin >> no;
	no = no - 1;
	int i = 0;

	//istenmeyen kupon haric digerlerini array a gönderdik
	ifstream read(tumKuponlarUrl);
	string line;
	while(getline(read,line))
	{
		*(kuponlar + i) = line;
		i++;
	}
	read.close();

	string silinecekTxt = *(kuponlar + no) + ".txt";
	remove(kuponDosyaUrl.append(silinecekTxt).c_str()); //silinen kuponun txt sil
	remove(tumKuponlarUrl.c_str()); //eski tum kuponlar listesi silindi
	ofstream write(tumKuponlarUrl, ios::app);
	for(int i=0;i<kuponSayisi;i++)
	{
		if(i != no)
		{
			write << *(kuponlar + i) << "\n";
		}
	}
	write.close();
	cout << "Kupon Silindi" << endl;
	string islemGecmisiMesaji = "Sistemden " + *(kuponlar + no) + " Kuponu silindi";
	islemGecmisineYaz(kuponIslemGecmisiUrl, islemGecmisiMesaji);
	islemGecmisineYaz(genelIslemGecmisiUrl, islemGecmisiMesaji);
	delete[] kuponlar; //bellekten kuponlar yerini sildik
}
void Kupon::kuponlariListele()
{
	ifstream read(tumKuponlarUrl);
	string line;
	int i = 1;
	while(getline(read,line))
	{
		cout << i << "- " << line << endl;
		i++;
	}
	read.close();
}

void Kupon::kuponSayisiHesapla()
{
	ifstream read(tumKuponlarUrl);
	string line;
	int i = 0;
	while (getline(read, line))
	{
		i++;
	}
	this->kuponSayisi = i;
	read.close();
}

void Kupon::islemGecmisineYaz(string url,string islem)
{
	ofstream write(url, ios::app);
	write << islem << endl;
	write.close();
}
#endif // !KUPON_H