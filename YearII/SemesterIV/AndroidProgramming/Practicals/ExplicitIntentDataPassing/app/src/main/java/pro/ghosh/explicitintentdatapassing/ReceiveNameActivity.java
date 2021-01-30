package pro.ghosh.explicitintentdatapassing;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class ReceiveNameActivity extends AppCompatActivity {

    private TextView tvHello;
    private Button btnGoBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_receive_name);
        tvHello = (TextView) findViewById(R.id.tvHello);
        tvHello.setText(
                getString(R.string.hello)
                        + " "
                        + getIntent().getStringExtra("Name")
        );
        btnGoBack = (Button) findViewById(R.id.btnGoBack);
        btnGoBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                onBackPressed();
            }
        });
    }
}