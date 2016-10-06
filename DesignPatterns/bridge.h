#ifndef BRIDGE_H
#define BRIDGE_H
#include <iostream>
class electronicsImp {

    public : std::string ports[6];
    public : std::string brand;
    public : int operatingVoltage;
    public : int batteryCapacity;
    public : electronicsImp();
    public : electronicsImp(std::string (&port)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity);
    public : virtual void pluggedIn();

};
class televisionImp : public electronicsImp{

    public : int resolution;
    public : televisionImp( std::string (&ports)[6], std::string &brand,
    int operatingVoltage, int batteryCapacity,int resolution);
    public : void pluggedIn();
};
class computerImp : public electronicsImp{

    public : int cpuCores;
    public : int ram;
    public : int ssd;
    public : computerImp( std::string (&ports)[6], std::string &brand,
    int operatingVoltage, int batteryCapacity,int cpuCores, int ram, int ssd);
    public : void pluggedIn();

};
class smartphoneImp : public electronicsImp{

    public : int cpuCores;
    public : int ram;
    public : int screenSize;
    public : int usbVersion;
    public : std::string androidVersion;
    public : smartphoneImp(std::string (&ports)[6], std::string &brand,
    int operatingVoltage, int batteryCapacity, int cpuCores, int ram, int screenSize, std::string &androidVersion);
    public : void pluggedIn();

};
///////////////////////////////////////////////////////////////////////////////////////////

class electronics {

    public : electronicsImp* elec;
    public : ~electronics();
    public : electronics(std::string (&ports)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity);
    public : virtual void pluggedIn();

};
class television : public electronics{

    public : televisionImp* tel;
    public : television(std::string (&ports)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity,
                          int resolution);
    public : void pluggedIn();
};
class computer : public electronics{

    public : computerImp* com;
    public : computer(std::string (&ports)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity,
                          int cpuCores, int ram, int ssd);
    public : void pluggedIn();

};
class smartphone : public electronics{

    public : smartphoneImp* smart;
    public : smartphone( std::string (&ports)[6], std::string &brand, int usbVersion, int batteryCapacity,
                            int cpuCores, int ram, int ssd, std::string &androidVersion);
    public : void pluggedIn();

};

#endif // BRIDGE_H
