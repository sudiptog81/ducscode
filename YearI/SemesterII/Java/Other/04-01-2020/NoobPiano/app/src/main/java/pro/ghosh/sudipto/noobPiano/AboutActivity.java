package pro.ghosh.sudipto.noobPiano;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import androidx.appcompat.app.AppCompatActivity;
import androidx.appcompat.widget.Toolbar;
import com.google.android.material.floatingactionbutton.FloatingActionButton;

public class AboutActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_about);
        Toolbar toolbar = findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        Log.d(MainActivity.TAG, "launchAbout: about activity created");

        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.d(MainActivity.TAG, "onClick: mail button clicked");
                startActivity(new Intent(Intent.ACTION_VIEW, Uri.parse("mailto:sudipto@ghosh.pro")));
            }
        });
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
    }

}
