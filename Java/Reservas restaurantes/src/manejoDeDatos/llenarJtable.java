package manejoDeDatos;

//Imports//
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JComboBox;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import org.jdom2.Element;
import java.io.*;
import java.util.ArrayList;
import java.util.Date;
import javax.swing.DefaultCellEditor;
import javax.swing.DefaultListModel;
import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JOptionPane;
import javax.swing.table.TableCellEditor;
import javax.swing.table.TableColumn;

public class llenarJtable {
    Registro registro = new Registro();
    ArrayList<Object> pedidos = new ArrayList<>();
    

    public llenarJtable() {}
    
    /**
     * Llenar la JTable recibida con los datos de tipos de comidas existentes
     * @param tabla
     * @return retorna la JTble llena con los tipos de comidas
     */
    public JTable tipoPlatos(JTable tabla){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        String[] dato = new String[2];
        try {
            List datos = registro.tiposComidas();
            for(int i = 0;i<datos.size();i++){
                Element tipo = (Element)datos.get(i);
                dato[0]= tipo.getAttributeValue("identificador");
                dato[1]=tipo.getAttributeValue("Tipo");
                modelo.addRow(dato);
            }
           tabla.setModel(modelo);
        } catch (Exception ex) {
            Logger.getLogger(llenarJtable.class.getName()).log(Level.SEVERE, null, ex);
        }
        return tabla;
        
    }
    
    /**
     * limpia la Tbable recibida
     * @param tabla 
     */
    public  void limpiarTabla(JTable tabla){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
            while(modelo.getRowCount()>0)modelo.removeRow(0);
    }
    
    
    /**
     * llena la combobox recibida con los tipos de comidas
     * @param combo
     * @return retorna la JComboBox lleba con los tipos de comidas
     * @throws Exception 
     */
    public JComboBox llenarComboBox(JComboBox combo) throws Exception{
        List datos = registro.tiposComidas();
        if(combo.getItemCount()>0){
            combo.removeAllItems();
            for(int i = 0;i<datos.size();i++){
                Element tipo = (Element)datos.get(i);
                combo.addItem(tipo.getAttributeValue("Tipo"));
            }
            combo.addItem("Todos");
            return combo;
        }
         else{
            for(int i = 0;i<datos.size();i++){
                Element tipo = (Element)datos.get(i);
                combo.addItem(tipo.getAttributeValue("Tipo"));
                }
             combo.addItem("Todos");
             return combo;
        }
            
    }
    
    public int prepararCombo(String identificador,String precio,String Imagen,JTable tabla){
        String platosCombo = "";
        DefaultTableModel modelo = (DefaultTableModel)tabla.getModel();
        if(verificarMarcaMenu(tabla)==1){
            for(int i = 0;i<modelo.getRowCount();i++){
                boolean marca = (boolean) modelo.getValueAt(i, 7);
                if(marca){
                    String combo = (String) modelo.getValueAt(i, 5);
                    if(combo.equals("Combo")){
                        return 2;
                    }
                    platosCombo+=modelo.getValueAt(i, 6)+" "+modelo.getValueAt(i, 1)+",";
                }
            }
            int resultado = registro.comidas(identificador, platosCombo, "Combo", precio, Imagen, "Combo");
            return resultado;
        }
        return 0;
    }
    
    /**
     * 
     * @param nombreJtable
     * @param tabla
     * @return  retorna un JTable
     */
    public JTable Comidas(String nombreJtable, JTable tabla){
        switch (nombreJtable) {
            case "admin":
                areaAdmin(tabla);
                break;
            default:
                areaMenu(tabla);
                break;
        }
        return tabla;
    }
         
