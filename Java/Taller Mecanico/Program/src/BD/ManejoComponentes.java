/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BD;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JComboBox;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Jordan Araya
 */
public class ManejoComponentes {
    private Connection Conectar;
    ConexionBD ConectarBD = new ConexionBD();
    private Statement st;
    
    /**
     * Limpiar  la tabla ingresada
     * @param tabla 
     */
    public void limpiarTabla(JTable tabla){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        while(modelo.getRowCount()>0)modelo.removeRow(0);
    }
    
    /**
     * Llenar una tabla con los datos de la consulta 
     * @param tabla
     * @param len
     * @param consulta
     * @return retorna la tabla con los datos de la consulta
     */
    public JTable llenarTablas(JTable tabla,int len,String consulta){
        try {
            DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
            tabla.setModel(modelo);
            String datos[] = new String[len];
            Conectar = ConectarBD.conexion();
            String sql = consulta;
            st = Conectar.createStatement();
            ResultSet resultado = st.executeQuery(sql);
            while (resultado.next()){
                for(int i = 0;i<len;i++){
                    datos[i]=resultado.getString(i+1);
                }
                modelo.addRow(datos);
            }
            return tabla;
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(ManejoComponentes.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(ManejoComponentes.class.getName()).log(Level.SEVERE, null, ex);
        }
        return tabla;

    }
    /**
     * 
     * @param combo
     * @param Consulta
     * @param columna
     * @return retorna una Jcombobox con los datos de la consulta ingresada
     * @throws ClassNotFoundException
     * @throws SQLException 
     */
    
    public JComboBox llenarCombobox(JComboBox combo,String Consulta,String columna) throws ClassNotFoundException, SQLException{
        Conectar = ConectarBD.conexion();
        st = Conectar.createStatement();
        ResultSet resultado = st.executeQuery(Consulta);
        while(resultado.next()){
            combo.addItem(resultado.getString(columna));
        }
        Conectar.close();
        
        return combo;
    }
    /**
     * 
     * @param tabla
     * @param datos
     * @return Llena la tabla de los repuestos por reparacion y la retorna
     */
    public JTable llenarTablaRE(JTable tabla, ArrayList datos){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        tabla.setModel(modelo);
        int len = datos.size();
        String dato[] = new String[len];
        for(int j=0;j<len;j++){
            dato[j]=datos.get(j).toString();         
        }
        modelo.addRow(dato);
        return tabla;
    }
}
