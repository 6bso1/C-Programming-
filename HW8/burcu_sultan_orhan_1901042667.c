#include <stdio.h>
#include <stdlib.h>
#define n 511

void main()
{
    FILE *fp1 = fopen("input.txt", "r");
    FILE *fp2 = fopen("output.txt", "w");

    int i=0, j=0, level, matrix[n][n], coordinate[n][n], cont=0, num=0;
    //The program gets the L value and attaches it to int level
    fscanf(fp1, "%d", &level);
    //The program fills the matrix array, i is row and j is column
    while(i<512)
    {
        fscanf(fp1, "%d", &matrix[i][j]);
        j++;
        //When j reaches to 512, that means the current row should end and a new row should start. So i increases and j is 0 again
        if(j==512)
        {
            i++;
            j=0;
        }
    }
    //With this for loop, the program checks the matrix values one by one, i is row and j is column
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=n; j++)
        {
            //If a value is above the sea level, the program checks if this is a new island or a part of the former island
            if(matrix[i][j] > level)
            {
                //If the row is bigger than 0, the program checks if (x-1, y) is also above the sea level
                if(i>0 && matrix[i-1][j]>level)
                {
                    //cont is a control value, if (x-1, y) is also above the sea level, that means there's not a new island
                    cont++;
                }
                //If the column is bigger than 0, the program checks if (x, y-1) is also above the sea level
                if(j>0 && matrix[i][j-1]>level)
                {
                    //cont is a control value, if (x, y-1) is also above the sea level, that means there's not a new island
                    cont++;
                }
                //If cont is 0, that means we found a new island, so we write down the coordinations in a new array
                if(cont==0)
                {
                    coordinate[num][0] = i;
                    coordinate[num][1] = j;
                    num++;
                }
                cont=0;
            }
        }
    }
    printf("%d\n", num);
    for(i=0; i<num; i++)
    {
        printf("%d %d\n", coordinate[i][0], coordinate[i][1]);
    }
}
