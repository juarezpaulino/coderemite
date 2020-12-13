/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
public class A1060 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		String a = in.next();
		System.out.println(Math.min(a.chars().filter(c->c=='8').count(),n/11));
	}
}