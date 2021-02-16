/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfaz;

import Logica.Prolog;
import java.awt.Color;
import java.awt.Font;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.JTextField;

/**
 *
 * @author Jordan Araya
 */
public class Principal extends javax.swing.JFrame {
    ArrayList<JTextField> tableroActual = new ArrayList();
    ArrayList<Object> solucion = new ArrayList();
    /**
     * Creates new form Principal
     */
    public Principal() {
        initComponents();
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setExtendedState(MAXIMIZED_BOTH);
        crearTablero();
        cronometro.start();
    }
    
    /**
     * E: Ninguna.
     * S: Muestra los campos de tengo en pantalla en forma de tablero
     * R: Ninguna
     * O: Mostras en patalla un tablero de kakuros.
     */
    public void crearTablero()
    {
        ArrayList<JTextField> tablero = listaTextBox();
        int x=50;
        int y=0;
        for(int i=0; i<81;i++)
        {
            if(i%9==0)
            {
                y+=70;
                x=70;
            }
            getContentPane().add(tablero.get(i), new org.netbeans.lib.awtextra.AbsoluteConstraints(x, y, 70, 70));
            x+=70;
        }
    }
    /**
     * E: Ninguna,
     * S: Una lista de JTextField cada uno con propiedades distintos y metodos.
     * R: Ninguna
     * @return 
     */
    public ArrayList listaTextBox()
    {
//        Prolog solucion = new Prolog();
        //this.solucion = solucion.tablero();
        ArrayList<Object> tab  = this.solucion;
       
        for(int i =0;i<81;i++)
        {
            JTextField campo = new JTextField();
            campo.setName("Campo"+i);
            campo.setHorizontalAlignment(JTextField.CENTER);
            campo.addKeyListener(new java.awt.event.KeyAdapter() 
            {
            @Override
            public void keyTyped(java.awt.event.KeyEvent evt) 
            {
                campoKeyTyped(evt,campo);
            }
            @Override
            public void keyReleased(java.awt.event.KeyEvent evt) 
            {
                campoKeyReleased(evt);
            }
            });
            
           /* if(tab.get(i).toString().contains("/"))
            {
                campo.setText(tab.get(i).toString());
                campo.setEnabled(false);
            }*/
            /*else if("-1".equals(tab.get(i).toString()))
            {
                campo.setText("");
                campo.setEnabled(false);
            }*/
            /*else
            {
                Font fuente=new Font("Dialog", Font.BOLD, 36);
                campo.setText("");
                campo.setEnabled(true);
                campo.setBackground(Color.LIGHT_GRAY);
                campo.setForeground(Color.BLACK);
                campo.setFont(fuente);
            }*/
            tableroActual.add(campo);
        }    
        return tableroActual;
    }
    /**
     * E: Evento KeyTyped y la cadena de texto que tiene el JTexField
     * S: Impide que el usuario pueda escribir letras y solo numeros del 1 al 9
     * R: Ninguna.
     * O: Impedir que el usuario altere el funcionamiento del juego
     * @param evt 
     * @param cadena 
     */
    private void campoKeyTyped(java.awt.event.KeyEvent evt,JTextField cadena)
    {
        char c = evt.getKeyChar();
        if(c<'1' || c>'9' | cadena.getText().length()>=1) evt.consume();
        
    }
    /**
     * E: Ninguna
     * S: Presenta en la JLabel jLabelDigitos la cantidad de campos llenos que hay en el tablero
     * R: Depende de los campos ingresados en el tablero
     * O: Mostar una estadistica en tiempo real al usuario, de la cantidad de campos llenos que hay en el tablero
     */
    private void cantidadDitigitos()
    {
        jLabelDigitos.setText("0");
        int digitos =0;
        for(int i=0;i<81;i++)
        {
            Object valor = tableroActual.get(i).getText();
            if(!("-1".equals(valor.toString()) | valor.toString().contains("/") | valor.toString().equals("")))
            {
                digitos+=1;
            }
        }
        jLabelDigitos.setText(String.valueOf(digitos));
    }
    /**
     * Se llama la funcion cantidadDitigitos() Cuando se agrega se esribe algo en los JTexrField
     * @param evt 
     */
    private void campoKeyReleased(java.awt.event.KeyEvent evt)
    {
            cantidadDitigitos();
    }
    
