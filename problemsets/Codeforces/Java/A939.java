/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
public class A939 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int []a = new int[5005];
		for (int i = 1; i <= n; i++) a[i] = in.nextInt();
		for (int i = 1; i <= n; i++) if (a[a[a[i]]]==i) { System.out.print("YES"); return; }
		System.out.print("NO");
	}
}