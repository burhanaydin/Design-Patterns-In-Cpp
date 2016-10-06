#ifndef CHAINOFRESPONSIBILITY_H
#define CHAINOFRESPONSIBILITY_H
#include <vector>

using namespace std;

class primitive{

    public : int variable;
    public : primitive* next;
    public : primitive(int variable, primitive* p);
    public : virtual void visit();
    public : virtual void traverse();
    public : void setNext(primitive* next);
};

class developed : public primitive{

    public : developed(int variable, primitive* p=0);
    public : void visit();
    public : void traverse();

};
class primitiveCompound : public primitive{

    public : vector<primitive*> prim;
    public : primitiveCompound(int variable, primitive* p=0);
    public : void add(primitive* p);
    public : void visit();
    public : void traverse();
};

#endif // CHAINOFRESPONSIBILITY_H
