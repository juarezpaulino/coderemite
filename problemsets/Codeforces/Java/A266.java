/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
import java.util.stream.IntStream;
public class A266 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String a = in.next();
		int c = 0;
		for (int i = 1; i < n; i++) c += a.charAt(i)==a.charAt(i-1)?1:0;
		System.out.print(c);
	}
}