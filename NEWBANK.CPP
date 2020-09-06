#include<fstream.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>

//Function Prototyping
void alignCenter(char*);
void Line();
void colorLine(int,char);
void nameHeader();
void AccountOpen();
void AccountList();
void deposit();
void deposit(unsigned long);
void withdraw();
void withdraw(unsigned long);
void ChangePassword(unsigned long);
void ForgotPassword();
void AccountClose();
void AccountFreeze();
void AccountUnFreeze();
void ClosedAccounts();
void ActiveAccounts();
void FreezedAccounts();
void BankFund();
void modifyDetails();
void Staffmenu();
void Clientmenu();
void project();
void home();
void Staff();  		//Function for Bank Staff Login
void ClientLogin();	//Function for Client Login
void SignIn();

//Declaration and Definition of Bank Class.
class Bank
{
	unsigned long acno;
	char name[50];
	char type;
	char gender;
	float balance;
	char status;
	unsigned long cid;	//Customer ID
	char pwd[10];		//Set Password
	char sques[20];	//Secret Question for password restoring
	char sans[20];		//Answer to secret question

	public:
	Bank()
	{
		acno=0;
		type='S';
		balance=0;
		strcpy(name,"");
		status='A';
		gender='F';
		cid=0;
		strcpy(pwd,"");
		strcpy(sques,"");
		strcpy(sans,"");
	}
	void getData(unsigned long, unsigned long);
	void listData();
	void showData();
	void modify();
	void Deposit(float);
	void Withdraw(float);
	void closeAccount();
	void freezeAccount();
	void unFreezeAccount();
	void newPassword();
	void resetPassword();

	unsigned long getAccountNumber()
	{
		return acno;
	}
	unsigned long getAccNo()
	{
		return acno;
	}
	char getType()
	{
		return type;
	}
	char getStatus()
	{
		return status;
	}
	float getBalance()
	{
		return balance;
	}
	char *getSecQuestion()
	{
		return sques;
	}
	char *getSecAnswer()
	{
		return sans;
	}
	char *getPwd()
	{
		return pwd;
	}
	char *getName()
	{
		return name;
	}
	unsigned long getCid()
	{
		return cid;
	}
}b;

//Class Member Function to Take Input for  Bank Clients.
void Bank::getData(unsigned long n, unsigned long id)
{
	char cpwd[10];
	alignCenter("ENTER YOUR PERSONAL DETAILS");
	colorLine(12,'=');
	cout<<"Enter Account Name       : ";
	cin.get();
	cin.getline(name,50);
	gen:
	cout<<"Enter Your Gender  (M/F) : ";
	cin>>gender;
	if(!(gender=='M' || gender=='m' || gender== 'F' || gender=='f'))
	{
		cout<<"\nGender should only be either M or F\n";
		cout<<"Kindly re-enter correct gender type....\n";
		goto gen;
	}
	check:
	cout<<"Enter Account Type (C/S) : ";
	cin>>type;
	if(!(type=='S' || type=='s' || type== 'C' || type=='c'))
	{
		cout<<"\nAccount type should only be either C or S\n";
		cout<<"Kindly re-enter correct account type....\n";
		goto check;
	}
	if(type=='S' || type=='s')
	{
		verify:
		cout<<"Enter the Opening Balance: ";
		cin>>balance;
		if(balance<500)
		{
			cout<<"\nMinimum account balance for savings account should not be less than 500\n";
			goto verify;
		}
	}
	else if(type=='C' || type=='c')
	{
		verify2:
		cout<<"Enter the Opening Balance: ";
		cin>>balance;
		if(balance<1000)
		{
			cout<<"\nMinimum account balance for current account should not be less than 1000\n";
			goto verify2;
		}
	}

	setpass:
	cout<<endl;
	textcolor(11+BLINK);
	cprintf("Don't Share or Forget your Customer ID");
	cout<<endl;
	textcolor(7);
	cout<<"Your Computer Generated Customer ID is : "<<id<<endl;
	cout<<"Set Your Password (Max. 8 characters)  : ";
	cin>>pwd;
	cout<<"Confirm Your Password                  : ";
	cin>>cpwd;
	if(strcmp(pwd,cpwd)==0)
	{
		cout<<"\nPassword Matched and Stored....\n";
	}
	else
	{
		cout<<"\nPassword Doesn't Match, Kindly re-enter\n";
		goto setpass;
	}

	setques:
	cout<<"In case you forget your password, to reset set your security question";
	cout<<"\n1. Place of Birth";
	cout<<"\n2. Year of Birth";
	cout<<"\n3. Pet Name";
	cout<<"\nEnter Your Choice : ";
	int ch;
	cin>>ch;
	switch(ch)
	{
		case 1: strcpy(sques,"Place of Birth"); break;
		case 2: strcpy(sques,"Year of Birth"); break;
		case 3: strcpy(sques,"Pet Name"); break;
		default:
		cout<<"\nWrong Choice... Kindly reselect\n";
		goto setques;
	}
	cout<<"Set Your Secret Answer (WITHOUT SPACE): ";
	cin>>sans;
	cout<<endl;
	textcolor(11+BLINK);
	cprintf("KINDLY STORE SAFELY YOUR SECRET ANSWER");
	cout<<endl;
	textcolor(7);
	acno=n;
	cid=id;
	status='A';
}

