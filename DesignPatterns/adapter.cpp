#include <iostream>
#include "adapter.h"
using namespace  std;

template <class T>
adapter<T>::adapter( T * o, void(T:: *m)()){
   object = o;
   method = m;
}
template <class T>
adapter<T>::~adapter(){
  delete object;
}
template <class T>
void adapter<T>::running(){

    (object->*method)();
}

highway::~highway(){
    cout << "high way maintenace" << endl;
}

void highway::buildHighWayGraphMap(){
    cout << " Building new highways" << endl;
}
bookscanner::~bookscanner(){
    cout << "Detaching the book" << endl;
}
void bookscanner::scanBookContent(){
    cout << "Scanning new book" << endl;
}
weatherForcast::~weatherForcast(){
    cout << "Prediction review period" << endl;
}
void weatherForcast::predict(){
    cout << "it may rain today" << endl;
}
topLevelInterface **init(){

    topLevelInterface **array = new topLevelInterface *[3];

    array[0] = new adapter<highway>(new highway(), &highway::buildHighWayGraphMap);
    array[1] = new adapter<bookscanner>(new bookscanner(), &bookscanner::scanBookContent);
    array[2] = new adapter<weatherForcast>(new weatherForcast(), &weatherForcast::predict);

    return array;
}
