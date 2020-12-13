/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A935 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), ret = 0;
		for (int i = 1; i <= n/2; i++)
			if ((n-i) % i == 0) ret++;
		System.out.println(ret);
	}
}