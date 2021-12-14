#pragma once
#include "Bill.h"
#include "Service.h"
class BillService
{
public:          //BillService
    Bill* pHead; //
    Bill* pTail;
    static int numNodes;
public:
    BillService();
    ~BillService();
    void add();//Thêm nhập từ bàn phím
    void add(Bill* bill);// Nhận từ file
    bool isEmpty();// Danh sách có rỗng
    void remove();// Xóa
    void removeFirst();//Xóa
    void removeAll();// Xóa hết
    void update();  //chưa làm .
    void display(); // Rồi
    void search();  // chưa làm đc
    void readFile(string path); // Đọc file

    bool contain(int);
    void calculatePrice();

    void MonthManger();
};

