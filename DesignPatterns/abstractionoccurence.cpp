using namespace std;
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include "abstractionoccurence.h"

int itemFactory::total = 0;
freeItemFactory::freeItemFactory(){
    id = total++;
}
nonFreeItemFactory::nonFreeItemFactory(){
    id = total++;
}

item* freeItemFactory::formFreeItemInstance(int barcodeNumber, char *borrowDate,
                          char *submissionDate, int submissionLatencyFee){

    if((this->getTotal()%2)==0){
       return new libraryItem(barcodeNumber, borrowDate, submissionDate, submissionLatencyFee);
    }else{
       return new manual("Physics");
    }
    this->id=total++;
}
item* freeItemFactory::formNonFreeItemInstance(std::string edition, std::string trends[],
                           int mountlyWage, int discountRate){

    if((this->getTotal()%2)==0){
       return new magazine( edition, trends, mountlyWage, discountRate);;
    }else{
       return new comicsBook(edition, trends,"Has the hero got lost?", mountlyWage, discountRate);
    }
    this->id=total++;
}

item* nonFreeItemFactory::formFreeItemInstance(int barcodeNumber, char *borrowDate,
                          char *submissionDate, int submissionLatencyFee){

    if((this->getTotal()%2)==0){
       return new libraryItem(barcodeNumber, borrowDate, submissionDate, submissionLatencyFee);
    }else{
       return new manual("Physics");
    }
    this->id=total++;
}
item* nonFreeItemFactory::formNonFreeItemInstance(std::string edition, std::string trends[],
                          int mountlyWage, int discountRate){

    if((getTotal()%2)==0){
       return new magazine( edition, trends, mountlyWage, discountRate);
    }else{
       return new comicsBook(edition, trends, "Has the hero got lost?", mountlyWage, discountRate);
    }
    this->id=total++;
}
std::string item::date(char *date){
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(date, 80, "%I:%M%p", timeInfo);

    std::string str(date);
    return str;
}

void item::toString(){

}

std::string libraryItem::date(char *date){
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(date, 80, "%I:%M%p", timeInfo);

    std::string str(date);
    return str;
}
std::string magazine::date(char *date){
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(date, 80, "%I:%M%p", timeInfo);

    std::string str(date);
    return str;
}
std::string comicsBook::date(char *date){
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(date, 80, "%I:%M%p", timeInfo);

    std::string str(date);
    return str;
}
comicsBook::comicsBook(std::string edition, std::string heroes[],
                                 std::string episodePilot, int mountlyWage, int discountRate){
    copy( heroes, heroes + 5, this->heroes);
    this->edition = edition;
    this->episodePilot = episodePilot;
    this->mountlyWage = mountlyWage;
    this->discountRate = discountRate;
}

