/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package manejoDeDatos;

//Imports//
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.pdf.PdfWriter;
import com.itextpdf.text.Paragraph;
import java.awt.Desktop;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * Clase Facturas
 * @author Jordan Araya
 */
public class Facturas {
    ValoresIniciales iniciales = new ValoresIniciales();
    Registro registro = new Registro();
    String numeroFactura;
    
    //Contructor//
    public Facturas(){}
    
    /**
     * 
     * @param Mesa
     * @param Nombre
     * @return retorna un numero si la creación fue exitosa
     * @throws DocumentException
     * @throws FileNotFoundException 
     */
    public int facturar(String Mesa,String Nombre) throws DocumentException, FileNotFoundException{
        int hora, minutos, segundos;
        Document document = new Document();        
        Calendar cal = Calendar.getInstance();
        hora =cal.get(Calendar.HOUR_OF_DAY);
        minutos = cal.get(Calendar.MINUTE);
        segundos = cal.get(Calendar.SECOND);
        Date fecha = new Date( cal.getTimeInMillis() );
        SimpleDateFormat formatoDeFehcha = new SimpleDateFormat("dd/MM/yyyy");
        ArrayList valores = iniciales.getDatos();
        String encabezadoFactura = "Factura Numero: "+valores.get(6)+ "               "
                + "                                           Fecha : "+formatoDeFehcha.format(fecha)+"    Hora :"+hora+":"+minutos+":"+segundos;
        
        String valoresinciales = "\nRazon Social: "+valores.get(0)+"\n"+
                "Cedula juridica: " +valores.get(1)+"\n"+
                "Eslogan : "+valores.get(2)+"\n"+
                "Telefono: "+valores.get(3)+"\n"+
                "Horario: "+valores.get(4)+"\n";
        
        String cliente = " \nNombre De Cliente: "+Nombre;
        ArrayList orden = registro.OrdenMesaSeleccionadaFactura(Mesa);
        String contenido = "\nDetalle de su orden\n";
        int precios = 0;
        for(int i = 0;i<orden.size();i+=3){
            contenido+=("\nPlato: "+orden.get(i)+"        "+"Cantidad: "+orden.get(i+1)+"          "+"Precio :"+orden.get(i+2));
            precios+=Integer.valueOf((String)orden.get(2));
        }
        double impuestoDeVenta = (double)precios*0.13;
        double impuestoDeServicio = (double)precios*0.10;
        double precioTotal = (double)precios+impuestoDeVenta+impuestoDeServicio;
        String totales = "\nPrecio Neto: "+String.valueOf(precios)+"\nImpuesto De venta: "+String.valueOf(impuestoDeVenta)+
                "\nImpuesto de Servicio :"+String.valueOf(impuestoDeServicio)+
                "\nPrecio Final: "+String.valueOf(precioTotal);
        
        PdfWriter.getInstance(document, new FileOutputStream("Factura Numero "+valores.get(6)+".pdf"));
        document.open();
        document.add(new Paragraph(encabezadoFactura));
        document.add(new Paragraph(valoresinciales));
        document.add(new Paragraph(cliente));
        document.add(new Paragraph(contenido));
        document.add(new Paragraph(totales));
        document.close();
        String fact = "Factura Numero "+valores.get(6)+".pdf";
        File factura = new File(fact);
        File ubicacion = factura.getAbsoluteFile();
        try {
            String horas=+hora+":"+minutos+":"+segundos;
            Desktop.getDesktop().open(ubicacion);
            registro.guardarFacturaXML(String.valueOf(valores.get(6)), formatoDeFehcha.format(fecha),horas,String.valueOf(precios),String.valueOf(precioTotal));
            registro.cambiarEstadoDeMesa(Mesa,formatoDeFehcha.format(fecha));
            iniciales.setFactura((String) valores.get(6));
        } catch (IOException ex) {
            Logger.getLogger(Facturas.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return 1;
    }
}
