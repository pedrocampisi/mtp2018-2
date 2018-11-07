/*p4.c*/
/*PedroPauloCampisi*/
/*11811ETE019*/
#include<stdio.h>
int ackermann (int a, int b);
int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n",ackermann(a,b));
}
 int ackermann (int a, int b){
	if(a==0){return b+1;}
  if(a>0 && b==0){return ackermann(a-1,1);}
	if(a>0 && b>0){return ackermann(a-1,ackermann(a,b-1));
}
}
