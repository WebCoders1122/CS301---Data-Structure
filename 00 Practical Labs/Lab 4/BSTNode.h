class BSTNode
{
private:
    int data;
    BSTNode *left;
    BSTNode *right;

public:
    BSTNode()
    {
        data = 0;
        left = nullptr;
        right = nullptr;
    };
    ~BSTNode() {};
    // getters and setters
    int getData()
    {
        return data;
    };
    void setData(int d)
    {
        data = d;
    };
    BSTNode *getLeft()
    {
        return left;
    };
    void setLeft(BSTNode *l)
    {
        left = l;
    };
    BSTNode *getRight()
    {
        return right;
    };
    void setRight(BSTNode *r)
    {
        right = r;
    };
};
