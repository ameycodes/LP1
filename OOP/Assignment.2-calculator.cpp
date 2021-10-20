#include <iostream>
#include<math.h>
using namespace std;

class alpha
{
private:
int a,b;
char c;

public:
void getdata();
void sum();
void sub();
void mult();
void div();
void operation();
};

void alpha::getdata()
{
cout<<"Enter the expression"<<endl;
cin>>a>>c>>b;
}

void alpha::sum()
{
char p;
cout<<"The addition is: "<<(a+b)<<endl;
cout<<"Do you want to continue? Y/N"<<endl;
cin>>p;
if(p=='y'||p=='Y')
{
    getdata();
    operation();
}
}

void alpha::sub()
{
char p;
cout<<"The subtraction is: "<<(a-b)<<endl;
cout<<"Do you want to continue? Y/N"<<endl;
cin>>p;
if(p=='y'||p=='Y')
{
    getdata();
    operation();
}
}

void alpha::mult()
{
char p;
cout<<"The multiplication is: "<<(a*b)<<endl;
cout<<"Do you want to continue? Y/N"<<endl;
cin>>p;
if(p=='y'||p=='Y')
{
    getdata();
    operation();
}
}

void alpha::div()
{
char p;
cout<<"The division is: "<<(a/b)<<endl;
cout<<"Do you want to continue? Y/N"<<endl;
cin>>p;
if(p=='y'||p=='Y')
{
    getdata();
    operation();
}
}

void alpha::operation()
{

switch(c)
{
case '+':
sum();
break;

case '-':
sub();
break;

case '*':
mult();
break;

case '/':
div();
break;
}
}


int main()
{
alpha d;
d.getdata();
d.operation();

    return 0;
}
