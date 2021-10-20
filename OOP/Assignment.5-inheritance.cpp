#include<iostream>
using namespace std;

class person
{
	protected:
		char name[30];
		char dob[15];
		int age;
		char gender[10];
};

class professional
{
	protected:
		char company[50];
		char position[30];
		float salary;
		int experiance;
};

class academic
{
	protected:
		float SSC;
		float HSC;
		float AvgGPA;
		int n;
};

class biodata:public person,public professional,public academic
{
public:
   void accept()
		{
			cout<<"Enter your Personal Details"<<endl;
			cout<<"Please Enter your Name:";
			ws(cin);
			cin.getline(name,30);
			cout<<"Enter your Age:"<<endl;
			cin>>age;
			cout<<"Enter Date of Birth:"<<endl;
			ws(cin);
			cin>>dob;
			cout<<"Enter Gender:"<<endl;
			ws(cin);
			cin>>gender;
			cout<<"\n\nEnter Professional Details"<<endl;
			cout<<"Enter Name of the Company: ";
			ws(cin);
			cin.getline(company,50);
			cout<<"Enter Position: "<<endl;
			ws(cin);
			cin.getline(position,30);
			cout<<"Enter Salary in Rs. "<<endl;
			cin>>salary;
			cout<<"Enter Experience of work(In years): "<<endl;
			cin>>experiance;
			cout<<"\n\nEnter Academic Details"<<endl;
			cout<<"\nEnter SSC Percentage:"<<endl;
			cin>>SSC;
			cout<<"Enter HSC Percentage:"<<endl;
			cin>>HSC;
			cout<<"Enter Average GPA:"<<endl;
			cin>>AvgGPA;
			cout<<"Enter number of programming languages known:"<<endl;
			cin>>n;

		}
		void display()
		{
		    cout<<"\nName: "<<name;
			cout<<"\nAge: "<<age;
			cout<<"\nDate of Birth: "<<dob;
			cout<<"\nGender: "<<gender;
			cout<<"\nCompany:"<<company;
			cout<<"\nPostion:"<<position;
			cout<<"\nSalary Rs."<<salary;
			cout<<"\nExperience in Years:"<<experiance;
			cout<<"\nSSC Score: "<<SSC<<" %";
			cout<<"\nHSC Score: "<<HSC<<" %";
			cout<<"\nAverage GPA Score: "<<AvgGPA;
			cout<<"\nNumber of Programming languages known: "<<n;

		}
};


int main()
{
	biodata z;
	//Enter data
	z.accept();


	cout<<"\nDisplaying Data"<<endl;
	z.display();

	return 0;
}
