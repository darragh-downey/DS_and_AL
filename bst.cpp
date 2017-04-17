#include "bst.h"



BST::BST(int data)
{
    this->_data = data;
}

BST::~BST()
{
    delete this->_left; // need to delete as I'm not using smart pointers!!
    delete this->_right;
}

bool BST::contains(int data)
{
    if(this->_data == data)
        return true;
    else if(this->_left != nullptr)
        return this->_left->contains(data);
    else if(this->_right != nullptr)
        return this->_right->contains(data);
    else
        return false;
}

void BST::insert(int data)
{
    if(data < this->_data){
        if(this->_left != nullptr)
            this->_left->insert(data);
        else
            this->_left = new BST(data); // needs to be new to survive exiting scope!
    }else{
        if(this->_right != nullptr)
            this->_right->insert(data);
        else
            this->_right = new BST(data);
    }
}

BST* BST::search_tree(BST *left, int x)
{
    if(left == NULL) return(NULL);

    if(left->_data == x) return left;

    if(x < left->_data)
        return search_tree(left->_left, x);
    else
        return search_tree(left->_right, x);
}

void BST::printInOrder()
{
    if(this->_left != nullptr)
        this->_left->printInOrder();
    std::cout << this->_data << std::endl;
    if(this->_right != nullptr)
        this->_right->printInOrder();
}

void BST::printPreOrder()
{
    std::cout << this->_data <<std::endl;
    if(this->_left != nullptr)
        this->_left->printPreOrder();
    if(this->_right != nullptr)
        this->_right->printPreOrder();
}

void BST::printPostOrder()
{
    if(this->_left != nullptr)
        this->_left->printPreOrder();
    if(this->_right != nullptr)
        this->_right->printPreOrder();
    std::cout << this->_data << std::endl;
}

void BST::printValue()
{
    std::cout << this->_data << std::endl;
}
