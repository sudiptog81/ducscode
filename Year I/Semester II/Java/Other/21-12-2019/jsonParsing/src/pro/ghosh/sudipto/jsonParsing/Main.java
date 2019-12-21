package pro.ghosh.sudipto.jsonParsing;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;

import java.io.*;

public class Main {
    static void writeJSON() {
        JSONObject s = new JSONObject();
        s.put("age", 20);
        s.put("name", "Sudipto");
        s.put("website", "https://sudipto.ghosh.pro");
        s.put("email", "sudipto@ghosh.pro");
        s.put("phone", "918826358310");

        try {
            writeToFile(s.toJSONString(), ".\\resources\\student.json");
            System.out.println("Written to \".\\resources\\student.json\".");
        } catch (IOException e) {
            System.out.println("Could not write JSON to file.");
            System.exit(-1);
        }
    }

    static void readJSON() {
        JSONParser parser = new JSONParser();

        try {
            Object o = parser.parse(readFromFile(".\\resources\\student.json"));
            JSONObject s = (JSONObject) o;
            System.out.println("Age: " + s.get("age"));
            System.out.println("Name: " + s.get("name"));
            System.out.println("Email: " + s.get("email"));
            System.out.println("Phone: " + s.get("phone"));
            System.out.println("Website: " + s.get("website"));
            System.out.println("Successfully Read from \".\\resources\\student.json\".");
        } catch (IOException e) {
            System.out.println("Could not read JSON from file.");
            System.exit(-1);
        } catch (ParseException e) {
            System.out.println("Could not parse JSON from string.");
            System.exit(-1);
        }
    }

    static String readFromFile(String path) throws IOException {
        FileReader reader = new FileReader(path);
        BufferedReader br = new BufferedReader(reader);
        String json = br.readLine();
        br.close();
        return json;
    }

    static void writeToFile(String content, String path) throws IOException {
        checkFolderExists();
        FileWriter writer = new FileWriter(path);
        BufferedWriter bw = new BufferedWriter(writer);
        bw.write(content);
        bw.close();
        writer.close();
    }

    static void checkFolderExists() {
        File folder = new File(".\\resources");
        if (!folder.exists()) {
            folder.mkdir();
        }
    }

    public static void main(String[] args) {
        writeJSON();
        readJSON();
    }
}
