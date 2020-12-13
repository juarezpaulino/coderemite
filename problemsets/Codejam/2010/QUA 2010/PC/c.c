#include <stdio.h>

struct t{
	unsigned long long int soma;
	int next;
}vet[1000];

unsigned long long int v[1000], k, R, euros,aux;
int N;

int main(void)
{
	int t,inst,i,j,p;
	scanf("%d",&t);
	for(inst=1;inst<=t;inst++){
		
		scanf("%llu %llu %d",&R, &k, &N);
		
		for(i=0;i<N;i++) scanf("%llu",&v[i]);
		
		for(i=0;i<N;i++) {
			j=i+1; if(j>=N) j =0;
			vet[i].soma = v[i];
			while(v[j]+vet[i].soma <= k && j != i) {
				vet[i].soma+= v[j];
				j++; if(j>=N) j=0;
			}
			vet[i].next = j;
		}
		
		euros = i = 0;
		while(R--){
			euros += vet[i].soma;
			i = vet[i].next;
		}
		printf("Case #%d: %llu\n",inst,euros);
	}
	return 0;
}
