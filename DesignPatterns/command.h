#ifndef COMMAND_H
#define COMMAND_H
#include <iostream>
#include <vector>
//////////////////////////////////////////////////////////////
/// \brief The directives class
///
//////////////////////////////////////////////////////////////
class directives{
    public : std::string directive;
    public : directives(std::string &d);
    public : void action(std::string &s);
};
class command{
    public : virtual void execute(std::string &s)=0;
};
class microCommand : public command{

    typedef void(directives::*Method)(std::string &s);
    public : directives* drc;
    public : Method m;
    public : microCommand(directives* d, Method m);
    public : void execute(std::string &s);
};
class macroCommand : public command{

    public : std::vector <command *> commandList;
    public : void add(command* c);
    public : void execute(std::string &s);
};
/////////////////////////////////////////////////////////////
/// \brief The word class
///
/////////////////////////////////////////////////////////////
class word{

    private : static int next_word;
    private : int word_id;
    public : word();
    public : void grabIt();
    public : void raiseIt();
    public : void putItDown();
};

class Command{

    public : typedef void(word::*Method)();
    private : word* w;
    private : Method m;
    public : Command(word *w, Method m);
    public : void execute();
};

template<typename T>
class Queue{

    private : enum{
        SIZE=9
    };
    private : T* commandArray[SIZE];
    private : int m_added = 0, m_removed = 0;

    public : void enqueue(T* t){

            commandArray[m_added] = t;
            m_added = (m_added + 1) % SIZE;
        }
    public : T* dequeue(){
            int temp = m_removed;
            m_removed = (m_removed + 1) % SIZE;
            return commandArray[temp];
        }
};

#endif // COMMAND_H
