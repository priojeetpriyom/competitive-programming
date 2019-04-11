#include <bits/stdc++.h>

using namespace std;
int find_square(int num)
{
	int sum=0,temp;
	//printf("%d\n",num);
	while(num>0)
	{
		//printf("num %d\n",num);
		temp= num%10;
//		for(int i=0;i<temp;i++)
//			sum+=temp;
		sum+=temp*temp;
		//if(num<10) break;
		num=num/10;
		//printf("%d\n",sum);
	}
	return sum;
}
int main()
{
	int n,num;
	bool repeat[1000101],flag;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&num);
		for(int i=0;i<1000101;i++)
			repeat[i] = false;
		flag==true;
		while(1)
		{
			//printf("%d ",num);
			num=find_square(num);
			//printf("num %d\n",num);
			if(num==1) {
				flag=true;
				break;
			}
			if(repeat[num]== true)
			{
				flag=false;
				printf("Not Happy\n");
				break;
			}
			repeat[num]= true;
		}
		if(flag==true) printf("Happy\n");
	}
}
