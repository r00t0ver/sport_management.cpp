#include<iostream>
#include<fstream>
#include<cstring>
#include <string>
#include<windows.h>
#include<conio.h>
using namespace std;
string user,pass;
char l=219;
char ll=176;
void logData();
void checkSlot();
void adminSlotReserve();
void readStudentInfo();
string passHide(string xx,string yy);
string encryption(string x);
string decryption(string x);
bool login();
char lset(char x);
char lget();
char ck;
void studentInfo(string x);
void checkSlotStudent();
string adminPass();
string adminUser();
void changePass();

void line()
{
    for(int i=0;i<40;i++)
    {
        cout<<ll;
    }
    cout<<endl;
}
void line(int y)
{
    char l=176;
    char s=y;
    for(int i=0;i<s;i++)
    {
        cout<<l;
    }
}
char lset(char x)
{
    ck=x;
    return ck;
}
char lget()
{
    return ck;
}

void loading()
{
    char c=219;
    string ch[51];
    cout<<"SPORTS MANAGEMENT PROGRAM ";
    Sleep(20);
    
    

    for(int i=0;i<51;i++)
    {
        for(int j=0;j<i;j++)
        {
            ch[i]=ch[i]+c;
        }
    }
    
    for(int i=0;i<51;i++)
    {
        
        if(i==0){system("color a");}
        if(i==10){system("color b");}
        if(i==20){system("color c");}
        if(i==30){system("color d");}
        if(i==40){system("color e");}
        if(i==50){system("color f");}
   
        cout<<"\n\n\n\t\t\t\tSPORTS MANAGEMENT PROGRAM \n";
        cout<<"\n\n\t\t\t\t";cout<<"LOADING ";
        cout<<ch[i]<<" "<<i*2<<"%";
        Sleep(1);
        if(i==50)
        break;
        system("cls");
    }
    cout<<endl;
    cout<<"\n\n\t\t\t\tpress any key for continue...";
    getch();
    system("cls");
}
void menu()
{
    Sleep(10);
    cout<<endl<<l;
    line();
    cout<<l<<"SPORTS MANAGEMENT PROGRAM \n";
    cout<<l;
    line();
    cout<<l<<" 1.Create a account"<<endl;Sleep(50);
    cout<<l<<" 2.Login a account"<<endl;Sleep(50);
    cout<<l<<" 3.Show time"<<endl;Sleep(50);
    cout<<l<<" 4.Admin panel"<<endl;Sleep(50);
    cout<<l<<" 0.exit()"<<endl;cout<<l;
    line();
}

