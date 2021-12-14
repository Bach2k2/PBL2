#include <iostream>
using namespace std;
class Customer {
private:
		string customerId;
		static int increment;
		int age;
		string customerName;
		string phoneNum;
		string address;
		
public:
	Customer* next;
	Customer(string = "", string = "", int = 0, string = "", string = "");
	Customer(const Customer&);
	~Customer();
	friend ostream& operator<<(ostream&,const Customer&);
	void fromString(string);
	//get va set
	void setData();
	void setCustomerId(string);
	void setAge(int);
	void setCustomerName(string);
	void setPhoneNumber(string);
	void setAddress(string);
	string getCustomerId(){
		return customerId;
	}
	int getAge(){ return age; }
	string getCustomerName(){ return customerName; }
	string getPhoneNumber(){ return phoneNum; }
	string getAddress(){ return address; }

};

