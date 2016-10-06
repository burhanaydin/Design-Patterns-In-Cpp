#include <iostream>
#include <vector>
#include "chainofresponsibility.h"
#include <ctime>

primitive::primitive(int variable, primitive* p=0){
    this->variable = variable;
    this->next = p;
}
void primitive::visit(){
    std::cout << variable << " - ";
}
void primitive::traverse(){
    next->visit();
}
void primitive::setNext(primitive *next){
    this->next = next;
}
developed::developed(int variable, primitive* p) : primitive(variable, p){

}
void developed::visit(){
    primitive::visit();
    if(rand()*100%6 == 0)
        primitive::traverse();
}
void developed::traverse(){
    primitive::traverse();
}

primitiveCompound::primitiveCompound(int variable, primitive* p) : primitive(variable,p){

}
void primitiveCompound::add(primitive *p){
    prim.push_back(p);
}
void primitiveCompound::visit(){
    primitive::visit();
    for(unsigned int i=0; i < prim.size(); i++){
        prim[i]->visit();
    }
}
void primitiveCompound::traverse(){
    primitive::traverse();
}
