namespace CRM3
{
    partial class FamiliaProductos
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
            this.dataGridViewFamProd = new System.Windows.Forms.DataGridView();
            this.buttonaASC = new System.Windows.Forms.Button();
            this.buttonDESC = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFamProd)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // dataGridViewFamProd
            // 
            this.dataGridViewFamProd.AllowUserToAddRows = false;
            this.dataGridViewFamProd.AllowUserToDeleteRows = false;
            this.dataGridViewFamProd.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridViewFamProd.BackgroundColor = System.Drawing.SystemColors.ControlLightLight;
            this.dataGridViewFamProd.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridViewFamProd.Location = new System.Drawing.Point(98, 12);
            this.dataGridViewFamProd.Name = "dataGridViewFamProd";
            this.dataGridViewFamProd.ReadOnly = true;
            this.dataGridViewFamProd.Size = new System.Drawing.Size(489, 230);
            this.dataGridViewFamProd.TabIndex = 0;
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
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.buttonaASC);
            this.groupBox1.Controls.Add(this.buttonDESC);
            this.groupBox1.Location = new System.Drawing.Point(98, 248);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(387, 55);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Ordenar Información";
            // 
            // FamiliaProductos
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(674, 329);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.dataGridViewFamProd);
            this.Name = "FamiliaProductos";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Familia de Productos";
            ((System.ComponentModel.ISupportInitialize)(this.dataGridViewFamProd)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridViewFamProd;
        private System.Windows.Forms.Button buttonaASC;
        private System.Windows.Forms.Button buttonDESC;
        private System.Windows.Forms.GroupBox groupBox1;
    }
}