#include <iostream>
#include <string>
using namespace std;
class ElectricInfo
{
    string meterCode; // Khóa chính
    string billName;
    string beginDate;
    string endDate;
    //Khach hang
    
    //Tien dien:
    int unit;
    double cost;

public:
    ElectricInfo* next;
public:
    ElectricInfo();
    ElectricInfo(string, string, string,string,int ,int);
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