/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
public class A1_177 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int [][]a = new int[n][n];
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = in.nextInt();
		int r = 0;
		for (int i = 0; i < n; i++) r += a[i][i]+a[i][n-1-i]+a[n/2][i]+a[i][n/2];
		r -= a[n/2][n/2]*3;
		System.out.println(r);
	}
}
