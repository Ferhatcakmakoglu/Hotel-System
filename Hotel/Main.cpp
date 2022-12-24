#include <iostream>
#include "Turizm.h"
#include "Kupon.h"
#include "Muhasebe.h"
//#include "OdaOlustur.h"
#include "OdaIslem.h"
#include "Node.h"
#include "IslemGecmisi.h"
#include "Hizmet.h"
#include "Personel.h"
#include "KisiIclal.h"
using namespace std;

int main()
{
	/*
		//DEFAULT 100 ODA OLUSTURULDU VE BÝRDAHA CALISMAMAK ÜZRE KAPATILDI

		OdaOlustur* o = new OdaOlustur();
		o->odaTanimlama();
	*/
	


	Kupon* kupon = new Kupon();
	Turizm* turizm = new Turizm();
	Muhasebe* muhasebe = new Muhasebe();
	OdaIslem* odaIslem = new OdaIslem();
	IslemGecmisi* islemGecmisi = new IslemGecmisi();
	Hizmet* hizmet = new Hizmet();
	Personel* personel = new Personel();
	KisiIclal* kisi = new KisiIclal();

	string genelIslemGecmisiUrl = "C:\\Users\\Ferhat\\source\\repos\\c\\Hotel\\Data\\islemGecmisi.txt";

	int islem;
	int cd;
	cout << "~ " << turizm->getHotelAdi() << " ~" << endl;
	while(true)
	{
		cout << "#1 Rezervasyon Bolumu\n"
			<< "#2 Muhasebe Bolumu\n"
			<< "#3 Islem Gecmisi\n" 
			<< "#4 Kupon Islemleri\n" 
			<< "#5 Oda Islemleri\n"
			<< "#6 Hizmet Bolumu\n" 
			<< "#7 Personel Bolumu\n" 
			<< "#8 Cikis Islemleri" << endl;
		cout << "Yapmak istediginiz islemi seciniz: ";
		cin >> islem;
		switch(islem)
		{
		case 1:
			turizm->turizmIslem();
			break;
		case 2:
			muhasebe->muhasebeIslem();
			break;
		case 3:
			islemGecmisi->islemGecmisiYazdir(genelIslemGecmisiUrl);
			break;
		case 4:
			kupon->kuponIslem();
			break;
		case 5:
			odaIslem->odaIslemMenu();
			break;
		case 6:
			hizmet->hizmetMenu();
			break;
		case 7:
			personel->personelMenu();
			break;
		case 8:
			kisi->Cikis();
			break;
		default:
			cout << "HATALI TUSLAMA" << endl;
			break;
		}
		cout << "#0 CIKIS\n"
			<< "#9 DEVAM" << ": ";
		cin >> cd;
		if (cd == 0)
			break;
		else
			continue;
	}
	return 0;
}