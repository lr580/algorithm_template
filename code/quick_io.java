import java.io.*;

public class quick_io {// Main
    static StreamTokenizer scanner = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

    public static int nextInt() throws IOException {// 快约一倍
        scanner.nextToken();
        return (int) scanner.nval;
    }

    public static long nextLong() throws IOException {
        scanner.nextToken();
        return (long) scanner.nval;
    }

    static String next() throws IOException {
        scanner.nextToken();
        return scanner.sval;
    }

    public static void main(String[] args) throws IOException {
        int n = nextInt() / 10;
        for (int i = 0; i < n; ++i) {
            int s = 0;
            for (int j = 0; j < 10; ++j) {
                s += nextInt();
            }
            out.println(s);// 实测快约4倍
        }
        out.close();// 没有的话什么也不输出
    }
}