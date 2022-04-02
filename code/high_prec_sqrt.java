import java.math.BigInteger;

public class high_prec_sqrt {// Main
    public static void main(String[] args) {
        System.out.println(isqrtNewton(new BigInteger("99999")));
    }

    public static BigInteger isqrtNewton(BigInteger n) {
        BigInteger a = BigInteger.ONE.shiftLeft(n.bitLength() / 2);
        boolean p_dec = false;
        for (;;) {
            BigInteger b = n.divide(a).add(a).shiftRight(1);
            if (a.compareTo(b) == 0 || a.compareTo(b) < 0 && p_dec)
                break;
            p_dec = a.compareTo(b) > 0;
            a = b;
        }
        return a;
    }
}