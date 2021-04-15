package pro.ghosh.loginmodule.services;

import android.content.Context;

import androidx.room.Room;

import pro.ghosh.loginmodule.data.UserDatabase;
import pro.ghosh.loginmodule.models.User;

public class UserService {
    private User user = null;
    private static UserService instance = null;
    private static UserDatabase database = null;

    public void login(User user) throws IllegalStateException {
        User u = database.userDao().findByEmail(user.email);
        if (!u.password.equalsIgnoreCase(user.password))
            throw new IllegalStateException("Password Mismatch");
        this.user = user;
    }

    public void register(User user) {
        database.userDao().insert(user);
        this.user = user;
    }

    public void logout() {
        this.user = null;
    }

    public User getUser() {
        return user;
    }

    public static UserService getInstance() {
        if (instance == null) {
            instance = new UserService();
        }
        return instance;
    }

    public static void initDatabase(Context ctx) {
        if (database == null) {
            database = Room
                    .databaseBuilder(ctx, UserDatabase.class, "login_module")
                    .allowMainThreadQueries()
                    .build();
        }
    }
}
