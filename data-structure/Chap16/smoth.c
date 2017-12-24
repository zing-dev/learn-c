/*=============================================================
// 函 数 名：smoth(x,n,y)
// 功能描述：五点三次平滑
// 输入参数：x（输入数据），n（系数个数）、y（平滑后序列）
// 返 回 值：整型数字。计算成功则返回1，否则返回0
//==============================================================*/
#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int smoth(x,n,y)
int n;
double *x,*y;
{
   int i;
   if(n < 5)
   {
	   printf("n should be at least 5.\n");
	   return(0);
   }  		  
   y[0] = (69.0*x[0]+4.0*(x[1]+x[3])-6.0*x[2]-x[4])/70.0;        /* 前两点*/
   y[1] = (2.0*x[0]+27.0*x[1]+12.0*x[2]-8.0*x[3]+2.0*x[4])/35.0;
   for(i=2; i<n-2; i++)                                          /* 中间点*/
	  y[i] = (-3.0*x[i-2]+12.0*x[i-1]+17.0*x[i]+12.0*x[i+1]-3.0*x[i+2])/35.0;
   y[n-2] = (2.0*x[n-5]-8.0*x[n-4]+12.0*x[n-3]+27.0*x[n-2]+2.0*x[n-1])/35.0;
   y[n-1] = (x[n-5]+4.0*x[n-4]-6.0*x[n-3]+4.0*x[n-2]+69.0*x[n-1])/70.0;
   return(1);
}