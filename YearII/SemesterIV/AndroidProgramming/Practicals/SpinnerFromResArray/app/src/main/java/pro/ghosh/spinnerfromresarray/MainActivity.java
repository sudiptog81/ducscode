package pro.ghosh.spinnerfromresarray;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

public class MainActivity extends AppCompatActivity implements AdapterView.OnItemSelectedListener {

    private Spinner spinner;
    private ImageView ivIcon;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this,
                R.array.icons,
                android.R.layout.simple_spinner_item
        );
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);

        spinner = (Spinner) findViewById(R.id.spIcon);
        spinner.setOnItemSelectedListener(this);
        spinner.setAdapter(adapter);

        ivIcon = (ImageView) findViewById(R.id.ivIcon);
    }


    @Override
    public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
        switch (parent.getItemAtPosition(position).toString()) {
            case "sdg1":
                ivIcon.setImageDrawable(ContextCompat.getDrawable(this, R.drawable.ic_sdg1));
                break;
            case "sdg2":
                ivIcon.setImageDrawable(ContextCompat.getDrawable(this, R.drawable.ic_sdg2));
                break;
            case "sdg5":
                ivIcon.setImageDrawable(ContextCompat.getDrawable(this, R.drawable.ic_sdg5));
                break;
            case "sdg10":
                ivIcon.setImageDrawable(ContextCompat.getDrawable(this, R.drawable.ic_sdg10));
                break;
            default:
                break;
        }
    }

    @Override
    public void onNothingSelected(AdapterView<?> parent) {

    }
}