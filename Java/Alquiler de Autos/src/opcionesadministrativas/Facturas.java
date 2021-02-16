package opcionesadministrativas;


//Librerias utilizadas para la lectura y escrituras de XML
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Calendar;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.JDOMException;
import org.jdom2.input.SAXBuilder;
import org.jdom2.output.Format;
import org.jdom2.output.XMLOutputter;

/**
 *Clase encargada de generar las facturas de los alquileres
 * @author Warner Diaz
 */
public class Facturas {
    //Declaracion de objetos de clase
    ValoresDeInicio valores;
    private static Calendar calendario; //Objeto para generar fechas
    
    public Facturas(){
        valores = new ValoresDeInicio();    
        calendario = Calendar.getInstance();
    }
    /**
     * Genera el XML con los datos del objeto especificado
     * @param documento
     */
     public void generarXml(Document documento){
        XMLOutputter out = new XMLOutputter();
        out.setFormat(Format.getPrettyFormat()); //Genera el formato del archivo XML
        try {
            out.output(documento,new FileWriter("facturas.xml")); //Genera el XML
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    /**
     * Genera la informacion de la factura del alquiler
     * @param pPlaca
     * @param pHoras
     * @return informacion de la factura
     */ 
    public String getFactura(String pPlaca,String pHoras){
        String informacion = "";
        informacion+=valores.getNombre(); //Nombre de la empresa
        informacion+="\n";
        informacion+=valores.getEslogan(); //Eslogan de la empresa
        informacion+="\n\n";                
        informacion+="Cédula Jurídica " + valores.getCedulaJuridica();//Cedula juridica de la empresa
        informacion+="\n";
        informacion+="Número de Teléfono " + valores.getTelefono();//Telefono de la empresa
        informacion+="\n";
        informacion+="Horario de Atención "+valores.getHorario();//Horario nde la empresa
        informacion+="\n";
        informacion+="# Factura "+ valores.getFactura();//Numero de factura
        informacion+="\n\n";
        informacion+= "Fecha del alquiler: "+"\t"; //Fecha actual del sistema
        informacion+=String.valueOf(calendario.get(Calendar.DAY_OF_MONTH)+"/"+calendario.get(Calendar.MONTH)+"/"+calendario.get(Calendar.YEAR));
        informacion+="\n";
        informacion+="Monto total del alquiler: "+"\t"; //Monto total del alquiler
        informacion+=String.valueOf(Integer.parseInt(Registro.getTarifa(pPlaca))*Integer.parseInt(pHoras));
        informacion+="\n";
        return informacion;
    }
    /**
     * Genera todas las facturas registradas
     * @return la informacion de la facturas
     */
    public String getFacturas(){
        SAXBuilder builder = new SAXBuilder(); //Parser para leer el XML
        File xml = new File("facturas.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();//Etiqueta raiz del XML
            List facturas = raiz.getChildren("Factura"); //Lista de facturas
            for(int i = 0; i < facturas.size(); i++){ //Itera la lista de facturas
                Element factura = (Element)facturas.get(i);
                //Por cada factura guarda los detalles
                informacion+=factura.getChildTextTrim("ID");
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Fecha");
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Hora");
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Placa");
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Marca");
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Tipo");
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Horas");                
                informacion+="\t";
                informacion+=factura.getChildTextTrim("Monto");
                informacion+="\n";
            }
            
        }catch(JDOMException | IOException e){}
        return informacion;
    }
    /**
     * Guarda la factura en el archivo XML de facturas
     * @param pPlaca
     * @param pMarca
     * @param pTipo
     * @param pMonto
     * @param pHoras 
     */
    public void agregarFactura(String pPlaca,String pMarca, String pTipo, String pMonto, String pHoras){
        String dia = String.valueOf(calendario.get(Calendar.DAY_OF_MONTH));
        String mes = String.valueOf(calendario.get(Calendar.MONTH)); //Fechas actuales del sistema
        String anno = String.valueOf(calendario.get(Calendar.YEAR));
        String horas = String.valueOf(calendario.get(Calendar.HOUR_OF_DAY));
        String minutos = String.valueOf(calendario.get(Calendar.MINUTE));
        String segundos = String.valueOf(calendario.get(Calendar.SECOND));
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("facturas.xml");
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            //Elementos que seran agregados a la factura
            Element factura = new Element("Factura");
            Element id = new Element("ID");
            id.addContent(valores.getFactura());
            factura.addContent(id);
            Element fecha = new Element("Fecha");
            fecha.addContent(dia+"/"+mes+"/"+anno);
            factura.addContent(fecha);
            Element hora = new Element("Hora");
            hora.addContent(horas+":"+minutos+":"+segundos);
            factura.addContent(hora);
            Element placa = new Element("Placa");
            placa.addContent(pPlaca);
            factura.addContent(placa);
            Element marca = new Element("Marca");
            marca.addContent(pMarca);
            factura.addContent(marca);
            Element tipo = new Element("Tipo");
            tipo.addContent(pTipo);
            factura.addContent(tipo);
            Element horasAlquiler = new Element("Horas");
            horasAlquiler.addContent(pHoras);
            factura.addContent(horasAlquiler);
            Element monto = new Element("Monto");
            monto.addContent(pMonto);
            //Nueva factura
            factura.addContent(monto);
            //Agrega la factura al ndo raiz
            raiz.addContent(factura);
            //Lo agrega al XML
            generarXml(documento);
        }catch(JDOMException | IOException e){}
    }
}
