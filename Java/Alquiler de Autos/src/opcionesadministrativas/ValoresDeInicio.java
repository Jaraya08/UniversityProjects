
package opcionesadministrativas;


import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.input.SAXBuilder;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdom2.JDOMException;
import org.jdom2.output.Format;
import org.jdom2.output.XMLOutputter;
/**
 *
 * @author Warner Diaz
 */
public class ValoresDeInicio {
    
    public ValoresDeInicio(){}
    
    public void generarXml(Document doc){
        XMLOutputter out = new XMLOutputter();
        out.setFormat(Format.getPrettyFormat());
        try {
            out.output(doc,new FileWriter("DatosGenerales.xml"));
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public String getNombre(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getAttributeValue("Nombre");
        }catch(JDOMException | IOException e){}
        return "";
    }
    public String getEslogan(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Eslogan");
        }catch(JDOMException | IOException e){}
        return "";
    }
    public String getTelefono(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Telefono");
        }catch(JDOMException | IOException e){}
        return "";
    }
    public String getCedulaJuridica(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("CedulaJuridica");
        }catch(JDOMException | IOException e){}
        return "";
    }
    public String getHorario(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Horario");
        }catch(JDOMException | IOException e){}
        return "";
    }
    
    public String getFactura(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Factura");
        }catch(JDOMException | IOException e){}
        return "";
    }
    
    public String getContrasena(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Contrasena");
        }catch(JDOMException | IOException e){}
        return "";
    }

    private int indiceEncriptacion(String pContrasena){
        char array[] = pContrasena.toLowerCase().toCharArray();
        int contador = 0;
        for(int i = 0; i < array.length; i++){
            if (array[i] == 97 || array[i] == 101 || array[i] == 105  || array[i] == 111 || array[i] == 117){
                contador++;
            }
            else if(array[i] == 65 || array[i] == 69 || array[i] == 73  || array[i] == 79 || array[i] == 85){
                contador++;
            }
            else if(47 < array[i] && array[i] < 58 ){
                contador--;
            }
        }
        return contador;
    }
    
    private String encriptarContrasena(String pContrasena){
        int indice = indiceEncriptacion(pContrasena);
        if (indice == 0)
            indice = 7;
        char array[] = pContrasena.toCharArray();
        for(int i = 0; i < array.length; i++){
            array[i] = (char)(array[i]+(char)indice);   
        }
        return String.valueOf(array);
    }
        
    private String desencriptarContrasena(String antiguaContrasena,String pContrasena){
        int indice = indiceEncriptacion(antiguaContrasena);
        if (indice == 0)
            indice = 7;
        char array[] = pContrasena.toCharArray();
        for(int i = 0; i < array.length; i++){
            array[i] = (char)(array[i]-(char)indice);   
        }
        return String.valueOf(array);
    }
    
    public int setFactura(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            int facturaSecuencial = Integer.parseInt(local.getChildTextTrim("Factura"));
            facturaSecuencial+=1;
            local.removeChild("Factura");
            Element factura = new Element("Factura");
            factura.addContent(String.valueOf(facturaSecuencial));
            local.addContent(factura);
            generarXml(documento);
            return 1;
        }catch(JDOMException | IOException | NumberFormatException e){}
        return 0;
    }
    
    public int validarContrasena(String pContrasena){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            String contrasena = desencriptarContrasena(pContrasena,local.getChildTextTrim("Contrasena"));
            if(contrasena.equals(pContrasena)){
                return 1;
            }
        }catch(JDOMException | IOException e){}
        return 0;
    }
        
    public int setContrasena(String pContrasena, String nuevaContrasena){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            String contrasena = desencriptarContrasena(pContrasena,local.getChildTextTrim("Contrasena"));
            if(contrasena.equals(pContrasena)){
                local.removeChild("Contrasena");
                Element nContrasena = new Element("Contrasena");
                nContrasena.addContent(encriptarContrasena(nuevaContrasena));
                local.addContent(nContrasena);
                generarXml(documento);
                return 1;
            }
            return -1;
            
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    public int editarValores(String pNombre, String pEslogan, String pTelefono, String pCedulaJuridica ,String pHorario){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            local.setAttribute("Nombre", pNombre);
            local.removeChild("Eslogan");
            local.removeChild("Nombre");
            local.removeChild("Telefono");
            local.removeChild("CedulaJuridica");
            local.removeChild("Horario");
            Element eslogan = new Element("Eslogan");
            eslogan.addContent(pEslogan);
            local.addContent(eslogan);
            Element telefono = new Element("Telefono");
            telefono.addContent(pTelefono);
            local.addContent(telefono);
            Element cedulaJuridica = new Element("CedulaJuridica");
            cedulaJuridica.addContent(pCedulaJuridica);
            local.addContent(cedulaJuridica);
            Element horario = new Element("Horario");
            horario.addContent(pHorario);
            local.addContent(horario);
            generarXml(documento);
            return 1;
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    public String valoresIniciales(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("DatosGenerales.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            informacion+=local.getAttributeValue("Nombre");
            informacion+="\t";
            informacion+=local.getChildTextTrim("Eslogan");
            informacion+="\t";
            informacion+=local.getChildTextTrim("Telefono");
            informacion+="\t";
            informacion+=local.getChildTextTrim("CedulaJuridica");
            informacion+="\t";
            informacion+=local.getChildTextTrim("Horario");
            
        }catch(JDOMException | IOException e){}
        return informacion;
    }
    
}
