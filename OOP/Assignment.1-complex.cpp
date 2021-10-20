#include <iostream>

using namespace std;

class complex
{
float x,y;
public:
    complex()
    {
        x=0.0;
        y=0.0;
    }

    complex(float s, float t)
    {
        x=s;
        y=t;
    }
    complex operator +(complex);
    complex operator -(complex);
    complex operator *(complex);
    complex operator /(complex);
    void display(complex,complex,complex,char);
};

complex complex::operator+(complex c)
{
    complex temp;
    temp.x=x+c.x;
    temp.y=y+c.y;
    return temp;
}
complex complex::operator-(complex c)
{
    complex temp;
    temp.x=x-c.x;
    temp.y=y-c.y;
    return temp;
}
complex complex::operator*(complex c)
{
    complex temp;
    temp.x=(x*c.x-y*c.y);
    temp.y=(x*c.y)+(y*c.x);
    return temp;
}
complex complex::operator/(complex c)
{
    complex temp;
    temp.x=(x*c.x+y*c.y)/(c.x*c.x+c.y*c.y);
    temp.y=((y*c.x)-(x*c.y))/(c.x*c.x+c.y*c.y);
    return temp;
}

void complex::display(complex c1,complex c2,complex c3,char a)
{
cout<<"("<<c1.x<<" + "<<c1.y<<"i) ";
cout<<a<<" ";
cout<<"("<<c2.x<<" + "<<c2.y<<"i)";
cout<<" = ";
cout<<" ("<<c3.x<<" + "<<c3.y<<"i)";
}



 int main()
 {
     char a,b;
     float c,d,e,f;
     complex c1,c2,c3;
     cout<<"Enter Real and Imag part of 1st complex no."<<endl;
     cin>>c>>d;
     cout<<"Enter Real and Imag part of 2nd complex no."<<endl;
     cin>>e>>f;
     c1=complex(c,d);
     c2=complex(e,f);
     cout<<"Addition='+'   Subtraction='-'   Multiplication='*'   Division='/'"<<endl;
     do
     {
         cout<<"Enter your choice"<<endl;
         cin>>a;
         switch(a)
         {
             case '+': c3=c1+c2;
                        break;

             case '-': c3=c1-c2;
                        break;

             case '*': c3=c1*c2;
                        break;

             case '/': c3=c1/c2;
                        break;

             default: cout<<"Invalid option"<<endl;
                        break;
             }

        c1.display(c1,c2,c3,a);
        cout<<"\nDo you want to continue(Y/N)"<<endl;
        cin>>b;

    }while(b=='Y'||b=='y');

     return 0;
 }