void reg()
{   
    string name,pass,confirm;
    int cn;
    line(12);
    cout<<" Registration ";
    line(12);
    cout<<endl;

    cout<<"User Name: ";cin>>name;
    cout<<"Password : ";cin>>pass;
    cout<<"Confirm password:";cin>>confirm; 
    if(name!="admin")
    {
        if(pass==confirm)
        {  
    fstream file;
    fstream check;
    check.open("log/"+name+".txt",ios::in);
    if(!check.is_open())
    {
        
            
    string  fname,dob,blood,mobile,department;
    cout<<"Enter full name: ";cin.ignore();getline(cin,fname);
    cout<<"Date of birth  : ";cin>>dob;
    cout<<"Blood group    : ";cin>>blood;
    cout<<"Mobile number  : ";cin>>mobile;
    cout<<"Department     : ";cin>>department;




        file.open("log/"+name+".txt",ios::out);
        pass=encryption(pass);
        file<<name<<endl;
        file<<pass<<endl;
        file<<fname<<endl;
        file<<dob<<"\t"<<blood<<"\t"<<mobile<<"\t"<<department;
        file.close();

        cout<<name<<" ,you created a account successfully !"<<endl;
        getch();
        system("cls");
    }
    else
    {cout<<"\nThis user name is already used\n";getch();system("cls");}

        }
        else {cout<<"Both Password are not matching !?";}

    }
    else{cout<<"This username is not available"<<endl;}
}
string userData(string x)
{
    user=x;
    return user;
}
bool login()
{
    bool log=false;
    string user,pass,usr,psd,depass;
    system("cls");
    line(12);
    cout<<" Log in ";
    line(12);
    cout<<endl;
    cout<<"Enter username: ";cin>>user;
    cout<<"Enter Password: ";cin>>pass;

    // pass=passHide(user," Log in ");
    cout<<endl;
    fstream file("log/"+user+".txt",ios::in);
    if(!file.is_open())
    {
    cout<<"account does not exist !"<<endl;
    lset('3');
    
    }
    else
    getline(file,usr);
    getline(file,psd);
    psd=decryption(psd);
    if(user==usr&&pass==psd)
    {
        log=true;
        lset('1');
        userData(user);
    }
    else if(usr==user&&pass!=psd) 
    {log=false;lset('1');}
    file.close();
    return log;
}
void clock()
{   
    system("time /t");
    system("date /t");
}
void slotForCarrom()
{
    char ch;
    system("cls");
    cout<<"1..slot 1: 12pm-1pm"<<endl;
    cout<<"2..slot 2: 1pm-2pm"<<endl;
    
    cout<<"->:";
    cin>>ch;
    fstream write;
    write.open("game/indoor/carrom/slot1.txt");
    if(ch=='1')
    {
        if(!write.is_open())
        
    {
    write.open("game/indoor/carrom/slot1.txt",ios::out);
    write<<user;
    cout<<user<<", Now slot 1 is booked for you"<<endl;
    write.close();
    
    }
    else{cout<<"Sorry , "<<user<<" ,Slot 1 is already booked "<<endl;}
    }
    else if(ch=='2')
    {
        fstream write2 ;
        write2.open("game/indoor/carrom/slot2.txt");
        if(!write2.is_open())
        {
            write2.open("game/indoor/carrom/slot2.txt",ios::out);
            write2<<user;
            cout<<user<<" , Now slot 2 is booked for you"<<endl;
            write2.close();  
        }
        else
        {cout<<"Sorry , "<<user<<" ,slot 2 is alreay booked"<<endl;}
        
    }


}
void slotForFootball()
{
        char ch;
        system("cls");
    cout<<"1..slot 1: 12pm-1pm"<<endl;
    cout<<"2..slot 2: 1pm-2pm"<<endl;
    cout<<"->:";
    cin>>ch;
    fstream write;
    write.open("game/outdoor/football/slot1.txt");
    if(ch=='1')
    {
        if(!write.is_open())
        
    {
    write.open("game/outdoor/football/slot1.txt",ios::out);
    write<<user;
    cout<<user<<" ,Now slot 1 is booked for you"<<endl;
    write.close();
    
    }
    else{cout<<"Sorry , "<<user<<" ,Slot 1 is already booked"<<endl;}
    }
    else if(ch=='2')
    {
        fstream write2 ;
        write2.open("game/outdoor/football/slot2.txt");
        if(!write2.is_open())
        {
            write2.open("game/outdoor/football/slot2.txt",ios::out);
            write2<<user;
            cout<<user<<" ,Now slot 2 is booked for you"<<endl;
            write2.close();  
        }
        else
        {cout<<"Sorry , "<<user<<" ,slot 2 is alreay booked"<<endl;}
        
    }
}
void indoor()
{
    fstream carrom;
    carrom<<"Booked";
    cout<<"1.Carrom "<<endl;
    char choice;
    cout<<"\n->: ";cin>>choice;
    if(choice=='1')
    {
        slotForCarrom();
        getch();
        system("cls");
    }

}
void outdoor()
{
    cout<<"1.Football"<<endl;

    char choice;
    cout<<"\n->: ";cin>>choice;
    if(choice=='1')
    {
        slotForFootball();
        getch();
        system("cls");
    }
}
void game()
{
    char choice;
    do
    {
    cout<<"1.Indoor Game"<<endl;
    cout<<"2.Outdor Game"<<endl;
    cout<<"3.Check available slot"<<endl;
    cout<<"0.exit"<<endl;
    
    cout<<"\nEnter your choice: ";cin>>choice;
    if(choice=='1')
    {
        indoor();
    }
    else if(choice=='2')
    {
        outdoor();
    }
    else if(choice=='3')
    {
        checkSlotStudent();
        getch();
        system("cls");
        
    }
    else if (choice=='0')
    {
        cout<<"exiting"<<endl;
        
    }
    else 
    {
        system("cls");
        cout<<"Invalid choice"<<endl;
        getch();
        system("cls");
    }
    }while(choice!='0');
}


