#include<iostream>
using namespace std;
class student
{
	private:
		char name[20],dob[10],bg[10],addr[50],div[3],stnd[10];
		char *obj;
		int roll;
		long int contact, lic;
	public:
		student()
		{

		obj = new char[20];
		cout<<"Enter name:\n";
		cin.getline(name, 20);
		cout<<"Enter address:\n";
		cin.getline(addr,50);
		cout<<"Enter division:\n";
		cin>>div;
		cout<<"Enter Date of birth:\n";
		cin>>dob;
		cout<<"Enter Blood group:\n";
		cin>>bg;
		cout<<"Enter roll no:\n";
		cin>>roll;
		cout<<"Enter Standard:\n";
		cin>>stnd;
		cout<<"Enter contact:\n";
		cin>>contact;
		cout<<"Enter license:\n";
		cin>>lic;
		}
		void display();
		~student()
		{
			cout<<"\nConstructor destroyed";
			delete obj;
			cout<<"\nobj deleted";
		}
};
void student::display()
{
	cout<<"\nName:"<<name;
	cout<<"\nAddress:"<<addr;
	cout<<"\nStandard:"<<stnd;
	cout<<"\nDivision:"<<div;
	cout<<"\nRoll no:"<<roll;
	cout<<"\nDate of Birth:"<<dob;
	cout<<"\nBlood Group:"<<bg;
	cout<<"\nContact:"<<contact;
	cout<<"\nLicense:"<<lic;
}
int main()
{
	student x;

	x.display();
	return 0;
}



