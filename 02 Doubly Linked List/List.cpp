#include <stdlib.h>
#include "Node.cpp"
    
// class

class List {
	public:
		//constructer
		List(){
			headNode = new Node();
			headNode->setNext(NULL);
			headNode->setPrev(NULL);
			currentNode = NULL;
			size = 0;
		}
		// method to add new node in list
		void add(int addObject){
			Node *newNode = new Node(); //node creation
			newNode->set(addObject);
			if(currentNode != NULL){
				newNode->setNext(currentNode->getNext()); // step 1
				newNode->setPrev(currentNode); //step 2
				(currentNode->getNext())->setPrev(newNode); //step 3
				currentNode->setNext(newNode); // step 3
				lastCurrentNode = currentNode;
				currentNode = newNode; // step 4
			} else {
				newNode->setNext(NULL);
				newNode->setPrev(headNode);
				headNode->setNext(newNode);
				lastCurrentNode = headNode;
				currentNode = newNode;
			}
			size++;
		};
//		function to get value of current node
		int get(){
			if (currentNode != NULL)
			return currentNode->get();
		}
		// function to switch to the next index of list
		bool next(){
			//if list empty
			if (currentNode == NULL)
				return false;
			//if list is not empty
			lastCurrentNode = currentNode;
			currentNode = currentNode->getNext();
			// showing success or falure to user
			if(currentNode == NULL || size == 0)
				return false;
			else
				return true;
		}
		// function to switch to the next index of list
		bool back(){
			//if list empty
			if (currentNode == NULL)
				return false;
			//if list is not empty
			lastCurrentNode = currentNode;
			currentNode = currentNode->getPrev();
			// showing success or falure to user
			if(currentNode == NULL || size == 0)
				return false;
			else
				return true;
		}
		// function to set current index to start of list
		void start(){
			this->lastCurrentNode = headNode;
			this->currentNode = headNode;
		}
		//function to remove item from list
		void remove(){
			if(currentNode != NULL && currentNode != headNode){
				lastCurrentNode->setNext(currentNode->getNext());
				(currentNode->getNext())->setPrev(lastCurrentNode);
				delete currentNode;
				currentNode = lastCurrentNode->getNext();
				size--;
			}
		}
		//function to reutn size of list
		int length(){
			return size;
		}
		
		 // Destructor
    	~List() {
       	 Node* current = headNode->getNext();
        	while (current != NULL) {
            Node* temp = current->getNext();
            delete current;
            current = temp;
       	 }
        delete headNode;
    	}
		
		private:
			int size;
			Node *headNode, *currentNode, *lastCurrentNode;
};

