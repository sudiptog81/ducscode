package pro.ghosh.loginmodule.data;

import androidx.room.RoomDatabase;
import androidx.room.Database;

import pro.ghosh.loginmodule.models.User;

@Database(entities = {User.class}, version = 1)
public abstract class UserDatabase extends RoomDatabase {
    public abstract UserDao userDao();
}