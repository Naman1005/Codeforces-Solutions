import java.util.*;
 public class test10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), l = sc.nextInt();
        int arr[] = new int[n];
        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();
        Arrays.sort(arr);
        int max = 0;
        for (int i = 1; i < n; i++)
            if (arr[i] != arr[i - 1])
                max = Math.max(max, arr[i] - arr[i - 1]);
        if(max/2.0 < arr[0] || max/2.0 <l - arr[n-1])
        System.out.println(Math.max(arr[0], l - arr[n-1]));
        else
        System.out.println(max/2.0);
    }
}