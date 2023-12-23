import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

public class EmployeeInfoApp extends Application {

    public static class Employee {
        private String name;
        private int empID;
        private String designation;
        private double basicPay;
        private double DA;
        private double HRA;
        private double PF;
        private double LIC;
        private double netSalary;

        public Employee(String name, int empID, String designation, double basicPay) {
            this.name = name;
            this.empID = empID;
            this.designation = designation;
            this.basicPay = basicPay;
            this.DA = 0.4 * basicPay; // 40% of basicPay
            this.HRA = 0.15 * basicPay; // 15% of basicPay
            this.PF = 0.12 * basicPay; // 12% of basicPay
            this.LIC = 0; // You can set LIC based on your requirements
            this.netSalary = calculateNetSalary();
        }

        private double calculateNetSalary() {
            // Assuming netSalary is the sum of basicPay, DA, HRA, and LIC, minus PF
            return basicPay + DA + HRA + LIC - PF;
        }

        // Getters and setters for other attributes if needed

        public double getNetSalary() {
            return netSalary;
        }

        @Override
        public String toString() {
            return "Employee{" +
                    "name='" + name + '\'' +
                    ", empID=" + empID +
                    ", designation='" + designation + '\'' +
                    ", basicPay=" + basicPay +
                    ", DA=" + DA +
                    ", HRA=" + HRA +
                    ", PF=" + PF +
                    ", LIC=" + LIC +
                    ", netSalary=" + netSalary +
                    '}';
        }
    }

    @Override
    public void start(Stage primaryStage) {
        Employee employee = new Employee("John Doe", 123, "Software Engineer", 50000);

        GridPane grid = new GridPane();
        grid.setPadding(new Insets(10, 10, 10, 10));
        grid.setVgap(5);
        grid.setHgap(5);

        // Display Employee Information
        grid.add(new Label("Name: "), 0, 0);
        grid.add(new Label(employee.name), 1, 0);

        grid.add(new Label("Employee ID: "), 0, 1);
        grid.add(new Label(String.valueOf(employee.empID)), 1, 1);

        grid.add(new Label("Designation: "), 0, 2);
        grid.add(new Label(employee.designation), 1, 2);

        grid.add(new Label("Basic Pay: "), 0, 3);
        grid.add(new Label(String.valueOf(employee.basicPay)), 1, 3);

        grid.add(new Label("DA: "), 0, 4);
        grid.add(new Label(String.valueOf(employee.DA)), 1, 4);

        grid.add(new Label("HRA: "), 0, 5);
        grid.add(new Label(String.valueOf(employee.HRA)), 1, 5);

        grid.add(new Label("PF: "), 0, 6);
        grid.add(new Label(String.valueOf(employee.PF)), 1, 6);

        grid.add(new Label("LIC: "), 0, 7);
        grid.add(new Label(String.valueOf(employee.LIC)), 1, 7);

        grid.add(new Label("Net Salary: "), 0, 8);
        grid.add(new Label(String.valueOf(employee.getNetSalary())), 1, 8);

        Scene scene = new Scene(grid, 300, 300);
        primaryStage.setTitle("Employee Information");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

