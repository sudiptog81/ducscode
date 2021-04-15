package pro.ghosh.loginmodule;

import android.content.Intent;
import android.database.sqlite.SQLiteConstraintException;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import pro.ghosh.loginmodule.models.User;
import pro.ghosh.loginmodule.services.UserService;

public class MainActivity extends AppCompatActivity {
    private EditText etEmail;
    private EditText etPassword;
    private Button btnLogin;
    private Button btnRegister;
    private UserService userService;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        userService = UserService.getInstance();
        UserService.initDatabase(this);

        etEmail = (EditText) findViewById(R.id.etEmail);
        etPassword = (EditText) findViewById(R.id.etPassword);
        btnLogin = (Button) findViewById(R.id.btnLogin);
        btnRegister = (Button) findViewById(R.id.btnRegister);

        btnLogin.setOnClickListener(v -> {
            User user = validateCredentials();
            if (user != null) {
                try {
                    userService.login(user);
                    Toast.makeText(this, "Logged In", Toast.LENGTH_SHORT).show();
                    startActivity(new Intent(this, MemberModule.class));
                } catch (IllegalStateException illegalStateException) {
                    Toast.makeText(this, "Invalid E-mail/Password", Toast.LENGTH_SHORT).show();
                } catch (Exception e) {
                    Log.d("TAG", e.getMessage());
                    Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show();
                }
            }
        });

        btnRegister.setOnClickListener(v -> {
            User user = validateCredentials();
            if (user != null) {
                try {
                    userService.register(user);
                    Toast.makeText(this, "Registered", Toast.LENGTH_SHORT).show();
                    startActivity(new Intent(this, MemberModule.class));
                } catch (SQLiteConstraintException sqLiteConstraintException) {
                    Toast.makeText(this, "E-mail Already Used", Toast.LENGTH_SHORT).show();
                } catch (Exception e) {
                    Toast.makeText(this, "Error", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    private User validateCredentials() {
        String email = etEmail.getText().toString().trim();
        String password = etPassword.getText().toString().trim();

        if (email.length() == 0) {
            etEmail.setError("Enter your e-mail address");
            return null;
        }

        if (password.length() == 0) {
            etPassword.setError("Enter your password");
            return null;
        }

        return new User(email, password);
    }
}