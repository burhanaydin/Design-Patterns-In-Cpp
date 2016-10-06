#ifndef ABSTRACTIONOCCURENCE_H
#define ABSTRACTIONOCCURENCE_H
using namespace std;
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <string.h>

class item {

    private : std::string name;
    private : std::string author;
    private : int ISBN;
    private : char *publicationDate;
    private : std::string libOfCongress;

    public : virtual std::string date(char *date);
    public : virtual int calculatePayment(const int unitFee, const int timeLength);
    public : virtual void toString();

    public : std::string getName();
    public : std::string getAuthor();
    public : int getISBN();
    public : char *getPublicationDate();
    public : std::string getLibOfCongress();
    public : void setName(const std::string &value);
    public : void setAuthor(const std::string &value);
    public : void setISBN(int value);
    public : void setPublicationDate(char *value);
    public : void setLibOfCongress(const std::string &value);
    public : virtual int getBarcodeNumber() const;
    public : virtual void setBarcodeNumber(int value);
    public : virtual char *getBorrowDate() const;
    public : virtual void setBorrowDate(char *value);
    public : virtual char *getSubmissionDate() const;
    public : virtual void setSubmissionDate(char *value);
    public : virtual int getPenalty() const;
    public : virtual void setPenalty(int value);
    public : virtual int getSubmissionLatencyFee() const;
    public : virtual void setSubmissionLatencyFee(int value);
    public : virtual std::string getEdition() const;
    public : virtual void setEdition(const std::string &value);
    public : virtual int getPrice() const;
    public : virtual void setPrice(int value);
    public : virtual int getMountlyWage() const;
    public : virtual void setMountlyWage(int value);
    public : virtual int getDiscountRate() const;
    public : virtual void setDiscountRate(int value);
    public : virtual std::string getEpisodePilot() const;
    public : virtual void setEpisodePilot(const std::string &value);
    public : virtual std::string getField() const;
    public : virtual void setField(const std::string &value);
};

class libraryItem : public item{

    private : int barcodeNumber;
    private : char *borrowDate;
    private : char *submissionDate;
    private : int submissionLatencyFee;
    private : int penalty;

    public : libraryItem(int barcodeNumber, char *borrowDate,
                          char *submissionDate, int submissionLatencyFee);

    public : int calculatePayment(const int unitFee, const int timeLength);
    public : void toString();
    public : std::string date(char *date);

    public : int getBarcodeNumber() const;
    public : void setBarcodeNumber(int value);
    public : char *getBorrowDate() const;
    public : void setBorrowDate(char *value);
    public : char *getSubmissionDate() const;
    public : void setSubmissionDate(char *value);
    public : int getPenalty();
    public : void setPenalty(int value);
    public : int getSubmissionLatencyFee() const;
    public : void setSubmissionLatencyFee(int value);
};

class magazine : public item{

    private : std::string edition;
    private : std::string trends[];
    private : int mountlyWage;
    private : int discountRate;
    private : int price;

    public : magazine(std::string edition, std::string trends[], int mountlyWage, int discountRate);

    public : int calculatePayment(const int unitFee, const int timeLength);
    public : void toString();
    public : std::string date(char *date);

    public : std::string getEdition() const;
    public : void setEdition(const std::string &value);
    public : int getPrice();
    public : void setPrice(int value);
    public : int getMountlyWage() const;
    public : void setMountlyWage(int value);
    public : int getDiscountRate() const;
    public : void setDiscountRate(int value);
};

class comicsBook : public item {

    private : std::string edition;
    private : std::string heroes[];
    private : std::string episodePilot;
    private : int mountlyWage;
    private : int discountRate;
    private : int price;

    public : comicsBook(std::string edition, std::string heroes[],
                        std::string episodePilot, int mountlyWage, int discountRate);

    public : int calculatePayment(const int unitFee, const int timeLength);
    public : void toString();
    public : std::string date(char *date);


    public : std::string getEdition() const;
    public : void setEdition(const std::string &value);
    public : std::string getEpisodePilot() const;
    public : void setEpisodePilot(const std::string &value);
    public : int getMountlyWage() const;
    public : void setMountlyWage(int value);
    public : int getDiscountRate() const;
    public : void setDiscountRate(int value);
    public : int getPrice() const;
    public : void setPrice(int value);
};

class manual : public item {

    private : std::string field;

    public : manual(std::string field);
    public : int calculatePayment(const int unitFee, const int timeLength);
    public : void toString();
    public : std::string date(char *date);


    public : std::string getField() const;
    public : void setField(const std::string &value);
};

class itemFactory{

    public : virtual item* formFreeItemInstance(int barcodeNumber,char *borrowDate,
                          char *submissionDate, int submissionLatencyFee)=0;
    public : virtual item* formNonFreeItemInstance(std::string edition, std::string trends[],
                           int mountlyWage, int discountRate)=0;
    public : int id = 0;
    public : static int total;

    public : int getId() const;
    public : void setId(int value);
    public : static int getTotal();
    public : static void setTotal(int value);
};


class freeItemFactory : public itemFactory {

    public : freeItemFactory();
    public : item* formFreeItemInstance(int barcodeNumber, char *borrowDate,
                          char *submissionDate, int submissionLatencyFee);
    public : item* formNonFreeItemInstance(std::string edition, std::string trends[],
                           int mountlyWage, int discountRate);
};

class nonFreeItemFactory : public itemFactory{

    public : nonFreeItemFactory();
    public : item* formFreeItemInstance(int barcodeNumber, char *borrowDate,
                           char *submissionDate, int submissionLatencyFee);
    public : item* formNonFreeItemInstance(std::string edition, std::string trends[],
                           int mountlyWage, int discountRate);
};

#endif // ABSTRACTIONOCCURENCE_H
