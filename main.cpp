#include<iostream>
#include<fstream>
#include<cstring>
#include<windows.h>
#include<conio.h>
#include"header.h"
using namespace std;



int main()
{   

    system("color a");
    bool condition;
    char ltest;
    char choice;
    
    fstream admin;
    admin.open("admin/system.txt",ios::in);
    string status;
    getline(admin,status);

   // loading();

    do{
    if(status=="1")
    {
        
     m: 
    system("color a");
    menu();
    cout<<"\n->:";
    cin>>choice;

    system("cls");

    if(choice=='1'){reg();}
    else if(choice=='2')
    {   c:
        condition=login();
        ltest=lget();
        if(ltest=='1')
        {
        if(condition==true)
        {
            cout<<"Login successsfully"<<endl;
            Sleep(500);
            system("cls");
            game();
            checkSlotStudent();
            system("cls");

        }
        else 
        {
        cout<<"wrong  password"<<endl;
        cout<<"press any key to Try again"<<endl;
        cout<<"press x for main menu"<<endl;
        char m;
        m=getch();system("cls");
        if(m=='x'){goto m;}
        goto c;
        }
        }
        else {cout<<"press x key for main menu"<<endl;
              cout<<"press any key for try again"<<endl;

        char m2;
        m2=getch();system("cls");
        if(m2!='x'){goto c;}
        }
    }
    else if(choice =='3')
    {
        clock();
        getch();
    }
    else if(choice =='4')
    {   string st;
        system("cls");
        adminpanel();
        fstream r;
        r.open("admin/system.txt",ios::in);
        getline(r,st);
        r.close();
        if(st=="0")
        {
            break;
        }
    }

    else if(choice=='0')
    {
        cout<<"Exiting ";
        getch();
    }
    else cout<<"Invalid Choice"<<endl;
    }
    else if(status=="0")
    {
        char c,q;
        system("color c");
        system("color a");
        q=maintenance();
        if(q=='1')
        {adminpanel();}
        else
        cout<<"Exited"<<endl;
        break;
       
    }
    else{cout<<"Internal system file problem :) "<<endl;}
    
    
    }while(choice!='0');

} 