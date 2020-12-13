/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A1017 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), r = 1, v = 0;
		while (n-->0) {
			int a = in.nextInt();
			a += in.nextInt() + in.nextInt() + in.nextInt();
			if (v==0) v = a;
			else if (a > v) r++;
		}
		System.out.println(r);
	}
}