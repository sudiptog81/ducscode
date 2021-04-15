package pro.ghosh.radiogroupincharge;

import android.os.Bundle;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.snackbar.Snackbar;

import java.util.HashMap;

public class MainActivity extends AppCompatActivity {

    private RadioGroup rgCourses;
    private HashMap<String, String> coursesMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initCourses();
    }

    private void initCourses() {
        rgCourses = (RadioGroup) findViewById(R.id.rgCourses);

        if (coursesMap == null) {
            coursesMap = new HashMap<>();
            coursesMap.put("B. Sc. (Hons.) Computer Science", "Dr. V. S. Dixit");
            coursesMap.put("B. Com. (Hons.)", "Dr. Manika Jain");
            coursesMap.put("B. A. (Hons.) Economics", "Dr. Apra Sinha");
            coursesMap.put("B. Sc. (Hons.) Mathematics", "Dr. Raj Kumar Bhagat");

            for (String course : coursesMap.keySet()) {
                RadioButton rButton = new RadioButton(MainActivity.this);
                rButton.setText(course);
                rgCourses.addView(rButton);
            }

            rgCourses.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
                @Override
                public void onCheckedChanged(RadioGroup group, int checkedId) {
                    int checkedRadioButtonId = rgCourses.getCheckedRadioButtonId();
                    RadioButton rButton = (RadioButton) findViewById(checkedRadioButtonId);
                    Snackbar.make(rgCourses, coursesMap.get(rButton.getText()), Snackbar.LENGTH_SHORT)
                            .show();
                }
            });
        }
    }
}