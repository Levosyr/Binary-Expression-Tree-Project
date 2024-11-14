// File: binaryExpressionTree.h

#ifndef H_binaryExpressionTree
#define H_binaryExpressionTree

#include "binaryTree.h"
#include <stack>
#include <string>
#include <sstream>
#include <cstring>

class binaryExpressionTree : public binaryTreeType<std::string> {
public:
    binaryExpressionTree() { root = nullptr; }
    ~binaryExpressionTree() { destroyTree(); }

    void buildExpressionTree(const std::string& postfix);
    double evaluateExpressionTree();

protected:
    double evaluate(nodeType<std::string>* p);

private:
    void insert(const std::string&) override {}
    bool search(const std::string&) const override { return false; }
    void deleteNode(const std::string&) override {}
};

#endif
#pragma once
