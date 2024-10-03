class Node {
	public:
		int get(){
			return object;
		};
		void set(int object){
			this->object = object;
		};
		Node* getNext(){
			return nextNode;
		}
		void setNext(Node *nextNode){
			this->nextNode = nextNode;
		}
		Node* getPrev(){
			return prevNode;
		}
		void setPrev(Node *prevNode){
			this->prevNode = prevNode;
		}
	private:
		int object;
		Node *nextNode, *prevNode;
};

