/**
 *
 * Author:  Juarez Paulino(coderemite)
 * Email: juarez.paulino@gmail.com
 *
 */
import java.util.*;
public class A732 {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int k = in.nextInt(), r = in.nextInt();
		for (int x = 1, t; (t=(k*x)%10)<10 && x<=10; x++) if (t==0 || t==r) {
			System.out.print(x);
			break;
		}
	}
}