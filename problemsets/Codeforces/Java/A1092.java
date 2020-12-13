/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
public class A1092 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while (t-->0) {
			int n = in.nextInt(), b = in.nextInt();
			for (int i = 0; i < n; i++) System.out.print((char)('a'+i%b));
			System.out.println("");
		}
	}
}