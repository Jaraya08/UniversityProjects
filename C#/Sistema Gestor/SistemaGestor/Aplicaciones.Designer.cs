namespace SistemaGestor
{
    partial class Aplicaciones
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle1 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle2 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle5 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle6 = new System.Windows.Forms.DataGridViewCellStyle();
            this.cLabelTitulo = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxNombre = new System.Windows.Forms.TextBox();
            this.maskedTextBoxFecha = new System.Windows.Forms.MaskedTextBox();
            this.textBoxDescripcion = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.dataGridViewAplicacion = new System.Windows.Forms.DataGridView();
            this.contextMenuStripOpciones = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItemEliminar = new System.Windows.Forms.ToolStripMenuItem();
            this.label6 = new System.Windows.Forms.Label();
            this.comboBoxDepartamentos = new System.Windows.Forms.ComboBox();
            this.dataGridViewDepartamentos = new System.Windows.Forms.DataGridView();
            this.label7 = new System.Windows.Forms.Label();
            this.buttonVolver = new System.Windows.Forms.Button();
            this.comboBoxTipo = new System.Windows.Forms.ComboBox();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonEnlazarApliASer = new System.Windows.Forms.Button();
            this.label10 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.comboBoxServidor = new System.Windows.Forms.ComboBox();
            this.comboBoxAplicaciones = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.aplicacionesBindingSource = new System.Windows.Forms.BindingSource(this.components);
            this.dataGridViewApliXServ = new System.Windows.Forms.DataGridView();
            this.label11 = new System.Windows.Forms.Label();
            this.buttonAgregarAplicacion = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewAplicacion)).BeginInit();
            this.contextMenuStripOpciones.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDepartamentos)).BeginInit();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.aplicacionesBindingSource)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewApliXServ)).BeginInit();
            this.SuspendLayout();
            // 
            // cLabelTitulo
            // 
            this.cLabelTitulo.AutoSize = true;
            this.cLabelTitulo.Font = new System.Drawing.Font("Modern No. 20", 14.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.cLabelTitulo.Location = new System.Drawing.Point(23, 9);
            this.cLabelTitulo.Name = "cLabelTitulo";
            this.cLabelTitulo.Size = new System.Drawing.Size(282, 21);
            this.cLabelTitulo.TabIndex = 2;
            this.cLabelTitulo.Text = "Agregar una nueva Aplicacion :";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(26, 109);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(120, 15);
            this.label1.TabIndex = 3;
            this.label1.Text = "Nombre Aplicacíon : ";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(26, 153);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(113, 15);
            this.label2.TabIndex = 4;
            this.label2.Text = "Tipo de Aplicacíon :";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(26, 238);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(154, 15);
            this.label4.TabIndex = 6;
            this.label4.Text = "Descripcíon de Aplicacíon :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(26, 198);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(99, 15);
            this.label3.TabIndex = 11;
            this.label3.Text = "Fecha Creación :";
            // 
            // textBoxNombre
            // 
            this.textBoxNombre.Location = new System.Drawing.Point(221, 108);
            this.textBoxNombre.Name = "textBoxNombre";
            this.textBoxNombre.Size = new System.Drawing.Size(332, 20);
            this.textBoxNombre.TabIndex = 12;
            // 
            // maskedTextBoxFecha
            // 
            this.maskedTextBoxFecha.Location = new System.Drawing.Point(221, 197);
            this.maskedTextBoxFecha.Mask = "00/00/0000";
            this.maskedTextBoxFecha.Name = "maskedTextBoxFecha";
            this.maskedTextBoxFecha.Size = new System.Drawing.Size(100, 20);
            this.maskedTextBoxFecha.TabIndex = 14;
            this.maskedTextBoxFecha.ValidatingType = typeof(System.DateTime);
            this.maskedTextBoxFecha.TypeValidationCompleted += new System.Windows.Forms.TypeValidationEventHandler(this.maskedTextBoxFecha_TypeValidationCompleted);
            // 
            // textBoxDescripcion
            // 
            this.textBoxDescripcion.Location = new System.Drawing.Point(221, 238);
            this.textBoxDescripcion.Multiline = true;
            this.textBoxDescripcion.Name = "textBoxDescripcion";
            this.textBoxDescripcion.Size = new System.Drawing.Size(332, 68);
            this.textBoxDescripcion.TabIndex = 15;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(354, 198);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(130, 15);
            this.label5.TabIndex = 17;
            this.label5.Text = "Formato DD/MM/AAAA";
            // 
            // dataGridViewAplicacion
            // 
            this.dataGridViewAplicacion.AllowUserToAddRows = false;
            this.dataGridViewAplicacion.AllowUserToDeleteRows = false;
            this.dataGridViewAplicacion.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewAplicacion.AutoSizeRowsMode = System.Windows.Forms.DataGridViewAutoSizeRowsMode.AllCells;
            this.dataGridViewAplicacion.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.dataGridViewAplicacion.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewAplicacion.ContextMenuStrip = this.contextMenuStripOpciones;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewAplicacion.DefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewAplicacion.Location = new System.Drawing.Point(24, 371);
            this.dataGridViewAplicacion.Name = "dataGridViewAplicacion";
            this.dataGridViewAplicacion.ReadOnly = true;
            this.dataGridViewAplicacion.RowHeadersVisible = false;
            this.dataGridViewAplicacion.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewAplicacion.Size = new System.Drawing.Size(1178, 330);
            this.dataGridViewAplicacion.TabIndex = 18;
            // 
            // contextMenuStripOpciones
            // 
            this.contextMenuStripOpciones.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemEliminar});
            this.contextMenuStripOpciones.Name = "contextMenuStripOpciones";
            this.contextMenuStripOpciones.Size = new System.Drawing.Size(215, 26);
            this.contextMenuStripOpciones.MouseClick += new System.Windows.Forms.MouseEventHandler(this.contextMenuStripOpciones_MouseClick);
            // 
            // toolStripMenuItemEliminar
            // 
            this.toolStripMenuItemEliminar.Name = "toolStripMenuItemEliminar";
            this.toolStripMenuItemEliminar.Size = new System.Drawing.Size(214, 22);
            this.toolStripMenuItemEliminar.Text = "Eliminar Linea Selecionada";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(21, 64);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(165, 15);
            this.label6.TabIndex = 19;
            this.label6.Text = "Departamento Responsable:";
            // 
            // comboBoxDepartamentos
            // 
            this.comboBoxDepartamentos.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxDepartamentos.FormattingEnabled = true;
            this.comboBoxDepartamentos.Location = new System.Drawing.Point(221, 63);
            this.comboBoxDepartamentos.Name = "comboBoxDepartamentos";
            this.comboBoxDepartamentos.Size = new System.Drawing.Size(172, 21);
            this.comboBoxDepartamentos.TabIndex = 20;
            this.comboBoxDepartamentos.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBoxDepartamentos_MouseClick);
            // 
            // dataGridViewDepartamentos
            // 
            this.dataGridViewDepartamentos.AllowUserToAddRows = false;
            this.dataGridViewDepartamentos.AllowUserToDeleteRows = false;
            this.dataGridViewDepartamentos.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewDepartamentos.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewDepartamentos.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
            this.dataGridViewDepartamentos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewDepartamentos.DefaultCellStyle = dataGridViewCellStyle3;
            this.dataGridViewDepartamentos.Location = new System.Drawing.Point(607, 28);
            this.dataGridViewDepartamentos.Name = "dataGridViewDepartamentos";
            this.dataGridViewDepartamentos.ReadOnly = true;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewDepartamentos.RowHeadersDefaultCellStyle = dataGridViewCellStyle4;
            this.dataGridViewDepartamentos.RowHeadersVisible = false;
            this.dataGridViewDepartamentos.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewDepartamentos.Size = new System.Drawing.Size(340, 278);
            this.dataGridViewDepartamentos.TabIndex = 21;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(604, 9);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(179, 16);
            this.label7.TabIndex = 22;
            this.label7.Text = "Departamentos Disponibles:";
            // 
            // buttonVolver
            // 
            this.buttonVolver.Location = new System.Drawing.Point(1224, 670);
            this.buttonVolver.Name = "buttonVolver";
            this.buttonVolver.Size = new System.Drawing.Size(95, 23);
            this.buttonVolver.TabIndex = 23;
            this.buttonVolver.Text = "Volver";
            this.buttonVolver.UseVisualStyleBackColor = true;
            this.buttonVolver.Click += new System.EventHandler(this.buttonVolver_Click);
            // 
            // comboBoxTipo
            // 
            this.comboBoxTipo.AutoCompleteCustomSource.AddRange(new string[] {
            "negocio",
            "utilitaria",
            "otra"});
            this.comboBoxTipo.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.comboBoxTipo.FormattingEnabled = true;
            this.comboBoxTipo.Items.AddRange(new object[] {
            "Negocios",
            "Utilitaria",
            "Otra"});
            this.comboBoxTipo.Location = new System.Drawing.Point(221, 152);
            this.comboBoxTipo.Name = "comboBoxTipo";
            this.comboBoxTipo.Size = new System.Drawing.Size(172, 21);
            this.comboBoxTipo.TabIndex = 24;
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.buttonEnlazarApliASer);
            this.panel1.Controls.Add(this.label10);
            this.panel1.Controls.Add(this.label9);
            this.panel1.Controls.Add(this.comboBoxServidor);
            this.panel1.Controls.Add(this.comboBoxAplicaciones);
            this.panel1.Location = new System.Drawing.Point(956, 28);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(340, 119);
            this.panel1.TabIndex = 25;
            // 
            // buttonEnlazarApliASer
            // 
            this.buttonEnlazarApliASer.Location = new System.Drawing.Point(235, 76);
            this.buttonEnlazarApliASer.Name = "buttonEnlazarApliASer";
            this.buttonEnlazarApliASer.Size = new System.Drawing.Size(75, 23);
            this.buttonEnlazarApliASer.TabIndex = 4;
            this.buttonEnlazarApliASer.Text = "Enlazar";
            this.buttonEnlazarApliASer.UseVisualStyleBackColor = true;
            this.buttonEnlazarApliASer.Click += new System.EventHandler(this.buttonEnlazarApliASer_Click);
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Location = new System.Drawing.Point(171, 22);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(49, 13);
            this.label10.TabIndex = 3;
            this.label10.Text = "Servidor:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(10, 22);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(59, 13);
            this.label9.TabIndex = 2;
            this.label9.Text = "Aplicación:";
            // 
            // comboBoxServidor
            // 
            this.comboBoxServidor.FormattingEnabled = true;
            this.comboBoxServidor.Location = new System.Drawing.Point(174, 49);
            this.comboBoxServidor.Name = "comboBoxServidor";
            this.comboBoxServidor.Size = new System.Drawing.Size(136, 21);
            this.comboBoxServidor.TabIndex = 1;
            this.comboBoxServidor.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBox2_MouseClick);
            // 
            // comboBoxAplicaciones
            // 
            this.comboBoxAplicaciones.FormattingEnabled = true;
            this.comboBoxAplicaciones.Location = new System.Drawing.Point(13, 49);
            this.comboBoxAplicaciones.Name = "comboBoxAplicaciones";
            this.comboBoxAplicaciones.Size = new System.Drawing.Size(142, 21);
            this.comboBoxAplicaciones.TabIndex = 0;
            this.comboBoxAplicaciones.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBoxAplicaciones_MouseClick);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(953, 9);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(208, 16);
            this.label8.TabIndex = 26;
            this.label8.Text = "Agregar Aplicación a un Servidor:";
            // 
            // aplicacionesBindingSource
            // 
            this.aplicacionesBindingSource.DataSource = typeof(SistemaGestor.Aplicaciones);
            // 
            // dataGridViewApliXServ
            // 
            this.dataGridViewApliXServ.AllowUserToAddRows = false;
            this.dataGridViewApliXServ.AllowUserToDeleteRows = false;
            this.dataGridViewApliXServ.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewApliXServ.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle5.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle5.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle5.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle5.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle5.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewApliXServ.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
            this.dataGridViewApliXServ.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle6.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle6.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle6.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle6.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewApliXServ.DefaultCellStyle = dataGridViewCellStyle6;
            this.dataGridViewApliXServ.Location = new System.Drawing.Point(956, 176);
            this.dataGridViewApliXServ.Name = "dataGridViewApliXServ";
            this.dataGridViewApliXServ.ReadOnly = true;
            this.dataGridViewApliXServ.Size = new System.Drawing.Size(340, 130);
            this.dataGridViewApliXServ.TabIndex = 27;
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(952, 153);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(195, 20);
            this.label11.TabIndex = 28;
            this.label11.Text = "Aplicaciones por Servidor :";
            // 
            // buttonAgregarAplicacion
            // 
            this.buttonAgregarAplicacion.Location = new System.Drawing.Point(433, 326);
            this.buttonAgregarAplicacion.Name = "buttonAgregarAplicacion";
            this.buttonAgregarAplicacion.Size = new System.Drawing.Size(120, 23);
            this.buttonAgregarAplicacion.TabIndex = 29;
            this.buttonAgregarAplicacion.Text = "Agregar Aplicacion";
            this.buttonAgregarAplicacion.UseVisualStyleBackColor = true;
            this.buttonAgregarAplicacion.Click += new System.EventHandler(this.buttonAgregarAplicacion_Click_1);
            // 
            // Aplicaciones
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1352, 729);
            this.Controls.Add(this.buttonAgregarAplicacion);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.dataGridViewApliXServ);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.comboBoxTipo);
            this.Controls.Add(this.buttonVolver);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.dataGridViewDepartamentos);
            this.Controls.Add(this.comboBoxDepartamentos);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.dataGridViewAplicacion);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.textBoxDescripcion);
            this.Controls.Add(this.maskedTextBoxFecha);
            this.Controls.Add(this.textBoxNombre);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cLabelTitulo);
            this.Name = "Aplicaciones";
            this.Text = "Aplicaciones";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Aplicaciones_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewAplicacion)).EndInit();
            this.contextMenuStripOpciones.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDepartamentos)).EndInit();
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.aplicacionesBindingSource)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewApliXServ)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Label cLabelTitulo;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxNombre;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxFecha;
        private System.Windows.Forms.TextBox textBoxDescripcion;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.DataGridView dataGridViewAplicacion;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.ComboBox comboBoxDepartamentos;
        private System.Windows.Forms.BindingSource aplicacionesBindingSource;
        private System.Windows.Forms.DataGridView dataGridViewDepartamentos;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Button buttonVolver;
        private System.Windows.Forms.ComboBox comboBoxTipo;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button buttonEnlazarApliASer;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.ComboBox comboBoxServidor;
        private System.Windows.Forms.ComboBox comboBoxAplicaciones;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripOpciones;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemEliminar;
        private System.Windows.Forms.DataGridView dataGridViewApliXServ;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button buttonAgregarAplicacion;
    }
}