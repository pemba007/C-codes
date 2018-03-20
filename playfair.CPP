#include<iostream.h>
#include<conio.h>
#include<string.h>

char ne[10];

struct data
{
	int xx;
	int yy;
};

data seartab(char che,char mat[5][5])
{
	data c1;
	for(int a=0;a<5;a++)
	{
		for(int b=0;b<5;b++)
		{
			if(che==mat[a][b])
			{
				c1.xx=a;
				c1.yy=b;
			}
		}
	}
	return c1;
}

void encrypt(char msg[100], char mat[5][5])
{
	char newmsg[100]="\0";
	if (strlen(msg)%2!=0)
	{
		char nep[2];
		nep[0]='X';
		nep[1]='\0';
		strcat(msg,nep);
	}
	for(int a=0;a<strlen(msg);a=a+2)
	{
		data x,y;
		char a1,a2;
		int x1,y1;
		a1=msg[a];
		a2=msg[a+1];
		x=seartab(a1,mat);
		y=seartab(a2,mat);
		if(x.xx==y.xx)
		{
			newmsg[a]=mat[x.xx][(x.yy+1)%5];
			newmsg[a+1]=mat[y.xx][(y.yy+1)%5];
		}
		else if(x.yy==y.yy)
		{
			newmsg[a]=mat[(x.xx+1)%5][x.yy];
			newmsg[a+1]=mat[(y.xx+1)%5][y.yy];
		}
		else
		{
			newmsg[a]=mat[x.xx][y.yy];
			newmsg[a+1]=mat[y.xx][x.yy];
		}
	}
	cout<<"MESSAGE is "<<endl<<newmsg<<endl;
}

int search(char chek,char mat[5][5])
{
	int flag1=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if(chek==mat[i][j])
				flag1=1;
		}
	}
	return flag1;
}

int check1(char che,char ne[])
{
	int flag=0;
	for(int i=0;i<strlen(ne);i++)
	{
		if(che==ne[i])
			flag=1;
	}
	return flag;
}

void check(char msg[])
{
	int i=0,j=0;
	for(i=0;i<strlen(msg);i++)
	{
		if(check1(msg[i],ne)==0)
		{
			ne[j]=msg[i];
			j++;
		}
	 }
}

void display(char mat[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<"   "<<mat[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}
void main()
{
	clrscr();
	char key[10];
	cout<<"Enter the key word  "<<endl;
	cin>>key;
	strupr(key);
	for(int i=0;i<strlen(key);i++)
	{
		if(key[i]=='J')
		{
			key[i]='I';
		}
	}
	check(key);
	char mat[5][5]={0};
	int a=0,b=0,count=0;
	char alpha='A';
	for(a=0;a<5;a++)
	{
		for(b=0;b<5;b++)
		if(count<strlen(ne))
		{
			mat[a][b]=ne[count];
			count++;
		}
		else
		{
			while(check1(alpha,ne)!=0)
			{
				if(alpha=='I')
				{
					alpha+=2;
				}
				else
				{
					alpha++;
				}
			}
			mat[a][b]=alpha;
			if(alpha=='I')
				alpha+=2;
			else
				alpha++;
		}
	}
	display (mat);

	char encry[100];
	cout<<"Enter the message "<<endl;
	cin>>encry;
	strupr(encry);
	for(int j1=0;j1<strlen(encry);j1++)
	{
		if(encry[j1]=='J')
			encry[j1]='I';
	}
	encrypt(encry,mat);
	cout<<endl<<"Encryption Over"<<endl;
	getch();
}