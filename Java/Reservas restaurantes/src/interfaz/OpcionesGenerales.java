package interfaz;

import java.awt.HeadlessException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import manejoDeDatos.Registro;
import manejoDeDatos.llenarJtable;

public class OpcionesGenerales extends javax.swing.JFrame {
    int mesa;
    ArrayList<String> orden = new ArrayList<>();
    llenarJtable llenar = new llenarJtable();
    Registro registro = new Registro();

    public OpcionesGenerales() {
        initComponents();
        bloquearBotones();
        llenar.Comidas("menu",menuOrdenar);
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setExtendedState(MAXIMIZED_BOTH);
        montoTotal.setEditable(false);
        montoTotal.setEnabled(true);
    }

    private void bloquearBotones(){
        AgregarAOrden.setEnabled(false);
        finalizarPedido.setEnabled(false);
        eliminarPlatillo.setEnabled(false);
        filtarTiposMenu.setEnabled(false);
    }
    
    private void desBloquearbotones(){
        AgregarAOrden.setEnabled(true);
        finalizarPedido.setEnabled(true); 
        eliminarPlatillo.setEnabled(true);
        filtarTiposMenu.setEnabled(true);
        
    }
       
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        Salir = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        menuOrdenar = new javax.swing.JTable();
        jScrollPane1 = new javax.swing.JScrollPane();
        tablaDePedido = new javax.swing.JTable();
        numeroDeMesa = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        filtrarTiposMenu = new javax.swing.JComboBox<>();
        filtarTiposMenu = new javax.swing.JButton();
        AgregarAOrden = new javax.swing.JButton();
        finalizarPedido = new javax.swing.JButton();
        mesasEnEstadoPendiente = new javax.swing.JComboBox<>();
        eliminarPlatillo = new javax.swing.JButton();
        seleccionarMesa = new javax.swing.JButton();
        ORDEN = new javax.swing.JLabel();
        MENU = new javax.swing.JLabel();
        nuevaOrden = new javax.swing.JButton();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        montoTotal = new javax.swing.JTextField();
        facturar = new javax.swing.JButton();
        agregarPedido = new javax.swing.JLabel();
        NuevasOrdenes = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        Salir.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        Salir.setText("Salir");
        Salir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SalirActionPerformed(evt);
            }
        });
        getContentPane().add(Salir, new org.netbeans.lib.awtextra.AbsoluteConstraints(920, 710, 120, 30));

        menuOrdenar.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        menuOrdenar.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Identificador ", "Nombre", "Descripcion", "Precio Sin impuesto", "Plato", "Tipo", "Cantidad", "Ordenar"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Object.class, java.lang.Object.class, java.lang.Object.class, java.lang.Object.class, java.lang.Object.class, java.lang.Object.class, java.lang.Object.class, java.lang.Boolean.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false, true, true
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane2.setViewportView(menuOrdenar);
        if (menuOrdenar.getColumnModel().getColumnCount() > 0) {
            menuOrdenar.getColumnModel().getColumn(0).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(1).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(1).setPreferredWidth(200);
            menuOrdenar.getColumnModel().getColumn(2).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(2).setPreferredWidth(100);
            menuOrdenar.getColumnModel().getColumn(3).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(3).setPreferredWidth(50);
            menuOrdenar.getColumnModel().getColumn(4).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(4).setPreferredWidth(130);
            menuOrdenar.getColumnModel().getColumn(5).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(5).setPreferredWidth(1);
            menuOrdenar.getColumnModel().getColumn(6).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(6).setPreferredWidth(1);
            menuOrdenar.getColumnModel().getColumn(7).setResizable(false);
            menuOrdenar.getColumnModel().getColumn(7).setPreferredWidth(1);
        }

        getContentPane().add(jScrollPane2, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 20, 1080, 380));

        tablaDePedido.setBorder(javax.swing.BorderFactory.createCompoundBorder());
        tablaDePedido.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        tablaDePedido.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Plato", "Cantidad", "Precio final"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(tablaDePedido);
        if (tablaDePedido.getColumnModel().getColumnCount() > 0) {
            tablaDePedido.getColumnModel().getColumn(0).setResizable(false);
            tablaDePedido.getColumnModel().getColumn(0).setPreferredWidth(100);
            tablaDePedido.getColumnModel().getColumn(1).setResizable(false);
            tablaDePedido.getColumnModel().getColumn(1).setPreferredWidth(1);
            tablaDePedido.getColumnModel().getColumn(2).setResizable(false);
            tablaDePedido.getColumnModel().getColumn(2).setPreferredWidth(1);
        }

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 430, 610, 280));

        numeroDeMesa.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(numeroDeMesa, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 500, 120, -1));

        jLabel1.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel1.setText("CRC");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(620, 710, 30, 20));

        jLabel2.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel2.setText("Total Final");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(370, 710, -1, 20));

        jLabel3.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel3.setText("Filtar por tipos");
        getContentPane().add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(1150, 110, -1, -1));

        filtrarTiposMenu.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        filtrarTiposMenu.setToolTipText("");
        filtrarTiposMenu.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                filtrarTiposMenuMouseClicked(evt);
            }
        });
        getContentPane().add(filtrarTiposMenu, new org.netbeans.lib.awtextra.AbsoluteConstraints(1120, 140, 180, -1));

        filtarTiposMenu.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        filtarTiposMenu.setText("Filtrar");
        filtarTiposMenu.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                filtarTiposMenuActionPerformed(evt);
            }
        });
        getContentPane().add(filtarTiposMenu, new org.netbeans.lib.awtextra.AbsoluteConstraints(1120, 170, 180, -1));

        AgregarAOrden.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        AgregarAOrden.setText("Agregar Seleccionados");
        AgregarAOrden.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarAOrdenActionPerformed(evt);
            }
        });
        getContentPane().add(AgregarAOrden, new org.netbeans.lib.awtextra.AbsoluteConstraints(1120, 220, -1, -1));

        finalizarPedido.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        finalizarPedido.setText("Finalizar Pedido");
        finalizarPedido.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                finalizarPedidoActionPerformed(evt);
            }
        });
        getContentPane().add(finalizarPedido, new org.netbeans.lib.awtextra.AbsoluteConstraints(1120, 260, 180, -1));

        mesasEnEstadoPendiente.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        mesasEnEstadoPendiente.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mousePressed(java.awt.event.MouseEvent evt) {
                mesasEnEstadoPendienteMousePressed(evt);
            }
        });
        mesasEnEstadoPendiente.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                mesasEnEstadoPendienteActionPerformed(evt);
            }
        });
        getContentPane().add(mesasEnEstadoPendiente, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 580, 110, -1));

        eliminarPlatillo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        eliminarPlatillo.setText("Eliminar Plato");
        eliminarPlatillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                eliminarPlatilloActionPerformed(evt);
            }
        });
        getContentPane().add(eliminarPlatillo, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 710, -1, -1));

        seleccionarMesa.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        seleccionarMesa.setText("Seleccionar Mesa");
        seleccionarMesa.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                seleccionarMesaActionPerformed(evt);
            }
        });
        getContentPane().add(seleccionarMesa, new org.netbeans.lib.awtextra.AbsoluteConstraints(790, 580, -1, -1));

        ORDEN.setText("ORDEN");
        getContentPane().add(ORDEN, new org.netbeans.lib.awtextra.AbsoluteConstraints(120, 400, 50, 30));

        MENU.setText("MENU");
        getContentPane().add(MENU, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 0, 50, 20));

        nuevaOrden.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        nuevaOrden.setText("Nueva Orden");
        nuevaOrden.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                nuevaOrdenActionPerformed(evt);
            }
        });
        getContentPane().add(nuevaOrden, new org.netbeans.lib.awtextra.AbsoluteConstraints(647, 440, 120, -1));

        jLabel4.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel4.setText("Numero de mesa");
        getContentPane().add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 470, 120, 20));

        jLabel5.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel5.setText("Modificar Pedido de una mesa");
        getContentPane().add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 540, -1, 20));

        montoTotal.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(montoTotal, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 710, 170, -1));

        facturar.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        facturar.setText("Facturar Ordenes");
        facturar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                facturarActionPerformed(evt);
            }
        });
        getContentPane().add(facturar, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 520, -1, -1));

        agregarPedido.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        getContentPane().add(agregarPedido, new org.netbeans.lib.awtextra.AbsoluteConstraints(1100, 90, 240, 210));

        NuevasOrdenes.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        getContentPane().add(NuevasOrdenes, new org.netbeans.lib.awtextra.AbsoluteConstraints(630, 430, 320, 210));

        jLabel6.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        getContentPane().add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(1040, 430, 320, 210));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SalirActionPerformed
        PantallaPrincipal volver = new PantallaPrincipal();
        volver.setVisible(true);
        dispose();
    }//GEN-LAST:event_SalirActionPerformed

    private void filtrarTiposMenuMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_filtrarTiposMenuMouseClicked
        try {
            llenar.llenarComboBox(filtrarTiposMenu);
        } catch (Exception ex) {
            Logger.getLogger(OpcionesGenerales.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_filtrarTiposMenuMouseClicked

    private void nuevaOrdenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_nuevaOrdenActionPerformed
        if(numeroDeMesa.getText().equals("")){
            JOptionPane.showMessageDialog(null, "Se debe ingregar un numero de mesa primero");
        }
        
        else if (menuOrdenar.getRowCount()==0){JOptionPane.showMessageDialog(null, "Lo sentimos el menu esta vacio");
        }
        else{
            try{
                int numeroMesa=Integer.parseInt(numeroDeMesa.getText());
                if(numeroMesa>0){
                    this.mesa= numeroMesa;
                    int resultado = registro.verificarMesa(String.valueOf(mesa));
                    if(resultado==1){
                        seleccionarMesa.setEnabled(false);
                        nuevaOrden.setEnabled(false);
                        desBloquearbotones();
                    }
                    else{
                        JOptionPane.showMessageDialog(null, "La mesa Selecionada se ecuentra en estado pendiente de pago");
                    }
                }
                else{
                    JOptionPane.showMessageDialog(null, "el Numero de mesa debe ser positivo");
                }
            }
            catch(NumberFormatException | HeadlessException e){
                JOptionPane.showMessageDialog(null, "Favor ingregar un numero");
            }
        }
        
        
    }//GEN-LAST:event_nuevaOrdenActionPerformed

    private void filtarTiposMenuActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_filtarTiposMenuActionPerformed
        if(filtrarTiposMenu.getSelectedIndex()==-1){
            JOptionPane.showMessageDialog(null, "Se debe seleccionar una opcion");
        }
        else{
            int resultado = llenar.verificarMarcaMenu(menuOrdenar);
            if(resultado==1){
                int respuesta =JOptionPane.showConfirmDialog(null, "Existen platillos marcados,¿desea agregarlos a la orden?");
                switch (respuesta) {
                    case 0:
                        llenar.limpiarTabla(tablaDePedido);
                        llenar.tableDeOrden(menuOrdenar,tablaDePedido);
                        break;
                    default:
                        break;
                }              
            }
            else{}
            llenar.limpiarTabla(menuOrdenar);
            String seleccionFiltro = (String) filtrarTiposMenu.getSelectedItem();
            llenar.filtroJtable(seleccionFiltro,menuOrdenar);
        }
    }//GEN-LAST:event_filtarTiposMenuActionPerformed

    private void AgregarAOrdenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarAOrdenActionPerformed
        llenar.limpiarTabla(tablaDePedido);
        try{
            String cantidad = (String) menuOrdenar.getValueAt(menuOrdenar.getSelectedRow(),6);
            llenar.tableDeOrden(menuOrdenar, tablaDePedido);
            String monto = String.valueOf(llenar.precioOrden());
            montoTotal.setText(monto);
        }
        catch(Exception e){
            JOptionPane.showMessageDialog(null, "Debe escogerge una cantidad");
        }
    }//GEN-LAST:event_AgregarAOrdenActionPerformed

    private void eliminarPlatilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_eliminarPlatilloActionPerformed
        if(tablaDePedido.getSelectedRow()==-1){
            JOptionPane.showMessageDialog(null, "Se debe selecionar un plato");
        }
        else{
            int resultado =llenar.eliminarModificarPlatillo(tablaDePedido,tablaDePedido.getSelectedRow());
            if(resultado==1){
                String respuesta =  JOptionPane.showInputDialog(null, "el plato tiene cantidad superior a 1, indicar cauntos platos desea eliminar");
                try{
                    int cantidad = Integer.valueOf(respuesta);
                    if (cantidad>0) {
                        llenar.eliminarTablaOrdenar(tablaDePedido, cantidad,tablaDePedido.getSelectedRow());
                        montoTotal.setText(String.valueOf(llenar.precioOrden()));
                    }
                    else{JOptionPane.showMessageDialog(null, "El numero debe ser positivo");}
                }
                catch(Exception e){
                    JOptionPane.showMessageDialog(null, "Se debe ingregar un numero "+e);
                }
            }
            else{
                llenar.eliminarTablaOrdenar(tablaDePedido, 1,tablaDePedido.getSelectedRow());
            }
        }
        
    }//GEN-LAST:event_eliminarPlatilloActionPerformed

    private void finalizarPedidoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_finalizarPedidoActionPerformed
        bloquearBotones();
        if(tablaDePedido.getRowCount()==0){
            JOptionPane.showMessageDialog(null, "No se puede crear Una orden vacia");
            desBloquearbotones();
        }
        else{
            int resultado = llenar.GuargarPedido(mesa);
            if(resultado==1){
                JOptionPane.showMessageDialog(null, "Se guardo la orden exitozamente");
            }
            llenar.limpiarTabla(tablaDePedido);
            nuevaOrden.setEnabled(true);
            seleccionarMesa.setEnabled(true);
            mesasEnEstadoPendiente.setEnabled(true);
            facturar.setEnabled(true);
            Salir.setEnabled(true);
        }
            
    }//GEN-LAST:event_finalizarPedidoActionPerformed

    private void seleccionarMesaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_seleccionarMesaActionPerformed
       if(mesasEnEstadoPendiente.getSelectedIndex()==-1){
           JOptionPane.showMessageDialog(null, "Se debe seleccionar una opcion");
       }
       else{
           this.mesa=Integer.valueOf((String)mesasEnEstadoPendiente.getSelectedItem());
           llenar.recargarPedido(tablaDePedido,(String) mesasEnEstadoPendiente.getSelectedItem());
           if(tablaDePedido.getRowCount()==0){JOptionPane.showMessageDialog(null, "La orden no existe");}
           else{
                desBloquearbotones();
                seleccionarMesa.setEnabled(false);
                mesasEnEstadoPendiente.setEnabled(false);
                nuevaOrden.setEnabled(false);
                Salir.setEnabled(false);
                facturar.setEnabled(false);
           }
           
       }
    }//GEN-LAST:event_seleccionarMesaActionPerformed

    private void mesasEnEstadoPendienteActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_mesasEnEstadoPendienteActionPerformed

    }//GEN-LAST:event_mesasEnEstadoPendienteActionPerformed

    private void mesasEnEstadoPendienteMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_mesasEnEstadoPendienteMousePressed
        try {
            llenar.MesasPendientes(mesasEnEstadoPendiente);
        } catch (Exception ex) {
            Logger.getLogger(OpcionesGenerales.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_mesasEnEstadoPendienteMousePressed

    private void facturarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_facturarActionPerformed

       Facturar fact = new Facturar();
       fact.setVisible(true);
    }//GEN-LAST:event_facturarActionPerformed
    
    public static void main(String args[]) {
        
        java.awt.EventQueue.invokeLater(() -> {
            new OpcionesGenerales().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton AgregarAOrden;
    private javax.swing.JLabel MENU;
    private javax.swing.JLabel NuevasOrdenes;
    private javax.swing.JLabel ORDEN;
    private javax.swing.JButton Salir;
    private javax.swing.JLabel agregarPedido;
    private javax.swing.JButton eliminarPlatillo;
    private javax.swing.JButton facturar;
    private javax.swing.JButton filtarTiposMenu;
    private javax.swing.JComboBox<String> filtrarTiposMenu;
    private javax.swing.JButton finalizarPedido;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable menuOrdenar;
    private javax.swing.JComboBox<String> mesasEnEstadoPendiente;
    private javax.swing.JTextField montoTotal;
    private javax.swing.JButton nuevaOrden;
    private javax.swing.JTextField numeroDeMesa;
    private javax.swing.JButton seleccionarMesa;
    private javax.swing.JTable tablaDePedido;
    // End of variables declaration//GEN-END:variables
}
