/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaz;

import com.itextpdf.text.DocumentException;
import java.io.FileNotFoundException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import manejoDeDatos.Facturas;
import manejoDeDatos.Registro;
import manejoDeDatos.llenarJtable;


public class Facturar extends javax.swing.JFrame {
    Facturas nuevaFactura = new Facturas();
    Registro registro  = new Registro();
    llenarJtable llenar = new llenarJtable();
    /**
     * Creates new form Facturar
     */
    public Facturar() {
        initComponents();
        this.setSize(400,200);
        this.setResizable(false);
        this.setLocationRelativeTo(null);
    }
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        seleccionarMesaFacturas = new javax.swing.JComboBox<>();
        jLabel1 = new javax.swing.JLabel();
        nombreCliente = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        generarFactura = new javax.swing.JButton();
        salir = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        seleccionarMesaFacturas.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        seleccionarMesaFacturas.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                seleccionarMesaFacturasMouseClicked(evt);
            }
        });
        getContentPane().add(seleccionarMesaFacturas, new org.netbeans.lib.awtextra.AbsoluteConstraints(160, 20, 90, -1));

        jLabel1.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel1.setText("Nombre Del Cliente");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 70, -1, 20));

        nombreCliente.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(nombreCliente, new org.netbeans.lib.awtextra.AbsoluteConstraints(170, 70, 200, -1));

        jLabel2.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel2.setText("Seleccionar Mesa");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 20, -1, 20));

        generarFactura.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        generarFactura.setText("Generar Factura");
        generarFactura.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                generarFacturaActionPerformed(evt);
            }
        });
        getContentPane().add(generarFactura, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 130, 170, 30));

        salir.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        salir.setText("Salir");
        salir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                salirActionPerformed(evt);
            }
        });
        getContentPane().add(salir, new org.netbeans.lib.awtextra.AbsoluteConstraints(210, 130, 170, 30));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void seleccionarMesaFacturasMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_seleccionarMesaFacturasMouseClicked
        try {
            llenar.MesasPendientesFacturas(seleccionarMesaFacturas);
        } catch (Exception ex) {
            Logger.getLogger(Facturar.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_seleccionarMesaFacturasMouseClicked

    private void generarFacturaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_generarFacturaActionPerformed
        if(seleccionarMesaFacturas.getSelectedIndex()==-1){
            JOptionPane.showMessageDialog(null, "Se Debe selecionar una mesa o aun no hay ordenes pendientes de pago");
        }
        else if (nombreCliente.getText().equals("")){
            JOptionPane.showMessageDialog(null, "Se debe ingregar un nombre");
        }
        else{
            try {
                nuevaFactura.facturar((String) seleccionarMesaFacturas.getSelectedItem(), nombreCliente.getText());
                dispose();
            } catch (DocumentException ex) {
                Logger.getLogger(Facturar.class.getName()).log(Level.SEVERE, null, ex);
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Facturar.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }//GEN-LAST:event_generarFacturaActionPerformed

    private void salirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_salirActionPerformed
       dispose();
    }//GEN-LAST:event_salirActionPerformed

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
            java.util.logging.Logger.getLogger(Facturar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Facturar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Facturar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Facturar.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new Facturar().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton generarFactura;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField nombreCliente;
    private javax.swing.JButton salir;
    private javax.swing.JComboBox<String> seleccionarMesaFacturas;
    // End of variables declaration//GEN-END:variables
}