//Displaying the details of account holder in tabular form.
void Bank::listData()
{
	cout.setf(ios::left);
	cout<<setw(8)<<acno
	    <<setw(8)<<cid
	    <<setw(20)<<name
	    <<gender<<setw(5)<<" "
	    <<type<<setw(5)<<" "
	    <<setw(10)<<balance
	    <<status<<setw(7)<<" "
	    <<endl;
}

//Displaying the details of account holder in columnar form.
void Bank::showData()
{
	cout<<".....ACCOUNT DETAILS.....\n";
	cout<<"Account Number     : "<<acno<<endl;
	cout<<"Customer ID        : "<<cid<<endl;
	cout<<"Account Name       : "<<name<<endl;
	cout<<"Account Type       : "<<type<<endl;
	cout<<"Account Balance    : "<<balance<<endl;
}

//Modify Customer Details
void Bank::modify()
{
	char ch;
	cout<<"\n........Modify Existing Details........\n";
	cout<<"\tAcc. No   : "<<acno<<endl;
	cout<<"\tLogin ID  : "<<cid<<endl;
	cout<<"\tName      : "<<name<<endl;
	cout<<"\tPress 1 if you want to modify\n";
	ch=getch();
	if(ch=='1')
	{
		cout<<"Enter New Name : ";
		cin.ignore();
		cin.getline(name,20);
	}
	cout<<"\tAcc. Type : "<<type<<endl;
	cout<<"\tGender    : "<<gender<<endl;
	cout<<"\tPress 1 if you want to modify\n";
	ch=getch();
	if(ch=='1')
	{
		gen:
		cout<<"Enter Your Gender  (M/F) : ";
		cin>>gender;
		if(!(gender=='M' || gender=='m' || gender== 'F' || gender=='f'))
		{
			cout<<"\nGender should only be either M or F\n";
			cout<<"Kindly reenter correct gender type....\n";
			goto gen;
		}
	}
}

//Modify Customer Password
void Bank::newPassword()
{
	char ch;
	int i=0;
	cout<<"\n........Set New Password........\n";
	cout<<"\tEnter New Password(Max 8. characters) : ";
	do
	{
		ch=getch();
		if(ch!=13)
		{
			cout<<"*";
			pwd[i++]=ch;
		}
		else
			pwd[i]='\0';

	}while(ch!=13);
	cout<<"\n\nYour Password is successfully changed....\n";
}

//Reset the Password
void Bank::resetPassword()
{
	char ch,pass1[10],pass2[10];
	int i=0;
	cout<<"\n........Reset Your Password........\n";
	cout<<"\tEnter New Password: (Max 8. characters) : ";
	do
	{
		ch=getch();
		if(ch!=13)
		{
			cout<<"*";
			pass1[i++]=ch;
		}
		else
			pass1[i]='\0';
	}while(ch!=13);

	i=0;
	int chance=1;

	confirm:
	cout<<"\n\tConfirm Password : ";
	do
	{
		ch=getch();
		if(ch!=13)
		{
			cout<<"*";
			pass2[i++]=ch;
		}
		else
			pass2[i]='\0';
	}while(ch!=13);

	if(strcmp(pass1,pass2)==0)
	{
		cout<<"\n\nYour Password is successfully changed....\n";
		strcpy(pwd,pass1);
		goto stop;
	}
	else
	{
		cout<<"\nKindly password does not match.";
		if(chance<=3)
		{
			cout<<"\nYou have "
			    <<3-chance<<" remaining to confirm password\n";
			    goto confirm;
		}
		else
		{
			goto stop;
		}
	}
	stop:
}