    /**
     * LLena la JTable con todos los platos guardados en el XML
     * @param tabla
     * @return Una JTable llena con los datos de XML
     */
    private JTable areaAdmin(JTable tabla ) {
        tabla.setDefaultRenderer(Object.class, new imagen());
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        Object[] datos = new Object[6];
        tabla.setRowHeight(200);
        try {
            List comidas = registro.camidas();
            for ( int i = 0;i<comidas.size();i++){
                Element tipo = (Element)comidas.get(i);
                datos[0]= tipo.getAttributeValue("Identificador");
                datos[1]=tipo.getAttributeValue("Nombre");
                datos[2]= tipo.getAttributeValue("Descripcion");
                datos[3]=tipo.getAttributeValue("Precio");
                JLabel imagen = new JLabel();
                ImageIcon foto = new ImageIcon(AbrirImagen(new File(tipo.getAttributeValue("Imagen")).getAbsoluteFile()));
                Icon icono = new ImageIcon(foto.getImage().getScaledInstance(200,200,200));
                imagen.setIcon(icono);
                datos[4]=imagen;
                datos[5]=tipo.getAttributeValue("Tipo");
                modelo.addRow(datos);   
            }
            tabla.setModel(modelo);
            
        } catch (Exception ex) {
            Logger.getLogger(llenarJtable.class.getName()).log(Level.SEVERE, null, ex);
        }
        return tabla;
    }
    
    /**
     * llena la JTable recibida con los datos de los platos almacenados en el XML
     * @param tabla
     * @return retorna la JTable llena con los datos
     */
    private JTable areaMenu(JTable tabla){
        tabla.setDefaultRenderer(Object.class, new imagen());
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        Object[] cantidad = new Object[10000];
        for(int i =1;i<10000;i++){
            cantidad[i]=String.valueOf(i);
        }
        Object[] datos = new Object[8];
        tabla.setRowHeight(200);
        try {
            List comidas = registro.camidas();
            for ( int i = 0;i<comidas.size();i++){
                Element tipo = (Element)comidas.get(i);
                datos[0]= tipo.getAttributeValue("Identificador");
                datos[1]=tipo.getAttributeValue("Nombre");
                datos[2]= tipo.getAttributeValue("Descripcion");
                datos[3]=tipo.getAttributeValue("Precio");
                JLabel imagen = new JLabel();
                ImageIcon foto = new ImageIcon(AbrirImagen(new File(tipo.getAttributeValue("Imagen")).getAbsoluteFile()));
                Icon icono = new ImageIcon(foto.getImage().getScaledInstance(200,200,200));
                imagen.setIcon(icono);
                datos[4]=imagen;
                datos[5]=tipo.getAttributeValue("Tipo");
                JComboBox jcb = new JComboBox(cantidad);
                TableColumn tb = tabla.getColumnModel().getColumn(6);
                TableCellEditor tce = new DefaultCellEditor(jcb);
                jcb.setSize(10,10);
                tb.setCellEditor(tce);
                datos[6]=jcb;
                datos[7]=false;  
                modelo.addRow(datos);   
                
            }
            tabla.setModel(modelo);
            
        } catch (Exception ex) {
            Logger.getLogger(llenarJtable.class.getName()).log(Level.SEVERE, null, ex);
        }
        return tabla;
        
    }
    
    /**
     * recorre toda la imagen bit pot bit y lo almacena en un arreglo
     * @param archivo
     * @return devualte un arreglo de Byte
     * @throws Exception 
     */
    private byte[] AbrirImagen(File archivo) throws Exception{
        FileInputStream entrada;
        long l = archivo.length();
        Integer tamaño = (int) (long) l;
        byte[] nuevaImegen = new byte[tamaño];
            try {
                entrada = new FileInputStream(archivo);
                entrada.read(nuevaImegen);
                return nuevaImegen;
            } catch (FileNotFoundException ex) {
                JOptionPane.showMessageDialog(null, "Algunas imagenes no se pudieron cargar, debido a que fueron movidas de lugar");
            }
            return nuevaImegen;
    }
    
