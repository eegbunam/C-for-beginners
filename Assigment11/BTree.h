

#include <iostream>
template<typename T>class  BTree
{
    public:
        BTree(){
            data = 0;
            left = NULL;
            right = NULL;
        }
        BTree(T d){
            data = d;
            left = NULL;
            right = NULL;
        }
        void insert(const T& d){
            BTree *curr = this;
            while(curr != NULL){
                if(d < curr->data){
                    if(curr->left == NULL){
                        curr->left = new BTree(d);
                        return;
                    }
                    curr = curr->left;
                }
                else{
                    if(curr->right == NULL){
                        curr->right = new BTree(d);
                        return;
                    }
                    curr = curr->right;
                }
            }
        }

        void print(){
            print_helper(this);
        }


        int size()
        {
            return node_count_helper(this);
        }

       
          

    private:
        T data;
        BTree<T>* left;
        BTree<T>* right;

        int node_count_helper(const BTree *curr)
        {
            if(curr == NULL)
                return 0;
            return 1 + node_count_helper(curr->left) + node_count_helper(curr->right);
        }
        void print_helper(const BTree *curr)
        {
            if(curr == NULL)
            {
                //std::cout << "NULL" << std::endl;
                return;
            }
                
            print_helper(curr->left);
            std::cout << curr->data << " ";
            print_helper(curr->right);
        }

};