//=================================================
// Nicolas Nguyen
// List.cpp 
// This file contains the class implementation for the
// Linked List implementation of a List ADT
//=================================================


//=================================================
// default constructor 
//  - Create an empty list
// PARAMETERS: none
// RETURN: none but creates an empty list  
//=================================================
template <class T> 
	List<T>::List		( void )
{
	head = NULL; 
}

//=================================================
// destructor  
//=================================================
template <class T>
	List<T>::~List		( void ) 
{
	Node *nxt; 
	while (head!=NULL)
	{
		nxt = head -> next; 
		delete head; 
		head = nxt; 
	}
}
//=================================================
// append  
// list1.append()
// Appends a new item to the end of the list 
// PARAMTERS: const reference to item
// RETURN: none but appends item to back of list
//=================================================
template <class T> 
void	List<T>::append	( const T &item )
{
	Node *qtr; 
	
	qtr = new Node; 
	qtr -> item = item; 
	qtr -> next = NULL; 
	
	//special case for empty list
	if (head==NULL) 	
	{
		head = qtr; 
	}
	
	// general case of non-empty list 
	else			
	{
		Node *ptr = head;
		while (ptr->next != NULL) //gets to last node but not past it
		{
			ptr = ptr -> next; 
		} 
		ptr->next = qtr; 
	}
}

//=================================================
// copy constructor   
// performs deep copy on a linked list 
// PARAMTERS: const reference to mylist 
// RETURN: none but copies every node of the linked list  
//=================================================
template <class T> 
	List<T>::List		( const List<T> &mylist )
{
	Node *ptr; 		//used to create new node 
	Node *qtr; 		//traverses the to-be-copied list 
	Node *curr; 	//traverses the copy 
	
	if (mylist.head == NULL)
		head = NULL; 
		
	else
	{
		qtr = mylist.head; 
		head = new Node; 			//copy first node
		head -> item = qtr -> item; 
		head -> next = NULL; 
		
		curr = head; 
		qtr = qtr -> next; 
		
		while (qtr!=NULL)
		{
			ptr = new Node; 
			ptr -> item = qtr -> item;
			ptr -> next = NULL;

			curr -> next = ptr; 
			curr = curr -> next; 
			
			qtr = qtr -> next; 
			
		}
	}
}

//=================================================
// isEmpty  
// list1.isEmpty()
// PARAMTERS: none
// RETURN: True if list is empty. False otherwise 
//=================================================
template <class T> 
bool	List<T>::isEmpty		( void ) const
{
	return(head==NULL); 
}


//=================================================
// length  
// list1.length()
// PARAMTERS: none
// RETURN: the number of items in the list 
//=================================================
template <class T> 
int		List<T>::length		( void ) const
{
	int count = 0;  
	Node *ptr = head; 
	while (ptr!=NULL)
	{
		count++; 
		ptr = ptr -> next; 
	}
	return count; 
}


//=================================================
// operator[]  
// list1[2]
// PARAMTERS: int index 
// RETURN: the value at the index specified in the argument
//=================================================
template <class T> 
T &		List<T>::operator[]	( int index )
{
	//Check for invalid index 
	if (index <0 || index>length()-1) throw std::invalid_argument( "Invalid index" ); 

	//access item at desired position 
	Node *get;
	get = head; 
	for (int i=0; i<index; i++)
	{
		get = get -> next; 
	} 
	return (get -> item); 
}


//=================================================
// clear
// list1.clear()
// PARAMTERS: none
// RETURN: none but removes all items from the list
//=================================================
template <class T> 
void	List<T>::clear		( void )
{
	Node *nxt; 
	while (head!=NULL)
	{
		nxt = head -> next; 
		delete head; 
		head = nxt; 
	}
}

//=================================================
// insert
// PARAMTERS: item of type T and an integer index 
// RETURN: none but inserts the item into the 
//		   specified position 
//=================================================
template <class T> 
void	List<T>::insert		( const T &item, int index )
{
	//Check for invalid index 
	if (index <0 || index>length()) throw std::invalid_argument( "Invalid index" );  

	//Inserting at the front 
	if (index == 0)
	{
		Node *ptr;
		ptr = new Node; 
		ptr -> item = item; 
		ptr -> next = head; 
		head = ptr; 
	}

	//Append to the back of the list  
	else if (index == length()) 
		append(item); 
	

	//Inserting in the middle 
	else 
	{
		Node *curr; 
		curr = head; 

		for (int i=0; i<index-1; i++)
		{
			curr = curr -> next; 
		}

		Node *ptr; 
		ptr = new Node; 
		ptr -> item = item; 
		ptr -> next = curr -> next; 
		curr -> next = ptr; 
	}

}


