#include <iostream>
#include "bridge.h"
#include "string.h"
#include "stdio.h"
using  namespace std;
electronicsImp::electronicsImp(){

}

electronicsImp::electronicsImp(std::string (&port)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity){
    this->operatingVoltage = operatingVoltage;
    this->batteryCapacity = batteryCapacity;
    this->brand = brand;
    std::copy(port, port+6, ports);
}
void electronicsImp::pluggedIn(){

    cout << "Brand        : " << this->brand << endl;
    cout << "Device Ports : " << ports[0] << "\t" <<
            ports[1] << "\t" << ports[2] << "\t" << ports[3] <<
         "\t" << ports[4] << "\t" << ports[5] << endl;
    cout << "Voltage      : " << operatingVoltage << endl;
    cout << "Battery      : " << batteryCapacity << endl;
}
televisionImp::televisionImp(std::string (&ports)[6], std::string &brand,
int operatingVoltage, int batteryCapacity,int resolution):electronicsImp(ports,brand,operatingVoltage,batteryCapacity){
    this->resolution = resolution;
}
void televisionImp::pluggedIn(){
    electronicsImp::pluggedIn();
    cout << "Resolution   : " << this->resolution << endl;
}
computerImp::computerImp(std::string (&ports)[6], std::string &brand,
int operatingVoltage, int batteryCapacity,int cpuCores, int ram, int ssd):electronicsImp(ports,brand,operatingVoltage,batteryCapacity){
    this->cpuCores = cpuCores;
    this->ram = ram;
    this->ssd = ssd;
}
void computerImp::pluggedIn(){
    electronicsImp::pluggedIn();
    cout << "Cpu Cores    : " << this->cpuCores << endl;
    cout << "Ram          : " << this->ram << endl;
    cout << "Ssd          : " << this->ssd << endl;
}
smartphoneImp::smartphoneImp(std::string (&ports)[6], std::string &brand,
int operatingVoltage, int batteryCapacity,int cpuCores, int ram, int screenSize, std::string &androidVersion):electronicsImp(ports,brand,operatingVoltage,batteryCapacity){
    this->usbVersion = usbVersion;
    this->cpuCores = cpuCores;
    this->ram = ram;
    this->screenSize = screenSize;
    this->androidVersion = androidVersion;
}
void smartphoneImp::pluggedIn(){
    electronicsImp::pluggedIn();
    cout << "Cpu Cores    : " << this->cpuCores << endl;
    cout << "Ram          : " << this->ram << endl;
    cout << "Screen Size  : " << this->screenSize << endl;
    cout << "Usb Version  : " << "Usb 3" << endl;
}
/////////////////////////////////////////////////////////////////////////////////////////
electronics::~electronics(){

}
electronics::electronics(std::string (&ports)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity){
    cout << "electronics" << endl;
    this->elec = new electronicsImp(ports,brand,operatingVoltage,batteryCapacity);

}
void electronics::pluggedIn(){
    cout << "electronics->pluggedIn()" << endl;
    this->elec->pluggedIn();
}
television::television(std::string (&ports)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity, int resolution):electronics(ports, brand, operatingVoltage, batteryCapacity){
    cout << "television" << endl;
    this->tel = new televisionImp(ports,brand,operatingVoltage,batteryCapacity,resolution);
    cout << "television constructed" << endl;
}
void television::pluggedIn(){
    cout << "television->pluggedIn()" << endl;
    this->tel->pluggedIn();
}
computer::computer(std::string (&ports)[6], std::string &brand,
                          int operatingVoltage, int batteryCapacity,
                          int cpuCores, int ram, int ssd):electronics(ports, brand,operatingVoltage,batteryCapacity){
    cout << "computer" << endl;
    this->com = new computerImp(ports,brand,operatingVoltage,batteryCapacity,cpuCores,ram,ssd);
    cout << "computer constructed" << endl;
}
void computer::pluggedIn(){
    cout << "computer->pluggedIn()" << endl;
    this->com->pluggedIn();
}
smartphone::smartphone(std::string (&ports)[6], std::string &brand, int usbVersion, int batteryCapacity,
                            int cpuCores, int ram, int ssd, std::string &androidVersion):electronics(ports,brand,5,batteryCapacity){

    cout << "smartphone" << endl;
    this->smart = new smartphoneImp(ports,brand,5,batteryCapacity,cpuCores,ram,ssd,androidVersion);
    cout << "smartphone constructed" << endl;
}
void smartphone::pluggedIn(){
    cout << "smartphone->pluggedIn()" << endl;
    this->smart->pluggedIn();
}
