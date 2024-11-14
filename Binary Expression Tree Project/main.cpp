#include <iostream>
#include <fstream>
#include "binaryExpressionTree.h"

int main() {
    binaryExpressionTree exprTree;
    std::ifstream infile("RpnData.txt");
    std::ofstream outfile("C:\\Users\\yyber\\source\\repos\\Binary Expression Tree Project\\x64\\Debug\\Results.txt");
    std::string postfixExpression;

    while (getline(infile, postfixExpression)) {
        exprTree.buildExpressionTree(postfixExpression);
        double result = exprTree.evaluateExpressionTree();

        // This line prints each result to the console
        std::cout << "Expression: " << postfixExpression << " = " << result << std::endl;

        // Write the result to the file
        outfile << "Expression: " << postfixExpression << " = " << result << std::endl;
    }

    infile.close();
    outfile.close();

    std::cout << "Results written to Results.txt" << std::endl;
    return 0;
}
