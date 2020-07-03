import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Arrays;

class A {
    public static void main(String[] args) {
        try {
            System.setIn(new FileInputStream(new File("input.txt")));
            System.setOut(new PrintStream(new File("output.txt")));
        } catch (Exception e) {

        }
        int[] start = { 0, 3, 4, 7, 1 };
        int[] end = { 2, 7, 6, 8, 5 };
        System.out.println(maxOverlapIntervalCount(start, end));
    }

    public static int maxOverlapIntervalCount(int[] start, int[] end) {
        int maxOverlap = 0;
        int currentOverlap = 0;
        Arrays.sort(start);
        Arrays.sort(end);
        int i = 0;
        int j = 0;
        while (i < start.length && j < end.length) {
            int s = start[i];
            int e = end[j];
            if (s < e) {
                currentOverlap++;
                maxOverlap = Math.max(maxOverlap, currentOverlap);
                i++;
            } else {
                currentOverlap--;
                j++;
            }
        }
        return maxOverlap;
    }
}