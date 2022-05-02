
template<typename T> struct Node{
    T data;
    Node<T> *parent;
    Node<T> *left;
    Node<T> *right;
};

#include <iostream>
template<typename T> class BinaryTree {

    public:
        BinaryTree(){
            root = NULL;
            left = NULL;
            right = NULL;
        }
        void create_first_node( T data ){
           
            Node<T> *node = new Node<T>();
            node->data = data;
            node->left = NULL;
            node->right = NULL;
            node->parent = NULL;
            root = node;
           
        }
        void add_left(T data){
            if (this->size() > 0 && this->has_right_child() == false)
            {
                Node<T> *node = new Node<T>();
                node->data = data;
                node->left = NULL;
                node->right = NULL;
                node->parent = root;
                this->left = node;
            }
           

           
        }
        void change( T data )
        {
            if (size() > 0)
            {
                root->data = data;
            }
        }
        void add_right( T data ){
            if (this->size() > 0 && this->has_right_child() == false)
            {
                 Node<T> *node = new Node<T>();
                node->data = data;
                node->left = NULL;
                node->right = NULL;
                node->parent = root;
                this->right = node;
            }
           
        }
        Node<T>* get_left(){
            return left;
        }
        Node<T>* get_right(){
            return right;
        }
        Node<T>* get_root(){
            return root;
        }
        T retreive(){
            if( root != NULL ){
                return root->data;
            }
            else{
                return NULL;
            }
        }

        bool has_left_child(){
            if( size() > 0 && root->left != NULL ){
                return true;
            }
            else{
                return false;
            }
        }
        bool has_parent()
        {
            if(size() > 0 && root->parent != NULL){
                return true;
            }
            else{
                return false;
            }
        }
        bool has_right_child(){
            if( size() > 0 && root->right != NULL ){
                return true;
            }
            else{
                return false;
            }
        }
        size_t size(){
            size_t size = 0;
        }
        void shift_to_root(){
            if( size() > 0 && has_parent() )
            {
               while( root->parent != NULL )
               {
                   root = root->parent;
               }
            }
        }
        void shift_to_left(){
            if( size() > 0 && has_left_child() )
            {
                root = root->left;
            }
        }
        void shift_to_right(){
            if( size() > 0 && has_right_child() )
            {
                root = root->right;
            }
        }
        void shift_up()
        {
            if( size() > 0 && has_parent() )
            {
                root = root->parent;
            }
        }
    private:
        Node<T> *root;
        Node<T> *left;
        Node<T> *right;

        

};