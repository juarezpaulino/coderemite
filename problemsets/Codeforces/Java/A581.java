/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A581 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int a = in.nextInt(), b = in.nextInt();
		if (b < a) {
			a=a^b;
			b=a^b;
			a=a^b;
		}
		System.out.println(a + " " + (b-a)/2);
	}
}