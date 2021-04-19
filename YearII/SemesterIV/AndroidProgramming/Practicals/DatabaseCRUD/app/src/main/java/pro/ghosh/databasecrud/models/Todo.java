package pro.ghosh.databasecrud.models;

import java.time.LocalDateTime;
import java.util.Date;

public class Todo {
    private String id;
    private String content;
    private LocalDateTime addedAt;
    private boolean isDone;

    public Todo(String id, String content, LocalDateTime addedAt, boolean isDone) {
        this.id = id;
        this.content = content;
        this.addedAt = addedAt;
        this.isDone = isDone;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getContent() {
        return content;
    }

    public void setContent(String content) {
        this.content = content;
    }

    public LocalDateTime getAddedAt() {
        return addedAt;
    }

    public void setAddedAt(LocalDateTime addedAt) {
        this.addedAt = addedAt;
    }

    public boolean isDone() {
        return isDone;
    }

    public void setDone(boolean done) {
        isDone = done;
    }

    @Override
    public String toString() {
        return "Todo{" +
                "id='" + id + '\'' +
                ", content='" + content + '\'' +
                ", addedAt=" + addedAt +
                ", isDone=" + isDone +
                '}';
    }
}
