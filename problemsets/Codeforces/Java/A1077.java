/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A1077 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while (t-->0) {
			long a = in.nextInt(), b = in.nextInt(), k = in.nextInt();
			System.out.println(k/2*(a-b) + k%2*a);
		}
	}
}