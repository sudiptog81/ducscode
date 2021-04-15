package pro.ghosh.changecolorvertical;
import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {
    private Button btnRed;
    private Button btnGreen;
    private Button btnBlue;
    private Button btnReset;
    private ConstraintLayout layoutSuperParent;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        layoutSuperParent = (ConstraintLayout) findViewById(R.id.layoutSuperParent);
        btnRed = (Button) findViewById(R.id.btnRed);
        btnGreen = (Button) findViewById(R.id.btnGreen);
        btnBlue = (Button) findViewById(R.id.btnBlue);
        btnReset = (Button) findViewById(R.id.btnReset);
        btnRed.setOnClickListener(this);
        btnGreen.setOnClickListener(this);
        btnBlue.setOnClickListener(this);
        btnReset.setOnClickListener(this);
    }
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnRed:
                layoutSuperParent.setBackgroundColor(Color.RED);
                break;
            case R.id.btnGreen:
                layoutSuperParent.setBackgroundColor(Color.GREEN);
                break;
            case R.id.btnBlue:
                layoutSuperParent.setBackgroundColor(Color.BLUE);
                break;
            case R.id.btnReset:
                layoutSuperParent.setBackgroundColor(Color.TRANSPARENT);
                break;
            default:
                break;
        }
    }
}