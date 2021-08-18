/**
 * Program to implement bitwise functions
 * Compilation : gcc bitmasking.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 17/8/2021
 * Bits And Bytes Assignment.
 *
 */
#include<stdio.h>

int bitAnd (int x, int y) {
    // every bit which is common in both x and y becomes 0
    int answer = ( ~x ) | ( ~y );
    //every common bit is 0 and rest are 1 so we again find complement of answer and we get common bits
    answer = ( ~answer );
    return answer;
}

int bitXor (int x, int y) {
    //part1 represents all bits which are not set in x and y both
    int part1= ( ~y ) & ( ~x );

    //by doing ~ we remove all those bits which are not set in both x and y 
    part1 = ( ~part1 );

    //find all common bits
    int part2 = ( x & y );

    //changing it to uncommon bits in x and y
    part2=( ~part2 );
    
    //part 1 contains both common bits in x and y and also any bit which is either common in x or in y so
    //doing part1 & part2 removes all those bits which are common in both and only those will be remaining which exist either in x or in y
    
    return (part1 & part2 );
}
int sign(int x)
{
    //double !! is to make any number greater than 1 equal to 1 and zero will remain as it is
    int answer = ((!!x) | (x >> 31));

    //for x >=0  (x>>31) will give 0 ,but for negative numbers it will give -1 with the logic of arithemetic shift of signed numbers
    return answer;
}
int getByte(int x , int n)
{
    //right shift the number x to (n*8) bits
    int shift = ( x >> ( n * 8 )) ;

    //now 0xff is 255 and doing & operation with 0xff we extract 8 bits
    return (shift & ( 0xff));

}
int conditional(int x, int y, int z)
{  
    // (!x) + ~0 will give 0 if x is 0 and -1 if x is any other number except 0
    int checker = ( (!x) + (~0) );
    
    // just simple xor of y and z
    int condition = ( y ^ z );
    
    // if checker is 0 final answer is z else answer is y
    return  ((checker & condition  ) ^ z) ;
}
int logicalShift(int x, int n) {
	
    //arithemetic shifting operator
    int shift1 = (x >> n) ;
    
    //we will use it to convert arithemetic operator to logical operator
    int shift2 = ~(((1 << 31) >> n) << 1);
    
    //doing & covert simple arithemetic shift to logical shift
    return ( shift1 & shift2 );
}


int bang(int x)
{ 
    //(((~x + 1) | x) >> 31) will always give 0 for positive number and -1 for every other number
    int answer = (((~x + 1) | x) >> 31) ;
    
    //if positive number answer will be -1 + 1 = 0 and for 0 it will (0 + 1) = 1
    answer += 1;
    return answer;
}

int invert(int x , int p , int n)
{
    
    int answer = (~(~0 << n));
    
    // shifting the 1's group to position p by left shifting the answer by p+1-n
    answer = answer << (p - n);
    
    // inverting the bits using xor operator
    return (x ^ answer);
}



int main()
{
    printf("BitAnd of 6 and 5 : %d\n",bitAnd(6,5));
    printf("BitXor of 4 and 5 : %d\n",bitXor(4,5));
    printf("Sign(130) = %d \nSign(-23) = %d\n",sign(130),sign(-23));
    printf("getByte(0x12345678, 1) = 0x%x\n",getByte(0x12345678, 1));
    printf("conditional (2, 4, 5) = %d\n",conditional(2, 4, 5));
    printf("bang(3) = %d \nbang(0) = %d\n", bang(3),bang(0));
    printf("logicalShift(0x87654321, 4) = 0x%x\n",logicalShift(0x87654321, 4));
    printf("invert (10, 3, 2) = %d\n",invert(10, 3, 2));
}
