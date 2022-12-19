#include<iostream>
#include<fstream>
#include<string>
#include "Node.h"
#ifndef ODAISLEM_H
#define ODAISLEM_H
using namespace std;
class AbsOdaIslem {
public:
	virtual void odaEkle() = 0;
	virtual void odaSil() = 0;
	virtual void doluOdaListele() = 0;
	virtual void bosOdaListele() = 0;
	virtual void tumOdalariListele() = 0;
};

class Oda {
public:
	string odaNo;
	string odaTuru;
	int odaKisiKapasitesi;
	int gunlukOdaFiyati;
	bool temizlik;
	bool araTemizlik;
	bool ozelTemizlik;
	bool doluMu;
};

class OdaIslem : public AbsOdaIslem
{
	int toplamOdaSayisi;
public:
	OdaIslem()
	{
		setToplamOdaSayisi();
	}
	void odaIslemMenu()
	{
		int islem;
		cout << "1~ Oda Ekle\n"
			<< "2~ Oda Sil\n" 
			<< "3~ Tum Odalari Listele\n" 
			<< "4~ Dolu Odalari Listele\n" 
			<< "5~ Bos Odalari Listele" << endl;
		cout << "Islem seciniz: ";
		cin >> islem;

		switch (islem)
		{
		case 1:
			odaEkle();
			break;
		case 2:
			odaSil();
			break;
		case 3:
			tumOdalariListele();
			break;
		case 4:
			doluOdaListele();
			break;
		case 5:
			bosOdaListele();
			break;
		default:
			cout << "Hatali Tuslama" << endl;
			break;
		}
	}
	inline void odaEkle() override;
	inline void odaSil() override;
	inline void doluOdaListele() override;
	inline void bosOdaListele() override;
	inline void tumOdalariListele() override;
	inline void dosyayaYaz(string,string);
	void setToplamOdaSayisi()
	{
		string line;
		int count = 0;
		string tumOdalarTxtUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar.txt";
		ifstream read(tumOdalarTxtUrl);
		while(getline(read,line))
		{
			count++;
		}
		read.close();
		this->toplamOdaSayisi = count;
	}
};


void OdaIslem::odaEkle()
{
	Oda* oda = new Oda(); //oda tanýmlama
	string tumOdalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar.txt";
	
	cout << "ODA NO: ";
	cin >> oda->odaNo;
	cout << "ODA TURU(A,B,C,VIP..): ";
	cin >> oda->odaTuru;
	cout << "KAPASITE: ";
	cin >> oda->odaKisiKapasitesi;
	cout << "GUNLUK FIYAT: ";
	cin >> oda->gunlukOdaFiyati;
	oda->doluMu = false;
	oda->temizlik = true;
	oda->ozelTemizlik = false;
	oda->araTemizlik = false;

	string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\"+ oda->odaNo +".txt";
	string data =  "---------------------------"
					"\nODA NO:" + oda->odaNo
					+ "\nODA TURU:" + oda->odaTuru
					+ "\nODA KAPASITE:" + to_string(oda->odaKisiKapasitesi)
					+ "\nGUNLUK FIYAT:" + to_string(oda->gunlukOdaFiyati)
					+ "\nDOLULUK :" + to_string(oda->doluMu)
					+ "\nTEMIZLIK:" + to_string(oda->temizlik)
					+ "\nARA TEMIZLIK:" + to_string(oda->araTemizlik)
					+ "\n---------------------------\n";
	string genelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
	string ozelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\odaIslemGecmisi.txt";
	string odaNo = oda->odaNo;
	string islemGecmisiMesaji = "Sisteme [ " + odaNo + " ] adli oda eklenmistir";
	dosyayaYaz(odalarUrl,data); //odaNo.txt açýp içerisini doldurdu
	dosyayaYaz(tumOdalarUrl,odaNo); //tüm odalara ekleme yaptý
	dosyayaYaz(genelIslemGecmisiUrl, islemGecmisiMesaji); // genel islem gecmisine yazildi
	dosyayaYaz(ozelIslemGecmisiUrl, islemGecmisiMesaji); // odalar icindeki islem gecmisine yazildi
	cout << odaNo << " Adli odaniz olusturuldu!" << endl;
}

void OdaIslem::odaSil()
{
	int id;
	tumOdalariListele();
	cout << "Lutfen silmek istediginiz odanin solundaki no'yu giriniz";
	cin >> id;

	Node* oda = new Node();
	string line;
	string tumOdalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar.txt";
	ifstream read(tumOdalarUrl);

	while(getline(read,line))
	{
		oda->add(oda, line); //tüm odalari once linkedListe ekledik
	}
	read.close();
	
	
	oda->remove(oda, --id); // odayi linkedListten sildik
	
	string silinecekOda = oda->getSilinecekData();
	string silinecekData = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + silinecekOda + ".txt";
	
	remove(tumOdalarUrl.c_str()); //dosyayi sildik
	remove(silinecekData.c_str()); // bos odalardan odaNo.txt silindi
	
	oda->writeNodeToFile(oda, tumOdalarUrl); //tumOdaalr.txt ye tekrar yazdik
	cout << "Oda silindi" << endl;

	string genelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
	string ozelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\odaIslemGecmisi.txt";
	string islemGecmisiOzel = "Sistemden " + silinecekOda + " Odasi Silinmistir";
	
	dosyayaYaz(ozelIslemGecmisiUrl, islemGecmisiOzel); //ozel islem gecmisine yazildi
	dosyayaYaz(genelIslemGecmisiUrl,islemGecmisiOzel);//genel islem gecmisine yazildi
}


void OdaIslem::doluOdaListele()
{

}


void OdaIslem::bosOdaListele()
{

}

void OdaIslem::tumOdalariListele()
{
	cout << "TUM ODALAR" << endl;
	string tumOdalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar.txt";
	ifstream read(tumOdalarUrl);
	string line;
	int i = 1;
	while(getline(read,line))
	{
		cout << i << "# " << line << endl;
		i++;
	}
	cout << "\nTOPLAM ODA SAYISI: " << this->toplamOdaSayisi << endl;
	read.close();
}

void OdaIslem::dosyayaYaz(string url, string data)
{
	ofstream write(url, ios::app);
	write << data << endl;
	write.close();
}

#endif // !ODAISLEM_H