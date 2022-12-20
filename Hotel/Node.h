#include<iostream>
#include<fstream>
#ifndef NODE_H
#define NODE_H

using namespace std;
class Node
{
	string data;
	Node* next;
public:
	string silinecekData;
	Node()
	{
		this->next = NULL;
	}

	void add(Node* head, string myData)
	{
		if (head->data == "")
		{
			head->data = myData;
			head->next = NULL;
		}
		else
		{
			Node* temp = head;
			Node* new_node = new Node();
			new_node->data = myData;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			new_node->next = NULL;
			temp->next = new_node;
		}
	}

	void print(Node* head)
	{
		Node* temp = head;
		while(temp != NULL)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}

	void remove(Node* head, int id)
	{

		int i = 0;
		Node* temp = head;
		Node* prev = head;

		while(temp != NULL)
		{
			if(i == id)
			{
				string data = temp->data;
				setSilinecekData(data); //silinecek datanýn ismini kaydettik
				temp = temp->next; //silinecek datanin onune gecmesi icin, sonrasýnda prev ile baglanacak
				break;
			}
			if( i + 1 != id)
			{
				prev = prev->next; //silinecek datanýn bir öncesinde kalmasý için
			}
			temp = temp->next;
			i++;
		}
		prev->next = temp; 
		/*
			prev = silinecekData nýn öncesinde
			temp = silinecekData onunda
			previn next i ile silinecekDatanýn kendisi ve sonraki elemanlarý birbirine baglandý
		*/
	}

	void writeNodeToFile(Node* head, string url)
	{
		ofstream write(url, ios::app);
		Node* temp = head;
		while (temp != NULL)
		{
			write << temp->data << endl;
			temp = temp->next;
		}
		write.close();
	}

	void setSilinecekData(string data)
	{
		this->silinecekData = data;
	}

	string getSilinecekData()
	{
		return silinecekData;
	}

};

#endif // !NODE_H