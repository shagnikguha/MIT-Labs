import myPackages.p1.Max;

import java.util.*;

public class demoMax{
    public static void main(String args[]){
        System.out.println(Max.max(1,2,5));
        System.out.println(Max.max(1.2512f, 1.3512f, 1.5512f));
        int arr[] = {1,2,4,3};
        System.out.println(Max.max(arr));
        int arr1[][] = {{1,2},{3,4}};
        System.out.println(Max.max(arr1));

    }
}
