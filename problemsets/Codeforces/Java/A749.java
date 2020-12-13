/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A749 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		System.out.println(n/2);
		for (int i = 1; i < n/2; i++) System.out.print("2 ");
		System.out.print("23".charAt(n%2));
	}
}