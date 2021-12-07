#include "Customer.h"
class CustomerService
{
public:
    Customer* head;
    Customer* tail;
    static int cusAmount;
public:
    CustomerService();
    ~CustomerService();
    void enqueue();
    void enqueue(Customer *customer);//them sau
    bool isEmpty();
    void dequeue();//Xoa dau
    void removeAll();
    void update();
    void display();
    void search();
    bool contain(string);

 //   void setData();
    void readDataInFile(string);//Doc file
    void showInfoByMkh(string);


};

