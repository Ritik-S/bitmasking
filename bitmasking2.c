/**
 * Program to implement bitwise functions
 * Compilation : gcc bitmasking.c
 * Execution : ./a.out
 *
 * @Ritik Sedana ( 1910990138 )  , 17/8/2021
 * Bits And Bytes Assignment.
 *
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

int maxN=1000;
long long power(int base, int val)
{
    int ans=1;
    for(int i = 1; i <= val ;++i) {
    ans*=base;	
    }
    return ans;
} 
void decoder()
{   //converting base32 to decimal and then from decimal to base64
    char code_32[maxN];
    scanf("%s",code_32);
    
    int base_64[maxN];
    base_64[62]='+';
    base_64[63]='/';
    
    for(int i='A' ; i <='Z' ; i++)
    base_64[i]=i;
    
   
    for(int i=26 ;i < 52; i++)
    base_64[i]=('a' + i-26);
    
   
    for(int i = 52 ; i < 62; i++)
    {	

    base_64[i]=('a' + i-51);
    }
   
    
    
    long long int decode=0;
    int t=0;
    
    char start = 'A',start2 = 26 - '2';
    
    for(int i=strlen(code_32)-1;i>=0;i--)
    {
        if(code_32[i] >= 'A' && code_32[i] <= 'Z')
        {

          decode += power(32, t) * (code_32[i] - start);
          t++;
          continue;
        }
       
        decode += power(32 , t) * (code_32[i] + start2);
        t++;
    }
    
  
    
    char temp[100];
    int idx=0;
    while(decode!=0)
    {
        //converting to base 64
        temp[idx++]=base_64[decode%64];
        decode/=64;
    }
    temp[idx]='\0';
    printf("%s\n",temp);
    
}
int main() {
	int t=1;
	scanf("%d",&t);
	while(t--)
	{
	    decoder();
	}
	return 0;
}