libraryItem::libraryItem(int barcodeNumber,char *borrowDate,
                            char *submissionDate,int submissionLatencyFee) {

    this->barcodeNumber = barcodeNumber;
    this->borrowDate = borrowDate;
    this->submissionDate = submissionDate;
    this->submissionLatencyFee = submissionLatencyFee;
}
int comicsBook::calculatePayment(const int unitFee, const int timeLength){

    return unitFee * timeLength;
}
void comicsBook::toString(){
    std::cout <<"This comics book item has the following specs"<<endl;
    std::cout << "Name                   " << getName() << endl;
    std::cout << "Author                 " << getAuthor() <<endl;
    std::cout << "ISBN                   " << getISBN() <<endl;
    std::cout << "Date of Publication    " << getPublicationDate() <<endl;
    std::cout << "Library Info           " << getLibOfCongress() <<endl;
    std::cout << "Edition                " << getEdition() <<endl;
    std::cout << "Episode Pilot          " << getEpisodePilot() <<endl;
    std::cout << "Discount Rate          " << getDiscountRate() <<endl;
    std::cout << "Mountly Wage           " << getMountlyWage() <<endl;
    std::cout << "Price to Pay           " << getPrice() <<endl;
}
int libraryItem::calculatePayment(const int unitFee, const int timeLength){

    return unitFee * timeLength;
}
void libraryItem::toString(){

    std::cout <<"This library item has the following specs"<<endl;
    std::cout << "Name                   " << getName() << endl;
    std::cout << "Author                 " << getAuthor() <<endl;
    std::cout << "ISBN                   " << getISBN() <<endl;
    std::cout << "Date of Publication    " << getPublicationDate() <<endl;
    std::cout << "Library Info           " << getLibOfCongress() <<endl;
    std::cout << "Barcode #              " << getBarcodeNumber() <<endl;
    std::cout << "Date of Barrowing      " << this->getBorrowDate() <<endl;
    std::cout << "Date of Submission     " << getSubmissionDate() <<endl;
    std::cout << "Submission Latency Fee " << getSubmissionLatencyFee() <<endl;
    std::cout << "Penalty to Pay         " << getPenalty() <<endl;
}
magazine::magazine(std::string edition, std::string trends[],
                        int mountlyWage, int discountRate) {
    this->edition = edition;
    std::copy( trends, trends + 5, trends);
    this->mountlyWage = mountlyWage;
    this->discountRate = discountRate;
}
int magazine::calculatePayment(const int unitFee, const int timeLength){

    return (1 - this->getDiscountRate()/100) * unitFee * timeLength;
}
void magazine::toString(){
    std::cout <<"This magazine item has the following specs"<<endl;
    std::cout << "Name                   " << getName() << endl;
    std::cout << "Author                 " << getAuthor() <<endl;
    std::cout << "ISBN                   " << getISBN() <<endl;
    std::cout << "Date of Publication    " << getPublicationDate() <<endl;
    std::cout << "Library Info           " << getLibOfCongress() <<endl;
    std::cout << "Edition                " << getEdition() <<endl;
    std::cout << "Discount Rate          " << getDiscountRate() <<endl;
    std::cout << "Mountly Wage           " << getMountlyWage() <<endl;
    std::cout << "Price to Pay           " << getPrice() <<endl;
}

manual::manual(std::string field){

    this->setField(field);
}
void manual::toString(){
    std::cout <<"This magazine item has the following specs"<<endl;
    std::cout << "Name                   " << getName() << endl;
    std::cout << "Author                 " << getAuthor() <<endl;
    std::cout << "ISBN                   " << getISBN() <<endl;
    std::cout << "Date of Publication    " << getPublicationDate() <<endl;
    std::cout << "Library Info           " << getLibOfCongress() <<endl;
    std::cout << "Field                  " << getField() <<endl;
}
std::string manual::date(char *date){
    time_t rawTime;
    struct tm *timeInfo;

    time(&rawTime);
    timeInfo = localtime(&rawTime);

    strftime(date, 80, "%I:%M%p", timeInfo);

    std::string str(date);
    return str;
}
int manual::calculatePayment(const int unitFee, const int timeLength){
    return 0*unitFee*timeLength;
}

std::string item::getName(){
    return this->name;
}
std::string item::getAuthor(){
    return this->author;
}
int item::getISBN(){
    return this->ISBN;
}
char* item::getPublicationDate(){
    return this->publicationDate;
}
std::string item::getLibOfCongress(){
    return this->libOfCongress;
}

void item::setName(const std::string &value)
{
    name = value;
}

void item::setAuthor(const std::string &value)
{
    author = value;
}

void item::setISBN(int value)
{
    ISBN = value;
}

void item::setPublicationDate(char *value)
{
    publicationDate = value;
}

void item::setLibOfCongress(const std::string &value)
{
    this->libOfCongress = value;
}

int libraryItem::getBarcodeNumber() const
{
    return barcodeNumber;
}

void libraryItem::setBarcodeNumber(int value)
{
    barcodeNumber = value;
}

char* libraryItem::getBorrowDate() const
{
    return this->borrowDate;
}

