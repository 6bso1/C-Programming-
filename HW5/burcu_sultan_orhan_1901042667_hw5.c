#include <stdio.h>
#include <string.h>
int rec(char c[], int i);

void main()
{
	FILE *fp1 = fopen("input.txt","r");
	FILE *fp2 = fopen("output.txt", "w");

	char c, str[250], node[10];
	int len, num;

	fgets(str, 250, fp1);
	len = strlen(str);
	int j = 0, cont=0;
	for(int i=0; i<len; i++)
	{
		if(str[i] != ',')
		{
			node[j] = str[i];
			j++;
		}
		else
		{
			num = rec(str, i);
			for(int k=0; k<num; k++)
			{
				fprintf(fp2, "-");
			}
			for(int k=0; k<j; k++)
			{
				if((node[k] > 64 && node[k] < 91) || (node[k] > 96 && node[k] < 123) || node[k] == ' ')
				fprintf(fp2, "%c", node[k]);
			}
			fprintf(fp2, "\n");
			j=0;
		}
	}
	fclose(fp1);
	fclose(fp2);
}

int rec(char c[], int i)
{
	int num=0, len = strlen(c);
	if(i==len-1)
	{
		return num;
	}
	else if(c[i] == '(')
	{
		num--;
		return num + rec(c, i+1);
	}
	else if(c[i] == ')')
	{
		num++;
		return num + rec(c, i+1);
	}
	else
	{
		return num + rec(c, i+1);
	}
}