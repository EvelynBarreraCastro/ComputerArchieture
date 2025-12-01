// Code translation from MIPS to C Code example so you can run

#include <stdio.h>

        int main () {
            
        int t0 = 10;
        int t1 = 2;
        int v0;

        while (t0 != 0) {

            // storing division in t2
            int t2 = t0 / t1; 
            // storing quotient from t2 --> t3 (mimicking MIPS div + mflo)
            int t3 = t2;

            // updating t1 & t0 values 
            t1 = t1 + t3;
            t0 = t0 - 1; 

            // Used to check what's going inside the loop
            printf("t1 = %d\n", t1);
            printf("Iteration: t0 = %d\n", t0);
            printf("\n");
            
            }

            // stores t1 value into v0 and diplayes final v0 value
            v0 = t1 + 0;
            printf("Final v0 value is ");
            printf("%d\n", v0);

        
            return 0;
        }

