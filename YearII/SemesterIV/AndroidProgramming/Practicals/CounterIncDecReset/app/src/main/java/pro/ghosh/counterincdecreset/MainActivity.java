package pro.ghosh.counterincdecreset;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private int counter = 0;
    private Button btnIncrement;
    private Button btnDecrement;
    private Button btnReset;
    private TextView tvCounter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        init();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnIncrement:
                setCounter(counter + 1);
                break;
            case R.id.btnDecrement:
                setCounter(counter - 1);
                break;
            case R.id.btnReset:
                setCounter(0);
                break;
            default:
                break;
        }
    }

    private void init() {
        tvCounter = (TextView) findViewById(R.id.tvCounter);
        btnIncrement = (Button) findViewById(R.id.btnIncrement);
        btnDecrement = (Button) findViewById(R.id.btnDecrement);
        btnReset = (Button) findViewById(R.id.btnReset);
        btnIncrement.setOnClickListener(this);
        btnDecrement.setOnClickListener(this);
        btnReset.setOnClickListener(this);
    }

    private void setCounter(int counter) {
        this.counter = counter;
        tvCounter.setText("" + counter);
    }
}