#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
typedef struct Person
{
	string name;
	int age;
	string father_name;
	string address;
	long long int contact;
	long long int amount;
	//int serial;
	long int account;
}individual;

int list_no=-1;

class Bank
{
protected:
	int account_list[100];
	long int account_no=101000,*p=&account_no;

	
public:
	string password={"gauravbank"};
	int list_no;
	int *j=&list_no;
	individual i;
	
	void set()
	{
	
	}
};
class Customer:public Bank
{
public:
	void start()
	{
		ifstream fin;
		fin.open("variables.txt");
		fin>>(*j);
		fin.close();
		
		//cout<<(*j);
		if((*j)>100||(*j)==0)
		{
			list_no=0;
			*p=101000;
			//cout<<"hello";
		}
		else
		{
			fin.open("myfile.txt",ios::in);
		fin.read((char *)&i,sizeof(i));
		while(!fin.eof())
			{*p=i.account;
				fin.read((char *)&i,sizeof(i));}
		fin.close();
		}
	}
	void faltu()
	{
		cout<<(*j)<<endl<<"hello";
	}
	void new_account()
	{
		ofstream fout;
		(*p)=(*p)+1;
		//cout<<(*j)<<endl;
		
		(*j)=(*j)+1;
		ofstream fo;
		fo.open("variables.txt",ios::out);
		fo<<(*j);
		fo.close();
		//cout<<(*j)<<endl;
		while(1)
		{
		cout<<"NAME: ";
		cin.ignore();
		getline(cin,i.name);
		cout<<"AGE: ";
		cin>>i.age;
		if(i.age<18)
		{
			cout<<"You are not eligible to make account.\nSORRY!!!\n\n";
			break;
		}
		cout<<"FATHER'S NAME: ";
		cin.ignore();
		getline(cin,(i.father_name));
		cout<<"ADDRESS: ";
		cin.ignore();
		getline(cin,(i.address));
		cout<<"CONTACT: ";
		cin>>i.contact;
		cout<<"\n\n";
		cout<<"YOUR ACCOUNT IS MAKE SUCCESSFULLY!!!\n\n";
		cout<<"Your account number is "<<(*p)<<"\n\n";
		i.amount=0;
		i.account=(*p);
		cout<<"Thanks for making account in our bank!\n\n";
		break;
		}
		fout.open("myfile.txt",ios::app|ios::binary);
		//fout.seekp(0,ios::beg);
		fout.write((char *)&i,sizeof(i));
		fout.close();
	} 
	void deposit_account()
	{
		int x1,e=0;
		fstream fin;
		cout<<"\nENTER ACCOUNT NUMBER : ";
		cin>>(*p);
		cout<<(*p);
		cout<<"\n\n";
		cout<<(*j);
		if((*j)==0)
		{
			cout<<"YOU HAVE NOT ANY ACCOUNT IN THIS BANK,\n\n";
			cout<<"Go to main menu and create account first\n\n";
		}
/*aap ek or file banke usme serial no. or account no. or uska separate password bhi set kr skte h*/ 
				cout<<"ENTER AMOUNT YOU WANT TO DEPOSIT :  ";
				cin>>x1;
				cout<<"\n\n";
				fin.open("myfile.txt",ios::in|ios::out|ios::ate|ios::binary);
				fin.seekp(0);
				fin.read((char *)&i,sizeof(i));
				//individual temp;
				while(!fin.eof())
				{
					if(i.account==(*p))
					{
						cout<<i.name<<" in your account "<<x1<<" rupees is deposited.\n\n";
						e++;
						i.amount=i.amount+x1;
						int pos=(int)fin.tellp()-sizeof(i);
						fin.seekp(pos,ios::beg);
						cout<<"Total amount="<<i.amount<<"\n\n";
						fin.write((char *)&i,sizeof(i));
						
						break;
					}
					fin.read((char *)&i,sizeof(i));
				}
				fin.close();
		if(e==0)
		{
			cout<<"YOU HAVE NOT ANY ACCOUNT IN THIS BANK,\n\n";
			cout<<"Go to main menu and create account first\n";
		}
		cout<<"HAVE A NICE DAY!!\n\n";

	}
	void withdraw_amount()
	{
		int x1,e=0;
		fstream fin;
		cout<<"\nENTER ACCOUNT NUMBER : ";
		cin>>(*p);
		cout<<(*p);
		cout<<"\n\n";
		cout<<(*j);
		if((*j)==0)
		{
			cout<<"YOU HAVE NOT ANY ACCOUNT IN THIS BANK,\n\n";
			cout<<"Go to main menu and create account first\n\n";
		}
/*aap ek or file banke usme serial no. or account no. or uska separate password bhi set kr skte h*/ 
				cout<<"ENTER AMOUNT YOU WANT TO WITHDRAW :  ";
				cin>>x1;
				cout<<"\n\n";
				fin.open("myfile.txt",ios::in|ios::out|ios::ate|ios::binary);
				fin.seekp(0);
				fin.read((char *)&i,sizeof(i));
				//individual temp;
				while(!fin.eof())
				{
					if(i.account==(*p))
					{
						cout<<i.name<<" in your account "<<x1<<" rupees is withdraw.\n\n";
						e++;
						i.amount=i.amount-x1;
						int pos=(int)fin.tellp()-sizeof(i);
						fin.seekp(pos,ios::beg);
						cout<<"Total amount="<<i.amount<<"\n\n";
						fin.write((char *)&i,sizeof(i));
						
						break;
					}
					fin.read((char *)&i,sizeof(i));
				}
				fin.close();
		if(e==0)
		{
			cout<<"YOU HAVE NOT ANY ACCOUNT IN THIS BANK,\n\n";
			cout<<"Go to main menu and create account first\n";
		}
		cout<<"HAVE A NICE DAY!!\n\n";

	}
	void balance()
	{
		int e=0;
		cout<<"\nENTER ACCOUNT NUMBER : ";
		cin>>(*p);
		cout<<"\n\n";
		cout<<(*p);
		ifstream fin;
		fin.open("myfile.txt",ios::in);
		fin.read((char *)&i,sizeof(i));
		cout<<"hello";
		while(!fin.eof())
		{
			if(i.account==(*p))
			{
				cout<<i.name<<" total amount in your account is "<<i.amount<<"\n\n";
				e++;
			}
			fin.read((char *)&i,sizeof(i));
		}
		fin.close();
		if(e==0)
		{
			cout<<"YOU HAVE NOT ANY ACCOUNT IN THIS BANK,\n\n";
			cout<<"Go to main menu and create account first\n\n";
		}
		cout<<"HAVE A NICE DAY!!\n\n";
	}
	void account_holder_list()
	{
		cout<<"**BANK INFORMATION**\n\n";
		if((*j)==0)
			cout<<"THERE IS NO CUSTOMER IN THIS BANK\n\n";
		ifstream fin;
		fin.open("myfile.txt",ios::in);
		int e=0;
		while(e<(*j))
		{
			fin.read((char *)&i,sizeof(i));
			cout<<"INFORMATION of account no. "<<i.account<<"\n\n";
			cout<<"NAME: "<<i.name<<endl;
			cout<<"AGE: "<<i.age<<endl;
			cout<<"FATHER NAME: "<<i.father_name<<endl;
			cout<<"ADDRESS: "<<i.address<<endl;
			cout<<"CONTACT: "<<i.contact<<endl;
			cout<<"AMOUNT: "<<i.amount<<"\n\n";
			e++;
		}
	}
	void close_account()
	{
		int e=0;
		string temp;
		char m;
		(*j)=(*j)-1;
		ofstream tout;
		tout.open("variables.txt",ios::out);
		tout<<(*j);
		tout.close();
		cout<<(*j)<<endl;
		cout<<"\nENTER ACCOUNT NUMBER : ";
		cin>>(*p);
		cout<<"\n\n";
		cout<<"\nDo you really want to close account?\nY or N\n";
		cin>>m;
		
		if(m=='Y')
		{
		ifstream fin;
				fin.open("myfile.txt",ios::in);
		fin.read((char *)&i,sizeof(i));
		while(!fin.eof())
		{
			if(i.account!=(*p))
				{	ofstream pout;
					pout.open("tempfile.txt",ios::app|ios::binary);
					pout.write((char *)&i,sizeof(i));
					pout.close();
				}
			else
				{temp=i.name;
					e++;}
			fin.read((char *)&i,sizeof(i));
		}
		fin.close();
		if(e==0)
		{
			cout<<"YOU HAVE NOT ANY ACCOUNT IN THIS BANK,\n\n";
			cout<<"Go to main menu and create account first\n\n";
		}
		cout<<temp<<" YOUR ACCOUNT IS SUCCESSFULLY CLOSED\n\n";
		
		remove("myfile.txt");
		rename("tempfile.txt","myfile.txt");
		}
	}
	void modify_account()
	{
		int e=0;
		cout<<"\nENTER ACCOUNT NUMBER : ";
		cin>>(*p);
		cout<<"\n\n";
		fstream fiot;
		fiot.open("myfile.txt",ios::ate|ios::in|ios::out);
		fiot.seekp(0);
		fiot.read((char *)&i,sizeof(i));
		while(!fiot.eof())
		{
			if(i.account==(*p))
			{
				cout<<"***ACCOUNT STATUS***\n";
				cout<<"NAME: "<<i.name<<endl;
				cout<<"AGE: "<<i.age<<endl;
				cout<<"FATHER'S NAME: "<<i.father_name<<endl;
				cout<<"ADDRESS: "<<i.address<<endl;
				cout<<"CONTACT: "<<i.contact<<endl<<endl;
				cout<<"AMOUNT: "<<i.amount<<endl<<endl;
				cout<<"ACCOUNT: "<<i.account<<endl<<endl;
				cout<<"ENTER MODIFIED NAME\n";
				cin.ignore();
				cin>>i.name;
				cout<<"ENTER MODIFIED AGE\n";
				cin>>i.age;
				cout<<"ENTER MODIFIED FATHER NAME\n";
				cin.ignore();
				cin>>i.father_name;
				cout<<"ENTER MODIFIED ADDRESS\n";
				cin.ignore();
				cin>>i.address;
				cout<<"ENTER MODIFIED CONTACT\n";
				cin>>i.contact;
				cout<<"ENTER MODIFIED AMOUNT\n";
				cin>>i.amount;
				cout<<"ENTER MODIFIED ACCOUNT\n";
				cin>>i.account;
				int pos=(int)fiot.tellp()-sizeof(i);
				fiot.seekp(pos,ios::beg);
				fiot.write((char *)&i,sizeof(i));
				e++;
				break;
			}
			fiot.read((char *)&i,sizeof(i));
		}
		fiot.close();
		if(e==0)
		{
			cout<<"THERE IS NO ACCOUNT IN THIS BANK OF THIS ACCOUNT NUMBER,\n\n";
			cout<<"Say individual to go to main menu and create account first\n\n";
		}
		
		
	}
};

