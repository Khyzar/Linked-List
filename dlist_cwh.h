#ifndef DLIST_CWH_H
#define DLIST_CWH_H
#include<iostream>
using namespace std;

template<typename t>
struct node
{
	t data;
	node<t> *next;
	node<t> *prev;
	node(){data=0; next=NULL; prev=NULL;}
	node(node<t>& n)
	{
		data=n.data;
		next=n.next;
		prev=n.prev;
	}
	node operator =(const node<t> & n)
	{
		data=n.data;
		next=n.next;
		prev=n.prev;
	}
	node(t _data, node<t> *_next,node<t> *_prev){data=_data; next=_next; prev=_prev;}
};

template<typename t>
class linked_list
{
private:
	node<t> *head;
	node<t> *tail;
public:
	linked_list();
	class Iterator;
	linked_list(Iterator, Iterator);
	Iterator start(){return Iterator(head->next);}
	Iterator end(){return Iterator(tail);}
	void insert(const t &);
	node<t> *find_(const t &);
	void PrintList ();
	bool delete_(const t &);
	~linked_list()
	{
		node<t>* temp1=head->next, *temp2=head->next;
		while(temp1!=tail)
		{
			temp2=temp1;
			temp1=temp1->next;
			delete temp2;
		}
		delete tail;
	}
	
};




#endif