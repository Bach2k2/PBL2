#include "ElectricBill.h"

class BillManage{
public:
    ElectricInfo* head;   // current
    ElectricInfo* tail;   // current
    int numNodes; // number of Bills
public:
    BillManage();
    void addBill(ElectricInfo &);   
    void searchBill(int);
    void updateBill(int);
    ElectricInfo& getBill(int);
    void displayList();
    void removeBill(int);
    void saveDataInFile(string);

};
// so với cái báo cáo trước:
// Nhập khach hàng với thông tin hóa đơn là từ file 
//Tính tiền
//Menu : 2 cái quản lý khách hàng với hóa đơn , 
// In hóa đơn ra file -> theo tháng
// Hàm tìm kiếm.
// 