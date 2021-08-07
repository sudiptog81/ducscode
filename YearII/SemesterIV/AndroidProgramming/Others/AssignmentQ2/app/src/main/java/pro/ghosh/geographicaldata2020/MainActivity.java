package pro.ghosh.geographicaldata2020;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private Spinner spinnerState;
    private EditText etPopulation;
    private EditText etLiteracy;
    private EditText etHospitals;
    private EditText etPoverty;
    private Button btnSubmit;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinnerState = (Spinner) findViewById(R.id.spinnerStates);
        etPopulation = (EditText) findViewById(R.id.etPopulation);
        etLiteracy = (EditText) findViewById(R.id.etLiteracy);
        etHospitals = (EditText) findViewById(R.id.etHospitals);
        etPoverty = (EditText) findViewById(R.id.etPoverty);
        btnSubmit = (Button) findViewById(R.id.btnSubmit);

        btnSubmit.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        if (
                etPopulation.getText().toString().trim().equals("") ||
                        etLiteracy.getText().toString().trim().equals("") ||
                        etHospitals.getText().toString().trim().equals("") ||
                        etPoverty.getText().toString().trim().equals("")
        ) {
            Toast.makeText(this, "Failure", Toast.LENGTH_SHORT).show();
            return;
        }

        int population = Integer.parseInt(etPopulation.getText().toString());
        int literacy = Integer.parseInt(etLiteracy.getText().toString().trim());
        int hospitals = Integer.parseInt(etHospitals.getText().toString().trim());
        int poverty = Integer.parseInt(etPoverty.getText().toString().trim());

        if (
                population < 0 ||
                        literacy < 0 ||
                        hospitals < 0 ||
                        poverty < 0
        ) {
            Toast.makeText(this, "Failure", Toast.LENGTH_SHORT).show();
            return;
        }

        new AlertDialog.Builder(this)
                .setTitle("Details")
                .setMessage(
                        "State: " + spinnerState.getSelectedItem().toString() +
                                "\nLiteracy: " + literacy +
                                "\nHospitals/1000: " + hospitals +
                                "\nPoverty Rate: " + poverty
                )
                .create()
                .show();

        return;
    }
}