namespace CRM3
{
    partial class VentasPorSector
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
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea3 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend3 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series3 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title3 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.maskedTextBoxAnno = new System.Windows.Forms.MaskedTextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label1 = new System.Windows.Forms.Label();
            this.dateTimePickerFinal = new System.Windows.Forms.DateTimePicker();
            this.dateTimePickerInicio = new System.Windows.Forms.DateTimePicker();
            this.comboBoxMeses = new System.Windows.Forms.ComboBox();
            this.radioButtonRango = new System.Windows.Forms.RadioButton();
            this.radioButtonMes = new System.Windows.Forms.RadioButton();
            this.buttonConsultar = new System.Windows.Forms.Button();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.groupBox3.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            this.SuspendLayout();
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label4);
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.maskedTextBoxAnno);
            this.groupBox3.Controls.Add(this.label2);
            this.groupBox3.Controls.Add(this.label1);
            this.groupBox3.Controls.Add(this.dateTimePickerFinal);
            this.groupBox3.Controls.Add(this.dateTimePickerInicio);
            this.groupBox3.Controls.Add(this.comboBoxMeses);
            this.groupBox3.Controls.Add(this.radioButtonRango);
            this.groupBox3.Controls.Add(this.radioButtonMes);
            this.groupBox3.Location = new System.Drawing.Point(621, 83);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(296, 217);
            this.groupBox3.TabIndex = 2;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Filtros";
            // 
            // maskedTextBoxAnno
            // 
            this.maskedTextBoxAnno.Location = new System.Drawing.Point(156, 56);
            this.maskedTextBoxAnno.Mask = "9999";
            this.maskedTextBoxAnno.Name = "maskedTextBoxAnno";
            this.maskedTextBoxAnno.Size = new System.Drawing.Size(100, 20);
            this.maskedTextBoxAnno.TabIndex = 8;
            this.maskedTextBoxAnno.ValidatingType = typeof(int);
            this.maskedTextBoxAnno.MaskInputRejected += new System.Windows.Forms.MaskInputRejectedEventHandler(this.maskedTextBoxAnno_MaskInputRejected);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(17, 153);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(62, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Fecha Final";
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(14, 114);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(65, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Fecha Inicio";
            // 
            // dateTimePickerFinal
            // 
            this.dateTimePickerFinal.Format = System.Windows.Forms.DateTimePickerFormat.Short;
            this.dateTimePickerFinal.Location = new System.Drawing.Point(17, 169);
            this.dateTimePickerFinal.Name = "dateTimePickerFinal";
            this.dateTimePickerFinal.Size = new System.Drawing.Size(266, 20);
            this.dateTimePickerFinal.TabIndex = 4;
            // 
            // dateTimePickerInicio
            // 
            this.dateTimePickerInicio.Format = System.Windows.Forms.DateTimePickerFormat.Custom;
            this.dateTimePickerInicio.Location = new System.Drawing.Point(17, 130);
            this.dateTimePickerInicio.Name = "dateTimePickerInicio";
            this.dateTimePickerInicio.Size = new System.Drawing.Size(266, 20);
            this.dateTimePickerInicio.TabIndex = 3;
            // 
            // comboBoxMeses
            // 
            this.comboBoxMeses.FormattingEnabled = true;
            this.comboBoxMeses.Items.AddRange(new object[] {
            "Enero",
            "Febrero",
            "Marzo",
            "Abril",
            "Mayo",
            "Junio",
            "Julio",
            "Agosto",
            "Septiembre",
            "Octubre",
            "Noviembre",
            "Diciembre"});
            this.comboBoxMeses.Location = new System.Drawing.Point(17, 56);
            this.comboBoxMeses.Name = "comboBoxMeses";
            this.comboBoxMeses.Size = new System.Drawing.Size(112, 21);
            this.comboBoxMeses.TabIndex = 2;
            // 
            // radioButtonRango
            // 
            this.radioButtonRango.AutoSize = true;
            this.radioButtonRango.Location = new System.Drawing.Point(16, 94);
            this.radioButtonRango.Name = "radioButtonRango";
            this.radioButtonRango.Size = new System.Drawing.Size(105, 17);
            this.radioButtonRango.TabIndex = 1;
            this.radioButtonRango.TabStop = true;
            this.radioButtonRango.Text = "Rango de Fecha";
            this.radioButtonRango.UseVisualStyleBackColor = true;
            // 
            // radioButtonMes
            // 
            this.radioButtonMes.AutoSize = true;
            this.radioButtonMes.Location = new System.Drawing.Point(20, 19);
            this.radioButtonMes.Name = "radioButtonMes";
            this.radioButtonMes.Size = new System.Drawing.Size(45, 17);
            this.radioButtonMes.TabIndex = 0;
            this.radioButtonMes.TabStop = true;
            this.radioButtonMes.Text = "Mes";
            this.radioButtonMes.UseVisualStyleBackColor = true;
            // 
            // buttonConsultar
            // 
            this.buttonConsultar.Location = new System.Drawing.Point(621, 338);
            this.buttonConsultar.Name = "buttonConsultar";
            this.buttonConsultar.Size = new System.Drawing.Size(296, 23);
            this.buttonConsultar.TabIndex = 4;
            this.buttonConsultar.Text = "Gráficar";
            this.buttonConsultar.UseVisualStyleBackColor = true;
            this.buttonConsultar.Click += new System.EventHandler(this.buttonConsultar_Click);
            // 
            // dataGridView1
            // 
            this.dataGridView1.AllowUserToAddRows = false;
            this.dataGridView1.AllowUserToDeleteRows = false;
            this.dataGridView1.AutoSizeColumnsMode = System.Windows.Forms.DataGridViewAutoSizeColumnsMode.Fill;
            this.dataGridView1.BackgroundColor = System.Drawing.SystemColors.ButtonHighlight;
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Location = new System.Drawing.Point(621, 367);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.ReadOnly = true;
            this.dataGridView1.Size = new System.Drawing.Size(296, 182);
            this.dataGridView1.TabIndex = 6;
            // 
            // chart1
            // 
            chartArea3.Area3DStyle.Enable3D = true;
            chartArea3.Area3DStyle.Inclination = 50;
            chartArea3.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea3);
            legend3.Name = "Legend1";
            this.chart1.Legends.Add(legend3);
            this.chart1.Location = new System.Drawing.Point(12, 12);
            this.chart1.Name = "chart1";
            series3.ChartArea = "ChartArea1";
            series3.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Pie;
            series3.Legend = "Legend1";
            series3.Name = "Series1";
            series3.SmartLabelStyle.MaxMovingDistance = 20D;
            this.chart1.Series.Add(series3);
            this.chart1.Size = new System.Drawing.Size(568, 537);
            this.chart1.TabIndex = 7;
            this.chart1.Text = "chart1";
            title3.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            title3.Name = "Title1";
            title3.Text = "Ventas Por Sector";
            this.chart1.Titles.Add(title3);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(14, 39);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(30, 13);
            this.label3.TabIndex = 9;
            this.label3.Text = "Mes:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(153, 40);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(29, 13);
            this.label4.TabIndex = 10;
            this.label4.Text = "Año:";
            // 
            // VentasPorSector
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(984, 561);
            this.Controls.Add(this.chart1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.buttonConsultar);
            this.Controls.Add(this.groupBox3);
            this.Name = "VentasPorSector";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Gráfico de Ventas Por Sector";
            this.Load += new System.EventHandler(this.GrapVentasPorSector_Load);
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.DateTimePicker dateTimePickerFinal;
        private System.Windows.Forms.DateTimePicker dateTimePickerInicio;
        private System.Windows.Forms.ComboBox comboBoxMeses;
        private System.Windows.Forms.RadioButton radioButtonRango;
        private System.Windows.Forms.RadioButton radioButtonMes;
        private System.Windows.Forms.Button buttonConsultar;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.MaskedTextBox maskedTextBoxAnno;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label3;
    }
}