    /**
     * filtra las JTabla con los tipos seleccionados
     * @param tipoComida
     * @param tabla
     * @return retorna la JTabla con los datos del filtro enviado
     */
    public JTable filtroJtable(String tipoComida,JTable tabla){
        if(tipoComida.equals("Todos")){
            return areaMenu(tabla);
        }
        else{
            try {
                tabla.setDefaultRenderer(Object.class, new imagen());
                DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
                Object[] cantidad = new Object[10000];
                for(int i =1;i<10000;i++){
                    cantidad[i]=String.valueOf(i);
        }
                Object[] datos = new Object[8];
                tabla.setRowHeight(200);
                List comidas = registro.camidas();
                for ( int i = 0;i<comidas.size();i++){
                    Element tipo = (Element)comidas.get(i);
                    if(tipoComida.equals(tipo.getAttributeValue("Tipo"))){
                        datos[0]= tipo.getAttributeValue("Identificador");
                        datos[1]=tipo.getAttributeValue("Nombre");
                        datos[2]= tipo.getAttributeValue("Descripcion");
                        datos[3]=tipo.getAttributeValue("Precio");
                        JLabel imagen = new JLabel();
                        ImageIcon foto = new ImageIcon(AbrirImagen(new File(tipo.getAttributeValue("Imagen"))));
                        Icon icono = new ImageIcon(foto.getImage().getScaledInstance(200,200,200));
                        imagen.setIcon(icono);
                        datos[4]=imagen;
                        datos[5]=tipo.getAttributeValue("Tipo");
                        JComboBox jcb = new JComboBox(cantidad);
                        TableColumn tb = tabla.getColumnModel().getColumn(6);
                        TableCellEditor tce = new DefaultCellEditor(jcb);
                        jcb.setSize(10,10);
                        tb.setCellEditor(tce);
                        datos[6]=jcb;
                        datos[7]=false;
                        modelo.addRow(datos);
                    }
                    else{}
                }
                tabla.setModel(modelo);
            } catch (Exception ex) {
                Logger.getLogger(llenarJtable.class.getName()).log(Level.SEVERE, null, ex);
            }
           
        }
        return tabla;
            
        }
    
    /**
     * revisa la JTable si existen ordenes marcadas
     * @param tabla
     * @return retorna un un numero dependiendo del resultado de la operacion
     */
    public int verificarMarcaMenu(JTable tabla){
        DefaultTableModel modelo = (DefaultTableModel)tabla.getModel();
        int numeroFilas=modelo.getRowCount();
        for(int i=0;i<numeroFilas;i++){
            boolean marca = (boolean) modelo.getValueAt(i, 7);
            if(marca){
                return 1;
            }
        }
        return 0;
    }
    
    /**
     * busca las marcas de la JTabla del menu y las agrega a la orden
     * @param tabla
     * @param pedido
     * @return retorna una JTable con los pedidos 
     */
    public JTable tableDeOrden(JTable tabla,JTable pedido){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        int numeroFilas=modelo.getRowCount();
        for(int i = 0;i<numeroFilas;i++){
            boolean marca = (boolean) modelo.getValueAt(i, 7);
            if(marca){
                String cantidad = (String) modelo.getValueAt(i, 6);
                String plato = (String) modelo.getValueAt(i, 1);
                String precio = (String) modelo.getValueAt(i, 3);
                if(!pedidos.isEmpty()){
                    if(pedidos.contains(plato)){
                        int pos = pedidos.indexOf(plato);
                        int cantAnterior = Integer.valueOf((String)pedidos.get(pos+1));
                        int sumaCantidades = (Integer.parseInt(cantidad))+cantAnterior;
                        int sumaPrecios = (Integer.parseInt(precio))*sumaCantidades;
                        pedidos.set(pos+1, String.valueOf(sumaCantidades)); 
                        pedidos.set(pos+2,String.valueOf(sumaPrecios));
                    }
                    else{
                        int cantidades = Integer.valueOf(cantidad);
                        int precioUT = Integer.valueOf(precio);
                        pedidos.add(plato);pedidos.add(cantidad);pedidos.add(String.valueOf(cantidades*precioUT));
                    }
                }
                else{
                    int cantidades = Integer.valueOf(cantidad);
                    int precioUT = Integer.valueOf(precio);
                    pedidos.add(plato);pedidos.add(cantidad);pedidos.add(String.valueOf(cantidades*precioUT));}
            }
        }
        JTable tablaPedido= llenarTablaPedido(pedido, pedidos); 
        return tablaPedido;
    }
    
