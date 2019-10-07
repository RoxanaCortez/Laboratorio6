#include <bits/stdc++.h> 
#define NS 4
using namespace std; 
int fe, le;
int fastWay(int a[][NS], int t[][NS], int *e, int *x, int n)  
{ 
	int f1[NS], f2[NS];
	f1[1] = e[1] + a[1][1];  
      
    f2[1] = e[2] + a[2][1];
    
    for (int j = 2; j < n; ++j)  
    { 
	    if (f1[j-1] + a[1][j] <= f2[j-1] + t[2][j-1] + a[1][j])
		{
			f1[j] = f1[j-1] + a[1][j];
			//l[1][j] = 1;	
		}
		else
		{
			f1[j] = f2[j-1] + t[1][j-1] + a[1][j];
			//l[1][j] = 2;
		}
		
		if((f2[j-1]+a[2][j]) <= (f1[j-1]+t[1][j-1]+a[2][j]))
		{
			f2[j] = f2[j-1] + a[2][j];
			//l[1][j] = 2;
		}
		else
		{
			f2[j] = f1[j-1] + t[1][j-1] + a[2][j];
			//l[1][j] = 1;
		}
	}
	
	if( (f1[n] + x[1]) <= (f2[n] + x[2]) )
	{
		fe = f1[n] + x[1];
		//le = 1;
	}	
	else
	{
		fe = f2[n] + x[2];
		//le = 2;
	}

}
