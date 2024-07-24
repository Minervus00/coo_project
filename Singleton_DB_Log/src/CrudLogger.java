import java.io.FileWriter;
import java.io.IOException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class CrudLogger {
    private static final String LOG_FILE = "src/crud_log.txt";
    private static FileWriter fileWriter;

    private CrudLogger() {}

    public static void log(String operation, String tableName) {
        try {
            if (fileWriter == null) {
                fileWriter = new FileWriter(LOG_FILE, true);
            }
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss");
            String logEntry = formatter.format(LocalDateTime.now()) + " - " + operation + " - " + tableName + "\n";
            fileWriter.write(logEntry);
            fileWriter.flush();
        } catch (IOException e) {
            System.err.println(e.getMessage());
        }
    }
}
