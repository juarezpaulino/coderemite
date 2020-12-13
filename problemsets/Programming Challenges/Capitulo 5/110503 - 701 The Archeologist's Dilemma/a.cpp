/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include<iostream>
#include<cstdio>
#include <math.h>
using namespace std;


int main()
{
   
   double n;
   while(cin>>n)
   {
      double i=floor(log10(n));
      double log2=log10((double)2.0);
      for(double j=i+2.0;;j+=1.0)
      {
         double arg1= n;
         double arg2=n+1.0;
         
         
         if(ceil((log10(arg1)+j)/log2)==floor((log10(arg2)+j)/log2))
         {
            printf("%.0lf\n",ceil((log10(arg1)+j)/log2));
            break;
         }
      }   
   }   
   return 0;
} 
