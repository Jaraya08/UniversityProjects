namespace CRM3
{
    partial class CantidadEjecuciones
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
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label1 = new System.Windows.Forms.Label();
            this.maskedTextBoxAño = new System.Windows.Forms.MaskedTextBox();
            this.buttonaASC = new System.Windows.Forms.Button();
            this.buttonDESC = new System.Windows.Forms.Button();
            this.dataGridViewEjecuciones = new System.Windows.Forms.DataGridView();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewEjecuciones)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.maskedTextBoxAño);
            this.groupBox1.Controls.Add(this.buttonaASC);
            this.groupBox1.Controls.Add(this.buttonDESC);
            this.groupBox1.Location = new System.Drawing.Point(67, 283);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(489, 72);
            this.groupBox1.TabIndex = 15;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Ordenar Información";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(355, 16);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(29, 13);
            this.label1.TabIndex = 4;
            this.label1.Text = "Año:";
            // 
            // maskedTextBoxAño
            // 
            this.maskedTextBoxAño.Location = new System.Drawing.Point(358, 34);
            this.maskedTextBoxAño.Mask = "9999";
            this.maskedTextBoxAño.Name = "maskedTextBoxAño";
            this.maskedTextBoxAño.Size = new System.Drawing.Size(100, 20);
            this.maskedTextBoxAño.TabIndex = 3;
            // 
            // buttonaASC
            // 
            this.buttonaASC.Location = new System.Drawing.Point(47, 31);
            this.buttonaASC.Name = "buttonaASC";
            this.buttonaASC.Size = new System.Drawing.Size(75, 23);
            this.buttonaASC.TabIndex = 1;
            this.buttonaASC.Text = "Ascendente";
            this.buttonaASC.UseVisualStyleBackColor = true;
            this.buttonaASC.Click += new System.EventHandler(this.buttonaASC_Click);
            // 
            // buttonDESC
            // 
            this.buttonDESC.Location = new System.Drawing.Point(148, 31);
            this.buttonDESC.Name = "buttonDESC";
            this.buttonDESC.Size = new System.Drawing.Size(75, 23);
            this.buttonDESC.TabIndex = 2;
            this.buttonDESC.Text = "Desendente";
            this.buttonDESC.UseVisualStyleBackColor = true;
            this.buttonDESC.Click += new System.EventHandler(this.buttonDESC_Click);
            // 
            // dataGridViewEjecuciones
            // 
            this.dataGridViewEjecuciones.AllowUserToAddRows = false;
            this.dataGridViewEjecuciones.AllowUserToDeleteRows = false;
            this.dataGridViewEjecuciones.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewEjecuciones.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.dataGridViewEjecuciones.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewEjecuciones.Location = new System.Drawing.Point(67, 38);
            this.dataGridViewEjecuciones.Name = "dataGridViewEjecuciones";
            this.dataGridViewEjecuciones.ReadOnly = true;
            this.dataGridViewEjecuciones.Size = new System.Drawing.Size(489, 230);
            this.dataGridViewEjecuciones.TabIndex = 14;
            // 
            // CantidadEjecuciones
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(623, 377);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.dataGridViewEjecuciones);
            this.Name = "CantidadEjecuciones";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "CantidadEjecuciones";
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewEjecuciones)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxAño;
        private System.Windows.Forms.Button buttonaASC;
        private System.Windows.Forms.Button buttonDESC;
        private System.Windows.Forms.DataGridView dataGridViewEjecuciones;
    }
}