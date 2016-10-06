#include <stdio.h>
#include <iostream>
#include <string.h>
#include "builder.h"
using namespace std;
int distributedTaskUnit::index=0;
distributedTaskUnit::distributedTaskUnit( char* purpose){
    distributedTaskUnit::index = 0;
    sprintf(intricateState[distributedTaskUnit::index++], "Distributed Work for %s", purpose);
}

void distributedTaskUnit::getState(){
    for(int i=0; i < 42; i++){
        std::cout << this->intricateState[i] << endl;
        std::cout << endl;
    }
    std::cout << endl;
}

void distributedTaskUnit::setCables(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the cable : %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setWires(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the wire : %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setConnectors(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the connector : %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setCommunicationTool(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the communication tool %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setControl(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the controller %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setDataStorage(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the data storage unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setInterfaceAdapters(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the interface adapter %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setConverter(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the converter %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}


void distributedTaskUnit::setDisplay(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the display unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setLightning(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the lightning unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}

void distributedTaskUnit::setMechanics(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the mechanics unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}
void distributedTaskUnit::setMotors(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the motor unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}
void distributedTaskUnit::setActuators(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the actuator unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}
void distributedTaskUnit::setSensors(char *model, char *value, int performancePenalty, int cost){

    sprintf(temp, "the sensor unit %s with %s model was added into the structure"
                  " its performace penalty is %d, cost is %d", value, model, performancePenalty,cost);
    strcat(intricateState[distributedTaskUnit::index++],temp);
    temp[0] = '\0';
}
distributedTaskUnit* builder::getResult(){
    return dTaskUnitResult;
}

industrialRobotBuilder::industrialRobotBuilder(){
    dTaskUnitResult = new distributedTaskUnit("Industrial Robot");
}
void industrialRobotBuilder::configureCables(char *value){
    dTaskUnitResult->setCables("xxxxxx",value,8, 5);
}
void industrialRobotBuilder::configureWires(char *value){
    dTaskUnitResult->setWires("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureConnectors(char *value){
    dTaskUnitResult->setConnectors("xxxxxx",value,3, 6);
}
void industrialRobotBuilder::configureCommunicationTools(char *value){
    dTaskUnitResult->setCommunicationTool("xxxxxx",value,3, 7);
}
void industrialRobotBuilder::configureControl(char *value){
    dTaskUnitResult->setControl("xxxxxx",value,3, 8);
}
void industrialRobotBuilder::configureDataStorage(char *value){
    dTaskUnitResult->setDataStorage("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureInterfaceAdapters(char *value){
    dTaskUnitResult->setInterfaceAdapters("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureConverter(char *value){
    dTaskUnitResult->setConverter("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureDisplay(char *value){
    dTaskUnitResult->setDisplay("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureLightning(char *value){
    dTaskUnitResult->setLightning("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureMechanics(char *value){
    dTaskUnitResult->setMechanics("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureMotors(char *value){
    dTaskUnitResult->setMotors("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureActuators(char *value){
    dTaskUnitResult->setActuators("xxxxxx",value,3, 11);
}
void industrialRobotBuilder::configureSensors(char *value){
    dTaskUnitResult->setSensors("xxxxxx",value,3, 11);
}

houseHoldRobotBuilder::houseHoldRobotBuilder(){
    dTaskUnitResult = new distributedTaskUnit("Household Robot");
}
void houseHoldRobotBuilder::configureCables(char *value){
    dTaskUnitResult->setCables("xxxxxx",value,8, 5);
}
void houseHoldRobotBuilder::configureWires(char *value){
    dTaskUnitResult->setWires("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureConnectors(char *value){
    dTaskUnitResult->setConnectors("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureCommunicationTools(char *value){
    dTaskUnitResult->setCommunicationTool("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureControl(char *value){
    dTaskUnitResult->setControl("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureDataStorage(char *value){
    dTaskUnitResult->setDataStorage("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureInterfaceAdapters(char *value){
    dTaskUnitResult->setInterfaceAdapters("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureConverter(char *value){
    dTaskUnitResult->setConverter("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureDisplay(char *value){
    dTaskUnitResult->setDisplay("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureLightning(char *value){
    dTaskUnitResult->setLightning("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureMechanics(char *value){
    dTaskUnitResult->setMechanics("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureMotors(char *value){
    dTaskUnitResult->setMotors("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureActuators(char *value){
    dTaskUnitResult->setActuators("xxxxxx",value,3, 11);
}
void houseHoldRobotBuilder::configureSensors(char *value){
    dTaskUnitResult->setSensors("xxxxxx",value,3, 11);
}

medicalRobotBuilder::medicalRobotBuilder(){
    dTaskUnitResult = new distributedTaskUnit("Medical Robot");
}
void medicalRobotBuilder::configureCables(char *value){
    dTaskUnitResult->setCables("xxxxxx",value,8, 5);
}
void medicalRobotBuilder::configureWires(char *value){
    dTaskUnitResult->setWires("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureConnectors(char *value){
    dTaskUnitResult->setConnectors("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureCommunicationTools(char *value){
    dTaskUnitResult->setCommunicationTool("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureControl(char *value){
    dTaskUnitResult->setControl("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureDataStorage(char *value){
    dTaskUnitResult->setDataStorage("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureInterfaceAdapters(char *value){
    dTaskUnitResult->setInterfaceAdapters("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureConverter(char *value){
    dTaskUnitResult->setConverter("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureDisplay(char *value){
    dTaskUnitResult->setDisplay("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureLightning(char *value){
    dTaskUnitResult->setLightning("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureMechanics(char *value){
    dTaskUnitResult->setMechanics("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureMotors(char *value){
    dTaskUnitResult->setMotors("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureActuators(char *value){
    dTaskUnitResult->setActuators("xxxxxx",value,3, 11);
}
void medicalRobotBuilder::configureSensors(char *value){
    dTaskUnitResult->setSensors("xxxxxx",value,3, 11);
}


serviceRobotBuilder::serviceRobotBuilder(){
    dTaskUnitResult = new distributedTaskUnit("Service Robot");
}
void serviceRobotBuilder::configureCables(char *value){
    dTaskUnitResult->setCables("xxxxxx",value,8, 5);
}
void serviceRobotBuilder::configureWires(char *value){
    dTaskUnitResult->setWires("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureConnectors(char *value){
    dTaskUnitResult->setConnectors("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureCommunicationTools(char *value){
    dTaskUnitResult->setCommunicationTool("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureControl(char *value){
    dTaskUnitResult->setControl("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureDataStorage(char *value){
    dTaskUnitResult->setDataStorage("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureInterfaceAdapters(char *value){
    dTaskUnitResult->setInterfaceAdapters("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureConverter(char *value){
    dTaskUnitResult->setConverter("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureDisplay(char *value){
    dTaskUnitResult->setDisplay("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureLightning(char *value){
    dTaskUnitResult->setLightning("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureMechanics(char *value){
    dTaskUnitResult->setMechanics("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureMotors(char *value){
    dTaskUnitResult->setMotors("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureActuators(char *value){
    dTaskUnitResult->setActuators("xxxxxx",value,3, 11);
}
void serviceRobotBuilder::configureSensors(char *value){
    dTaskUnitResult->setSensors("xxxxxx",value,3, 11);
}

militaryRobotBuilder::militaryRobotBuilder(){
    dTaskUnitResult = new distributedTaskUnit("Military Robot");
}
void militaryRobotBuilder::configureCables(char *value){
    dTaskUnitResult->setCables("xxxxxx",value,8, 5);
}
void militaryRobotBuilder::configureWires(char *value){
    dTaskUnitResult->setWires("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureConnectors(char *value){
    dTaskUnitResult->setConnectors("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureCommunicationTools(char *value){
    dTaskUnitResult->setCommunicationTool("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureControl(char *value){
    dTaskUnitResult->setControl("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureDataStorage(char *value){
    dTaskUnitResult->setDataStorage("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureInterfaceAdapters(char *value){
    dTaskUnitResult->setInterfaceAdapters("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureConverter(char *value){
    dTaskUnitResult->setConverter("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureDisplay(char *value){
    dTaskUnitResult->setDisplay("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureLightning(char *value){
    dTaskUnitResult->setLightning("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureMechanics(char *value){
    dTaskUnitResult->setMechanics("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureMotors(char *value){
    dTaskUnitResult->setMotors("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureActuators(char *value){
    dTaskUnitResult->setActuators("xxxxxx",value,3, 11);
}
void militaryRobotBuilder::configureSensors(char *value){
    dTaskUnitResult->setSensors("xxxxxx",value,3, 11);
}

spaceRobotBuilder::spaceRobotBuilder(){
    dTaskUnitResult = new distributedTaskUnit("Space Robot");
}
void spaceRobotBuilder::configureCables(char *value){
    dTaskUnitResult->setCables("xxxxxx",value,8, 5);
}
void spaceRobotBuilder::configureWires(char *value){
    dTaskUnitResult->setWires("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureConnectors(char *value){
    dTaskUnitResult->setConnectors("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureCommunicationTools(char *value){
    dTaskUnitResult->setCommunicationTool("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureControl(char *value){
    dTaskUnitResult->setControl("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureDataStorage(char *value){
    dTaskUnitResult->setDataStorage("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureInterfaceAdapters(char *value){
    dTaskUnitResult->setInterfaceAdapters("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureConverter(char *value){
    dTaskUnitResult->setConverter("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureDisplay(char *value){
    dTaskUnitResult->setDisplay("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureLightning(char *value){
    dTaskUnitResult->setLightning("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureMechanics(char *value){
    dTaskUnitResult->setMechanics("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureMotors(char *value){
    dTaskUnitResult->setMotors("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureActuators(char *value){
    dTaskUnitResult->setActuators("xxxxxx",value,3, 11);
}
void spaceRobotBuilder::configureSensors(char *value){
    dTaskUnitResult->setSensors("xxxxxx",value,3, 11);
}

void customer::setBuilder(builder *b){
    this->b = b;
}
void customer::order(robotStructure r[42], int num){
    for(int i=0; i < num; i++){
        switch (r[i].rbtParts) {
        case cables:
            b->configureCables(r[i].value);
            break;
        case wires:
            b->configureWires(r[i].value);
            break;
        case connectors:
            b->configureConnectors(r[i].value);
            break;
        case communicationTool:
            b->configureCommunicationTools(r[i].value);
            break;
        case control:
            b->configureControl(r[i].value);
            break;
        case dataStorage:
            b->configureDataStorage(r[i].value);
            break;
        case interfaceAdapters:
            b->configureInterfaceAdapters(r[i].value);
            break;
        case converter:
            b->configureConverter(r[i].value);
            break;
        case dislpay:
            b->configureDisplay(r[i].value);
            break;
        case lightning:
            b->configureLightning(r[i].value);
            break;
        case mechanics:
            b->configureMechanics(r[i].value);
            break;
        case motors:
            b->configureMotors(r[i].value);
            break;
        case actuators:
            b->configureActuators(r[i].value);
            break;
        case sensors:
            b->configureSensors(r[i].value);
            break;
        default:
            break;
        }
    }
}
