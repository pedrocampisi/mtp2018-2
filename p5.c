/*P5.c*/
/*PedroPaulo*/
/*11811ETE019*/
#include <stdio.h>
#include <stdlib.h>
typedef
unsigned long long int
Bytes8;
typedef
struct LCG { Bytes8 a, c, m, rand_max, atual; }
LCG;
void semente(LCG * r, Bytes8 seed) {
// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
// ULL transforma a constante ’int’ em ’unsigned long long int’
r->a = 0x5DEECE66DULL;
r->c = 11ULL;
r->m = (1ULL << 48);
r->rand_max = r->m - 1;
r->atual = seed;
}
Bytes8 lcg_rand(LCG * r) {
r->atual = (r->a * r->atual + r->c) % r->m;
return r->atual;
}
double lcg_rand_01(LCG * r) {
return ((double) lcg_rand(r))/(r->rand_max);
}
void gera_numeros(float * vetor, int tam,
float min, float max, LCG * r) {
int i;
for(i = 0; i < tam; i++)
vetor[i] = (max-min)*lcg_rand_01(r) + min;
}
 float soma(float *inicio_vetor, float *fim_vetor){
 	if(inicio_vetor<fim_vetor){
 		return *inicio_vetor+soma(inicio_vetor+1, fim_vetor);
 		}
 		return 0;
 }
 float produto(float *inicio_vetor, float *fim_vetor){
 	if(inicio_vetor<fim_vetor){
 		return inicio_vetor[0]*(produto(inicio_vetor+1, fim_vetor));
 		}
 		return 1;
 }
int main(){
	LCG random;
	semente(&random,123456); 
	float  vet[50];
	int escolha=0;
	gera_numeros(vet, 50, 0.5, 1.5, &random);
   scanf("%d",&escolha);
   fflush(stdin);
   switch(escolha)   {
   	  case 1:
   	     printf("%f\n",soma(vet, vet+50));
   	  break;
   	  case 2:
   	   printf("%f\n",produto(vet, vet+50));
   	  break;
   	  default:
   	  break;
   }
	return 0;
	}
