#include<iostream>
#include<string.h>
#include <bits/stdc++.h>

using namespace std;
string convertToString(char* a, int size)//convert char array to string
{
    int i;
    string s = "";
    for (i = 0; i < size; i++) {
        s = s + a[i];
    }
    return s;
}
int count(unsigned long long int n)
{
    int c = 0;
    while (n != 0)
    {
        n = n / 10;
        ++c;
    }
    return c;
}
string reverseS(string ordered)//reverses the given string
{
	char *revO=new char[ordered.length()];
	int j=0;
	for(int i=ordered.length();i>0;i--)
	{
		revO[j]=ordered[i-1];
		j++;
	}
	string rev="";
	rev=convertToString(revO,strlen(revO));
	return rev;
}
//mutilply big ints
string multiply(string a,string b)
{
	int sizeA=a.length();
	int sizeB=b.length();
	int LengthF=sizeA+sizeB;
	//make string of size lengthF and initialize it with '0'
	string FinalS(LengthF,'0');
	for(int i=sizeA-1;i>=0;i--)
	{
		int carry=0;
		int aDigit=a[i]-48;
		for(int j=sizeB-1;j>=0;j--)
		{
			int bDigit=b[j]-48;
			int product;
			carry=FinalS[i+j+1]-48;
			product=aDigit*bDigit;	//multiply
			product+=carry;//add carry if any
			FinalS[i+j+1]=product%10+48;//remainder to be stored in Final string
			FinalS[i+j]+=product/10;
			//carry generated for next iteration
			//and stored at the prev index
		}
	}
	for(int i=0;i<LengthF;i++){
      	if(FinalS[i]!='0')
	  	return FinalS.substr(i);
   	}
	return "0";
}
string EulerFtn(string pp,string qq)
{
	
	pp[pp.length()-1]-=1;
	qq[qq.length()-1]-=1;
	return multiply(pp,qq);
	
}
string divide(string ee,string ff)//assume e,f same size
{
	char t[100]="";
	cout<<ee<<"/"<<ff<<endl;
	for(int i=ee.length()-1;i>=0;i--)
	{
		if(ee[i]-48>=ff[i]-48)
		{
			t[i]=((ee[i]-48)-(ff[i]-48))+48;
			//cout<<ee[i]<<";"<<ff[i]<<":"<<t[i]<<"/";
		}
		else
		{
			int r=ee[i-1]-48;
			r=r-1;
			ee[i-1]=r+48;
			int q=ee[i]-48;
			q=q+10;
			ee[i]=q+48;
			t[i]=((ee[i]-48)-(ff[i]-48))+48;
			//cout<<t[i]<<"|";
		}
	}
	string tv= convertToString(t,strlen(t));
	cout<<"\nj"<<tv<<endl;
	return tv;
}
void modulo(string e,string f)//e/f
{
	if(e.length()==f.length())
	{
		for(int i=0;i<e.length();i++)
		{
			cout<<e[i]-48<<" | "<<f[i]-48<<endl;
			if((e[i]-48)<(f[i]-48))
			{
				cout<<"f es grande"<<i<<endl;
				cout<<"modulo is"<<e<<endl;
				break;
			}
			else if((e[i]-48)>(f[i]-48))
			{
				cout<<"e es grande"<<i<<endl;
				cout<<"we gotta test modulo waitoo"<<endl;
				cout<<"modulo for same size"<<divide(e,f)<<endl; 
				break;
			}
			else
			{
				cout<<"yok"<<endl;
			}
			
		}
	}
	else if(e.length()>f.length())
	{
		int k=0;
		for(int i=0;i<f.length();i++) 
		{
			unsigned long long int size_d=e.length()-f.length();
			if(size_d==0)
			{
				if(e[i]>f[i])
				{
					cout<<"modulo for same size"<<divide(e,f)<<endl; 
					break;
				}
			}
			else
			{
				
				unsigned long long int num=stoi(f);
				int x=count(num);
				cout<<x<<"|"<<e.length()<<endl;
				unsigned long long int j=2;
				while(x<e.length())
				{
					
					num=num*j;
					x=count(num);
					j+=1;
					cout<<j<<" | ";//endl;
				}
				cout<<num<<endl;
				string str=to_string(num);
				string d;
				for(int i=0;i<e.length();i++)
				{
					while(str[i]>e[i])
					{
						int num=stoi(str);
						int div=stoi(f);
						num=num-div;
						str=to_string(num);
					
					}
					//else
					//{
					//	break;
					//}
				}
				cout<<str<<endl;
				modulo(e,str);
				break;
			}
		}
		
	}
	//modulo for diff sizes
}
string coPrime(string e)
{
	string s="";
	//string v1="";
	//char z='2';
	//v1+=z;
	//cout<<e.length()<<" | "<<v1.length()<<endl;
	for(int i=2;i<e.length();i++)
	{
		string v1="";
		char z=i+48;
		v1+=z;
		if(v1.length()<e.length())
		{
			i=i*100;
			cout<<i<<"|"<<endl;
			v1="";
		}
		else
		{
		}
		/*for(int v2=2;v2<e[i]-48;v2++)
		{
			if(__gcd(v2,e[i]-48)==1)
			{
				char a=v2+48;
				s=s+a;
				return s;
				

			}
		}*/
	}		
	return "0";
}
int main()
{
	//string p="1245";
	string p = "7234209806623201864682567858348680892116173182140261050350822105286971056530242161111756679763022306351222752815540241732559974935084088001392930301241783";
	//string q="7891";
	string q = "816230882841784149012572739720281133606243500967077330332337012012702964700275171333236442861768176166351155303176398597178131293592660994740123653235769";
	string n=multiply(p,q);
	cout<<"\n\n user1"<<endl;
	cout<<"n for user 1:  "<<n<<endl;
	string eul=EulerFtn(p,q);
	cout<<"\n\n\neuler totient for user 1: "<<eul<<endl;
	//cout<<coPrime(eul)<<endl;
	modulo("48251","47272");
	
	string p2="6564584856311576823219586145505817523113427318397549863156566595560964279269333536612422604682084397862269910306961221458864604814121074712407934014669999";
	string q2=
	"9941873979806835599702901677734296903578182354545139121669644308746151750381191686446685233111396500008268216311307333460113276698746418258657455137572063";
	string n2=multiply(p2,q2);
	cout<<"\n\n user2"<<endl;
	cout<<"\n for user 2:  "<<n2<<endl;
	string eul2=EulerFtn(p2,q2);
	cout<<"\n\n\neuler totient for user 2: "<<eul2<<endl;
	return 0;
}
