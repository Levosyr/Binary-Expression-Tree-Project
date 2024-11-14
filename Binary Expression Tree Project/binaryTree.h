// File: binaryTree.h

#ifndef H_binaryTree
#define H_binaryTree
#include <iostream>
using namespace std;

template <class elemType>
struct nodeType {
    elemType info;
    nodeType<elemType>* lLink;
    nodeType<elemType>* rLink;
};

template <class elemType>
class binaryTreeType {
protected:
    nodeType<elemType>* root;

public:
    const binaryTreeType<elemType>& operator=(const binaryTreeType<elemType>&);
    bool isEmpty() const;
    void inorderTraversal() const;
    void preorderTraversal() const;
    void postorderTraversal() const;
    int treeHeight() const;
    int treeNodeCount() const;
    int treeLeavesCount() const;
    void destroyTree();
    virtual bool search(const elemType& searchItem) const = 0;
    virtual void insert(const elemType& insertItem) = 0;
    virtual void deleteNode(const elemType& deleteItem) = 0;

    binaryTreeType(const binaryTreeType<elemType>& otherTree);
    binaryTreeType();
    ~binaryTreeType();

protected:
    void copyTree(nodeType<elemType>*& copiedTreeRoot, nodeType<elemType>* otherTreeRoot);
    void destroy(nodeType<elemType>*& p);
    void inorder(nodeType<elemType>* p) const;
    void preorder(nodeType<elemType>* p) const;
    void postorder(nodeType<elemType>* p) const;
    int height(nodeType<elemType>* p) const;
    int max(int x, int y) const;
    int nodeCount(nodeType<elemType>* p) const;
    int leavesCount(nodeType<elemType>* p) const;
};

// Implementation of member functions
template <class elemType>
binaryTreeType<elemType>::binaryTreeType() {
    root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty() const {
    return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal() const {
    inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal() const {
    preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal() const {
    postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight() const {
    return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount() const {
    return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount() const {
    return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType>*& copiedTreeRoot, nodeType<elemType>* otherTreeRoot) {
    if (otherTreeRoot == NULL)
        copiedTreeRoot = NULL;
    else {
        copiedTreeRoot = new nodeType<elemType>;
        copiedTreeRoot->info = otherTreeRoot->info;
        copyTree(copiedTreeRoot->lLink, otherTreeRoot->lLink);
        copyTree(copiedTreeRoot->rLink, otherTreeRoot->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType>* p) const {
    if (p != NULL) {
        inorder(p->lLink);
        cout << p->info << " ";
        inorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType>* p) const {
    if (p != NULL) {
        cout << p->info << " ";
        preorder(p->lLink);
        preorder(p->rLink);
    }
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType>* p) const {
    if (p != NULL) {
        postorder(p->lLink);
        postorder(p->rLink);
        cout << p->info << " ";
    }
}

template <class elemType>
const binaryTreeType<elemType>& binaryTreeType<elemType>::operator=(const binaryTreeType<elemType>& otherTree) {
    if (this != &otherTree) { // avoid self-copy
        if (root != NULL) // if the binary tree is not empty, destroy the binary tree
            destroy(root);
        if (otherTree.root == NULL) // otherTree is empty
            root = NULL;
        else
            copyTree(root, otherTree.root);
    }
    return *this;
}

template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType>*& p) {
    if (p != NULL) {
        destroy(p->lLink);
        destroy(p->rLink);
        delete p;
        p = NULL;
    }
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree() {
    destroy(root);
}

template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType>& otherTree) {
    if (otherTree.root == NULL) // otherTree is empty
        root = NULL;
    else
        copyTree(root, otherTree.root);
}

template <class elemType>
binaryTreeType<elemType>::~binaryTreeType() {
    destroy(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType>* p) const {
    if (p == NULL)
        return 0;
    else
        return 1 + max(height(p->lLink), height(p->rLink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y) const {
    return (x >= y) ? x : y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType>* p) const {
    if (p == nullptr)
        return 0;
    else
        return 1 + nodeCount(p->lLink) + nodeCount(p->rLink);
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType>* p) const {
    if (p == NULL)
        return 0;
    else if (p->lLink == NULL && p->rLink == NULL)
        return 1;
    else
        return leavesCount(p->lLink) + leavesCount(p->rLink);
}

#endif
