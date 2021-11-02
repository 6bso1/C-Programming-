#include <stdio.h>
#define sample 10
void main()
{
    float x1=0.0, y1=0.0, x2=0.0, y2=0.0, x_temp, y_temp, x, y, x_mid, y_mid, m1, m2, point_x, point_y;
    int i, j=1;

    // With this for loop the user fills the class 1, the program sums each x and y values because we need the averages. //
    for(i=0; i<sample; i++){
        scanf("%f %f", &x_temp, &y_temp);
        x1 = x1 + x_temp;
        y1 = y1 + y_temp;
    }

    // The program finds the x and y components of the average point for class 1. //
    x1 = x1/(float)(sample);
    y1 = y1/(float)(sample);

    // With this for loop the user fills the class 2, the program sums each x and y values because we need the averages. //
    for(i=0; i<sample; i++){
        scanf("%f %f", &x_temp, &y_temp);
        x2 = x2 + x_temp;
        y2 = y2 + y_temp;
    }

    // The program finds the x and y components of the average point for class 2. //
    x2 = x2/(float)(sample);
    y2 = y2/(float)(sample);

    // This is the equation of the line that connects the two average points. //
    y = (x-x2)*(y2-y1)/(x2-x1) + y2;

    // These are the components of the midpoint of the connecting line. //
    x_mid = (x1 + x2)/2;
    y_mid = (y1 + y2)/2;

    // m1 is the slope of the connecting line. //
    m1 = (y2-y1)/(x2-x1);
    if(x2-x1 == 0){
    	m1 = (y2-y1)/0.00001;
    }
    // Since the average line and the separating line are perpendicular to each other, m2 is slope of the separating line: //
    m2 = -1/m1;

    // Since the separating line passes through the midpoint of the connecting line, and its slope is m2, here is its equation: //
    y = m2*(x-x_mid) + y_mid;

    while(j){
    	// The program checks whether the given input is invalid or not. If it is, program quits.//
        if(scanf("%f %f", &point_x, &point_y) == 0){
        	j=0;
        }

        //When we write down the values into seperating line equation, the result will be negative or positive, and maybe zero.//
        //To find out which class the given point applies to, program compares the given point's result with each midpoint's results by multiplying them.//
        //Example: If the given point's and class 1's midpoint's results are both negative, then they belong to the same class, multiplication result will be positive.// 
        else if((m2*(point_x - x_mid) + y_mid - point_y) * (m2*(x1 - x_mid) + y_mid - y1) > 0){
        	
           	printf("Class 1\n");
        }
        
        else if((m2*(point_x - x_mid) + y_mid - point_y) * (m2*(x2- x_mid) + y_mid - y2) > 0){
       
        	printf("Class 2\n");
        }
    }
}