    /**
     * LLena la la JTable del de la orden
     * @param tabla
     * @param pedido
     * @return retorna la JTable llena con la orden
     */
    private JTable llenarTablaPedido(JTable tabla , ArrayList<Object> pedido){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        Object[] datos = new Object[3];
        for(int i=0;i<pedido.size();i+=3){
            datos[0]=pedido.get(i);
            datos[1]=pedido.get(i+1);
            datos[2]=pedido.get(i+2);
            modelo.addRow(datos);
        }
        tabla.setModel(modelo);
        
        return tabla;
    }
    
    /**
     * suma todos los precios de la orden
     * @return retorna un precio, el de todas las ordenes
     */
    public long precioOrden(){
        int resultado = 0;
        for(int i =0;i<pedidos.size();i+=3){
            int precio = Integer.valueOf((String)pedidos.get(i+2));
            resultado+=precio;    
        }
        return resultado;
    }
    
    
    /**
     * revisa si el plato selecionado tiene mas de 1
     * @param tabla
     * @param seleccion
     * @return retorna un numero dependiendo del resultado de la operacion
     */
    public int eliminarModificarPlatillo(JTable tabla,int seleccion){
        String nombrePlato = (String) tabla.getValueAt(seleccion, 0);
        for(int i = 0;i<pedidos.size();i++){
            int pos = pedidos.indexOf(nombrePlato);
            if(Integer.valueOf((String) pedidos.get(pos+1))>1){
                return 1;
            }
        }
        
        return 0;
    }
    
    /**
     * eliminar la cantidad de platos ingresada
     * @param tabla
     * @param cantidad
     * @param seleccion
     * @return Jtable modifica con los nuevos datos
     */
    public JTable eliminarTablaOrdenar(JTable tabla, int cantidad, int seleccion){
        String nombrePlato = (String) tabla.getValueAt(seleccion, 0);
        String cantidades = (String)tabla.getValueAt(seleccion, 1);
        String precio = (String) tabla.getValueAt(seleccion, 2);
        if(eliminarModificarPlatillo(tabla, seleccion)==1){
                int pos = pedidos.indexOf(nombrePlato);
                int precioUT =Integer.valueOf(precio)/Integer.valueOf((String)cantidades) ;
                int nuevaCantidad = Integer.valueOf((String)cantidades)-cantidad;
                if(nuevaCantidad==0){
                    pedidos.remove(pos+2);
                    pedidos.remove(pos+1);
                    pedidos.remove(pos);
                    
                }
                else{
                   pedidos.set(pos, nombrePlato);
                   pedidos.set(pos+1,String.valueOf(nuevaCantidad));
                   pedidos.set(pos+2, String.valueOf(precioUT*nuevaCantidad));
                }
        }
        else{
            int pos = pedidos.indexOf(nombrePlato);
            pedidos.remove(pos+2);pedidos.remove(pos+1);pedidos.remove(pos);
            
        }
        JTable tem = tabla;
        limpiarTabla(tabla);
        llenarTablaPedido(tem, pedidos);
        return tabla;
    }  
    
    /**
     * Finaliza el pedido guardando todos los datos en un XML
     * @param mesa
     * @return returna un numero dependiendo del resultado de la operacion
     */
    public int GuargarPedido(int mesa){
        int resultado  =registro.guardarPedido(mesa,pedidos);
        pedidos.clear();
        return resultado;   
    }
    
    /**
     * llena la JComboBox recibida con las mesas con estado "Pendiente de pago"
     * @param combobox
     * @return retorna la JConboBox llena con las mesas estado "Pendiente de Pago"
     * @throws Exception 
     */
    public JComboBox MesasPendientes(JComboBox combobox) throws Exception{
        ArrayList listaMesas = registro.mesasEnpendiente();
        if(combobox.getItemCount()>=0){
            combobox.removeAllItems();
            for(int i = 0;i<listaMesas.size();i++){
                String numero = (String) listaMesas.get(i);
                combobox.addItem(numero);
            }
        }
        return combobox;
    }
    
    
    /**
     * recarga carga el pedido de la mesa selecionada para su modificacion
     * @param tabla
     * @param seleccion
     * @return retorna la JTabla con los datos recargados
     */
    public JTable recargarPedido(JTable tabla,String seleccion){
        pedidos=registro.OrdenMesaSeleccionada(seleccion);
        llenarTablaPedido(tabla, pedidos);
        return tabla;
    }
    
