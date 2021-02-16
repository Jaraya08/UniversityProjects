namespace SistemaGestor
{
    partial class FormServidores
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
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textBoxSerie = new System.Windows.Forms.TextBox();
            this.textBoxMarca = new System.Windows.Forms.TextBox();
            this.textBoxModelo = new System.Windows.Forms.TextBox();
            this.label8 = new System.Windows.Forms.Label();
            this.label9 = new System.Windows.Forms.Label();
            this.textBoxNuevoRol = new System.Windows.Forms.TextBox();
            this.buttonAgregarSer = new System.Windows.Forms.Button();
            this.buttonAgregarRol = new System.Windows.Forms.Button();
            this.dataGridViewServidores = new System.Windows.Forms.DataGridView();
            this.contextMenuStripServidores = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItemElimarServidor = new System.Windows.Forms.ToolStripMenuItem();
            this.dataGridViewRoles = new System.Windows.Forms.DataGridView();
            this.contextMenuStripRoles = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.toolStripMenuItemEliminarRol = new System.Windows.Forms.ToolStripMenuItem();
            this.label10 = new System.Windows.Forms.Label();
            this.label11 = new System.Windows.Forms.Label();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonAsignarRol = new System.Windows.Forms.Button();
            this.label14 = new System.Windows.Forms.Label();
            this.label13 = new System.Windows.Forms.Label();
            this.comboBoxServidores = new System.Windows.Forms.ComboBox();
            this.comboBoxRoles = new System.Windows.Forms.ComboBox();
            this.label12 = new System.Windows.Forms.Label();
            this.textBoxProc = new System.Windows.Forms.TextBox();
            this.textBoxAlm = new System.Windows.Forms.TextBox();
            this.textBoxRam = new System.Windows.Forms.TextBox();
            this.label15 = new System.Windows.Forms.Label();
            this.label16 = new System.Windows.Forms.Label();
            this.label17 = new System.Windows.Forms.Label();
            this.buttonVolver = new System.Windows.Forms.Button();
            this.dataGridViewRolesPorServ = new System.Windows.Forms.DataGridView();
            this.label18 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewServidores)).BeginInit();
            this.contextMenuStripServidores.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewRoles)).BeginInit();
            this.contextMenuStripRoles.SuspendLayout();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewRolesPorServ)).BeginInit();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(12, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(203, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "Agregar un Nuevo Servidor:";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(28, 278);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(93, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Memoria RAM :";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(29, 232);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(140, 15);
            this.label3.TabIndex = 2;
            this.label3.Text = "Capacidad Almacenaje: ";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(28, 188);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(135, 15);
            this.label4.TabIndex = 3;
            this.label4.Text = "Capacidad Procesador:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(28, 148);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(52, 15);
            this.label5.TabIndex = 4;
            this.label5.Text = "Modelo:";
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label6.Location = new System.Drawing.Point(28, 103);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(45, 15);
            this.label6.TabIndex = 5;
            this.label6.Text = "Marca:";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label7.Location = new System.Drawing.Point(29, 62);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(42, 15);
            this.label7.TabIndex = 6;
            this.label7.Text = "Serie: ";
            // 
            // textBoxSerie
            // 
            this.textBoxSerie.Location = new System.Drawing.Point(169, 61);
            this.textBoxSerie.Name = "textBoxSerie";
            this.textBoxSerie.Size = new System.Drawing.Size(171, 20);
            this.textBoxSerie.TabIndex = 1;
            // 
            // textBoxMarca
            // 
            this.textBoxMarca.Location = new System.Drawing.Point(169, 102);
            this.textBoxMarca.Name = "textBoxMarca";
            this.textBoxMarca.Size = new System.Drawing.Size(171, 20);
            this.textBoxMarca.TabIndex = 2;
            // 
            // textBoxModelo
            // 
            this.textBoxModelo.Location = new System.Drawing.Point(169, 147);
            this.textBoxModelo.Name = "textBoxModelo";
            this.textBoxModelo.Size = new System.Drawing.Size(171, 20);
            this.textBoxModelo.TabIndex = 3;
            // 
            // label8
            // 
            this.label8.AutoSize = true;
            this.label8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label8.Location = new System.Drawing.Point(12, 392);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(147, 20);
            this.label8.TabIndex = 13;
            this.label8.Text = "Agregar Nuevo Rol:";
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label9.Location = new System.Drawing.Point(29, 442);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(78, 16);
            this.label9.TabIndex = 14;
            this.label9.Text = "Nuevo Rol: ";
            // 
            // textBoxNuevoRol
            // 
            this.textBoxNuevoRol.Location = new System.Drawing.Point(169, 441);
            this.textBoxNuevoRol.Name = "textBoxNuevoRol";
            this.textBoxNuevoRol.Size = new System.Drawing.Size(224, 20);
            this.textBoxNuevoRol.TabIndex = 8;
            // 
            // buttonAgregarSer
            // 
            this.buttonAgregarSer.Location = new System.Drawing.Point(235, 324);
            this.buttonAgregarSer.Name = "buttonAgregarSer";
            this.buttonAgregarSer.Size = new System.Drawing.Size(156, 23);
            this.buttonAgregarSer.TabIndex = 7;
            this.buttonAgregarSer.Text = "Agregar Servidor";
            this.buttonAgregarSer.UseVisualStyleBackColor = true;
            this.buttonAgregarSer.Click += new System.EventHandler(this.buttonAgregarSer_Click);
            // 
            // buttonAgregarRol
            // 
            this.buttonAgregarRol.Location = new System.Drawing.Point(235, 478);
            this.buttonAgregarRol.Name = "buttonAgregarRol";
            this.buttonAgregarRol.Size = new System.Drawing.Size(158, 23);
            this.buttonAgregarRol.TabIndex = 9;
            this.buttonAgregarRol.Text = "Agregar  Rol";
            this.buttonAgregarRol.UseVisualStyleBackColor = true;
            this.buttonAgregarRol.Click += new System.EventHandler(this.buttonAgregarRol_Click);
            // 
            // dataGridViewServidores
            // 
            this.dataGridViewServidores.AllowUserToAddRows = false;
            this.dataGridViewServidores.AllowUserToDeleteRows = false;
            this.dataGridViewServidores.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewServidores.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle1.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle1.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle1.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle1.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle1.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle1.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewServidores.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
            this.dataGridViewServidores.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewServidores.ContextMenuStrip = this.contextMenuStripServidores;
            dataGridViewCellStyle2.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle2.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle2.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle2.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle2.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle2.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle2.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewServidores.DefaultCellStyle = dataGridViewCellStyle2;
            this.dataGridViewServidores.Location = new System.Drawing.Point(422, 61);
            this.dataGridViewServidores.Name = "dataGridViewServidores";
            this.dataGridViewServidores.ReadOnly = true;
            this.dataGridViewServidores.RowHeadersVisible = false;
            this.dataGridViewServidores.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewServidores.Size = new System.Drawing.Size(918, 302);
            this.dataGridViewServidores.TabIndex = 18;
            // 
            // contextMenuStripServidores
            // 
            this.contextMenuStripServidores.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemElimarServidor});
            this.contextMenuStripServidores.Name = "contextMenuStripServidores";
            this.contextMenuStripServidores.Size = new System.Drawing.Size(231, 26);
            this.contextMenuStripServidores.MouseClick += new System.Windows.Forms.MouseEventHandler(this.contextMenuStripServidores_MouseClick);
            // 
            // toolStripMenuItemElimarServidor
            // 
            this.toolStripMenuItemElimarServidor.Name = "toolStripMenuItemElimarServidor";
            this.toolStripMenuItemElimarServidor.Size = new System.Drawing.Size(230, 22);
            this.toolStripMenuItemElimarServidor.Text = "Eliminar Servidor Selecionado";
            // 
            // dataGridViewRoles
            // 
            this.dataGridViewRoles.AllowUserToAddRows = false;
            this.dataGridViewRoles.AllowUserToDeleteRows = false;
            this.dataGridViewRoles.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewRoles.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewRoles.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this.dataGridViewRoles.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewRoles.ContextMenuStrip = this.contextMenuStripRoles;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewRoles.DefaultCellStyle = dataGridViewCellStyle4;
            this.dataGridViewRoles.Location = new System.Drawing.Point(422, 415);
            this.dataGridViewRoles.Name = "dataGridViewRoles";
            this.dataGridViewRoles.ReadOnly = true;
            this.dataGridViewRoles.RowHeadersVisible = false;
            this.dataGridViewRoles.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewRoles.Size = new System.Drawing.Size(272, 216);
            this.dataGridViewRoles.TabIndex = 19;
            // 
            // contextMenuStripRoles
            // 
            this.contextMenuStripRoles.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripMenuItemEliminarRol});
            this.contextMenuStripRoles.Name = "contextMenuStripRoles";
            this.contextMenuStripRoles.Size = new System.Drawing.Size(138, 26);
            this.contextMenuStripRoles.MouseClick += new System.Windows.Forms.MouseEventHandler(this.contextMenuStripRoles_MouseClick);
            // 
            // toolStripMenuItemEliminarRol
            // 
            this.toolStripMenuItemEliminarRol.Name = "toolStripMenuItemEliminarRol";
            this.toolStripMenuItemEliminarRol.Size = new System.Drawing.Size(137, 22);
            this.toolStripMenuItemEliminarRol.Text = "Eliminar Rol";
            // 
            // label10
            // 
            this.label10.AutoSize = true;
            this.label10.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label10.Location = new System.Drawing.Point(422, 43);
            this.label10.Name = "label10";
            this.label10.Size = new System.Drawing.Size(77, 16);
            this.label10.TabIndex = 20;
            this.label10.Text = "Servidores:";
            // 
            // label11
            // 
            this.label11.AutoSize = true;
            this.label11.Location = new System.Drawing.Point(422, 399);
            this.label11.Name = "label11";
            this.label11.Size = new System.Drawing.Size(40, 13);
            this.label11.TabIndex = 21;
            this.label11.Text = "Roles :";
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.buttonAsignarRol);
            this.panel1.Controls.Add(this.label14);
            this.panel1.Controls.Add(this.label13);
            this.panel1.Controls.Add(this.comboBoxServidores);
            this.panel1.Controls.Add(this.comboBoxRoles);
            this.panel1.Location = new System.Drawing.Point(16, 556);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(391, 131);
            this.panel1.TabIndex = 22;
            // 
            // buttonAsignarRol
            // 
            this.buttonAsignarRol.Location = new System.Drawing.Point(299, 77);
            this.buttonAsignarRol.Name = "buttonAsignarRol";
            this.buttonAsignarRol.Size = new System.Drawing.Size(75, 23);
            this.buttonAsignarRol.TabIndex = 10;
            this.buttonAsignarRol.Text = "Asignar Rol";
            this.buttonAsignarRol.UseVisualStyleBackColor = true;
            this.buttonAsignarRol.Click += new System.EventHandler(this.buttonAsignarRol_Click);
            // 
            // label14
            // 
            this.label14.AutoSize = true;
            this.label14.Location = new System.Drawing.Point(196, 22);
            this.label14.Name = "label14";
            this.label14.Size = new System.Drawing.Size(57, 13);
            this.label14.TabIndex = 3;
            this.label14.Text = "Servidores";
            // 
            // label13
            // 
            this.label13.AutoSize = true;
            this.label13.Location = new System.Drawing.Point(19, 19);
            this.label13.Name = "label13";
            this.label13.Size = new System.Drawing.Size(37, 13);
            this.label13.TabIndex = 2;
            this.label13.Text = "Roles:";
            // 
            // comboBoxServidores
            // 
            this.comboBoxServidores.FormattingEnabled = true;
            this.comboBoxServidores.Location = new System.Drawing.Point(199, 38);
            this.comboBoxServidores.Name = "comboBoxServidores";
            this.comboBoxServidores.Size = new System.Drawing.Size(175, 21);
            this.comboBoxServidores.TabIndex = 1;
            this.comboBoxServidores.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBox2_MouseClick);
            // 
            // comboBoxRoles
            // 
            this.comboBoxRoles.FormattingEnabled = true;
            this.comboBoxRoles.Location = new System.Drawing.Point(19, 38);
            this.comboBoxRoles.Name = "comboBoxRoles";
            this.comboBoxRoles.Size = new System.Drawing.Size(174, 21);
            this.comboBoxRoles.TabIndex = 0;
            this.comboBoxRoles.MouseClick += new System.Windows.Forms.MouseEventHandler(this.comboBoxRoles_MouseClick);
            // 
            // label12
            // 
            this.label12.AutoSize = true;
            this.label12.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label12.Location = new System.Drawing.Point(12, 533);
            this.label12.Name = "label12";
            this.label12.Size = new System.Drawing.Size(170, 20);
            this.label12.TabIndex = 23;
            this.label12.Text = "Asignar Rol a Servidor:";
            // 
            // textBoxProc
            // 
            this.textBoxProc.Location = new System.Drawing.Point(169, 188);
            this.textBoxProc.Name = "textBoxProc";
            this.textBoxProc.Size = new System.Drawing.Size(122, 20);
            this.textBoxProc.TabIndex = 4;
            // 
            // textBoxAlm
            // 
            this.textBoxAlm.Location = new System.Drawing.Point(169, 232);
            this.textBoxAlm.Name = "textBoxAlm";
            this.textBoxAlm.Size = new System.Drawing.Size(122, 20);
            this.textBoxAlm.TabIndex = 5;
            // 
            // textBoxRam
            // 
            this.textBoxRam.Location = new System.Drawing.Point(169, 277);
            this.textBoxRam.Name = "textBoxRam";
            this.textBoxRam.Size = new System.Drawing.Size(122, 20);
            this.textBoxRam.TabIndex = 6;
            // 
            // label15
            // 
            this.label15.AutoSize = true;
            this.label15.Location = new System.Drawing.Point(299, 191);
            this.label15.Name = "label15";
            this.label15.Size = new System.Drawing.Size(22, 13);
            this.label15.TabIndex = 24;
            this.label15.Text = "GB";
            // 
            // label16
            // 
            this.label16.AutoSize = true;
            this.label16.Location = new System.Drawing.Point(299, 234);
            this.label16.Name = "label16";
            this.label16.Size = new System.Drawing.Size(22, 13);
            this.label16.TabIndex = 25;
            this.label16.Text = "GB";
            // 
            // label17
            // 
            this.label17.AutoSize = true;
            this.label17.Location = new System.Drawing.Point(299, 280);
            this.label17.Name = "label17";
            this.label17.Size = new System.Drawing.Size(22, 13);
            this.label17.TabIndex = 26;
            this.label17.Text = "GB";
            // 
            // buttonVolver
            // 
            this.buttonVolver.Location = new System.Drawing.Point(1055, 634);
            this.buttonVolver.Name = "buttonVolver";
            this.buttonVolver.Size = new System.Drawing.Size(75, 23);
            this.buttonVolver.TabIndex = 27;
            this.buttonVolver.Text = "Volver";
            this.buttonVolver.UseVisualStyleBackColor = true;
            this.buttonVolver.Click += new System.EventHandler(this.buttonVolver_Click);
            // 
            // dataGridViewRolesPorServ
            // 
            this.dataGridViewRolesPorServ.AllowUserToAddRows = false;
            this.dataGridViewRolesPorServ.AllowUserToDeleteRows = false;
            this.dataGridViewRolesPorServ.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewRolesPorServ.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle5.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle5.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle5.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle5.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle5.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle5.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle5.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewRolesPorServ.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle5;
            this.dataGridViewRolesPorServ.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle6.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle6.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle6.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle6.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle6.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle6.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewRolesPorServ.DefaultCellStyle = dataGridViewCellStyle6;
            this.dataGridViewRolesPorServ.Location = new System.Drawing.Point(723, 415);
            this.dataGridViewRolesPorServ.Name = "dataGridViewRolesPorServ";
            this.dataGridViewRolesPorServ.ReadOnly = true;
            this.dataGridViewRolesPorServ.RowHeadersVisible = false;
            this.dataGridViewRolesPorServ.Size = new System.Drawing.Size(407, 213);
            this.dataGridViewRolesPorServ.TabIndex = 28;
            // 
            // label18
            // 
            this.label18.AutoSize = true;
            this.label18.Location = new System.Drawing.Point(723, 392);
            this.label18.Name = "label18";
            this.label18.Size = new System.Drawing.Size(97, 13);
            this.label18.TabIndex = 29;
            this.label18.Text = "Roles por Servidor:";
            // 
            // FormServidores
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1352, 729);
            this.Controls.Add(this.label18);
            this.Controls.Add(this.dataGridViewRolesPorServ);
            this.Controls.Add(this.buttonVolver);
            this.Controls.Add(this.label17);
            this.Controls.Add(this.label16);
            this.Controls.Add(this.label15);
            this.Controls.Add(this.textBoxRam);
            this.Controls.Add(this.textBoxAlm);
            this.Controls.Add(this.textBoxProc);
            this.Controls.Add(this.label12);
            this.Controls.Add(this.panel1);
            this.Controls.Add(this.label11);
            this.Controls.Add(this.label10);
            this.Controls.Add(this.dataGridViewRoles);
            this.Controls.Add(this.dataGridViewServidores);
            this.Controls.Add(this.buttonAgregarRol);
            this.Controls.Add(this.buttonAgregarSer);
            this.Controls.Add(this.textBoxNuevoRol);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.label8);
            this.Controls.Add(this.textBoxModelo);
            this.Controls.Add(this.textBoxMarca);
            this.Controls.Add(this.textBoxSerie);
            this.Controls.Add(this.label7);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "FormServidores";
            this.Text = "FormServidores";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewServidores)).EndInit();
            this.contextMenuStripServidores.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewRoles)).EndInit();
            this.contextMenuStripRoles.ResumeLayout(false);
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewRolesPorServ)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBoxSerie;
        private System.Windows.Forms.TextBox textBoxMarca;
        private System.Windows.Forms.TextBox textBoxModelo;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Label label9;
        private System.Windows.Forms.TextBox textBoxNuevoRol;
        private System.Windows.Forms.Button buttonAgregarSer;
        private System.Windows.Forms.Button buttonAgregarRol;
        private System.Windows.Forms.DataGridView dataGridViewServidores;
        private System.Windows.Forms.DataGridView dataGridViewRoles;
        private System.Windows.Forms.Label label10;
        private System.Windows.Forms.Label label11;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button buttonAsignarRol;
        private System.Windows.Forms.Label label14;
        private System.Windows.Forms.Label label13;
        private System.Windows.Forms.ComboBox comboBoxServidores;
        private System.Windows.Forms.ComboBox comboBoxRoles;
        private System.Windows.Forms.Label label12;
        private System.Windows.Forms.TextBox textBoxProc;
        private System.Windows.Forms.TextBox textBoxAlm;
        private System.Windows.Forms.TextBox textBoxRam;
        private System.Windows.Forms.Label label15;
        private System.Windows.Forms.Label label16;
        private System.Windows.Forms.Label label17;
        private System.Windows.Forms.Button buttonVolver;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripServidores;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemElimarServidor;
        private System.Windows.Forms.ContextMenuStrip contextMenuStripRoles;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItemEliminarRol;
        private System.Windows.Forms.DataGridView dataGridViewRolesPorServ;
        private System.Windows.Forms.Label label18;
    }
}