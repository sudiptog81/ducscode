package pro.ghosh.databasecrud.services;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import androidx.annotation.Nullable;

public class DBService extends SQLiteOpenHelper {
    private static DBService instance = null;

    public DBService(@Nullable Context context, @Nullable String name, @Nullable SQLiteDatabase.CursorFactory factory, int version) {
        super(context, name, factory, version);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(
                "CREATE TABLE TODOS ("
                        + "Id INT,"
                        + "Content VARCHAR(255),"
                        + "AddedAt DATETIME,"
                        + "IsDone BOOL"
                + ");"
        );
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS TODOS;");
        onCreate(db);
    }

    public static DBService getInstance(Context context, String name, int version) {
        if (instance == null) {
            instance = new DBService(context, name, null, version);
        }
        return instance;
    }
}
