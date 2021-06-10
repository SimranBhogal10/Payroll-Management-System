#include <iostream>
#include<stdlib.h>
#include<windows.h>
#include<fstream>
#include<process.h>
#include<iomanip>
#include<fstream>
#include<stdio.h>
#include<conio.h>

using namespace std;

class noticeee
{
private:

    int empidE1;
    string noticetxt;

public:

    void notice();
    void shownotice();

}n1;

class pyrl
{
  private:

      string empname;
      int empid;
      int pass;
      char rank1[30];
      char doj[30];
      int salary;
      char team[20];

  public:

      void newemp();
      void adminlogin();
      void emplogin();
      void showall();
      void showone();
      void update_r_s();
      void accdepartment();
      void empmenu();
      void dlt();
      void update_p();
}e1;

void pyrl::newemp()
{
    system("cls");
    cout << "Enter Employee name-";
    cin.ignore();
    getline(cin,empname);
    cout << "Assign an Employee ID- ";
    cin >> empid;
    cout << "Assign a Password- ";
    cin >> pass;
    cout << "Enter Rank- ";
    cin >> rank1;
    cout << "Enter Date Of Joining (format- DD/MM/YYYY)- ";
    cin >> doj;
    cout << "Enter Salary- ";
    cin >> salary;
    cout << "Enter Team- ";
    cin >> team;
    cout<<"RECORD SUCESSFULLY ADDED " << endl<<"PRESS ANY KEY TO CONTINUE" << endl;
    getch();

}

void pyrl::adminlogin()
{
    flagA:
    system("cls");
    fstream f91;
    int empidA, k1=0;
    int passA;

    f91.open("empdetails.dat",ios::in);
    f91.seekg(0);

    cout << endl << "Enter Your Employee ID- ";
    cin >> empidA;

    while(f91.read((char*)&e1,sizeof(e1)))
    {

    if(empid==empidA)
    {
       k1=k1+1;
       cout << endl << "Enter Your Password- ";
       cin >> passA;

       if(pass==passA)
       {
               f91.clear();
               f91.close();
           e1.accdepartment();

       }
    }
    f91.read((char *)&e1,sizeof(e1));
    }
    if(k1==0)
    {
        cout<<"Employee ID  not found";
        getch();
    }
    f91.clear();
    f91.close();
}

void pyrl::accdepartment()
{
    int a;
    flagacc:
    system("cls");

    cout << endl << "ACCOUNT DEPARTMENT";
    cout << endl << "PRESS 1 FOR ADDING NEW EMPLOYEE";
    cout << endl << "PRESS 2 FOR SHOWING LIST OF ALL EMPLOYEES";
    cout << endl << "PRESS 3 FOR SHOWING RECORD OF A PARTICULAR EMPLOYEES";
    cout << endl << "PRESS 4 FOR UPDATING SALARY";
    cout << endl << "PRESS 5 FOR CHECKING RESIGNATIONS LIST";
    cout << endl << "PRESS 6 FOR DELETING AN EMPLOYEE DETAILS";
    cout << endl << "PRESS 7 TO LOGOUT";
    cout << endl << "ENTER YOUR CHOICE- ";
    cin >> a;
    cout << endl << endl;

    if(a==1)
        {
            fstream f1;
            f1.open("empdetails.dat",ios::out | ios::app);
            f1.tellg();
            e1.newemp();
            f1.write((char*)&e1,sizeof(e1));
            f1.clear();
            f1.close();
            goto flagacc;
        }

    else if(a==2)
        {
            e1.showall();
            goto flagacc;
        }

    else if(a==3)
        {
            e1.showone();
            goto flagacc;
        }

    else if(a==4)
        {
            e1.update_r_s();

            fstream f4;
            goto flagacc;
        }

    else if(a==5)
        {
            system("cls");
            fstream f6;
            f6.open("noticedetails.dat",ios::in);
            while(f6.read((char*)&n1,sizeof(n1)))
            {
                n1.shownotice();
            }
            f6.close();
            goto flagacc;
        }

    else if(a==6)
        {
            e1.dlt();

            goto flagacc;
        }

    else if(a==7)
        {
            cout<<"\t\t\t\t***SEE YOU AGAIN***" << endl << endl;
            exit(0);
        }
    else
        {
            cout << "Invalid input" << endl;
            cout << "TRY AGAIN:)" << endl;
            goto flagacc;
        }
}