//Function to update the deposited balance in the deposited account.
void Bank::Deposit(float d)
{
	balance+=d;
	cout<<"\nYour amount : "<<d<<" deposited into your account....\n";
	cout<<"Your updated balance is now : Rs. "<<balance<<endl;
}

//Function to update the withdrawn balance in the deposited account.
void Bank::Withdraw(float d)
{
	if(type=='C' || type=='c')
	{
		if(balance-d>1000)
		{
			cout<<"\nYour amount : "<<d<<" withdrawn from your account....\n";
			balance-=d;
			cout<<"Your updated balance is now : Rs. "<<balance<<endl;
		}
		else
		{
			cout<<"\nYou can withdraw maximum : "
			    <<balance-1000<<" from your current account.";
		}
	}
	else if(type=='S' || type=='s')
	{
		if(balance-d>500)
		{
			cout<<"\nYour amount : "<<d<<" withdrawn from your account....\n";
			balance-=d;
			cout<<"Your updated balance is now : Rs. "<<balance<<endl;
		}
		else
		{
			cout<<"\nYou can withdraw maximum : "
			    <<balance-500<<" from your savings account.";
		}
	}
}

//Close Account Class Function
void Bank::closeAccount()
{
	status='C';
	cout<<"\nYou can collect the cash balance from your account.\n";
	cout<<"You have balance in your account i.e.: Rs."<<balance<<endl;
	balance=0;
}

//Freeze Account Class Function
void Bank::freezeAccount()
{
	status='F';
	cout<<"\nYour account has been freezed...\n";
	cout<<"\nContact branch office to unfreeze the account....\n";
	cout<<"You have balance in your account i.e.: Rs."<<balance
	    <<"\nbut you cannot do any transactions....\n";
}

//Unfreeze Account Class Function
void Bank::unFreezeAccount()
{
	status='A';
	cout<<"\nYour account has been unfreezed...\n";
	cout<<"\nContact branch office to unfreeze the account....\n";
	cout<<"You have balance in your account i.e.: Rs."<<balance
	    <<"\nnow you can do any transactions....\n";
}

void alignCenter(char* c)
{
	int n,x,y=5;
	n=strlen(c);
	textcolor(14);
	x=(80-n)/2;
	gotoxy(x,y);
	cprintf("%s",c);
	textcolor(7);
	cout<<endl;
}

void Line()
{
	for(int i=1;i<80;i++)
		cout<<"=";
	cout<<endl;
}

void colorLine(int n,char c)
{
	textcolor(n);
	for(int i=1;i<80;i++)
		cprintf("%c",c);
	textcolor(7);
	cout<<endl;
}

void Header()
{
	gotoxy(1,1);
	colorLine(13,'#');
	gotoxy(28,2);
	textcolor(2);
	cprintf("BHARTIYA JANTA BANK (BJB)");
	textcolor(7);
	gotoxy(1,3);
	colorLine(13,'#');
	cout<<endl;
	gotoxy(1,3);
	cout<<endl;
}

//Function to display name header for tabular list display of account holders
void nameHeader()
{
	cout.setf(ios::left);
	colorLine(12,'+');
	cout<<setw(8)<<"A/c.No."
	    <<setw(8)<<"Cust.ID"
	    <<setw(20)<<"Name of Account"
	    <<setw(6)<<"Gender"
	    <<setw(6)<<"Type"
	    <<setw(10)<<"Balance"
	    <<setw(8)<<"Status"
	    <<endl;
	colorLine(12,'+');
}

//Open Account Function
void AccountOpen()
{
	unsigned long ano=0, id=0;
	//Reading File For Getting the Last Account Number
	ifstream fin("bank.dat",ios::in|ios::binary);
	while(fin.read((char*)&b,sizeof(b)))
	{
		ano=b.getAccNo();
		id=b.getCid();
	}
	fin.close();

	//Generating Automatic Account Number
	if(ano==0) ano=1;
	else	   ano+=1;

	if(id==0) id=10001;
	else id+=1;

	ofstream fout("bank.dat",ios::out|ios::app|ios::binary);

	textcolor(11+BLINK);
	cout<<"Your Account Number is   : ";
	cprintf("%u",ano);
	cout<<endl<<endl<<endl;
	textcolor(7);

	b.getData(ano,id);
	fout.write((char*)&b,sizeof(b));
	fout.close();
	cout<<"\n\n....Data Saved to File.....\n";
}

