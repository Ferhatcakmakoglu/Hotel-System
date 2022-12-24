#include<iostream>
#ifndef EXCEPTIONHANDLING_H
#define EXCEPTIONHANDLING_H


using namespace std;


class ExceptionHandling
{
public:
	void printFileException(string err)
	{
		cout << "DOSYA HATASI: " + err << endl;
	}

	void printPersonException(string err)
	{
		cout << "PERSONEL ISLEM HATASI: " + err << endl;
	}

	void printNamingError(string err)
	{
		cout << "ISIMLENDIRME HATASI: " + err << endl;
	}
};

#endif // !EXCEPTIONHANDLING_H