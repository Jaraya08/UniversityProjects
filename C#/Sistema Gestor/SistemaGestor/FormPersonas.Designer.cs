namespace SistemaGestor
{
    partial class FormPersonas
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle7 = new System.Windows.Forms.DataGridViewCellStyle();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.textBoxNombre = new System.Windows.Forms.TextBox();
            this.textBoxCedula = new System.Windows.Forms.TextBox();
            this.textBoxApellido = new System.Windows.Forms.TextBox();
            this.textBoxRol = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonAgregarPerProy = new System.Windows.Forms.Button();
            this.label8 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.comboBoxPersonas = new System.Windows.Forms.ComboBox();
            this.comboBoxProyectos = new System.Windows.Forms.ComboBox();
            this.button2 = new System.Windows.Forms.Button();
            this.dataGridViewPersonas = new System.Windows.Forms.DataGridView();
            this.contextMenuStripEliminarPersona = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItemEliminarPersona = new System.Windows.Forms.ToolStripMenuItem();
            this.dataGridViewProyPers = new System.Windows.Forms.DataGridView();
            this.dataGridViewProyectos = new System.Windows.Forms.DataGridView();
            this.label9 = new System.Windows.Forms.Label();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.buttonVolver = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPersonas)).BeginInit();
            this.contextMenuStripEliminarPersona.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProyPers)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProyectos)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(13, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(178, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Agregar Nueva Persona";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(21, 93);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(55, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Nombre:";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(21, 53);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(49, 15);
            this.label3.TabIndex = 2;
            this.label3.Text = "Cedula:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(21, 133);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(54, 15);
            this.label4.TabIndex = 3;
            this.label4.Text = "Apellido:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(21, 165);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(26, 15);
            this.label5.TabIndex = 4;
            this.label5.Text = "Rol";
            // 
            // textBoxNombre
            // 
            this.textBoxNombre.Location = new System.Drawing.Point(101, 93);
            this.textBoxNombre.Name = "textBoxNombre";
            this.textBoxNombre.Size = new System.Drawing.Size(208, 20);
            this.textBoxNombre.TabIndex = 2;
            this.textBoxNombre.Enter += new System.EventHandler(this.textBoxNombre_Enter);
            // 
            // textBoxCedula
            // 
            this.textBoxCedula.Location = new System.Drawing.Point(101, 53);
            this.textBoxCedula.Name = "textBoxCedula";
            this.textBoxCedula.Size = new System.Drawing.Size(208, 20);
            this.textBoxCedula.TabIndex = 1;
            this.textBoxCedula.Enter += new System.EventHandler(this.textBoxCedula_Enter);
            // 
            // textBoxApellido
            // 
            this.textBoxApellido.Location = new System.Drawing.Point(101, 128);
            this.textBoxApellido.Name = "textBoxApellido";
            this.textBoxApellido.Size = new System.Drawing.Size(208, 20);
            this.textBoxApellido.TabIndex = 3;
            this.textBoxApellido.Enter += new System.EventHandler(this.textBoxApellido_Enter);
            // 
            // textBoxRol
            // 
            this.textBoxRol.Location = new System.Drawing.Point(101, 164);
            this.textBoxRol.Name = "textBoxRol";
            this.textBoxRol.Size = new System.Drawing.Size(208, 20);
            this.textBoxRol.TabIndex = 4;
            this.textBoxRol.Enter += new System.EventHandler(this.textBoxRol_Enter);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(14, 235);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(234, 20);
            this.label6.TabIndex = 9;
            this.label6.Text = "Agregar Persona a un Proyecto:";
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.buttonAgregarPerProy);
            this.panel1.Controls.Add(this.label8);
            this.panel1.Controls.Add(this.label7);
            this.panel1.Controls.Add(this.comboBoxPersonas);
            this.panel1.Controls.Add(this.comboBoxProyectos);
            this.panel1.Cursor = System.Windows.Forms.Cursors.Default;
            this.panel1.Location = new System.Drawing.Point(24, 276);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(409, 100);
            this.panel1.TabIndex = 10;
            this.panel1.Tag = "";
            // 
            // buttonAgregarPerProy
            // 
            this.buttonAgregarPerProy.Location = new System.Drawing.Point(307, 72);
            this.buttonAgregarPerProy.Name = "buttonAgregarPerProy";
            this.buttonAgregarPerProy.Size = new System.Drawing.Size(97, 23);
            this.buttonAgregarPerProy.TabIndex = 8;
            this.buttonAgregarPerProy.Text = "Agregar";
            this.buttonAgregarPerProy.UseVisualStyleBackColor = true;
            this.buttonAgregarPerProy.Click += new System.EventHandler(this.buttonAgregarPerProy_Click);
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Location = new System.Drawing.Point(214, 12);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(54, 13);
            this.label8.TabIndex = 3;
            this.label8.Text = "Personas:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(4, 9);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(52, 13);
            this.label7.TabIndex = 2;
            this.label7.Text = "Proyecto:";
            // 
            // comboBoxPersonas
            // 
            this.comboBoxPersonas.FormattingEnabled = true;
            this.comboBoxPersonas.Location = new System.Drawing.Point(214, 28);
            this.comboBoxPersonas.Name = "comboBoxPersonas";
            this.comboBoxPersonas.Size = new System.Drawing.Size(190, 21);
            this.comboBoxPersonas.TabIndex = 7;
            this.comboBoxPersonas.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBoxPersonas_MouseClick);
            // 
            // comboBoxProyectos
            // 
            this.comboBoxProyectos.FormattingEnabled = true;
            this.comboBoxProyectos.Location = new System.Drawing.Point(3, 28);
            this.comboBoxProyectos.Name = "comboBoxProyectos";
            this.comboBoxProyectos.Size = new System.Drawing.Size(205, 21);
            this.comboBoxProyectos.TabIndex = 6;
            this.comboBoxProyectos.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBoxProyectos_MouseClick);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(194, 200);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(115, 23);
            this.button2.TabIndex = 5;
            this.button2.Text = "Agregar Persona";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // dataGridViewPersonas
            // 
            this.dataGridViewPersonas.AllowUserToAddRows = false;
            this.dataGridViewPersonas.AllowUserToDeleteRows = false;
            this.dataGridViewPersonas.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewPersonas.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewPersonas.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewPersonas.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewPersonas.ContextMenuStrip = this.contextMenuStripEliminarPersona;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewPersonas.DefaultCellStyle = dataGridViewCellStyle2;
            this.dataGridViewPersonas.Location = new System.Drawing.Point(563, 62);
            this.dataGridViewPersonas.Name = "dataGridViewPersonas";
            this.dataGridViewPersonas.ReadOnly = true;
            this.dataGridViewPersonas.RowHeadersVisible = false;
            this.dataGridViewPersonas.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewPersonas.Size = new System.Drawing.Size(560, 150);
            this.dataGridViewPersonas.TabIndex = 12;
            // 
            // contextMenuStripEliminarPersona
            // 
            this.contextMenuStripEliminarPersona.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemEliminarPersona});
            this.contextMenuStripEliminarPersona.Name = "contextMenuStripEliminarPersona";
            this.contextMenuStripEliminarPersona.Size = new System.Drawing.Size(163, 26);
            this.contextMenuStripEliminarPersona.MouseClick += new System.Windows.Forms.MouseEventHandler(this.contextMenuStripEliminarPersona_MouseClick);
            // 
            // toolStripMenuItemEliminarPersona
            // 
            this.toolStripMenuItemEliminarPersona.Name = "toolStripMenuItemEliminarPersona";
            this.toolStripMenuItemEliminarPersona.Size = new System.Drawing.Size(162, 22);
            this.toolStripMenuItemEliminarPersona.Text = "Eliminar Persona";
            // 
            // dataGridViewProyPers
            // 
            this.dataGridViewProyPers.AllowUserToAddRows = false;
            this.dataGridViewProyPers.AllowUserToDeleteRows = false;
            this.dataGridViewProyPers.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewProyPers.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewProyPers.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this.dataGridViewProyPers.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewProyPers.DefaultCellStyle = dataGridViewCellStyle4;
            this.dataGridViewProyPers.Location = new System.Drawing.Point(17, 459);
            this.dataGridViewProyPers.Name = "dataGridViewProyPers";
            this.dataGridViewProyPers.ReadOnly = true;
            dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle5.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle5.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle5.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle5.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle5.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewProyPers.RowHeadersDefaultCellStyle = dataGridViewCellStyle5;
            this.dataGridViewProyPers.Size = new System.Drawing.Size(930, 200);
            this.dataGridViewProyPers.TabIndex = 13;
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
            this.dataGridViewProyectos.Location = new System.Drawing.Point(563, 276);
            this.dataGridViewProyectos.Name = "dataGridViewProyectos";
            this.dataGridViewProyectos.ReadOnly = true;
            this.dataGridViewProyectos.Size = new System.Drawing.Size(384, 150);
            this.dataGridViewProyectos.TabIndex = 14;
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(14, 436);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(181, 20);
            this.label9.TabIndex = 15;
            this.label9.Text = "Personas por Proyectos:";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(559, 253);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(169, 20);
            this.label10.TabIndex = 16;
            this.label10.Text = "Proyectos Disponibles:";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label11.Location = new System.Drawing.Point(559, 39);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(162, 20);
            this.label11.TabIndex = 17;
            this.label11.Text = "Personas Agregadas:";
            // 
            // buttonVolver
            // 
            this.buttonVolver.Location = new System.Drawing.Point(872, 678);
            this.buttonVolver.Name = "buttonVolver";
            this.buttonVolver.Size = new System.Drawing.Size(75, 23);
            this.buttonVolver.TabIndex = 18;
            this.buttonVolver.Text = "Volver";
            this.buttonVolver.UseVisualStyleBackColor = true;
            this.buttonVolver.Click += new System.EventHandler(this.buttonVolver_Click);
            // 
            // FormPersonas
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1352, 729);
            this.Controls.Add(this.buttonVolver);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.dataGridViewProyectos);
            this.Controls.Add(this.dataGridViewProyPers);
            this.Controls.Add(this.dataGridViewPersonas);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.textBoxRol);
            this.Controls.Add(this.textBoxApellido);
            this.Controls.Add(this.textBoxCedula);
            this.Controls.Add(this.textBoxNombre);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "FormPersonas";
            this.Text = "FormPersonas";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewPersonas)).EndInit();
            this.contextMenuStripEliminarPersona.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProyPers)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewProyectos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox textBoxNombre;
        private System.Windows.Forms.TextBox textBoxCedula;
        private System.Windows.Forms.TextBox textBoxApellido;
        private System.Windows.Forms.TextBox textBoxRol;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button buttonAgregarPerProy;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.ComboBox comboBoxPersonas;
        private System.Windows.Forms.ComboBox comboBoxProyectos;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.DataGridView dataGridViewPersonas;
        private System.Windows.Forms.DataGridView dataGridViewProyPers;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripEliminarPersona;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemEliminarPersona;
        private System.Windows.Forms.DataGridView dataGridViewProyectos;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Button buttonVolver;
    }
}