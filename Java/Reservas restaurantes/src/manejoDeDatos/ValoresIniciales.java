package manejoDeDatos;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.JDOMException;
import org.jdom2.input.SAXBuilder;
import org.jdom2.output.Format;
import org.jdom2.output.XMLOutputter;


public class ValoresIniciales {
    
    public ValoresIniciales(){}
    
    /**
     * se encarga de generar un XML
     * @param documento 
     */
    public void generarXml(Document documento){
        XMLOutputter out = new XMLOutputter();
        out.setFormat(Format.getPrettyFormat());//Formato para el archivo XML
        try {
            out.output(documento,new FileWriter("DatosGenerales.xml"));
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    /**
     * Modica los datos de valores iniales en el XML DatosGenerales.xml
     * @param pNombre
     * @param pEslogan
     * @param pTelefono
     * @param pCedulaJuridica
     * @param pHorario
     * @return retorna un numero dependiendo del resultado de la operacion
     */
    public int editarValores(String pNombre, String pEslogan, String pTelefono, String pCedulaJuridica ,String pHorario){
        SAXBuilder builder = new SAXBuilder();//Parser para leer del archivo XML
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
            //Nuevos valores agregados
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
    
    /**
     * recoge todos los datos del XML DatosGenerales.xml
     * @return retorna una una ArrayList con todos los datos del XML DatosGenerales.xml
     */
    public ArrayList getDatos(){
         ArrayList datos = new ArrayList();
         SAXBuilder builder = new SAXBuilder();
            File xml = new File("DatosGenerales.xml");
        try {
            Document documento = (Document) builder.build(xml);
            Element local = documento.getRootElement();
            datos.add(local.getAttributeValue("Nombre"));
            datos.add(local.getChildTextTrim("CedulaJuridica"));
            datos.add(local.getChildTextTrim("Eslogan"));
            datos.add(local.getChildTextTrim("Telefono"));
            datos.add(local.getChildTextTrim("Horario"));
            datos.add(local.getChildTextTrim("Contrasena"));
            datos.add(local.getChildTextTrim("Factura"));
            return datos;
        } catch (JDOMException ex) {
            Logger.getLogger(ValoresIniciales.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(ValoresIniciales.class.getName()).log(Level.SEVERE, null, ex);
        }
        return datos;
    }
    
    /**
     * Retorna el indice de la encriptacion de la contraseña
     * @param pContrasena
     * @return el indice de la contraseña
     */
    private int indiceEncriptacion(String pContrasena){
        //Convierte la contraseña a un arreglo de caracteres
        char array[] = pContrasena.toLowerCase().toCharArray();
        int contador = 0;
        //Recorre cada caracter
        for(int i = 0; i < array.length; i++){
            //Compara si es una vocal en minuscula
            if (array[i] == 97 || array[i] == 101 || array[i] == 105  || array[i] == 111 || array[i] == 117){
                contador++;
            }
            //Compara si es una vocal en mayuscula
            else if(array[i] == 65 || array[i] == 69 || array[i] == 73  || array[i] == 79 || array[i] == 85){
                contador++;
            }
            //Compara si es un numero del 0 al 9
            else if(47 < array[i] && array[i] < 58 ){
                contador--;
            }
        }
        return contador;
    }
    
    /**
     * Encripta la contraseña depende al indice
     * @param pContrasena
     * @return la contraseña encriptada
     */
    private String encriptarContrasena(String pContrasena){
        int indice = indiceEncriptacion(pContrasena);
        if (indice == 0) //Si el indice es 0, se le asigna 7 por defecto
            indice = 7;
        //Convierte la contraseña a un arreglo de caracteres
        char array[] = pContrasena.toCharArray();
        //Recorre cada caracter
        for(int i = 0; i < array.length; i++){
            //Le suma el indice en su valor ASCII
            array[i] = (char)(array[i]+(char)indice);   
        }
        return String.valueOf(array);
    }
    
    /**
     * Retorna la contraseña desencriptada
     * @param antiguaContrasena
     * @param pContrasena
     * @return un string con la contraseña desencriptada
     */
    private String desencriptarContrasena(String antiguaContrasena,String pContrasena){
        int indice = indiceEncriptacion(antiguaContrasena);
        if (indice == 0)//Si el indice es 0, se le asigna 7 al indice
            indice = 7;
        char array[] = pContrasena.toCharArray();//Convierte la contraseña a un arreglo de caracteres
        for(int i = 0; i < array.length; i++){
            array[i] = (char)(array[i]-(char)indice);//Le resta el indice a cada cacarcter en su valor ASCII
        }
        return String.valueOf(array);
    }
    
    /**
     * Valida la contraseña introducida por el usuario
     * @param pContrasena
     * @return 1:Si la contraseña es correcta,0:Si es incorrecta
     */
    public int validarContrasena(String pContrasena){
        SAXBuilder builder = new SAXBuilder();//Parser para leer del XML
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();//Elemento raiz del documento
            String contrasena = desencriptarContrasena(pContrasena,local.getChildTextTrim("Contrasena"));
            //Compara la contraseña
            if(contrasena.equals(pContrasena)){
                return 1;
            }
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    /**
     * Retorna la contraseña encriptada del administrador
     * @return un string con la contraseña del administrador encriptada
     */
    public String getContrasena(){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Contrasena");
        }catch(JDOMException | IOException e){}
        return "";
    }
    
    /**
     * busca el numero de la factura en el XML DatosGenerales.xml
     * @return retorna el numero de la factura
     */
    public String getNumeroFact(){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            return local.getChildTextTrim("Factura");
        }catch(JDOMException | IOException e){}
        return "";
    }
    
    /**
     * cambia las contraseñas 
     * @param pContrasena
     * @param nuevaContrasena
     * @return retorna un numero dependiendo del resultado de la operacion
     */
    public int setContrasena(String pContrasena, String nuevaContrasena){
        SAXBuilder builder = new SAXBuilder();//Praser para leer el archuvo XML
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            //Desencripta la contraseña
            String contrasena = desencriptarContrasena(pContrasena,local.getChildTextTrim("Contrasena"));
            //Compara las contraseñas
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
    
    /**
     * se encarga de cambiar el numero de factura por el numero siguiente
     * @param numero 
     */
    public void setFactura(String numero){
        int sig = Integer.valueOf(numero);
        SAXBuilder builder = new SAXBuilder();//Praser para leer el archuvo XML
        File xml = new File("DatosGenerales.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element local = documento.getRootElement();
            local.removeChild("Factura");
            Element factura = new Element("Factura");
            factura.addContent(String.valueOf(sig+1));
            local.addContent(factura);
            generarXml(documento);
        }
        catch(JDOMException | IOException e){
            
        }
    }
}
