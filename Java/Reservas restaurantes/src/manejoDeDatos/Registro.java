package manejoDeDatos;

/**
 * Imports
 */
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import org.jdom2.Document;
import org.jdom2.Element;
import org.jdom2.JDOMException;
import org.jdom2.input.SAXBuilder;
import org.jdom2.output.Format;
import org.jdom2.output.XMLOutputter;

public class Registro {
    
    public Registro(){}
    
    /**
     * Se encarga de generar el XML con los parametros recibidos
     * @param documento
     * @param nombreXML 
     */
    public void generarXml(Document documento,String nombreXML){
        XMLOutputter out = new XMLOutputter();
        out.setFormat(Format.getPrettyFormat());//Formato del archivo XML
        try {
            out.output(documento,new FileWriter(nombreXML));
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    /**
     * Guarda un tipo de comida en el XML de Comidas
     * @param identificador
     * @param pTipo
     * @return retorna un numero dependiendo del resultado de la operacion
     * @throws Exception 
     */
    public int agregarTipoDeComida(String identificador, String pTipo) throws Exception{
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("Comidas.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            Element tipo = new Element("Tipo");
            List listaTipos = raiz.getChildren("Tipo");
            for(int i = 0; i < listaTipos.size(); i++){
                Element vTipo = (Element)listaTipos.get(i);
                if(pTipo.toLowerCase().equals(vTipo.getAttributeValue("Tipo").toLowerCase())){
                    return -1;
                }
            }
            for(int i = 0; i < listaTipos.size(); i++){
                Element vTipo = (Element)listaTipos.get(i);
                if(identificador.toLowerCase().equals(vTipo.getAttributeValue("identificador").toLowerCase())){
                    return -1;  
                }
            }
            //Agrega el nuevo tipo al archivo XML
            tipo.setAttribute("identificador",identificador);
            tipo.setAttribute("Tipo", pTipo);
            raiz.addContent(tipo);
            generarXml(documento,"Comidas.xml");
            return 1;
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    /**
     * Saca una List de todos los hijos del XML Comidas
     * @return una List con hijos del XML Comidas
     * @throws Exception 
     */
    public List tiposComidas() throws Exception{
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("Comidas.xml");
        Document documento = (Document) builder.build(xml); 
        Element raiz = documento.getRootElement();
        List listaTipos = raiz.getChildren("Tipo");
        return listaTipos;
    }
  
    /**
     * Almacena todos los atributos de un plato de restaurante en el XML de Platos.xml
     * @param sIdentificador
     * @param sNombre
     * @param sDescripcion
     * @param sPrecio
     * @param sImagen
     * @param sTipo
     * @return  retorna un numero dependiendo del resultado de la operacion
     */
    public int comidas(String sIdentificador, String sNombre,String sDescripcion,String sPrecio,String sImagen,String sTipo){
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("Platos.xml"); 
        try {
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            Element platillo = new Element("Platillo");
            List listaNombres = raiz.getChildren("Platillo");
            for(int i = 0; i < listaNombres.size(); i++){//busca nombres de comidas repetidas
                Element vTipo = (Element)listaNombres.get(i);//No se puede agregar un tipo de vehiculo con una descripcion existente
                if(sNombre.toLowerCase().equals(vTipo.getAttributeValue("Nombre").toLowerCase())){
                    return -1;
                }
            }
            for(int i = 0; i < listaNombres.size(); i++){//busca nombres de comidas repetidas
                Element vTipo = (Element)listaNombres.get(i);//No se puede agregar un tipo de vehiculo con una descripcion existente
                if(sIdentificador.toLowerCase().equals(vTipo.getAttributeValue("Identificador").toLowerCase())){
                    return -1;
                }
            }
            platillo.setAttribute("Nombre",sNombre);
            platillo.setAttribute("Identificador",sIdentificador);
            platillo.setAttribute("Descripcion",sDescripcion);
            platillo.setAttribute("Precio",sPrecio);
            platillo.setAttribute("Imagen",sImagen);
            platillo.setAttribute("Tipo",sTipo);
            raiz.addContent(platillo);
            generarXml(documento,"Platos.xml");
            return 1;
            
        } catch (JDOMException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
        return 0;
    }
    
    /**
     * Saca una List con todos los hijos del XML platos
     * @return Una List con todos los hijos del XML platos.xml
     * @throws Exception 
     */
    public List camidas() throws Exception{
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("Platos.xml"); 
        Document documento = (Document) builder.build(xml);
        Element raiz = documento.getRootElement();
        List listaNombres = raiz.getChildren("Platillo");
        return listaNombres;
    }
    
    /**
     * Eliminar del XML Platos.xml un plato anteriomente guardado
     * @param nombrePlato
     * @return retorna un numero dependiento del resultado de la operacion
     */
    public int eliminarComidas(String nombrePlato){
    SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
    File xml = new File("Platos.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaNombres = raiz.getChildren("Platillo");
            for(int i = 0; i < listaNombres.size(); i++){
                Element tipo = (Element)listaNombres.get(i);
                if(nombrePlato.toLowerCase().equals(tipo.getAttributeValue("Nombre").toLowerCase())){
                    raiz.removeContent(tipo);
                    generarXml(documento,"Platos.xml");
                    return 1;
                }
            }
        }catch(JDOMException | IOException e){}
        return 0;
    }
    
    /**
     * Elimina un Tipo de comida del XML Comidas.xml
     * @param tipo
     * @return retorna un numero dependiendo del resultado de la operacion
     */
    public int eliminarTipoComidas(String tipo){
        if(tipo.equals("Combo")){return 2;}
        SAXBuilder builder = new SAXBuilder();//Parser para leer el archivo XML
        File xml = new File("Comidas.xml");
        try {
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaTipo = raiz.getChildren();
            List listaComidas = camidas();
            for(int i = 0;i<listaComidas.size();i++){
                Element platillo = (Element) listaComidas.get(i);
                if(tipo.equals(platillo.getAttributeValue("Tipo"))){
                    return -1;
                }  
            }
            for(int j = 0 ;j<listaTipo.size();j++){
                Element tipoPlato = (Element) listaTipo.get(j);
                if(tipo.equals(tipoPlato.getAttributeValue("Tipo"))){
                    raiz.removeContent(tipoPlato);
                    generarXml(documento, "Comidas.xml");
                    return 1;
                }
            }  
        } catch (Exception ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
        return 0;
    }
    
    
    /**
     * Guarda un pedido en el XML ordenes.xml
     * @param mesa
     * @param listaPedido
     * @return  retorna un numero dependiendo el resultado de la operacion
     */
    public int guardarPedido(int mesa,ArrayList<Object> listaPedido){
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("ordenes.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            Element tipo  = new Element("Orden");
            for(int j=0;j<listaPedido.size();j+=3){
                Element pedido = new Element("Platillo");
                pedido.setAttribute("NombrePlato", (String) listaPedido.get(j));
                pedido.setAttribute("Cantidad", (String) listaPedido.get(j+1));
                pedido.setAttribute("Precio", (String) listaPedido.get(j+2));
                tipo.addContent(pedido); 
            }
            tipo.setAttribute("Estado","Pendiente de pago");
            tipo.setAttribute("Mesa",String.valueOf(mesa));
            raiz.addContent(tipo);
            generarXml(documento,"ordenes.xml");
            return 1;
        }
        catch(JDOMException | IOException e){   
            return 0;
        }
    }
    
    /**
     * verifica las mesas que esta pendientes de pago
     * @param mesa
     * @return retorna un numero dependiendo del resultado de la operacions
     */
    public int verificarMesa(String mesa){
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("ordenes.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaMesa = raiz.getChildren();
            for(int i = 0;i<listaMesa.size();i++){
                Element numeroDeMesa =  (Element) listaMesa.get(i);
                if(numeroDeMesa.getAttributeValue("Mesa").equals(mesa)){
                    if(numeroDeMesa.getAttributeValue("Estado").equals("Pendiente de pago")){
                        return -1;
                    }
                }
            }
            return 1;
            
        }
        catch(JDOMException | IOException e){
            return 0;
        }
    }
    
    /**
     * se encarga de buscar las mesas pendiente de pago un meterlas en una lista
     * @return retorna una ArrayList con las mesas que se encontran pendientes de pago
     * @throws Exception 
     */
    public ArrayList mesasEnpendiente() throws Exception{
            ArrayList mesas = new ArrayList();
            SAXBuilder builder = new SAXBuilder();//Parser del XML
            File xml = new File("ordenes.xml");
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaMesa = raiz.getChildren();
            for(int i = 0;i<listaMesa.size();i++){
                Element numeroDeMesa =  (Element) listaMesa.get(i);
                if(numeroDeMesa.getAttributeValue("Estado").equals("Pendiente de pago")){
                    mesas.add(numeroDeMesa.getAttributeValue("Mesa"));
                    }
                }
            return  mesas;
    }
    
    /**
     * busca la orden una mesa selecionada y mete los datos en una ArrayList
     * @param mesa
     * @return retorna una ArrayList con la lista de todos los platos del pedido
     */
    public ArrayList OrdenMesaSeleccionada(String mesa){
        SAXBuilder builder = new SAXBuilder();
        ArrayList<Object> listaOrden = new ArrayList<>();
        File xml = new File("ordenes.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaMesa = raiz.getChildren();
            for(int i = 0;i<listaMesa.size();i++){
                Element numeroDeMesa =  (Element) listaMesa.get(i);
                if(numeroDeMesa.getAttributeValue("Mesa").equals((Object)mesa)&numeroDeMesa.getAttributeValue("Estado").equals("Pendiente de pago")){
                    List pedido = numeroDeMesa.getChildren("Platillo");
                    for(int j = 0;j<pedido.size();j++){
                        Element nombrePlato = (Element) pedido.get(j);
                        listaOrden.add(nombrePlato.getAttributeValue("NombrePlato"));
                        listaOrden.add(nombrePlato.getAttributeValue("Cantidad"));
                        listaOrden.add(nombrePlato.getAttributeValue("Precio"));    
                    }
                    raiz.removeContent(numeroDeMesa);
                    generarXml(documento,"ordenes.xml");
                    return listaOrden;
                }
            }
            return listaOrden;
        }
        catch(JDOMException | IOException e){
            System.out.println(e);
        }
        return listaOrden;
        
    }
    
    /**
     * se encarga de guarda las facturas pagadas en el XML Facturas.xml
     * @param Factura
     * @param fecha
     * @param hora
     * @param subTotal
     * @param total 
     */
    public void guardarFacturaXML(String Factura,String fecha,String hora,String subTotal,String total){
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("Facturas.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            Element factura = new Element("Factura");
            factura.setAttribute("Factura", Factura);
            factura.setAttribute("Fecha", fecha);
            factura.setAttribute("Hora", hora);
            factura.setAttribute("SubTotal", subTotal);
            factura.setAttribute("Total",total);
            raiz.addContent(factura);
            generarXml(documento,"Facturas.xml");
            
        }
        catch(JDOMException | IOException e){}
    
    }
    
    /**
     * cambia el estado de una mesa de "Pendiente de pago" a "Pagado"
     * @param Mesa
     * @param fecha 
     */
    public void cambiarEstadoDeMesa(String Mesa,String fecha){
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("ordenes.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaMesa = raiz.getChildren();
            for (int i = 0;i<listaMesa.size();i++){
                Element mesa = (Element) listaMesa.get(i);
                if(mesa.getAttributeValue("Mesa").equals(Mesa)){
                    mesa.removeAttribute("Estado");
                    mesa.setAttribute("Estado", "Pagado");
                    mesa.setAttribute("Fecha",fecha);
                    generarXml(documento,"ordenes.xml");
                }
            }  
        }
        catch(JDOMException | IOException e){
            
        }
    
    }
    
    /**
     * ingresa en una ArrayList Todos platos de una orden ( area Facturacion )
     * @param mesa
     * @return retorna una ArrayList con todos los platos de la orden
     */
    public ArrayList OrdenMesaSeleccionadaFactura(String mesa){
        SAXBuilder builder = new SAXBuilder();
        ArrayList<Object> listaOrden = new ArrayList<>();
        File xml = new File("ordenes.xml");
        try{
            Document documento = (Document) builder.build(xml); 
            Element raiz = documento.getRootElement();
            List listaMesa = raiz.getChildren();
            for(int i = 0;i<listaMesa.size();i++){
                Element numeroDeMesa =  (Element) listaMesa.get(i);
                if(numeroDeMesa.getAttributeValue("Mesa").equals((Object)mesa)){
                    List pedido = numeroDeMesa.getChildren("Platillo");
                    for(int j = 0;j<pedido.size();j++){
                        Element nombrePlato = (Element) pedido.get(j);
                        listaOrden.add(nombrePlato.getAttributeValue("NombrePlato"));
                        listaOrden.add(nombrePlato.getAttributeValue("Cantidad"));
                        listaOrden.add(nombrePlato.getAttributeValue("Precio"));    
                    }
                    return listaOrden;
                }
            }
            return listaOrden;
        }
        catch(JDOMException | IOException e){
            System.out.println(e);
        }
        return listaOrden;
    }
    
    /**
     * busca todos los hijos del XML facturas.xml
     * @return retorna una List con todos los hijos del XML Facturas.xml
     * @throws Exception 
     */
    public List facturasListas() throws Exception{
        SAXBuilder builder = new SAXBuilder();//Parser del XML
        File xml = new File("Facturas.xml");
        Document documento = (Document) builder.build(xml); 
        Element raiz = documento.getRootElement();
        List facturas = raiz.getChildren();
        return facturas;
        

    }
    
    /**
     * verifica que el nombre del plato no este asociado a una orden
     * @param dato
     * @return retorna un numer dependiendo del resultado de la operacion
     */
    public int verificarPlato(String dato){
        try {
            SAXBuilder builder = new SAXBuilder();//Parser del XML
            File xml = new File("ordenes.xml");
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List ordenes = raiz.getChildren();
            for(int i = 0;i<ordenes.size();i++){
                Element platillo = (Element) ordenes.get(i);
                List nombrePlatos = platillo.getChildren("Platillo");
                for(int j = 0;j<nombrePlatos.size();j++){
                    Element nombre = (Element) nombrePlatos.get(j);
                    if(nombre.getAttributeValue("NombrePlato").toLowerCase().equals(dato.toLowerCase())){
                        return 0;
                    }  
                }  
            }
            
        } catch (JDOMException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
        return 1;
    }
    
    
    
    /**
     * busca las mesas con estado "Pendiente de pago"
     * @return retorna la cantidad de mesas con estado "Pendentte de pago"
     */
    public int cantidadOrdenesPen(){
        int resultado = 0;
        try {
            SAXBuilder builder = new SAXBuilder();//Parser del XML
            File xml = new File("ordenes.xml");
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List ordenes = raiz.getChildren();
            for(int i = 0;i<ordenes.size();i++){
                Element pendiente = (Element) ordenes.get(i);
                if ( pendiente.getAttributeValue("Estado").equals("Pendiente de pago")){
                    resultado+=1;
                }
            }
        } catch (JDOMException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            Logger.getLogger(Registro.class.getName()).log(Level.SEVERE, null, ex);
        }
        return resultado;
    }
    
    /**
     * busca las mesas con estado "Pagado" en un rango de fechas
     * @param inicio
     * @param Final
     * @return retorna la cantidad de mesas con estado "Pagado"
     */
    public int cantidadOrdenesPag(Date inicio , Date Final){
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        int resultado = 0;
        try {
            SAXBuilder builder = new SAXBuilder();//Parser del XML
            File xml = new File("ordenes.xml");
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List ordenes = raiz.getChildren();
            for(int i = 0;i<ordenes.size();i++){
                Element pendiente = (Element) ordenes.get(i);
                if ( pendiente.getAttributeValue("Estado").equals("Pagado")){
                    Date fechaOrden =formato.parse(pendiente.getAttributeValue("Fecha"));
                    if(!(fechaOrden.before(inicio)&fechaOrden.after(Final))){
                        resultado+=1;
                    }
                }
            } 
        }
        catch(JDOMException | IOException | ParseException e){
            System.out.println(e);
        }
          
        return resultado;
    }
    
    /**
     * busca en todas las facturas el monto total de la orden
     * @param inicio
     * @param Final
     * @return  retorna un monto final con la suma de todos los totales de las facturas
     */
    public double promedioDeCompra(Date inicio,Date Final){
        SimpleDateFormat formato = new SimpleDateFormat("dd/MM/yyyy");
        double resultado = 0;
        try {
            SAXBuilder builder = new SAXBuilder();//Parser del XML
            File xml = new File("Facturas.xml");
            Document documento = (Document) builder.build(xml);
            Element raiz = documento.getRootElement();
            List facturas = raiz.getChildren();
            for(int i = 0;i<facturas.size();i++){
                Element promedio = (Element) facturas.get(i);
                Date fechaOrden =formato.parse(promedio.getAttributeValue("Fecha"));
                if(!(fechaOrden.before(inicio)&fechaOrden.after(Final))){
                    resultado+=Double.parseDouble(promedio.getAttributeValue("Total"));
                }
            }
        }
        catch(JDOMException | IOException | ParseException | NumberFormatException e){
            System.out.println(e);
        }
        return resultado;
    }
    
}