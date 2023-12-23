import java.util.*;
interface Series{
    public int getNext();
    public void reset();
    public void setStart(int x);
}
class ByTwos1 implements Series{
    public int interval = 2;
    public int start = 0;

    public int getNext(){
        start += interval;
        return start;
    }

    public void reset(){
        start = 0;
    }

    public void setStart(int x){
        start = x;
    }

}

class ByTwos
{

    public static void main(String args[]){
        ByTwos1 obj = new ByTwos1();
        obj.setStart(2);
        System.out.println(obj.getNext());
        System.out.println(obj.getNext());
        System.out.println(obj.getNext());
        obj.reset();
        System.out.println(obj.getNext());
    }
}
/* Output
4
6
8
2
*/
