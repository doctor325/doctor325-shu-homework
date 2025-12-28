#include<iostream>
using namespace std;

int main()
{
	int n;
	int a,b;
	int c,s,x,y;
	int max=0;
	
    cin>>a>>b;
	int bu[b-a];
	for(c=a;c<=b;c++)
	{
		x=c;
		s=10;

		if(s<10) continue;
		bu[c-a]=0;

		do
		{
			y=1;	
			do
			{
				y=y*(x%10);
				x=x/10;	
			}while(x>0);
			x=y;
			bu[c-a]++;
			//	cout<<y<<" ";
			//cout<<"\n"<<endl;
		}while(y>=10);
		//cout<<bu[c-a]<<"\n"<<"==================="<<c<<"\n"<<endl;
	}
	for(c=0;c<b-a;c++)
	{
		if(bu[c]>=max)
			max=bu[c];
	}
	cout<<max<<"\n";
	for(c=a;c<=b;c++)
	{
		if(bu[c-a]==max)
	cout<<c<<" ";
	}
    cout<<"\b"<<endl;
	return 0;
}
