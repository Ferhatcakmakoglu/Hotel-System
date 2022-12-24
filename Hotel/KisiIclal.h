#include<iostream>
#include<fstream>
#include<string>
#include "OdaIslem.h"

#ifndef KISIICLAL_H
#define KISIICLAL_H

using namespace std;
class KisiIclal {
public:
	string adi;
	string soyadi;
	string tc;
	string cinsiyet;
	void olustur(){}
	inline void dosyayaYaz(string,string);
	inline void dosyaOlustur(string);
	inline void dosyaSil(string);
	inline void Giris(string,int);
	inline void Cikis();
	
	string odaNo;
	int odaKisiKapasitesi;
	int gunlukOdaFiyati;
	bool temizMi;
	bool doluMu;
	string odaturu;

	KisiIclal()
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
			yaz << adým->data;
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

	void writeToTxt(string odaNoUrl, string data)
	{
		
		ofstream write(odaNoUrl, ios::app);
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


class Atipi_oda : public KisiIclal
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	KisiIclal* taKisi;




	void olustur(string odaNo)
	{
		
		KisiBilgileri = new NodeIclal();
		taKisi = new KisiIclal[2];
		
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


	void writeToTxt(KisiIclal* kisi, string url, int i)
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

class Btipi_oda : public KisiIclal
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	KisiIclal* taKisi;
	



	void olustur(string odaNo)
	{
		KisiBilgileri = new NodeIclal();
		taKisi = new KisiIclal[3];

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


	void writeToTxt(KisiIclal* kisi, string url, int i)
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

class Ctipi_oda : public KisiIclal //5 kiþilik oda
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	KisiIclal* taKisi;



	void olustur(string odaNo)
	{
		KisiBilgileri = new NodeIclal();
		taKisi = new KisiIclal[5];

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


	void writeToTxt(KisiIclal* kisi, string url, int i)
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

class VIPtipi_oda : public KisiIclal
{
public:
	NodeIclal* KisiBilgileri;
	NodeIclal* OdaBilgileri;
	KisiIclal* taKisi;



	void olustur(string odaNo)
	{
		KisiBilgileri = new NodeIclal();
		taKisi = new KisiIclal[1];

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


	void writeToTxt(KisiIclal* kisi, string url, int i)
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

void KisiIclal::Giris(string odaNo,int secim)
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


void KisiIclal::Cikis()
{
	OdaIslem* odaIslem = new OdaIslem();
	string odaNo;
	string odaNoUrl;

	//Dolu Odalarý Listeledik
	odaIslem->doluOdaListele();
	cout << "Lutfen Cikis Yapacaginiz Odanin No'sunu yaziniz: ";
	cin >> odaNo;

	//Odanýn dolu mu bos mu oldugu kontrol edildi
	if(odaIslem->getOdaDoluluk(odaNo) == 1)
	{
		odaNoUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\tumOdalar\\" + odaNo + ".txt";
		
		NodeIclal* dosyaDatasi = new NodeIclal();
		ifstream read(odaNoUrl);
		string line;
		int i = 0;

		//DOLU ODANIN DATALARINI LÝNKEDLIST E ALDIK. DOLU ODAYI BOÞ HALE GETÝRDÝK
		while(getline(read,line))
		{
			if((i != 9) && (i != 5)) // dosyalardaki 8 indisi alýyoruz, 5in sebebi 5. indis doluluk. Orasi degisecek
			{
				dosyaDatasi->ekle(dosyaDatasi, line+"\n");
			}
			else if((i != 9) && (i == 5))
			{
				string doluluk = "DOLULUK :0";
				dosyaDatasi->ekle(dosyaDatasi, doluluk+"\n");
			}
			else
			{
				break;
			}
			i++;
		}
		read.close();
		dosyaSil(odaNoUrl); // odayi sildik
		
		//aldýgýmýz linkedlist datalarýni ozel fonk. ile dosyaya yazdýk
		dosyaDatasi->NodeIclalDosyayaYazdýr(dosyaDatasi, odaNoUrl);
		cout << "Cikis islemi Basarili, Bizi Tercih Ettiginiz icin Tesekkurler :)" << endl;
	
		string islemGecmisiTxtOzel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Oda\\odaIslemGecmisi.txt";
		string islemGecmisiTxtGenel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
		string islemgecmisiMesaji = odaNo + " Hotelden Cikis Yapti";

		//islem gecmisine yazildi
		dosyayaYaz(islemGecmisiTxtGenel, islemgecmisiMesaji);
		dosyayaYaz(islemGecmisiTxtOzel, islemgecmisiMesaji);
	
	}
	else
	{
		cout << "Yazilan Oda Dolu Defil!!" << endl;
	}

}


void KisiIclal::dosyaOlustur(string url)
{
	ofstream create(url, ios::app);
	create.close();
}



void KisiIclal::dosyaSil(string url)
{
	const int result = remove(url.c_str());
}

void KisiIclal::dosyayaYaz(string url,string data)
{
	ofstream write(url, ios::app);
	write << data << endl;
	write.close();
}


//
//void Kisi::Cikis()
//{
//	string odaTipi;
//	string odaNo;
//	string kapasite;
//	string url = "C:\\Odalar\\" + odaTipi + "_tipi\\" + odaTipi + "-" + odaNo + ".txt";
//	remove(url.c_str());
//
//	cout << "A || B || C || VIP \n oda tipi seciniz: \n";
//	cin >> odaTipi;
//	cout << "\noda no giriniz: \n";
//	cin >> odaNo;
//
//	if (odaTipi == "A")
//		kapasite = "2";
//
//	else if (odaTipi == "B")
//		kapasite = "3";
//
//	else if (odaTipi == "C")
//		kapasite = "5";
//
//	else if (odaTipi == "VIP")
//		kapasite = "1";
//
//	else
//		cout << "HATALÝ GÝRÝS";
//
//	fstream file;
//	file.open(url);
//	if (file.is_open()) {
//
//		file << "--------------------------- \nODA NO : A\nODA TURU : " + odaTipi + " \nODA KAPASITE : " + kapasite + " \nGUNLUK FIYAT : 3000 \nDOLULUK : 0 \nTEMIZLIK : 1 * nARA TEMIZLIK : 0 \n--------------------------";
//
//	}
//	file.close();
//
//	cout << "--------------------------- Cikis Yapildi-------------------------";
//
//}

#endif