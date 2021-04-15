package pro.ghosh.loginmodule;

import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import pro.ghosh.loginmodule.models.User;
import pro.ghosh.loginmodule.services.UserService;

public class MemberModule extends AppCompatActivity {
    private User user;
    private UserService userService;
    private TextView tvEmail;
    private TextView btnLogout;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_member_module);

        userService = UserService.getInstance();
        user = userService.getUser();

        tvEmail = (TextView) findViewById(R.id.tvEmail);
        btnLogout = (TextView) findViewById(R.id.btnLogout);

        if (user == null) {
            super.finish();
        } else {
            tvEmail.setText(user.email);
        }

        btnLogout.setOnClickListener(v -> {
            userService.logout();
            Toast.makeText(this, "Logged Out", Toast.LENGTH_SHORT).show();
            super.finish();
        });
    }
}