#include<iostream>
#include<math.h>
#include<cstring>
#include<stdlib.h>
#include<drawille.hpp>
using namespace std;

//menu driven calculator
int numDigits(int num)
{
	if(num==0) return 0;
	else
	{
		int d=0,temp=3;
		while(temp!=0)
		{
			temp=num%10;
			num=num/10;
			d++;
		}
		return (d-1);
	}
}
int chkArm(int num)
{
	int i,p=numDigits(num),num2=num,temp,tsum=0;
	for(i=p;i>0;--i)
	{
		temp=num%10;
		num=num/10;
		tsum+=pow(temp,p);
	}
	if(tsum==num2) return 1;
	else return 0;
}
void divLemma(int D,int d)
{
	cout<<D<<" = "<<d<<" x "<<D/d<<" + "<<D%d<<endl;
}
int menu()
{
	int n;
	cout<<"Enter the number corresponding to the desired operation:"<<endl;
	cout<<"1 for addition"<<endl<<"2 for subtraction"<<endl<<"3 for multiplication"<<endl<<"4 for division"<<endl<<"5 for raising a number to a certain power"<<endl<<"6 to print a number's division lemma"<<endl<<"7 to check for an armstrong number"<<endl<<"8 to compare two strings"<<endl<<"9 to exit"<<endl<<endl;
	cin>>n;
	if(n==0||n>9)
	{
		cout<<"Please enter a valid number"<<endl<<endl;
		menu();
	}
	else if(n==9)exit(0);
	else return n;	
}
void values(int m)
{
	int n1,n2,n,p;
	char a[455],b[455];
	switch(m)
	{
		case 1 : cout<<"Enter two numbers"<<endl;
			 cin>>n1>>n2;
			 cout<<"Sum is "<<n1+n2<<endl;
			 break;
		
		case 2 : cout<<"Enter two numbers in correct order"<<endl;
			 cin>>n1>>n2;
			 cout<<"Difference is "<<n1-n2<<endl;
			 break;
		
		case 3 : cout<<"Enter two numbers"<<endl;
			 cin>>n1>>n2;
			 cout<<"Product is "<<n1*n2<<endl;
			 break;
		
		case 4 : cout<<"Enter two numbers in correct order"<<endl;
			 cin>>n1>>n2;
			 cout<<"Quotient is "<<n1/n2<<" (For division lemma, use point 6)"<<endl;
 			 break;
		
		case 5 : cout<<"Enter the number and desired power"<<endl;
			 cin>>n>>p;
			 cout<<"Answer is "<<pow(n,p)<<endl;
			 break;
		case 6 : cout<<"Enter dividend and divisor"<<endl;
			 cin>>n1>>n2;
			 divLemma(n1,n2);
			 break;
		case 7 : cout<<"Enter the number"<<endl;
			 cin>>n;
			 if(chkArm(n)) cout<<"It is an armstrong number"<<endl;
			 else cout<<"It is not an armstrong number"<<endl;
			 break;
		case 8 : cout<<"Enter first string"<<endl;
			 cin>>a;
			 cout<<"Enter second string"<<endl;
			 cin>>b;
			 if(!strcmp(a,b)) cout<<"They are equal"<<endl;
			 else cout<<"They are unequal"<<endl;
			 break;	
	}		
}
void funInt()                      //accepts a polynomial function as a string and breaks it up in its components to find its value at a particular x
{
    string fun, *f=&fun;
    float x,a[17];
    int p;
    cout<<"Enter the monovariable polynomial function with the degree of x (even of x\u00B9, but not in constant term) just after x and all coefficients with their sign (eg, write x\u00B2 as +1x2) "<<endl;
    cin>>fun;
    for(int i=0;i<fun.size();i++)
    {
        if(fun.at(i)=='+')//||(fun.at(i-1)!=x&&fun.at(i+1)>=0&&fun.at(i+1)<10))                       //TRY TO REMOVE THIS CONDITION.... AND UNCOMMENT THE EXTRA LINE OF CODE
            a[0]=1.2;
        if(fun.at(i)=='-')
            a[0]=-1.2;                                                                                //stores signs as + or -1.2.
        int j=1;
        while(fun.at(i+j)!='x'&&i+j<fun.size())
        {
            fun.at(i+j)=='.'?a[j]=1.1:a[j]=fun.at(i+j)-'0';            //to store decimal in case of decimal values, a[] stores 1.1 to denote decimal point
            cout<<a[j]<<endl;
            j++;
        }
        cout<<a[0]<<endl;
        i=i+j-1;
    }
}
void check()
{
	char x;
	int m;
	cout<<"Do you want to calculate again ? [y/n] : ";
	cin>>x;
	cout<<endl;
	if(x=='n') exit(0);
	else if(x=='y')
	{
		m=menu();
		values(m);
		check();	
	}
	else 
	{
		cout<<"enter a valid response "<<endl;
		check();
	}
}
int main()
{
	//int m=menu();
    //values(m);
	//check();
    funInt();
	return 0;
}
