import java.util.Scanner;
import java.math.BigInteger;
public class Main {
public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger x = scanner.nextBigInteger();
        BigInteger y = scanner.nextBigInteger();
        System.out.println(x.gcd(y));
    }
}