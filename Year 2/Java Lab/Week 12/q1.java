import java.util.*;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.Pos;
import javafx.scene.canvas.*;

public class q1 extends Application {
	@Override
	public void start(Stage primaryStage) {
		primaryStage.setTitle("Number");
		
		VBox inputPanel = new VBox(10);
		inputPanel.setAlignment(Pos.CENTER);
		
		Label nameLabel = new Label("Enter numbers:");
		TextField number1 = new TextField();
		number1.setEditable(true);
		TextField number2 = new TextField();
		number2.setEditable(true);
		
		Button btn = new Button("Enter");
		
		Canvas canvas = new Canvas(400, 200);
        GraphicsContext gc = canvas.getGraphicsContext2D();
		
		inputPanel.getChildren().addAll(nameLabel, number1, number2, btn, canvas);
		
		btn.setOnAction(w -> {
			try {
                double n1 = Double.parseDouble(number1.getText());
                double n2 = Double.parseDouble(number2.getText());
                display(n1, n2, gc);
            } catch (NumberFormatException ex) {
                System.err.println("Invalid input. Please enter valid numbers.");
            }
		});
		
		Scene scene = new Scene(inputPanel, 400, 300);
        primaryStage.setScene(scene);
		
		primaryStage.show();
	}
	
	public void display(double n1, double n2, GraphicsContext gc){
		double sum = n1 + n2;
		double diff = n1 - n2;
		double mul = n1*n2;
		double div = n1/n2;
		
		gc.clearRect(0 , 0, 400,  200);
		
		gc.fillText("Sum: " + sum, 20, 30);
        gc.fillText("Difference: " + diff, 20, 60);
        gc.fillText("Multiplication: " + mul, 20, 90);
        gc.fillText("Division: " + div, 20, 120);
	}
	

    public static void main(String[] args) {
        launch(args);
    }
}

