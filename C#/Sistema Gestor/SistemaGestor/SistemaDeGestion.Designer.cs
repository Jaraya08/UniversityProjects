namespace SistemaGestor
{
    partial class SistemaDeGestion
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle9 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle10 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle6 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle7 = new System.Windows.Forms.DataGridViewCellStyle();
            this.labelError = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.comboBoxServidor = new System.Windows.Forms.ComboBox();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.maskedTextBoxFechaError = new System.Windows.Forms.MaskedTextBox();
            this.maskedTextBoxHora = new System.Windows.Forms.MaskedTextBox();
            this.textBoxIdError = new System.Windows.Forms.TextBox();
            this.textBoxDescripcionError = new System.Windows.Forms.TextBox();
            this.dataGridViewErrores = new System.Windows.Forms.DataGridView();
            this.contextMenuStripErrores = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItemEliminarError = new System.Windows.Forms.ToolStripMenuItem();
            this.buttonAgregarError = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.comboBoxImpacto = new System.Windows.Forms.ComboBox();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.comboBoxAplicacion = new System.Windows.Forms.ComboBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.label12 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.label14 = new System.Windows.Forms.Label();
            this.textBoxIdProyecto = new System.Windows.Forms.TextBox();
            this.textBoxNomProy = new System.Windows.Forms.TextBox();
            this.textBoxEsfuerzoEst = new System.Windows.Forms.TextBox();
            this.textBoxEsfuerzoReal = new System.Windows.Forms.TextBox();
            this.textBoxDescripcionProy = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.dataGridViewProyectos = new System.Windows.Forms.DataGridView();
            this.label16 = new System.Windows.Forms.Label();
            this.maskedTextBoxFechaINI = new System.Windows.Forms.MaskedTextBox();
            this.maskedTextBoxFechaFin = new System.Windows.Forms.MaskedTextBox();
            this.label17 = new System.Windows.Forms.Label();
            this.label18 = new System.Windows.Forms.Label();
            this.buttonVolver = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewErrores)).BeginInit();
            this.contextMenuStripErrores.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProyectos)).BeginInit();
            this.SuspendLayout();
            // 
            // labelError
            // 
            this.labelError.AutoSize = true;
            this.labelError.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.labelError.Location = new System.Drawing.Point(12, 9);
            this.labelError.Name = "labelError";
            this.labelError.Size = new System.Drawing.Size(218, 20);
            this.labelError.TabIndex = 0;
            this.labelError.Text = "Registrar Error de Producción";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(32, 51);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(77, 15);
            this.label1.TabIndex = 1;
            this.label1.Text = "Identificador:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(34, 261);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(75, 15);
            this.label2.TabIndex = 2;
            this.label2.Text = "Descripción:";
            // 
            // comboBoxServidor
            // 
            this.comboBoxServidor.FormattingEnabled = true;
            this.comboBoxServidor.Location = new System.Drawing.Point(149, 90);
            this.comboBoxServidor.Name = "comboBoxServidor";
            this.comboBoxServidor.Size = new System.Drawing.Size(121, 21);
            this.comboBoxServidor.TabIndex = 2;
            this.comboBoxServidor.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBox1_MouseClick);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(34, 91);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(58, 15);
            this.label3.TabIndex = 4;
            this.label3.Text = "Servidor :";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(34, 180);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(79, 15);
            this.label4.TabIndex = 5;
            this.label4.Text = "Fecha y Hora";
            // 
            // maskedTextBoxFechaError
            // 
            this.maskedTextBoxFechaError.Location = new System.Drawing.Point(149, 179);
            this.maskedTextBoxFechaError.Mask = "00/00/0000";
            this.maskedTextBoxFechaError.Name = "maskedTextBoxFechaError";
            this.maskedTextBoxFechaError.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.maskedTextBoxFechaError.Size = new System.Drawing.Size(70, 20);
            this.maskedTextBoxFechaError.TabIndex = 4;
            this.maskedTextBoxFechaError.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.maskedTextBoxFechaError.ValidatingType = typeof(System.DateTime);
            this.maskedTextBoxFechaError.TypeValidationCompleted += new System.Windows.Forms.TypeValidationEventHandler(this.maskedTextBoxFechaError_TypeValidationCompleted);
            // 
            // maskedTextBoxHora
            // 
            this.maskedTextBoxHora.Location = new System.Drawing.Point(225, 179);
            this.maskedTextBoxHora.Mask = "00:00";
            this.maskedTextBoxHora.Name = "maskedTextBoxHora";
            this.maskedTextBoxHora.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.maskedTextBoxHora.Size = new System.Drawing.Size(45, 20);
            this.maskedTextBoxHora.TabIndex = 5;
            this.maskedTextBoxHora.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.maskedTextBoxHora.ValidatingType = typeof(System.DateTime);
            // 
            // textBoxIdError
            // 
            this.textBoxIdError.Enabled = false;
            this.textBoxIdError.Location = new System.Drawing.Point(149, 50);
            this.textBoxIdError.Name = "textBoxIdError";
            this.textBoxIdError.Size = new System.Drawing.Size(121, 20);
            this.textBoxIdError.TabIndex = 1;
            this.textBoxIdError.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxDescripcionError
            // 
            this.textBoxDescripcionError.Location = new System.Drawing.Point(149, 260);
            this.textBoxDescripcionError.Multiline = true;
            this.textBoxDescripcionError.Name = "textBoxDescripcionError";
            this.textBoxDescripcionError.Size = new System.Drawing.Size(268, 78);
            this.textBoxDescripcionError.TabIndex = 7;
            // 
            // dataGridViewErrores
            // 
            this.dataGridViewErrores.AllowUserToAddRows = false;
            this.dataGridViewErrores.AllowUserToDeleteRows = false;
            this.dataGridViewErrores.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewErrores.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewErrores.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this.dataGridViewErrores.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewErrores.ContextMenuStrip = this.contextMenuStripErrores;
            dataGridViewCellStyle9.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle9.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle9.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle9.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle9.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle9.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle9.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewErrores.DefaultCellStyle = dataGridViewCellStyle9;
            this.dataGridViewErrores.Location = new System.Drawing.Point(463, 32);
            this.dataGridViewErrores.Name = "dataGridViewErrores";
            this.dataGridViewErrores.ReadOnly = true;
            dataGridViewCellStyle10.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle10.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle10.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle10.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle10.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle10.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle10.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewErrores.RowHeadersDefaultCellStyle = dataGridViewCellStyle10;
            this.dataGridViewErrores.RowHeadersVisible = false;
            this.dataGridViewErrores.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewErrores.Size = new System.Drawing.Size(875, 240);
            this.dataGridViewErrores.TabIndex = 8;
            // 
            // contextMenuStripErrores
            // 
            this.contextMenuStripErrores.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemEliminarError});
            this.contextMenuStripErrores.Name = "contextMenuStripErrores";
            this.contextMenuStripErrores.Size = new System.Drawing.Size(146, 26);
            this.contextMenuStripErrores.MouseClick += new System.Windows.Forms.MouseEventHandler(this.contextMenuStripErrores_MouseClick);
            // 
            // toolStripMenuItemEliminarError
            // 
            this.toolStripMenuItemEliminarError.Name = "toolStripMenuItemEliminarError";
            this.toolStripMenuItemEliminarError.Size = new System.Drawing.Size(145, 22);
            this.toolStripMenuItemEliminarError.Text = "Eliminar Error";
            // 
            // buttonAgregarError
            // 
            this.buttonAgregarError.Location = new System.Drawing.Point(271, 675);
            this.buttonAgregarError.Name = "buttonAgregarError";
            this.buttonAgregarError.Size = new System.Drawing.Size(146, 23);
            this.buttonAgregarError.TabIndex = 15;
            this.buttonAgregarError.Text = "Agregar Error";
            this.buttonAgregarError.UseVisualStyleBackColor = true;
            this.buttonAgregarError.Click += new System.EventHandler(this.buttonAgregarError_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(34, 220);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(51, 15);
            this.label5.TabIndex = 12;
            this.label5.Text = "Impacto";
            // 
            // comboBoxImpacto
            // 
            this.comboBoxImpacto.FormattingEnabled = true;
            this.comboBoxImpacto.Items.AddRange(new object[] {
            "Bajo ",
            "Medio ",
            "Alto",
            "Devastador"});
            this.comboBoxImpacto.Location = new System.Drawing.Point(149, 219);
            this.comboBoxImpacto.Name = "comboBoxImpacto";
            this.comboBoxImpacto.Size = new System.Drawing.Size(121, 21);
            this.comboBoxImpacto.TabIndex = 6;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(12, 350);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(245, 20);
            this.label6.TabIndex = 13;
            this.label6.Text = "Proyecto de Correción Generado:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(34, 138);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(66, 15);
            this.label7.TabIndex = 14;
            this.label7.Text = "Aplicación:";
            // 
            // comboBoxAplicacion
            // 
            this.comboBoxAplicacion.FormattingEnabled = true;
            this.comboBoxAplicacion.Items.AddRange(new object[] {
            "Bajo ",
            "Medio ",
            "Alto",
            "Devastador"});
            this.comboBoxAplicacion.Location = new System.Drawing.Point(149, 137);
            this.comboBoxAplicacion.Name = "comboBoxAplicacion";
            this.comboBoxAplicacion.Size = new System.Drawing.Size(268, 21);
            this.comboBoxAplicacion.TabIndex = 3;
            this.comboBoxAplicacion.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBoxAplicacion_MouseClick);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(32, 393);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(77, 15);
            this.label8.TabIndex = 15;
            this.label8.Text = "Identificador:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(32, 427);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(55, 15);
            this.label9.TabIndex = 16;
            this.label9.Text = "Nombre:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(37, 592);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(72, 15);
            this.label10.TabIndex = 17;
            this.label10.Text = "Descripción";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(32, 459);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(90, 15);
            this.label11.TabIndex = 18;
            this.label11.Text = "Fecha de Inicio";
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(34, 530);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(110, 15);
            this.label12.TabIndex = 19;
            this.label12.Text = "Esfuerzo Estimado";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label13.Location = new System.Drawing.Point(32, 494);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(110, 15);
            this.label13.TabIndex = 20;
            this.label13.Text = "Fecha Finalización";
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label14.Location = new System.Drawing.Point(34, 564);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(84, 15);
            this.label14.TabIndex = 21;
            this.label14.Text = "Esfuerzo Real";
            // 
            // textBoxIdProyecto
            // 
            this.textBoxIdProyecto.Enabled = false;
            this.textBoxIdProyecto.Location = new System.Drawing.Point(149, 393);
            this.textBoxIdProyecto.Name = "textBoxIdProyecto";
            this.textBoxIdProyecto.Size = new System.Drawing.Size(92, 20);
            this.textBoxIdProyecto.TabIndex = 8;
            this.textBoxIdProyecto.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBoxNomProy
            // 
            this.textBoxNomProy.Location = new System.Drawing.Point(149, 427);
            this.textBoxNomProy.Name = "textBoxNomProy";
            this.textBoxNomProy.Size = new System.Drawing.Size(268, 20);
            this.textBoxNomProy.TabIndex = 9;
            // 
            // textBoxEsfuerzoEst
            // 
            this.textBoxEsfuerzoEst.Location = new System.Drawing.Point(150, 530);
            this.textBoxEsfuerzoEst.Name = "textBoxEsfuerzoEst";
            this.textBoxEsfuerzoEst.Size = new System.Drawing.Size(92, 20);
            this.textBoxEsfuerzoEst.TabIndex = 12;
            // 
            // textBoxEsfuerzoReal
            // 
            this.textBoxEsfuerzoReal.Location = new System.Drawing.Point(149, 564);
            this.textBoxEsfuerzoReal.Name = "textBoxEsfuerzoReal";
            this.textBoxEsfuerzoReal.Size = new System.Drawing.Size(92, 20);
            this.textBoxEsfuerzoReal.TabIndex = 13;
            // 
            // textBoxDescripcionProy
            // 
            this.textBoxDescripcionProy.Font = new System.Drawing.Font("MV Boli", 8.25F);
            this.textBoxDescripcionProy.Location = new System.Drawing.Point(149, 592);
            this.textBoxDescripcionProy.Multiline = true;
            this.textBoxDescripcionProy.Name = "textBoxDescripcionProy";
            this.textBoxDescripcionProy.Size = new System.Drawing.Size(268, 77);
            this.textBoxDescripcionProy.TabIndex = 14;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label15.Location = new System.Drawing.Point(463, 13);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(55, 16);
            this.label15.TabIndex = 29;
            this.label15.Text = "Errores:";
            // 
            // dataGridViewProyectos
            // 
            this.dataGridViewProyectos.AllowUserToAddRows = false;
            this.dataGridViewProyectos.AllowUserToDeleteRows = false;
            this.dataGridViewProyectos.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewProyectos.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle6.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle6.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle6.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle6.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle6.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewProyectos.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
            this.dataGridViewProyectos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle7.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle7.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle7.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle7.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle7.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle7.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewProyectos.DefaultCellStyle = dataGridViewCellStyle7;
            this.dataGridViewProyectos.Location = new System.Drawing.Point(466, 373);
            this.dataGridViewProyectos.Name = "dataGridViewProyectos";
            this.dataGridViewProyectos.ReadOnly = true;
            this.dataGridViewProyectos.RowHeadersVisible = false;
            this.dataGridViewProyectos.Size = new System.Drawing.Size(872, 276);
            this.dataGridViewProyectos.TabIndex = 30;
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label16.Location = new System.Drawing.Point(463, 354);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(158, 16);
            this.label16.TabIndex = 31;
            this.label16.Text = "Proyectos de Coreccion :";
            // 
            // maskedTextBoxFechaINI
            // 
            this.maskedTextBoxFechaINI.Location = new System.Drawing.Point(149, 459);
            this.maskedTextBoxFechaINI.Mask = "00/00/0000";
            this.maskedTextBoxFechaINI.Name = "maskedTextBoxFechaINI";
            this.maskedTextBoxFechaINI.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.maskedTextBoxFechaINI.Size = new System.Drawing.Size(70, 20);
            this.maskedTextBoxFechaINI.TabIndex = 10;
            this.maskedTextBoxFechaINI.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.maskedTextBoxFechaINI.ValidatingType = typeof(System.DateTime);
            this.maskedTextBoxFechaINI.TypeValidationCompleted += new System.Windows.Forms.TypeValidationEventHandler(this.maskedTextBoxFechaINI_TypeValidationCompleted);
            // 
            // maskedTextBoxFechaFin
            // 
            this.maskedTextBoxFechaFin.Location = new System.Drawing.Point(148, 494);
            this.maskedTextBoxFechaFin.Mask = "00/00/0000";
            this.maskedTextBoxFechaFin.Name = "maskedTextBoxFechaFin";
            this.maskedTextBoxFechaFin.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.maskedTextBoxFechaFin.Size = new System.Drawing.Size(70, 20);
            this.maskedTextBoxFechaFin.TabIndex = 11;
            this.maskedTextBoxFechaFin.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            this.maskedTextBoxFechaFin.ValidatingType = typeof(System.DateTime);
            this.maskedTextBoxFechaFin.TypeValidationCompleted += new System.Windows.Forms.TypeValidationEventHandler(this.maskedTextBoxFechaFin_TypeValidationCompleted);
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label17.Location = new System.Drawing.Point(258, 531);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(58, 15);
            this.label17.TabIndex = 32;
            this.label17.Text = "En Horas";
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label18.Location = new System.Drawing.Point(258, 565);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(58, 15);
            this.label18.TabIndex = 33;
            this.label18.Text = "En Horas";
            // 
            // buttonVolver
            // 
            this.buttonVolver.Location = new System.Drawing.Point(1263, 675);
            this.buttonVolver.Name = "buttonVolver";
            this.buttonVolver.Size = new System.Drawing.Size(75, 23);
            this.buttonVolver.TabIndex = 34;
            this.buttonVolver.Text = "Volver";
            this.buttonVolver.UseVisualStyleBackColor = true;
            this.buttonVolver.Click += new System.EventHandler(this.buttonVolver_Click);
            // 
            // SistemaDeGestion
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 729);
            this.Controls.Add(this.buttonVolver);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.maskedTextBoxFechaFin);
            this.Controls.Add(this.maskedTextBoxFechaINI);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.dataGridViewProyectos);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.textBoxDescripcionProy);
            this.Controls.Add(this.textBoxEsfuerzoReal);
            this.Controls.Add(this.textBoxEsfuerzoEst);
            this.Controls.Add(this.textBoxNomProy);
            this.Controls.Add(this.textBoxIdProyecto);
            this.Controls.Add(this.label14);
            this.Controls.Add(this.label13);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.comboBoxAplicacion);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.comboBoxImpacto);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.buttonAgregarError);
            this.Controls.Add(this.dataGridViewErrores);
            this.Controls.Add(this.textBoxDescripcionError);
            this.Controls.Add(this.textBoxIdError);
            this.Controls.Add(this.maskedTextBoxHora);
            this.Controls.Add(this.maskedTextBoxFechaError);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.comboBoxServidor);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.labelError);
            this.Name = "SistemaDeGestion";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterParent;
            this.Text = "Sistema de Gestion";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewErrores)).EndInit();
            this.contextMenuStripErrores.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProyectos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelError;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.ComboBox comboBoxServidor;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxFechaError;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxHora;
        private System.Windows.Forms.TextBox textBoxIdError;
        private System.Windows.Forms.TextBox textBoxDescripcionError;
        private System.Windows.Forms.DataGridView dataGridViewErrores;
        private System.Windows.Forms.Button buttonAgregarError;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox comboBoxImpacto;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox comboBoxAplicacion;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.TextBox textBoxIdProyecto;
        private System.Windows.Forms.TextBox textBoxNomProy;
        private System.Windows.Forms.TextBox textBoxEsfuerzoEst;
        private System.Windows.Forms.TextBox textBoxEsfuerzoReal;
        private System.Windows.Forms.TextBox textBoxDescripcionProy;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.DataGridView dataGridViewProyectos;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxFechaINI;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxFechaFin;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripErrores;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemEliminarError;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Label label18;
        private System.Windows.Forms.Button buttonVolver;
    }
}