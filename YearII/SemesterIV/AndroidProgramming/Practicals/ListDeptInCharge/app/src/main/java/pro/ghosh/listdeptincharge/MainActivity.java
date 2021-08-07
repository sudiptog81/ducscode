package pro.ghosh.listdeptincharge;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.RadioButton;
import android.widget.RadioGroup;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.snackbar.Snackbar;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class MainActivity extends AppCompatActivity {

    private ListView lvCourses;
    private HashMap<String, String> coursesMap;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initCourses();
    }

    private void initCourses() {
        lvCourses = (ListView) findViewById(R.id.lvCourses);

        if (coursesMap == null) {
            coursesMap = new HashMap<>();
            coursesMap.put("B. Sc. (Hons.) Computer Science", "Deptt. of CS - Dr. V. S. Dixit");
            coursesMap.put("B. Com. (Hons.)", "Deptt. of Commerce - Dr. Manika Jain");
            coursesMap.put("B. A. (Hons.) Economics", "Deptt. of Economics - Dr. Apra Sinha");
            coursesMap.put("B. Sc. (Hons.) Mathematics", "Deptt. of Mathematics - Dr. Raj Kumar Bhagat");

            String[] keys = coursesMap.keySet().toArray(new String[0]);


            lvCourses.setAdapter(new ArrayAdapter<String>(
                    this, R.layout.list_item, R.id.tvListItem, keys
            ));

            lvCourses.setOnItemClickListener(new AdapterView.OnItemClickListener() {
                @Override
                public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                    Snackbar.make(lvCourses, coursesMap.get(keys[position]), Snackbar.LENGTH_SHORT)
                            .show();
                }
            });
        }
    }
}