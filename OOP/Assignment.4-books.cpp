#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;
class book
{
 	private:
 		char author[30];
 		char title[30];
 		char publisher[30];
 		int price;
 		int stock;
	public:
     	book();
   		void accept();
   		void display();
   		int search(char*,char*);
   		void availability(int);
};

book::book()
{
   		char *author=new char[50];
   		char * title=new char[50];
   		char *publisher=new char[50];
    	price=0;
   		stock=0;
}

void book::accept()
{
 	 	cout<<"\n Enter the name of Book: \n";
  		cin>>title;
  		cout<<"\n Enter The Name Of Author: \n";
  		cin>>author;
  		cout<<"\n Enter The name of Publisher: \n";
  		cin>>publisher;
  		cout<<"\n Enter the Price of book:\n" ;
  		cin>>price;
  		cout<<"\n Enter Stock of book:\n" ;
  		cin>>stock;
}


void book::display()
{
    cout<<"\n "<<title<<"\t  "<<author<<"\t\t  "<<publisher<<"\t\t  "<<price<<"\t  "<<stock;
}



int book::search(char *sectitle,char *secauthor)
{
      	if(strcmp(title,sectitle)&&strcmp(author,secauthor))
        {
        return 0;
        }
        else
        {
        return 1;
        }
}



void book::availability(int copies)
{
	if(stock>=copies)
    {
	cout<<"\n Book is available";
	cout<<"\n Cost of"<<copies<<" book(s) is Rs."<<(price*copies);
    }
    else
    {
	cout<<"\n Required copies are not in stock";
    }
}



int main()
{
book b[10];
int ch,n,i,x=0,copies,y=0;
char bname[50];
char sectitle[50];
char secauthor[50];

cout<<"Welcome to Bookstore"<<endl;
do
{

cout<<"\n1.Add books\n2.Display inventory\n3.Search books/Buy books\n4.Exit";
cout<<"\nEnter Your Choice:";
cin>>ch;
switch(ch)
{
    case 1: cout<<"\nPlease enter no. of books:"<<endl;
            cin>>n;
            for(i=0;i<n;i++)
            {
            b[i].accept();
            }
            break;


    case 2: cout<<"\n"<<"Title"<<"\t  "<<"Author"<<"\t"<<"Publisher"<<"\t"<<"Price"<<"\t"<<"Stock";
            for(i=0;i<n;i++)
            {
            cout<<"\n";
            b[i].display();
            }
            break;

    case 3: cout<<"\n Enter the title of required book\n";
            cin>>sectitle;
            cout<<"\n Enter author of required book\n";
            cin>>secauthor;

            for(i=0;i<n;i++)
            {
                if(b[i].search(sectitle,secauthor))
                {
                    //cout<<b[i].search(sectitle,secauthor);
                x=1;
                cout<<"\n"<<"Title"<<"\t  "<<"Author"<<"\t  "<<"Publisher"<<"\t  "<<"Price"<<"\t   "<<"Stock";
                b[i].display();
                y=i;
                }
            }
    if(x==1)
    cout<<"\n Book is available";
    else
    {
    cout<<"\n Book is Not available";
        break;
    }

    if(x==1)
    {
    cout<<"\n Please enter the required number of copies of the book:";
    cin>>copies;
    b[y].availability(copies);
    }
    break;



    case 4: break;

    default :   cout<<"\n Wrong Choice";
                break;
    }

}while(ch!=4);


return 0;
}
