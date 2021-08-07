package pro.ghosh.sudipto.sqlSwing;

public class Student implements Record {
    /**
     * Successful Registration Message
     *
     * @param s SwingView Instance
     * @return String
     */
    public String submit(SwingView s) {
        return s.nameField.getText() + " was registered successfully!";
    }

    /**
     * Successful Deletion Message
     *
     * @param s SwingView Instance
     * @return String
     */
    public String delete(SwingView s) {
        return s.studentList.getSelectedValue() + " was deleted successfully!";
    }

    /**
     * Successful Clearing Message
     *
     * @return String
     */
    public String clear() {
        return "All Students cleared from database!";
    }
}
