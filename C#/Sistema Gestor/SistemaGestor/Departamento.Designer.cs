namespace SistemaGestor
{
    partial class Departamento
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
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle3 = new System.Windows.Forms.DataGridViewCellStyle();
            System.Windows.Forms.DataGridViewCellStyle dataGridViewCellStyle4 = new System.Windows.Forms.DataGridViewCellStyle();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.textBoxNombreDepa = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.textBoxCodigoDepa = new System.Windows.Forms.TextBox();
            this.dataGridViewDepartamentos = new System.Windows.Forms.DataGridView();
            this.buttonAgregarDepa = new System.Windows.Forms.Button();
            this.panelEliminar = new System.Windows.Forms.Panel();
            this.label4 = new System.Windows.Forms.Label();
            this.buttonEliminarDepartamento = new System.Windows.Forms.Button();
            this.buttonVolver = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDepartamentos)).BeginInit();
            this.panelEliminar.SuspendLayout();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Modern No. 20", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(32, 13);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(242, 18);
            this.label1.TabIndex = 0;
            this.label1.Text = "Agregar un nuevo departamento";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label2.Location = new System.Drawing.Point(33, 102);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(160, 15);
            this.label2.TabIndex = 1;
            this.label2.Text = "Nombre de Departamento : ";
            // 
            // textBoxNombreDepa
            // 
            this.textBoxNombreDepa.Location = new System.Drawing.Point(229, 101);
            this.textBoxNombreDepa.Name = "textBoxNombreDepa";
            this.textBoxNombreDepa.Size = new System.Drawing.Size(350, 20);
            this.textBoxNombreDepa.TabIndex = 2;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(36, 66);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(154, 15);
            this.label3.TabIndex = 3;
            this.label3.Text = "Codigo de Departamento : ";
            // 
            // textBoxCodigoDepa
            // 
            this.textBoxCodigoDepa.Enabled = false;
            this.textBoxCodigoDepa.Location = new System.Drawing.Point(230, 65);
            this.textBoxCodigoDepa.Name = "textBoxCodigoDepa";
            this.textBoxCodigoDepa.Size = new System.Drawing.Size(78, 20);
            this.textBoxCodigoDepa.TabIndex = 4;
            this.textBoxCodigoDepa.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // dataGridViewDepartamentos
            // 
            this.dataGridViewDepartamentos.AllowUserToAddRows = false;
            this.dataGridViewDepartamentos.AllowUserToDeleteRows = false;
            this.dataGridViewDepartamentos.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewDepartamentos.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            dataGridViewCellStyle3.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle3.BackColor = System.Drawing.SystemColors.Control;
            dataGridViewCellStyle3.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle3.ForeColor = System.Drawing.SystemColors.WindowText;
            dataGridViewCellStyle3.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle3.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle3.WrapMode = System.Windows.Forms.DataGridViewTriState.True;
            this.dataGridViewDepartamentos.ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
            this.dataGridViewDepartamentos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            dataGridViewCellStyle4.Alignment = System.Windows.Forms.DataGridViewContentAlignment.MiddleCenter;
            dataGridViewCellStyle4.BackColor = System.Drawing.SystemColors.Window;
            dataGridViewCellStyle4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            dataGridViewCellStyle4.ForeColor = System.Drawing.SystemColors.ControlText;
            dataGridViewCellStyle4.SelectionBackColor = System.Drawing.SystemColors.Highlight;
            dataGridViewCellStyle4.SelectionForeColor = System.Drawing.SystemColors.HighlightText;
            dataGridViewCellStyle4.WrapMode = System.Windows.Forms.DataGridViewTriState.False;
            this.dataGridViewDepartamentos.DefaultCellStyle = dataGridViewCellStyle4;
            this.dataGridViewDepartamentos.Location = new System.Drawing.Point(39, 214);
            this.dataGridViewDepartamentos.Name = "dataGridViewDepartamentos";
            this.dataGridViewDepartamentos.ReadOnly = true;
            this.dataGridViewDepartamentos.RowHeadersVisible = false;
            this.dataGridViewDepartamentos.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dataGridViewDepartamentos.Size = new System.Drawing.Size(541, 217);
            this.dataGridViewDepartamentos.TabIndex = 5;
            // 
            // buttonAgregarDepa
            // 
            this.buttonAgregarDepa.Location = new System.Drawing.Point(450, 171);
            this.buttonAgregarDepa.Name = "buttonAgregarDepa";
            this.buttonAgregarDepa.Size = new System.Drawing.Size(129, 23);
            this.buttonAgregarDepa.TabIndex = 6;
            this.buttonAgregarDepa.Text = "Agregar Departamento";
            this.buttonAgregarDepa.UseVisualStyleBackColor = true;
            this.buttonAgregarDepa.Click += new System.EventHandler(this.buttonAgregarDepa_Click);
            // 
            // panelEliminar
            // 
            this.panelEliminar.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panelEliminar.Controls.Add(this.label4);
            this.panelEliminar.ForeColor = System.Drawing.SystemColors.ControlText;
            this.panelEliminar.Location = new System.Drawing.Point(39, 484);
            this.panelEliminar.Name = "panelEliminar";
            this.panelEliminar.Size = new System.Drawing.Size(541, 37);
            this.panelEliminar.TabIndex = 7;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(22, 11);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(489, 13);
            this.label4.TabIndex = 0;
            this.label4.Text = "Nota: Para Eliminar un departamento debe selecionarlo y presionar el boton de \'El" +
    "iminar Departamento\'";
            // 
            // buttonEliminarDepartamento
            // 
            this.buttonEliminarDepartamento.Location = new System.Drawing.Point(450, 446);
            this.buttonEliminarDepartamento.Name = "buttonEliminarDepartamento";
            this.buttonEliminarDepartamento.Size = new System.Drawing.Size(130, 23);
            this.buttonEliminarDepartamento.TabIndex = 8;
            this.buttonEliminarDepartamento.Text = "Eliminar Departamento";
            this.buttonEliminarDepartamento.UseVisualStyleBackColor = true;
            this.buttonEliminarDepartamento.Click += new System.EventHandler(this.buttonbuttonEliminarDepartamento_Click);
            // 
            // buttonVolver
            // 
            this.buttonVolver.Location = new System.Drawing.Point(450, 609);
            this.buttonVolver.Name = "buttonVolver";
            this.buttonVolver.Size = new System.Drawing.Size(129, 23);
            this.buttonVolver.TabIndex = 9;
            this.buttonVolver.Text = "Volver";
            this.buttonVolver.UseVisualStyleBackColor = true;
            this.buttonVolver.Click += new System.EventHandler(this.buttonVolver_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label5.Location = new System.Drawing.Point(39, 194);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(95, 15);
            this.label5.TabIndex = 11;
            this.label5.Text = "Departamentos:";
            // 
            // Departamento
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1352, 729);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.buttonVolver);
            this.Controls.Add(this.buttonEliminarDepartamento);
            this.Controls.Add(this.panelEliminar);
            this.Controls.Add(this.buttonAgregarDepa);
            this.Controls.Add(this.dataGridViewDepartamentos);
            this.Controls.Add(this.textBoxCodigoDepa);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.textBoxNombreDepa);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Name = "Departamento";
            this.Text = "Departamentos";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.Load += new System.EventHandler(this.Departamento_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewDepartamentos)).EndInit();
            this.panelEliminar.ResumeLayout(false);
            this.panelEliminar.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox textBoxNombreDepa;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox textBoxCodigoDepa;
        private System.Windows.Forms.DataGridView dataGridViewDepartamentos;
        private System.Windows.Forms.Button buttonAgregarDepa;
        private System.Windows.Forms.Panel panelEliminar;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button buttonEliminarDepartamento;
        private System.Windows.Forms.Button buttonVolver;
        private System.Windows.Forms.Label label5;
    }
}