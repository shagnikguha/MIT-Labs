import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.FlowPane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class q1 extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Create a Label with the specified text
        Label label = new Label("Welcome to JavaFX programming");

        // Set the text color to Magenta
        label.setTextFill(Color.MAGENTA);

        // Create a FlowPane layout
        FlowPane root = new FlowPane();
        root.getChildren().add(label);

        // Set the horizontal and vertical gap of the FlowPane
        root.setHgap(10); // Set your desired hgap value
        root.setVgap(10); // Set your desired vgap value

        // Create a Scene with the FlowPane as the root
        Scene scene = new Scene(root, 500, 200);

        // Set the title of the Stage
        primaryStage.setTitle("This is the first JavaFX Application");

        // Set the Scene for the Stage
        primaryStage.setScene(scene);

        // Show the Stage
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}

