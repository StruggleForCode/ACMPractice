package acm.hdu;

import java.math.BigInteger;
import java.util.Scanner;

public class SumProblem {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
       while(in.hasNext()){
           int n = in.nextInt();
           BigInteger sum = new BigInteger("0");
           for (int i = 1; i <= n; i++){
               BigInteger temp = new BigInteger(String.valueOf(i));
               sum = sum.add(temp);
           }
           System.out.println(sum);
           System.out.println();
       }

    }
}
