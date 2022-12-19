#include<iostream>
#include<fstream>
#include<string>
#ifndef MUHASEBE_H
#define MUHASEBE_H

using namespace std;
class AbsMuhasebe {
	virtual void gelirHesabi() = 0;
	virtual void giderHesabi() = 0;
	virtual void karZararHesabi() = 0;
};

class FileStream {
	friend class Muhasebe;
public:
	void readFile1(string url, string dosyaTuru = "")
	{
		int toplayici = 0;
		ifstream readUrl(url);
		string line;
		while (getline(readUrl, line))
		{
			toplayici += stoi(line);
		}
		readUrl.close();
		cout << dosyaTuru << " = " << toplayici << endl;
	}
	void readFile2(string url, string dosyaTuru = "")
	{
		int toplayici = 0;
		ifstream readUrl(url);
		string line;
		while (getline(readUrl, line))
		{
			toplayici += stoi(line);
		}
		readUrl.close();
		cout << dosyaTuru << " = " << toplayici << endl;
	}
};

class Muhasebe : public AbsMuhasebe
{
	int toplamGelir;
	int toplamGider;
	int toplamKar;
	string muhasebeDosyaUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Muhasebe\\";
	string genelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
public:
	/*Muhasebe()
	{
		
	}*/
	inline void gelirHesabi();
	inline void giderHesabi();
	inline void karZararHesabi();
	inline void ekGelirEkle();
	inline void ekGiderEkle();
	inline void muhasebeIslem();
	inline void islemGecmisineYaz(string, string);
};

void Muhasebe::muhasebeIslem()
{
	int islem;
	cout << "#1 Gelir Hesabi\n"
		<< "#2 Gider Hesabi\n"
		<< "#3 Kar Zarar Durumu\n" 
		<< "#4 Ek Gelir Ekle\n" 
		<< "#5 Ek Gider Ekle" << endl;
	cout << "Islem seciniz: ";
	cin >> islem;
	switch (islem)
	{
	case 1:
		gelirHesabi();
		break;
	case 2:
		giderHesabi();
		break;
	case 3:
		karZararHesabi();
		break;
	case 4:
		ekGelirEkle();
		break;
	case 5:
		ekGiderEkle();
		break;
	default:
		cout << "Hatali Tuslama" << endl;
		break;
	}
}

void Muhasebe::gelirHesabi()
{
	FileStream* file = new FileStream();
	string urlLoc = muhasebeDosyaUrl.append("gelirler.txt");
	file->readFile1(urlLoc, "GELIRLER");
	delete file;
}

void Muhasebe::giderHesabi()
{
	FileStream* file2 = new FileStream();
	string url = muhasebeDosyaUrl.append("giderler.txt");
	file2->readFile2(url, "GIDERLER");
	delete file2;
}

void Muhasebe::karZararHesabi()
{
	Muhasebe::gelirHesabi();
	Muhasebe::giderHesabi();
	cout << "~ KAR-ZARAR BILANCOSU ~" << endl;
	Muhasebe::toplamKar = toplamGelir+toplamGider;
	cout << "TOPLAM KAR: " << toplamKar << endl;
}

void Muhasebe::ekGelirEkle()
{
	string gelirTuru;
	int gelirTutari;
	cout << "Ek Gelir Turu: ";
	cin >> gelirTuru;
	cout << "Ek Gelir Tutari: ";
	cin >> gelirTutari;

	ofstream write(muhasebeDosyaUrl.append("gelirler.txt"),ios::app);
	write << gelirTutari << endl;
	write.close();

	string islemGecmisiMesaji = "EK GELIR EKLENDI: [ " + gelirTuru + " = " + to_string(gelirTutari) + " ]";
	cout << islemGecmisiMesaji << endl;
	islemGecmisineYaz(genelIslemGecmisiUrl, islemGecmisiMesaji);
	string muhasebeUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Muhasebe\\muhasebeIslemGecmisi.txt";
	islemGecmisineYaz(muhasebeUrl, islemGecmisiMesaji);
}

void Muhasebe::ekGiderEkle()
{
	string giderTuru;
	int giderTutari;
	cout << "Ek Gider Turu: ";
	cin >> giderTuru;
	cout << "Ek Gider Tutari: ";
	cin >> giderTutari;

	ofstream write(muhasebeDosyaUrl.append("giderler.txt"),ios::app);
	write << giderTutari << endl;
	write.close();

	string islemGecmisiMesaji = "EK GIDER EKLENDI: [ " +giderTuru +" = " +to_string(giderTutari) +" ]";
	cout << islemGecmisiMesaji << endl;
	islemGecmisineYaz(genelIslemGecmisiUrl,islemGecmisiMesaji);
	string muhasebeUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Muhasebe\\muhasebeIslemGecmisi.txt";
	islemGecmisineYaz(muhasebeUrl, islemGecmisiMesaji);
}

void Muhasebe::islemGecmisineYaz(string url, string islem)
{
	ofstream write(url, ios::app);
	write << islem << endl;
	write.close();
}



#endif // !MUHASEBE_H