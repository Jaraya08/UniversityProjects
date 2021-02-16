/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Reportes;

import BD.ConexionBD;
import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperExportManager;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;


/**
 *
 * @author Jordan Araya
 */
public class GenerarReportes {
    ConexionBD ConectarBD = new ConexionBD();
    private Connection Conexion;
    
    /**
     * Genera los Reporte del area de facturacion
     * @param archivo
     * @param nombre
     * @throws ClassNotFoundException
     * @throws SQLException
     * @throws JRException
     * @throws IOException 
     */
    public void CrearReporte(String archivo,String nombre) throws ClassNotFoundException, SQLException, JRException, IOException{
        Conexion = ConectarBD.conexion();
        String rutaReporte="C:\\Users\\Jordan\\Desktop\\1493523555-TC2\\TC2\\Programa\\TallerMecanico\\src\\Reportes\\"+archivo;
        JasperPrint informe = JasperFillManager.fillReport(rutaReporte, null, Conexion);
        String ubicacion ="C:\\Users\\Jordan\\Desktop\\1493523555-TC2\\TC2\\Programa\\TallerMecanico\\src\\Reportes\\"+nombre;
        JasperExportManager.exportReportToPdfFile(informe,ubicacion);
        File factura = new File("C:\\Users\\Jordan\\Desktop\\1493523555-TC2\\TC2\\Programa\\TallerMecanico\\src\\Reportes\\"+nombre);
        Desktop.getDesktop().open(factura.getAbsoluteFile());
    }
   
}
