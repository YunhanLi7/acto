/*
  ID : daizhao1
  PROG : milk2
  LANG : C++
*/
#include<stdio.h>
#include<iostream>
#include<stdlib.h> 
int milk[5000][2];
int comp(const void *a,const void *b)
{

    return *(int *)a-*(int *)b;
}    
int max(int a,int b)
{
    if(a>b)
      return a;
    else
      return b;
}    
int main()
{
    FILE *fin=fopen("milk2.in","r");
    FILE *fout=fopen("milk2.out","w");
    int n; 
    fscanf(fin,"%d",&n);
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<2;j++)
      {
          fscanf(fin,"%d",&milk[i][j]);
      }  
    qsort(milk,n,sizeof(int)*2,comp);  
    int Continuous=milk[0][1]-milk[0][0],idle=0,one=milk[0][0],two=milk[0][1];
    int flag=0;
    for(i=0;i<n-1;i++)
    {
       if(milk[i+1][0]>two)
       {
           idle=max(idle,milk[i+1][0]-two);
           Continuous=max(Continuous,two-one);
           one=milk[i+1][0];
           two=milk[i+1][1];
       }
       else
       {
           two=max(two,milk[i+1][1]);
       }               
         
    }    
    fprintf(fout,"%d %d\n",Continuous,idle);

    
    return 0;
}    
