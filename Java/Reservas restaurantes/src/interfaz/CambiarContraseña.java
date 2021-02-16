/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaz;


import javax.swing.JOptionPane;
import manejoDeDatos.ValoresIniciales;

/**
 *
 * @author Jordan Araya
 */
public class CambiarContraseña extends javax.swing.JFrame {
    
    /**
     * Creates new form CambiarContraseña
     */
    public CambiarContraseña() {
        initComponents();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setSize(400, 300);
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        campoTextoContraAnterior = new javax.swing.JPasswordField();
        campoTextoNuevaContra = new javax.swing.JPasswordField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        cambiarContraseña = new javax.swing.JButton();
        cancelarContraseña = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        campoTextoContraAnterior.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(campoTextoContraAnterior, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 70, 130, -1));

        campoTextoNuevaContra.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(campoTextoNuevaContra, new org.netbeans.lib.awtextra.AbsoluteConstraints(190, 130, 130, -1));

        jLabel1.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel1.setText("Nueva Contraseña");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 130, 130, -1));

        jLabel2.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel2.setText("Contraseña Actual");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 70, 130, -1));

        cambiarContraseña.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        cambiarContraseña.setText("Cambiar");
        cambiarContraseña.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cambiarContraseñaActionPerformed(evt);
            }
        });
        getContentPane().add(cambiarContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 200, 110, 30));

        cancelarContraseña.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        cancelarContraseña.setText("Cancelar");
        cancelarContraseña.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cancelarContraseñaActionPerformed(evt);
            }
        });
        getContentPane().add(cancelarContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(220, 200, 110, 30));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void cambiarContraseñaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cambiarContraseñaActionPerformed
        ValoresIniciales valores = new ValoresIniciales();
        String antiguaContrasena = campoTextoContraAnterior.getText();
        String nuevaContrasena = campoTextoNuevaContra.getText();
        if (antiguaContrasena.length() > 0 && nuevaContrasena.length() > 0){
            int respuesta = valores.setContrasena(antiguaContrasena, nuevaContrasena);
            if (respuesta > 0){
                JOptionPane.showMessageDialog(null, "Se cambio la contraseña con éxito");
                this.setVisible(false);
            }
            else{
                JOptionPane.showMessageDialog(null, "Contraseña invalida");
            }
        }
        else{
            JOptionPane.showMessageDialog(null, "No puede dejar espacion en blanco");
        }
         
         
    }//GEN-LAST:event_cambiarContraseñaActionPerformed

    private void cancelarContraseñaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cancelarContraseñaActionPerformed
        this.setVisible(false);
    }//GEN-LAST:event_cancelarContraseñaActionPerformed

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
            java.util.logging.Logger.getLogger(CambiarContraseña.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(CambiarContraseña.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(CambiarContraseña.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(CambiarContraseña.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new CambiarContraseña().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton cambiarContraseña;
    private javax.swing.JPasswordField campoTextoContraAnterior;
    private javax.swing.JPasswordField campoTextoNuevaContra;
    private javax.swing.JButton cancelarContraseña;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    // End of variables declaration//GEN-END:variables
}