void adminMenu()
{
    line(12);
    cout<<" Admin Panel ";
    line(12);
    cout<<endl;
    cout<<l<<" 1.ShutDown the system"<<endl;Sleep(20);
    cout<<l<<" 2.PowerUp the System"<<endl;Sleep(20);
    cout<<l<<" 3.Make All Slot Available"<<endl;Sleep(20);
    cout<<l<<" 4.show all slot "<<endl;Sleep(20);
    cout<<l<<" 5.Destroy the System"<<endl;Sleep(20);
    cout<<l<<" 6.Reserve a slot"<<endl;Sleep(20);
    cout<<l<<" 7.Check total user list"<<endl;Sleep(20);
    cout<<l<<" 8.Check student details"<<endl;Sleep(20); 
    cout<<l<<" 9.Change Admin user and Password"<<endl;Sleep(20);
    cout<<l<<" 0.exit"<<endl;Sleep(20);
}

void adminpanel()

{   
    char ch;
    string username,password;
    // cout<<"\n\n";
    system("color c");
    char l=219;
    char x;
    A:

    line(12);
    Sleep(30);
    cout<<" ADMIN PANEL  ";
    line(12);Sleep(30);
    cout<<endl;
    
    
    cout<<"Enter username: ";cin>>username;
    cout<<"Enter Password: ";cin>>password;
    //password=passHide(username," Admin Panel ");
 
    string userr,passd;
    userr=adminUser();
    passd=adminPass();
    passd=decryption(passd);
    // cout<<userr;
    // cout<<passd;
    // getch();

    do{

    if(username==userr&&password==passd)
    {
    system("cls");
    adminMenu();
    cout<<"->: ";cin>>ch;
    if(ch=='1')
    {
        fstream read;
        read.open("admin/system.txt",ios::in);
        string x1;
        getline(read,x1);
        read.close();
        if(x1=="1")
        {
            fstream write;
            write.open("admin/system.txt",ios::out);
            write<<"0";
            write.close();
            cout<<"Shuting Down the System ";
            for(int i=0;i<50;i++){cout<<l;Sleep(50);}
            cout<<endl;

        }
        else {cout<<"System is already shutdown"<<endl;}
    }
    else if(ch=='2')
    {
        fstream read;
        read.open("admin/system.txt",ios::in);
        string x2;
        getline(read,x2);
        read.close();

        if(x2=="0")
        {
            fstream write;
            write.open("admin/system.txt",ios::out);
            write<<"1";
            write.close();
            cout<<"Starting the system ";
            for(int i=0;i<50;i++){cout<<l;Sleep(50);}
            cout<<endl;
        }
        else{cout<<"System is running"<<endl;}
    }
    else if(ch=='3')
    {
        string ch;
        cout<<"Are you sure?  [type  yes or no]"<<endl;
        cin>>ch;
        if(ch=="yes")
        {
            remove("game/indoor/carrom/slot1.txt");
            remove("game/indoor/carrom/slot2.txt");
            remove("game/outdoor/football/slot1.txt");
            remove("game/outdoor/football/slot2.txt");
            cout<<"Cleaning up..."<<endl;Sleep(1000);
            cout<<"Now All slot are available"<<endl;
        }
        else if(ch=="no")
        {
            cout<<"You choose no\n";
        }
        else{cout<<"Type yes or no\n";}
    }
    else if(ch=='4')
    {
        checkSlot();
        cout<<"any key for continue.."<<endl;
        getch();
    }
    else if(ch=='5')
    {
        string usr,pass;
        cout<<"Are you sure you want to destroy the system"<<endl;
        cout<<"Enter username:";cin>>usr;
        cout<<"Enter password:";cin>>pass;
        if(usr=="admin"&&pass=="password")
        {
            string con;
            cout<<"Are your sure  [type yes or no ]"<<endl;
            cin>>con;
            if(con=="yes")
            {
                system("rmdir /s /q admin");
                system("rmdir /s /q game");
                system("rmdir /s /q log");
                system("del /s /q *.*");
                system("cls");
            }
            else if(con=="no"){cout<<"You choose no"<<endl;}
            else {cout<<"choose yes or not";}
        }
    }
    else if(ch=='6')
    {
        adminSlotReserve();
    }
    else if(ch=='7')
    {
        system("cls");
        system("dir /r log");
        getch();
    }
    else if(ch=='8')
    {
        readStudentInfo();
    }
    else if(ch=='9')
    {
        changePass();
        getch();
        system("cls");
    }
    else if(ch=='0')
    {
       
        cout<<"exiting.."<<endl;
        system("cls");
         break;
         
    }
    else 
    {cout<<"Invalid choice"<<endl;}
    }
    
    else if(username!="admin"||password!="password")
    {
        cout<<"Wrong Username or Password"<<endl;
        cout<<"press any key for continue..."<<endl;
        cout<<"press x for main menu"<<endl;
        x=getch();
        if(x=='x'){system("cls");break;}
        system("cls");
        goto A;
    } 
    
    
    system("cls");
    system("color c");
    

    }while(true);

}




