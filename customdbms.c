#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
void getString(char arr[],int n)
{
	printf(">");
	fgets(arr,n,stdin);
	arr[strcspn(arr, "\n")] = '\0';
}
char* getFirstString(char arr[])
{
	static char a[10];
	int i=0,j;
	while(arr[i]!=' ')
	{
		a[i]=arr[i];
		i++;
	}
	a[i]='\0';
	return a;
}
void displayArray(char arr[])
{
	int i=0;
	while(arr[i]!='\0')
	{
		printf("%c",arr[i]);
		i++;
	}
}
char* createFileName(char arr[])
{
	char txt[4]=".txt";
	int i=0,j;
	static char fn[20];
	while(arr[i]!='\0')
	{
		fn[i]=arr[i];
		i++;
	}
	for(j=0;j<4;j++)
	{
		fn[i]=txt[j];
		i++;
	}
	fn[i]='\0';
	return fn;
}
char* getSecondString(char arr[])
{
	static char a1[30];
	int i=0,j=0,z;
	while(arr[i]!=' ')
	{
		i++;
	}
	i++;
	while(arr[i]!='\0')
	{
		a1[j]=arr[i];
		i++;
		j++;
	}
	a1[i]='\0';
	return a1;
}
void getDataTypes(char arr[],char dt[10][30])
{
	char temp[20];
	char temp2[10];
	int i=0,j=0,z=0,n=0;
	while(arr[n]!=0)
	{
		n++;
	}
	n++;
	while(i<n)
	{
		if(arr[i]!=',')
		{
			temp[j]=arr[i];
		}
	    if(arr[i]==',' || arr[i]=='\0')
		{
			temp[j]='\0';
			strcpy(temp2,getFirstString(temp));
			strcpy(dt[z],temp2);
			z++;
			memset(temp, 0, sizeof(temp));
    		j=-1;
		}
		j++;
		i++;
	}
}
void getInputData(char arr[],char dt[10][30])
{
	char temp[20];
	int i=0,j=0,z=0,n=0;
	while(arr[n]!=0)
	{
		n++;
	}
	n++;
	while(i<n)
	{
		if(arr[i]!=',')
		{
			temp[j]=arr[i];
		}
	    if(arr[i]==',' || arr[i]=='\0')
		{
			temp[j]='\0';
			strcpy(dt[z],temp);
			z++;
			memset(temp, 0, sizeof(temp));
    		j=-1;
		}
		j++;
		i++;
	}
}
int countInputData(char arr[])
{
	int c=0,n=0,i=0;
	while(arr[n]!=0)
	{
		n++;
	}
	n++;
	while(i<n)
	{
		if(arr[i]!=',')
		{
			c++;
		}
		i++;
	}
	c++;
	return c;
}
void createDatabase(char arr[],int c)
{
	FILE *f;
	char fname[4+c-1];
	strcpy(fname,createFileName(arr));
	f=fopen(fname,"w");
	if(f==NULL)
	{
		printf("database cannot be created\n");
	}
	else
	{
		printf("database created successfully\n");
	}
	fclose(f);
}
char* getBeforeBracket(char arr[])
{
	static char arr1[20];
	int i=0;
	while(arr[i]!='(')
	{
		arr1[i]=arr[i];
		i++;
	}
	arr1[i]='\0';
	return arr1;
}
char* getInsideBracket(char arr[])
{
	static char arr1[50];
	int i=0,j=0;
	while(arr[i]!='(')
	{
		i++;
	}
	i++;
	while(arr[i]!=')')
	{
		arr1[j]=arr[i];
		j++;
		i++;
	}
	arr1[i]='\0';
	return arr1;
}
void createTable(char arr[],int x)
{
	FILE *f;
	int z,p;
	char txt[4]=".txt";
	char fname[4+x];
	strcpy(fname,createFileName(arr));
	f=fopen(fname,"w");
	if(f==NULL)
	{
		printf("table cannot be created\n");
	}
	else
	{
		printf("table created successfully\n");
	}
	fclose(f);
}
void insertTable(char arr[],char arr1[],char arr2[],int x)
{
	FILE *f;
	int i=0,j=0,z=0,p=0,c;
	char txt[4]=".txt";
	char s1[3]="int";
	char dt[10][30];
	char dt1[10][30];
	char fname[4+x];
	strcpy(fname,createFileName(arr));
	getDataTypes(arr2,dt);
	getInputData(arr1,dt1);
	c=countInputData(arr1);
	while(z<c)
	{
		if(strcmp(dt1[z],s1)==0)
		{
			while(dt[z][p]!='\0')
			{
				if(!isdigit(dt[z][p]))
				{
					printf("datatype mismatch\n");
					return;
				}
				p++;
			}
		}
		z++;
	}
	f=fopen(fname,"a");
	fprintf(f,arr1);
	fprintf(f,"\n");
	printf("data inserted successfully\n");
	fclose(f);
}
void deleteTable(char fn[],char arr[],FILE *f)
{
	FILE *f1;
	char tn[20];
	char rf[30];
	char fname[20];
	strcpy(fname,createFileName(arr));
	f1=fopen(fn,"w");
	if(f==NULL)
	{
		printf("error\n");
		return;
	}
	while(fgets(rf,50,f))
	{
		strcpy(tn,getBeforeBracket(rf));
		if(strcmp(arr,tn)==0)
		{
			continue;
		}
		fprintf(f1,rf);
		fprintf(f1,"\n");
	}
	if(remove(fname)==0)
	{
		printf("table deleted successfully\n");
	}
	else
	{
		printf("error while deleting table\n");
	}
	fclose(f1);
}
void useDatabase(char arr[],int y)
{
	char arr1[50];
	char arr2[3]="-c";
	char arr3[3]="-i";
	char trr[4]="-dt";
	char trr1[4]="-dc";
	char trr2[4]="-dr";
	char exit[3]="-e";
	char arr5[5];
	char arr6[50];
	char arr7[50];
	char arr71[20];
	char ar[20];
	char ar1[50];
	char ar2[20];
	char ar3[50];
	char ar4[20];
	char rf[50];
	char tn[20];
	char st[30];
	char txt[4]=".txt";
	FILE *f;
	int i=0,j,z,c=0,c1=0,p,check=0;
	char fname[4+y];
	arr2[2]='\0';
	arr3[2]='\0';
	trr[3]='\0';
	trr1[3]='\0';
	trr2[3]='\0';
	exit[2]='\0';
	while(arr[i]!='\0')
	{
		fname[i]=arr[i];
		i++;
	}
	for(j=0;j<4;j++)
	{
		fname[i]=txt[j];
		i++;
	}
	fname[i]='\0';
	f=fopen(fname,"a+");
	if(f==NULL)
	{
		printf("database cannot be found\n");
	}
	else
	{
		for(p=0;p<i-4;p++)
		{
			printf("%c",fname[p]);
		}
		getString(arr1,sizeof(arr1));
		strcpy(arr5,getFirstString(arr1));
		if(strcmp(arr5,arr2)==0)
		{
			strcpy(arr6,getSecondString(arr1));
			strcpy(ar,getBeforeBracket(arr6));
			z=0;
			while(arr6[z]!='\0')
			{
				z++;
			}
			z++;
			arr6[z]='\n';
			fprintf(f,arr6);
			fprintf(f,"\n");
			while(ar[c]!='\0')
			{
				c++;
			}
			createTable(ar,c);
		}
		else if(strcmp(arr5,arr3)==0)
		{
			strcpy(arr7,getSecondString(arr1));
			strcpy(ar2,getBeforeBracket(arr7));
			strcpy(ar3,getInsideBracket(arr7));
			while(ar2[c1]!='\0')
			{
				c1++;
			}
			while(fgets(rf,50,f))
			{
				strcpy(tn,getBeforeBracket(rf));
				if(strcmp(ar2,tn)==0)
				{
					check=1;
					strcpy(st,getInsideBracket(rf));
					break;
				}
			}
			if(check==1)
			{
				insertTable(ar2,ar3,st,c1);
			}
			else
			{
				printf("table not found\n");
			}
		}
		else if(strcmp(arr5,trr)==0)
		{
			strcpy(arr71,getSecondString(arr1));
			deleteTable(fname,arr71,f);
		}
		else if(strcmp(arr5,exit)==0)
		{
			return;
		}
		else
		{
			printf("invalid syntax\n");
		}
	}
	fclose(f);
	if(strcmp(arr5,exit)!=0)
	{
		useDatabase(arr,y);
	}
}
int main()
{
	char arr1[50];
	char arr2[4]="cdb";
	char arr3[4]="udb";
	char arr4[4];
	char arr5[30];
	char exit[3]="-e";
	int c=0,c1=0;
	char fname[20];
	char txt[4]=".txt";
	FILE *f;
	arr2[3]='\0';
	arr3[3]='\0';
	exit[2]='\0';
	getString(arr1,sizeof(arr1));
	strcpy(arr4,getFirstString(arr1));
	if(strcmp(arr2,arr4)==0)
	{
		strcpy(arr5,getSecondString(arr1));
		while(arr5[c]!='\0')
		{
			c++;
		}
		createDatabase(arr5,c);
	}
	else if(strcmp(arr3,arr4)==0)
	{
		strcpy(arr5,getSecondString(arr1));
		while(arr5[c1]!='\0')
		{
			c1++;
		}
		strcpy(fname,createFileName(arr5));
		f=fopen(fname,"r");
		if(f==NULL)
		{
			printf("database does not exits\n");
		}
		else
		{
			fclose(f);
			useDatabase(arr5,c1);
		}
	}
	else if(strcmp(arr4,exit)==0)
	{
		return 0;
	}
	else
	{
		printf("\nerror");
	}
	if(strcmp(arr4,exit)!=0)
	{
		main();
	}
}