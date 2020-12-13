/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;


int main() {

	map<string,int> TZ = {
							{"UTC", 0},
							{"GMT", 0},
							{"BST", 60},
							{"IST", 60},
							{"WET", 0},
							{"WEST", 60},
							{"CET", 60},
							{"CEST", 120},
							{"EET", 120},
							{"EEST", 180},
							{"MSK", 180},
							{"MSD", 240},
							{"AST", -240},
							{"ADT", -180},
							{"NST", -210},
							{"NDT", -150},
							{"EST", -300},
							{"EDT", -240},
							{"CST", -360},
							{"CDT", -300},
							{"MST", -420},
							{"MDT", -360},
							{"PST", -480},
							{"PDT", -420},
							{"HST", -600},
							{"AKST", -540},
							{"AKDT", -480},
							{"AEST", 600},
							{"AEDT", 660},
							{"ACST", 570},
							{"ACDT", 630},
							{"AWST", 480},
						};
	int TT;
	scanf("%d ", &TT);
  	char S[100];
  	while (TT--) {
  		int h, m, t;
  		char sc[100], tg[100], p[100];
  		gets(S);
  		if (*S == 'm') { t = 0; sscanf(S, "%*s %s %s", sc, tg); }
  		else if (*S == 'n') { t = 720; sscanf(S, "%*s %s %s", sc, tg); }
  		else {
  			sscanf(S, "%d:%d %s %s %s", &h, &m, p, sc, tg);
  			h = (h==12)?0:h;
  			t = h*60+m;
  			if (*p == 'p') t += 720;
  		}
  		t += TZ[tg] - TZ[sc];
  		if (t < 0) t += 1440;
  		t %=1440;
//  		cout << t << endl;
  		if (t == 0) puts("midnight");
  		else if (t == 720) puts("noon");
  		else if (t < 720) printf("%d:%02d a.m.\n", t<60?12:t/60, t%60);
  		else { t -= 720; printf("%d:%02d p.m.\n", t<60?12:t/60, t%60); } 
  	}

	return 0;
}