void checkSlot()

{   system("cls");
    system("color a");
    for(int i=0;i<8;i++){cout<<l;}
    cout<<"Carrom";
    for(int i=0;i<8;i++){cout<<l;}

    cout<<endl<<endl;
    fstream file;
    file.open("game/indoor/carrom/slot1.txt",ios::in);
    string str1;
    if(!file.is_open())
    {
        cout<<"Indoor -> Carrom -> slot 1 is available !"<<endl;
    }
    else
    {
        getline(file,str1);
        if(str1=="admin")
        {
            cout<<"Slot 1 is Reserved by you"<<endl;
        }
        else
        cout<<"Indoor ->Carrom ->slot 1 is booked by  "<<str1<<endl;
        file.close();
    }
        fstream file2;
    file2.open("game/indoor/carrom/slot2.txt",ios::in);
    string str2;
    if(!file2.is_open())
    {
        cout<<"Indoor -> Carrom -> slot 2 is available !"<<endl;
    }
    else
    {
        getline(file2,str2);
        if(str2=="admin")
        {
            cout<<"Slot 2 is Reserved by you"<<endl;
        }
        else
        cout<<"Indoor ->Carrom ->slot 2 is booked by  "<<str2<<endl<<endl;
        file2.close();
    }
    for(int i=0;i<8;i++){cout<<l;}
    cout<<"Football";
    for(int i=0;i<8;i++){cout<<l;}
    cout<<endl<<endl;
    fstream file3;
    file3.open("game/outdoor/football/slot1.txt",ios::in);
    string str3;
    if(!file3.is_open())
    {
        cout<<"outdoor -> football -> slot 1 is available !"<<endl;
    }
    else
    {
        getline(file3,str3);
        if(str3=="admin")
        {
            cout<<"Slot 1 is Reserved by you"<<endl;
        }
        else
        cout<<"outdoor ->football ->slot 1 is booked by  "<<str3<<endl;
        file3.close();
    }


    fstream file4;
    file4.open("game/outdoor/football/slot2.txt",ios::in);
    string str4;
    if(!file4.is_open())
    {
        cout<<"outdoor -> football -> slot 2 is available !"<<endl;
    }
    else
    {
        getline(file4,str4);
        if(str4=="admin")
        {
            cout<<"Slot 2 is Reserved by you"<<endl;
        }
        else
        cout<<"outdoor ->football ->slot 2 is booked by  "<<str4<<endl;
        file4.close();
    }




}

