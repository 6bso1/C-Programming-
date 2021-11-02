#include<stdio.h>
#define p1 0.5
#define p2 20

void main(){
	FILE *fpointer = fopen("input.txt", "r");
	FILE *fp = fopen("output.txt", "w");
	float a, b, sum=0, n, numbers[1000000], x=0, y=0, temp;
	int num=0, i, j=0;

	//With this while loop, the program fills the numbers[] array with the numbers from the input.txt file.//
	while(!feof(fpointer)){
		fscanf(fpointer, "%f", &x);
		temp = x;
		x = y;
		y = temp;
		sum = sum + x;
		num++;

		if(num==1){
			fprintf(fp, "%f ", y);
		}
		else{
			
			a = sum/num;
			b = (sum + y)/(num+1);
			n = y;
			//Here is the contition that ends the current chunk//
			if(!(b > a*(1+p1) || b < a*(1-p1) || a > n*p2 || a < n/p2)){
				fprintf(fp, "%f ", x);
			}
			else{
				//The program writes the average into the output.txt file.//
				fprintf(fp, "average: %f\n", a);
				//Since we will start with a new chunk, we set these values 0 again//
				sum=0;
				num=0;
			}
		}
	}
}