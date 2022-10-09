import java.io.*;
import java.util.Scanner;

public class ComputeArea {
    public static void main(String args[]) throws IOException {
        // create output file
        File outputFile = new File("java_output.txt");

        // create a file writer class
        FileWriter fw = new FileWriter(outputFile);

        // create a print writer class
        PrintWriter pw = new PrintWriter(fw);

        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.print("Please enter three sides: ");
            String s[] = sc.nextLine().split(" ");
            float[] a;
            a = new float[4];
            for (int i = 0; i < s.length; i++) {
                a[i] = Float.parseFloat(s[i]);
                // System.out.println(a[i]);
            }

            if (a[0] == -1 && a[1] == -1 && a[2] == -1) {
                pw.close();
                System.exit(0);
            } else {
                if (a[0] + a[1] <= a[2] || a[0] + a[2] <= a[1] || a[1] + a[2] <= a[0]) {
                    pw.println("Ilegal input data ( " + a[0] + " , " + a[1] + " , " + a[2] + " )");
                } else {
                    double sum = (a[0] + a[1] + a[2]) / 2d;
                    double area = sum * (sum - a[0]) * (sum - a[1]) * (sum - a[2]);
                    area = Math.sqrt(area);
                    pw.println("The area of the triangle is " + area + "");
                }
            }
        }
    } // end main
} // end of class Add