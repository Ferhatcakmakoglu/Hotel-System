#include<iostream>
#include<fstream>
#include<string>
#ifndef NodeIclal_H
#define NodeIclal_H

using namespace std;
class Kisi {
public:
	string adi;
	string soyadi;
	string tc;
	string cinsiyet;
	void olustur(){}
	inline void dosyayaYaz(string url, string data);
	inline void Giris(string,int);
	inline void Cikis();
	string odaNo;
	int odaKisiKapasitesi;
	int gunlukOdaFiyati;
	bool temizMi;
	bool doluMu;
	string odaturu;

	Kisi()
	{
		this->doluMu = false;
		this->temizMi = true;
	}

};

class NodeIclal
{
	string data;
	NodeIclal* sonraki;
public:

	NodeIclal()
	{
		this->sonraki = NULL;
	}

	void ekle(NodeIclal* bas, string datam)
	{
		if (bas->data == "")
		{
			bas->data = datam;
			bas->sonraki = NULL;
		}
		else
		{
			NodeIclal* adým = bas;
			NodeIclal* yeni_NodeIclal = new NodeIclal();
			yeni_NodeIclal->data = datam;
			while (adým->sonraki != NULL)
			{
				adým = adým->sonraki;
			}
			yeni_NodeIclal->sonraki = NULL;
			adým->sonraki = yeni_NodeIclal;
		}
	}

	void yazdýr() // listeyi yazdýrýr
	{
		NodeIclal* bas;
		NodeIclal* adým = bas;
		while (adým != NULL)
		{
			cout << adým->data << endl;
			adým = adým->sonraki;
		}
	}

	void NodeIclalDosyayaYazdýr(NodeIclal* bas, string url) // listeyi .txt ye yazdýrýr
	{
		ofstream yaz(url, ios::app); //sondan eklesin diye
		NodeIclal* adým = bas;
		while (adým != NULL)
		{
			yaz << adým->data << endl;
			adým = adým->sonraki;
		}
		yaz.close();
	}

	void print(NodeIclal* head)
	{
		NodeIclal* temp = head;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->sonraki;
		}
	}

	void writeToTxt(string url, string data)
	{
		string fileUrl = "C:\\Odalar\\A_tipi\\" + url + ".txt";
		ofstream write(fileUrl, ios::app);
		write << data << endl;
		write.close();
	}

	//deneme amaçlý oluþturuldu
	//void print(Kisi* Kisi, int i)
	//{
	//	string url[] = {"A-110"};
	//	string data;
	//	for (int j = 0; j < i; j++)
	//	{
	//		data = (Kisi + j)->adi + " "
	//			+ (Kisi + j)->soyadi + " "
	//			+ (Kisi + j)->tc + " "
	//			+ (Kisi + j)->cinsiyet;
	//		writeToTxt(url[j],data);
	//	}
	//}

};

#endif // !NodeIclal_H
class Atipi_oda : public Kisi
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	Kisi* taKisi;




	void olustur(string odaNo)
	{
		
		KisiBilgileri = new NodeIclal();
		taKisi = new Kisi[2];
		
		for (int j = 0; j < 2; j++)
		{
			cout << "ADI: ";
			cin >> (taKisi + j)->adi;
			cout << "SOYADI: ";
			cin >> (taKisi + j)->soyadi;
			cout << "TC: ";
			cin >> (taKisi + j)->tc;
			cout << "CINSIYET: ";
			cin >> (taKisi + j)->cinsiyet;

		}
		cout << "--------------------------- Odaya Giriþ Yapildi-------------------------" << endl;
		writeToTxt(taKisi, odaNo, 2);
	}


	void writeToTxt(Kisi* kisi, string url, int i)
	{
		string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + url + ".txt";
		ofstream write(fileUrl, ios::app);
		string dataKisi;
		for (int j = 0; j < i; j++)
		{
			dataKisi = "ADI SOYADI: " + (kisi + j)->adi + " " + (kisi + j)->soyadi + " "
				+ "\nCINSIYET: " + (kisi + j)->cinsiyet + " " + " \nTC NO: " + (kisi + j)->tc + "\n";
			write << dataKisi << endl;
		}
		write << "---------------------------" << endl;
		write.close();
	}
};

class Btipi_oda : public Kisi
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	Kisi* taKisi;
	



	void olustur(string odaNo)
	{
		KisiBilgileri = new NodeIclal();
		taKisi = new Kisi[3];

		for (int j = 0; j < 3; j++)
		{
			cout << endl;
			cout << "ADI: ";
			cin >> (taKisi + j)->adi;
			cout << "SOYADI: ";
			cin >> (taKisi + j)->soyadi;
			cout << "TC: ";
			cin >> (taKisi + j)->tc;
			cout << "CINSIYET: ";
			cin >> (taKisi + j)->cinsiyet;

		}
		cout << "--------------------------- Odaya Giris Yapildi-------------------------" << endl;
		writeToTxt(taKisi, odaNo, 3);
	}


	void writeToTxt(Kisi* kisi, string url, int i)
	{
		string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + url + ".txt";
		ofstream write(fileUrl, ios::app);
		string dataKisi;
		for (int j = 0; j < i; j++)
		{
			dataKisi = "ADI SOYADI: " + (kisi + j)->adi + " " + (kisi + j)->soyadi + " "
				+ "\nCINSIYET: " + (kisi + j)->cinsiyet + " " + " \nTC NO: " + (kisi + j)->tc + "\n";
			write << dataKisi << endl;
		}
		write << "---------------------------" << endl;
		write.close();
	}
};

