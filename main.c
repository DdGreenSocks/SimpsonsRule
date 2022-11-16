
/**********************************************************************
Name: Deirdre Deeney
Student Number: B00139591

Description: Simpsons Rule, program to find area under a curve.
************************************************************************/

/**********************************************************************
    Header Files
************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**********************************************************************
    Declaring Global Variables
************************************************************************/

int n;              //number of strips
float s;            //width of each strip
float F;            //First ordinate
float L;            //Last ordinate
float sumEven=0;
float sumOdd=0;
float area=0;

void comp_Simpsons();

/**********************************************************************
    Main Function describes to the user what the program will do
     and calls the comp_Simpsons function
************************************************************************/
int main()
{
    printf("Calculate the area underneath a curve using Simpsons Rule \n\n");
    printf("This program will ask the user to input: \n1.the number of strips (n) \n");
    printf("2.the space between each strip (s) \n");
    printf("3.The ordinate length either side of the strip\n");
    printf("\nThe program will then compute the approximate area.\n\n\n");
    comp_Simpsons();


    return 0;
}

/****************************************************************************
    comp_Simpsons Function to calculate the area under a curve based on user
    inputs
*****************************************************************************/

void comp_Simpsons(){

  printf("Please enter the number of strips (MAX 10): \n");
  scanf("%d", &n);

  while(n >= 11){                   //If users inputs strips greater than 10 ask the user to enter value below 10 again.
   printf("Number of strips must be less than or equal 10, please enter again: ");
   scanf("%d", &n);
}


  float *arr = calloc(n, sizeof(int)); // Creating enough space for 'n' integers.


  printf("\nPlease enter a value for s: \n");
  scanf("%f", &s);

  printf("\nEnter the ordinate lengths: \n");

  for (int i = 0; i < n+1; i++){           // add another count as there one more ordinate than the number of strips
    printf("Ordinate Length %d : ", i+1);
    scanf("%f", arr + i);                 // (arr + i) points to the next element
  }

  F= arr[0];                //First element in array
  L= arr[n];                //Last element in array

 // printf("\nF %f : ", F);       //Code to test correct output
 // printf("L %f : ", L);         //Code to test correct output
 // printf("F+L %f : ", F+L);     //Code to test correct output


  for(int j=1; j<n; j++)                //Count array except for 1st & Last position
    {
        if(j%2!=0){                     //Values at even positions of array
        //printf("%f ", arr[j]);        //Code to test correct output
        sumEven = sumEven + arr[j];
        }
        else{                           //Values at even positions of array
        //printf("%f ", arr[j]);        //Code to test correct output
           sumOdd= sumOdd + arr[j];
        }
    }

  //printf("\nSum of Even ");       //Code to test correct output
  //printf("\n%f \n", sumEven);     //Code to test correct output

  //printf("\nSum of Odd ");        //Code to test correct output
  //printf("\n%f \n", sumOdd);      //Code to test correct output

  area= (s/3)*((F+L)+(4*sumEven)+(2*sumOdd));       //Simpsons Rule Formula
  printf("\nAREA =  ");
  printf("\n%.2f \n", area);

  free(arr);                        //Deallocate Dyanamic memory set for the array


}