void libraryItem::setBorrowDate(char *value)
{
    borrowDate = value;
}

char* libraryItem::getSubmissionDate() const
{
    return this->submissionDate;
}

void libraryItem::setSubmissionDate(char *value)
{
    submissionDate = value;
}

std::string magazine::getEdition() const
{
    return edition;
}

void magazine::setEdition(const std::string &value)
{
    edition = value;
}

int magazine::getPrice()
{
    return calculatePayment(this->getMountlyWage(), 1);
}

void magazine::setPrice(int value)
{
    price = value;
}

int magazine::getMountlyWage() const
{
    return mountlyWage;
}

void magazine::setMountlyWage(int value)
{
    mountlyWage = value;
}

int magazine::getDiscountRate() const
{
    return discountRate;
}

void magazine::setDiscountRate(int value)
{
    discountRate = value;
}

int libraryItem::getPenalty()
{
    return this->calculatePayment(this->getSubmissionLatencyFee(), 10);
}

void libraryItem::setPenalty(int value)
{
    penalty = value;
}

int libraryItem::getSubmissionLatencyFee() const
{
    return submissionLatencyFee;
}

void libraryItem::setSubmissionLatencyFee(int value)
{
    submissionLatencyFee = value;
}

std::string comicsBook::getEpisodePilot() const
{
    return episodePilot;
}

void comicsBook::setEpisodePilot(const std::string &value)
{
    episodePilot = value;
}

int comicsBook::getMountlyWage() const
{
    return mountlyWage;
}

void comicsBook::setMountlyWage(int value)
{
    mountlyWage = value;
}

int comicsBook::getDiscountRate() const
{
    return discountRate;
}

void comicsBook::setDiscountRate(int value)
{
    discountRate = value;
}

int comicsBook::getPrice() const
{
    return price;
}

void comicsBook::setPrice(int value)
{
    price = value;
}

std::string comicsBook::getEdition() const
{
    return edition;
}

void comicsBook::setEdition(const std::string &value)
{
    edition = value;
}

std::string manual::getField() const
{
    return field;
}

void manual::setField(const std::string &value)
{
    field = value;
}

int itemFactory::getTotal()
{
    return itemFactory::total;
}

void itemFactory::setTotal(int value)
{
    itemFactory::total = value;
}

int itemFactory::getId() const
{
    return id;
}

void itemFactory::setId(int value)
{
    id = value;
}
int item::getBarcodeNumber() const{
    return 0;
}

void item::setBarcodeNumber(int value){
    cout << value << endl;
}

char* item::getBorrowDate() const{
    return 0;
}

void item::setBorrowDate(char *value){
    cout << value << endl;
}

char* item::getSubmissionDate() const{
    return 0;
}

void item::setSubmissionDate(char *value){
    cout << value << endl;
}

int item::getPenalty() const{
    return 0;
}

void item::setPenalty(int value){
    cout << value << endl;
}

int item::getSubmissionLatencyFee() const{
    return 0;
}

void item::setSubmissionLatencyFee(int value){
    cout << value << endl;
}

std::string item::getEdition() const{
    return 0;
}

void item::setEdition(const std::string &value){
    cout << value << endl;
}

int item::getPrice() const{
    return 0;
}

void item::setPrice(int value){
    cout << value << endl;
}

int item::getMountlyWage() const{
    return 0;
}

void item::setMountlyWage(int value){
    cout << value << endl;
}

int item::getDiscountRate() const{
    return 0;
}

void item::setDiscountRate(int value){
    cout << value << endl;
}

std::string item::getEpisodePilot() const{
    return "";
}

void item::setEpisodePilot(const std::string &value){
    cout << value << endl;
}

std::string item::getField() const{
    return 0;
}

void item::setField(const std::string &value){
    cout << value << endl;
}

int item::calculatePayment(const int unitFee, const int timeLength){
    return 1*unitFee*timeLength;
}
