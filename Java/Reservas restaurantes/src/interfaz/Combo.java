/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaz;

import java.awt.HeadlessException;
import java.io.File;
import javax.swing.JFileChooser;
import javax.swing.JOptionPane;
import manejoDeDatos.Sustitucion;
import manejoDeDatos.llenarJtable;

/**
 *
 * @author Jordan Araya
 */
public class Combo extends javax.swing.JFrame {
    llenarJtable llenar = new llenarJtable();
    AreaAdministrativa admi = new AreaAdministrativa();
    Sustitucion sustituir = new Sustitucion();

    /**
     * Creates new form Combo
     */
    public Combo() {
        initComponents();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setExtendedState(MAXIMIZED_BOTH);
        llenar.Comidas("Combo", menuComidas);
        campoImagen.setEnabled(false);
        
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jScrollPane2 = new javax.swing.JScrollPane();
        menuComidas = new javax.swing.JTable();
        jLabel1 = new javax.swing.JLabel();
        Salir = new javax.swing.JButton();
        campoImagen = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        campoIdentificado = new javax.swing.JTextField();
        campoPrecio = new javax.swing.JTextField();
        agregarImagen = new javax.swing.JButton();
        crearCombo = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        menuComidas.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        menuComidas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Identificador ", "Nombre", "Descripcion", "Precio Sin impuesto", "Plato", "Tipo", "Cantidad", "Agregar"
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
        jScrollPane2.setViewportView(menuComidas);

        getContentPane().add(jScrollPane2, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 20, 1080, 750));

        jLabel1.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel1.setText("Precio");
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 110, -1, -1));

        Salir.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        Salir.setText("Salir");
        Salir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                SalirActionPerformed(evt);
            }
        });
        getContentPane().add(Salir, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 300, 160, -1));

        campoImagen.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(campoImagen, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 210, 160, -1));

        jLabel2.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel2.setText("Identificador del Combo");
        getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 40, -1, -1));

        campoIdentificado.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(campoIdentificado, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 70, 160, -1));

        campoPrecio.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        getContentPane().add(campoPrecio, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 130, 160, -1));

        agregarImagen.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        agregarImagen.setText("Agregar imagen");
        agregarImagen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                agregarImagenActionPerformed(evt);
            }
        });
        getContentPane().add(agregarImagen, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 170, -1, -1));

        crearCombo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        crearCombo.setText("Crear Combo");
        crearCombo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                crearComboActionPerformed(evt);
            }
        });
        getContentPane().add(crearCombo, new org.netbeans.lib.awtextra.AbsoluteConstraints(1110, 250, 160, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void SalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_SalirActionPerformed
        dispose();
    }//GEN-LAST:event_SalirActionPerformed

    private void agregarImagenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_agregarImagenActionPerformed
        JFileChooser fileChooser = new JFileChooser();
        int seleccion = fileChooser.showSaveDialog(this);
        if (seleccion == JFileChooser.APPROVE_OPTION) {
           File fichero = fileChooser.getSelectedFile();
           if(fichero !=null){
               String nombreArchivo = fichero.getAbsolutePath();
               if(nombreArchivo.endsWith(".png")||nombreArchivo.endsWith(".jpg")||
                    nombreArchivo.endsWith(".jpeg")){
                    campoImagen.setText(fichero.getAbsolutePath());
                    campoImagen.setEnabled(false);
                    campoImagen.setEditable(false);
               }
               else{
                   JOptionPane.showMessageDialog(null, "Se debe agregar un archivo con un formato .png, .jpn o .jpeg");
               }
           }
           else{
               JOptionPane.showMessageDialog(null, "Debe agregar una imagen");
           }
        }
    }//GEN-LAST:event_agregarImagenActionPerformed

    private void crearComboActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_crearComboActionPerformed
        if(campoIdentificado.getText().equals("")||campoPrecio.getText().equals("")||campoImagen.getText().equals("")){
            JOptionPane.showMessageDialog(null, "Se deben llenar los espacios");
        }
        else{
            try{
                String cantidad = (String) menuComidas.getValueAt(menuComidas.getSelectedRow(),6);
                int precio = Integer.valueOf(campoPrecio.getText());
                if (precio<1){
                    JOptionPane.showMessageDialog(null, "El precio no puede ser menor a 0");
                }
                else{
                   int resultado=llenar.prepararCombo(sustituir.remplazar(campoIdentificado.getText()),campoPrecio.getText(), campoImagen.getText(), menuComidas);
                    switch (resultado) {
                        case 1:
                            JOptionPane.showMessageDialog(null,"El combo se guardo exitosamente");
                            dispose();
                            break;
                        case 2:
                            JOptionPane.showMessageDialog(null, "No se pueden agregar combos a un combo");
                            break;
                        case -1:
                            JOptionPane.showMessageDialog(null, "Identificador ya existe");
                            break;
                        default:
                            JOptionPane.showMessageDialog(null, "Se deben selecionar platos para poder crear un combo");
                            break;
                    }
                }
            }
            catch(Exception e){
                JOptionPane.showMessageDialog(null, "Se detencto un Error puede ser por dos opciones\n 1-El precio es negativo\n 2-No se escogio una cantidad");
            }
        }
    }//GEN-LAST:event_crearComboActionPerformed

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
            java.util.logging.Logger.getLogger(Combo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Combo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Combo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Combo.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new Combo().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton Salir;
    private javax.swing.JButton agregarImagen;
    private javax.swing.JTextField campoIdentificado;
    private javax.swing.JTextField campoImagen;
    private javax.swing.JTextField campoPrecio;
    private javax.swing.JButton crearCombo;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JTable menuComidas;
    // End of variables declaration//GEN-END:variables
}