    /**
     * busca las mesas de estado "Pendiente de pago" y las agrega a la JComboBox
     * @param combobox
     * @return retorna la JConboBox con los datos dentro
     * @throws Exception 
     */
    public JComboBox MesasPendientesFacturas(JComboBox combobox) throws Exception{
        ArrayList listaMesas = registro.mesasEnpendiente();
        if(combobox.getItemCount()>=0){
            combobox.removeAllItems();
            for(int i = 0;i<listaMesas.size();i++){
                String numero = (String) listaMesas.get(i);
                combobox.addItem(numero);
            }
        }
        return combobox;
    }
    
    /**
     * Llena la JTabla con las facturas existentes
     * @param tabla
     * @return retorna la JTabla llena con las facturas existentes
     */
    public JTable llenarTablaFacturas(JTable tabla){
        DefaultTableModel modelo = (DefaultTableModel) tabla.getModel();
        Object[] datos = new Object[5];
        
        try {
            List facturas = registro.facturasListas();
            for(int i = 0;i<facturas.size();i++){
                Element datosFactura = (Element) facturas.get(i);
                datos[0]=datosFactura.getAttributeValue("Factura");
                datos[1]=datosFactura.getAttributeValue("Fecha");
                datos[2]=datosFactura.getAttributeValue("Hora");
                datos[3]=datosFactura.getAttributeValue("SubTotal");
                datos[4]=datosFactura.getAttributeValue("Total");
                modelo.addRow(datos);
            }
            tabla.setModel(modelo);
            return tabla;
        } catch (Exception ex) {
            Logger.getLogger(llenarJtable.class.getName()).log(Level.SEVERE, null, ex);
        }
        return tabla;
    }
    
    /**
     * 
     * @param lista
     * @param clave
     * @param inicio
     * @param Final
     * @return una JLista con el resultad de la estadistica selecioanada
     */
    public JList llenarListaEstadistica(JList lista,String clave,Date inicio,Date Final){
        switch (clave) {
            case "Cantidad de órdenes pendientes":
                cantidadOrdenesPendientes(lista);
                break;
            case "Cantidad de órdenes pagadas":
                catidadDeOrdenesPagadas(lista,inicio,Final);
                break;
            case "Promedio de compra":
                PromedioDeCompra(lista,inicio,Final);
                break;
            default:
                throw new AssertionError();
        }
        return lista;
    }
    
    /**
     * presenta en la JList recibida la cantidad de ordenes con estado "Pendiente de pago"
     * @param lista
     * @return retorna la JList con la cantidad de ordenes pendientes de pago
     */
    private JList cantidadOrdenesPendientes(JList lista){
        DefaultListModel modelo = new DefaultListModel();
        int resultado = registro.cantidadOrdenesPen();
        modelo.addElement("cantidadOrdenesPendientes: "+resultado);
        lista.setModel(modelo);
        return lista;
    }
    
    /**
     * presenta en la Jlist recibida la cantidad de ordenes con estado "Pagado"
     * @param lista
     * @param inicio
     * @param Final
     * @return retorna  la JList con la cantidad de ordenes pendientes de Pago
     */
    private JList catidadDeOrdenesPagadas(JList lista,Date inicio,Date Final){
        DefaultListModel modelo = new DefaultListModel();
        int resultado = registro.cantidadOrdenesPag(inicio,Final);
        modelo.addElement("cantidadOrdenesPagadas: "+resultado);
        lista.setModel(modelo);
        return lista;
    }
    
    /**
     * presenta en la JList recibida el promedio de compra 
     * @param lista
     * @param inicio
     * @param Final
     * @return retorna la JList con el promedio de compra
     */
    private JList PromedioDeCompra(JList lista , Date inicio , Date Final){
        DefaultListModel modelo = new DefaultListModel();
        double resultado = registro.promedioDeCompra(inicio,Final);
        modelo.addElement("El Promedio de compra es de : "+resultado);
        lista.setModel(modelo);
        return lista;
    }
       
}