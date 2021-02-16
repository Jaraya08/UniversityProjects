/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Facturacion;

import BD.ConexionBD;
import java.awt.Desktop;
import java.io.File;
import java.io.IOException;
import java.sql.Connection;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;
import net.sf.jasperreports.engine.JRException;
import net.sf.jasperreports.engine.JasperExportManager;
import net.sf.jasperreports.engine.JasperFillManager;
import net.sf.jasperreports.engine.JasperPrint;
import org.jdom2.JDOMException;

/**
 *
 * @author Jordan Araya
 */
public class CrearFactura {
    ConexionBD ConectarBD = new ConexionBD();
    private Connection Conexion;
    
    /**
     * Crea un reporte en pdf con los datos de la factura solicitada
     * @param IDFactura
     * @return retorna el nombre del la factura
     * @throws ClassNotFoundException
     * @throws SQLException
     * @throws JRException 
     */
    public String CrearFactura(int IDFactura) throws ClassNotFoundException, SQLException, JRException{
        Conexion = ConectarBD.conexion();
        Map parametros= new HashMap();
        parametros.put("NoFactura", IDFactura);
        String rutaReporte="C:\\Users\\Jordan\\Desktop\\1493523555-TC2\\TC2\\Programa\\TallerMecanico\\src\\Facturacion\\MachoteFactura.jasper";
        JasperPrint informe = JasperFillManager.fillReport(rutaReporte, parametros, Conexion);
        String nombre = "Factura Numero "+IDFactura+".pdf";
        String ubicacion ="C:\\Users\\Jordan\\Desktop\\1493523555-TC2\\TC2\\Programa\\TallerMecanico\\src\\Facturacion\\"+nombre;
        JasperExportManager.exportReportToPdfFile(informe,ubicacion);   
        return nombre;
    }
    /**
     * Abre una factura de la ubicacion recibida
     * @param nombre
     * @return respuesta 1 o 0 
     * @throws JDOMException
     * @throws IOException 
     */
    public int visualizarFactura(String nombre) throws JDOMException, IOException{
        File factura = new File("C:\\Users\\Jordan\\Desktop\\1493523555-TC2\\TC2\\Programa\\TallerMecanico\\src\\Facturacion\\"+nombre);
        Desktop.getDesktop().open(factura.getAbsoluteFile());
        return 1;
    
    }
}
