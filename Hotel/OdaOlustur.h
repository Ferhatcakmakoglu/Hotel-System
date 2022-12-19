#include<iostream>
#include <string>
#include<fstream>
/*

BU CLASS TEK SEFERLÝK KULLANIM ÝÇÝN OLUÞTURULMUÞTUR
SÝSTEMDE DEFAULT OLARAK 100 ADET ODA TANIMLANMIÞTIR
(100 ODAYI TEKTEK AÇMAK YERÝNE SÝSTEMDEN AÇTIK)

10 ADET --> VIP ODA
30 ADET --> A CLASS ODA
30 ADET --> B CLASS ODA
30 ADET --> C CLASS ODA

*/

using namespace std;

class Oda {
	friend class OdaOlustur;
	string odaNo;
	string odaTuru;
	int odaKisiKapasitesi;
	int gunlukOdaFiyati;
	bool temizlik;
	bool araTemizlik;
	bool ozelTemizlik;
	bool doluMu;
};


class AbsOdaOlustur {
public:
	virtual void odaOlustur(Oda*) = 0;
	int toplamOdaSayisi;
};

class OdaOlustur : public AbsOdaOlustur , Oda
{
	//string dosyaUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Odalar\\";
public:
	
	int vipOdaSayisi = 10;
	int aOdaSayisi = 30;
	int bOdaSayisi = 30;
	int cOdaSayisi = 30;
	const int toplamOdaSayisi = vipOdaSayisi + aOdaSayisi + bOdaSayisi + cOdaSayisi;
	
	//DEFAULT TANIMLANAN 100 ODA
	void odaTanimlama()
	{
		int i, a, b, c;
		Oda* odalar = new Oda[toplamOdaSayisi];
		for (i = 0; i < vipOdaSayisi; i++)
		{
			(odalar + i)->odaNo = "VIP-" + to_string(i + 10);
			(odalar + i)->odaTuru = "VIP";
			(odalar + i)->odaKisiKapasitesi = 1;
			(odalar + i)->temizlik = true;
			(odalar + i)->araTemizlik = false;
			(odalar + i)->ozelTemizlik = false;
			(odalar + i)->gunlukOdaFiyati = 15000;
			(odalar + i)->doluMu = false;
		}
		int j = i;
		for (a = (aOdaSayisi + j); j < a; j++)
		{
			(odalar + j)->odaNo = "A-" + to_string(j + 10);
			(odalar + j)->odaTuru = "A";
			(odalar + j)->odaKisiKapasitesi = 2;
			(odalar + j)->temizlik = true;
			(odalar + j)->araTemizlik = false;
			(odalar + j)->ozelTemizlik = false;
			(odalar + j)->gunlukOdaFiyati = 3000;
			(odalar + j)->doluMu = false;
		}
		int z = a;
		for (b = (bOdaSayisi + a); z < b; z++)
		{
			(odalar + z)->odaNo = "B-" + to_string(z + 10);
			(odalar + z)->odaTuru = "B";
			(odalar + z)->odaKisiKapasitesi = 3;
			(odalar + z)->temizlik = true;
			(odalar + z)->araTemizlik = false;
			(odalar + z)->ozelTemizlik = false;
			(odalar + z)->gunlukOdaFiyati = 4000;
			(odalar + z)->doluMu = false;
		}
		int x = b;
		for (c = (cOdaSayisi + b); x < c; x++)
		{
			(odalar + x)->odaNo = "C-" + to_string(x + 10);
			(odalar + x)->odaTuru = "C";
			(odalar + x)->odaKisiKapasitesi = 5;
			(odalar + x)->temizlik = true;
			(odalar + x)->araTemizlik = false;
			(odalar + x)->ozelTemizlik = false;
			(odalar + x)->gunlukOdaFiyati = 5000;
			(odalar + x)->doluMu = false;
		}
		odaOlustur(odalar);
	}

	//ODAYI TXT DOSYASI OLARAK ACIP ÝCÝNE BÝLGÝLERÝ YAZILDI
	void odaOlustur(Oda* o)
	{
		string data;
		string txtAdi;
		for(int i=0;i<toplamOdaSayisi;i++)
		{
			txtAdi = (o + i)->odaNo;
			createFile(txtAdi); //dosya olustu
			data = "---------------------------"
				"\nODA NO:" + (o + i)->odaNo
				+ "\nODA TURU:" + (o + i)->odaTuru
				+ "\nODA KAPASITE:" + to_string((o + i)->odaKisiKapasitesi)
				+ "\nGUNLUK FIYAT:" + to_string((o + i)->gunlukOdaFiyati)
				+ "\nDOLULUK :" + to_string((o + i)->doluMu)
				+ "\nTEMIZLIK:" + to_string((o + i)->temizlik)
				+ "\nARA TEMIZLIK:" + to_string((o + i)->araTemizlik)
				+ "\n---------------------------\n";
			writeToFile(txtAdi, data); //dosyaya yazildi
		}
	}

	//TXT DOSYASÝ AÇMA ÝÞLEMÝ
	void createFile(string fileName)
	{
		string dosyaUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Odalar\\" +fileName +".txt";
		ofstream file(dosyaUrl);
		file.close();
		cout << "Dosya olustu" << endl;
	}


	//DOSYA YAZMA ÝÞLEMÝ
	void writeToFile(string fileName, string data)
	{
		string dosyaUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Odalar\\" + fileName + ".txt";
		ofstream file(dosyaUrl);
		file << data;
		file.close();
	}
};

