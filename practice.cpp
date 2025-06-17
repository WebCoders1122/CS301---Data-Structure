template <class T>
class practice
{
private:
    /* data */
public:
    practice(/* args */) {};
    ~practice() {};
};
int main()
{
    void remove()
    {
        if (current == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = current;
        if (current->next == NULL)
        {
            delete current;
            current = NULL;
            return;
        }
    }
    return 0;
}