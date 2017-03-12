#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <queue>
#include "BinaryTreeNode.h"

// Definition

template <class T>
class BinaryTree
{
public:
    BinaryTree() : m_root(NULL) {}
    BinaryTree(T data) { m_root = new BinaryTreeNode<T>(data); }
    virtual ~BinaryTree();

    bool IsEmpty() const { return m_root == NULL ? true : false; }
    bool IsLeftChild(BinaryTreeNode<T> *p) const;
    bool IsRightChild(BinaryTreeNode<T> *p) const;

    BinaryTreeNode<T> * GetRoot() const { return m_root; }
    BinaryTreeNode<T> * Parent(BinaryTreeNode<T> *p) const { return Parent(m_root, p); }

    BinaryTreeNode<T> * LeftChild(BinaryTreeNode<T> *root) const { return root != NULL ? root->GetLeftChild() : NULL; }
    BinaryTreeNode<T> * RightChild(BinaryTreeNode<T> *root) const { return root != NULL ? root->GetRightChild() : NULL; }

    // 仅限于同一个父节点
    BinaryTreeNode<T> * LeftSibling(BinaryTreeNode<T> *leftChild) const;
    BinaryTreeNode<T> * RightSibling(BinaryTreeNode<T> *rightChild) const;

    const T& GetData(BinaryTreeNode<T> *p) const { return p->GetData(); }
    void SetData(BinaryTreeNode<T> *p, const T &data) { p->SetData(data); }

    // 插入或者替换
    void InsertLeftChild(BinaryTreeNode<T> *p, const T &data);
    void InsertRightChild(BinaryTreeNode<T> *p, const T &data);

    void DeleteLeftChild(BinaryTreeNode<T> *p) { Destroy(p->GetLeftChild()); }
    void DeleteRightChild(BinaryTreeNode<T> *p) { Destroy(p->GetRightChild()); }

    virtual void PreOrderTraverse(BinaryTreeNode<T> *root) const;
    virtual void InOrderTraverse(BinaryTreeNode<T> *root) const;
    virtual void PostOrderTraverse(BinaryTreeNode<T> *root) const;
    virtual void LevelOrderTraverse(BinaryTreeNode<T> *root) const;

protected:
    BinaryTreeNode<T> * Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *child);
    void Destroy(BinaryTreeNode<T> *p);

private:
    BinaryTreeNode<T> * m_root;
};

// Implementation

template <class T>
BinaryTree<T>::~BinaryTree()
{
    Destroy(m_root);
    m_root = NULL;
}

template <class T>
bool BinaryTree<T>::IsLeftChild(BinaryTreeNode<T> *p) const
{
    BinaryTreeNode<T> *parent = GetParent(m_root, p);
    if (parent == NULL)
        return false;

    return p == parent->GetLeftChild() ? true : false;
}

template <class T>
bool BinaryTree<T>::IsRightChild(BinaryTreeNode<T> *p) const
{
    BinaryTreeNode<T> *parent = GetParent(m_root, p);
    if (parent == NULL)
        return false;

    return p == parent->GetRightChild() ? true : false;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::LeftSibling(BinaryTreeNode<T> *p) const
{
    BinaryTreeNode<T> *parent = GetParent(m_root, p);
    if (parent == NULL)
        return NULL;

    BinaryTreeNode<T> *temp = parent->GetLeftChild();
    return p == temp ? NULL : temp;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::RightSibling(BinaryTreeNode<T> *p) const
{
    BinaryTreeNode<T> *parent = GetParent(m_root, p);
    if (parent == NULL)
        return NULL;

    BinaryTreeNode<T> *temp = parent->GetRightChild();
    return p == temp ? NULL : temp;
}

template <class T>
void BinaryTree<T>::InsertLeftChild(BinaryTreeNode<T> *p, const T &data)
{
    BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(data);
    temp->SetLeftChild(p->GetLeftChild());
    p->SetLeftChild(temp);
}

template <class T>
void BinaryTree<T>::InsertRightChild(BinaryTreeNode<T> *p, const T &data)
{
    BinaryTreeNode<T> *temp = new BinaryTreeNode<T>(data);
    temp->SetRightChild(p->GetRightChild());
    p->SetRightChild(temp);
}

// Traverse
template <class T>
void BinaryTree<T>::PreOrderTraverse(BinaryTreeNode<T> *root) const
{
    if (root != NULL)
    {
        std::cout << root->GetData();
        PreOrderTraverse(root->GetLeftChild());
        PreOrderTraverse(root->GetRightChild());
    }
}

template <class T>
void BinaryTree<T>::InOrderTraverse(BinaryTreeNode<T> *root) const
{
    if (root != NULL)
    {
        InOrderTraverse(root->GetLeftChild());
        std::cout << root->GetData();
        InOrderTraverse(root->GetRightChild());
    }
}

template <class T>
void BinaryTree<T>::PostOrderTraverse(BinaryTreeNode<T> *root) const
{
    if (root != NULL)
    {
        PostOrderTraverse(root->GetLeftChild());
        PostOrderTraverse(root->GetRightChild());
        std::cout << root->GetData();
    }
}

template <class T>
void BinaryTree<T>::LevelOrderTraverse(BinaryTreeNode<T> *root) const
{
    std::queue<BinaryTreeNode<T> *> nodeQueue;

    if (root != NULL)
        nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        root = nodeQueue.front(), nodeQueue.pop();
        std::cout << root->GetData();

        if (root->GetLeftChild())
            nodeQueue.push(root->GetLeftChild());

        if (root->GetRightChild())
            nodeQueue.push(root->GetRightChild());
    }

    std::cout << std::endl;
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *child)
{
    if (root == NULL)
        return NULL;

    if ((child == root->GetLeftChild()) || (child == root->GetRightChild()))
        return root;

	BinaryTreeNode<T> *temp = Parent(root->GetLeftChild(), child);
    if (temp != NULL)
        return temp;

    return Parent(root->GetRightChild(), child);
}

template <class T>
void BinaryTree<T>::Destroy(BinaryTreeNode<T> *p)
{
    if (p != NULL)
    {
        Destroy(p->GetLeftChild());
        Destroy(p->GetRightChild());
        delete p;
    }
}

#endif
