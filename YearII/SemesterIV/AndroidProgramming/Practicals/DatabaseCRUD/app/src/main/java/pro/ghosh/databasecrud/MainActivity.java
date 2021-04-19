package pro.ghosh.databasecrud;

import android.app.AlertDialog;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import androidx.swiperefreshlayout.widget.SwipeRefreshLayout;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import pro.ghosh.databasecrud.adapters.RVAdapter;
import pro.ghosh.databasecrud.repos.TodoRepository;

public class MainActivity extends AppCompatActivity implements SwipeRefreshLayout.OnRefreshListener {
    private TodoRepository todoRepository;
    private RecyclerView rvTodos;
    private RVAdapter todosAdapter;
    private SwipeRefreshLayout swipeLayout;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        todoRepository = new TodoRepository(this);

        todosAdapter = new RVAdapter(this, todoRepository);

        swipeLayout = (SwipeRefreshLayout) findViewById(R.id.swipeLayout);
        swipeLayout.setOnRefreshListener(this);

        rvTodos = (RecyclerView) findViewById(R.id.rvTodos);
        rvTodos.setAdapter(todosAdapter);
        rvTodos.setLayoutManager(new LinearLayoutManager(this));

        FloatingActionButton fabAdd = (FloatingActionButton) findViewById(R.id.fabAdd);
        fabAdd.setOnClickListener(v -> {
            View layout = getLayoutInflater().inflate(R.layout.dialog_layout, null);
            EditText etNewContent = (EditText) layout.findViewById(R.id.etNewContent);
            AlertDialog dialog = new AlertDialog.Builder(this)
                    .setView(layout)
                    .setTitle("Add New Todo")
                    .setPositiveButton("Save", (_dialog, which) -> {
                        String content = etNewContent.getText().toString().trim();
                        if (content.length() == 0) {
                            Toast.makeText(this, "No Text Entered", Toast.LENGTH_SHORT).show();
                        } else {
                            todoRepository.create(content);
                            loadTodos();
                        }
                    })
                    .setNegativeButton("Cancel", (_dialog, which) -> _dialog.dismiss())
                    .create();
            dialog.show();
        });

        loadTodos();
    }

    @Override
    public void onRefresh() {
        loadTodos();
    }

    private void loadTodos() {
        swipeLayout.setRefreshing(true);
        todosAdapter.setTodos(todoRepository.getAll());
        swipeLayout.setRefreshing(false);
    }
}