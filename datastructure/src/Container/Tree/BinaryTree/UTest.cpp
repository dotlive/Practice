#include <iostream>
#include "BinaryTree.h"

using std::cout;
using std::endl;

void Output(const vector<char> & data);

int main()
{
    vector<char> dataQueue;

    BinaryTree<char> myBinTree('a');
    myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'b');
    myBinTree.InsertRightChild(myBinTree.GetRoot(), 'c');
    dataQueue.clear();
    myBinTree.LevelOrderTraverse(dataQueue);
    Output(dataQueue);

    myBinTree.SetData(myBinTree.GetRoot(), 'A');
    dataQueue.clear();
    myBinTree.LevelOrderTraverse(dataQueue);
    Output(dataQueue);

    myBinTree.SetData(myBinTree.GetRoot()->GetRightChild(), 'C');
    dataQueue.clear();
    myBinTree.LevelOrderTraverse(dataQueue);
    Output(dataQueue);

    myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetLeftChild(), 'd');
    myBinTree.InsertRightChild(myBinTree.GetRoot()->GetLeftChild(), 'e');
    myBinTree.InsertLeftChild(myBinTree.GetRoot()->GetRightChild(), 'f');
    myBinTree.InsertRightChild(myBinTree.GetRoot()->GetRightChild(), 'g');
    dataQueue.clear();
    myBinTree.LevelOrderTraverse(dataQueue);
    Output(dataQueue);

    cout << "#####" << endl;

    dataQueue.clear();
    myBinTree.PreOrderTraverseR(myBinTree.GetRoot(), dataQueue);
    Output(dataQueue);

    dataQueue.clear();
    myBinTree.InOrderTraverseR(myBinTree.GetRoot(), dataQueue);
    Output(dataQueue);

    dataQueue.clear();
    myBinTree.PostOrderTraverseR(myBinTree.GetRoot(), dataQueue);
    Output(dataQueue);

    cout << "#####" << endl;

    dataQueue.clear();
    myBinTree.PreOrderTraverse(dataQueue);
    Output(dataQueue);

    dataQueue.clear();
    myBinTree.InOrderTraverse(dataQueue);
    Output(dataQueue);
}

void Output(const vector<char> & data)
{
    vector<char>::const_iterator citer = data.begin();
    for (; citer != data.end(); ++citer)
    {
        cout << (*citer) << " ";
    }
    cout << endl;
}
