/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#include <stdio.h>
#include <stdlib.h>

int get_int() {
    int ch, i;
    while (((ch = getchar()) == ' ') || (ch == '\n'));
    for (i = 0; ch >= '0' && ch <= '9'; ch = getchar()) i = 10 * i + (ch - '0');
    return i;
}

char out[100000]; int nout;


int main(){
	int n,N,x0,y0,x1,y1;
	int pos,teste=1,i,k;

	for(;;){
        N = get_int(); x0 = get_int(); y0 = get_int(); x1 = get_int(); y1 = get_int();
		if(!N)	break;
		n=2*N-1;

		x1++;y1++;nout = 0;
		printf("Case %d:\n",teste);
		for(i=x0;i<x1;i++,out[nout++]='\n')
			for(k=y0;k<y1;k++){
				pos = abs(i%n-N+1)+abs(k%n-N+1);
				if(pos<N)
					out[nout++] = pos%26+'a';
					else out[nout++]='.';
			}
		out[nout] = 0; printf(out);
		teste++;
	}
	
	return 0;
}
