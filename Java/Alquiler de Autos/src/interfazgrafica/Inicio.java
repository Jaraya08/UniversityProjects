/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfazgrafica;

import opcionesadministrativas.ValoresDeInicio;
/**
 *
 * @author Warner Diaz
 */
public class Inicio extends javax.swing.JFrame {
    ValoresDeInicio valores;
    /**
     * Creates new form Inicio
     */
    public Inicio() {
        initComponents();
        this.setLocationRelativeTo(null);
        this.setSize(870,485);
        this.setResizable(false);
        valores = new ValoresDeInicio();
        this.jLabelNombre.setText(valores.getNombre());
        this.jLabelEslogan.setText(valores.getEslogan());
        this.jLabelCedula.setText("Cédula Jurídica: "+valores.getCedulaJuridica());
        this.jLabelHorario.setText("Horario de Atención: "+valores.getHorario());
        this.jLabelTelefono.setText("Teléfono: "+valores.getTelefono());
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jButtonOpcAdm = new javax.swing.JButton();
        jButtonOpcGen = new javax.swing.JButton();
        jButtonSalir = new javax.swing.JButton();
        jLabelNombre = new javax.swing.JLabel();
        jLabelEslogan = new javax.swing.JLabel();
        jLabelHorario = new javax.swing.JLabel();
        jLabelCedula = new javax.swing.JLabel();
        jLabelTelefono = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(new java.awt.Color(0, 0, 0));
        setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jButtonOpcAdm.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jButtonOpcAdm.setText("Opciones Administrativas");
        jButtonOpcAdm.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jButtonOpcAdm.setBorderPainted(false);
        jButtonOpcAdm.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        jButtonOpcAdm.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jButtonOpcAdmMouseClicked(evt);
            }
        });
        getContentPane().add(jButtonOpcAdm, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 310, 220, 50));

        jButtonOpcGen.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jButtonOpcGen.setText("Opciones Generales");
        jButtonOpcGen.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        jButtonOpcGen.setBorderPainted(false);
        jButtonOpcGen.setCursor(new java.awt.Cursor(java.awt.Cursor.HAND_CURSOR));
        jButtonOpcGen.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jButtonOpcGenMouseClicked(evt);
            }
        });
        getContentPane().add(jButtonOpcGen, new org.netbeans.lib.awtextra.AbsoluteConstraints(310, 310, 220, 50));

        jButtonSalir.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jButtonSalir.setText("Salir");
        jButtonSalir.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jButtonSalir.setBorderPainted(false);
        jButtonSalir.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                jButtonSalirMouseClicked(evt);
            }
        });
        getContentPane().add(jButtonSalir, new org.netbeans.lib.awtextra.AbsoluteConstraints(590, 310, 220, 50));

        jLabelNombre.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jLabelNombre.setText("Nombre");
        getContentPane().add(jLabelNombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 10, 400, 40));

        jLabelEslogan.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jLabelEslogan.setText("Eslogan");
        getContentPane().add(jLabelEslogan, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 60, 400, 30));

        jLabelHorario.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jLabelHorario.setText("Cedula");
        getContentPane().add(jLabelHorario, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 100, 400, 40));

        jLabelCedula.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jLabelCedula.setText("Telefono");
        getContentPane().add(jLabelCedula, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 140, 400, 40));

        jLabelTelefono.setFont(new java.awt.Font("Century Schoolbook", 2, 14)); // NOI18N
        jLabelTelefono.setText("Horario");
        getContentPane().add(jLabelTelefono, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 190, 400, 40));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonOpcAdmMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButtonOpcAdmMouseClicked
        this.setVisible(false);
        Login ventana = new Login();
        ventana.setVisible(true);
    }//GEN-LAST:event_jButtonOpcAdmMouseClicked

    private void jButtonOpcGenMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButtonOpcGenMouseClicked
        this.setVisible(false);
        OpcionesGenerales ventana = new OpcionesGenerales();
        ventana.setVisible(true);
    }//GEN-LAST:event_jButtonOpcGenMouseClicked

    private void jButtonSalirMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jButtonSalirMouseClicked
       System.exit(0);
    }//GEN-LAST:event_jButtonSalirMouseClicked

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
            java.util.logging.Logger.getLogger(Inicio.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Inicio.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Inicio.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Inicio.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Inicio().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonOpcAdm;
    private javax.swing.JButton jButtonOpcGen;
    private javax.swing.JButton jButtonSalir;
    private javax.swing.JLabel jLabelCedula;
    private javax.swing.JLabel jLabelEslogan;
    private javax.swing.JLabel jLabelHorario;
    private javax.swing.JLabel jLabelNombre;
    private javax.swing.JLabel jLabelTelefono;
    // End of variables declaration//GEN-END:variables
}
