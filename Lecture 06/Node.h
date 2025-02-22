class Node
{
public:
    Node()
    {
        this->data = 0;
        next = nullptr;
    }
    ~Node() {};
    // getters and setters
    int getData()
    {
        return data;
    }
    void setData(int data)
    {
        this->data = data;
    }
    Node *getNext()
    {
        return next;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }

private:
    int data;
    Node *next;
};