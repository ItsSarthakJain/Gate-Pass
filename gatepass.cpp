#include<fstream>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<map>
#include<time.h>    ///using time library
#include<tuple>
#include<conio.h>
#include<bits/stdc++.h>  ///use of standard template libraries
#include<windows.h>   ///windows library used
using namespace std;

COORD coord={0,0};

class Login
 {
  string uname;
  string passw;
  public:
  void signIn()
  {
    cout<<"Enter username:\n";
    cin.ignore();
    getline(cin,uname);
    cout<<"Enter the password\n";
    cin.ignore();
    getline(cin,passw);
    ofstream pass;
    pass.open("password.txt",ios::in|ios::out|ios::app);
    pass<<uname<<"\t\t"<<passw<<endl;
  }
  int Logg()
  {
    fstream pass;
    pass.open("password.txt",ios::in|ios::out|ios::app);
    string un,ps;
    cout<<"Enter username:\n";
    cin.ignore();
    getline(cin,un);
    cout<<"Enter the password\n";
    cin.ignore();
    getline(cin,ps);
    string line;
    while(!pass.eof())
    {
      getline(pass,line);
      if(line.find(un) != std::string::npos)
        if(line.find(ps) != std::string::npos)
           return 1;
    }
    return 0;
  }
 }STUDENT;

class MAIN
  {
  public:
  inline void dept();
  };
                                   //-----------------------------------------------------------------|
class ADMIN:public MAIN
  {
  public:
    inline void dept();
  }ad1;          //|                                                                |
class STU:public MAIN
  {
  public:
    inline void dept();
  }st1;           //|                INHERITANCE USED WIITH METHOD OVERRIDING        |
class WAR:public MAIN
  {
  public:
    inline void dept();
  }war1;          //|                    polymorphisim USED                          |
class SECU:public MAIN
  {
  public:
    inline void dept();
  }sec1;        //|                                                                |
                              //---------------------------------------------------------------- -|

void gotoxy(int x,int y)  /////---------gotoxy function used
 {
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
 }

void centerstring(string s)
 {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD NewSBSize;
	NewSBSize = GetLargestConsoleWindowSize(hOut);
	int l=s.length();
	int pos=(int)((NewSBSize.X-l)/2);
	for(int i=0;i<pos;i++)
	cout<<" ";
	cout<<s;
 }

inline void main_menu()
  {
  char ch;
  do
   {
     system("cls");
     cout<<endl<<endl;
   centerstring("GATE PASS MENU");
   cout<<"\n\n\t01. ADMINISTRATOR\n";
   cout<<"\n\n\t02. SECURITY GUARD\n";
   cout<<"\n\n\t03. WARDEN\n";
   cout<<"\n\n\t04. STUDENT\n";
   cout<<"\n\n\t05. EXIT\n";
   cout<<"\n\n\tPlease Select Your Option (1-5) :\n";
   gotoxy(33,11);
   cin>>ch;
   try
   {
   switch(ch)
   {
    case '1':
         ad1.dept();
         break;
     case '2':
         sec1.dept();
         break;
     case '3':
         war1.dept();
         break;
     case '4':
         STU *p;
         p=&st1;
         p->dept();
         break;
     case '5':
        system("cls");
         cout<<"\n\n\t\t\t\t\tTHANKS FOR USING GATE PASS PORTAL made by :: \n\n\t\t\t\t\t\t\tsarthak jain \n\n\t\t\t\t\t\t\t\n\n\n\n";
         gotoxy(33,11);
         exit(0);
         break;
     default:
         throw("\n\n\tEnter correct choise\n");
    }
  }
  catch(const char* ch)
  {
    system("cls");
    cout<<ch;
    main_menu();
  }
   }while(ch!='|');
 }
//done
inline char* time()
 {
  time_t now = time(0);
  char* dt = ctime(&now);
  return dt;
 }