    /**
     * Un hilo para presentar el cronometro en pantalla.
     */
    Thread cronometro = new Thread()
    {
        @Override
        public void run()
        {
            int hora =0, minuto=0, segundo=1;
            for(;;)
            {
            try 
            {
                segundo++;
                if(segundo>59)
                {
                    segundo=0;
                    minuto++;
                }
                if(minuto>59)
                {
                    segundo=0;
                    minuto=0;
                    hora++;
                }
              jLabelCronometro.setText(hora+":"+minuto+":"+segundo);
              Thread.sleep(10);  
            }   
            catch (Exception e) {}
                
            }
        }
    };
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel2 = new javax.swing.JLabel();
        jLabelCronometro = new javax.swing.JLabel();
        jPanel3 = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jLabelDigitos = new javax.swing.JLabel();
        jLabelVerificaciones = new javax.swing.JLabel();
        jLabelErrores = new javax.swing.JLabel();
        jLabelSugeres = new javax.swing.JLabel();
        jLabelFinalizacion = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jLabelIntentos = new javax.swing.JLabel();
        jButtonEstadisticas = new javax.swing.JButton();
        jLabel10 = new javax.swing.JLabel();
        jPanel2 = new javax.swing.JPanel();
        jButtonSolucion = new javax.swing.JButton();
        jButtonSugerir = new javax.swing.JButton();
        jButtonVerificar = new javax.swing.JButton();
        jButtonReiniciar = new javax.swing.JButton();
        jButtonNuevoJuego = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Juego - KAKUROS");
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Estadisticas Generales"));
        jPanel1.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel2.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabel2.setText("Tiempo:");
        jPanel1.add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(420, 30, -1, -1));

        jLabelCronometro.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabelCronometro.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jPanel1.add(jLabelCronometro, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 60, 140, 30));

        jPanel3.setBorder(javax.swing.BorderFactory.createTitledBorder("Estadisticas del Juego"));
        jPanel3.setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel4.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel4.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel4.setText("Cantidad de celdas de ingreso de dígitos");
        jPanel3.add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(14, 16, 330, -1));

        jLabel5.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel5.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel5.setText("Cantidad de verificaciones realizadas");
        jPanel3.add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 81, 324, -1));

        jLabel6.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel6.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel6.setText("Cantidad de errores de verificación");
        jPanel3.add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 141, 320, -1));

        jLabel7.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel7.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel7.setText("Cantidad de sugerencias utilizadas");
        jPanel3.add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 203, 320, -1));

        jLabel8.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel8.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel8.setText("Tipo Finalización");
        jPanel3.add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 280, 328, -1));

        jLabelDigitos.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabelDigitos.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelDigitos.setText("0");
        jPanel3.add(jLabelDigitos, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 40, 70, 40));

        jLabelVerificaciones.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabelVerificaciones.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelVerificaciones.setText("0");
        jPanel3.add(jLabelVerificaciones, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 100, 70, 40));

        jLabelErrores.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabelErrores.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelErrores.setText("0");
        jPanel3.add(jLabelErrores, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 160, 70, 40));

        jLabelSugeres.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabelSugeres.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelSugeres.setText("0");
        jPanel3.add(jLabelSugeres, new org.netbeans.lib.awtextra.AbsoluteConstraints(140, 230, 70, 40));

        jLabelFinalizacion.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jLabelFinalizacion.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelFinalizacion.setText("Juego en Curso");
        jPanel3.add(jLabelFinalizacion, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 310, 310, 30));

        jPanel1.add(jPanel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(20, 20, 360, 350));

        jLabel9.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel9.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel9.setText("Estadisticas");
        jPanel1.add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(380, 300, 160, -1));

        jLabelIntentos.setFont(new java.awt.Font("Snap ITC", 1, 48)); // NOI18N
        jLabelIntentos.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabelIntentos.setText("5");
        jPanel1.add(jLabelIntentos, new org.netbeans.lib.awtextra.AbsoluteConstraints(410, 160, 110, 80));

        jButtonEstadisticas.setFont(new java.awt.Font("Snap ITC", 2, 18)); // NOI18N
        jButtonEstadisticas.setText("Ver");
        jButtonEstadisticas.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonEstadisticasActionPerformed(evt);
            }
        });
        jPanel1.add(jButtonEstadisticas, new org.netbeans.lib.awtextra.AbsoluteConstraints(400, 330, 130, 30));

        jLabel10.setFont(new java.awt.Font("Snap ITC", 2, 14)); // NOI18N
        jLabel10.setText("Intentos Restantes");
        jPanel1.add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(390, 140, -1, -1));

        getContentPane().add(jPanel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(790, 0, 550, 380));

        jPanel2.setBorder(javax.swing.BorderFactory.createTitledBorder("Juego"));

        jButtonSolucion.setFont(new java.awt.Font("Snap ITC", 2, 24)); // NOI18N
        jButtonSolucion.setText("VER SOLUCION");
        jButtonSolucion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSolucionActionPerformed(evt);
            }
        });

        jButtonSugerir.setFont(new java.awt.Font("Snap ITC", 2, 24)); // NOI18N
        jButtonSugerir.setText("SUGERIR");
        jButtonSugerir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonSugerirActionPerformed(evt);
            }
        });

        jButtonVerificar.setFont(new java.awt.Font("Snap ITC", 2, 24)); // NOI18N
        jButtonVerificar.setText("VERIFICAR");
        jButtonVerificar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonVerificarActionPerformed(evt);
            }
        });

        jButtonReiniciar.setFont(new java.awt.Font("Snap ITC", 2, 24)); // NOI18N
        jButtonReiniciar.setText("REINICIAR");
        jButtonReiniciar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonReiniciarActionPerformed(evt);
            }
        });

        jButtonNuevoJuego.setFont(new java.awt.Font("Snap ITC", 2, 24)); // NOI18N
        jButtonNuevoJuego.setText("NUEVA PARTIDA");
        jButtonNuevoJuego.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButtonNuevoJuegoActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addGap(33, 33, 33)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jButtonNuevoJuego, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButtonReiniciar, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButtonVerificar, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButtonSolucion, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButtonSugerir, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(35, 35, 35))
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addComponent(jButtonSugerir, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jButtonVerificar, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jButtonSolucion, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jButtonReiniciar, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jButtonNuevoJuego, javax.swing.GroupLayout.PREFERRED_SIZE, 50, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        getContentPane().add(jPanel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(790, 380, 550, 320));

        jLabel1.setFont(new java.awt.Font("Snap ITC", 2, 36)); // NOI18N
        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("KAKUROS");
        jLabel1.setHorizontalTextPosition(javax.swing.SwingConstants.CENTER);
        getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(110, 10, 550, 50));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButtonReiniciarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonReiniciarActionPerformed
       for(int i=0; i<81;i++)
        {
            Object valor = solucion.get(i);
            if(!("-1".equals(valor.toString()) | valor.toString().contains("/")))
            {
                tableroActual.get(i).setText("");
                tableroActual.get(i).setEnabled(true);
            }  
            jButtonSugerir.setEnabled(true);
            jButtonVerificar.setEnabled(true);
            jLabelFinalizacion.setText("Juego en Curso");
            cantidadDitigitos();
        }
    }//GEN-LAST:event_jButtonReiniciarActionPerformed

    private void jButtonSugerirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSugerirActionPerformed
        int intentos = Integer.valueOf(jLabelIntentos.getText());
        if(intentos==0)
        {
            JOptionPane.showMessageDialog(this, "Se agotaron las sugerencias","AVISO",JOptionPane.INFORMATION_MESSAGE);
        }
        else
        {
            Object valor;
            boolean ciclo=true;
            while(ciclo)
            {
               int numero = (int) (Math.random() * 80) + 1;
               valor = solucion.get(numero);
               if( "-1".equals(valor.toString()) | valor.toString().contains("/"))
               {
                   ciclo=true;
               }
               else
               {
                   if(tableroActual.get(numero).getText().equals(""))
                   {
                       tableroActual.get(numero).setText(valor.toString());
                       ciclo=false;
                   }   
               }
            }        
            jLabelIntentos.setText(String.valueOf(intentos-1));
            int utilizados = Integer.valueOf(jLabelSugeres.getText());
            jLabelSugeres.setText((String.valueOf(utilizados+1)));
            cantidadDitigitos();
        }
        
    }//GEN-LAST:event_jButtonSugerirActionPerformed

    private void jButtonVerificarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonVerificarActionPerformed
        int verificacion = Integer.valueOf(jLabelVerificaciones.getText());
        jLabelVerificaciones.setText(String.valueOf(verificacion+1));
        int errores = Integer.valueOf(jLabelErrores.getText());
        int vacios = 0;
        int correctos =0;
        int incorrectos =0;
        for(int i =0;i<81;i++)
        {
            Object valor = solucion.get(i);
            if("-1".equals(valor.toString()) | valor.toString().contains("/"))
            {}
            else
            {
                if(tableroActual.get(i).getText().equals(""))
                {
                    vacios+=1;
                }
                else if(tableroActual.get(i).getText().equals(valor.toString()))
                {
                    correctos+=1;
                }
                else
                {
                    incorrectos+=1;
                }
            }
            jLabelErrores.setText(String.valueOf(errores+incorrectos));
        }
        if(vacios ==0 & incorrectos==0)
        {
            jLabelFinalizacion.setText("Juego Exitoso");
            JOptionPane.showMessageDialog(this, "¡Felicidades haz Ganado!","¡Enhorabuena!",JOptionPane.INFORMATION_MESSAGE);
        }
        else
        {
        JOptionPane.showMessageDialog(this, "Informacion de la Verificaion\nCampos Vacios = "+vacios+"\nCampos Correctos ="+correctos+"\nCampos Incorrectos ="+incorrectos,"Informacion",JOptionPane.INFORMATION_MESSAGE);
        }
    }//GEN-LAST:event_jButtonVerificarActionPerformed

    private void jButtonSolucionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonSolucionActionPerformed
        for(int i=0; i<81;i++)
        {
            Object valor = solucion.get(i);
            if(!("-1".equals(valor.toString()) | valor.toString().contains("/")))
            {
                tableroActual.get(i).setText(String.valueOf(solucion.get(i)));
                tableroActual.get(i).setEnabled(false);
            }  
        }
        jLabelFinalizacion.setText("Autosolucíon");
        jButtonSugerir.setEnabled(false);
        jButtonVerificar.setEnabled(false);// COMENTAR LINEA PARA PROBAR GANE
        jButtonReiniciar.setEnabled(false);
        cantidadDitigitos();
    }//GEN-LAST:event_jButtonSolucionActionPerformed

    private void jButtonNuevoJuegoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonNuevoJuegoActionPerformed
        if(!(jLabelFinalizacion.getText().toLowerCase().equals("autosolucíon") | jLabelFinalizacion.getText().toLowerCase().equals("juego exitoso")))
        {
            jLabelFinalizacion.setText("Abandono de partida");
        }
        int reply = JOptionPane.showConfirmDialog(null, "¿Esta seguro que quieres abandonar la partida?", "¿?", JOptionPane.YES_NO_OPTION);
        if (reply == JOptionPane.YES_OPTION)
        {
            ArrayList<String> estadistica = new ArrayList();
            estadistica.add("Partida "+(Prolog.Estadisticas.size()+1));
            estadistica.add(jLabelDigitos.getText());
            estadistica.add(jLabelVerificaciones.getText());
            estadistica.add(jLabelErrores.getText());
            estadistica.add(jLabelSugeres.getText());
            estadistica.add(jLabelFinalizacion.getText());
            estadistica.add(jLabelCronometro.getText());
            Prolog.Estadisticas.add(estadistica);
            Principal recargar = new Principal();
            recargar.setVisible(true);
            this.dispose();
        }
        else
        {
            jLabelFinalizacion.setText("Juego en Curso");
        }
        
    }//GEN-LAST:event_jButtonNuevoJuegoActionPerformed

    private void jButtonEstadisticasActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonEstadisticasActionPerformed
           Estadistica estadistica = new Estadistica(this,true);
           estadistica.setVisible(true);
           
    }//GEN-LAST:event_jButtonEstadisticasActionPerformed

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
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(Principal.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(() -> {
            new Principal().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonEstadisticas;
    private javax.swing.JButton jButtonNuevoJuego;
    private javax.swing.JButton jButtonReiniciar;
    private javax.swing.JButton jButtonSolucion;
    private javax.swing.JButton jButtonSugerir;
    private javax.swing.JButton jButtonVerificar;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JLabel jLabelCronometro;
    private javax.swing.JLabel jLabelDigitos;
    private javax.swing.JLabel jLabelErrores;
    private javax.swing.JLabel jLabelFinalizacion;
    private javax.swing.JLabel jLabelIntentos;
    private javax.swing.JLabel jLabelSugeres;
    private javax.swing.JLabel jLabelVerificaciones;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    // End of variables declaration//GEN-END:variables
}
