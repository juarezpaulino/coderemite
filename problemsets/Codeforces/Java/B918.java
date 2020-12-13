/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;

public class B918 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt(), m = in.nextInt();
		Map<String,String> H = new HashMap<>();
		while (n-- > 0) {
			String s = in.next(), ip = in.next();
			H.put(ip, s);
		}
		while (m-- > 0) {
			String c = in.next(), ip = in.next().replace(";","");
			System.out.println(c + " " + ip + "; #" + H.get(ip));
		}
	}

}