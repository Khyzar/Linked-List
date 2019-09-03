#ifndef SLIST_H
#define SLIST_H

#include<iostream>
using namespace std;

template<typename t>
struct node
{
	t data;
	node<t> *next;
	node(){data=0; next=NULL;}
	node(node<t>& n)
	{
		data=n.data;
		next=n.next;
	}
	node operator =(const node<t> & n)
	{
		data=n.data;
		next=n.next;
	}
	node(t _data, node<t> *_next){data=_data; next=_next;}
};


template <typename t>
class linked_list
{
private:
	node<t> *head;
	node<t> *tail;
public:
	linked_list();
	class Iterator;
	linked_list(Iterator, Iterator);
	Iterator start(){return Iterator(head);}
	Iterator end(){return Iterator(tail);}
	void insert(const t &);
	node<t> *find_(const t &);
	void PrintList ();
	bool delete_(const t &);
	~linked_list()
	{
		node<t>* curr=head, *prev=head;
		while(curr!=tail)
		{
			prev=curr;
			curr=curr->next;
			delete prev;
		}
		delete tail;
	}
	
};
#endif