void checkSlotStudent()
{
    system("color a");
    for(int i=0;i<8;i++){cout<<l;}
    cout<<"Carrom";
    for(int i=0;i<8;i++){cout<<l;}

    cout<<endl<<endl;
    fstream file;
    file.open("game/indoor/carrom/slot1.txt",ios::in);
    string str1;
    if(!file.is_open())
    {
        cout<<"Indoor -> Carrom -> slot 1 is available !"<<endl;
    }
    else
    {
        getline(file,str1);
        if(str1=="admin")
        {
            cout<<"Slot 1 is Reserved"<<endl;
        }
        else
        cout<<"Indoor ->Carrom ->slot 1 is not avilable :( "<<endl;
        file.close();
    }
        fstream file2;
    file2.open("game/indoor/carrom/slot2.txt",ios::in);
    string str2;
    if(!file2.is_open())
    {
        cout<<"Indoor -> Carrom -> slot 2 is available !"<<endl;
    }
    else
    {
        getline(file2,str2);
        if(str2=="admin")
        {
            cout<<"Slot 2 is Reserved"<<endl;
        }
        else
        cout<<"Indoor ->Carrom ->slot 2 is not avilable :( "<<endl<<endl;
        file2.close();
    }
    for(int i=0;i<8;i++){cout<<l;}
    cout<<"Football";
    for(int i=0;i<8;i++){cout<<l;}
    cout<<endl<<endl;
    fstream file3;
    file3.open("game/outdoor/football/slot1.txt",ios::in);
    string str3;
    if(!file3.is_open())
    {
        cout<<"outdoor -> football -> slot 1 is available !"<<endl;
    }
    else
    {
        getline(file3,str3);
        if(str3=="admin")
        {
            cout<<"Slot 1 is Reserved"<<endl;
        }
        else
        cout<<"outdoor ->football ->slot 1 is not avilable :( "<<endl;
        file3.close();
    }


    fstream file4;
    file4.open("game/outdoor/football/slot2.txt",ios::in);
    string str4;
    if(!file4.is_open())
    {
        cout<<"outdoor -> football -> slot 2 is available !"<<endl;
    }
    else
    {
        getline(file4,str4);
        if(str4=="admin")
        {
            cout<<"Slot 2 is Reserved"<<endl;
        }
        else
        cout<<"outdoor ->football ->slot 2 is not avilable :( "<<endl;
        file4.close();
    }
}

