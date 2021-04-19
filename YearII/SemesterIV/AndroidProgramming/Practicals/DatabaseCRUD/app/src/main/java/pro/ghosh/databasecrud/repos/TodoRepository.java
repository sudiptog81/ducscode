package pro.ghosh.databasecrud.repos;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.UUID;

import pro.ghosh.databasecrud.models.Todo;
import pro.ghosh.databasecrud.services.DBService;

public class TodoRepository {
    private SQLiteDatabase db;
    private DBService dbService;

    public TodoRepository(Context context) {
        this.dbService = DBService.getInstance(context, "todos", 1);
        this.db = this.dbService.getWritableDatabase();
    }

    public boolean create(String content) {
        try {
            ContentValues contentValues = new ContentValues();
            contentValues.put("Id", UUID.randomUUID().toString());
            contentValues.put("Content", content);
            contentValues.put("AddedAt", LocalDateTime.now().toString());
            contentValues.put("IsDone", false);
            db.insert("todos", null, contentValues);
            return true;
        } catch (Exception e) {
            return false;
        }
    }


    public ArrayList<Todo> getAll() {
        ArrayList<Todo> todos = new ArrayList<>();
        Cursor res = db.rawQuery("SELECT * FROM TODOS", null);
        res.moveToFirst();
        while (!res.isAfterLast()) {
            todos.add(
                    new Todo(
                            res.getString(res.getColumnIndex("Id")),
                            res.getString(res.getColumnIndex("Content")),
                            LocalDateTime.parse(res.getString(res.getColumnIndex("AddedAt"))),
                            res.getInt(res.getColumnIndex("IsDone")) > 0
                    )
            );
            res.moveToNext();
        }
        res.close();
        for (Todo todo: todos) {
            Log.d("TODO", todo.toString());
        }
        return todos;
    }

    public Todo get(String id) {
        Cursor res = db.rawQuery("SELECT * FROM TODOS WHERE Id = " + id, null);
        Todo todo = new Todo(
                res.getString(res.getColumnIndex("Id")),
                res.getString(res.getColumnIndex("Content")),
                LocalDateTime.parse(res.getString(res.getColumnIndex("AddedAt"))),
                res.getInt(res.getColumnIndex("IsDone")) > 0
        );
        res.close();
        return todo;
    }

    public void update(String id) {
        db.execSQL("UPDATE TODOS SET IsDone = NOT IsDone WHERE Id = '" + id + "'");
    }

    public void delete(String id) {
        db.execSQL("DELETE FROM TODOS WHERE Id = '" + id + "'");
    }
}
