package interfaz;

import java.awt.Desktop;
import java.awt.HeadlessException;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JFileChooser;
import manejoDeDatos.*;
import java.io.*;
import java.util.Date;
import javax.swing.JOptionPane;

public class AreaAdministrativa extends javax.swing.JFrame {
    Sustitucion sustituir = new Sustitucion();
    ValoresIniciales valores = new ValoresIniciales();
    Registro registro = new Registro();
    llenarJtable llenar = new llenarJtable();
   
    public AreaAdministrativa() {
        initComponents();
        mostarValoresIniciales();
        llenar.tipoPlatos(TablaTiposDeComidas);
        llenar.Comidas("admin", tablaComidas);
        llenar.llenarTablaFacturas(tablaDeFacturas);
        this.setResizable(false);
        this.setLocationRelativeTo(null);
        this.setExtendedState(MAXIMIZED_BOTH);

      
    }
    
    @SuppressWarnings("unchecked")
    
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        buttonGroup1 = new javax.swing.ButtonGroup();
        jButton1 = new javax.swing.JButton();
        AreaAdministrativa = new javax.swing.JTabbedPane();
        valoresIniciales = new javax.swing.JInternalFrame();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        campoTextoNombreRes = new javax.swing.JTextField();
        campoTextoCedJuridica = new javax.swing.JTextField();
        campoTextoEslogan = new javax.swing.JTextField();
        campoTextoTelefono = new javax.swing.JTextField();
        campoTextoHorario = new javax.swing.JTextField();
        campoTextoContraseña = new javax.swing.JTextField();
        camporTextoFactura = new javax.swing.JTextField();
        guardarDatosValoresI = new javax.swing.JButton();
        cambiarContraseña = new javax.swing.JButton();
        estadisticas = new javax.swing.JInternalFrame();
        jCalendar1 = new com.toedter.calendar.JCalendar();
        fechaInicio = new com.toedter.calendar.JDateChooser();
        fechaFinal = new com.toedter.calendar.JDateChooser();
        jLabel1 = new javax.swing.JLabel();
        jLabel15 = new javax.swing.JLabel();
        jScrollPane4 = new javax.swing.JScrollPane();
        listaPresentacionEstaditica = new javax.swing.JList<>();
        filtroEstadistica = new javax.swing.JComboBox<>();
        confirmarEstadistica = new javax.swing.JButton();
        ConsultaDeFacturas = new javax.swing.JInternalFrame();
        jScrollPane3 = new javax.swing.JScrollPane();
        tablaDeFacturas = new javax.swing.JTable();
        campTextInfoFact = new javax.swing.JButton();
        RegistroDeTipos = new javax.swing.JInternalFrame();
        jScrollPane1 = new javax.swing.JScrollPane();
        TablaTiposDeComidas = new javax.swing.JTable();
        AgregarTipo = new javax.swing.JButton();
        jLabel9 = new javax.swing.JLabel();
        jLabel10 = new javax.swing.JLabel();
        EliminarTipo = new javax.swing.JButton();
        campoTextoID = new javax.swing.JTextField();
        campoTextoTipo = new javax.swing.JTextField();
        registroDeComidas = new javax.swing.JInternalFrame();
        jScrollPane2 = new javax.swing.JScrollPane();
        tablaComidas = new javax.swing.JTable();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        jLabel14 = new javax.swing.JLabel();
        campoTextoIdRC = new javax.swing.JTextField();
        campoTextNombrePlato = new javax.swing.JTextField();
        campTextDescripcion = new javax.swing.JTextField();
        campTextPrecio = new javax.swing.JTextField();
        gurdarPlatillo = new javax.swing.JButton();
        eliminarPlatillo = new javax.swing.JButton();
        comboBoxTipos = new javax.swing.JComboBox<>();
        jLabel16 = new javax.swing.JLabel();
        agregarImagen = new javax.swing.JButton();
        campoTextoImagen = new javax.swing.JTextField();
        jLabel17 = new javax.swing.JLabel();
        crearCombo = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jButton1.setText("Salir");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });
        getContentPane().add(jButton1, new org.netbeans.lib.awtextra.AbsoluteConstraints(650, 690, 108, 40));

        AreaAdministrativa.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));

        valoresIniciales.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        valoresIniciales.setVisible(true);
        valoresIniciales.getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel2.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel2.setText("Contraseña");
        valoresIniciales.getContentPane().add(jLabel2, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 320, -1, -1));

        jLabel3.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel3.setText("Horario ");
        valoresIniciales.getContentPane().add(jLabel3, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 270, -1, -1));

        jLabel4.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel4.setText("Telefono ");
        valoresIniciales.getContentPane().add(jLabel4, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 220, -1, -1));

        jLabel5.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel5.setText("Eslogan");
        valoresIniciales.getContentPane().add(jLabel5, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 170, -1, -1));

        jLabel6.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel6.setText("Cedula Juridica");
        valoresIniciales.getContentPane().add(jLabel6, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 120, -1, -1));

        jLabel7.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel7.setText("Nombre des restaurantes ");
        valoresIniciales.getContentPane().add(jLabel7, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 70, -1, -1));

        jLabel8.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        jLabel8.setText("Siguiente Factura");
        valoresIniciales.getContentPane().add(jLabel8, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 370, -1, -1));

        campoTextoNombreRes.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(campoTextoNombreRes, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 60, 290, 30));

        campoTextoCedJuridica.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(campoTextoCedJuridica, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 110, 290, 30));

        campoTextoEslogan.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(campoTextoEslogan, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 160, 290, 30));

        campoTextoTelefono.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(campoTextoTelefono, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 210, 290, 30));

        campoTextoHorario.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(campoTextoHorario, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 260, 290, 30));

        campoTextoContraseña.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(campoTextoContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 310, 290, 30));

        camporTextoFactura.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        valoresIniciales.getContentPane().add(camporTextoFactura, new org.netbeans.lib.awtextra.AbsoluteConstraints(540, 360, 290, 30));

        guardarDatosValoresI.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        guardarDatosValoresI.setText("Guardar Datos Modificados");
        guardarDatosValoresI.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                guardarDatosValoresIActionPerformed(evt);
            }
        });
        valoresIniciales.getContentPane().add(guardarDatosValoresI, new org.netbeans.lib.awtextra.AbsoluteConstraints(580, 460, -1, 40));

        cambiarContraseña.setFont(new java.awt.Font("Lucida Sans", 1, 12)); // NOI18N
        cambiarContraseña.setText("Cambiar Contraseña");
        cambiarContraseña.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                cambiarContraseñaActionPerformed(evt);
            }
        });
        valoresIniciales.getContentPane().add(cambiarContraseña, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 313, 200, 30));

        AreaAdministrativa.addTab("Valores Inciales", valoresIniciales);

        estadisticas.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        estadisticas.setVisible(true);
        estadisticas.getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());
        estadisticas.getContentPane().add(jCalendar1, new org.netbeans.lib.awtextra.AbsoluteConstraints(30, 60, 370, 220));
        estadisticas.getContentPane().add(fechaInicio, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 90, 160, -1));
        estadisticas.getContentPane().add(fechaFinal, new org.netbeans.lib.awtextra.AbsoluteConstraints(660, 90, 160, -1));

        jLabel1.setText("Fecha Fin");
        estadisticas.getContentPane().add(jLabel1, new org.netbeans.lib.awtextra.AbsoluteConstraints(660, 60, -1, -1));

        jLabel15.setText("Fecha inicio");
        estadisticas.getContentPane().add(jLabel15, new org.netbeans.lib.awtextra.AbsoluteConstraints(450, 60, -1, -1));

        jScrollPane4.setViewportView(listaPresentacionEstaditica);

        estadisticas.getContentPane().add(jScrollPane4, new org.netbeans.lib.awtextra.AbsoluteConstraints(460, 220, 350, -1));

        filtroEstadistica.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Cantidad de órdenes pendientes", "Cantidad de órdenes pagadas", "Promedio de compra" }));
        filtroEstadistica.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                filtroEstadisticaActionPerformed(evt);
            }
        });
        estadisticas.getContentPane().add(filtroEstadistica, new org.netbeans.lib.awtextra.AbsoluteConstraints(480, 160, 290, -1));

        confirmarEstadistica.setText("Confirmar");
        confirmarEstadistica.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                confirmarEstadisticaActionPerformed(evt);
            }
        });
        estadisticas.getContentPane().add(confirmarEstadistica, new org.netbeans.lib.awtextra.AbsoluteConstraints(590, 400, -1, -1));

        AreaAdministrativa.addTab("Estadisticas", estadisticas);

        ConsultaDeFacturas.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        ConsultaDeFacturas.setVisible(true);
        ConsultaDeFacturas.getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        tablaDeFacturas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Identificador ", "Fecha ", "Hora", "Sub Total", "Total"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                true, true, true, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane3.setViewportView(tablaDeFacturas);
        if (tablaDeFacturas.getColumnModel().getColumnCount() > 0) {
            tablaDeFacturas.getColumnModel().getColumn(0).setResizable(false);
            tablaDeFacturas.getColumnModel().getColumn(0).setPreferredWidth(1);
            tablaDeFacturas.getColumnModel().getColumn(1).setResizable(false);
            tablaDeFacturas.getColumnModel().getColumn(1).setPreferredWidth(1);
            tablaDeFacturas.getColumnModel().getColumn(2).setResizable(false);
            tablaDeFacturas.getColumnModel().getColumn(2).setPreferredWidth(1);
            tablaDeFacturas.getColumnModel().getColumn(3).setResizable(false);
            tablaDeFacturas.getColumnModel().getColumn(3).setPreferredWidth(1);
            tablaDeFacturas.getColumnModel().getColumn(4).setResizable(false);
            tablaDeFacturas.getColumnModel().getColumn(4).setPreferredWidth(1);
        }

        ConsultaDeFacturas.getContentPane().add(jScrollPane3, new org.netbeans.lib.awtextra.AbsoluteConstraints(0, 30, 820, 170));

        campTextInfoFact.setText("Mostar Informacion ");
        campTextInfoFact.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campTextInfoFactActionPerformed(evt);
            }
        });
        ConsultaDeFacturas.getContentPane().add(campTextInfoFact, new org.netbeans.lib.awtextra.AbsoluteConstraints(920, 110, -1, -1));

        AreaAdministrativa.addTab("Consultas De Facturas", ConsultaDeFacturas);

        RegistroDeTipos.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        RegistroDeTipos.setVisible(true);
        RegistroDeTipos.getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        TablaTiposDeComidas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Identificador ", "Descripcion Tipo"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane1.setViewportView(TablaTiposDeComidas);
        if (TablaTiposDeComidas.getColumnModel().getColumnCount() > 0) {
            TablaTiposDeComidas.getColumnModel().getColumn(0).setResizable(false);
            TablaTiposDeComidas.getColumnModel().getColumn(0).setPreferredWidth(5);
            TablaTiposDeComidas.getColumnModel().getColumn(1).setResizable(false);
            TablaTiposDeComidas.getColumnModel().getColumn(1).setPreferredWidth(5);
        }

        RegistroDeTipos.getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(340, 80, 510, 400));

        AgregarTipo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        AgregarTipo.setText("Agregar Tipo ");
        AgregarTipo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                AgregarTipoActionPerformed(evt);
            }
        });
        RegistroDeTipos.getContentPane().add(AgregarTipo, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 250, -1, -1));

        jLabel9.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel9.setText("Identificador ");
        RegistroDeTipos.getContentPane().add(jLabel9, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 90, -1, -1));

        jLabel10.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel10.setText("Tipo Descripcion");
        RegistroDeTipos.getContentPane().add(jLabel10, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 160, -1, -1));

        EliminarTipo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        EliminarTipo.setText("Eliminar Tipo ");
        EliminarTipo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                EliminarTipoActionPerformed(evt);
            }
        });
        RegistroDeTipos.getContentPane().add(EliminarTipo, new org.netbeans.lib.awtextra.AbsoluteConstraints(1000, 250, -1, -1));

        campoTextoID.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        RegistroDeTipos.getContentPane().add(campoTextoID, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 120, 230, 20));

        campoTextoTipo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        campoTextoTipo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoTextoTipoActionPerformed(evt);
            }
        });
        RegistroDeTipos.getContentPane().add(campoTextoTipo, new org.netbeans.lib.awtextra.AbsoluteConstraints(860, 190, 230, 20));

        AreaAdministrativa.addTab("Registro De tipos de Comidas", RegistroDeTipos);

        registroDeComidas.setBorder(javax.swing.BorderFactory.createBevelBorder(javax.swing.border.BevelBorder.LOWERED));
        registroDeComidas.setVisible(true);
        registroDeComidas.getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        tablaComidas.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 14)); // NOI18N
        tablaComidas.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {

            },
            new String [] {
                "Identificador ", "Nombre", "Descripcion", "Precio Sin impuesto", "Plato", "Tipo"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false, false, false, false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        tablaComidas.getTableHeader().setReorderingAllowed(false);
        jScrollPane2.setViewportView(tablaComidas);
        if (tablaComidas.getColumnModel().getColumnCount() > 0) {
            tablaComidas.getColumnModel().getColumn(0).setResizable(false);
            tablaComidas.getColumnModel().getColumn(0).setPreferredWidth(1);
            tablaComidas.getColumnModel().getColumn(1).setResizable(false);
            tablaComidas.getColumnModel().getColumn(1).setPreferredWidth(200);
            tablaComidas.getColumnModel().getColumn(2).setResizable(false);
            tablaComidas.getColumnModel().getColumn(2).setPreferredWidth(100);
            tablaComidas.getColumnModel().getColumn(3).setResizable(false);
            tablaComidas.getColumnModel().getColumn(3).setPreferredWidth(5);
            tablaComidas.getColumnModel().getColumn(4).setResizable(false);
            tablaComidas.getColumnModel().getColumn(4).setPreferredWidth(90);
            tablaComidas.getColumnModel().getColumn(5).setResizable(false);
        }

        registroDeComidas.getContentPane().add(jScrollPane2, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 10, 1080, 600));

        jLabel11.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel11.setText("Descripcion");
        registroDeComidas.getContentPane().add(jLabel11, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 130, 180, 20));

        jLabel12.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel12.setText("Nombre Del Plato");
        registroDeComidas.getContentPane().add(jLabel12, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 80, 210, 20));

        jLabel13.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel13.setText("Identificador ");
        registroDeComidas.getContentPane().add(jLabel13, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 40, 200, 20));

        jLabel14.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel14.setText("Precio (Colones)");
        registroDeComidas.getContentPane().add(jLabel14, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 190, 140, -1));

        campoTextoIdRC.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        registroDeComidas.getContentPane().add(campoTextoIdRC, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 60, 210, -1));

        campoTextNombrePlato.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        registroDeComidas.getContentPane().add(campoTextNombrePlato, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 110, 210, -1));

        campTextDescripcion.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        registroDeComidas.getContentPane().add(campTextDescripcion, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 160, 210, -1));

        campTextPrecio.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        registroDeComidas.getContentPane().add(campTextPrecio, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 210, 210, -1));

        gurdarPlatillo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        gurdarPlatillo.setText("Guardar Platillo");
        gurdarPlatillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                gurdarPlatilloActionPerformed(evt);
            }
        });
        registroDeComidas.getContentPane().add(gurdarPlatillo, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 370, -1, -1));

        eliminarPlatillo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        eliminarPlatillo.setText("Eliminar Platillo");
        eliminarPlatillo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                eliminarPlatilloActionPerformed(evt);
            }
        });
        registroDeComidas.getContentPane().add(eliminarPlatillo, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 410, -1, -1));

        comboBoxTipos.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        comboBoxTipos.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                comboBoxTiposMouseClicked(evt);
            }
        });
        registroDeComidas.getContentPane().add(comboBoxTipos, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 260, 210, 20));

        jLabel16.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        jLabel16.setText("Tipo");
        registroDeComidas.getContentPane().add(jLabel16, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 230, 150, 20));

        agregarImagen.setText("Agregar Imagen");
        agregarImagen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                agregarImagenActionPerformed(evt);
            }
        });
        registroDeComidas.getContentPane().add(agregarImagen, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 290, -1, -1));

        campoTextoImagen.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                campoTextoImagenActionPerformed(evt);
            }
        });
        registroDeComidas.getContentPane().add(campoTextoImagen, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 320, 210, 20));
        registroDeComidas.getContentPane().add(jLabel17, new org.netbeans.lib.awtextra.AbsoluteConstraints(840, 150, 260, 480));

        crearCombo.setFont(new java.awt.Font("Lucida Sans Typewriter", 1, 12)); // NOI18N
        crearCombo.setText("Crear Un Combo");
        crearCombo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                crearComboActionPerformed(evt);
            }
        });
        registroDeComidas.getContentPane().add(crearCombo, new org.netbeans.lib.awtextra.AbsoluteConstraints(1130, 450, -1, -1));

        AreaAdministrativa.addTab("Registro De Comidas", registroDeComidas);

        getContentPane().add(AreaAdministrativa, new org.netbeans.lib.awtextra.AbsoluteConstraints(10, 0, 1400, 680));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
      PantallaPrincipal inicio = new PantallaPrincipal();
      inicio.setVisible(true);
      dispose();
      
    }//GEN-LAST:event_jButton1ActionPerformed
    
    private void mostarValoresIniciales(){
        ArrayList datos = valores.getDatos();
        campoTextoNombreRes.setText((String) datos.get(0));
        campoTextoCedJuridica.setText((String) datos.get(1));
        campoTextoEslogan.setText((String) datos.get(2));
        campoTextoTelefono.setText((String) datos.get(3));
        campoTextoHorario.setText((String) datos.get(4));
        campoTextoContraseña.setText((String) datos.get(5));
        campoTextoContraseña.setEnabled(false);
        campoTextoContraseña.setEditable(false);
        camporTextoFactura.setText((String) datos.get(6));
        camporTextoFactura.setEnabled(false);
        camporTextoFactura.setEditable(false);   
    }
       
    private void gurdarPlatilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_gurdarPlatilloActionPerformed
        try{          
            int precio = Integer.valueOf(campTextPrecio.getText());
            if (precio<0){
                JOptionPane.showMessageDialog(null, "El Precio no puede ser negativo");
            }
            else if(campoTextoIdRC.getText().equals("")||campoTextNombrePlato.getText().equals("")||
                    campTextDescripcion.getText().equals("")||campoTextoImagen.getText().equals("")||campTextPrecio.getText().equals("")||comboBoxTipos.getSelectedItem()==null){
                JOptionPane.showMessageDialog(null, "Todos los datos deben ser llenados");
                }

            else{
                int resultado = registro.comidas(sustituir.remplazar(campoTextoIdRC.getText()), sustituir.remplazar(campoTextNombrePlato.getText()), sustituir.remplazar(campTextDescripcion.getText())
                        , sustituir.remplazar(campTextPrecio.getText())
                    , campoTextoImagen.getText(), (String) comboBoxTipos.getSelectedItem());
                switch (resultado) {
                    case -1:
                        JOptionPane.showMessageDialog(null, "No pueden haber nombres ni identificadores repetidos");

                        break;
                    case 1:
                        JOptionPane.showMessageDialog(null, "se agrego Exitosamente");
                        llenar.limpiarTabla(tablaComidas);
                        llenar.Comidas("admin",tablaComidas);
                        campoTextoIdRC.setText("");
                        campoTextNombrePlato.setText("");
                        campTextDescripcion.setText("");
                        campTextPrecio.setText("");
                        campoTextoImagen.setText("");
                        break;
                    default:
                        JOptionPane.showMessageDialog(null, "hubo un errror");
                        break;
                }

            }
        }
        catch(NumberFormatException | HeadlessException e){
            JOptionPane.showMessageDialog(null, "El precio debe ser un numero entero");
        }
        
        
    }//GEN-LAST:event_gurdarPlatilloActionPerformed

    private void guardarDatosValoresIActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_guardarDatosValoresIActionPerformed
        if(campoTextoNombreRes.getText().equals("")||campoTextoCedJuridica.getText().equals("")||campoTextoEslogan.getText().equals("")
                ||campoTextoHorario.getText().equals("")||campoTextoTelefono.getText().equals("")){
            JOptionPane.showMessageDialog(null, "Todos los campos habilitados deben ser llanados");
        }
        else{
            String nombreRes = sustituir.remplazar(campoTextoNombreRes.getText());
            String cedulaJuri = sustituir.remplazar(campoTextoCedJuridica.getText());
            String eslogan = sustituir.remplazar(campoTextoEslogan.getText());
            String telefono = sustituir.remplazar(campoTextoTelefono.getText());
            String horario = sustituir.remplazar(campoTextoHorario.getText());
            int confinrmar =valores.editarValores(nombreRes, eslogan, telefono, cedulaJuri, horario);  
            if(confinrmar==1){
                JOptionPane.showMessageDialog(null, "Los datos fueron almacenandos correctamente");
            }
            else{
                JOptionPane.showMessageDialog(null, "Hubo Un problema");
            }
        }
    }//GEN-LAST:event_guardarDatosValoresIActionPerformed

    private void cambiarContraseñaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_cambiarContraseñaActionPerformed
        CambiarContraseña cambiar = new CambiarContraseña();
        cambiar.setVisible(true);
        
    }//GEN-LAST:event_cambiarContraseñaActionPerformed

    private void AgregarTipoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_AgregarTipoActionPerformed
        if (campoTextoID.getText().equals("")||campoTextoTipo.getText().equals("")){
         JOptionPane.showMessageDialog(null, "Se deben llenar los Espacios");
        }
        else{
            try {
                int resultado = registro.agregarTipoDeComida(sustituir.remplazar(campoTextoID.getText()), sustituir.remplazar(campoTextoTipo.getText()));
                switch (resultado) {
                    case -1:
                        JOptionPane.showMessageDialog(null, "Identificador o tipo repetido");
                        break;
                    case 1:
                        JOptionPane.showMessageDialog(null, "Resitro Exitoso");
                        llenar.limpiarTabla(TablaTiposDeComidas);
                        llenar.tipoPlatos(TablaTiposDeComidas);
                        campoTextoID.setText("");
                        campoTextoTipo.setText("");
                        break;
                    default:
                        JOptionPane.showMessageDialog(null, "Hubo un problema");
                        break;
                }
            } catch (Exception ex) {
                Logger.getLogger(AreaAdministrativa.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
            
        
    }//GEN-LAST:event_AgregarTipoActionPerformed

    private void comboBoxTiposMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_comboBoxTiposMouseClicked
        try {
            llenar.llenarComboBox(comboBoxTipos);
        } catch (Exception ex) {
            Logger.getLogger(AreaAdministrativa.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_comboBoxTiposMouseClicked

    private void eliminarPlatilloActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_eliminarPlatilloActionPerformed
       int fila = tablaComidas.getSelectedRow();
       if(!(fila==-1)){
          String dato = sustituir.remplazar((String) tablaComidas.getValueAt(fila, 1));
          int asosiado = registro.verificarPlato(dato);
          if(asosiado!=0){
            int resultado =registro.eliminarComidas(dato);
            if(resultado==1){
                llenar.limpiarTabla(tablaComidas);
                llenar.Comidas("admin",tablaComidas);
                JOptionPane.showMessageDialog(null, "Los datos fueron eliminaodos exitosamente");
            }
            else if (resultado==2){
                JOptionPane.showMessageDialog(null, "El plato selecionado no puede ser eliminado debido que esta asociado a un combo");
            }
          }
          else{
              JOptionPane.showMessageDialog(null, "El plato que se quiere eliminar ya fue asociado a una orden");
          }
        }
       else{
           JOptionPane.showMessageDialog(null, "Se debe selecionar una opcion");
       }
    }//GEN-LAST:event_eliminarPlatilloActionPerformed

    private void EliminarTipoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_EliminarTipoActionPerformed
       int fila = TablaTiposDeComidas.getSelectedRow();
        if(!(fila==-1)){
            String dato = sustituir.remplazar((String) TablaTiposDeComidas.getValueAt(fila, 1));
            System.out.println(dato);
            int resultado = registro.eliminarTipoComidas(dato);
             switch (resultado) {
                 case -1:
                     JOptionPane.showMessageDialog(null, "El tipo de comida esta asociado a un platillo");
                     break;
                 case 1:
                     llenar.limpiarTabla(TablaTiposDeComidas);
                     llenar.tipoPlatos(TablaTiposDeComidas);
                     JOptionPane.showMessageDialog(null, "El tipo fue eliminado correctamente");
                     break;
                 case 2:
                     JOptionPane.showMessageDialog(null, "El tipo 'Combo' no puede ser eliminado");
                     break;
                 default:
                     break;
             }
        }
        else{
            JOptionPane.showMessageDialog(null, "Se debe seleccionar una opcion");
        }
    }//GEN-LAST:event_EliminarTipoActionPerformed

    private void agregarImagenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_agregarImagenActionPerformed
        JFileChooser fileChooser = new JFileChooser();
        int seleccion = fileChooser.showSaveDialog(this);
        if (seleccion == JFileChooser.APPROVE_OPTION) {
           File fichero = fileChooser.getSelectedFile();
           if(fichero !=null){
               String nombreArchivo = fichero.getAbsolutePath();
               if(nombreArchivo.endsWith(".png")||nombreArchivo.endsWith(".jpg")||
                    nombreArchivo.endsWith(".jpeg")){
                    campoTextoImagen.setText(fichero.getAbsolutePath());
                    campoTextoImagen.setEnabled(false);
                    campoTextoImagen.setEditable(false);
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

    private void campoTextoTipoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoTextoTipoActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoTextoTipoActionPerformed

    private void campoTextoImagenActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campoTextoImagenActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_campoTextoImagenActionPerformed

    private void campTextInfoFactActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_campTextInfoFactActionPerformed
        if(tablaDeFacturas.getSelectedRow()==-1){
            JOptionPane.showMessageDialog(null, "Se debe selecconar una opcion");
        }
        else{
            try {
                int seleccion = tablaDeFacturas.getSelectedRow();
                String factura = sustituir.remplazar((String) tablaDeFacturas.getValueAt(seleccion, 0));
                String ubicacar = "Factura Numero "+factura+".pdf";
                File ubicacion = new File(ubicacar);
                File ubicar = ubicacion.getAbsoluteFile();
                Desktop.getDesktop().open(ubicar);
            } catch (IOException ex) {
                Logger.getLogger(AreaAdministrativa.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }//GEN-LAST:event_campTextInfoFactActionPerformed

    private void confirmarEstadisticaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_confirmarEstadisticaActionPerformed

        if(fechaInicio.getDate()==null||fechaFinal.getDate()==null){
            JOptionPane.showMessageDialog(null, "Se deben llenar los espacios de fecha");
        }
        else{
            Date fechaInicial = fechaInicio.getDate();
            Date fechaFinaliza = fechaFinal.getDate();
            if(fechaFinaliza.before(fechaInicial)&!fechaFinaliza.equals(fechaInicial)){
                JOptionPane.showMessageDialog(null, "La fecha de inicio no puede mayor que la final");
            }
            else{
                llenar.llenarListaEstadistica(listaPresentacionEstaditica, (String) filtroEstadistica.getSelectedItem(),fechaInicial,fechaFinaliza);
            }
        }
    }//GEN-LAST:event_confirmarEstadisticaActionPerformed

    private void crearComboActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_crearComboActionPerformed
        Combo nuevoCombo = new Combo();
        nuevoCombo.setVisible(true);
    }//GEN-LAST:event_crearComboActionPerformed

    private void filtroEstadisticaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_filtroEstadisticaActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_filtroEstadisticaActionPerformed

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(() -> {
            new AreaAdministrativa().setVisible(true);
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton AgregarTipo;
    private javax.swing.JTabbedPane AreaAdministrativa;
    private javax.swing.JInternalFrame ConsultaDeFacturas;
    private javax.swing.JButton EliminarTipo;
    private javax.swing.JInternalFrame RegistroDeTipos;
    private javax.swing.JTable TablaTiposDeComidas;
    private javax.swing.JButton agregarImagen;
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JButton cambiarContraseña;
    private javax.swing.JTextField campTextDescripcion;
    private javax.swing.JButton campTextInfoFact;
    private javax.swing.JTextField campTextPrecio;
    private javax.swing.JTextField campoTextNombrePlato;
    private javax.swing.JTextField campoTextoCedJuridica;
    private javax.swing.JTextField campoTextoContraseña;
    private javax.swing.JTextField campoTextoEslogan;
    private javax.swing.JTextField campoTextoHorario;
    private javax.swing.JTextField campoTextoID;
    private javax.swing.JTextField campoTextoIdRC;
    private javax.swing.JTextField campoTextoImagen;
    private javax.swing.JTextField campoTextoNombreRes;
    private javax.swing.JTextField campoTextoTelefono;
    private javax.swing.JTextField campoTextoTipo;
    private javax.swing.JTextField camporTextoFactura;
    private javax.swing.JComboBox<String> comboBoxTipos;
    private javax.swing.JButton confirmarEstadistica;
    private javax.swing.JButton crearCombo;
    private javax.swing.JButton eliminarPlatillo;
    private javax.swing.JInternalFrame estadisticas;
    private com.toedter.calendar.JDateChooser fechaFinal;
    private com.toedter.calendar.JDateChooser fechaInicio;
    private javax.swing.JComboBox<String> filtroEstadistica;
    private javax.swing.JButton guardarDatosValoresI;
    private javax.swing.JButton gurdarPlatillo;
    private javax.swing.JButton jButton1;
    private com.toedter.calendar.JCalendar jCalendar1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel16;
    private javax.swing.JLabel jLabel17;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JList<String> listaPresentacionEstaditica;
    private javax.swing.JInternalFrame registroDeComidas;
    private javax.swing.JTable tablaComidas;
    private javax.swing.JTable tablaDeFacturas;
    private javax.swing.JInternalFrame valoresIniciales;
    // End of variables declaration//GEN-END:variables
}
