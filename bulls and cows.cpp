#include<bits/stdc++.h>
#include<string>
using namespace std;


int bull_counter(string &secret, string &a)
{	
	int bull=0,temp=65;
	for(int i=0;i<4;i++)
	{
		if(secret[i]==a[i])
		{
			bull++;
			secret[i]=temp++;
			a[i]=temp++;	
		}
		else
		continue;
	}	
	return bull;
}

int cow_counter(string secret, string a)
{	int temp = 122;
	int cow=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(secret[i]==a[j] && i!=j)
			{
				cow++;
				secret[i]=temp--;
				a[j]=temp--;
			}
		}
	}
	
	
	return cow;
}


int main()
{
	srand(time(0));
	
	int num = (rand()%10000)+1;
	string secret = to_string(num);
	string dupli = secret;
	
	cout<<"Secret number chosen(between 1000 and 9999)"<<endl;
	int guess;
	cin>>guess;
	string gue = to_string(guess);
	while(gue.length()!=4)
	{
		cout<<"Invalid Input!"<<endl;
		cin>>guess;
		gue=to_string(guess);
	}
	int turn=1;
	while(true)
	{
		if(guess==num)
		{
			cout<<"Congratulations! you did it!"<<endl;
			cout<<"You took "<<turn<<" turns to guess the number!"<<endl;
			cout<<"Secret number is "<<num;
			return 0;
		}
		else
		{
			secret=dupli;
			int b = bull_counter(secret, gue);
			int c = cow_counter(secret, gue);
			cout<<"Turn "<<turn<<": Your guess "<<guess<<" has "<<b<<" bulls and "<<c<<" cows."<<endl;
			turn++;
			cin>>guess;
			gue = to_string(guess);
			while(gue.length()!=4)
			{
				cout<<"Invalid Input!"<<endl;
				cin>>guess;
				gue = to_string(guess);
			}
		}
	}
	
}


