#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

#include <iostream>

template <class T>
class BinaryTreeNode
{
public:
    BinaryTreeNode()
        : m_leftChild(NULL)
        , m_rightChild(NULL)
    {}

    BinaryTreeNode(const T &data, BinaryTreeNode<T> *leftChild = NULL, BinaryTreeNode<T> *rightChild = NULL)
        : m_data(data)
        , m_leftChild(leftChild)
        , m_rightChild(rightChild)
    {}

    ~BinaryTreeNode() {}

    T & GetData() { return m_data; }
    void SetData(const T &data) { m_data = data; }

    BinaryTreeNode<T> * GetLeftChild() { return m_leftChild; }
    void SetLeftChild(BinaryTreeNode<T> *leftChild) { m_leftChild = leftChild; }

    BinaryTreeNode<T> * GetRightChild() { return m_rightChild; }
    void SetRightChild(BinaryTreeNode<T> *rightChild) { m_rightChild = rightChild; }


private:
    T m_data;
    BinaryTreeNode<T> * m_leftChild;
    BinaryTreeNode<T> * m_rightChild;
};

#endif
