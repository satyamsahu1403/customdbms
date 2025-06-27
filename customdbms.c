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
void getColumnName(char *colDef, char *result) {
    int i = 0, j = 0;
    while (colDef[i] != ' ' && colDef[i] != '\0') i++; 
    if (colDef[i] == ' ') i++; 
    while (colDef[i] != '\0') {
        result[j++] = colDef[i++];
    }
    result[j] = '\0';
}

void getTableStructure(char arr[],char dt[10][30])
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
void removeStringRow(char arr[][30], int *rows, int rowToRemove) {
    if (rowToRemove < 0 || rowToRemove >= *rows) {
        printf("Invalid row index\n");
        return;
    }

    for (int i = rowToRemove; i < (*rows) - 1; i++) {
        strcpy(arr[i], arr[i + 1]);
    }

    (*rows)--;
}


int deleteColumn(char *dbName, char *tableName, char *columnToDelete) {
    char schemaLine[256], newSchemaLine[256];
    char schemaFile[30], tableFile[30];
    char tempSchemaFile[] = "temp_schema.txt", tempTableFile[] = "temp_table.txt";
    char fields[10][30], columnName[30];
    int numCols = 0, deleteIndex = -1;

    strcpy(schemaFile, createFileName(dbName));
    strcpy(tableFile, createFileName(tableName));

    FILE *schemaIn = fopen(schemaFile, "r");
    FILE *schemaOut = fopen(tempSchemaFile, "w");
    FILE *tableIn = fopen(tableFile, "r");
    FILE *tableOut = fopen(tempTableFile, "w");

    if (!schemaIn || !schemaOut || !tableIn || !tableOut) {
        printf("Error opening files for column deletion.\n");
        return -1;
    }

    bool found = false;

    while (fgets(schemaLine, sizeof(schemaLine), schemaIn)) {
        char schemaTable[30];
        strcpy(schemaTable, getBeforeBracket(schemaLine));

        if (strcmp(schemaTable, tableName) == 0) {
            found = true;
            char *schemaContent = getInsideBracket(schemaLine);
            getTableStructure(schemaContent, fields);

            while (fields[numCols][0] != '\0') numCols++;

            for (int i = 0; i < numCols; i++) {
                getColumnName(fields[i], columnName);
                if (strcmp(columnName, columnToDelete) == 0) {
                    deleteIndex = i;
                    break;
                }
            }

            if (deleteIndex == -1) {
                printf("Column '%s' not found in table '%s'.\n", columnToDelete, tableName);
                fclose(schemaIn); fclose(schemaOut); fclose(tableIn); fclose(tableOut);
                remove(tempSchemaFile); remove(tempTableFile);
                return -1;
            }

            for (int i = deleteIndex; i < numCols - 1; i++) {
                strcpy(fields[i], fields[i + 1]);
            }
            numCols--;

            fprintf(schemaOut, "%s(", tableName);
            for (int i = 0; i < numCols; i++) {
                fprintf(schemaOut, "%s", fields[i]);
                if (i < numCols - 1) fprintf(schemaOut, ",");
            }
            fprintf(schemaOut, ")\n");
        } else {
            fputs(schemaLine, schemaOut);
        }
    }

    if (found && deleteIndex != -1) {
        char row[256], values[10][30];
        while (fgets(row, sizeof(row), tableIn)) {
            getInputData(row, values);
            for (int i = deleteIndex; i < numCols; i++) {
                strcpy(values[i], values[i + 1]);
            }

            fprintf(tableOut, "%s", values[0]);
            for (int i = 1; i < numCols; i++) {
                fprintf(tableOut, ",%s", values[i]);
            }
            fprintf(tableOut, "\n");
        }

        fclose(schemaIn); fclose(schemaOut);
        fclose(tableIn); fclose(tableOut);

        remove(schemaFile);
        rename(tempSchemaFile, schemaFile);
        remove(tableFile);
        rename(tempTableFile, tableFile);

        printf("✅ Column '%s' deleted successfully from table '%s'.\n", columnToDelete, tableName);
        return 0;
    }

    fclose(schemaIn); fclose(schemaOut); fclose(tableIn); fclose(tableOut);
    printf("❌ Failed to update table. No files were modified.\n");
    remove(tempSchemaFile); remove(tempTableFile);
    return -1;
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
			deleteColumn(arr,st3,st2);
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