int main()
{
	int n,y;
	string s;
	Customer c;
	c.start();
	//c.faltu();
	Bank b;
	//c.set();
	cout<<"$$$$_WELCOME  TO MY BANK_$$$$\n\n";
    //cout<<n<<endl;
	while(1)
	{
	cout<<"**MAIN MENU**\n\n";
	cout<<"1. NEW ACCOUNT\n\n";
	cout<<"2. DEPOSIT AMOUNT\n\n";
	cout<<"3. WITHDRAW AMOUNT\n\n";
	cout<<"4. BALANCE ENQUIRY\n\n";
	cout<<"5. ALL ACCOUNT HOLDERS LIST\n\n";
	cout<<"6. CLOSE AN ACCOUNT\n\n";
	cout<<"7. MODIFY AN ACCOUNT\n\n";
	cout<<"8. EXIT\n\n";
	cout<<"Select Your Option <1-8>"<<endl;
	cin>>n;
	switch(n)
	{
		case 1:
		{
		c.new_account();
		//c.deposit_account();
		cout<<"To go to main menu enter 1\n";
		cin>>y;
		}
		break;
		case 2:
		{
		c.deposit_account();
		cout<<"To go to main menu enter 1\n";
		cin>>y;
		}
		break;
		case 3:
		{
		c.withdraw_amount();
		cout<<"To go to main menu enter 1\n";
		cin>>y;
		}
		break;
		case 4:
		{
		c.balance();
		cout<<"To go to main menu enter 1\n";
		cin>>y;
		}
		break;
		case 5:
		{
		cout<<"ENTER PASSWORD\n";
		cin>>s;
		if(s==b.password)
				c.account_holder_list();
		else
			cout<<"\n\nYOU ARE NOT ELIGIBLE TO SEE THIS INFORMATION\n\n";
		}
		break;
		case 6:
		{
		c.close_account();
		cout<<"To go to main menu enter 1\n";
		cin>>y;
		}
		break;
		case 7:
		{
		cout<<"ENTER PASSWORD\n";
		cin>>s;
		if(s==b.password)
			c.modify_account();
		else
			cout<<"\n\nYOU ARE NOT ELIGIBLE TO DO THIS TASK.\n\n";
		}
		break;
		case 8:
		{
			cout<<"****THANKS FOR COMING OUR BANK****\n\n";
		}
		return 0;
		default:
		cout<<"you entered wrong choice\n";
		
	}
	}
}

