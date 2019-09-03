#include<iostream>
#include"slist_cwh.h"
using namespace std;

template<typename t>
linked_list<t>::linked_list()
{
	tail=new node<t>;
	head=new node<t>(0, tail);
	tail->data=0;
	tail->next=head;
}
template<typename t>
linked_list<t>::linked_list(Iterator s1, Iterator s2)
{
	node<t>* curr, *temp;
	curr=s1.curr;
	tail=new node<t>;
	head=new node<t>;
	head->next=new node<t>(curr->data, tail);
	temp=head->next;
	while(curr!=s2.curr)
	{
		curr=curr->next;
		temp->next=new node<t>(curr->data, tail);
		temp=temp->next;
	}
}
template<typename t>
void linked_list<t>::insert(const t & _data)
{
	node<t> *temp=NULL;
	temp=find_(_data);
	if(temp==head)
	{
		head->next=new node<t>(_data,tail);
	}
	else
		temp->next=new node<t>(_data,tail);

}
template<typename t>
node<t> *linked_list<t>::find_(const t & _data)
{
	node<t> *curr=head->next, *prev=head;
	while(curr!=tail)     
	{
		prev=curr;
		curr=curr->next;
	}
	return prev;

}
template <typename t>
bool linked_list<t>::delete_(const t &_data)
{
	node<t> *curr=head->next, *prev=head;
	while(curr!=NULL)
	{
		if(curr->data==_data)
			break;
		prev=curr;
		curr=curr->next;
	}
	if(curr==NULL)
		return false;
	prev->next=curr->next;
	delete curr;
	return true;
}
template <typename t>
void linked_list<t>::PrintList ()
{
	node<t> *temp=head->next;
	while(temp!=tail)
	{
		cout<<temp->data<<endl;
		temp=temp->next;
	}
}
template<typename t>
class linked_list<t>::Iterator
	{
	private:
		node<t> *curr;
		friend linked_list<t>;
		Iterator(node<t> *ptr)	
		{
			curr=ptr;
		}
	public:
		Iterator()
		{
			curr= NULL;
		}
		Iterator& operator++()
		{
			curr=curr->next;
			return *this;
		}
		Iterator& operator++(int _a)  //post Increment
		{
			Iterator temp=*this;
			++(*this);
			return temp;
		}
		bool operator!=(Iterator a)  
		{
			if(this->curr==a.curr)
				return false;
			return true;
		}
		t& operator*()
		{
			return curr->data;
		}
	};
