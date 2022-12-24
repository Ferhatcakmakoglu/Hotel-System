#include <iostream>
#include <fstream>
#include <string> 
#ifndef PERSONEL_H
#define PERSONEL_H


using namespace std;

class Personel {
public:
	friend class MuhasebeP;
	//Personel();
	ifstream personelOku;
	ofstream personelYaz;
	ifstream personelOku2;
	ofstream personelYaz2;

	inline void personelMenu();
	inline void islemGecmisiYaz(string, string);
	inline void personelEkle();
	inline void maasOde();
	inline void mesaiEkle();
	int mesaiUcretleri[500];
	string personelMesaiDuzenleme[500];
	string personelMaaslari[500];
	string personelMaaslari2[500];
	int maasGiderleri[500];

};

void Personel::personelMenu()
{
	int islem;
	cout << endl << "1 - Personel Ekle\n"
		<< "2 - Personel Mesai Ekle\n"
		<< "3 - Personel Maas Ode\n"
		<< "Islem Seciniz: ";
	cin >> islem;
		 
	switch (islem)
	{
	case 1:
		personelEkle();
		break;
	case 2:
		mesaiEkle();
		break;
	case 3:
		maasOde();
		break;
	default:
		cout << "Hatali Tuslama" << endl;
		break;
	}
}

void Personel::personelEkle() {
	string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\personeller.txt";
	string islemGecmisiGenel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
	string islemgecmisiOzel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\personelIslemGecmisi.txt";

	string pAd, pSoyad, pYas, pNo;

	cout << "Eklenecek Personel Adi : ";
	cin >> pAd;
	cout << "Eklenecek Personel Soyadi : ";
	cin >> pSoyad;
	cout << "Eklenecek Personel Yasi : ";
	cin >> pYas;
	cout << "Eklenecek Personel No : ";
	cin >> pNo;

	// ------------------------------------------------------------- // Dosya Tan�mlama ��lemleri

	personelYaz.open(fileUrl, ios::app);
	personelOku.open(fileUrl, ios::in);

	// ------------------------------------------------------------- // Dosyaya Yazma ��lemleri

	personelYaz2.open(pAd + pSoyad + ".txt", ios::app);

	personelYaz2 << pAd << " " + pSoyad << endl << "--------------------------" << endl << "PersonelNo:" << pNo << endl
		<< "PersonelYas:" << pYas << endl << "PersonelMesaiUcreti:" << "0" << endl << "--------------------------" << endl;
	personelYaz << pAd << " " + pSoyad << endl;

	personelYaz2.close();
	personelYaz.close();
	personelOku.close();

	cout << "ISE ADLIM BASARILI" << endl;
	string data = "[PERSONEL ALIMI]  ID --> " + pNo + " [" + pAd + " " + pSoyad + " - " + pYas + "]";
	islemGecmisiYaz(islemGecmisiGenel, data);
	islemGecmisiYaz(islemgecmisiOzel, data);
}


void Personel::mesaiEkle() {
	string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\personeller.txt";
	string pAd, pSoyad, veri, toplamMesaiStr;
	int sayac = 0;
	int index, ucret, mesaiSaati, toplamMesai, mesaiSecim, adSoyadSecim, satirSayisi = 0;


	personelYaz.open(fileUrl, ios::app);
	personelOku.open(fileUrl, ios::in);


	// ------------------------------------------------------------- // Personel Ad Soyadlar� Diziye Al�n�yor
	if (personelOku.is_open()) {
		while (!personelOku.eof()) {								// Dosya sonuna ula��p ula�amad���n� g�sterir
			personelOku >> veri;
			personelMesaiDuzenleme[sayac] = veri;
			sayac++;
		}
	}
	sayac--;	// eleman say�s� ve sayac ayn� ama index olarak kullanmak istedi�imiz i�in -- yapt�k

	// ------------------------------------------------------------- // Personel Ad Soyadlar� Ekrana Bas�l�yor
	int j = 0;
	for (int i = 0; i < sayac; i++) {
		if ((i % 2 == 0) && (i != 0))
		{
			cout << endl;
		}
		if (i % 2 == 0)
		{
			cout << (j + 1) << "-";
			j++;
		}
		cout << personelMesaiDuzenleme[i] << " ";
	}
	cout << endl;

	// ------------------------------------------------------------- // Mesai Ekleme Bilgileri
	cout << "Mesai eklemek istedigin kisinin numarasi : ";
	cin >> index;
	--index;
	cout << "Kac saat mesai eklemek istiyorsunuz ? ";
	cin >> mesaiSaati;
	cout << "Mesai saatlik ucreti : ";
	cin >> ucret;

	// ------------------------------------------------------------- // Personel Ad� Soyad� indexle diziden �ekilip txt dosyas�na ad soyad olarak veriliyor.
	if (index == 0)
		adSoyadSecim = 0;
	else
		adSoyadSecim = (index * 2);

	string urlPerson = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\" + personelMesaiDuzenleme[adSoyadSecim] + personelMesaiDuzenleme[adSoyadSecim + 1] + ".txt";
	
	personelOku2.open(urlPerson , ios::in);
	personelYaz2.open(urlPerson , ios::app);


	// ------------------------------------------------------------- // Mesai Eklenecek Ki�inin Dosyas�ndaki Elemanlar� Diziye Alma ��lemi
	if (personelOku2.is_open()) {
		sayac = 0;
		while (!personelOku2.eof()) {								// Dosya sonuna ula��p ula�amad���n� g�sterir
			personelOku2 >> veri;									// Dosyadaki elemanlar� teker teker al�p veri de�i�kenine at�yor
			personelMesaiDuzenleme[sayac] = veri;					// Veri de�i�kenindeki dosya elemanlar�n� diziye at�yor
			sayac++;
		}
	}

	//if (index == 0)
	//	mesaiSecim = 5;
	//else
	//	mesaiSecim = 5 + (index * 7);

	toplamMesai = (mesaiSaati * ucret);

	toplamMesaiStr = to_string(toplamMesai);						// String dizisine atama yapaca��m�z i�in mesai�cretini stringe �eviriyoruz
	personelMesaiDuzenleme[5] = "PersonelMesaiUcreti:" + toplamMesaiStr;		//Mesai �cretini dosyadaki forma uygun hale getiriyoruz


	// ------------------------------------------------------------- // Mesai Ekleyece�imiz Ki�inin Verilerini Tekrardan Dosyaya Yazd�r�yoruz

	/*personelYaz2 << personelMesaiDuzenleme[0] << " " + personelMesaiDuzenleme[1]
		<< endl << "--------------------------" << endl << personelMesaiDuzenleme[3] << endl
		<< personelMesaiDuzenleme[4] << endl << personelMesaiDuzenleme[5]
		<< endl << "--------------------------" << endl;*/

	personelYaz2 << personelMesaiDuzenleme[adSoyadSecim]
		<< endl << "--------------------------" << endl
		<< personelMesaiDuzenleme[5]
		<< endl << "--------------------------" << endl;

	personelOku2.close();
	personelYaz2.close();
	personelYaz.close();
	personelOku.close();
	cout << "Mesai Basariyla Eklenmistir" << endl;

	string islemGecmisiGenel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
	string islemgecmisiOzel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\personelIslemGecmisi.txt";


	string islemGecmisiMesaji = personelMesaiDuzenleme[adSoyadSecim] +" ADLI PERSONELE --> Mesai Saati: " + to_string(mesaiSaati) + " Ucreti: " +to_string(ucret) + " Verilmistir";
	islemGecmisiYaz(islemGecmisiGenel, islemGecmisiMesaji);
	islemGecmisiYaz(islemgecmisiOzel, islemGecmisiMesaji);

}




