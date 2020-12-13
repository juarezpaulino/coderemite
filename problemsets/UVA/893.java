/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;

public class Main { 

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int d = sc.nextInt();
			int D = sc.nextInt(), M = sc.nextInt(), Y = sc.nextInt();
			if (D + d + M + Y == 0) return;
			Calendar c = new GregorianCalendar(Y,M-1,D);
			c.add(Calendar.DAY_OF_MONTH, d);
			System.out.printf("%d %d %d\n", c.get(Calendar.DAY_OF_MONTH), c.get(Calendar.MONTH)+1, c.get(Calendar.YEAR)); 
		}
	}
}
