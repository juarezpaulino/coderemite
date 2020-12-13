/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class A1107 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int q = in.nextInt();
		while (q-- > 0) {
			int n = in.nextInt();
			String a = in.next();
			if (a.length() < 2 || (a.length()==2 &&  a.charAt(0)>=a.charAt(1)))
				System.out.println("NO");
			else
				System.out.println("YES\n2\n" + a.charAt(0) + " " + a.substring(1));
		}
	}

}