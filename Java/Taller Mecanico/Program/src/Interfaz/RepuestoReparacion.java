/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Interfaz;

import BD.ManejoComponentes;
import BD.ManejoDatos;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

/**
 *
 * @author Jordan Araya
 */
public class RepuestoReparacion extends javax.swing.JFrame {
    ManejoDatos conectar = new ManejoDatos();
    ManejoComponentes componente = new ManejoComponentes();

    /**
     * Creates new form RepuestoReparacion
     */
    public RepuestoReparacion() {
        initComponents();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setExtendedState(MAXIMIZED_BOTH);
        componente.llenarTablas(jTableRepuestos,jTableRepuestos.getColumnCount(),""
                    + "SELECT IdRepuesto,NombreRepuesto,PrecioRepuesto FROM repuestos");
        componente.llenarTablas(jTableReparaciones,jTableReparaciones.getColumnCount(),""
                    + "SELECT R.idReparacion,R.CedulaMecanico,R.Matricula,I.Dueño,R.FechaEntrega FROM "
                    + "reparacion as R inner join Vehiculo as V on R.matricula = V.MatriculaVehiculo "
                    + "inner join InformacionCliente as I on I.CedulaCliente = V.CedulaCliente WHERE EstadoReparacion=1");
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPopupMenuEliminarRE = new javax.swing.JPopupMenu();
        jMenuItemEliminarRepuesto = new javax.swing.JMenuItem();
        jPopupMenuEliminarReparacion = new javax.swing.JPopupMenu();
        jMenuItemEliminarRep = new javax.swing.JMenuItem();
        jMenuItemVerRepuestos = new javax.swing.JMenuItem();
        jPanel1 = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jTextFieldPrecioRE = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jTextFieldNombreRE = new javax.swing.JTextField();
        jButtonAgregarRepuesto = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTableRepuestos = new javax.swing.JTable();
        jPanel3 = new javax.swing.JPanel();
        jTextFieldDueño = new javax.swing.JTextField();
        jComboBoxMatriculas = new javax.swing.JComboBox<>();
        jLabel6 = new javax.swing.JLabel();
        jButtonReparacion = new javax.swing.JButton();
        jLabel8 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jComboBoxMecanicoP = new javax.swing.JComboBox<>();
        jLabel4 = new javax.swing.JLabel();
        jTextFieldNombreMC = new javax.swing.JTextField();
        jPanel4 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTableReparaciones = new javax.swing.JTable();
        jPanel5 = new javax.swing.JPanel();
        jLabel14 = new javax.swing.JLabel();
        jButtonVolver = new javax.swing.JButton();

        jMenuItemEliminarRepuesto.setText("Eliminar Repuesto");
        jMenuItemEliminarRepuesto.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemEliminarRepuestoActionPerformed(evt);
            }
        });
        jPopupMenuEliminarRE.add(jMenuItemEliminarRepuesto);

        jMenuItemEliminarRep.setText("Eliminar Reparacion");
        jMenuItemEliminarRep.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemEliminarRepActionPerformed(evt);
            }
        });
        jPopupMenuEliminarReparacion.add(jMenuItemEliminarRep);

        jMenuItemVerRepuestos.setText("Ver Repuestos Utilizados");
        jMenuItemVerRepuestos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItemVerRepuestosActionPerformed(evt);
            }
        });
        jPopupMenuEliminarReparacion.add(jMenuItemVerRepuestos);

        setDefaultCloseOperation(javax.swing.WindowConstants.DO_NOTHING_ON_CLOSE);
        setTitle("Area Repuestos - Reparaciones");
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Ingresar Nuevo Repuesto"));
        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel1.setText("Nombre Repuesto:");
        jPanel1.add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 60, -1, 20));
        jPanel1.add(jTextFieldPrecioRE, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 90, 80, -1));

        jLabel2.setText("Precio Repuesto:");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 90, -1, 20));
        jPanel1.add(jTextFieldNombreRE, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 60, 230, -1));

        jButtonAgregarRepuesto.setText("Agregar Repuesto");
        jButtonAgregarRepuesto.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonAgregarRepuestoActionPerformed(evt);
            }
        });
        jPanel1.add(jButtonAgregarRepuesto, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 130, 140, -1));

        getContentPane().add(jPanel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 10, 370, 164));

        jPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("Lista de Repuestos"));

        jTableRepuestos.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "ID Repuesto", "Nombre - Descripcion", "Precio Unitario"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jTableRepuestos.setComponentPopupMenu(jPopupMenuEliminarRE);
        jScrollPane1.setViewportView(jTableRepuestos);
        if (jTableRepuestos.getColumnModel().getColumnCount() > 0) {
            jTableRepuestos.getColumnModel().getColumn(0).setPreferredWidth(5);
            jTableRepuestos.getColumnModel().getColumn(1).setPreferredWidth(400);
            jTableRepuestos.getColumnModel().getColumn(2).setPreferredWidth(50);
        }

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 778, Short.MAX_VALUE)
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 274, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 3, Short.MAX_VALUE))
        );

        getContentPane().add(jPanel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(420, 10, 790, 300));

        jPanel3.setBorder(javax.swing.BorderFactory.createTitledBorder("Incluir Nueva Reparación"));
        jPanel3.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jTextFieldDueño.setEnabled(false);
        jPanel3.add(jTextFieldDueño, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 150, 200, -1));

        jComboBoxMatriculas.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jComboBoxMatriculasMouseClicked(evt);
            }
        });
        jComboBoxMatriculas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBoxMatriculasActionPerformed(evt);
            }
        });
        jPanel3.add(jComboBoxMatriculas, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 110, 110, -1));

        jLabel6.setText("Nombre Dueño:");
        jPanel3.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 150, -1, 20));

        jButtonReparacion.setText("Procesar");
        jButtonReparacion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonReparacionActionPerformed(evt);
            }
        });
        jPanel3.add(jButtonReparacion, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 220, 130, -1));

        jLabel8.setText("Matricula:");
        jPanel3.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 110, -1, 20));

        jLabel3.setText("Mecanico:");
        jPanel3.add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 30, 100, 20));

        jComboBoxMecanicoP.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jComboBoxMecanicoPMouseClicked(evt);
            }
        });
        jComboBoxMecanicoP.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBoxMecanicoPActionPerformed(evt);
            }
        });
        jPanel3.add(jComboBoxMecanicoP, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 30, 110, -1));

        jLabel4.setText("Nombre Mecánico:");
        jPanel3.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 70, -1, -1));

        jTextFieldNombreMC.setEnabled(false);
        jPanel3.add(jTextFieldNombreMC, new org.netbeans.lib.awtextra.AbsoluteConstraints(130, 70, 210, -1));

        getContentPane().add(jPanel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 350, 350, 260));

        jPanel4.setBorder(javax.swing.BorderFactory.createTitledBorder("Reparaciones Pendientes"));

        jTableReparaciones.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "ID Reparación", "Mecánico", "Matrícula", "Nombre Cliente", "Fecha Entrega"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jTableReparaciones.setComponentPopupMenu(jPopupMenuEliminarReparacion);
        jTableReparaciones.getTableHeader().setReorderingAllowed(false);
        jScrollPane2.setViewportView(jTableReparaciones);
        if (jTableReparaciones.getColumnModel().getColumnCount() > 0) {
            jTableReparaciones.getColumnModel().getColumn(0).setPreferredWidth(5);
            jTableReparaciones.getColumnModel().getColumn(2).setPreferredWidth(40);
            jTableReparaciones.getColumnModel().getColumn(3).setPreferredWidth(150);
            jTableReparaciones.getColumnModel().getColumn(4).setPreferredWidth(50);
        }

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 778, Short.MAX_VALUE)
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 300, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        getContentPane().add(jPanel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(420, 350, 790, -1));

        jPanel5.setBorder(javax.swing.BorderFactory.createTitledBorder("Ayuda"));

        jLabel14.setText("Para  Eliminar, selecionar un registro de la tabla y presionar click derecho.");

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel14, javax.swing.GroupLayout.DEFAULT_SIZE, 478, Short.MAX_VALUE)
                .addContainerGap())
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addComponent(jLabel14)
                .addGap(0, 13, Short.MAX_VALUE))
        );

        getContentPane().add(jPanel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 690, 510, 50));

        jButtonVolver.setText("Volver");
        jButtonVolver.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonVolverActionPerformed(evt);
            }
        });
        getContentPane().add(jButtonVolver, new org.netbeans.lib.awtextra.AbsoluteConstraints(1190, 690, 100, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonVolverActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonVolverActionPerformed
        PaginaPrincipal Volver = new PaginaPrincipal();
        Volver.setVisible(true);
        this.dispose();
    }//GEN-LAST:event_jButtonVolverActionPerformed

    private void jButtonAgregarRepuestoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonAgregarRepuestoActionPerformed
        try {
            String NomRep = jTextFieldNombreRE.getText();
            double precio = Double.valueOf(jTextFieldPrecioRE.getText());
            String sql = "CALL AgregarRepuesto('"+NomRep+"',"+precio+")";
            conectar.ExecutarConsulta(sql);
            componente.limpiarTabla(jTableRepuestos);
            componente.llenarTablas(jTableRepuestos,jTableRepuestos.getColumnCount(),""
                    + "SELECT IdRepuesto,NombreRepuesto,PrecioRepuesto FROM repuestos");
            jTextFieldNombreRE.setText("");
            jTextFieldPrecioRE.setText("");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        }
        catch(NumberFormatException ex){
            JOptionPane.showMessageDialog(this,"Precio deben ser numeros \n "+ex,"ERROR",JOptionPane.ERROR_MESSAGE);
        }
    }//GEN-LAST:event_jButtonAgregarRepuestoActionPerformed

    private void jComboBoxMatriculasMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jComboBoxMatriculasMouseClicked
        try {
            jComboBoxMatriculas.removeAllItems();
            componente.llenarCombobox(jComboBoxMatriculas,"SELECT MatriculaVehiculo FROM vehiculo","MatriculaVehiculo");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jComboBoxMatriculasMouseClicked

    private void jComboBoxMatriculasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBoxMatriculasActionPerformed
       if(jComboBoxMatriculas.getSelectedIndex()==-1){
            jTextFieldDueño.setText("");
        }
        else{
            try {
                 String dueño = conectar.duenhoMatricula(jComboBoxMatriculas.getSelectedItem().toString());
                 jTextFieldDueño.setText(dueño);      
            } catch (SQLException ex) {
                Logger.getLogger(ClienteVehiculo.class.getName()).log(Level.SEVERE, null, ex);
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(ClienteVehiculo.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }//GEN-LAST:event_jComboBoxMatriculasActionPerformed

    private void jButtonReparacionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonReparacionActionPerformed
        if(jComboBoxMatriculas.getSelectedIndex()==-1){
            JOptionPane.showMessageDialog(this,"Se debe seleccionar una matricula de la lista","AVISO",JOptionPane.INFORMATION_MESSAGE);
        }
        else if(jComboBoxMecanicoP.getSelectedIndex()==-1){
            JOptionPane.showMessageDialog(this, "Se debe seleccionar un mecánico de la lista","AVISO",JOptionPane.INFORMATION_MESSAGE);
        }
        else{
            try {
                String CedMc = jComboBoxMecanicoP.getSelectedItem().toString();
                String placa = jComboBoxMatriculas.getSelectedItem().toString();
                String sql = "CALL AgregarReparacion ('"+CedMc+"','"+placa+"',1)";
                conectar.ExecutarConsulta(sql);
                componente.limpiarTabla(jTableReparaciones);
                componente.llenarTablas(jTableReparaciones,jTableReparaciones.getColumnCount(),""
                        + "SELECT R.idReparacion,R.CedulaMecanico,R.Matricula,I.Dueño,R.FechaEntrega FROM "
                        + "reparacion as R inner join Vehiculo as V on R.matricula = V.MatriculaVehiculo "
                        + "inner join InformacionCliente as I on I.CedulaCliente = V.CedulaCliente WHERE EstadoReparacion=1");
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
            } catch (SQLException ex) {
                Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }//GEN-LAST:event_jButtonReparacionActionPerformed

    private void jMenuItemEliminarRepuestoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemEliminarRepuestoActionPerformed
        try {
            String sql = "DELETE FROM repuestos WHERE IdRepuesto = "+Integer.valueOf(jTableRepuestos.getValueAt(jTableRepuestos.getSelectedRow(),0).toString());
            System.out.println(sql);
            conectar.ExecutarConsulta(sql);
            componente.limpiarTabla(jTableRepuestos);
            componente.llenarTablas(jTableRepuestos,jTableRepuestos.getColumnCount(),""
                    + "SELECT IdRepuesto,NombreRepuesto,PrecioRepuesto FROM repuestos");
        } catch (SQLException ex) {
            JOptionPane.showMessageDialog(this,"Este repuesto esta en una lista de repuestos de una reparacion, No se puede eliminar","ERROR",JOptionPane.ERROR_MESSAGE);
            //Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ClassNotFoundException ex) {
            //Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
            JOptionPane.showMessageDialog(this, "hubo un error inesperado "+ex,"ERROR",JOptionPane.ERROR_MESSAGE);

        }
    }//GEN-LAST:event_jMenuItemEliminarRepuestoActionPerformed

    private void jMenuItemEliminarRepActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemEliminarRepActionPerformed
        if(jTableReparaciones.getSelectedRow()==-1){
            JOptionPane.showMessageDialog(this,"No se selecciono nunguna fila" , "AVISO",JOptionPane.INFORMATION_MESSAGE);
        }
        try {
            String sql = "DELETE FROM reparacion WHERE idReparacion ="+Integer.valueOf(jTableReparaciones.getValueAt(jTableReparaciones.getSelectedRow(),0).toString());
            conectar.ExecutarConsulta(sql);
            componente.limpiarTabla(jTableReparaciones);
            componente.llenarTablas(jTableReparaciones,jTableReparaciones.getColumnCount(),""
                    + "SELECT R.idReparacion,R.CedulaMecanico,R.Matricula,I.Dueño,R.FechaEntrega FROM "
                    + "reparacion as R inner join Vehiculo as V on R.matricula = V.MatriculaVehiculo "
                    + "inner join InformacionCliente as I on I.CedulaCliente = V.CedulaCliente WHERE EstadoReparacion=1");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
         JOptionPane.showMessageDialog(this,"La reparacion selecionada aun no ha finalizado, NO puede ser Eliminada","ERROR",JOptionPane.ERROR_MESSAGE);
        //Logger.getLogger(RepuestoReparacion.class.getName()).log(Level.SEVERE, null, ex);
        }
       
    }//GEN-LAST:event_jMenuItemEliminarRepActionPerformed

    private void jComboBoxMecanicoPMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jComboBoxMecanicoPMouseClicked
        try {
            jComboBoxMecanicoP.removeAllItems();
            componente.llenarCombobox(jComboBoxMecanicoP,"SELECT CedulaMecanico FROM mecanicos", "CedulaMecanico");
        } catch (ClassNotFoundException ex) {
            Logger.getLogger(Mecanicos.class.getName()).log(Level.SEVERE, null, ex);
        } catch (SQLException ex) {
            Logger.getLogger(Mecanicos.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jComboBoxMecanicoPMouseClicked

    private void jComboBoxMecanicoPActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBoxMecanicoPActionPerformed
       if(jComboBoxMecanicoP.getSelectedIndex()==-1){
            jTextFieldNombreMC.setText("");
        }
        else{
            try {
               String nombre= conectar.nonbreMecanico(jComboBoxMecanicoP.getSelectedItem().toString());
               jTextFieldNombreMC.setText(nombre);
            } catch (ClassNotFoundException ex) {
                Logger.getLogger(Mecanicos.class.getName()).log(Level.SEVERE, null, ex);
            } catch (SQLException ex) {
                Logger.getLogger(Mecanicos.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }//GEN-LAST:event_jComboBoxMecanicoPActionPerformed

    private void jMenuItemVerRepuestosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemVerRepuestosActionPerformed
        if(jTableReparaciones.getSelectedRow() == -1){
            JOptionPane.showMessageDialog(this,"NO selecciono niguna fila","AVISO",JOptionPane.INFORMATION_MESSAGE);
        }
        else{
            int id = Integer.valueOf(jTableReparaciones.getValueAt(jTableReparaciones.getSelectedRow(),0).toString());
            RepuestosEnRepraciones Repuestos = new RepuestosEnRepraciones(id);
            Repuestos.setVisible(true);
    
        }
    }//GEN-LAST:event_jMenuItemVerRepuestosActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(RepuestoReparacion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(RepuestoReparacion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(RepuestoReparacion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(RepuestoReparacion.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new RepuestoReparacion().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonAgregarRepuesto;
    private javax.swing.JButton jButtonReparacion;
    private javax.swing.JButton jButtonVolver;
    private javax.swing.JComboBox<String> jComboBoxMatriculas;
    private javax.swing.JComboBox<String> jComboBoxMecanicoP;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JMenuItem jMenuItemEliminarRep;
    private javax.swing.JMenuItem jMenuItemEliminarRepuesto;
    private javax.swing.JMenuItem jMenuItemVerRepuestos;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPopupMenu jPopupMenuEliminarRE;
    private javax.swing.JPopupMenu jPopupMenuEliminarReparacion;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable jTableReparaciones;
    private javax.swing.JTable jTableRepuestos;
    private javax.swing.JTextField jTextFieldDueño;
    private javax.swing.JTextField jTextFieldNombreMC;
    private javax.swing.JTextField jTextFieldNombreRE;
    private javax.swing.JTextField jTextFieldPrecioRE;
    // End of variables declaration//GEN-END:variables
}