void Personel::maasOde() {
	string fileUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\personeller.txt";
	
	personelYaz.open(fileUrl, ios::app);
	personelOku.open(fileUrl, ios::in);
	int sayac = 0;
	string veri;
	int index, adSoyadSecim;
	bool odensinMi = true;


	if (personelOku.is_open()) {
		while (!personelOku.eof()) {
			//if (sayac % 2 == 0 && sayac != 0) {	// Okurken Alt sat�ra ge�mesi i�in
			//	cout << endl;
			//}
			//else if ((sayac % 1 == 0 ) && (sayac != 0)) {	// okurken elemanlar aras�nda bo�luk b�rakmas� i�in
			//	cout << "  ";
			//}
			personelOku >> veri;
			personelMaaslari[sayac] = veri;
			sayac++;
		}
	}
	sayac--;
	int j = 0;
	for (int i = 0; i < sayac; i++) {
		if ((i % 2 == 0) && (i != 0))
		{
			cout << endl;
		}
		if (i % 2 == 0)
		{
			cout << (j + 1) << "-";
			j++;
		}
		cout << personelMaaslari[i] << " ";
	}



	int maasTutari;

	cout << endl;
	cout << "Maas Odenecek Personel No : ";
	cin >> index;
	cout << "Tutar: ";
	cin >> maasTutari;
	index--;
	if (index == 0)
		adSoyadSecim = 0;
	else
		adSoyadSecim = (index * 2);

	string urlPerson = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\" + personelMaaslari[adSoyadSecim] + personelMaaslari[adSoyadSecim + 1] + ".txt";


	personelOku2.open(urlPerson, ios::in);
	personelYaz2.open(urlPerson, ios::app);


	// ------------------------------------------------------------- // Mesai Eklenecek Ki�inin Dosyas�ndaki Elemanlar� Diziye Alma ��lemi
	if (personelOku2.is_open()) {
		sayac = 0;
		while (!personelOku2.eof()) {								// Dosya sonuna ula��p ula�amad���n� g�sterir
			personelOku2 >> veri;									// Dosyadaki elemanlar� teker teker al�p veri de�i�kenine at�yor
			personelMaaslari2[sayac] = veri;					// Veri de�i�kenindeki dosya elemanlar�n� diziye at�yor
			sayac++;
		}
	}

	cout << personelMaaslari2[5] << endl;
	cout << "Mesai Ucreti Odensin Mi ? // 1 - Evet // 0 - Hayir " << endl;
	cin >> odensinMi;
	if (odensinMi == true)
		personelMaaslari2[5] = "Ucret:"+to_string(maasTutari);


	// ------------------------------------------------------------- // Mesai Ekleyece�imiz Ki�inin Verilerini Tekrardan Dosyaya Yazd�r�yoruz

	personelYaz2 << personelMaaslari2[adSoyadSecim]
		<< endl << "--------------------------" << endl <<  personelMaaslari2[5]
		<< endl << "--------------------------" << endl;


	personelYaz2.close();
	personelOku2.close();
	personelYaz.close();
	personelOku.close();
	
	string islemGecmisiGenel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";
	string islemgecmisiOzel = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\Personel\\personelIslemGecmisi.txt";

	
	string islemGecmisiMesaji = personelMaaslari2[adSoyadSecim] + " ADLI PERSONELE --> Maas Odemesi: " + to_string(maasTutari) ;
	islemGecmisiYaz(islemGecmisiGenel, islemGecmisiMesaji);
	islemGecmisiYaz(islemgecmisiOzel, islemGecmisiMesaji);
}


void Personel::islemGecmisiYaz(string url,string data)
{
	ofstream write(url, ios::app);
	write << data << endl;
	write.close();
}

class MuhasebeP {
public:
	int personelMaas;
	int personelEkMesai;
};

#endif // !PERSONEL_H