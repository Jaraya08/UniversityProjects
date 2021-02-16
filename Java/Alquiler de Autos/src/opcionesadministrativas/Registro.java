
package opcionesadministrativas;

//Librerias utilizadas para la lectura y escritura de archivos XML
import java.util.List;
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
public class Registro {

    
    public Registro() throws Exception{}
    
    /**
     * Genera el archivo XML de vehiculos 
     * @param documento
     */
    public void generarXml(Document documento){
        XMLOutputter out = new XMLOutputter();
        out.setFormat(Format.getPrettyFormat());//Formato del archivo XML
        try {
            out.output(documento,new FileWriter("vehiculos.xml"));
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    /**
     * Agrega un nuevo tipo de vehiculo al archivo XML de vehiculos
     * @param descripcion
     * @param pTipo
     * @param tarifa
     * @return un entero. 1:correcto,-1:requisitos innecesarios
     */
    public int agregarTipoVehiculo(String descripcion, String pTipo, String tarifa){
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            Element tipo = new Element("Tipo");
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){//Itera los tipos de vehiculo
                Element vTipo = (Element)listaTipos.get(i);//No se puede agregar un tipo de vehiculo con una descripcion existente
                if(descripcion.toLowerCase().equals(vTipo.getAttributeValue("Descripcion").toLowerCase())){
                    return -1;
                }
            }
            //Agrega el nuevo tipo al archivo XML
            tipo.setAttribute("Descripcion",descripcion);
            tipo.setAttribute("Tipo", pTipo);
            tipo.setAttribute("Tarifa", tarifa);
            raiz.addContent(tipo);
            generarXml(documento);
            return 1;
        }catch(JDOMException | IOException e){}
        return 0;
    }
    /**
     * Busca si la placa del nuevo auto existe
     * @param pPlaca
     * @return false:Si la placa no existe,true:Si la placa existe
     */
    private boolean validarPlaca(String pPlaca){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document)builder.build(xml);
            Element raiz = documento.getRootElement();
            //Lista de tipos
            List listaTipos = raiz.getChildren("Tipo");
            // Itera los tipos de auto
            for (int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                //Itera los vehiculos
                for (int j = 0; j < vehiculos.size(); j++){
                    //Lista de vehiculos
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara la placa introducida con las placas de los autos existentes
                    if (pPlaca.equals(vehiculo.getChildTextTrim("Placa"))){
                        return true;
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return false;
    }
    /**
     * Agrega un nuevo vehiculo al archivo XML de vehiculos
     * @param pPlaca
     * @param pMarca
     * @param pModelo
     * @param pAnno
     * @param pTipo
     * @return 1:Si se agrego correctamente,0:Si el tipo de vehiculo no se encuentra,-1:Si existe la placa
     */
    public int agregarVehiculo(String pPlaca,String pMarca, String pModelo ,String pAnno, String pTipo){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document)builder.build(xml);
            Element raiz = documento.getRootElement();
            //Lista de tipos de vehiculos
            List listaTipos = raiz.getChildren("Tipo");
            //Itera la lista de tipos de vehiculo
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                //Valida que el tipo existe y que no existe la placa
                if(pTipo.toLowerCase().equals(tipo.getAttributeValue("Tipo").toLowerCase()) && !validarPlaca(pPlaca)){
                    Element vehiculo = new Element("Vehiculo");
                    //Elementos que pertenecen el nuevo vehiculo
                    Element placa = new Element("Placa");
                    placa.addContent(pPlaca);
                    vehiculo.addContent(placa);
                    Element marca = new Element("Marca");
                    marca.addContent(pMarca);
                    vehiculo.addContent(marca);
                    Element modelo = new Element("Modelo");
                    modelo.addContent(pModelo);
                    vehiculo.addContent(modelo);
                    Element anno = new Element("Anno");
                    anno.addContent(pAnno);
                    vehiculo.addContent(anno);
                    Element nTipo = new Element("Tipo");
                    nTipo.addContent(pTipo);
                    vehiculo.addContent(nTipo);
                    Element estado = new Element("Estado");
                    estado.addContent("Disponible");
                    vehiculo.addContent(estado);
                    Element horas = new Element("Horas");
                    horas.addContent("0");
                    vehiculo.addContent(horas);
                    //Agrega el vehiculo al tipo
                    tipo.addContent(vehiculo);
                    //Genera el XML
                    generarXml(documento);
                    return 1;
                }
            }
            if(validarPlaca(pPlaca))
                return -1;
        }catch( JDOMException | IOException e){}
        return 0;
    }
    /**
     * Elimina el tipo de vehiculo especificado
     * @param pTipo
     * @return 1:Si se elimino correctamente,0:Si no se encontró el tipo,-1:Si no se puede eliminar
     */
    public int eliminarTipoVehiculo(String pTipo){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            //Lista de tipos de vehiculos
            List listaTipos = raiz.getChildren("Tipo");
            //Itera los tipos de vehiculos
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                //Compara el tipo especificado con los tipos existentes
                if(pTipo.toLowerCase().equals(tipo.getAttributeValue("Tipo").toLowerCase())){
                    //Lista de vehiculos del tipo
                    List vehiculos = tipo.getChildren();
                    //Compara si tiene vehiculos, en el caso que posea, no se puede eliminar
                    if(vehiculos.size() < 1){                                           
                        raiz.removeContent(tipo);
                        generarXml(documento);
                        return 1;
                    }
                    else{
                        return -1;
                    }
                }
            }
            
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    /**
     * Elimina el vehiculo con la placa especificada
     * @param pPlaca
     * @return 1:Si elimino efectivamente, 0:Si no encuentra la placa, -1: Si el auto esta alquilado
     */
    public int eliminarVehiculo(String pPlaca){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            //Lista de tipos de vehiculo
            List listaTipos = raiz.getChildren("Tipo");
            //Itera los tipos de vehiculos
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                //Lista de vehiculos
                List vehiculos = tipo.getChildren();
                //Itera los vehiculos
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara si la placa existe
                    if(pPlaca.toLowerCase().equals(vehiculo.getChildTextTrim("Placa").toLowerCase())){
                        //Compara si el vehiculo esta disponible, en otro caso no se puede eliminar
                        if("Disponible".equals(vehiculo.getChildTextTrim("Estado"))){
                            tipo.removeContent(vehiculo);
                            generarXml(documento);
                            return 1;
                        }
                        else{
                            return -1;
                        }
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return 0;
    }
    /**
     * Cambia el estado de alquilado a disponible, devuelve el vehiculo
     * @param pPlaca
     * @return 1:Si lo remueve correctamente,0:Si no encuentra el vehiculo,-1:Si el vehiculo no esta alquilado
     * @throws Exception 
     */
    public int devolverVehiculo(String pPlaca)throws Exception{
        SAXBuilder builder = new SAXBuilder();//Parser para leer el XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            //Lista de tipos de vehiculos
            List listaTipos = raiz.getChildren("Tipo");
            //Itera los tipos de vehiculos
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                //Lista de vehiculos
                List vehiculos = tipo.getChildren();
                //Itera la lista de vehiculos
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara la placa especificada con las placas existentes
                    if(pPlaca.toLowerCase().equals(vehiculo.getChildTextTrim("Placa").toLowerCase())){
                        //Verifica que el que vehiculo este alquilado
                        if("Alquilado".equals(vehiculo.getChildTextTrim("Estado"))){
                            //Remueve los valores anteriores
                            vehiculo.removeChild("Estado");
                            vehiculo.removeChild("Horas");
                            //Agrega los nuevos valorex
                            Element estado = new Element("Estado");
                            estado.addContent("Disponible");
                            vehiculo.addContent(estado);
                            Element horas = new Element("Horas");
                            //Pone las horas por defecto en 0
                            horas.addContent("0");
                            vehiculo.addContent(horas);
                            generarXml(documento);
                            return 1;
                            
                        }
                        else{
                            return -1;
                        }
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    /**
     * Retorna la tarifa del tipo de auto especificado
     * @param pPlaca
     * @return la tarifa del tipo especificado
     */
    public static String getTarifa(String pPlaca){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            //Lista de tipos de vehiculos
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                //Lista de vehiculos
                List vehiculos = tipo.getChildren();
                //Itera los vehiculos
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara la placa especificada 
                    if(pPlaca.toLowerCase().equals(vehiculo.getChildTextTrim("Placa").toLowerCase())){
                        //Retorna la tarifa del vehiculo
                        return tipo.getAttributeValue("Tarifa");
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return "";
    }
    
    /**
     * Camnbia el estado del vehiculo disponible a alquilado
     * @param pPlaca
     * @param pHoras
     * @return 1:Si lo alquilo correctamente,0:Si no se encuentra la placa,-1:Si se encuentra alquilado
     * @throws Exception 
     */
    public int alquilarVehiculo(String pPlaca, String pHoras)throws Exception{
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List listaTipos = raiz.getChildren("Tipo");
            //Itera la lista de tipos de vehiculos
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                //Itera la lista de vehiculos
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara la placa especifica con las placas de los autos existentes
                    if(pPlaca.toLowerCase().equals(vehiculo.getChildTextTrim("Placa").toLowerCase())){
                        //Verifica si esta disponible para alquilarlo
                        if("Disponible".equals(vehiculo.getChildTextTrim("Estado"))){
                            //Remmueve los estados anteriores
                            vehiculo.removeChild("Estado");
                            vehiculo.removeChild("Horas");
                            //Agrega los nuevos estados
                            Element estado = new Element("Estado");
                            estado.addContent("Alquilado");
                            vehiculo.addContent(estado);
                            Element horas = new Element("Horas");
                            horas.addContent(pHoras);
                            vehiculo.addContent(horas);
                            generarXml(documento);
                            //Calcula el monto del alquiler
                            String monto = String.valueOf(Integer.parseInt(tipo.getAttributeValue("Tarifa"))*Integer.parseInt(pHoras));
                            //Objeto de la clase factura
                            Facturas factura = new Facturas();
                            //Agrega la nueva factura
                            factura.agregarFactura(pPlaca, vehiculo.getChildTextTrim("Marca"), vehiculo.getChildTextTrim("Tipo"), monto, pHoras);
                            return 1;
                        }
                        else{
                            return -1;
                        }
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return 0;
    }
    /**
     * Retorna los vehiculos encontrados en el filtro por marca
     * @param pMarca
     * @param pEstado
     * @return un string con los vehiculos encontrados
     */
    public String consultaMarca(String pMarca, String pEstado){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el XML
        File xml = new File("vehiculos.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            //Lista de tipos de vehiculos
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                //Itera los vehiculos
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara las marcas y el estado del filtro
                    if(pMarca.toLowerCase().equals(vehiculo.getChildText("Marca").toLowerCase()) && pEstado.toLowerCase().equals(vehiculo.getChildText("Estado").toLowerCase())){
                        informacion+=vehiculo.getChildTextTrim("Placa");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Marca");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Modelo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Anno");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Tipo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Estado");
                        informacion+="\n";
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return informacion;
    }
   /**
    * Realiza una consulta por tipo de vehiculo
    * @param pTipo
    * @param pEstado
    * @return un string con los vehiculos encontrados por el filtro
    */
   public String consultaTipo(String pTipo, String pEstado){
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("vehiculos.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List listaTipos = raiz.getChildren("Tipo");
            //Itera los tipos de vehiculos
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                //Itera los vehiculos
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    //Compara los tipos y el estado del vehiculo |
                    if(pTipo.toLowerCase().equals(vehiculo.getChildTextTrim("Tipo").toLowerCase()) && 
                            pEstado.toLowerCase().equals(vehiculo.getChildTextTrim("Estado").toLowerCase())){
                        informacion+=vehiculo.getChildTextTrim("Placa");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Marca");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Modelo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Anno");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Tipo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Estado");
                        informacion+="\n";
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return informacion;
    }
      /**
       * Retorna todos los vehiculos encontrados por los filtros de busqueda
       * @param pMarca
       * @param pTipo
       * @param pEstado
       * @return 
       */
      public String consultaGlobal(String pMarca, String pTipo, String pEstado){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("vehiculos.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    if(pMarca.toLowerCase().equals(vehiculo.getChildTextTrim("Marca").toLowerCase()) && 
                            pTipo.toLowerCase().equals(vehiculo.getChildTextTrim("Tipo").toLowerCase()) &&
                            pEstado.toLowerCase().equals(vehiculo.getChildTextTrim("Estado").toLowerCase())){
                        informacion+=vehiculo.getChildTextTrim("Placa");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Marca");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Modelo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Anno");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Tipo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Estado");
                        informacion+="\n";
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return informacion;
    }
     
      
   public String consultaEstado(String pEstado){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("vehiculos.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                for(int j = 0; j < vehiculos.size(); j++){                    
                    Element vehiculo = (Element)vehiculos.get(j);
                    if(pEstado.toLowerCase().equals(vehiculo.getChildTextTrim("Estado").toLowerCase())){
                        informacion+=vehiculo.getChildTextTrim("Placa");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Marca");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Modelo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Anno");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Tipo");
                        informacion+="\t";
                        informacion+=vehiculo.getChildTextTrim("Estado");
                        informacion+="\n";
                    }
                }
            }
        }catch(JDOMException | IOException e){}
        return informacion;
    }   
            
    public String consultaVehiculos(){
        SAXBuilder builder = new SAXBuilder();
        File xml = new File("vehiculos.xml");
        String informacion = "";
        try{
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){
                Element tipo = (Element)listaTipos.get(i);
                List vehiculos = tipo.getChildren();
                for(int j = 0; j < vehiculos.size(); j++){
                    Element vehiculo = (Element)vehiculos.get(j);
                    informacion+=vehiculo.getChildTextTrim("Placa");
                    informacion+="\t";
                    informacion+=vehiculo.getChildTextTrim("Marca");
                    informacion+="\t";
                    informacion+=vehiculo.getChildTextTrim("Modelo");
                    informacion+="\t";
                    informacion+=vehiculo.getChildTextTrim("Anno");
                    informacion+="\t";
                    informacion+=vehiculo.getChildTextTrim("Tipo");
                    informacion+="\t";
                    informacion+=vehiculo.getChildTextTrim("Estado");
                    informacion+="\n";
                }
            }
        }catch(JDOMException | IOException e){}
        return informacion;
    }

}