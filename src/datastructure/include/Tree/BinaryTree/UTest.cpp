#include "BinaryTree.h"

int main()
{
    BinaryTree<char> myBinTree('a');
    myBinTree.InsertLeftChild(myBinTree.GetRoot(), 'b');
    myBinTree.InsertRightChild(myBinTree.GetRoot(), 'c');
    myBinTree.LevelOrderTraverse(myBinTree.GetRoot());

    myBinTree.SetData(myBinTree.GetRoot(), 'A');
    myBinTree.LevelOrderTraverse(myBinTree.GetRoot());

    myBinTree.SetData(myBinTree.GetRoot()->GetRightChild(), 'C');
    myBinTree.LevelOrderTraverse(myBinTree.GetRoot());

    myBinTree.PreOrderTraverse(myBinTree.GetRoot());
    std::cout << std::endl;

    myBinTree.InOrderTraverse(myBinTree.GetRoot());
    std::cout << std::endl;

    myBinTree.PostOrderTraverse(myBinTree.GetRoot());
    std::cout << std::endl;
}
