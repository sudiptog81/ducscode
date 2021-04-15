package pro.ghosh.loginmodule;

import android.app.AlertDialog;
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
            new AlertDialog.Builder(this)
                    .setTitle("Logout")
                    .setMessage("Are you sure you want to log out?")
                    .setPositiveButton(android.R.string.ok, (dialog, which) -> logoutUser())
                    .setNegativeButton(android.R.string.cancel, null)
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .show();
        });
    }

    private void logoutUser() {
        userService.logout();
        Toast.makeText(this, "Logged Out", Toast.LENGTH_SHORT).show();
        super.finish();
    }
}