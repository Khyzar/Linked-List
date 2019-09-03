#include"dlist_wh.h"

template<typename t>
linked_list<t>::linked_list()
{
	tail=new node<t>;
	head=new node<t>(0, tail, NULL);
	tail->prev=head;
}
template<typename t>
linked_list<t>::linked_list(Iterator s1, Iterator s2)
{
	node<t>* curr, *temp;
	curr=s1.curr;
	tail=new node<t>;
	head=new node<t>;
	head->next=new node<t>(curr->data, curr->next,NULL);
	temp=head->next;
	while(curr!=s2.curr)
	{
		curr=curr->next;
		temp->next=new node<t>(curr->data, tail, temp);
		temp=temp->next;
	}
}
template <typename t>
void linked_list<t>::insert(const t & _data)
{
	node<t> *temp=NULL;
	temp=find_(_data);
	if(temp==head)
	{
		head->next=new node<t>(_data,tail,head);
	}
	else
		temp->next=new node<t>(_data,tail,temp);
}
template<typename t>
node<t> *linked_list<t>::find_(const t & _data)
{
	node<t> *curr1=head->next, *prev1=head;
	while(curr1!=tail)
	{
		prev1=curr1;
		curr1=curr1->next;

	}
	return prev1;
}
template <typename t>
bool linked_list<t>::delete_(const t &_data)
{
	node<t> *curr1=head->next, *prev1=head;
	while(curr1!=NULL)
	{
		if(curr1->data==_data)
			break;
		prev1=curr1;
		curr1=curr1->next;
	}
	if(curr1==NULL)
		return false;
	prev1->next=curr1->next;
	curr1->next->prev=curr1->prev;
	delete curr1;
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
	node<t> *curr1;
	friend linked_list<t>;
	Iterator(node<t> *ptr)	
	{
		curr1=ptr;
	}
public:
	Iterator()
	{
		curr1= NULL;
	}
	Iterator& operator++()
	{
		curr1=curr1->next;
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
		if(this->curr1==a.curr1)
			return false;
		return true;
	}
	t& operator*()
	{
		return curr1->data;
	}
};
