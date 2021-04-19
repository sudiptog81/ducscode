package pro.ghosh.databasecrud.adapters;

import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import com.google.android.material.card.MaterialCardView;

import java.util.ArrayList;

import pro.ghosh.databasecrud.R;
import pro.ghosh.databasecrud.models.Todo;
import pro.ghosh.databasecrud.repos.TodoRepository;

public class RVAdapter extends RecyclerView.Adapter<RVAdapter.ViewHolder> {
    private final Context ctx;
    private final TodoRepository repository;
    private ArrayList<Todo> todos = new ArrayList<>();

    public RVAdapter(Context context, TodoRepository repository) {
        this.ctx = context;
        this.repository = repository;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater
                .from(parent.getContext())
                .inflate(R.layout.todo_item, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        holder.cvParent.setOnClickListener(v ->
                Log.d("DEBUG", todos.get(position).getId() + " Clicked")
        );
        holder.tvTodoContent.setText(todos.get(position).getContent());
        holder.tvTodoAddedAt.setText(todos.get(position).getAddedAt().toString());
        if (todos.get(position).isDone()) {
            holder.btnTodoAction.setText("Mark as Not Done");
        } else {
            holder.btnTodoAction.setText("Mark as Done");
        }
        holder.btnTodoAction.setOnClickListener(v -> {
            repository.update(todos.get(position).getId());
            Toast.makeText(ctx, "Todo State Toggled", Toast.LENGTH_SHORT).show();
        });
        holder.btnTodoDelete.setOnClickListener(v -> {
            repository.delete(todos.get(position).getId());
            Toast.makeText(ctx, "Todo Deleted", Toast.LENGTH_SHORT).show();
        });
    }

    @Override
    public int getItemCount() {
        return todos.size();
    }

    public void setTodos(ArrayList<Todo> todos) {
        this.todos = todos;
        notifyDataSetChanged();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        private final TextView tvTodoId;
        private final TextView tvTodoContent;
        private final TextView tvTodoAddedAt;
        private final Button btnTodoAction;
        private final Button btnTodoDelete;
        private final MaterialCardView cvParent;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            tvTodoId = itemView.findViewById(R.id.tvTodoId);
            tvTodoContent = itemView.findViewById(R.id.tvTodoContent);
            tvTodoAddedAt = itemView.findViewById(R.id.tvTodoAddedAt);
            btnTodoAction = itemView.findViewById(R.id.btnTodoAction);
            btnTodoDelete = itemView.findViewById(R.id.btnTodoDelete);
            cvParent = itemView.findViewById(R.id.cvParent);
        }
    }
}