#include <iostream>
using namespace std;
class Customer {
public:
		string MKH;
		static int increment;
		int age;
		string customerName;
		string phoneNum;
		string address;
		Customer* next;
public:
	
	Customer(string = "", string = "", int = 0, string = "", string = "");
	Customer(const Customer&);
	~Customer();
	friend ostream& operator<<(ostream&,const Customer&);
	void fromString(string);
	//get va set
	void setData();
};

