package myPackages.p1;

import java.util.*;

public class Max{
    public static int max(int x, int y, int z){
        int max = 0;
        if(x>y){
            if(x>z){
                max = x;
            } else{
                max = z;
            }
        } else{
            if(y>z){
                max = y;
            } else{
                max = z;
            }
        }
        return max;
    }

    public static float max(float x, float y, float z){
        float max = 0;
        if(x>y){
            if(x>z){
                max = x;
            } else{
                max = z;
            }
        } else{
            if(y>z){
                max = y;
            } else{
                max = z;
            }
        }
        return max;
    }
    public static int max(int arr[]){
        int max = 0;
        for(int i=0; i<arr.length; i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;
    }
    public static int max(int arr[][]){
        int max = 0;
        for(int i=0; i<arr.length; i++){
            for(int j=0; j<arr[i].length;j++){
                if(arr[i][j]>max){
                    max = arr[i][j];
                }
            }
        }
        return max;
    }
}
