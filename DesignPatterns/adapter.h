#ifndef ADAPTER_H
#define ADAPTER_H
#include <iostream>
using namespace  std;

class topLevelInterface{

    public : virtual ~topLevelInterface(){}
    public : virtual void running()=0;
};

template <class T>
class adapter : public topLevelInterface {

     public : adapter(T *o, void(T::*m)());
     public : void running();
     public : ~adapter();

     private : T* object;
     private : void ( T::*method)();
};
class highway{

     public : ~highway();
     public : void buildHighWayGraphMap();
};
class bookscanner{
     public : ~bookscanner();
     public : void scanBookContent();
};
class weatherForcast{
     public : ~weatherForcast();
     public : void predict();
};
topLevelInterface **init();
#endif // ADAPTER_H
