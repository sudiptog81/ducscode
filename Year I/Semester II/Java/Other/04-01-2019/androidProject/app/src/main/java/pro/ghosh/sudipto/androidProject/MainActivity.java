package pro.ghosh.sudipto.androidProject;

import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Log.d("debugTag", "activity created");
    }

    @Override
    protected void onStart() {
        super.onStart();
        Log.d("debugTag", "activity started");
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.d("debugTag", "activity resumed");
    }

    @Override
    protected void onPause() {
        super.onPause();
        Log.d("debugTag", "activity paused");
    }

    @Override
    protected void onStop() {
        super.onStop();
        Log.d("debugTag", "activity stopped");
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        Log.d("debugTag", "activity destroyed");
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        Log.d("debugTag", "activity restarted");
    }

    public void clickTap(View view) {
        TextView o = findViewById(R.id.youEnteredTextView);
        TextView t = findViewById(R.id.outputTextView);
        EditText e = findViewById(R.id.editText);
        o.setVisibility(View.VISIBLE);
        t.setTextColor(getColor(R.color.colorPrimary));
        t.setText(e.getText().toString());
        Log.d("debugTag", "text set to " + e.getText().toString());
    }

    public void clickReset(View view) {
        TextView o = findViewById(R.id.youEnteredTextView);
        TextView t = findViewById(R.id.outputTextView);
        EditText e = findViewById(R.id.editText);
        o.setVisibility(View.INVISIBLE);
        e.setText("");
        t.setText("");
        Log.d("debugTag", "text cleared");
    }

    public void clickOpenSite(View view) {
        Log.d("debugTag", "site opened");
        this.startActivity(
                new Intent(Intent.ACTION_VIEW, Uri.parse("https://sudipto.ghosh.pro"))
        );
    }

    public void clickCallMe(View view) {
        Log.d("debugTag", "caller opened");
        this.startActivity(
                new Intent(Intent.ACTION_DIAL, Uri.parse("tel:+918826358310"))
        );
    }
}
