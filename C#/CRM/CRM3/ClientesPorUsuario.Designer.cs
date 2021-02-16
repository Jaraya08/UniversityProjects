namespace CRM3
{
    partial class ClientesPorUsuario
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
            this.buttonaASC = new System.Windows.Forms.Button();
            this.buttonDESC = new System.Windows.Forms.Button();
            this.dataGridViewClientesPorUsuario = new System.Windows.Forms.DataGridView();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewClientesPorUsuario)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonaASC);
            this.groupBox1.Controls.Add(this.buttonDESC);
            this.groupBox1.Location = new System.Drawing.Point(67, 283);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(489, 55);
            this.groupBox1.TabIndex = 11;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Ordenar Información";
            // 
            // buttonaASC
            // 
            this.buttonaASC.Location = new System.Drawing.Point(143, 19);
            this.buttonaASC.Name = "buttonaASC";
            this.buttonaASC.Size = new System.Drawing.Size(75, 23);
            this.buttonaASC.TabIndex = 1;
            this.buttonaASC.Text = "Ascendente";
            this.buttonaASC.UseVisualStyleBackColor = true;
            this.buttonaASC.Click += new System.EventHandler(this.buttonaASC_Click);
            // 
            // buttonDESC
            // 
            this.buttonDESC.Location = new System.Drawing.Point(285, 19);
            this.buttonDESC.Name = "buttonDESC";
            this.buttonDESC.Size = new System.Drawing.Size(75, 23);
            this.buttonDESC.TabIndex = 2;
            this.buttonDESC.Text = "Desendente";
            this.buttonDESC.UseVisualStyleBackColor = true;
            this.buttonDESC.Click += new System.EventHandler(this.buttonDESC_Click);
            // 
            // dataGridViewClientesPorUsuario
            // 
            this.dataGridViewClientesPorUsuario.AllowUserToAddRows = false;
            this.dataGridViewClientesPorUsuario.AllowUserToDeleteRows = false;
            this.dataGridViewClientesPorUsuario.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewClientesPorUsuario.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.dataGridViewClientesPorUsuario.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewClientesPorUsuario.Location = new System.Drawing.Point(67, 38);
            this.dataGridViewClientesPorUsuario.Name = "dataGridViewClientesPorUsuario";
            this.dataGridViewClientesPorUsuario.ReadOnly = true;
            this.dataGridViewClientesPorUsuario.Size = new System.Drawing.Size(489, 230);
            this.dataGridViewClientesPorUsuario.TabIndex = 10;
            // 
            // ClientesPorUsuario
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(623, 377);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.dataGridViewClientesPorUsuario);
            this.Name = "ClientesPorUsuario";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "ClientesPorUsuario";
            this.groupBox1.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewClientesPorUsuario)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button buttonaASC;
        private System.Windows.Forms.Button buttonDESC;
        private System.Windows.Forms.DataGridView dataGridViewClientesPorUsuario;
    }
}