void adminSlotReserve()
{
    char ch;
    cout<<"1.indoor"<<endl;
    cout<<"2.outdoor"<<endl;
    cout<<"->:";
    cin>>ch;
    if(ch=='1')
    {
        char c;
        cout<<"1.carrom"<<endl;
        cout<<"->:";
        cin>>c;
        if(c=='1')
        {
            cout<<"1...Slot 1"<<endl;
            cout<<"2...Slot 2"<<endl;
            char cc;
            cout<<"->:";
            cin>>cc;
            if(cc=='1')
            {
                fstream w1;
                w1.open("game/indoor/carrom/slot1.txt",ios::in);
                string nam;
                getline(w1,nam);
                w1.close();
                if(!w1.is_open())
                {
                    
                        fstream w2;
                        w2.open("game/indoor/carrom/slot1.txt",ios::out);
                        w2<<"admin";
                        w2.close();
                        cout<<"Reserved !"<<endl;
                }
                else
                {
                        cout<<nam<<" already booked this slot1"<<endl;
                }

            }
            else if(cc=='2')
            {
                fstream w1;
                w1.open("game/indoor/carrom/slot2.txt",ios::in);
                string nam;
                getline(w1,nam);
                w1.close();
                if(!w1.is_open())
                {
                    fstream w2;
                        w2.open("game/indoor/carrom/slot2.txt",ios::out);
                        w2<<"admin";
                        w2.close();
                        cout<<"Reserved !"<<endl;
                }
                else
                {
                        cout<<nam<<" already booked this slot1"<<endl;
                }
            }
            else {cout<<"Invalid choice"<<endl;}
        }
        else{cout<<"Invalid choice"<<endl;}

    }
    else if(ch=='2')
    {

        char c;
        cout<<"1.Football"<<endl;
        cout<<"->:";
        cin>>c;
        if(c=='1')
        {
            cout<<"1...Slot 1"<<endl;
            cout<<"2...Slot 2"<<endl;
            char cc;
            cout<<"->:";
            cin>>cc;
            if(cc=='1')
            {
                fstream w1;
                w1.open("game/outdoor/football/slot1.txt",ios::in);
                string nam;
                getline(w1,nam);
                w1.close();
                if(!w1.is_open())
                {
                        fstream w2;
                        w2.open("game/outdoor/football/slot1.txt",ios::out);
                        w2<<"admin";
                        w2.close();
                        cout<<"Reserved !"<<endl;
                }
                else
                {
                      cout<<nam<<" already booked this slot1"<<endl;  
                }

            }
            else if(cc=='2')
            {
                fstream w1;
                w1.open("game/outdoor/football/slot2.txt",ios::in);
                string nam;
                getline(w1,nam);
                w1.close();
                if(!w1.is_open())
                {
                        fstream w2;
                        w2.open("game/outdoor/football/slot2.txt",ios::out);
                        w2<<"admin";
                        w2.close();
                        cout<<"Reserved !"<<endl;
                }
                else
                {
                    cout<<nam<<" already booked this slot2"<<endl;
                }
            }
            else {cout<<"Invalid choice"<<endl;}
        }
        else{cout<<"Invalid choice"<<endl;}


    }
    else {cout<<"Invalid choice"<<endl;}
}
string encryption(string x)
{
    string str=x;
    string en;    
    int len,j=12;
    len=str.length();
    for(int i=0;i<len;i++)
    {
        str[i]=str[i]+j;
    }
    return str;
}
string decryption(string x)
{
    string str=x;
    string en;    
    int len,j=12;
    len=str.length();
    for(int i=0;i<len;i++)
    {
        str[i]=str[i]-j;
    }
    return str;
}



char maintenance()
{
    char m,ret;

    char c=219;
    string ch[50];
    
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<i;j++)
        {
            ch[i]=ch[i]+c;
        }
    }
    

    

    for(int i=0;i<50;i++)
    {
        cout<<"\nSorry we are currently in maintenance,Try again later"<<endl;
        cout<<"\nOnly admin are allowed now\n"<<endl;
        cout<<"Server under maintenance ";
        cout<<ch[i]<<" ";
        Sleep(.01);
        system("cls");
    

        if(i==49)
        {
            for(int i=50;i>0;i--)
            {
                cout<<"\nSorry we are currently in maintenance,Try again later"<<endl;
                cout<<"\nOnly admin are allowed now\n"<<endl;
                cout<<"Server under maintenance ";
                cout<<ch[i]<<" ";
                Sleep(.01);
                system("cls");
                
                
            }
        }
    
    }
    cout<<"\nSorry we are currently in maintenance,Try again later"<<endl;
    cout<<"\nOnly admin are allowed now\n"<<endl;
    cout<<"press p for admin panel"<<endl;
    m=getch();
    if(m=='p')
    {
       ret='1';
    }
    else if(m!='p')
    {
        ret='0';
    }
    return ret;
}



