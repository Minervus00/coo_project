import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class SingletonDatabaseConnection {
    // Single instance of the class
    private static SingletonDatabaseConnection instance;
    // Connection object
    private Connection connection;
    // Database URL
    private String url = "jdbc:sqlite:src/data.db";

    // Private constructor to prevent instantiation from other classes
    private SingletonDatabaseConnection() {
        try {
            Class.forName("org.sqlite.JDBC");
            this.connection = DriverManager.getConnection(url);
        } catch (ClassNotFoundException e) {
            System.out.println("SQLite JDBC Driver not found. Add it to your library path.");
            e.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException("Error connecting to the database", e);
        }
    }

    // Public method to provide access to the instance
    public static SingletonDatabaseConnection getInstance() {
        if (instance == null) {
            synchronized (SingletonDatabaseConnection.class) {
                if (instance == null) {
                    instance = new SingletonDatabaseConnection();
                }
            }
        }
        return instance;
    }

    // Method to get the database connection
    public Connection getConnection() {
        return connection;
    }
}
