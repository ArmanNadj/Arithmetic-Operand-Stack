//Author: Arman Nadjarian
//Project: To Implement an Arithmetic Operand Stack capable of performing the 6 main arithmetic operations

#include <iostream>
#include <vector>
#include <cmath>


//Operation represents one of 6 possible operations that could take place
//in a simple Arithmetic Based Operand Stack
enum class Operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    MODULO,
    EXP,
    NONE
};

//OpNode is a data-structure representation of an Operation
//it contains:
// data1: first data value used in arithmetic :: type double
// data2: second data value used in arithmetic :: type double
// answer: data value to represent answer of arithmetic on data1 and data2 :: type double
// op: enum Operation to represent the kind of operation to take place on data1 and data2
class OpNode {
public:
    double data1, data2, answer;
    Operation op;

    OpNode(double one, double two, Operation operation){
        this->data1 = one;
        this->data2 = two;
        this->op = operation;
        this->answer = 0; //default value for answer
    }
};


//Evaluates the OpNode at the top of the stack
//returns true if successful, false if failure
bool Evaluate(std::vector<OpNode *>& OpStack){
    if(OpStack[OpStack.size() - 1] == NULL || OpStack[OpStack.size() - 1]->op == Operation::NONE)
        return false;
    if(OpStack.size() <= 0) return false;    

    std::cout << "Operation: ";
    std::cout << OpStack[OpStack.size() - 1]->data1 << " ";
    switch(OpStack[OpStack.size() - 1]->op){
        case Operation::ADD:
            std::cout << "+ ";
            OpStack[OpStack.size() - 1]->answer = OpStack[OpStack.size() - 1]->data1 + OpStack[OpStack.size() - 1]->data2;
            break;
        case Operation::SUBTRACT:
            std::cout << "- ";
            OpStack[OpStack.size() - 1]->answer = OpStack[OpStack.size() - 1]->data1 - OpStack[OpStack.size() - 1]->data2;
            break;
        case Operation::MULTIPLY:
            std::cout << "x ";
            OpStack[OpStack.size() - 1]->answer = OpStack[OpStack.size() - 1]->data1 * OpStack[OpStack.size() - 1]->data2;
            break;
        case Operation::DIVIDE:
            std::cout << "/ ";
            OpStack[OpStack.size() - 1]->answer = OpStack[OpStack.size() - 1]->data1 / OpStack[OpStack.size() - 1]->data2;
            break;
        case Operation::MODULO:
            std::cout << "% ";
            OpStack[OpStack.size() - 1]->answer = ((int) OpStack[OpStack.size() - 1]->data1 % (int) OpStack[OpStack.size() - 1]->data2);
            break;
        case Operation::EXP:
            std::cout << "^ ";
            OpStack[OpStack.size() - 1]->answer = pow(OpStack[OpStack.size() - 1]->data1, OpStack[OpStack.size() - 1]->data2);
            break;
    }

    std::cout << OpStack[OpStack.size() - 1]->data2 << " = " 
    << OpStack[OpStack.size() - 1]->answer << "\n\t::::> Updated Op-Stack size is " << OpStack.size() - 1 << "\n";
    
    delete OpStack[OpStack.size() - 1];
    OpStack.pop_back();

    return true;
}

int main(int argc, char * argv[]){
    std::vector<OpNode *> OpStack;
    OpNode * testNode1 = new OpNode(11, 7, Operation::MULTIPLY);
    OpNode * testNode2 = new OpNode(125, 1.69, Operation::DIVIDE);
    OpNode * testNode3 = new OpNode(78, 35, Operation::ADD);
    OpNode * testNode4 = new OpNode(-1, 8, Operation::SUBTRACT);
    OpNode * testNode5 = new OpNode(67, 4, Operation::MODULO);
    OpNode * testNode6 = new OpNode(2, 8, Operation::EXP);

    OpStack.push_back(testNode1);
    OpStack.push_back(testNode2);
    OpStack.push_back(testNode3);
    OpStack.push_back(testNode4);
    OpStack.push_back(testNode5);
    OpStack.push_back(testNode6);

    int totalRuns = OpStack.size();
    for(int i = 0; i < totalRuns; i++){
        if(!Evaluate(OpStack)){
            std::cout << "Something went wrong when calculating value off of operand stack.\n";
            std::cout << "Terminating program...\n";
            exit(0);
        }
    }
    
}