inline void in()
 {
   system("cls");
   centerstring("GATEPASS IN");
   ifstream fin;
   fin.open("out.txt",ios::in|ios::app);
 int choise,check;
 string id,gt_no;
 cout<<"\n\n\tENTER 0 to exit to main\n";
 cout<<"\n\n\t1. GT-NUMBER\n";
 cout<<"\n\n\t2. ID-NUMBER\n";
 cin>>check;
 if(check==0)
 {
   system("cls");
   atexit(main_menu);
   exit(0);
 }
 try
 {
   if(check!=1&&check!=2)
   throw("\n\n\tPLEASE CHOOSE FROM THE TWO OPTIONS\n");
   int flag=0;
 if(check==1)
  {
    cout<<"\n\n\tENTER THE GT-NUMBER\n";
    cin>>gt_no;
    if(stoi(gt_no)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(gt_no.length()!=6)
    throw("\n\n\tINVALID GT-NUMBER\n");                   ///////CHECK FOR GT NUMBER EXCEPTION HANDELLED
    string line;
    ofstream temp;
    temp.open("temp.txt");
    while (!fin.eof())
    {
      fin>>line;
      if (line.find(gt_no) != std::string::npos)
      cout<<"\n\n\tSTUDENT SUCESSFULLY ENTERED\n";
      else
      temp<<line<<endl;
    }
    temp.close();
    fin.close();
    remove("out.txt");
    rename("temp.txt","out.txt");
  }
 else if(check==2)
  {
    cout<<"\n\n\tENTER THE ID-NUMBER\n";
    cin>>id;
    if(stoi(id)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(id.length()!=10)
    throw("\n\n\tINVALID ID\n");                   ///////CHECK FOR GT NUMBER EXCEPTION HANDELLED
    string line;
    ofstream temp;
    temp.open("temp.txt");
    while (!fin.eof())
    {
      getline(fin,line);
      if (line.find(id) != std::string::npos)
        cout<<"\n\n\tSTUDENT SUCESSFULLY ENTERED\n";
      else
      temp<<line<<endl;
    }
    temp.close();
    fin.close();
    remove("out.txt");
    rename("temp.txt","out.txt");
  }
 }
 catch(const char* ch)
 {
   cout<<ch;
    in();////////////////////////////////-----------------recurrsion used
  }
}
//done
inline void out()
 {
   system("cls");
   centerstring("GATEPASS OUT");
 ofstream oout;
 oout.open("out.txt",ios::in|ios::out|ios::app);
 ifstream ain;
 ain.open("approval.txt",ios::in|ios::out|ios::app);
 int check,choise,i,flag=0;
 string id,gt_no;
 cout<<"\n\n\tENTER 0 to exit to main\n";
 cout<<"\n\n\t1. GT-NUMBER\n";
 cout<<"\n\n\t2. ID-NUMBER\n";
 cin>>check;
 if(check==0)
 {
   system("cls");
   atexit(main_menu);
   exit(0);
 }
 try
 {
   if(check!=1&&check!=2)
   throw("\n\n\tPLEASE CHOOSE FROM THE TWO OPTIONS\n");
 if(check==1)
  {
    cout<<"\n\n\tENTER THE GT-NUMBER\n";
    cin>>gt_no;
    if(stoi(gt_no)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(gt_no.length()!=6)
    throw("\n\n\tINVALID GT-NUMBER\n");                   ///////CHECK FOR GT NUMBER EXCEPTION HANDELLED
    string line;
    ofstream temp;
    temp.open("temp.txt",ios::out);
    while (!ain.eof())
    {
      getline(ain,line);
      if (line.find(gt_no) != std::string::npos)
      {
        id=line.substr(0,10);
        flag=1;
      }
      else
        temp<<line<<endl;
    }
    char* ch=time();
    if(flag==1)
    {
    auto out=make_tuple(id,gt_no,ch);
    oout<<get<0>(out)<<"\t\t"<<get<1>(out)<<"\t\t"<<get<2>(out)<<endl;
    }
    ain.close();
    temp.close();
    oout.close();
    remove("approval.txt");
    rename("temp.txt","approval.txt");
  }
 else if(check==2)
  {
    cout<<"\n\n\tENTER THE ID-NUMBER\n";
    cin>>id;
    if(stoi(id)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(id.length()!=10)
    throw("\n\n\tINVALID ID\n");                          ///////////throw EXCEPTION WHEN INVALID ID---------
    string line;
    ofstream temp;
    temp.open("temp.txt",ios::out);
    while (!ain.eof())
    {
      getline(ain,line);
      if (line.find(id) != std::string::npos)
      {
        gt_no=line.substr(12,18);
        flag=1;
      }
      else
        temp<<line<<endl;
    }
    char* ch=time();
    if(flag==1)
    {
    auto out=make_tuple(id,gt_no,ch);
    oout<<get<0>(out)<<"\t\t"<<get<1>(out)<<"\t\t"<<get<2>(out)<<endl;
    }
    ain.close();
    temp.close();
    oout.close();
    remove("approval.txt");
    rename("temp.txt","approval.txt");
  }
 }
  catch(const char *ch)          ////////////////////--------------exception HANDLing -------------
  {
    system("cls");
    cout<<ch<<"Enter '0' to go to main menu\n";
    atexit(out);
    exit(0);                ////////////---------use of recurrsion-------------------------
  }
    if(flag==1)
    cout<<"\n\n\tOUT SUCESSFULL\n\n";
    else
    {
    cout<<"\n\n\tGATE PASS NOT APPROVED BY WARDEN\n\n";
    atexit (main_menu);
    exit(0);    ///////////////////////---------------------atexit used for callinf function when exit
    }
 }//done//done//done
//done
inline int check_out()
 {
   system("cls");
   centerstring("CHECK WHETHER STUDENT IS IN UNIVERSITY");
 ifstream oin;
 oin.open("out.txt",ios::in|ios::app);
 int check,choise,i=0;
 string gt_no,id,line;
 cout<<"\n\n\tENTER 0 to exit to main\n";
 cout<<"\n\n\t1. GT-NUMBER\n";
 cout<<"\n\n\t2. ID-NUMBER\n";
 cin>>check;
 if(check==0)
 {
   system("cls");
   atexit(main_menu);
   exit(0);
 }
 try
 {
   if(check!=1&&check!=2)
   throw("\n\n\tPLEASE CHOOSE FROM THE TWO OPTIONS\n");
   if(check==0)
   {
     system("cls");
     atexit(main_menu);
     exit(0);
   }
  if(check==1)
  {
    cout<<"\n\n\tENTER THE GT-NUMBER\n";
    cin>>gt_no;
    if(stoi(gt_no)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(gt_no.length()!=6)
   throw("\n\n\tINVALID GT-NUMBER\n");                   ///////CHECK FOR GT NUMBER EXCEPTION HANDELLED    string line;
    while (!oin.eof())
    {
      getline(oin, line);
      if(line.find(gt_no)!= std::string::npos)
      return 1;
    }
  }
 else if(check==2)
  {
    cout<<"\n\n\tENTER THE ID-NUMBER:";
    cin>>id;
    if(stoi(id)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(id.length()!=10)
    throw("\n\n\tINVALID ID\n");                   ///////CHECK FOR GT NUMBER EXCEPTION HANDELLED
    string line,str;
    while (!oin.eof())
    {
      getline(oin, line);
      if(line.find(id)!= string::npos)
      return 1;
    }
  }
 }
 catch(const char* ch)
 {
   cout<<ch;
   cout<<"\n\n\tEnter 0 to go to main menu\n";
   atexit(out);
   exit(0);                  ////recurrsion used-----------------------------
 }

}
//done
void req()
 {
   system("cls");
   centerstring("REQUEST GATEPASS");
  string id;
  cout<<"\n\n\tENTER 0 to exit to main menu\n";
  cout<<"\n\n\tENTER THE STUDENT ID:";
  ofstream rout;
  rout.open("request.txt",ios::out|ios::app);
  cin>>id;
  if(stoi(id)==0)
  {
    system("cls");
    atexit(main_menu);
    exit(0);
  }
  try
  {
  if(id.length()!=10)
  throw("\n\n\tINVALID ID\n");
  rout<<id<<endl;
  rout.close();
  cout<<"\n\n\tGATE PASS REQUEST SUBMITTED SUCESSFULLY\n\n";
  }
  catch(const char* ch)
  {
    system("cls");
    cout<<ch;
    getch();
    atexit(req);
    exit(0);
  }
}
//done
void approve_gt()
 {
   system("cls");
   centerstring(" APPROVE GATEPASS");
 long int r;
 map <string,string>gt;
 map <string,string>::iterator itr;
 fstream aout;
 aout.open("approval.txt",ios::out|ios::app|ios::in);
 fstream rin;
 rin.open("request.txt",ios::in|ios::out|ios::app);
 int check,choise,i,flag=0;
 string id;
 cout<<"\n\n\tENTER 0 to exit to main\n";
 try
  {
 cout<<"\n\n\tENTER THE ID-NUMBER:";
 cin>>id;
 if(stoi(id)==0)
 {
   system("cls");
   atexit(main_menu);
   exit(0);
 }
 if(id.length()!=10)
 throw("\n\n\tINVALID ID");
 string line;
 ofstream tmp;
 tmp.open("temp.txt");
 while (!rin.eof())
 {
  rin>>line;
  if (line.find(id) != std::string::npos)
    flag=1;
  else
  {
    tmp<<line<<endl;
  }
 }
 rin.close();
 tmp.close();
 remove("request.txt");
 rename("temp.txt","request.txt");
 srand(time(0));
 if(flag==1)
 {
   r=(rand() %999999 + 111111);
 cout<<"\n\n\tGATE PASS REQUEST APPROVED SUCESSFULL\n";
 cout<<"\n\n\tGT NO::"<<r;
 string gt_no = to_string(r);
 gt.insert(pair<string,string> (id,gt_no));
 itr=gt.begin();
 aout<<(*itr).first<<"\t\t"<<(*itr).second<<endl;
  getch();
 }
 else if(flag==0){
 throw("\n\n\tNO MATCHING GATE PASS REQUEST FOR THAT ID FOUND\n");
 getch();}
 }
 catch(const char * ch)
  {
  system("cls");
  cout<<ch;
  approve_gt();
  }
}
//done
void out_on_day()
 {
   system("cls");
   centerstring("CHECK GATEPASS OUT ENTRIES");
  ifstream oin;
  int count=0;
  oin.open("out.txt",ios::in|ios::out|ios::app);
  cout<<"\n\n\tENTER 0 to exit to main\n";
  cout<<"\n\n\tEnter date for which you want to check entries (Apr 17) \n\n";
  string date,line;
  cin.ignore();
  getline(cin,date);
  auto d=date;
  if(date[0]=='0')
  {
    system("cls");
    atexit(main_menu);
    exit(0);
  }                                                         ////------auto keyword used-------
  transform(d.begin(), d.end(), d.begin(), ::tolower);              ////----------non-member begin() and end()-----
  while(!oin.eof())
  {
    getline(oin,line);
    transform(line.begin(), line.end(), line.begin(), ::tolower);
    if (line.find(d) != std::string::npos)
    {
      cout<<line<<endl;
      count++;
    }
  }
  if(count==0)
  cout<<"\n\n\tSorry no entries found for that day\n\n";
  else
  cout<<"\n\n\t"<<count<<" Entries found for that day\n\n";
}

int check_gt()
  {
    system("cls");
    centerstring("CHECK GATEPASS STATUS");
    string id;
    ifstream gin;
    cout<<"\n\n\tEnter the Student Id\n";
    cout<<"\n\n\tENTER 0 to exit to main\n";
    try
    {
    cin.ignore();
    getline(cin,id);
    if(stoi(id)==0)
    {
      system("cls");
      atexit(main_menu);
      exit(0);
    }
    if(id.length()!=10)
    throw("\n\n\tINVALID ID\n");
      gin.open("approval.txt",ios::in);
      string line;
    while(!gin.eof())
    {
      getline(gin,line);
      if(line.find(id)!= std::string::npos)
      return 1;
    }
    }
    catch(const char * ch)
    {
      cout<<ch;
      return(check_gt());
    }
    return 0;
  }
//done
void ADMIN::dept()
 {
  system("cls");
  cout<<endl<<endl;
  centerstring("ADMINISTRATOR");
  string pass ="";
   char cha;
   cout << "\n\n\tEnter password\n";
   cha = _getch();
   while(cha != 13)
   {
      pass.push_back(cha);
      cout << '*';
      cha = _getch();
   }
   if(!(pass == "PROJECT"))
   {
      cout << "\n\n\tAccess aborted...\n";
      getch();
      system("cls");
      atexit(main_menu);
      exit(0);
   }
   else
   {
     cout<<"\n\n\tACCESS GRANTED\n";
     getch();
     system("cls");
     cout<<endl<<endl;
     centerstring("ADMINISTRATOR");
   }
  cout<<"\n\n\t1. GATE PASS (IN) \n\n";
  cout<<"\n\n\t2. GATE PASS (OUT) \n\n";
  cout<<"\n\n\t3. CHECK STUDENT IS OUTSIDE OR NOT \n\n";
  cout<<"\n\n\t4. CHECK FOR STUDENTS WHO WENT OUT ON PERTICULAR DAY \n\n";
  cout<<"\n\n\t5. DELETE ALL STORED DATA ON PORTAL\n\n";
  cout<<"\n\n\t6. BACK....\n\n\n";
  do
  {
  int c,choise;
  cin>>choise;
  char a;
  switch(choise)
    {
    case 1:
      in();
      getch();
      system("cls");
      atexit(main_menu);
      exit(0);
      break;
    case 2:
      out();
      getch();
      system("cls");
      atexit(main_menu);
      exit(0);
      break;
    case 3:
      c=check_out();
      if(c==0)
      {
      cout<<"\n\n\tTHE STUDENT IS IN THE UNIVERSITY CAMPUS:: \n";
      getch();
      system("cls");
      atexit(main_menu);
      exit(0);
      }
      else
      {
      cout<<"\n\n\tTHE STUDENT IS OUT OF THE UNIVERSITY CAMPUS:: "<<endl;
      getch();
      system("cls");
      atexit(main_menu);
      exit(0);
      }
      break;
    case 4:
      out_on_day();
      getch();
      system("cls");
      atexit(main_menu);
      exit(0);
      break;
    case 5:
    system("cls");
     centerstring("DELETE DATA OF PORTAL");
     cout<<"\n\n\tARE YOU SURE ALL THE STORED DATA WOULD BE ERASED\n\n";
     cin>>a;
    if(a=='y')
    {
    remove("approval.txt");
    remove("out.txt");
    remove("request.txt");
    cout<<"\n\n\tALL FILES REMOVED";
    getch();
    system("cls");
    atexit(main_menu);
    exit(0);}
    else
    {
    cout<<"\n\n\tNO FILES REMOVED";
    getch();
    system("cls");
    atexit(main_menu);
    exit(0);
   } break;
    case 6:
        system("cls");
        main_menu();
        break;
    default:
      cout<<"\n\n\tENTER FROM THE ABOVE CHOISES\n";
      cin>>choise;
      break;
    }
 }while(1);
}

void STU::dept()
 {
   system("cls");
   cout<<endl<<endl;
  centerstring("STUDENT");
  cout<<"\n\n\t1. Add new Account \n\n";
  cout<<"\n\n\t2. Login \n\n";
  cout<<"\n\n\tPRESS 0 TO GO BACK\n\n";
 do{
  int i;
  cin>>i;
  if(i==1)
  {
  STUDENT.signIn();
  cout<<"\n\n\tNew Account added\n\n";
  getch();
  system("cls");
  atexit(main_menu);
  exit(0);
  }
  else if(i==2)
  {
    int i=STUDENT.Logg();
    if(i!=1)
    {
      system("cls");
      cout<<"\n\n\tInvalid credentials\n\n";
      getch();
      atexit(main_menu);
      exit(0);
    }
    else
    {
      system("cls");
    break;
    }
  }
  else if(i==0)
  main_menu();
 }while(1);
  centerstring("STUDENT");
  cout<<"\n\n\n\n\tAcess Granted \n\n";
  cout<<"\n\n\t1. REQUEST GATE \n\n";
  cout<<"\n\n\t2. CHECK GATE PASS STATUS \n\n";
  cout<<"\n\n\t3. BACK....\n\n\n";
 do
 {
 int c,choise;
 cin>>choise;
 char a;
 switch(choise)
   {
   case 1:
     req();
     getch();
     system("cls");
     atexit(main_menu);
     exit(0);
     break;
   case 2:
     c=check_gt();
    if(c==1)
    {
       cout<<"\n\n\tGATE PASS REQUEST IS APROVED BY WARDEN \n";
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
     }else
     {
       cout<<"\n\n\tGATEPASS REQUEST IS PENDING \n "<<endl;
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
     } break;
    case 3:
    getch();
    system("cls");
    atexit(main_menu);
    exit(0);
           break;
    default:
           cout<<"\n\n\tEnter correct choise\n";
           cin>>choise;
           break;
   }
 }while(1);
}

void SECU::dept()
 {
   system("cls");
   centerstring("SECURITY GUARD");
   cout<<"\n\n\t1. GATE PASS (IN) \n\n";
   cout<<"\n\n\t2. GATE PASS (OUT) \n\n";
   cout<<"\n\n\t3. CHECK STUDENT IS OUTSIDE OR NOT \n\n";
   cout<<"\n\n\t4. CHECK FOR STUDENTS WHO WENT OUT ON PERTICULAR DAY \n\n";
   cout<<"\n\n\t5. BACK....\n\n\n";
   do
   {
   int c,choise;
   cin>>choise;
   char a;
   switch(choise)
     {
     case 1:
       in();
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
       break;
     case 2:
       out();
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
       break;
     case 3:
       c=check_out();
       if(c==0)
       {
       cout<<"\n\n\tTHE STUDENT IS IN THE UNIVERSITY CAMPUS:: \n";
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
       }
       else
       {
       cout<<"\n\n\tTHE STUDENT IS OUT OF THE UNIVERSITY CAMPUS:: "<<endl;
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
      }break;
     case 4:
       out_on_day();
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
       break;
     case 5:
      getch();
        system("cls");
        atexit(main_menu);
        exit(0);
        break;
     default:
       cout<<"\n\n\tENTER FROM THE ABOVE CHOISES\n";
       cin>>choise;
       break;
     }
  }while(1);
 }

void WAR::dept()
 {
   system("cls");
   cout<<endl<<endl;
   centerstring("WARDEN");
   cout<<"\n\n\t1. GATE PASS (IN) \n\n";
   cout<<"\n\n\t2. APPROVE GATEPASS \n\n";
   cout<<"\n\n\t3. CHECK STUDENT IS OUTSIDE OR NOT \n\n";
   cout<<"\n\n\t4. CHECK FOR STUDENTS WHO WENT OUT ON PERTICULAR DAY \n\n";
   cout<<"\n\n\t5. BACK....\n\n\n";
   do
   {
   int c,choise;
   cin>>choise;
   char a;
   switch(choise)
     {
     case 1:
       in();
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
       break;
    case 2:
    approve_gt();
    getch();
    system("cls");
    atexit(main_menu);
    exit(0);
    break;
     case 3:
       c=check_out();
       if(c==0){
       cout<<"\n\n\tTHE STUDENT IS IN THE UNIVERSITY CAMPUS:: \n";
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
      }
       else
       {
       cout<<"\n\n\tTHE STUDENT IS OUT OF THE UNIVERSITY CAMPUS:: "<<endl;
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
      }break;
     case 4:
       out_on_day();
       getch();
       system("cls");
       atexit(main_menu);
       exit(0);
       break;
     case 5:
     getch();
     system("cls");
     atexit(main_menu);
     exit(0);
         break;
     default:
       cout<<"\n\n\tENTER FROM THE ABOVE CHOISES\n";
       cin>>choise;
       break;
     }
  }while(1);
 }

int main()
	{
  centerstring("WELCOME TO THE GATE-PASS PORTAL");
  main_menu();
	return 0;
	}
