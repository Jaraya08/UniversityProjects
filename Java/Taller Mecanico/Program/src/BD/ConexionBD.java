/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BD;
import java.sql.*;
/**
 *
 * @author Jordan Araya
 */
public class ConexionBD {
    private Connection conectar = null;
    private final String driver = "com.mysql.jdbc.Driver";
    private final String usuario = "root";
    private final String contraseña ="jordanHAL.881992";
    
    /*
        Conexión con la Base de Datos
    */
    public Connection conexion() throws ClassNotFoundException, SQLException{
        Class.forName(driver);
        conectar = DriverManager.getConnection("jdbc:mysql://localhost/bd_tallermecanico",usuario,contraseña);
        return conectar;
    }
}