void pyrl::showall()
{
    system("cls");
    fstream f2;
    f2.open("empdetails.dat",ios::in);
    while(f2.read((char*)&e1,sizeof(e1)))
          {
            cout << empname << setw(15) << empid << setw(15) << pass << setw(15) << rank1 << setw(15) << doj << setw(15) << salary << setw(15) << team << endl;
          }
    f2.clear();
    f2.close();
    cout<<"\n\tPRESS ANY KEY TO CONTINUE";
    getch();
    system("cls");

}

void pyrl::showone()
{
    system("cls");
    fstream f3;
    int r2,k2=0;

        f3.open("empdetails.dat",ios::in);
        f3.seekg(0);

        cout << "\nEnter the Employee Id which needs to be displayed:";
        cin >> r2;

        while(f3.read((char*)&e1,sizeof(e1)))
        {
            if(r2==e1.empid)
            {
                k2=1;
                break;
            }
        }
        f3.clear();
        if(k2==1)
        {
            f3.seekp(f3.tellp()-sizeof(e1));
            cout << empname << setw(15) << empid << setw(15) << pass << setw(15) << rank1 << setw(15) << doj << setw(15) << salary << setw(15) << team << endl;
        }

        else
        {
            cout << "\n\t\tEmployee ID " << r2 << " not found";
        }

        getch();
        system("cls");
        f3.close();

}

void pyrl::update_r_s()
{
    system("cls");

    fstream f4;
    int s,k=0;
    int m;

    f4.open("empdetails.dat",ios::out|ios::in|ios::ate);
    f4.seekg(0);

    cout<<"\n\t\tENTER THE EMPLOYEE ID WHOSE SALARY NEED TO BE UPDATED:";
    cin>>s;

    while(f4.read((char*)&e1,sizeof(e1)))
    {
        if(s==e1.empid)
        {
            k=1;
            break;
        }
    }

    f4.clear();

    if(k==1)
    {
        f4.seekp(f4.tellp()-sizeof(e1));
        cout<<"\n\t\tENTER THE NEW SALARY:";
        cin>>m;
        e1.salary=m;
        f4.write((char*)&e1,sizeof(e1));
        cout<<"\n\t\tRECORD UPDATED SUCESSFULLY..";
    }

    else
    {
        cout << "\n\t\ EMPLOYEE ID " << s << " NOT FOUND";
    }

    getch();
    f4.close();
    system("cls");
}


void pyrl::dlt()
{
       system("cls");
       fstream f1,f2;
	   int id,c=0,rec;
	   f1.open("empdetails.dat",ios::in|ios::ate);
	   rec = f1.tellp()/sizeof(e1);

	   f2.open("temp.dat",ios::out);
	   cout<<"\n\t\tENTER THE EMPLOYEE ID WHICH NEED TO BE DELETED:";
	   cin>>id;
	   f1.seekg(0);
	   while(f1.read((char*)&e1,sizeof(e1)))
	    {
	      if(id!=e1.empid)
	       {
		        c++;
                f2.write((char*)&e1,sizeof(e1));
	       }
	   }

	   f1.clear();
	   f1.close();
	   f2.close();
	   remove("empdetails.dat");
	   rename("temp.dat","empdetails.dat");
	   if(rec==c)
	      cout<<"\n\t\tEMPLOYEE ID "<<id<<" NOT FOUND";
	   else
	      cout<<"\n\t\tRECORD DELETED SUCESSFULLY..";
	   getch();
	   system("cls");
}

void noticeee::shownotice()
{

    cout <<"EMPLOYEE ID --"<< empidE1 << endl << "REASON -->" << noticetxt << endl;
    getch();
}

