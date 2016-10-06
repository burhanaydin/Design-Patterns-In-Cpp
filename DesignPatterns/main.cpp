#include <QCoreApplication>
using namespace std;
#include <time.h>
#include <ctime>
#include <stdio.h>
#include "abstractionoccurence.h"
#include "adapter.h"
#include "bridge.h"
#include "builder.h"
#include "chainofresponsibility.h"
#include "command.h"
#include "facade.h"

const int num_parts = 42;
robotStructure input[num_parts]={

     { cables, "1.5m USB Cable Type A to B"},
     { cables, "SIRC-01 Sharp GP2 IR Sensor Cable - 8"},
     { cables, "Arduino Jumper Cables (65pk)"},
     { wires, "140 Piece Pre-formed Jumper Wire Kit"},
     { wires, "25' #22 Gauge Green Hook-Up Wire"},
     { wires, "300mm F/F 20 Pin Jumper Wire (Splittable)"},
     { connectors, "Quick Connect Battery Connector"},
     { connectors, "WH-01 Wiring Harness with Battery Connector"},
     { connectors, "2mm 10pin XBee Socket"},
     { communicationTool, "DFRobot Serial Bluetooth Module"},
     { communicationTool, "Maxstream 1mW XBee Transceiver Module (Wire Antennae)"},
     { communicationTool, "WiFi Serial Transceiver Module w/ ESP8266"},
     { control, "Leap Motion 3D Motion Controller"},
     { control, "DFRobot IR Remote Kit for Arduino"},
     { control, "Hubsan FPV DIY Remote Control Set"},
     { dataStorage, "Hubsan FPV X4 Mini Quadcopter MicroSD Card 4GB"},
     { dataStorage, "DFRobot EEPROM Data Storage Module For Arduino"},
     { dataStorage, "Parallax Smart Card Reader"},
     { interfaceAdapters, "Phidgets PhidgetBridge Wheatstone Bridge Sensor Interface"},
     { interfaceAdapters, "Owi USB Interface For Robotic Arm Edge"},
     { interfaceAdapters, "Devantec USB to I2C, SPI and Serial interface"},
     { converter, "Logic Level Converter Bidirectional"},
     { converter, "CPT-C5 5V Power Converter"},
     { converter, "MCP3424 4-Channel 18-bit Analog to Digital Converter w/ Programmable Gain "},
     { dislpay, "DFRobot I2C / TWI 4x20 LCD Module"},
     { dislpay, "16x2 LCD Shield Kit for Arduino"},
     { dislpay, "SeeedStudio 16 x 2 Green LCD w/ Yellow Back Light"},
     { lightning, "5mm Triple Output LED RGB (20pk)"},
     { lightning, "SFE Piezo Clicking Igniter"},
     { lightning, "NeoPixel Stick - 8x RGB LED"},
     { mechanics, "Lynxmotion Pan and Tilt Kit / Aluminium"},
     { mechanics, "Lynxmotion Track Sprocket - 6 Tooth (Pair) SPRK-01"},
     { mechanics, "Lynxmotion HUB-02 Universal Hub - 6mm (pair)"},
     { motors, "HS-645MG Servo Motor"},
     { motors, "Neato XV Wheel Motor"},
     { motors, "12V, 350mA, 28oz-in NEMA-17 Bipolar Stepper Motor"},
     { actuators, "L12 12V 100mm 100:1 PLC/RC Miniature Linear Actuator"},
     { actuators, "Flexinol Electrostem II Air Valve"},
     { actuators, "Mounting Bracket for all ZYJ(s) and FA-150 model Actuators"},
     { sensors, "Pan/Tilt Kit for Pixy CMUcam5 Image Sensor"},
     { sensors, "Lynxmotion Aluminum Multi-Purpose Sensor Bracket MPSH-01"},
     { sensors, "DFRobot Adjustable Infrared Sensor Bracket"}
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    srand(time(0));

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                            ABSTRACTION - FACTORY  PATTERN                                                       ///
    ///                                                                                                                 ///
    ///   ||||||||||||||||                 ||||||||||||||||||||||                                                       ///
    ///   |              |                 |                    |                                                       ///
    ///   |    Client    |---------------->|   AbstractFactory  |                                                       ///
    ///   |              |                 |____________________|                                                       ///
    ///   ||||||||||||||||                 |  CreateProductA()  |                                                       ///
    ///        |  |                        |  CreateProductB()  |                                                       ///
    ///        |  |                        ||||||||||||||||||||||                                                       ///
    ///        |  |                                  /\                                                                 ///
    ///        |  |                                 /__\                                                                ///
    ///        |  |                  _________________|________________                                                 ///
    ///        |  |                 |                                  |                                                ///
    ///        |  |                 |                                  |                                                ///
    ///        |  |                 |                                  |                                                ///
    ///        |  |      ||||||||||||||||||||||             ||||||||||||||||||||||                                      ///
    ///        |  |      |                    |             |                    |                                      ///
    ///        |  |      |  ConcreteFactory1  |             |  ConcreteFactory2  |                                      ///
    ///        |  |      |____________________|             |____________________|                                      ///
    ///        |  |      |  CreateProductA()  |             |  CreateProductA()  |                                      ///
    ///        |  |      |  CreateProductB()  |             |  CreateProductB()  |                                      ///
    ///        |  |      ||||||||||||||||||||||             ||||||||||||||||||||||                                      ///
    ///        |  |                                                                                                     ///
    ///        |  |______________________________________________________________________                               ///
    ///        |                                                                        |                               ///
    ///        |                                                                        v                               ///
    ///        |          ||||||||||||||||||||||                              ||||||||||||||||||||||                    ///
    ///        |          |                    |                              |                    |                    ///
    ///        |--------->|  AbstractProductA  |                              |  AbstractProductB  |                    ///
    ///                   |                    |                              |                    |                    ///
    ///                   ||||||||||||||||||||||                              ||||||||||||||||||||||                    ///
    ///                             /\                                                   /\                             ///
    ///                            /__\                                                 /__\                            ///
    ///                  ____________|____________                          ______________|____________                 ///
    ///                 |                        |                          |                         |                 ///
    ///                 |                        |                          |                         |                 ///
    ///      ||||||||||||||||||||||     ||||||||||||||||||||||       ||||||||||||||||||||||     ||||||||||||||||||||||  ///
    ///      |                    |     |                    |       |                    |     |                    |  ///
    ///      |      ProductA1     |     |      ProductA2     |       |      ProductB1     |     |      ProductB2     |  ///
    ///      |                    |     |                    |       |                    |     |                    |  ///
    ///      ||||||||||||||||||||||     ||||||||||||||||||||||       ||||||||||||||||||||||     ||||||||||||||||||||||  ///
    ///                                                                                                                 ///
    ///                                                                                                                 ///
    ///                                                                                                                 ///
    ///                                                                                                                 ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    item* items[10];
    freeItemFactory *freeFactory = new freeItemFactory();
    nonFreeItemFactory *nonFreeFactory = new nonFreeItemFactory();

    char submissionDate[] = "12/06/2016";
    char borrowDate[] = "12/03/2016";
    items[0] = freeFactory->formFreeItemInstance(123456789, borrowDate , submissionDate, 20);
    items[0]->setName("Extinction Parade 2: War");
    items[0]->setAuthor("Max Brooks");
    items[0]->setISBN( 1592912551);
    items[0]->setPublicationDate("April 2015");
    items[0]->setLibOfCongress("Library of Congress");
    items[0]->setPenalty( items[0]->calculatePayment( items[0]->getSubmissionLatencyFee(), 10 ));

    items[1] = freeFactory->formFreeItemInstance(0, "", "" , 0);
    items[1]->setISBN(463645756876);
    items[1]->setAuthor("xxxxxxxx");
    items[1]->setName("xxxxxxxxxx");
    items[1]->setLibOfCongress("Library of Congress");
    items[1]->setPublicationDate("01/01/2014");

    strcpy(submissionDate, "04/06/2016");
    strcpy(borrowDate, "15/04/2015");
    items[2] = freeFactory->formFreeItemInstance(123456798, borrowDate, submissionDate, 5);
    items[2]->setName("Closure, Limited: And Other Zombie Tales");
    items[2]->setAuthor("Max Brooks");
    items[2]->setISBN( 715642931);
    items[2]->setPublicationDate("2012");
    items[2]->setLibOfCongress("Library of Congress");
    items[2]->setPenalty( items[2]->calculatePayment( items[2]->getSubmissionLatencyFee(), 10 ));

    items[3] = freeFactory->formFreeItemInstance(0, "", "" , 0);
    items[3]->setISBN(463645756876);
    items[3]->setAuthor("xxxxxxxx");
    items[3]->setName("xxxxxxxxxx");
    items[3]->setLibOfCongress("Library of Congress");
    items[3]->setPublicationDate("01/01/2014");

    strcpy(submissionDate, "04/10/2016");
    strcpy(borrowDate , "15/09/2015");
    items[4] = freeFactory->formFreeItemInstance(125456798,borrowDate,submissionDate, 7);
    items[4]->setName("The Zombie Survival Guide: Recorded Attacks");
    items[4]->setAuthor("Max Brooks");
    items[4]->setISBN( 715643051);
    items[4]->setPublicationDate("Feb 1, 2012");
    items[4]->setLibOfCongress("Library of Congress");
    items[4]->setPenalty( items[4]->calculatePayment( items[4]->getSubmissionLatencyFee(), 14 ));

    items[5] = freeFactory->formFreeItemInstance(0, "", "" , 0);
    items[5]->setISBN(463645756876);
    items[5]->setAuthor("xxxxxxxx");
    items[5]->setName("xxxxxxxxxx");
    items[5]->setLibOfCongress("Library of Congress");
    items[5]->setPublicationDate("01/01/2014");

    std::string trends[] = {"Sport-Luxe Trousers", "Asymmetrical Pants", "Extra-Long Sleeves"};
    items[6] = nonFreeFactory->formNonFreeItemInstance("July", trends, 30, 11);
    items[6]->setName("Who What Wear");
    items[6]->setAuthor("Jhon Fulker, Ceremy Ann, et al.");
    items[6]->setISBN(458769852);
    items[6]->setPublicationDate("July 1, 2016");
    items[6]->setLibOfCongress("Casual");
    items[6]->setPrice( items[6]->calculatePayment( items[6]->getMountlyWage(), 14 ));

    std::string s[] = {"",""};
    items[7] = nonFreeFactory->formNonFreeItemInstance("", s, 0 , 0);
    items[7]->setISBN(463645756876);
    items[7]->setAuthor("xxxxxxxx");
    items[7]->setName("xxxxxxxxxx");
    items[7]->setLibOfCongress("Library of Congress");
    items[7]->setPublicationDate("01/01/2014");

    std::string trends2[] = {"White T-Shirts", "Gladiator Sandals", "Hollywood's New It-Shirt"};
    items[8] = nonFreeFactory->formNonFreeItemInstance("March", trends2, 25, 30);
    items[8]->setName("ELLE");
    items[8]->setAuthor("Micheal Dinny, Bod Zylle, et al.");
    items[8]->setISBN( 42315892);
    items[8]->setPublicationDate("March 1, 2016");
    items[8]->setLibOfCongress("Casual");
    items[8]->setPrice( items[8]->calculatePayment( items[8]->getMountlyWage(), 3 ));

    for( unsigned int i=0; i < 9; i++){
      items[i]->toString();
      std::cout << "\n" ;
    }

    /////////////////////////////////////////////////////////////////////////////////////
    ///                        ADAPTER   PATTERN                                      ///
    ///                                                                               ///
    ///   |||||||||||||||||||||||              |||||||||||||||||||||||                ///
    ///   |                     |              |         Shape       |                ///
    ///   |       Client        |------------->|     <<Interface>>   |                ///
    ///   |                     |              |_____________________|                ///
    ///   |||||||||||||||||||||||              | display(x1,y1,x2,y2)|                ///
    ///                                        |||||||||||||||||||||||                ///
    ///                                                   /\                          ///
    ///                                                  /__\                         ///
    ///                                                    |                          ///
    ///                                                    |                          ///
    ///                                        |||||||||||||||||||||||                ///
    ///    |||||||||||||||||||||||             |      Rectangle      |                ///
    ///    |   LegacyRectangle   |<<-----------|_____________________|                ///
    ///    |      <<Adaptee>>    |             | display(x1,y1,x2,y2)|                ///
    ///    |_____________________|             |||||||||||||||||||||||                ///
    ///    | display(x1,y1,x2,y2)|                                                    ///
    ///    |||||||||||||||||||||||                                                    ///
    ///                                                                               ///
    ///                                                                               ///
    /////////////////////////////////////////////////////////////////////////////////////

    topLevelInterface **objects = init();
    for(int i=0; i < 3; i++){
        objects[i]->running();
    }
    for(int i=0; i < 3; i++){
        delete objects[i];
    }
    delete objects;


    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                        BRIDGE  PATTERN                                            ///
    ///                                                                                                   ///
    ///    ||||||||||||||||||||||||||                              |||||||||||||||||||||||||||            ///
    ///    |                        |                              |                         |            ///
    ///    | InterfaceIncapsulation |     -theImplement            |  InterfaceIncapsulation |            ///
    ///    |________________________|----------------------------->|_________________________|            ///
    ///    |                        |                              |     +doThisOne()        |            ///
    ///    |        +doThis()       |                              |     +doThisTwo()        |            ///
    ///    ||||||||||||||||||||||||||                              |||||||||||||||||||||||||||            ///
    ///                /\                                                        /\                       ///
    ///               /__\                                                      /__\                      ///
    ///                 |                                           ______________|____________           ///
    ///                 |                                           |                         |           ///
    ///                 |                                           |                         |           ///
    ///    |||||||||||||||||||||||||||                ||||||||||||||||||||||     ||||||||||||||||||||||   ///
    ///    |                         |                |                    |     |                    |   ///
    ///    | InterfaceSpecialization |                | ImplementationOne  |     | ImplementationTwo  |   ///
    ///    |                         |                |____________________|     |                    |   ///
    ///    |                         |                |    +doThisOne()    |     |                    |   ///
    ///    |                         |                |    +doThisTwo()    |     |                    |   ///
    ///    |||||||||||||||||||||||||||                ||||||||||||||||||||||     ||||||||||||||||||||||   ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////


    std::string ports[6] = {"USB Type C", "USB Type A", "HDMI", "Display Port",
                           "HeadPhone Jack", "Microfon Jack"};
    std::string brand = "LG";
    std::string androidVersion = "Marshmallow";
    std::cout << endl;
    electronics  *electronicsArray[3];
    electronicsArray[0] = new television(ports, brand, 5, 2000, 3840);
    std::cout<<endl;
    brand = "Dell";
    electronicsArray[1] = new computer(ports, brand, 12, 5000, 8, 16, 512);
    std::cout<<endl;
    brand = "Samsung";
    electronicsArray[2] = new smartphone(ports, brand, 3, 2000, 4, 4, 128, androidVersion);
    std::cout<<endl;
    for(int j=0; j < 3; j++){
        electronicsArray[j]->pluggedIn();
        std::cout<<endl;
    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                        BUILDER  PATTERN                                           ///
    ///                                                                                                   ///
    ///    ||||||||||||||||||||||||||                              |||||||||||||||||||||||||||            ///
    ///    |                        |                              |                         |            ///
    ///    |         Reader         |     -theCoverter             |         Converter       |            ///
    ///    |________________________|----------------------------->|_________________________|            ///
    ///    |                        |                              |        +makeLine()      |            ///
    ///    |        +parseInput()   |                              |        +makeParagraph() |            ///
    ///    //////////////////////////                              |        +makeTable()     |            ///
    ///                                                            |        +getDocument()   |            ///
    ///                                                            |||||||||||||||||||||||||||            ///
    ///                                                                          /\                       ///
    ///                                                                         /__\                      ///
    ///                                ___________________________________________|____________           ///
    ///                                |                            |                         |           ///
    ///                                |                            |                         |           ///
    ///                |||||||||||||||||||||||||||    ||||||||||||||||||||||     ||||||||||||||||||||||   ///
    ///                |                         |    |                    |     |                    |   ///
    ///                |      ASCIIConverter     |    | PostscriptConverter|     |     PDFConverter   |   ///
    ///                |                         |    |                    |     |                    |   ///
    ///                |                         |    |                    |     |                    |   ///
    ///                |                         |    |                    |     |                    |   ///
    ///                |||||||||||||||||||||||||||    ||||||||||||||||||||||     ||||||||||||||||||||||   ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////

    customer client;
    industrialRobotBuilder iBuilder;
    client.setBuilder(&iBuilder);
    client.order(input, 42);
    iBuilder.getResult()->getState();
    medicalRobotBuilder mBuilder;
    client.setBuilder(&mBuilder);
    client.order(input, 42);
    mBuilder.getResult()->getState();
    militaryRobotBuilder mlBuilder;
    client.setBuilder(&mlBuilder);
    client.order(input, 42);
    mlBuilder.getResult()->getState();
    houseHoldRobotBuilder hBuilder;
    client.setBuilder(&hBuilder);
    client.order(input, 42);
    hBuilder.getResult()->getState();
    serviceRobotBuilder sBuilder;
    client.setBuilder(&sBuilder);
    client.order(input, 42);
    sBuilder.getResult()->getState();
    spaceRobotBuilder spcBuilder;
    client.setBuilder(&spcBuilder);
    client.order(input, 42);
    spcBuilder.getResult()->getState();


    ////////////////////////////////////////////////////////////////////////////////////////////
    ///                        CHAIN OF RESPONSIBILITY PATTERN                               ///
    ///                                                                                      ///
    ///          ||||||||||||||||||||||                                                      ///
    ///          |                    |                                                      ///
    ///          |       Client       |___________________                                   ///
    ///          |                    |       request    |                                   ///
    ///          ||||||||||||||||||||||                  |                                   ///
    ///                                                  |                                   ///
    ///                                                  |                                   ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                        |     Processing     |                        ///
    ///                                        |       element      |                        ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                                  |                                   ///
    ///                                                  |                                   ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                        |    Processing      |                        ///
    ///                                        |      element       |                        ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                                  |                                   ///
    ///                                                  |                                   ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                        |    Processing      |                        ///
    ///                                        |      element       |                        ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                                  |                                   ///
    ///                                                  |                                   ///
    ///                                        ||||||||||||||||||||||                        ///
    ///                                        |    Processing      |                        ///
    ///                                        |      element       |                        ///
    ///                                        ||||||||||||||||||||||                        ///
    ////////////////////////////////////////////////////////////////////////////////////////////

    developed seven(7);
    developed six(6, &seven);
    primitiveCompound three(3, &six);
    three.add(&six);
    three.add(&seven);
    developed five(5, &three);
    developed four(4, &five);
    primitiveCompound two(2, &four);
    two.add(&four);
    two.add(&five);
    primitiveCompound one(1, &two);
    developed nine(9, &one);
    developed eight(8, &nine);
    one.add(&two);
    one.add(&three);
    one.add(&eight);
    one.add(&nine);
    seven.setNext(&eight);
    cout << "traverse " << endl;
    one.traverse();
    cout << "\n" ;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                        COMMAND  PATTERN                                           ///
    ///                                                                                                   ///
    ///    ||||||||||||||||||||||||||                              |||||||||||||||||||||||||||            ///
    ///    |                        |                              |     << interface >>     |            ///
    ///    |         Client         |                              |    CallBackInterface    |            ///
    ///    |________________________|----------------------------->|_________________________|            ///
    ///    |                        |                              |                         |            ///
    ///    |                        |                              |                         |            ///
    ///    ||||||||||||||||||||||||||                              |||||||||||||||||||||||||||            ///
    ///                                                                          /\                       ///
    ///                                                                         /__\                      ///
    ///                                                             ______________|____________           ///
    ///                                                             |                         |           ///
    ///                                                             |                         |           ///
    ///    |||||||||||||||||||||||||||                ||||||||||||||||||||||     ||||||||||||||||||||||   ///
    ///    |                         |                |                    |     |     CallBackTwo    |   ///
    ///    |        Receiver         |                |     CallBackOne    |     |____________________|   ///
    ///    |_________________________|                |____________________|     |    +targetMethod   |   ///
    ///    |        +doThis()        |                |                    |     |+Constructor        |   ///
    ///    |        +doThis()        |                ||||||||||||||||||||||     |(receiverObject,    |   ///
    ///    |||||||||||||||||||||||||||                                           |   methodPointer)   |   ///
    ///                 |                                                        |     +execute()     |   ///
    ///                 |                                                        ||||||||||||||||||||||   ///
    ///                 |                                                                  /|\            ///
    ///                 |___________________________________________________________________|             ///
    ///                                                                                                   ///
    ///                                                                                                   ///
    /////////////////////////////////////////////////////////////////////////////////////////////////////////


    std::string d[12] = {"Mark Time", "Forward", "Change step on the march", "Squad", "Attention",
                        "Stand at ease", "Attention", "Stand easy", "Squad will advance, left turn",
                        "Squad, right turn", "Squad will advance, about turn",
                        "Squad by the halt, left incline"};
    directives d1(d[0]);
    directives d2(d[1]);
    directives d3(d[2]);
    directives d4(d[3]);
    directives d5(d[4]);
    directives d6(d[5]);
    directives d7(d[6]);
    directives d8(d[7]);
    directives d9(d[8]);
    directives d10(d[9]);
    directives d11(d[10]);
    directives d12(d[11]);
    command *c[13];
    microCommand mic1(&d1, &directives::action);   c[0] = &mic1;
    microCommand mic2(&d2, &directives::action);   c[1] = &mic2;
    microCommand mic3(&d3, &directives::action);   c[2] = &mic3;
    microCommand mic4(&d4, &directives::action);   c[3] = &mic4;
    microCommand mic5(&d5, &directives::action);   c[4] = &mic5;
    microCommand mic6(&d6, &directives::action);   c[5] = &mic6;
    microCommand mic7(&d7, &directives::action);   c[6] = &mic7;
    microCommand mic8(&d8, &directives::action);   c[7] = &mic8;
    microCommand mic9(&d9, &directives::action);   c[8] = &mic9;
    microCommand mic10(&d10, &directives::action);   c[9] = &mic10;
    microCommand mic11(&d11, &directives::action);   c[10] = &mic11;
    microCommand mic12(&d12, &directives::action);   c[11] = &mic12;
    macroCommand m1;
    macroCommand m2;
    m2.add(c[5]);
    m2.add(c[9]);
    c[12] = &m2;
    m1.add(c[0]);
    m1.add(c[1]);
    m1.add(c[2]);
    m1.add(c[3]);
    m1.add(c[4]);
    m1.add(c[5]);
    m1.add(c[6]);
    m1.add(c[7]);
    m1.add(c[8]);
    m1.add(c[9]);
    m1.add(c[10]);
    m1.add(c[11]);
    m1.add(c[12]);
    std::string tmp = ", please";
    for(int j=0; j < 13; j++){
        c[j]->execute(tmp);
    }
    ///////////////////////////////////////////

    Queue<Command> queue;
    Command *commandArray[9];
    Command command1(new word, &word::grabIt);       commandArray[0] = &command1;
    Command command2(new word, &word::raiseIt);      commandArray[1] = &command2;
    Command command3(new word, &word::putItDown);    commandArray[2] = &command3;
    Command command4(new word, &word::grabIt);       commandArray[3] = &command4;
    Command command5(new word, &word::raiseIt);      commandArray[4] = &command5;
    Command command6(new word, &word::putItDown);    commandArray[5] = &command6;
    Command command7(new word, &word::grabIt);       commandArray[6] = &command7;
    Command command8(new word, &word::raiseIt);      commandArray[7] = &command8;
    Command command9(new word, &word::putItDown);    commandArray[8] = &command9;

    for( int i=0 ; i < 9; i++){
       queue.enqueue(commandArray[i]);
    }
    for( int i=0 ; i < 9 ; i++){
       queue.dequeue()->execute();
    }
    std::cout << std::endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ///                                        FACADE   PATTERN                                                         ///
    ///                                                                                                                 ///
    ///    ||||||||||||||||||||||||||             |||||||||||||||||||||||||||           |||||||||||||||||||||||||||     ///
    ///    |                        |             |     << interface >>     |           |                         |     ///
    ///    |     SubsystemOne       |             |   SubsystemTwoWrapper   |           |    SubsystemThree       |     ///
    ///    |________________________|------------>|_________________________|<----------|                         |     ///
    ///    |                        |             |                         |           |                         |     ///
    ///    |                        |             |   +primeTheDirective()  |           |||||||||||||||||||||||||||     ///
    ///    ||||||||||||||||||||||||||             |||||||||||||||||||||||||||                                           ///
    ///                                          /\             |         /\                                            ///
    ///                                          \/             |         \/                                            ///
    ///                                           |             |          |                                            ///
    ///               ____________________________|             |          |________________________                    ///
    ///              \|/                          |            \|/                |               \|/                   ///
    ///    |||||||||||||||||||||||||||            |   ||||||||||||||||||||||      |      ||||||||||||||||||||||         ///
    ///    |                         |            |   |                    |      |      |       HoloDeck     |         ///
    ///    |       PlasmaConduit     |        |---s---|      WrapCore      |------s----->|____________________|         ///
    ///    |_________________________|        |   |   |____________________|      |      |                    |         ///
    ///    |                         |        |   |   |                    |      |      |                    |         ///
    ///    |                         |        |   |   ||||||||||||||||||||||      |      ||||||||||||||||||||||         ///
    ///    |||||||||||||||||||||||||||        |   |             |                 |                                     ///
    ///                                       |   |             |                 |_________________                    ///
    ///                                       |   |            \|/                                \|/                   ///
    ///    |||||||||||||||||||||||||||        |   |   ||||||||||||||||||||||             ||||||||||||||||||||||         ///
    ///    |                         |        |   |   |                    |             |        Weapon      |         ///
    /// -->|       JeferriesTube     |        |   |   |   DilithumChamber  |             |____________________|         ///
    /// |  |_________________________|<-------|   |   |____________________|             |                    |         ///
    /// |  |                         |            |   |                    |             |                    |         ///
    /// |  |                         |<-----------|   ||||||||||||||||||||||             ||||||||||||||||||||||         ///
    /// |  |||||||||||||||||||||||||||            |                                                /\                   ///
    /// |                                         |                                               /__\                  ///
    /// |               __________________________|                                 ________________|________           ///
    /// |              \|/                                                         |                         |          ///
    /// |  |||||||||||||||||||||||||||        ||||||||||||||||||||||    ||||||||||||||||||||||   |||||||||||||||||||||| ///
    /// |  |                         |        |                    |    |       PhaserBack   |   |    PhotonTorpedo   | ///
    /// |  |       Transporter       |        |      TurboLift     |    |____________________|   |____________________| ///
    /// |__|_________________________|K|------|____________________|    |                    |   |                    | ///
    ///    |                         |        |                    |    |                    |   |                    | ///
    ///    |                         |        ||||||||||||||||||||||    ||||||||||||||||||||||   |||||||||||||||||||||| ///
    ///    |||||||||||||||||||||||||||                                                                                  ///
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Point p1(2,4);
    Point p2(5,7);
    Point p3(2,1);
    Point p4(2.866,1.5);
    Line l1(&p1, &p2);
    l1.move(-2,-4);
    l1.rotate(35);
    std::cout << "Line 1 after rotation " << endl;
    l1.toString();
    std::cout << endl;
    Line l2(&p3, &p4);
    l2.move(1,5);
    l2.rotate(46);
    std::cout << "Line 2 after rotation " << endl;
    l2.toString();

    return a.exec();
}
