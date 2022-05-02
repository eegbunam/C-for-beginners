
template<typename T>
struct Node{

    Node* next;
    T data;
};

template<typename T>
class LL{

    public:
        LL(){
            head = NULL;
        }
        Node<T>* head;
        void Appened(T data)
        {
            Node<T>* temp = new Node<T>;
            temp->data = data;
            temp->next = NULL;
            if(head == NULL)
            {
                head = temp;
            }
            else
            {
                Node<T>* temp2 = head;
                while(temp2->next != NULL)
                {
                    temp2 = temp2->next;
                }
                temp2->next = temp;
            }
        }
        
    
};

int main()
{
    // LL<int> ll;
    // ll.Appened(1);
    // ll.Appened(2.8);

}