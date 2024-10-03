#include<iostream>
#include<conio.h>
using namespace std;

// global veriable 
int size = 0;
class Node {
	public:
	int data;
	Node *next_add;
};

// functions to be added
// add, count, search, update delete show

class List{
	public:
	Node *head = NULL, *tail = NULL;
	//destructor
	~List()
	//	 function to add values
void add(){
	int number;
	cout << "\n\n Enter Value: ";
	cin >> number;
	Node *new_node = new Node;
	new_node->data = number;
	new_node->next_add = NULL;
//	if list is empty
	if(head == NULL){
		head = new_node;
		tail = new_node;
		new_node -> next_add = new_node;
	}else {
		// if list not empty
		tail->next_add = new_node;
		new_node->next_add = head;
		tail = new_node;
	}
		size++;
		cout << "\n\n added successfully";
}
//to show total count in the list
void count(){
	if(head == NULL)
	{
		cout<< "\n\n List is empty and count is 0";
	}
	else
	{
	cout << "\n\n List size is " << size ;	
	}
};
// to search any element in the list
void search(){
		if(head == NULL)
	{
		cout<< "\n\n List is empty ...";
	}
	else
	{
		int number, found, loop_count = 0;
		Node *ptr = head;
		cout << "\n\n Enter number to search";
		cin >> number;
		while(loop_count != size)
		{
			if(number == ptr->data)
			{
				found++;
				cout << "\n\n number found successfully...";
				break;
			}
			loop_count++;
			ptr = ptr->next_add;
			
		}
		if(found == 0){
			cout << "\n\n entered value not found in the list...";
		}
	}
}
// to update any element in the list
void update(){
		if(head == NULL)
	{
		cout<< "\n\n List is empty ...";
	}
	else
	{
		int number, found, loop_count = 0;
		Node *ptr = head;
		cout << "\n\n Enter number to update";
		cin >> number;
		while(loop_count != size)
		{
			if(number == ptr->data)
			{
				int new_number;
				cout << "\n enter new value: ";
				cin >> new_number;
				ptr->data = new_number;
				found++;
				cout << "\n\n number updated successfully...";
				break;
			}
			loop_count++;
			ptr = ptr->next_add;
			
		}
		if(found == 0){
			cout << "\n\n Can't update. Bcz enter value is not in the list'...";
		}
	}
}

// function to delete the node
void remove(){
	int number, found =0;
	Node *ptr;
	cout<< "\n\n Enter number to delete: ";
	cin >> number;
		if(head == NULL)
		{
		cout<< "\n\n List is empty ...";
		}
		else if(size == 1)
		{
			ptr=head;
			head = NULL;
			tail = NULL;
			delete ptr;
			found++;
			size --;
			cout << "\n\n value deleted successfully...";
		}
		else if(number == head->data)
		{
			ptr = head;
			head = head->next_add;
			tail->next_add = head;
			delete ptr;
			found++;
			size --;
			cout << "\n\n value deleted successfully...";
		}
		else if(number == tail->data) 
		{
			ptr = tail;
			Node *prev_node = head;
			int loop_count =0;
			while(size != loop_count)
			{
				if(prev_node->next_add == tail){
					tail = prev_node;
					prev_node->next_add = head;
					delete ptr;
					found++;
					size --;
					cout << "\n\n value deleted successfully...";
					break;
				}
				prev_node = prev_node->next_add;
			}
		
		}
		else
		{
			int loop_count = 0;
			ptr = head->next_add;
			Node *pre_node=head;
			
			while(size != loop_count)
			{
				if(ptr->data == number){
					pre_node->next_add = ptr->next_add;
					delete ptr;
					found++;
					size --;
					cout << "\n\n value deleted successfully...";
					break;
				}
				pre_node= pre_node->next_add;
				ptr= ptr->next_add;
				loop_count++;
			}
		}
		if (found == 0)
		{
			cout << "\n\n Can't delete. Bcz enter value is not in the list'...";
		}
}

void show(){
		if(head == NULL)
		{
		cout<< "\n\n List is empty ...";
		}
		else
		{
		Node *ptr = head;
		for(int i=0; i<size; i++)
		{
			cout << ptr->data<< "\t";
			ptr=ptr->next_add;
		}
		}
	}	
};


main(){
	List list;
	p:
	system("cls");
	int choice;
	cout << "\n\n 1. Inset new Number: ";
	cout << "\n 2. Count Number: ";
	cout << "\n 3. Search Number: ";
	cout << "\n 4. Update Number: ";
	cout << "\n 5. Delete Number: ";
	cout << "\n 6. Show Numbers: ";
	cout << "\n 7. Exit Number: ";
	cout << "\n\n Enter your choice: ";
	cin >> choice;
	switch(choice){
		case 1:
			list.add();
			break;
		case 2:
			list.count();
			break;
		case 3:
			list.search();
			break;
		case 4:
			list.update();
			break;
		case 5:
			list.remove();
			break;
		case 6:
			list.show();
			break;
		case 7:
			exit(0);
			break;	
		default:
				cout << "\n\n You have entered wrong choice: ";
			break;
	}
	
	getch();
	goto p;
	
}
