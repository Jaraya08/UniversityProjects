namespace SistemaGestor
{
    partial class cFormPrincipal
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(cFormPrincipal));
            this.button1 = new System.Windows.Forms.Button();
            this.panel1 = new System.Windows.Forms.Panel();
            this.buttonCerrarSistema = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.buttonErrores = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.buttonDepartamento = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.panel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(134, 19);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(126, 23);
            this.button1.TabIndex = 0;
            this.button1.Text = "Aplicación";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // panel1
            // 
            this.panel1.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.panel1.Controls.Add(this.buttonCerrarSistema);
            this.panel1.Controls.Add(this.button4);
            this.panel1.Controls.Add(this.buttonErrores);
            this.panel1.Controls.Add(this.button3);
            this.panel1.Controls.Add(this.button1);
            this.panel1.Controls.Add(this.buttonDepartamento);
            this.panel1.Location = new System.Drawing.Point(12, 30);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(428, 310);
            this.panel1.TabIndex = 1;
            // 
            // buttonCerrarSistema
            // 
            this.buttonCerrarSistema.Location = new System.Drawing.Point(134, 258);
            this.buttonCerrarSistema.Name = "buttonCerrarSistema";
            this.buttonCerrarSistema.Size = new System.Drawing.Size(126, 23);
            this.buttonCerrarSistema.TabIndex = 6;
            this.buttonCerrarSistema.Text = "Cerrar Sistema";
            this.buttonCerrarSistema.UseVisualStyleBackColor = true;
            this.buttonCerrarSistema.Click += new System.EventHandler(this.buttonCerrarSistema_Click);
            // 
            // button4
            // 
            this.button4.Location = new System.Drawing.Point(134, 209);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(126, 23);
            this.button4.TabIndex = 5;
            this.button4.Text = "Personas";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // buttonErrores
            // 
            this.buttonErrores.Location = new System.Drawing.Point(134, 162);
            this.buttonErrores.Name = "buttonErrores";
            this.buttonErrores.Size = new System.Drawing.Size(126, 23);
            this.buttonErrores.TabIndex = 3;
            this.buttonErrores.Text = "Sistema de Gestion";
            this.buttonErrores.UseVisualStyleBackColor = true;
            this.buttonErrores.Click += new System.EventHandler(this.buttonErrores_Click);
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(134, 115);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(126, 23);
            this.button3.TabIndex = 2;
            this.button3.Text = "Servidor";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // buttonDepartamento
            // 
            this.buttonDepartamento.Location = new System.Drawing.Point(134, 69);
            this.buttonDepartamento.Name = "buttonDepartamento";
            this.buttonDepartamento.Size = new System.Drawing.Size(126, 23);
            this.buttonDepartamento.TabIndex = 1;
            this.buttonDepartamento.Text = "Departamento";
            this.buttonDepartamento.UseVisualStyleBackColor = true;
            this.buttonDepartamento.Click += new System.EventHandler(this.button2_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(63, 7);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(320, 20);
            this.label1.TabIndex = 2;
            this.label1.Text = "Sistema de Gestión de Activos de Software ";
            // 
            // cFormPrincipal
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 729);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.panel1);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "cFormPrincipal";
            this.Text = "Sistema de Gestión";
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.panel1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button buttonDepartamento;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button buttonErrores;
        private System.Windows.Forms.Button buttonCerrarSistema;
        private System.Windows.Forms.Label label1;
    }
}

