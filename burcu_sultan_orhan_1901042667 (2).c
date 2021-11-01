#include <stdio.h>
#include <string.h>

float rec(char object[], char parentObject[]);
int if_num(char c);

void main()
{
    char object[100], str[100];
    float result;

    printf("Name of the object:\n");
    scanf("%s", &object);
    printf("Define %s?\n", object);
    scanf(" %[^\n]s", str);
    result = rec(str, object);
    printf("Total cost of %s is %f\n", object, result);
}

int if_num(char c)
{
    if(c>47 && c<58)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

float rec(char object[], char parentObject[])
{
    int i, j=0, a=0, len, node=0, num1=0, num2=0, ch1=-1, ch2=0;
    char temp[100], nodez[100][100], nodes[100][100];
    float result=0, nod[100];

    len=strlen(object);

    for(i=0; i<len; i++)
    {
        if(object[i] != ' ')
        {
            temp[j] = object[i];
            j++;
        }
    }

    len = strlen(temp);

    for(i=0; i<j; i++)
    {
        if(if_num(temp[i]))
        {
            if(!if_num(temp[i+1]))
            {
                node++;
                ch1++;
                ch2=0;
            }
            nodes[num1][num2] = temp[i];
            num2++;
        }
        if((temp[i]>64 && temp[i]<91) || (temp[i]>96 && temp[i]<123))
        {
            a++;
            nodez[ch1][ch2] = temp[i];
            ch2++;
            if(!((temp[i+1]>64 && temp[i+1]<91) || (temp[i+1]>96 && temp[i+1]<123)))
            {
                sscanf(nodes[num1], "%f", &nod[num1]);
                num1++;
                num2=0;
            }
        }
    }
    if(a==0)
    {
        sscanf(temp, "%f", &result);
        return result;
    }
    else
    {
        for(i=0; i<=node; i++)
        {
            printf("Define %s in %s?\n", nodez[i], parentObject);
            scanf(" %[^\n]s", object);
            result = result + (nod[i] * rec(object, nodez[i]));
        }
        return result;
    }
}
