#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

int main()
{
	char arr[30][5][100];
	int issue[30]={0};
	FILE *fp= fopen("library.txt", "r");
	int i;
	if (fp == NULL){
        printf("Error Reading File\n");
        exit (0);
    }

    for (i = 0; i < 30; i++){
        fscanf(fp, " %[^\n]s", &arr[i][0] );
        fscanf(fp, " %[^\n]s", &arr[i][1] );
        fscanf(fp, " %[^\n]s", &arr[i][2] );
    }
    
    char store[10000][100];
    int st[10000][2];
    
    char book[100];
    char auth[100];
    
    cout<<"search by? \nEnter your choice: \n1. book, 2. author";
    int n;
    scanf("%d", &n);
    
    if(n==1)
    {
    	cout<<"Enter book name";
    	scanf(" %[^\n]s",book);;
    	int c=0,pos;
    	for(int i=0;i<30;i++)
    	{
    		if(!strcmp(book, arr[i][1]))
    		{
    			c++; pos=i+1;
    			break;
			}
    	
		}
		
		int j=0,k=0;
		
		
		int sid;
		char date[100];
		if(c>0 && issue[pos-1]==0)
		{
			cout<<"Yes! Book is available! Enter student id and today's date!";
			cin>>sid;
			gets(date);
			st[j][0]=pos;
			st[j++][1]=sid;
			
			issue[pos-1]=1;
		
		}
		else if(c>0)
		{
			cout<<"Book issued! Sorry!";
		}
		else
		{
			cout<<"Book not available";
		}
		
		cout<<"Book ID \t Student ID \t Return date\n";
		for(int i=0;i<j;i++)
		{
			cout<<st[i]<<"\t"<<store[i][1]<<"\t"<<"7 days from "<<date<<"\n";
		}
	}
	
	else
	{
		cout<<"Enter author name";
    	scanf(" %[^\n]s",auth);;
    	int c=0,pos;
    	for(int i=0;i<30;i++)
    	{
    		if(!strcmp(auth, arr[i][2]))
    		{
    			c++; pos=i+1;
    			break;
			}
    	
		}
		
		int j=0,k=0;
		
		
		int sid;
		char date[100];
		if(c>0 && issue[pos-1]==0)
		{
			cout<<"Yes! Author is available! Enter student id and today's date!";
			cin>>sid;
			gets(date);
			st[j][0]=pos;
			st[j++][1]=sid;
			
			issue[pos-1]=1;
		
		}
		else if(c>0)
		{
			cout<<"Book issued! Sorry!";
		}
		else
		{
			cout<<"Book not available";
		}
		
		cout<<"Book ID \t Student ID \t Return date\n";
		for(int i=0;i<j;i++)
		{
			cout<<st[i][0]<<"\t"<<st[i][1]<<"\t"<<"7 days from "<<date<<"\n";
		}
	}
}


