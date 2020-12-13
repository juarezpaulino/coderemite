/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.Scanner;
import java.util.Calendar;
import java.util.GregorianCalendar;
import java.util.Map;
import java.util.HashMap;

public class Main { 

	private static final Map<Integer, String> A;
    static
    {
        A = new HashMap<Integer, String>();
        A.put(0, "January");
        A.put(1, "February");
        A.put(2, "March");
        A.put(3, "April");
        A.put(4, "May");
        A.put(5, "June");
        A.put(6, "July");
        A.put(7, "August");
        A.put(8, "September");
        A.put(9, "October");
        A.put(10, "November");
        A.put(11, "December");
    }

    private static final Map<String, Integer> B;
    static
    {
        B = new HashMap<String, Integer>();
        B.put("January", 0);
        B.put("February", 1);
        B.put("March", 2);
        B.put("April", 3);
        B.put("May", 4);
        B.put("June", 5);
        B.put("July", 6);
        B.put("August", 7);
        B.put("September", 8);
        B.put("October", 9);
        B.put("November", 10);
        B.put("December", 11);
    }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int TT = sc.nextInt();
		for (int tt = 1; tt <= TT; tt++) {
			String s = sc.next();
			String[] p = s.split("-");
			int d = sc.nextInt();
			int D = Integer.parseInt(p[2]), M = B.get(p[1]), Y = Integer.parseInt(p[0]);
			Calendar c = new GregorianCalendar(Y,M,D);
			c.add(Calendar.DAY_OF_MONTH, d);
			System.out.printf("Case %d: %d-%s-%02d\n", tt, c.get(Calendar.YEAR), A.get(c.get(Calendar.MONTH)), c.get(Calendar.DAY_OF_MONTH)); 
		}
	}
}
