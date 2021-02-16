using SQLite;
using System;

namespace Despacha.Despacha.Models
{
    public class Despacho
    {
        [PrimaryKey, AutoIncrement, Column("_id")]
        public int IdRegistro { get; set; }

        public string Contenedor { get; set; }
        [MaxLength(8)]
        public string Tamanho { get; set; }

        [MaxLength(30)]
        public string Ced_Chofer { get; set; }

        [MaxLength(10)]
        public string Placa { get; set; }

        [MaxLength(30)]
        public string Marchamo { get; set; }

        public int Despachado { get; set; }

        public String FechaSalida { get; set; }

        public String FechaIngreso { get; set; }

        public string FechaPlacaPre => $" Placa: {Placa}";
        public string FechaMarchamoPre => $" Marchamo: {Marchamo}";
        public string FechaSalidaPre => $" Fecha: {FechaSalida} ";

    }
}