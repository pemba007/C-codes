#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
void encry(void);
void decry(void);
void main()
{
	clrscr();
	int opt=0;
	printf("Welcome to my program to encrypt and decrypt messages\n");
	printf("What to do \n");
	printf("1. Encrypt messages\n2. Decrypt messages ");
	scanf("%d",&opt);
	switch (opt)
	{
		case 1:
			encry();
			break;
		default:
			decry();
	}
	getch();
}
void encry()
{
	clrscr();
	fflush(stdin);
	char bas;
	char msg[100];
	int ba=0,diff=0,i,l=0,diff2=0;
	printf("**********************************Encryption********************************");
	printf("\nEnter in capital letters. No numbers and other characters except letters and spaces. \n");
	printf("Enter the base character ");
	scanf("%c",&bas);
	ba=bas;
	if(ba>=97 && ba<=122)
	{
		bas-=32;
		ba-=32;
	}
	fflush(stdin);
	printf("Enter your msg to encrypt\n");
	gets(msg);
	strupr(msg);
	diff=ba-65;
	l=strlen(msg);
	for(i=0;i<l;i++)
	{
		if(msg[i]>=65 && msg[i]<=90)
		{
			msg[i]+=diff;
			if(msg[i]>90)
				msg[i]-=26;
		}
		else if (msg[i]>=48 && msg[i]<=57)
		{
			diff2=diff%10;
			msg[i]+=diff2;
			if(msg[i]>57)
				msg[i]-=10;
		}
	}
	printf("\n");
	printf("Your enrcypted message is \n\n");
	fflush(stdout);
	puts(msg);
	printf("\n\n You can put this encrypted on the decryption option in this program itself");
	getch();
}
void decry()
{
	flushall();
	clrscr();
	char bas;
	char msg[100];
	int ba=0,diff=0,i,l=0,diff2=0;
	printf("**********************************Decryption********************************");
	printf("\nEnter in capital letters\n");
	printf("Enter the base character ");
	scanf("%c",&bas);
	ba=bas;
	if(ba>=97 && ba<=122)
	{
		bas-=32;
		ba-=32;
	}
	fflush(stdin);
	printf("Enter your msg to decrypt\n");
	gets(msg);
	strupr(msg);
	diff=ba-65;
	l=strlen(msg);
	puts(msg);
	for(i=0;i<l;i++)
	{
		if(msg[i]>=65 && msg[i]<=90)
		{
			msg[i]-=diff;
			if(msg[i]<65)
				msg[i]+=26;
		}
		else if (msg[i]>=48 && msg[i]<=57)
		{
			diff2=diff%10;
			msg[i]-=diff2;
			if(msg[i]<48)
				msg[i]+=10;
		}
	}
	printf("\n");
	printf("Your decrypted message is \n\n");
	fflush(stdout);
	puts(msg);
	getch();
}