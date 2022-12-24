#include<iostream>
#include<fstream>
#include<string>
#include "Node.h"
#include "ExceptionHandling.h"
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
	inline void dosyaOku(string);
	inline string getOdaAdi(int);
	inline int getOdaDoluluk(string);
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
	ExceptionHandling* exc = new ExceptionHandling();
	string tumOdalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar.txt";
	
	cout << "ODA NO: ";
	cin >> oda->odaNo;
	
	try
	{
		string kategori[] = {"A","B","C","VIP"};
		int kategoriSayisi = 4,result = 0;
		cout << "ODA TURU(A,B,C,VIP..): ";
		cin >> oda->odaTuru;
		for(int i=0;i<kategoriSayisi;i++)
		{
			if (oda->odaTuru == kategori[i])
			{
				result = 1;
				break;
			}
		}

		if(result != 1)
		{
			throw 1;
		}
	}
	catch (int i)
	{
		if(i == 1)
		{
			exc->printNamingError("WrongRoomNaming");
			cout << "Lutfen Odanizi Tekrar Olusturunuz!" << endl;
			odaEkle();
		}
	}


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
	cout << "Lutfen silmek istediginiz odanin solundaki no'yu giriniz: ";
	cin >> id;

	Node* oda = new Node();
	ExceptionHandling* exc = new ExceptionHandling();
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
	
	try
	{
		int res1 = remove(tumOdalarUrl.c_str()); //dosyayi sildik
		int res2 = remove(silinecekData.c_str()); // bos odalardan odaNo.txt silindi
		if((res1 != 0) || (res2 != 0))
		{
			throw 1;
		}
	}
	catch (int i)
	{
		if(i == 1)
		{
			exc->printFileException("FileNotRemoved");
		}
	}
	
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
	string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\";
	string oda;
	//ifstream read();
	int count = 1;
	for(int i=0;i<toplamOdaSayisi;i++)
	{
		oda = getOdaAdi(i); //tumOdalar.txt den ilgili odanin adini aldýk
		odalarUrl.append(oda + ".txt");
		if(getOdaDoluluk(oda) == 1) // aldýgýmýz odayý kontrol ediyoruz (dolu mu bos mu diye)
		{
			cout << "\n#" << count << endl;
			dosyaOku(oda); // dolu odayi yazdirdik
			count++;
		}
	}
	cout << "\nTOPLAM " << --count << " ODA DOLU" << endl;
}


void OdaIslem::bosOdaListele()
{
	string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\";
	string oda;
	//ifstream read();
	int count = 1;
	for (int i = 0; i < toplamOdaSayisi; i++)
	{
		oda = getOdaAdi(i); //tumOdalar.txt den ilgili odanin adini aldýk
		odalarUrl.append(oda + ".txt");
		if (getOdaDoluluk(oda) == 0) // aldýgýmýz odayý kontrol ediyoruz (dolu mu bos mu diye)
		{
			cout << "\n#" << count << endl;
			dosyaOku(oda); // bos odayi yazdirdik
			count++;
		}
	}
	cout << "\nTOPLAM " << --count << " ODA BOS" << endl;
}

// tumOdalar.txt den index sayesinde oda isimlerine ulasýyoruz
// Bu isimleri odalardaki txt lere ulasmak icin kullaniyoruz
string OdaIslem::getOdaAdi(int i)
{
	int count = 0;
	string url = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar.txt";
	string line;
	ifstream read(url);
	string oda;
	while(getline(read,line))
	{
		if(count == i)
		{
			oda = line;
			read.close();
			break;
		}
		count++;
	}
	return oda;
}

//Her bir odayi dolasip Dolu olanlar için 1, olmayanlar için 0 degeri verecek
int OdaIslem::getOdaDoluluk(string fileName)
{
	int i = 0,index;
	string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\"+fileName+".txt";
	string line,arananData;
	ifstream read(odalarUrl);
	int doluluk = 0;
	while(getline(read,line))
	{
		if (i == 5) // 5 olmasinin sebebi odaNo.txt lerde 5. indis doluluk boslugun indisi
		{
			index = line.find(":");
			arananData = line.substr(index + 1);
			doluluk = stoi(arananData);
		}
		i++;
	}
	read.close();
	return doluluk;
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

void OdaIslem::dosyaOku(string fileName)
{
	string odalarUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + fileName + ".txt";
	ifstream read(odalarUrl);
	string line;
	while(getline(read,line))
	{
		cout << line << endl;
	}
	read.close();
}

#endif // !ODAISLEM_H