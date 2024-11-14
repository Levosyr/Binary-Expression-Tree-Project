#include "binaryExpressionTree.h"
#include <iostream>

void binaryExpressionTree::buildExpressionTree(const std::string& postfix) {
    destroyTree();
    std::stack<nodeType<std::string>*> nodeStack;
    std::istringstream ss(postfix);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            auto* newNode = new nodeType<std::string>{ token, nullptr, nullptr };
            nodeStack.push(newNode);
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            auto* newNode = new nodeType<std::string>{ token, nullptr, nullptr };
            if (!nodeStack.empty()) {
                newNode->rLink = nodeStack.top();
                nodeStack.pop();
            }
            if (!nodeStack.empty()) {
                newNode->lLink = nodeStack.top();
                nodeStack.pop();
            }
            nodeStack.push(newNode);
        }
    }

    if (!nodeStack.empty()) {
        root = nodeStack.top();
        nodeStack.pop();
    }
}

double binaryExpressionTree::evaluateExpressionTree() {
    return evaluate(root);
}

double binaryExpressionTree::evaluate(nodeType<std::string>* p) {
    if (p->lLink == nullptr && p->rLink == nullptr) {
        return std::stod(p->info);
    }
    else {
        double leftValue = evaluate(p->lLink);
        double rightValue = evaluate(p->rLink);

        if (p->info == "+") return leftValue + rightValue;
        if (p->info == "-") return leftValue - rightValue;
        if (p->info == "*") return leftValue * rightValue;
        if (p->info == "/") return leftValue / rightValue;
    }
    return 0;
}
