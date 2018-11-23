/*P6.c*/
/*PedroPaulo*/
/*11811ETE019*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct {
 	double *x,*y;
 }Pont;
int main(){
	
	int n,m;
	Pont p;
	scanf("%d",&n);
	fflush(stdin);
	p.x = calloc(n,sizeof(double ) );
	p.y= calloc(n,sizeof(double ) );
	for(m=0;m<n;m++){
		p.x [m]= cos(m*2.0*M_PI/(n-1));
        p.y[m] = sin(m*2.0*M_PI/(n-1));
        
	}
	for(m=0;m<n;m++){
	printf("(%.3lf,%.3lf)\n",p.x[m],p.y[m]);
	}
	free(p.x);
	free(p.y);
}