//=================================================
// operator=
// list1 = list2
// PARAMETERS: const reference to mylist 
// RETURN: the calling list with its value replaced
//		   by mylist's
//=================================================
template <class T> 
List<T>	List<T>::operator=	( const List<T> &mylist )
{
	//Deallocating every node (destructor code)
	Node *nxt; 
	while (head!=NULL)
	{
		nxt = head -> next; 
		delete head; 
		head = nxt; 
	}

	//Using copy constructor 
	Node *ptr; 		
	Node *qtr; 		
	Node *curr; 
	
	if (mylist.head == NULL)
		head = NULL; 
		
	else
	{
		qtr = mylist.head; 
		head = new Node; 			//copy first node
		head -> item = qtr -> item; 
		head -> next = NULL; 
		
		curr = head; 
		qtr = qtr -> next; 
		
		while (qtr!=NULL)
		{
			ptr = new Node; 
			ptr -> item = qtr -> item;
			ptr -> next = NULL;

			curr -> next = ptr; 
			curr = curr -> next; 
			
			qtr = qtr -> next; 
			
		}
	}
	return *this; 
}


//=================================================
// remove
// PARAMETERS: integer index
// RETURN: none but removes the value at specified 
//		   index from the list 
//=================================================
template <class T> 
void	List<T>::remove		( int index )
{
	//Check for invalid index 
	if (index <0 || index>length()-1) throw std::invalid_argument( "Invalid index" ); 

	//Removing the first item 
	if (index == 0) 
	{
		Node *curr; 
		curr = head; 
		head = head -> next;
		delete curr; 
	}

	//Removing an item in the middle/last
	else
	{
		Node *ptr1; 
		Node *ptr2; 
		Node *remove; 
		ptr1 = ptr2 = remove = head; 
		for (int i=0; i<index-1; i++)
		{
			ptr1 = ptr1 -> next; 
		}

		for (int i=0; i<index; i++)
		{
			remove = remove -> next; 
		}

		for (int i=0; i<index+1; i++)
		{
			ptr2 = ptr2 -> next; 
		}

		delete remove; 
		ptr1 -> next = ptr2; 

	}

}


//=================================================
// operator+
// list1 + list 2
// PARAMETERS: const reference to mylist 
// RETURN: A new list with values from the first addend 
//		   followed by the second 
//=================================================
template <class T> 
List<T>	List<T>::operator+	( const List<T> &mylist ) const
{
	List<T> res; 
	//Adding 2 empty lists
	if (head==NULL && mylist.head == NULL)
	{
		res.head = NULL; 
		return res; 
	}

	//Adding an empty list and a non-empty list
	else if ((head!= NULL && mylist.head==NULL) || (head== NULL && mylist.head!=NULL))
	{
		Node *ptr; 		 
		Node *qtr; 		
		Node *curr; 

		if (mylist.head==NULL) qtr = head; 
		else qtr = mylist.head; 

		res.head = new Node; 			
		res.head -> item = qtr -> item; 
		res.head -> next = NULL; 
		
		curr = res.head; 
		qtr = qtr -> next; 
		
		while (qtr!=NULL)
		{
			ptr = new Node; 
			ptr -> item = qtr -> item;
			ptr -> next = NULL;

			curr -> next = ptr; 
			curr = curr -> next; 
			
			qtr = qtr -> next; 
			
		}
	}


	//Adding 2 non-empty lists 
	else if (head != NULL && mylist.head != NULL)
	{
		Node *ptr; 		 
		Node *qtr; 		
		Node *curr; 

		qtr = head; 
		res.head = new Node; 			
		res.head -> item = qtr -> item; 
		res.head -> next = NULL; 
		
		curr = res.head; 
		qtr = qtr -> next; 
		
		//Copying from first list
		while (qtr!=NULL)
		{
			ptr = new Node; 
			ptr -> item = qtr -> item;
			ptr -> next = NULL;

			curr -> next = ptr; 
			curr = curr -> next; 
			
			qtr = qtr -> next; 
			
		}

		//Copying from second list
		qtr = mylist.head; 
		while(qtr!=NULL)
		{
			ptr = new Node; 
			ptr -> item = qtr -> item;
			ptr -> next = NULL;

			curr -> next = ptr; 
			curr = curr -> next; 
			
			qtr = qtr -> next; 
		}
	}
	return res; 


}

