class Node
{
private:
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = nullptr;
    };
    ~Node() {

    };
    // getters and setters
    void setData(int data)
    {
        this->data = data;
    }
    int getData()
    {
        return this->data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    Node *getNext()
    {
        return this->next;
    }
};