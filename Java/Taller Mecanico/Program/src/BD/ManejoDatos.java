/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BD;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import javax.swing.JTable;

/**
 *
 * @author Jordan Araya
 */
public class ManejoDatos extends Thread {
    ConexionBD conectarBD = new ConexionBD();
    private Connection Conexion;
    private PreparedStatement preparando;
    private Statement st;
    
    /**
     * Recibe una consulta y la ejecuta en la base de datos
     * @param sql
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public void ExecutarConsulta(String sql) throws ClassNotFoundException, SQLException{
        Conexion = conectarBD.conexion();
        preparando = Conexion.prepareStatement(sql);
        preparando.executeUpdate();
        Conexion.close();
    }
    
    /**
     * Llena una tabla con los repuestos incluidos en una reparacion.
     * @param tabla
     * @param IdReparacion
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public void repuestosEnReparaciones(JTable tabla, String IdReparacion) throws ClassNotFoundException, SQLException{
        Conexion = conectarBD.conexion();
        String sql="INSERT INTO repuestosreparacion (IdReparacion,idRepuestos,Cantidad,ManoObra) VALUES(?,?,?,?)";
        preparando = Conexion.prepareStatement(sql);
        for(int i = 0; i<tabla.getRowCount();i++){
            preparando.setString(1,String.valueOf(IdReparacion));
            preparando.setString(2,String.valueOf(tabla.getValueAt(i,0)));
            preparando.setString(3,String.valueOf(tabla.getValueAt(i,3)));
            preparando.setString(4,String.valueOf(tabla.getValueAt(i,4)));
            preparando.executeUpdate();
        }
        Conexion.close();      
    }
    

   
    
    /**
     * 
     * @param dueño
     * @return Retorna el Nombre del Dueño de un Vehiculo
     * @throws SQLException
     * @throws ClassNotFoundException 
     */
    public String duenhoVehiculo(String dueño) throws SQLException, ClassNotFoundException{
        Conexion =conectarBD.conexion();
        String sql = "SELECT Dueño FROM InformacionCliente WHERE CedulaCliente = '"+dueño+"'";
        st = Conexion.createStatement();
        ResultSet resultado = st.executeQuery(sql);
        resultado.next();
        String datos  = resultado.getString("Dueño");
        Conexion.close();
        return datos;
    }
    
    /**
     * 
     * @param matricula
     * @return retorna el Dueño de un vehiculo por su matricula
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public String duenhoMatricula(String matricula) throws ClassNotFoundException, SQLException{
        Conexion = conectarBD.conexion();
        String sql = ""
                + "SELECT Dueño FROM InformacionCliente as I inner join "
                + "Vehiculo as V on I.CedulaCliente = V.CedulaCliente WHERE V.MatriculaVehiculo = '"+matricula+"'";
        st = Conexion.createStatement();
        ResultSet resultado = st.executeQuery(sql);
        resultado.next();
        String datos = resultado.getString("Dueño");
        Conexion.close();
        return datos;
    }
    
    /**
     * 
     * @param cedula
     * @return Retorna el Nombre del Mecanico por su cedula
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public String nonbreMecanico(String cedula) throws ClassNotFoundException, SQLException{
        Conexion = conectarBD.conexion();
        String sql = "SELECT NombreMecanico FROM mecanicos WHERE CedulaMecanico = '"+cedula+"'";
        st = Conexion.createStatement();
        ResultSet resultado = st.executeQuery(sql);
        resultado.next();
        String nombre = resultado.getString("NombreMecanico");
        Conexion.close();
        return nombre;
    }
    
    /**
     * 
     * @param idReparacion
     * @return retorna un arreglo con el nombre del cliente y la placa del vehiculo por el id de la reparacion
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public ArrayList nombrePlaca(int idReparacion) throws ClassNotFoundException, SQLException{
        ArrayList datos = new ArrayList();
        Conexion = conectarBD.conexion();
        String sql = "SELECT V.MatriculaVehiculo,I.Dueño FROM Vehiculo as V inner join reparacion as RE "
                + "on V.MatriculaVehiculo = RE.Matricula inner join InformacionCliente as I on V.CedulaCliente = "
                + " I.CedulaCliente WHERE idReparacion = "+idReparacion;
        st = Conexion.createStatement();
        ResultSet resultado = st.executeQuery(sql);
        resultado.next();
        datos.add(resultado.getString("MatriculaVehiculo"));
        datos.add(resultado.getString("Dueño"));
        Conexion.close();
        return datos;
    }
    
    /**
     * 
     * @param IDRepuesto
     * @return reporta un arreglo con el nombre del repuesto y del precio por el id del repuesto
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public ArrayList nombreprecioRE(int IDRepuesto) throws ClassNotFoundException, SQLException{
        Conexion = conectarBD.conexion();
        ArrayList datos = new ArrayList();
        String sql = "SELECT NombreRepuesto,PrecioRepuesto FROM repuestos WHERE IdRepuesto = "+IDRepuesto;
        st=Conexion.createStatement();
        ResultSet resultado = st.executeQuery(sql);
        resultado.next();
        datos.add(resultado.getString("NombreRepuesto"));
        datos.add(resultado.getString("PrecioRepuesto"));
        Conexion.close();
        return datos;
    }   
    
    /**
     * 
     * @param IDReparacion
     * @return retorna el numero de la factura dependiente el id De la reparacion
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    public String NumeroFactura(String IDReparacion) throws ClassNotFoundException, SQLException{
        Conexion = conectarBD.conexion();
        String sql = "SELECT NumeroFactura FROM facturas WHERE IdReparacion = "+IDReparacion;
        st = Conexion.createStatement();
        ResultSet resultado = st.executeQuery(sql);
        resultado.next();
        String numero = resultado.getString("NumeroFactura");
        Conexion.close();
        return numero;
    }
}