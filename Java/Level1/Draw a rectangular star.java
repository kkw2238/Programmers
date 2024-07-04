/*
 *  https://school.programmers.co.kr/learn/courses/30/lessons/12969?language=java
 */

 import java.util.Scanner;

 class Solution {
     public static void main(String[] args) {
         Scanner sc = new Scanner(System.in);
         int a = sc.nextInt();
         int b = sc.nextInt();

         String repeatString = new String("*").repeat(a);

         for(int i = 0; i < b; ++i)
         {
            System.out.println(repeatString);
         }
     }
 }