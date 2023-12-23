import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.FlowPane;
import javafx.stage.Stage;

public class q2 extends Application {

    @Override
    public void start(Stage primaryStage) {
        Label promptLabel = new Label("Enter an integer:");
        TextField numberField = new TextField();
        Button generateButton = new Button("Generate Table");
        Label resultLabel = new Label();

        FlowPane root = new FlowPane();
        root.setPadding(new Insets(10));
        root.setHgap(10);
        root.getChildren().addAll(promptLabel, numberField, generateButton, resultLabel);

        generateButton.setOnAction(e -> {
            String input = numberField.getText();
            try {
                int number = Integer.parseInt(input);

                StringBuilder table = new StringBuilder();
                for (int i = 1; i <= 10; i++) {
                    int result = number * i;
                    table.append(number).append(" x ").append(i).append(" = ").append(result).append("\n");
                }

                resultLabel.setText(table.toString());
            } catch (NumberFormatException ex) {
                resultLabel.setText("Please enter a valid integer.");
            }
        });

        Scene scene = new Scene(root, 300, 200);

        primaryStage.setTitle("Multiplication Table Generator");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