class Ctipi_oda : public Kisi //5 kiþilik oda
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	Kisi* taKisi;



	void olustur(string odaNo)
	{
		KisiBilgileri = new NodeIclal();
		taKisi = new Kisi[5];

		for (int j = 0; j < 5; j++)
		{
			cout << endl;
			cout << "ADI: ";
			cin >> (taKisi + j)->adi;
			cout << "SOYADI: ";
			cin >> (taKisi + j)->soyadi;
			cout << "TC: ";
			cin >> (taKisi + j)->tc;
			cout << "CINSIYET: ";
			cin >> (taKisi + j)->cinsiyet;

		}
		cout << "--------------------------- Odaya Giris Yapildi-------------------------" << endl;
		writeToTxt(taKisi, odaNo, 5);
	}


	void writeToTxt(Kisi* kisi, string url, int i)
	{
		string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + url + ".txt";
		ofstream write(fileUrl, ios::app);
		string dataKisi;
		for (int j = 0; j < i; j++)
		{
			dataKisi = "ADI SOYADI: " + (kisi + j)->adi + " " + (kisi + j)->soyadi + " "
				+ "\nCINSIYET: " + (kisi + j)->cinsiyet + " " + " \nTC NO: " + (kisi + j)->tc + "\n";
			write << dataKisi << endl;
		}
		write << "---------------------------" << endl;
		write.close();
	}
};

class VIPtipi_oda : public Kisi
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	Kisi* taKisi;



	void olustur(string odaNo)
	{
		KisiBilgileri = new NodeIclal();
		taKisi = new Kisi[1];

		for (int j = 0; j < 1; j++)
		{
			cout << endl;
			cout << "ADI: ";
			cin >> (taKisi + j)->adi;
			cout << "SOYADI: ";
			cin >> (taKisi + j)->soyadi;
			cout << "TC: ";
			cin >> (taKisi + j)->tc;
			cout << "CINSIYET: ";
			cin >> (taKisi + j)->cinsiyet;

		}
		cout << "--------------------------- Odaya Giris Yapildi-------------------------" << endl;
		writeToTxt(taKisi, odaNo, 1);
	}


	void writeToTxt(Kisi* kisi, string url, int i)
	{
		string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + url + ".txt";
		ofstream write(fileUrl, ios::app);
		string dataKisi;
		for (int j = 0; j < i; j++)
		{
			dataKisi = "ADI SOYADI: " + (kisi + j)->adi + " " + (kisi + j)->soyadi + " "
				+ "\nCINSIYET: " + (kisi + j)->cinsiyet + " " + " \nTC NO: " + (kisi + j)->tc + "\n";
			write << dataKisi << endl;
		}
		write << "---------------------------" << endl;
		write.close();
	}
};

void Kisi::Giris(string odaNo,int secim)
{
	Atipi_oda* a = new Atipi_oda();
	Btipi_oda* b = new Btipi_oda();
	Ctipi_oda* c = new Ctipi_oda();
	VIPtipi_oda* V = new VIPtipi_oda();

	int odaFiyati;
	int toplamGelir = 0;
	switch (secim)
	{
	case 1: // A TÝPÝ
		a->olustur(odaNo);
		odaFiyati = 3000;
		toplamGelir = toplamGelir + odaFiyati;
		break;
	case 2:// B TÝPÝ
		b->olustur(odaNo);
		odaFiyati = 5000;
		toplamGelir = toplamGelir + odaFiyati;
		break;
	case 3:// C TÝPÝ
		c->olustur(odaNo);
		odaFiyati = 7000;
		toplamGelir = toplamGelir + odaFiyati;
		break;
	case 4:// VIP TÝPÝ
		V->olustur(odaNo);
		odaFiyati = 15000;
		toplamGelir = toplamGelir + odaFiyati;
		break;
	default:
		cout << "Hatali Tuslama" << endl;
		break;
	}

}


void Kisi::Cikis()
{
	string odaTipi;
	string odaNo;
	string kapasite;
	string url = "C:\\Odalar\\" + odaTipi + "_tipi\\" + odaTipi + "-" + odaNo + ".txt";
	remove(url.c_str());

	cout << "A || B || C || VIP \n oda tipi seciniz: \n";
	cin >> odaTipi;
	cout << "\noda no giriniz: \n";
	cin >> odaNo;

	if (odaTipi == "A")
		kapasite = "2";

	else if (odaTipi == "B")
		kapasite = "3";

	else if (odaTipi == "C")
		kapasite = "5";

	else if (odaTipi == "VIP")
		kapasite = "1";

	else
		cout << "HATALÝ GÝRÝS";

	fstream file;
	file.open(url);
	if (file.is_open()) {

		file << "--------------------------- \nODA NO : A\nODA TURU : " + odaTipi + " \nODA KAPASITE : " + kapasite + " \nGUNLUK FIYAT : 3000 \nDOLULUK : 0 \nTEMIZLIK : 1 * nARA TEMIZLIK : 0 \n--------------------------";

	}
	file.close();

	cout << "--------------------------- Cikis Yapildi-------------------------";

}

