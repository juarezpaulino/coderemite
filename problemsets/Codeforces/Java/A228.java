/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
import java.util.Arrays;
public class A228 {
	public static void main(String []args) {
		Scanner in = new Scanner(System.in);
		System.out.print(4 - (new HashSet<String>(Arrays.asList(in.nextLine().split(" ")))).size());
	}
}