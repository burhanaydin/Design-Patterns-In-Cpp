#include <iostream>
#include <vector>
#include "command.h"

//////////////////////////////////////////////////////
/// \brief directives::directives
/// \param d
//////////////////////////////////////////////////////
directives::directives(std::string &d){
    this->directive = d;
}
void directives::action(std::string &s){
    std::cout << "Here is the action command :  " << this->directive << s << std::endl;
}
microCommand::microCommand(directives *d, Method m){
    this->drc = d;
    this->m = m;
}
void microCommand::execute(std::string &s){
    (this->drc->*m)(s);
}
void macroCommand::add(command* c){
    commandList.push_back(c);
}
void macroCommand::execute(std::string &s){

    for(unsigned int i=0; i < commandList.size(); i++){
        commandList[i]->execute(s);
    }
}
/////////////////////////////////////////////////////
/// \brief word::word
///
/////////////////////////////////////////////////////

int word::next_word = 0;
word::word(){

    this->word_id = next_word++;
}
void word::grabIt(){
    std::cout << "Grabbed it" << std::endl;
}
void word::raiseIt(){
    std::cout << "Raised it" << std::endl;
}
void word::putItDown(){
    std::cout << "Put it down" << std::endl;
}
Command::Command(word *w, Method m) : w(w), m(m){

}
void Command::execute(){
    (w->*m)();
}