//Display Account Details List View
void AccountList()
{
	ifstream fin("bank.dat",ios::binary|ios::in);
	nameHeader();
	while(fin.read((char*)&b,sizeof(b)))
	{
		b.listData();
	}
	cout<<"\n....Data Reading from File Completed....\n";
	fin.close();
}

//Deposit Amount Function.....
void deposit()
{
	unsigned long ac;
	int flag=0, pos;
	float amount;
	cout<<"Enter Account no. to deposit amount : ";
	cin>>ac;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			if(b.getStatus()=='F'||b.getStatus()=='f')
			{
				cout<<"\nYour account is freezed.....";
				cout<<"\nContact Branch Office for assistance....\n";
				flag++;
			}
			else if(b.getStatus()=='C'||b.getStatus()=='c')
			{
				cout<<"\nYour account is closed....";
				cout<<"\nContact Branch Office for assistance...\n";
				flag++;
			}
			else
			{
				cout<<"\n.....Your Account Details.....\n";
				b.showData();
				cout<<"Enter Amount to Deposit : ";
				cin>>amount;
				fio.seekg(pos-sizeof(b));
				b.Deposit(amount);
				fio.write((char*)&b,sizeof(b));
				flag++;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\nEntered Account Number is invalid....\n";
	}
	fio.close();
}

//Withdraw Amount Function.....
void withdraw()
{
	unsigned long ac;
	int flag=0, pos;
	float amount;
	cout<<"Enter Account no. to Withdraw an amount : ";
	cin>>ac;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			if(b.getStatus()=='F'||b.getStatus()=='f')
			{
				cout<<"\nYour account is freezed.....";
				cout<<"\nContact Branch Manager for assistance....\n";
				flag++;
			}
			else if(b.getStatus()=='C'||b.getStatus()=='c')
			{
				cout<<"\nYour account is closed.....";
				cout<<"\nContact Branch Manager for assistance....\n";
				flag++;
			}
			else
			{
				cout<<"\n.....Your Account Details.....\n";
				b.showData();
				cout<<"Enter Amount to Withdraw : ";
				cin>>amount;
				fio.seekg(pos-sizeof(b));
				b.Withdraw(amount);
				fio.write((char*)&b,sizeof(b));
				flag++;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\nEntered Account Number is invalid....\n";
	}
	fio.close();
}

//Close Account Function Changes status to C from A
void AccountClose()
{
	unsigned long ac;
	int flag=0, pos;
	float amount;
	cout<<"Enter Account no. to Close : ";
	cin>>ac;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	ofstream fout("closed.dat",ios::binary|ios::app);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			cout<<"\nThe following account is closed now\n";
			cout<<"\n.....Your Account Details.....\n";
			b.showData();
			fio.seekg(pos-sizeof(b));
			b.closeAccount();
			fio.write((char*)&b,sizeof(b));
			fout.write((char*)&b,sizeof(b));
			flag++;
		}
	}
	if(flag==0)
	{
		cout<<"\nEntered Account Number is invalid....\n";
	}
	fio.close();
}

//Freeze Account Function Changes status to F from A
void AccountFreeze()
{
	unsigned long ac;
	int flag=0, pos;
	float amount;
	cout<<"Enter Account no. to Freeze : ";
	cin>>ac;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			if(b.getStatus()=='c'||b.getStatus()=='C')
			{
				cout<<"\nAccount No. "<<ac<<" is now freezed.....\n";
				cout<<"Contact branch office for assistance....\n";
				flag++;
			}
			else
			{
				cout<<"\nThe following account is freezed now\n";
				cout<<"\n.....Your Account Details.....\n";
				b.showData();
				fio.seekg(pos-sizeof(b));
				b.freezeAccount();
				fio.write((char*)&b,sizeof(b));
				flag++;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\nEntered Account Number is invalid....\n";
	}
	fio.close();
}

