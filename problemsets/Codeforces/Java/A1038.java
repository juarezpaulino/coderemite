/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A1038 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt(), min = Integer.MAX_VALUE;
		String a = in.next();
		for (int i = 0; i < k; i++) {
			char c = (char)('A'+i);
			min = Math.min(min, (int)a.chars().filter(x->x==c).count());
		}
		System.out.print(min*k);
	}
}