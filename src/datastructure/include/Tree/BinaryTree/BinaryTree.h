#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include <stack>
#include <queue>
#include "BinaryTreeNode.h"

using std::vector;
using std::stack;
using std::queue;
using std::pair;
using std::make_pair;

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

    BinaryTreeNode<T> * LeftChild(BinaryTreeNode<T> *p) const { return p != NULL ? p->GetLeftChild() : NULL; }
    BinaryTreeNode<T> * RightChild(BinaryTreeNode<T> *p) const { return p != NULL ? p->GetRightChild() : NULL; }

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

    // 按序遍历 (T->D, L->R)
    void LevelOrderTraverse(vector<T> &dataList) const;

    // 递归方式遍历
    void PreOrderTraverseR(BinaryTreeNode<T> *root, vector<T> &dataList) const;
    void InOrderTraverseR(BinaryTreeNode<T> *root, vector<T> &dataList) const;
    void PostOrderTraverseR(BinaryTreeNode<T> *root, vector<T> &dataList) const;

    // 非递归方式
    void PreOrderTraverse(vector<T> &dataList) const;
    void InOrderTraverse(vector<T> &dataList) const;
    void PostOrderTraverse(vector<T> &dataList) const;

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
void BinaryTree<T>::LevelOrderTraverse(vector<T> &dataList) const
{
    BinaryTreeNode<T> * root = GetRoot();
    if (root == NULL)
        return;

    queue<BinaryTreeNode<T> *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        root = nodeQueue.front(), nodeQueue.pop();
        dataList.push_back(root->GetData());

        if (root->GetLeftChild())
            nodeQueue.push(root->GetLeftChild());

        if (root->GetRightChild())
            nodeQueue.push(root->GetRightChild());
    }
}

template <class T>
void BinaryTree<T>::PreOrderTraverseR(BinaryTreeNode<T> *root, vector<T> &dataList) const
{
    if (root != NULL)
    {
        dataList.push_back(root->GetData());
        PreOrderTraverseR(root->GetLeftChild(), dataList);
        PreOrderTraverseR(root->GetRightChild(), dataList);
    }
}

template <class T>
void BinaryTree<T>::InOrderTraverseR(BinaryTreeNode<T> *root, vector<T> &dataList) const
{
    if (root != NULL)
    {
        InOrderTraverseR(root->GetLeftChild(), dataList);
        dataList.push_back(root->GetData());
        InOrderTraverseR(root->GetRightChild(), dataList);
    }
}

template <class T>
void BinaryTree<T>::PostOrderTraverseR(BinaryTreeNode<T> *root, vector<T> &dataList) const
{
    if (root != NULL)
    {
        PostOrderTraverseR(root->GetLeftChild(), dataList);
        PostOrderTraverseR(root->GetRightChild(), dataList);
        dataList.push_back(root->GetData());
    }
}

template <class T>
void BinaryTree<T>::PreOrderTraverse(vector<T> &dataList) const
{
    BinaryTreeNode<T> *root = GetRoot();
    if (root == NULL)
        return;

    stack<BinaryTreeNode<T> *> tempStack;

    while (!tempStack.empty() || root)
    {
        while (root)
        {
            dataList.push_back(root->GetData());

            tempStack.push(root);
            root = root->GetLeftChild();
        }

        // 回退
        root = tempStack.top();
        tempStack.pop();

        root = root->GetRightChild();
    }
}

template <class T>
void BinaryTree<T>::InOrderTraverse(vector<T> &dataList) const
{
    BinaryTreeNode<T> *root = GetRoot();
    if (root == NULL)
        return;

    stack<BinaryTreeNode<T> *> tempStack;

    while (!tempStack.empty() || root)
    {
        while (root)
        {
            tempStack.push(root);
            root = root->GetLeftChild();
        }

        root = tempStack.top();
        tempStack.pop();
        dataList.push_back(root->GetData());

        root = root->GetRightChild();
    }
}

template <class T>
void BinaryTree<T>::PostOrderTraverse(vector<T> &dataList) const
{
    BinaryTreeNode<T> *root = GetRoot();
    if (root == NULL)
        return;

    stack<pair<BinaryTreeNode<T> *, bool> > tempStack;
    tempStack.push(make_pair(root, false));
    bool visited;

    while (!tempStack.empty())
    {
        root = tempStack.top().first;
        visited = tempStack.top().second;
        tempStack.pop();

        if (root == NULL)
            continue;

        if (visited)
            dataList.push_back(root->GetData());
        else
        {
            tempStack.push(make_pair(root, true));
            tempStack.push(make_pair(root->GetRightChild(), false));
            tempStack.push(make_pair(root->GetLeftChild(), false));
        }
    }
}

template <class T>
BinaryTreeNode<T> * BinaryTree<T>::Parent(BinaryTreeNode<T> *root, BinaryTreeNode<T> *child)
{
    if (root == NULL)
        return NULL;
    
    if ((child == root->GetLeftChild()) || (child == root->GetRightChild()))
        return root;

    if ((BinaryTreeNode<T> *temp == Parent(root->GetLeftChild(), child)) != NULL)
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