//UnFreeze Account Function Changes status to A from F
void AccountUnFreeze()
{
	unsigned long ac;
	int flag=0, pos;
	cout<<"Enter Account no. to UnFreeze : ";
	cin>>ac;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			if(b.getStatus()=='F'||b.getStatus()=='f')
			{
			cout<<"\nThe following account is unfreezed now\n";
			cout<<"\n.....Your Account Details.....\n";
			b.showData();
			fio.seekg(pos-sizeof(b));
			b.unFreezeAccount();
			fio.write((char*)&b,sizeof(b));
			flag++;
			}
			else if(b.getStatus()=='A' || b.getStatus()=='a')
			{
				cout<<"\nYour account is already active.....\n";
				flag++;
			}
		}
	}
	if(flag==0)
	{
		cout<<"\nEntered Account Number is invalid....\n";
	}
	fio.close();
}

//Display Closed Account Details List View
void ClosedAccounts()
{
	int flag=0;
	ifstream fin("bank.dat",ios::binary|ios::in);
	nameHeader();
	while(fin.read((char*)&b,sizeof(b)))
	{
		if(b.getStatus()=='C'||b.getStatus()=='c')
		{
			b.listData();
			flag++;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n\nNo Closed Accont in the Bank.....\n";
	cout<<"\n....Data Reading from File Completed....\n";
	fin.close();
}

//Display Active Account Details List View
void ActiveAccounts()
{
	int flag=0;
	ifstream fin("bank.dat",ios::binary|ios::in);
	nameHeader();
	while(fin.read((char*)&b,sizeof(b)))
	{
		if(b.getStatus()=='A'||b.getStatus()=='F')
		{
			b.listData();
			flag++;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n\nNo Active Account in the Bank.....\n";
	cout<<"\n....Data Reading from File Completed....\n";
}

//Display Freezed Account Details List View
void FreezedAccounts()
{
	int flag=0;
	ifstream fin("bank.dat",ios::binary|ios::in);
	nameHeader();
	while(fin.read((char*)&b,sizeof(b)))
	{
		if(b.getStatus()=='F')
		{
			b.listData();
			flag++;
		}
	}
	fin.close();
	if(flag==0)
		cout<<"\n\nNo Freezed Accont in the Bank.....\n";
	cout<<"\n....Data Reading from File Completed....\n";
}

//Display Total Bank Fund Account Wise
void BankFund()
{
	//Variable for counting balance
	float sbalance=0, cbalance=0, fbalance=0, tbalance=0;
	//Variable for counting account
	int cs=0,cc=0, cf=0, tf=0;

	ifstream fin("bank.dat",ios::binary|ios::in);
//	nameHeader();
	while(fin.read((char*)&b,sizeof(b)))
	{
		if(b.getStatus()=='F')
		{
			fbalance+=b.getBalance(),cf++;
		}
		else
		{
			if(b.getType()=='C'||b.getType()=='c')
				cbalance+=b.getBalance(), cc++;
			else if(b.getType()=='S'||b.getType()=='s')
				sbalance+=b.getBalance(),cs++;
		}
	}
	tf=cc+cs+cf;
	tbalance=sbalance+cbalance+fbalance;
	fin.close();
	cout<<endl<<endl;
	cout<<"\t\t\tTOTAL BANK FUNDS\n\n";
	cout<<"\tAccount Type\tNo. of Accounts\tNet Balance\n";
	cout<<"\t============\t===============\t===========\n\n";
	cout<<"\tSavings     \t"<<setw(11)<<cs<<setw(15)<<sbalance<<endl<<endl;
	cout<<"\tCurrent     \t"<<setw(11)<<cc<<setw(15)<<cbalance<<endl<<endl;
	cout<<"\tFreezed     \t"<<setw(11)<<cf<<setw(15)<<fbalance<<endl<<endl;
	cout<<"\t============\t===============\t===========\n";
	cout<<"\tTotal       \t"<<setw(11)<<tf<<setw(15)<<tbalance<<endl;
	cout<<"\t============\t===============\t===========\n";
}

//Modifying the details of Customers...
void modifyDetails()
{
	unsigned long ac;
	int flag=0, pos;
	cout<<"Enter Account no. to Modify : ";
	cin>>ac;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			cout<<"\n.....Your Account Details.....\n";
			b.showData();
			fio.seekg(pos-sizeof(b));
			b.modify();
			fio.write((char*)&b,sizeof(b));
			flag++;
		}
	}
	if(flag==0)
	{
		cout<<"\nEntered Account Number is invalid....\n";
	}
	fio.close();
}

//Menu Options
void Staffmenu()
{
	clrscr();
	Header();
	cout<<"0.  Exit\n";
	cout<<"1.  Register for New Account\n";
	cout<<"2.  See Account Details\n";
	cout<<"3.  Deposit Amount\n";
	cout<<"4.  Withdraw Amount\n";
	cout<<"5.  Close Account\n";
	cout<<"6.  Show Active Accounts\n";
	cout<<"7.  Show Closed Accounts\n";
	cout<<"8.  Freeze Account\n";
	cout<<"9.  Show Freezed Accounts\n";
	cout<<"10. Unfreeze Account\n";
	cout<<"11. Total Bank Fund\n";
	cout<<"12. Modify Customer Data\n";
	cout<<"Enter your choice  : ";
}
void project()
{
	int ch;
	do
	{
		Staffmenu();
		cin>>ch;
		clrscr();
		Header();
		switch(ch)
		{
			case 1:  AccountOpen(); break;
			case 2:  AccountList(); break;
			case 3:  deposit(); break;
			case 4:  withdraw(); break;
			case 5:  AccountClose(); break;
			case 6:  ActiveAccounts(); break;
			case 7:  ClosedAccounts(); break;
			case 8:  AccountFreeze(); break;
			case 9:  FreezedAccounts(); break;
			case 10: AccountUnFreeze(); break;
			case 11: BankFund(); break;
			case 12: modifyDetails(); break;
		}
		getch();
	}while(ch);
}

void home()
{
	int ch;
	do
	{
		clrscr();
		textcolor(11);
		gotoxy(28,2);	cprintf("=========================");
		textcolor(14);
		gotoxy(28,3);	cprintf("BANKING MANAGEMENT SYSTEM");
		textcolor(11);
		gotoxy(28,4);	cprintf("=========================");
		textcolor(4);
		gotoxy(28,7);	cprintf("0. EXIT");
		gotoxy(28,9);	cprintf("1. BANK STAFF");
		gotoxy(28,11);	cprintf("2. BANK CLIENTS");
		textcolor(13);
		gotoxy(28,13);	cprintf("ENTER YOUR CHOICE : ");
		textcolor(7);
		cin>>ch;
		switch(ch)
		{
			case 1: Staff(); break;
			case 2: ClientLogin(); break;
		}
		getch();
		cout<<endl;
	}while(ch);
}

void Staff()
{
  char pwd[]="password",verify[20], ch;
  int i=0;
  clrscr();
  cout<<"Enter the password to verify: ";
  do
  {
    ch=getch();
    if(ch!=13)
    {
	verify[i++]=ch;
	cout<<"*";
    }
    else
    {
	verify[i++]='\0';
    }
  }while(ch!=13);          //13 IS THE ASCII OF ENTER

  if(strcmp(pwd,verify)==0)
  {
	cout<<"\nPassword Matched...";
	getch();
	project();
  }
  else
	cout<<"\nWrong Password...";

}

//Menu Options
void Clientmenu()
{
	clrscr();
	Header();
	cout<<"0.  Back to main menu\n";
	cout<<"1.  Register for New Account\n";
	cout<<"2.  See Account Details\n";
	cout<<"3.  Deposit Amount\n";
	cout<<"4.  Withdraw Amount\n";
	cout<<"5.  Close Account\n";
	cout<<"6.  Show Active Accounts\n";
	cout<<"7.  Show Closed Accounts\n";
	cout<<"8.  Freeze Account\n";
	cout<<"9.  Show Freezed Accounts\n";
	cout<<"10. Unfreeze Account\n";
	cout<<"11. Total Bank Fund\n";
	cout<<"12. Modify Customer Data\n";
	cout<<"Enter your choice  : ";
}

void ClientLogin()
{
	int ch;
	clrscr();
	textcolor(11);
	gotoxy(28,2);	cprintf("=========================");
	textcolor(15);
	gotoxy(28,3);	cprintf("CLIENT LOGIN CREDENTIALS");
	textcolor(11);
	gotoxy(28,4);	cprintf("=========================");
	textcolor(12);
	gotoxy(28,7);	cprintf("0. BACK TO MAIN MENU");
	gotoxy(28,9);	cprintf("1. SIGN IN");
	gotoxy(28,11);	cprintf("2. FORGOT PASSWORD");
	textcolor(13);
	gotoxy(28,13);	cprintf("ENTER YOUR CHOICE : ");
	textcolor(7);
	cin>>ch;
	switch(ch)
	{
		case 1: SignIn(); break;
		case 2: ForgotPassword(); break;
	}
}

void SignIn()
{
	int uid,flag=0;
	int ch;
	char pwd[10];
	ifstream fin("bank.dat",ios::binary|ios::in);
	cout<<"\nEnter Customer ID : ";
	cin>>uid;
	cout<<"\nEnter Password    : ";
	cin>>pwd;
	while(fin.read((char*)&b,sizeof(b)))
	{
		if(uid==b.getCid() && b.getStatus()=='A')
		{
			if(strcmp(pwd,b.getPwd())==0)
			{
				cout<<"\nPassword Matched....";
				do
				{
				clrscr();
				cout<<"\nWelcome : "<<b.getName()<<endl;
				cout<<"0. Back to menu\n";
				cout<<"1. Change Password\n";
				cout<<"2. Check Balance\n";
				cout<<"3. Deposit Amount\n";
				cout<<"4. Withdraw Amount\n";
				cout<<"Enter your choice : ";
				cin>>ch;
				switch(ch)
				{
					case 1: ChangePassword(b.getAccNo());
					break;
					case 2:
						cout<<"Your Account Balnace is : "
						    <<b.getBalance()<<endl;
					break;
					case 3:
						deposit(b.getAccNo());
					break;
					case 4: withdraw(b.getAccNo());
					break;
				}
				getch();
				}while(ch);

				flag++;
			}
			else
			{
				cout<<"\nPassword Error....\n";
				cout<<"Press 1. to Reset your password.\n";
			}
		}
	}
	if(flag==0)
		cout<<"\nWrong User ID or Password\n";
	fin.close();
}

void deposit(unsigned long ac)
{
	int flag=0, pos;
	float amount;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			cout<<"\n.....Your Account Details.....\n";
			b.showData();
			cout<<"Enter Amount to Deposit : ";
			cin>>amount;
			fio.seekg(pos-sizeof(b));
			b.Deposit(amount);
			fio.write((char*)&b,sizeof(b));
			flag++;
		}
	}
	fio.close();
}

