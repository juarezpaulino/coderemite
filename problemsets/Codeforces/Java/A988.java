/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
import java.util.stream.Collectors;
public class A988 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), k = in.nextInt();
		int[] a = new int[101];
		List<Integer> r = new ArrayList();
		for (int i = 0; i < n && r.size()!=k; i++) {
			int x = in.nextInt();
			if (a[x]++ == 0) r.add(i+1);
		}
		if (r.size()!=k) System.out.println("NO");
		else {
			System.out.println("YES");
			System.out.println(String.join(" ", r.stream().map(Object::toString).collect(Collectors.joining(" "))));
		}
	}
}