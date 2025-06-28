#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<stdbool.h>
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
	static char a12[30];
	memset(a12, 0, sizeof(a12));
	int i=0,j=0,z;
	while(arr[i]!=' ')
	{
		i++;
	}
	i++;
	while(arr[i]!='\0')
	{
		a12[j]=arr[i];
		i++;
		j++;
	}
	a12[i]='\0';
	return a12;
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
void getColumnName(char *colDef, char *result) {
    int i = 0, j = 0;
    while (colDef[i] != ' ' && colDef[i] != '\0') i++; 
    if (colDef[i] == ' ') i++; 
    while (colDef[i] != '\0') {
        result[j++] = colDef[i++];
    }
    result[j] = '\0';
}
void removeColumnData(char arr1[], char arr[], int colToRemove) {
    int i = 0, j = 0, k = 0, l = 0, count = 0;
    char temp[30];
    while (arr[i] != '\0') {
        if (count != colToRemove) {
            while (arr[i] != ',' && arr[i] != '\0') {
                temp[j++] = arr[i++];
            }
            temp[j] = '\0';
            k = 0;
            while (temp[k] != '\0') {
                arr1[l++] = temp[k++];
            }
            if (arr[i] == ',') {
                arr1[l++] = ',';
                i++; 
            }
        } else {
            while (arr[i] != ',' && arr[i] != '\0') {
                i++;
            }
            if (arr[i] == ',') {
                i++; 
            }
        }
        count++;
        j = 0;
        memset(temp, 0, sizeof(temp));
    }
    if (l > 0 && arr1[l - 1] == ',') {
        l--;
    }
    arr1[l] = '\0';
}

int getTableStructure(char arr[],char dt[10][30])
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
	return z;
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
void updateLineInFile(const char *filename, const char *target, const char *replacement) {
    FILE *src = fopen(filename, "r");
    FILE *tmp = fopen("temp.txt", "w");
    char buffer[256];

    if (!src || !tmp) {
        printf("File error\n");
        return;
    }

    while (fgets(buffer, sizeof(buffer), src)) {
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strcmp(buffer, target) == 0) {
            fprintf(tmp, "%s\n", replacement);
        } else {
            fprintf(tmp, "%s\n", buffer);
        }
    }
    fclose(src);
    fclose(tmp);
    remove(filename);
    rename("temp.txt", filename);
    printf("Line updated successfully\n");
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
void removeStringRow(char arr[][30], int rows, int rowToRemove) {
    if (rowToRemove < 0 || rowToRemove >= rows) {
        printf("Invalid row index\n");
        return ; 
    }

    for (int i = rowToRemove; i < rows - 1; i++) {
        strcpy(arr[i], arr[i + 1]);
    }
}

void updateTableSchema(char str1[50], char tableName[], char fields[][30], int rows) {
    int rr = 0;

    while (tableName[rr] != '\0') {
        str1[rr] = tableName[rr];
        rr++;
    }

    str1[rr++] = '(';

    for (int i = 0; i < rows; i++) {
        int j = 0;
        while (fields[i][j] != '\0') {
            str1[rr++] = fields[i][j++];
        }

        if (i < rows - 1) {
            str1[rr++] = ',';
        }
    }

    str1[rr++] = ')';
    str1[rr] = '\0';
}


