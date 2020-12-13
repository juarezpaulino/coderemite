/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A1031 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int w = in.nextInt(), h = in.nextInt(), k = in.nextInt();
		int r = 0;
		for (int i = 1; i <= k; i++, w-=4, h-=4) r += 2*(h+w-2);
		System.out.println(r);
	}
}