#ifndef _LIST_HPP_
#define _LIST_HPP_
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include<algorithm>

template <typename Object>
class List {
  private:
	struct Node {
	    Object  data;
	    Node   *next;
		Node   *prev;
	};
	int   theSize;
	Node *head;
	Node *tail;

  public:
	List() {
		theSize = 0;
		head = new Node; tail = new Node;
		head->next = tail;
		tail->prev = head;
		head->prev = tail->next = nullptr;
	}

	~List() { clear(); delete head; delete tail; }

	int size() { return theSize; }
	bool empty() { return (size() == 0); }

	void clear();
	void push_front(const Object& x);
	void push_back(const Object& x);
    void insert(const Object& x, int pos);

	Object pop_front();
	Object pop_back();
    Object remove(int pos);
	
	void reverse();
	void print_lst();

	bool find(const Object& x);


    int search(const Object& x);
    int search_helper(Node* current, const Object& x, int pos);
};

// Clear the list
template<typename Object>
void List<Object>::clear()
{
    if (empty()) return;
    // Create pointer to a node, and make it point at first element
    Node* p = head->next;
    while (p != tail) // While p is not equal tail
    {
        // temp variabel to point at the next node after the initial
        Node* t = p->next;
        delete p; // Delete the node from the heap
        p = t; // p points at the next node
        theSize--;
    }
    head->next = tail; // heads next points at tail
    tail->prev = head; // tails prev points at head
}
// Push element to the front of the list
template<typename Object>
void List<Object>::push_front(const Object& x)
{
    Node* temp = head->next; // Temp pointer points at first element
    Node* newNode = new Node{x, head->next, head}; // Initialize newNode
    head->next = newNode; // heads next points at newNode
    temp->prev = newNode; // old first elements prev points at newNode 
    this->theSize++; // increment the size of the lst
}
// Push element to the end of the list
template<typename Object>
void List<Object>::push_back(const Object& x)
{
	Node* temp = tail->prev; // temp pointing at the last element
    Node* newNode = new Node{x, tail, tail->prev};
    temp->next = newNode; // old last node's next points at newnode
    tail->prev = newNode; // tails prev pointing at the newnode
    this->theSize++;
}

template<typename Object>
Object List<Object>::pop_front()
{   
    // If the list is empty, raise an error. 
	if (theSize == 0)
    {
        throw std::underflow_error("List is empty");
    }
   // else 
    Node* temp = head->next; // temp points at the first element
    Object val = std::move(temp->data); // move the data from the element
    
    head->next = temp->next;  // head's next points at the new first node
    temp->next->prev = head; // new first elements prev points at head

    delete temp; // delete the first element
	--theSize;
    return val; // return the poped data
}

template<typename Object>
Object List<Object>::pop_back()
{
	// If the list is empty, raise an error
    if (theSize == 0)
    {
        throw std::underflow_error("List is empty");
    }
    
	Node* temp = tail->prev; // temp points at last element
    Object val = std::move(temp->data); // Move the data from the element
    tail->prev = temp->prev; // tail's prev points at the new last element
    temp->prev->next = tail; // new last element points at tail


    delete temp; // delete the last node 
    --theSize; 
    return val; // return the poped data 
}

template<typename Object>
void List<Object>::insert(const Object& x, int pos)
{
    // If the position is les than 0 or greater than size of list: out of range
    if (pos < 0 || pos > theSize)
    {
        throw std::out_of_range("Out of bound"); 
    } 
	
	if (pos == theSize)
	{
		push_back(x);
		return;
	}
	if(pos == 0)
	{
		push_front(x);
		return;
	}
	
	Node* temp; // Declare temp node pointer

	// If the pos is greater than half the size: start from tail
	if(pos >= theSize/2) 
	{
		int current = theSize - 1; // counter to keep track on current pos/index
		temp = tail->prev; // temp points at the last element
		while (current != pos)
		{
			temp = temp->prev; // Go through the list
			--current;
		}
	}
	// Else start from head
	else
	{
		int current = 0;
		temp = head->next; // temp points at the first element
	
		while (current != pos)
		{
			temp = temp->next;
			++current;
		}
	}

	Node* newNode = new Node{x, temp, temp->prev}; // Create the node
	temp->prev->next = newNode;
	temp->prev = newNode;
	++theSize;
    
}


template<typename Object>
Object List<Object>::remove(int pos)
{
    if (theSize == 0)
    {
        throw std::underflow_error("List is empty");
    }
    else if(pos < 0 || pos >= theSize)
    {
        throw std::out_of_range("Out of bound");
    }

	Node* temp;
   
	if(pos >= theSize/2) 
	{
		int current = theSize - 1; // counter to keep track on current pos/index
		temp = tail->prev; // temp points at the last element
		while (current != pos)
		{
			temp = temp->prev; // Go through the list backwards
			--current; // Decrement current
		}
	}
	else {

		int current = 0;  
		temp = head->next; // temp points at first element
	
		while (current != pos)
		{
			temp = temp->next; // Go through list forward
			++current;
		}
	}

    Object value = std::move(temp->data); // store the value

    temp->prev->next =  temp->next;
    temp->next->prev = temp->prev;

    delete temp;
    --theSize; 
    return value; 

}

template<typename Object>
bool List<Object>::find(const Object& x)
{
    if (theSize == 0)
    {
        return false;
    }
    Node* temp = head->next;
    while (temp != tail)
    {
        if (temp->data == x)
            return true;
        temp = temp->next;
        
    }
    return false;     
}


template<typename Object>
void List<Object>::print_lst()
{
    if (theSize == 0)
    {
        std::cout << "List is empty! No elements to print" << '\n';
        return;
    }
    
    Node* temp = head->next;

    while (temp != tail)
    {
        std::cout << temp->data << '\n';
        temp = temp->next;
    }
    
}


template<typename Object>
void List<Object>::reverse()
{
	if(theSize == 0)
	{
		std::cout << "List is empty! Nothing to reverse0\n";
		return;
	}
	if (theSize == 1)
	{
		return;
	}
	
	Node* temp_left = head->next;
	Node* temp_right = tail->prev;

	while (temp_left != temp_right && temp_left->prev != temp_right)
	{
		Object val = temp_left->data;
		temp_left->data = temp_right->data;
		temp_right->data = val;


		temp_left = temp_left->next;
		temp_right = temp_right->prev; 
	}
	
}


// Method that returns the postion/index of the desired element or -1 if elemenet is not found
template<typename Object>
int List<Object>::search(const Object& x) {
    
    // If list is empty throw an error
    if(theSize == 0){throw::std::underflow_error("List is empty!");}

    return search_helper(head->next, x, 0);
}

template<typename Object>
int List<Object>::search_helper(Node* current, const Object& x, int pos){

    // If currents next is tail return -1
    if(current == tail){return -1;}
    // If currents data is x return position
    if(current->data == x){return pos;}
    // recursive call
    return search_helper(current->next, x, pos + 1);
}


#endif