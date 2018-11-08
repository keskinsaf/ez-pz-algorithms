import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    static int countingValleys(int n, String s) {
        int level = 0, ctr = 0;
        for ( char step : s.toCharArray() ){
            if( step == 'D' && level == 0 ){
                ctr++;
            }
            if( step == 'D' )
                level--;
            else if( step == 'U' )
                level++;
        }
        return ctr;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        String s = in.next();
        int result = countingValleys(n, s);
        System.out.println(result);
        in.close();
    }
}
