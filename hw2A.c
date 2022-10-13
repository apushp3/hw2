#include <stdio.h>

/*
 * TODO
 * func: sudoku_ok
 * desc: determines if the given array of 9 integers 
 *   represents a valid "row" in the game of sudoku.
 *
 *   In other words:
 *     each of 1, 2, 3, ..., 9 must appear exactly
 *     once in the array a for it to be valid.
 *
 *   returns 1 if it is valid
 *   returns 0 otherwise.
 *
 *   Note:  we do not have a parameter "n" here because
 *     the length of the array is ALWAYS 9
 */
int sudoku_ok(int a[]) {
    int count[9];
    for(int i = 0; i < 9 ; i++){
        count[i] = 0;
    }
    for(int i = 0; i < 9; i++){
        count[a[i] - 1] = count[a[i] - 1] + 1;
    }
    for(int i = 0; i< 9; i++){
        if(count[i] > 1){
            return 0;
        }
    }
    return 1;
}


/*
 * TODO
 * func: vec_product
 * desc: computes the "vector product" of the given
 *   array so floats a, and b.  The result (a scalar
 *   float) is returned.
 *
 * CLARIFICATION:  the function should compute what is
 *   commonly called a DOT-product or INNER-product.
 *
 *   wikipedia link: 
 *      https://en.wikipedia.org/wiki/Dot_product#Algebraic_definition
 */
float vec_product(float a[], float b[], int n) {
    float sum = 0.0;
    for(int i = 0; i < n; i++){
        sum = sum + (a[i]*b[i]);
    }

    return sum;
}

/*
 * TODO
 * func: has_dups
 * desc: returns 1 if given array a contains at least one
 *   duplicate value.
 *   example:
 *     { 0, 10, -9, 10, 8}  : yes, 10 is  duplicated
 *     { 8, 8, 8, 8, 8}  : yes, 8 is  duplicated
 *     { 0, 10, -9, 15, 8}  : no, there are no duplicates
 */
int has_dups(int a[], int n) {
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(a[i] == a[j]){
                return 1;
            }
        }
    }
    return 0;
}


// DO NOT MOVE OR CHANGE THE LINE BELOW!!
#ifndef FUNCS_ONLY

int main(){
         // you can add testing code here!
         int a[] = {1,2,5,6,7,8,9,4,3};
         int b[] = { 5, 10, -9, -10, -5};
         float vector1[] = {1.0, 3.0, -5.0};
         float vector2[] = {4.0, -2.0, -1.0};
         printf("sudoku %d", sudoku_ok(a));
         printf("\n");
         printf("repeating %d", has_dups(b, 5));
         printf("\n");
         printf("vec product %f", vec_product(vector1, vector2, 3));
         return 0;
}


// DO NOT MOVE OR CHANGE THE LINE BELOW!!
#endif
