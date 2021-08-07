package pro.ghosh.sudipto.javaFXExample;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.text.Text;
import javafx.scene.control.PasswordField;

public class Controller {
    @FXML
    private Text actionTarget;

    @FXML
    private PasswordField passwordTarget;

    @FXML
    protected void handleSubmitButtonAction(ActionEvent event) {
        System.out.println("Password: " + passwordTarget.getText());
        actionTarget.setText("Sign in button pressed");
    }
}
