#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class ElectricBill
{
private:
    //Thong tin bill
    int billId;
    string billName;
    string beginDate;
    string endDate;
    //Khach hang
    int customerId;
    string customerName;
    string address;
    string phoneNumber;
    //Tien dien:
    int unit;
    double cost;

public:
    ElectricBill* next;
public:
    ElectricBill();
    ElectricBill(string, string, string,int,string,string,string,int);
    void setBillId();
    void setBillName(string);
    void setBeginDate(string);
    void setEndDate(string);

    void setCustomerId(int);
    void setCustomerName(string);
    void setCustomerAddress(string);
    void setPhoneNumber(string);
    
    void setUnit(int);
    void calculateCost();

    //get
    int getBillId();
    string getBillName();
    string getBeginDate();
    string getEndDate();

    int getCustomerId();
    string getCustomerName();
    string getCustomerAddress();
    string getCustomerPhone();

    int getUnit();
    double getCost();
   
    //display
    void showInfo();
    //Read file:
public:
    void printToFile(ofstream&);
    void setByFile(ifstream &);
    void readString(string , bool = false);

};