string passHide(string xx,string yy)
{
    string user=xx;
    int i=0;
    int k=0;
    char ch[50];
    char c[50];
    string star="*";

    string str[50];
    str[i]="*";
    for(int i=0;i<50;i++)
    {
        for(int j=0;j<i;j++)
        {
            str[i]=str[i]+star;
        }
    }
     str[0]="\0"; 
a:  
    do
    {
        c[i]=getch();
        system("cls");
        line(12);cout<<yy;line(12);cout<<endl;
        cout<<"Enter username: "<<user<<endl;
        cout<<"Enter Password: ";
        if(c[i]!=13&&c[i]!=8)
        {
            k++;
            cout<<str[k];
            ch[i]=c[i];
            
            i++;



        }
        else if(c[i]==8)
        {
            ch[i-1]='\0';
           
            if(i==0)
            {
                goto a;
            }
            k--;
            i--;
            cout<<str[k];


        }
        else if(c[i]==13)
        {
            break;
        }
            
    }while(true);

    system("cls");
    return ch;
}
string input()
{
    string str;
    getline(cin,str);
    return str;
}

   
void studentInfo(string x)
{
    string name=x;
    string  fname,dob,blood,mobile,department;
    cout<<"Enter full name: ";cin.ignore();getline(cin,fname);
    cout<<"Date of birth  : ";cin>>dob;
    cout<<"Blood group    : ";cin>>blood;
    cout<<"Mobile number  : ";cin>>mobile;
    cout<<"Department     : ";cin>>department;
    fstream add;
    Sleep(1000);
    add.open("log/"+name+".txt",ios::app);
    add<<fname<<endl;
    add<<dob<<"\t"<<blood<<"\t"<<mobile<<"\t"<<department;
    add.close();

}


void readStudentInfo()
{
    string name,fname,dob,blood,mobile,junk,department;
    cout<<"Enter student username: ";cin>>name;
    fstream read;
    read.open("log/"+name+".txt",ios::in);
    if(read.is_open())
    {

        getline(read,name);
        getline(read,junk);
        getline(read,fname);
        read>>dob;
        read>>blood;
        read>>mobile;
        read>>department;
        cout<<"User name    : "<<name<<endl;
        cout<<"Full name    : "<<fname<<endl;
        cout<<"Date of birth: "<<dob<<endl;
        cout<<"Blood group  : "<<blood<<endl;
        cout<<"Mobile number: "<<mobile<<endl;
        cout<<"Department   : "<<department<<endl;
        read.close();

    }
    else
    {cout<<"No account with this username"<<endl;}

    getch();
    system("cls");
}


void changePass()
{
    string olduser,oldpass;
    fstream read;
    read.open("admin/adlog.txt",ios::in);
    getline(read,olduser);
    getline(read,oldpass);
    read.close();
    string newuser,newpass,user,pass,conpass;
    cout<<"Enter old username : ";cin>>user;
    cout<<"Enter old password : ";cin>>pass;
    oldpass=decryption(oldpass);
    if(user==olduser&&pass==oldpass)
    {
        cout<<"Enter new username : ";cin>>newuser;
        cout<<"Enter new password : ";cin>>newpass;
        cout<<"Confirm password   : ";cin>>conpass;
        if(newpass==conpass)
        {
            fstream write;
            write.open("admin/adlog.txt",ios::out);
            write<<newuser<<endl;
            newpass=encryption(newpass);
            write<<newpass;
            cout<<"Password has been changed"<<endl;
            write.close();

        }
        else
        cout<<"Both password are not matching"<<endl;

    }
    
}

string adminUser()
{
    fstream read1;
    string usr;
    read1.open("admin/adlog.txt",ios::in);
    getline(read1,usr);
    read1.close();
    return usr;
}
string adminPass()
{
    fstream read1;
    string psd,jnk;
    read1.open("admin/adlog.txt",ios::in);
    getline(read1,jnk);
    getline(read1,psd);
    read1.close();
    return psd;
}