void withdraw(unsigned long ac)
{	int flag=0, pos;
	float amount;
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(ac==b.getAccNo())
		{
			cout<<"\n.....Your Account Details.....\n";
			b.showData();
			cout<<"Enter Amount to Withdraw : ";
			cin>>amount;
			fio.seekg(pos-sizeof(b));
			b.Withdraw(amount);
			fio.write((char*)&b,sizeof(b));
			flag++;
		}
	}
	fio.close();
}

void ChangePassword(unsigned long ac)
{
	int flag=0, pos;
	char opwd[10],npwd[10];
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	cout<<"Enter Old Password: ";
	cin>>opwd;
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(strcmp(opwd,b.getPwd())==0 && ac==b.getAccNo())
		{
			fio.seekg(pos-sizeof(b));
			b.newPassword();
			fio.write((char*)&b,sizeof(b));
			flag++;
			break;
		}
	}
	fio.close();
}

void ForgotPassword()
{	int flag=0, pos;
	unsigned long id;
	char ans[10];
	fstream fio("bank.dat",ios::binary|ios::in|ios::out);
	cout<<"Enter the Client ID : ";
	cin>>id;
	while(fio.read((char*)&b,sizeof(b)))
	{
		pos=fio.tellg();
		if(id==b.getCid())
		{
			cout<<"Enter Answer of your Secret Question:\n";
			cout<<b.getSecQuestion()<<": ";
			cin>>ans;
			if(strcmp(ans,b.getSecAnswer())==0)
			{
				fio.seekg(pos-sizeof(b));
				b.resetPassword();
				fio.write((char*)&b,sizeof(b));
				flag++;
			}
		}
	}
	if(flag==0)
		cout<<"\nID or Secret Answer Does Not Matched...\n";
	fio.close();
}

void main()
{
	clrscr();
	textcolor(14);
	gotoxy(27,5);
	cprintf("BANKING MANAGEMENT SYSTEM");
	textcolor(11);
	gotoxy(36,9);
	cprintf("Made By:");
	gotoxy(33,10);
	cprintf("Krushnaraj Pandya");
	gotoxy(27,13);
	cprintf("Computer-Engineering Student");
	gotoxy(24,14);
	cprintf("Memorial University of Newfoundland");
	getch();
	home();
}
