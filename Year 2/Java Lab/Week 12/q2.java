import java.util.*;

import javafx.application.Application;
import javafx.application.Platform;
import javafx.stage.Stage;
import javafx.scene.Scene;
import javafx.scene.layout.*;
import javafx.scene.control.*;
import javafx.geometry.Pos;
import javafx.scene.canvas.*;

public class q2 extends Application {

    private CheckBox englishCheckbox;
    private CheckBox spanishCheckbox;
    private CheckBox frenchCheckbox;
    private Canvas canvas;
    private GraphicsContext gc;

    @Override
    public void start(Stage primaryStage) {
        primaryStage.setTitle("Resume Builder");

        VBox root = new VBox(10);

        // Create checkboxes for language skills
        englishCheckbox = new CheckBox("English");
        spanishCheckbox = new CheckBox("Spanish");
        frenchCheckbox = new CheckBox("French");

        // Create a canvas to display resume details
        canvas = new Canvas(400, 200);
        gc = canvas.getGraphicsContext2D();

        Button submitButton = new Button("Submit");

        submitButton.setOnAction(e -> displayResume());

        root.getChildren().addAll(englishCheckbox, spanishCheckbox, frenchCheckbox, submitButton, canvas);

        Scene scene = new Scene(root, 400, 400);

        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public void displayResume() {
        gc.clearRect(0, 0, 400, 200);

        gc.fillText("Resume Details:", 20, 30);
        
        int x = 1;
        
        int y = 60;

        if (englishCheckbox.isSelected()) {
            gc.fillText("Language " + x + ": English", 20, y);
            y += 30;
            x++;
        }

        if (spanishCheckbox.isSelected()) {
            gc.fillText("Language " + x + ": Spanish", 20, y);
            y += 30;
            x++;
        }

        if (frenchCheckbox.isSelected()) {
            gc.fillText("Language " + x  + ": French", 20, y);
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
