#include<iostream>
#include<fstream>
#include<string>
#ifndef ISLEMGECMISI_H
#define ISLEMGECMISI_H

using namespace std;

class IslemGecmisi
{
public:
	void islemGecmisiYazdir(string url)
	{
		cout << "------ ISLEM GECMISLERI ------" << endl;
		ifstream read(url);
		string line;
		int i = 1;
		while(getline(read,line))
		{
			cout << i << "# " << line << endl;
			i++;
		}
		read.close();
	}
};

#endif 