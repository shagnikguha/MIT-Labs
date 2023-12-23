import java.util.*;

class Num{
    String n;
    Num(String n){
        this.n = n;
    }
    
    String punctuate(){
        int len = n.length();
        StringBuilder newSen = new StringBuilder();
        for(int i=len-1, c =0; i>=0; i--,c++){
            if(c!=0&&(i+1)%3==0){
                newSen.append(",");
            }
            newSen.append(n.charAt(len-1-i)); 
        }
        //newSen.reverse();
        return newSen.toString();
    }
}

class NumberP{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number string:");
        String num = sc.nextLine();
        Num obj = new Num(num);
        System.out.println(obj.punctuate());
        sc.close();
    }
}
