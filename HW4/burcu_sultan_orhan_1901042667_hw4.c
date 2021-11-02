#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int reverse(int num);

void main()
{
	FILE *fp1 = fopen("values.txt", "r");
	FILE *fp2 = fopen("polynomial.txt", "r");
	FILE *fp3 = fopen("evaluations.txt", "w");

	double numbers[100], conc=0, coe1=0, coe2=0, char_to_double=0, result=0, power = 0;
	char polynomial[1000];
	int i=0, j=0, k=0, temp=0;

	fgets(polynomial, 1000, fp2);
	int len = strlen(polynomial);

	//With this for loop, program erases the blank spaces in the array
	for(i=0; i<len; i++)
	{
		if(polynomial[i] == ' ')
		{
			for(j=i; j<len; j++)
			{
				polynomial[j] = polynomial[j+1];
			}
			i=i-1;
		}
	}
	fclose(fp2);

	len = strlen(polynomial);

	i=0;
	//With this while loop, program gets the numbers from file
	while(!feof(fp1))
	{
		fscanf(fp1, "%lf", &numbers[i]);
		i++;
	}
	fclose(fp1);
	//This whole loop is kind of complex and hard to understand, but i will try to explain my algorhytm
	//With this first for loop, program will run itself for every single number
	for(k=0; k<i; k++)
	{
		//conc is short for 'conclusion'
		conc = numbers[k];
		//With this for loop, we check the polynomial values
		for(j=0; j<len; j++)
		{
			if(polynomial[j] == 'x')
			{
				//Firstly we need to get rid of power conditions. So program checks it first.
				if(polynomial[j+1] == '^')
				{
					for(int a=j+2; a<len; a++)
					{
						//Checks until the power ends and there is no more digit of it
						if(!isdigit(polynomial[a]))
						{
							break;
						}
						//We cant simply add the two number next to each other, they have different step values.
						//For example, if the polynomial is like this: x^23, the program first needs to read 2
						//Then multiply 2 by 10
						//Then add 20 + 3
						else
						{
							//Ex: Program read 2 before, here it multplying it by 10, and getting 20
							power = power*10;
							//Ex: Program reads 3
							char_to_double = (double)(polynomial[a] - 48);
							//Ex: Program adds 20 and 3
							power = power + char_to_double;
						}
					}
					//Ex: and finally program gets x^23
					conc = powf(conc, power);
				}

				//Program got rid of the powers, and checks the other conditions.
				for(temp=j-1; temp>=0; temp--)
				{
					//Program checks whether it should add or substract this 'x'
					if(polynomial[temp] == '+')
					{
						//With this if, program checks whether there's no digit between 'x' and '+'
						if(polynomial[temp+1] == 'x')
						{
							//That means the first coefficient is actually 1. coe1 is short for coefficient 1
							coe1 = 1;
						}
						break;
					}
					//Does the same thing for minus
					else if(polynomial[temp] == '-')
					{
						if(polynomial[temp+1] == 'x')
						{
							coe1 = 1;
						}
						coe1 = coe1 * (-1);
						break;
					}
					//This time program checks whether the coefficient constant is double. If there's '.', then it's double
					else if(polynomial[temp] == '.')
					{
						//The program started to read polynomial from right to left, so these values are actually after the '.'
						//If coe1 becomes double, it means all the value the program read so far is actually after the '.'
						//So the program attaches the coe1 value to coe2 and divides it by its step value
						coe2 = coe1 / pow(10, (j-temp-1));
						//coe1 is 0 again
						coe1 = 0;
					}
					else
					{
						//Here we collect the coefficient constants but the program reads it by reverse
						//For example if the polynomial is 123x, since the program reads from right to left it will read 3 first
						//Then it should multiply by 10, and then reads 2, and add 30 + 2, then multiply that by 10, gets 320
						//Then it reads 1, and then add 320 + 1, gets 321. We just need to get this number's reverse, 123
						//And i wrote another functon for that
						coe1 = coe1*10;
						char_to_double = (double)(polynomial[temp] - 48);
						coe1 = coe1 + char_to_double;
					}
				}
				//We get the coefficient 1's reverse
				coe1 = reverse(coe1);
				//We add the two coefficients
				coe1 = coe1 + coe2;
				//We multiply x and coefficients
				conc = conc * coe1;
				//Add it to the results
				result = result + conc;
				conc = numbers[k];
				coe1 = 0;
				coe2 = 0;
				power = 0;
			}
		}
		fprintf(fp3, "%f\n", result);
		result = 0;
	}
}

int reverse(int num)
{
	int i, j, len=0, result=0;

	i=num;
	while(i!=0)
	{
		i = i/10;
		len++;
	}

	for(i=len-1; i>=0; i--)
	{
		j = num%10;
		num = num/10;
		j = j * pow(10, i);
		result = result + j;
	}
	return result;
}
