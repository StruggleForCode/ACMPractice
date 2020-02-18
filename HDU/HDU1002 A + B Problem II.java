package acm.hdu;

import java.math.BigInteger;
import java.util.Scanner;

public class AandBProblemtwo {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        for (int i = 1; i < t; i++) {
            BigInteger a = in.nextBigInteger();
            BigInteger b = in.nextBigInteger();
            System.out.println("Case " + String.valueOf(i) + ":");
            System.out.println(a + " + " + b + " = " + a.add(b));
            System.out.println();
        }
        BigInteger a = in.nextBigInteger();
        BigInteger b = in.nextBigInteger();
        System.out.println("Case " + String.valueOf(t) + ":");
        System.out.println(a + " + " + b + " = " + a.add(b));
    }
}