void deleteColumn(char *dbName, char *tableName, char *columnToDelete) {
	FILE *f1,*temp1,*f2,*temp2;
	char fn[20];
	char fr[50];
	static char as[10][50];
	char fr1[50];
	char fr2[30];
	char fr3[20];
	char fr4[50];
	static char dt[10][30];
	char fr5[50];
	char fr6[20];
	char fr7[30];
	char fr8[30];
	char tempf[10]="temp1.txt";
	char tempt[10]="temp2.txt";
	int i=0,j=0,rows,ctd=0;
	strcpy(fn,createFileName(dbName));
	f1=fopen(fn,"r");
	while(fgets(fr,sizeof(fr),f1))
	{
		if(strcmp(tableName,getBeforeBracket(fr))==0)
		{
			strcpy(fr1,fr);
		}
		strcpy(as[i],fr);
		i++;
	}
	strcpy(fr1,getInsideBracket(fr1));
	rows=getTableStructure(fr1,dt);
	while(dt[j][0]!='\0')
	{
		strcpy(fr2,dt[j]);
		strcpy(fr3,getSecondString(fr2));
		if(strcmp(fr3,columnToDelete)==0)
		{
			removeStringRow(dt,rows,j);
			break;
		}
		ctd++;
		j++;
	}
	rows--;
	updateTableSchema(fr4,tableName,dt,rows);
	fclose(f1);
	f1=fopen(fn,"r");
	temp1=fopen(tempf,"w");
	while(fgets(fr5,sizeof(fr5),f1))
	{
		if(strcmp(tableName,getBeforeBracket(fr5))==0)
		{
			fprintf(temp1,fr4);
			fprintf(temp1,"\n");
		}
		else
		{
			fprintf(temp1,fr5);
		}
	}
	fclose(f1);
	fclose(temp1);
	if (remove(fn) != 0) {
        printf("Error removing original file db\n");
        return;
    }
    if (rename(tempf, fn) != 0) {
        printf("Error renaming temp file\n");
        return;
    }
	strcpy(fr6,createFileName(tableName));
	f2=fopen(fr6,"r");
	temp2=fopen(tempt,"w");
	while(fgets(fr7,sizeof(fr7),f2))
	{
		removeColumnData(fr8,fr7,ctd);
		fprintf(temp2,fr8);
	}
	fclose(f2);
	fclose(temp2);
	if (remove(fr6) != 0) {
        printf("Error removing original file\n");
        return;
    }
    if (rename(tempt, fr6) != 0) {
        printf("Error renaming temp file\n");
        return;
    }
	
	printf("column removed successfully\n");
}
void deleteRow(char arr[],int rn)
{
	FILE *f1,*temp;
	char fn[30];
	char fr[50];
	char temo[9]="temp.txt";
	static char trows[10][30];
	int i=0,b=0;
	strcpy(fn,createFileName(arr));
	f1=fopen(fn,"r");
	while(fgets(fr,sizeof(fr),f1))
	{
		strcpy(trows[i],fr);
		i++;
	}
	removeStringRow(trows,i,rn);
	temp=fopen(temo,"w");
	while(b<i-1)
	{
		fprintf(temp,trows[b]);
		b++;
	}
	fclose(f1);
	fclose(temp);
	if (remove(fn) != 0) {
        printf("Error removing original file\n");
        return;
    }
    if (rename(temo, fn) != 0) {
        printf("Error renaming temp file\n");
        return;
    }
	printf("row deleted successfully\n");
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
	printf("data inserted successfully\n");
	fclose(f);
}
void deleteTable(char fn[], char arr[]) {
    FILE *f1;
    char tempFile[] = "temp.txt";
    char tn[20];
    char rf[100];
	FILE *f = fopen(fn, "r");
    if (f == NULL) {
        printf("Error opening original file for reading\n");
        return;
    }
    f1 = fopen(tempFile, "w");
    if (f1 == NULL || f == NULL) {
        printf("Error opening files\n");
        return;
    }

    while (fgets(rf, sizeof(rf), f)) {
        strcpy(tn, getBeforeBracket(rf));
        if (strcmp(arr, tn) != 0) {
            fputs(rf, f1);
        }
    }

    fclose(f);
    fclose(f1);

    if (remove(fn) != 0) {
        printf("Error removing original file\n");
        return;
    }

    if (rename(tempFile, fn) != 0) {
        printf("Error renaming temp file\n");
        return;
    }

    char tableFile[30];
    strcpy(tableFile, createFileName(arr));
    if (remove(tableFile) == 0) {
        printf("Table deleted successfully\n");
    } else {
        printf("Error while deleting table data file\n");
    }
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
	char st1[40];
	char st2[20];
	char st3[20];
	char st4[40];
	char st5[5];
	char st6[20];
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
			fclose(f);
			deleteTable(fname,arr71);
		}
		else if(strcmp(arr5,exit)==0)
		{
			return;
		}
		else if(strcmp(arr5,trr1)==0)
		{
			strcpy(st1,getSecondString(arr1));
			strcpy(st2,getInsideBracket(st1));
			strcpy(st3,getBeforeBracket(st1));
			fclose(f);
			deleteColumn(arr,st3,st2);
		}
		else if(strcmp(arr5,trr2)==0)
		{
			strcpy(st4,getSecondString(arr1));
			strcpy(st5,getInsideBracket(st4));
			strcpy(st6,getBeforeBracket(st4));
			int b=0;
			while(st5[b]!='\0')
			{
				if(isdigit(st5[b])==0)
				{
					printf("invalid row number");
					return;
				}
				b++;
			}
			int rowNumber=atoi(st5);
			deleteRow(st6,rowNumber);
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