void pyrl::emplogin()
{

       fstream f9;
       f9.open("empdetails.dat",ios::in|ios::out|ios::app);
       int empidE, passE, k=0;
       system("cls");

       cout << endl << "Enter Your Employee ID- ";
       cin >> empidE;

       f9.seekg(0,ios::beg);
       f9.read((char *)&e1,sizeof(e1));


       while(f9.eof()==0)
       {
       if(empid==empidE)
       {
           k=k+1;
           cout << endl << "Enter Your Password- ";
           cin >> passE;

           if(pass==passE)
           {
               empmenu();
           }
       }
       f9.read((char *)&e1,sizeof(e1));

       }
       if(k==0)
       cout<<"Employee ID  not found";
       getch();
       f9.close();
}

void pyrl::empmenu()
{
    int z;
    system("cls");
    flagemp:
    cout << endl << "*ACCOUNT DEPARTMENT*";
    cout << endl << "PRESS 1 TO SEE YOUR RECORD";
    cout << endl << "PRESS 2 FOR UPDATING YOUR PASSWORD";
    cout << endl << "PRESS 3 TO POST 30 DAY NOTICE FOR  RESIGNATION";
    cout << endl << "PRESS 4 TO LOGOUT";
    cout << endl << "ENTER YOUR CHOICE- ";
    cin >> z;
    cout << endl << endl;

    if(z==1)
        {
            e1.showone();
            goto flagemp;
        }

    else if(z==2)
        {
            update_p();
            goto flagemp;
        }

    else if(z==3)
        {
            fstream f11;
            f11.open("noticedetails.dat",ios::out | ios::app);
            f11.tellg();
            n1.notice();
            f11.write((char*)&n1,sizeof(n1));
            f11.close();
            goto flagemp;
        }

    else if(z==4)
        {
            cout<<"*SEE YOU AGAIN*";
            exit(0);
        }
    else
        {
            cout << "Invalid input" << endl;
            goto flagemp;
        }
}

void pyrl::update_p()
{
    system("cls");

    fstream f12;
    int s,k=0;
    int m;

    f12.open("empdetails.dat",ios::out|ios::in|ios::ate);
    f12.seekg(0);

    cout<<"\n\t\tREENTER YOUR EMPLOYEE ID:";
    cin>>s;

    while(f12.read((char*)&e1,sizeof(e1)))
    {
        if(s==e1.empid)
        {
            k=1;
            break;
        }
    }

    f12.clear();

    if(k==1)
    {
        f12.seekp(f12.tellp()-sizeof(e1));
        cout << "\n\t\tENTER THE NEW PASSWORD:";
        cin >> m;
        e1.pass=m;
        f12.write((char*)&e1,sizeof(e1));
        cout<<"\n\t\tPASSWORD UPDATED SUCESSFULLY..";
    }

    else
    {
        cout << "\n\t\ EMPLOYEE ID " << s << " NOT FOUND";
    }

    getch();
    f12.close();
    system("cls");
}

void noticeee::notice()
{
    system("cls");
    cout << "Enter Your Employee ID- ";
    cin >> empidE1;
    cout << "Reason- ";
    cin.ignore();
    getline(cin,noticetxt);
    cout << endl << endl;
}

int main()
{

    char choice;
    do
    {
        system("cls");
        cout<<endl<<endl<<"**PAYROLL**";
        cout<<endl<<endl<<"PRESS 1 FOR ACCOUNT DEPARTMENT LOGIN";
        cout<<endl<<"PRESS 2 FOR EMPLOYE LOGIN";
        cout<<endl<<"PRESS 3 FOR EXIT";
        cout<<endl<<"ENTER YOUR CHOICE=";
        cin.get(choice);

        switch(choice)
        {
           case '1':
               e1.adminlogin();
               break;
           case '2':
               e1.emplogin();
               break;
          case '3':
               cout << endl << "**SEE U AGAIN**" << endl;
               break;
          default:
            cout << endl << "**WRONG CHOICE**";
            getch();
        }
    }while(choice!='3');
}
