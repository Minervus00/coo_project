import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

public class Main {
    public static void main(String[] args) {
        SingletonDatabaseConnection dbInstance = SingletonDatabaseConnection.getInstance();
        Connection connection = dbInstance.getConnection();

        createTable(connection);

        insertData(connection, "John", "Doe", 3.4);
        insertData(connection, "Jane", "Doe", 5.7);

        readData(connection);

        updateData(connection, 6.5, 1);

        readData(connection);

//        deleteData(connection, 1);
//        readData(connection);
    }

    public static void createTable(Connection connection) {
        String sql = """
                CREATE TABLE IF NOT EXISTS employes (
                    id integer PRIMARY KEY,
                    nom text NOT NULL,
                    prenom text NOT NULL,
                    salaire real
                );""";

        try (Statement stmt = connection.createStatement()) {
            stmt.execute(sql);
            System.out.println("Table has been created.");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void insertData(Connection connection, String nom, String prenom, double salaire) {
        String sql = "INSERT INTO employes(nom, prenom, salaire) VALUES(?,?,?)";

        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setString(1, nom);
            pstmt.setString(2, prenom);
            pstmt.setDouble(3, salaire);
            pstmt.executeUpdate();
            CrudLogger.log("INSERT", "employes");
            System.out.println("Record has been inserted.");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void readData(Connection connection) {
        String sql = "SELECT id, nom, prenom, salaire FROM employes";

        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                System.out.println(rs.getInt("id") +  "\t" +
                        rs.getString("nom") + "\t" +
                        rs.getString("prenom") + "\t" +
                        rs.getDouble("salaire"));
            }
            CrudLogger.log("READ", "employes");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void updateData(Connection connection, double salaire, int id) {
        String sql = "UPDATE employes SET salaire = ? WHERE id = ?";

        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setDouble(1, salaire);
            pstmt.setInt(2, id);
            pstmt.executeUpdate();
            CrudLogger.log("UPDATE", "employes");
            System.out.println("Record has been updated.");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    public static void deleteData(Connection connection, int id) {
        String sql = "DELETE FROM employes WHERE id = ?";

        try (PreparedStatement pstmt = connection.prepareStatement(sql)) {
            pstmt.setInt(1, id);
            pstmt.executeUpdate();
            CrudLogger.log("DELETE", "employes");
            System.out.println("Record has been deleted.");
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }
}
