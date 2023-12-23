import com.course.structure.Building;
import com.course.structure.School;
import com.course.structure.House;

import java.util.*;

class Pkg_Building {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.print("1. Building only, 2. House, 3. School ");
        int input = sc.nextInt();
        Building b = new Building();
        if (input == 1) {
            b.assign();
            b.display();
        }
        if (input == 2) {
            House h =  new House();
            h.assign();
            h.display();
        }
        if (input == 3) {
            School s = new School();
            s.assign();
            s.display();
        }
    }
}
