#ifndef BUILDER_H
#define BUILDER_H
#include <stdio.h>
#include <string.h>
using namespace std;
enum robotParts{
    cables,wires,connectors,communicationTool,control,dataStorage,interfaceAdapters,converter,dislpay,
    lightning,mechanics,motors,actuators,sensors
};
struct robotStructure{
    robotParts rbtParts;
    char *value;
};
class distributedTaskUnit{

    private : char intricateState[43][200];
    private : static int index;
    private : char temp[200];
    public : void getState();
    public : distributedTaskUnit(char* purpose);
    public : void setCables(char* model, char* value, int performancePenalty, int cost);
    public : void setWires(char* model, char* value, int performancePenalty, int cost);
    public : void setConnectors(char* model, char* value, int performancePenalty, int cost);
    public : void setCommunicationTool(char* model, char* value, int performancePenalty, int cost);
    public : void setControl(char* model, char* value, int performancePenalty, int cost);
    public : void setDataStorage(char* model, char* value, int performancePenalty, int cost);
    public : void setInterfaceAdapters(char* model, char* value, int performancePenalty, int cost);
    public : void setConverter(char* model, char* value, int performancePenalty, int cost);
    public : void setDisplay(char* model, char* value, int performancePenalty, int cost);
    public : void setLightning(char* model, char* value, int performancePenalty, int cost);
    public : void setMechanics(char* model, char* value, int performancePenalty, int cost);
    public : void setMotors(char* model, char* value, int performancePenalty, int cost);
    public : void setActuators(char* model, char* value, int performancePenalty, int cost);
    public : void setSensors(char* model, char* value, int performancePenalty, int cost);
};

class builder{

    protected : distributedTaskUnit* dTaskUnitResult;
    public : virtual void configureCables(char* value)=0;
    public : virtual void configureWires(char* value)=0;
    public : virtual void configureConnectors(char* value)=0;
    public : virtual void configureCommunicationTools(char* value)=0;
    public : virtual void configureControl(char* value)=0;
    public : virtual void configureDataStorage(char* value)=0;
    public : virtual void configureInterfaceAdapters(char* value)=0;
    public : virtual void configureConverter(char* value)=0;
    public : virtual void configureDisplay(char* value)=0;
    public : virtual void configureLightning(char* value)=0;
    public : virtual void configureMechanics(char* value)=0;
    public : virtual void configureMotors(char* value)=0;
    public : virtual void configureActuators(char* value)=0;
    public : virtual void configureSensors(char* value)=0;
    public : distributedTaskUnit* getResult();
};
class industrialRobotBuilder : public builder{

    public : industrialRobotBuilder();
    public : void configureCables(char* value);
    public : void configureWires(char* value);
    public : void configureConnectors(char* value);
    public : void configureCommunicationTools(char* value);
    public : void configureControl(char* value);
    public : void configureDataStorage(char* value);
    public : void configureInterfaceAdapters(char* value);
    public : void configureConverter(char* value);
    public : void configureDisplay(char* value);
    public : void configureLightning(char* value);
    public : void configureMechanics(char* value);
    public : void configureMotors(char* value);
    public : void configureActuators(char* value);
    public : void configureSensors(char* value);
};
class houseHoldRobotBuilder : public builder{

    public : houseHoldRobotBuilder();
    public : void configureCables(char* value);
    public : void configureWires(char* value);
    public : void configureConnectors(char* value);
    public : void configureCommunicationTools(char* value);
    public : void configureControl(char* value);
    public : void configureDataStorage(char* value);
    public : void configureInterfaceAdapters(char* value);
    public : void configureConverter(char* value);
    public : void configureDisplay(char* value);
    public : void configureLightning(char* value);
    public : void configureMechanics(char* value);
    public : void configureMotors(char* value);
    public : void configureActuators(char* value);
    public : void configureSensors(char* value);
};
class medicalRobotBuilder : public builder{

    public : medicalRobotBuilder();
    public : void configureCables(char* value);
    public : void configureWires(char* value);
    public : void configureConnectors(char* value);
    public : void configureCommunicationTools(char* value);
    public : void configureControl(char* value);
    public : void configureDataStorage(char* value);
    public : void configureInterfaceAdapters(char* value);
    public : void configureConverter(char* value);
    public : void configureDisplay(char* value);
    public : void configureLightning(char* value);
    public : void configureMechanics(char* value);
    public : void configureMotors(char* value);
    public : void configureActuators(char* value);
    public : void configureSensors(char* value);
};
class serviceRobotBuilder : public builder{

    public : serviceRobotBuilder();
    public : void configureCables(char* value);
    public : void configureWires(char* value);
    public : void configureConnectors(char* value);
    public : void configureCommunicationTools(char* value);
    public : void configureControl(char* value);
    public : void configureDataStorage(char* value);
    public : void configureInterfaceAdapters(char* value);
    public : void configureConverter(char* value);
    public : void configureDisplay(char* value);
    public : void configureLightning(char* value);
    public : void configureMechanics(char* value);
    public : void configureMotors(char* value);
    public : void configureActuators(char* value);
    public : void configureSensors(char* value);
};
class militaryRobotBuilder : public builder{

    public : militaryRobotBuilder();
    public : void configureCables(char* value);
    public : void configureWires(char* value);
    public : void configureConnectors(char* value);
    public : void configureCommunicationTools(char* value);
    public : void configureControl(char* value);
    public : void configureDataStorage(char* value);
    public : void configureInterfaceAdapters(char* value);
    public : void configureConverter(char* value);
    public : void configureDisplay(char* value);
    public : void configureLightning(char* value);
    public : void configureMechanics(char* value);
    public : void configureMotors(char* value);
    public : void configureActuators(char* value);
    public : void configureSensors(char* value);
};
class spaceRobotBuilder : public builder{

    public : spaceRobotBuilder();
    public : void configureCables(char* value);
    public : void configureWires(char* value);
    public : void configureConnectors(char* value);
    public : void configureCommunicationTools(char* value);
    public : void configureControl(char* value);
    public : void configureDataStorage(char* value);
    public : void configureInterfaceAdapters(char* value);
    public : void configureConverter(char* value);
    public : void configureDisplay(char* value);
    public : void configureLightning(char* value);
    public : void configureMechanics(char* value);
    public : void configureMotors(char* value);
    public : void configureActuators(char* value);
    public : void configureSensors(char* value);
};
class customer {
    private : builder* b;
    public : void setBuilder(builder* b);
    public : void order(robotStructure r[42], int num);
};

#endif // BUILDER_H
