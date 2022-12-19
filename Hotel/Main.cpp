#include <iostream>
#include "Turizm.h"
#include "Kupon.h"
#include "Muhasebe.h"
using namespace std;

int main()
{
	Kupon* kupon = new Kupon();
	Turizm* turizm = new Turizm();
	Muhasebe* muhasebe = new Muhasebe();
	int islem;
	int cd;
	cout << "~ " << turizm->getHotelAdi() << " ~" << endl;
	while(true)
	{
		cout << "#1 Rezervasyon Bolumu\n"
			<< "#2 Muhasebe Bolumu\n"
			<< "#3 Islem Gecmisi\n" 
			<< "#4 Kupon Islemleri" << endl;
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
			//Ýslem Gecmisi
			break;
		case 4:
			kupon->kuponIslem();
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