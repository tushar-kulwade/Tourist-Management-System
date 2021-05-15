#include<cstdlib>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
class busbook
{

    public:
        float km,rs;
        string pay,pmt;
        string file;
    string name,source,dest,date,time,phone,email,pass,user,on;
        busbook()
        {
            cout<<"                               Tourist Management System "<<endl;
            cout<<endl;

        }
        void login()
        {
            cout<<"Enter Your Name : ";
            getline(cin,name);

            cout<<"Enter Your Phone number : ";
            getline(cin,phone);

            cout<<"Enter Your Email Address : ";
            getline(cin,email);
            cout<<"Set Your Password : ";
            getline(cin,pass);
            fstream a;

            a.open("Username.txt",ios::app);

                a<<name<<"\n";
                a.close();


            a.open("Password.txt",ios::app);

                a<<pass<<"\n";
                a.close();

            getinfo();
            bus();
            paym();
            display();


        }
        void login2(void)
        {
            cout<<"Enter Your name : ";
            getline(cin,name);
            cout<<"Enter Your Password : ";
            getline(cin,pass);

            check();
        }
        void check()
        {
                        ifstream fin;
                fin.open("Username.txt");
                if(fin.fail())
                {
                    cout << "Input file opening failed.\n";
                    exit(1);
                }
                string search;

                search=name;
                bool isFound=0;
                while(!fin.eof())
                {
                    string temp = "";
                    getline(fin,temp);
                    for(int i=0;i<search.size();i++)
                    {
                        if(temp[i]==search[i])
                        isFound = 1;
                        else
                        {
                            isFound =0;
                            break;
                        }
                    }

                    if(isFound)
                    {
                        checkpass();
			//for(int i = search.size()+1;i<temp.size();i++)
				//cout << temp[i];

                    break;
                    }
                    else
                    {

                    }

                }

                if(fin.eof()&&!isFound)
                {
                    cout << "Username not found!\n";
                }

                fin.close();

        }
        void checkpass()
        {
                    ifstream fins;
                    fins.open("Password.txt");
                    if(fins.fail())
                    {
                            cout << "Input file opening failed.\n";
                            exit(1);
                    }
                    string search;
                    search=pass;
                    bool isFound=0;
                    while(!fins.eof())
                    {
                        string temp = "";
                        getline(fins,temp);
                        for(int i=0;i<search.size();i++)
                        {
                            if(temp[i]==search[i])
                            isFound = 1;
                            else
                            {
                                isFound =0;
                                break;
                            }
                        }

                        if(isFound)
                        {
                            getinfo();
                            bus();
                            paym();
                            display();
                            break;
                        }
                        else
                        {

                        }

                    }

                    if(fins.eof()&&!isFound)
                    {
                        cout << "Password not Matched!\n";
                    }

                    fins.close();
        }
        void loginmn()
        {
            cout<<"Are you new user or old user : ";
            getline(cin,on);
            cout<<endl;

            if(on=="new")
            {
                login();
            }
            if(on=="old")
            {
                login2();
            }
        }
        void getinfo(void)
        {
            cout<<endl;
            cout<<endl;
            cout<<"You are Logged in Successfully ."<<endl<<endl;
            cout<<"Enter source city : ";
            getline(cin,source);
            cout<<"Enter Destination city : ";
            getline(cin,dest);
            cout<<"Enter Date for your ride(in dd/mm/yyyy format) : ";
            cin>>date;
           // cout<<"Enter the Time for your ride(in hh:mm 24hrs format) : ";
           // cin>>time;
            cout<<"Enter The Distance in kilometers : "<<endl;
            cout<<"(You can calculate/measure distance from (maps.google.com) this link.) "<<endl;
            cin>>km;
        }
        void bus()
        {
           cout<<"Choose bus for your journey(Enter options given below) :";
           cout<<"a)Sangitam\n b)Sai Ram \n c)Novelty \n d)Purple \n e)Ni3 \n";
           cin>>pmt;
           if(pmt =="a")
           {
              cout<<" Your seat is booked in Sangitam."<<endl;
           }
           else if(pmt =="b")
           {
              cout<<" Your seat is booked in Sai Ram."<<endl;
           }
           else if(pmt =="c")
           {
              cout<<" Your seat is booked in Novelty."<<endl;
           }
           else if(pmt=="d")
           {
            cout<<" Your seat is booked in Purple. "<<endl;
           }
           else
           {
           cout<<"Your seat is booked in Ni3."<<endl;
           }

        }
        void paym()
        {
           cout<<"Choose Payment method(Enter options given below) :";
           cout<<"a)Paytm\n b)Google Pay \n c)PhonePay \n d)Credit or Debit card \n e)Cash \n";
           cin>>pay;
           if(pay=="a" || pay=="b" || pay=="c")
           {
              cout<<"QR code and Link is send to your Gmail pay using this link. "<<endl;
           }
           else if(pay=="d")
           {
            cout<<"Link is send to your Gmail fill appropriate card details and pay. "<<endl;
           }
           else
           {
           cout<<"Pay the cash to the Driver ."<<endl;
           }

        }


        void display (void)
        {

            cout<<"_____________________________"<<endl;
            cout<<"Recipt :- "<<endl;
            cout<<endl;
            cout<<"Name : "<<name<<endl;
            cout<<"Phone no. : "<<phone<<endl;
            cout<<"Source city : "<<source<<endl;
            cout<<"Destination city : "<<dest<<endl;
            cout<<"Date for your journey : "<<date<<endl;
            cout<<"Distance (in kM) : "<<km<<endl;
            rs = km*7;
            cout<<"Your booked bus : "<<pmt<<endl;
            cout<<"Payment Method : "<<pay<<endl;
            cout<<"Your fair is Rs. "<<rs<<endl;
            cout<<endl;
            cout<<"Your bus is booked on given date."<<endl;
            cout<<endl;
            cout<<"                             Thank You For Using Our APP."<<endl;
            cout<<"                                       Visit Again."<<endl;
            fstream disp;


            file=name+".txt";
            disp.open(file , ios::app);
            disp<<"Recipt :- "<<endl;
            disp<<endl;
            disp<<"Name : "<<name<<endl;
            disp<<"Phone no. : "<<phone<<endl;
            disp<<"Source city : "<<source<<endl;
            disp<<"Destination City : "<<dest<<endl;
            disp<<"Date for your journey : "<<date<<endl;
            disp<<"Distance (in kM) : "<<km<<endl;
            disp<<"Your booked bus : "<<pmt<<endl;
            disp<<"Payment method : "<<pay<<endl;
            disp<<"Your fair is Rs. "<<rs<<endl;
            disp<<endl;
            disp<<"Your bus is booked on given date."<<endl;
            disp<<endl;
            disp<<"                             Thank You For Using Our APP."<<endl;
            disp<<"                                       Visit Again."<<endl;
            disp<<"_____________________________"<<endl;

            disp.close();
        }

};
int main()
{
   busbook b;
   b.loginmn();
   getch();
   return(0);

}
