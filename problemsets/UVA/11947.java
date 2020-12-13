/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main { 

	public static void main(String[] args) throws IOException {
		int range[][] = {
						{21,1,19,2},
						{20,2,20,3},
						{21,3,20,4},
						{21,4,21,5},
						{22,5,21,6},
						{22,6,22,7},
						{23,7,21,8},
						{22,8,23,9},
						{24,9,23,10},
						{24,10,22,11},
						{23,11,22,12},
						{23,12,31,12},
						{1,1,20,1}};
		String rangeName[] ={	"aquarius",
								"pisces",
								"aries",
								"taurus",
								"gemini",
								"cancer",
								"leo",
								"virgo",
								"libra",
								"scorpio",
								"sagittarius",
								"capricorn",
								"capricorn"
							};
							
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for (int i = 1; i <= T; i++) {
			String S = br.readLine();
			int d = Integer.parseInt(S.substring(2,4)),
				m = Integer.parseInt(S.substring(0,2)),
				y = Integer.parseInt(S.substring(4,8));
			Calendar c = new GregorianCalendar(y,m-1,d);
			c.add(Calendar.WEEK_OF_YEAR, 40);
			d = c.get(Calendar.DAY_OF_MONTH);
			m = c.get(Calendar.MONTH)+1;
			y = c.get(Calendar.YEAR);
			int k = 0;
			while (k < range.length) {
				if ((m==range[k][1]&&d>=range[k][0]) || (m==range[k][3]&&d<=range[k][2])) break;
				k++;
			}
			System.out.printf("%d %02d/%02d/%d %s\n", i, m, d, y, rangeName[k]); 
		}
	}
}
