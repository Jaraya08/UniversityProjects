using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Windows.Forms;

namespace SistemaGestor
{


    class ManejoBD
    {
        SqlCommand cmm;
        ConexionBD Conexion = new ConexionBD();

        /*Devuelve el codigo de la ultima fila de la tabla segun los datos recibos*/
        public int ultimoCodigo(String columna, string tabla) {
            Conexion.conectar();
            cmm = new SqlCommand("Select top(1) " + columna + " FROM " + tabla + " order by " + columna + " desc ", Conexion.getConexion());
            if (cmm.ExecuteScalar() is null)
            {
                Conexion.desconectar();
                return 1;
            }
            else
            {
                int codigo = Convert.ToInt32(cmm.ExecuteScalar());

                Conexion.desconectar();
                return codigo + 1;
            }
        }

        /*Agrega un departamento a la base de datos*/
        public void agregarDepartamento(string nombre)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO Departamentos (Nombre_Departamento) values(@P1)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", nombre);
                cmm.ExecuteNonQuery();
            }
            catch (Exception e) {
                if (e is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }

        }

        /*Eliminar un departamente segun el codigo recibido*/
        public void eliminarDepartamento(int codigo)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM Departamentos WHERE Codigo_Departamento =" + codigo, Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                if (e is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Agrega una Aplicacion en la base de datos*/
        public void agregarSoftware(string Nombre, string tipo, string fecha, int depa, string descripcion)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO Software (Nombre_Software,Tipo_Software,Fecha,Departamento,Descripcion_Software) values(@P1,@P2,@P3,@P4,@P5)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", Nombre);
                cmm.Parameters.AddWithValue("@P2", tipo);
                cmm.Parameters.AddWithValue("@P3", Convert.ToDateTime(fecha));
                cmm.Parameters.AddWithValue("@P4", depa);
                cmm.Parameters.AddWithValue("@P5", descripcion);
                cmm.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                if (e is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }



        }
       
        /*Eliminar una aplicacion de la base de datos segun el codigo ingresado*/
        public void eliminarSoftware(int codigo)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM Software WHERE Codigo_Software =" + codigo, Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }


        }

        /*Agrega una conexion de aplicacion a un servidor */
        public void aplicacionAServidor(int idAplicacion,string serieServ)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO Aplicacion_servidor (Serie_Servidores,Codigo_Software) values(@P1,@P2)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", serieServ);
                cmm.Parameters.AddWithValue("@P2", idAplicacion);
                cmm.ExecuteNonQuery();

            }
            catch(Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Elimina una conexion de aplicacion Servidor*/
        public void eliminarAplicacionSer(int codigo)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM Aplicacion_servidor WHERE  Codigo_Software = " + codigo,Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Agrega un servidor a la base de dato*/
        public void agregarServidor(string serie, string marca, string modelo, double Proces, double Almac, double Ram) {
            Conexion.conectar();
            try {
                cmm = new SqlCommand("INSERT INTO Servidor (Serie,Marca,Modelo,CapacidadPROC,CapacidadALM,MemoriaRAM) values(@P1,@P2,@P3,@P4,@P5,@P6)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", serie);
                cmm.Parameters.AddWithValue("@P2", marca);
                cmm.Parameters.AddWithValue("@P3", modelo);
                cmm.Parameters.AddWithValue("@P4", Proces);
                cmm.Parameters.AddWithValue("@P5", Almac);
                cmm.Parameters.AddWithValue("@P6", Ram);
                cmm.ExecuteNonQuery();
            }
            catch (Exception e)
            {
                if (e is SqlException)
                {
                    throw new Exception();
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Elimina un servudor de la base de datos segun la serie que ingrese*/
        public void eliminarServidor(String serie)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM Servidor WHERE Serie ='" + serie + "'", Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();

            }
        }

        /*Elimina los roles de los servidores*/
        public void eliminarRolASer(String serie)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM RolAServidor WHERE Serie_Servidor ='" + serie + "'", Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Elimina sevidores de las aplicaciones*/
        public void eliminarServDeApliacion(string serie)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM Aplicacion_servidor WHERE Serie_Servidores = '" + serie + "'", Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Agrega un rol a la base de datos*/
        public void agregarRol(string rol)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO RolesServidores (Tipo_Rol) values(@P1)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", rol);
                cmm.ExecuteNonQuery();
            }
            catch (Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();

            }
        }

        /*Elimina un rol de la base de datos*/
        public void eliminarRol(int idRol)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM RolesServidores WHERE Codigo_Rol = " + idRol, Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }


        /*Agrega una persona a la base de datos*/
        public void agregarPersona(String nombre, string cedula, string apellido, string rol)
            {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO Personas (Nombre,Cedula,Apellido,Rol) values(@P1,@P2,@P3,@P4)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", nombre);
                cmm.Parameters.AddWithValue("@P2", cedula);
                cmm.Parameters.AddWithValue("@P3", apellido);
                cmm.Parameters.AddWithValue("@P4", rol);
                cmm.ExecuteNonQuery();
            }
             catch(Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
            }

        /*Elimina una persona de la base de datos*/
        public void eliminarPersona(string ced)
            {
                Conexion.conectar();
                cmm = new SqlCommand("DELETE FROM Personas WHERE Cedula ='" + ced + "'", Conexion.getConexion());
                cmm.ExecuteNonQuery();
                Conexion.desconectar();

            }

        /*Elimina personas asociadas a un proyecto*/
        public void eliminarPersProy(string cedula)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("DELETE FROM Personas_Proyectos WHERE Cedula_Miembro = '" + cedula + "'", Conexion.getConexion());
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Agrega un error a la base de datos*/
        public void agregarError(string SerieSer, string aplicacion, DateTime fechaError, DateTime hora, string impacto, string descripcion)
            {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO ErrorProduccion (Serie_Servidor,Nombre_Aplicacion,Fecha_Error,Hora_Error,Impacto,Descripcion_Erro) values(@P1,@P2,@P3,@P4,@P5,@P6)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", SerieSer);
                cmm.Parameters.AddWithValue("@P2", aplicacion);
                cmm.Parameters.AddWithValue("@P3", Convert.ToDateTime(fechaError));
                cmm.Parameters.AddWithValue("@P4", Convert.ToDateTime(hora));
                cmm.Parameters.AddWithValue("@P5", impacto);
                cmm.Parameters.AddWithValue("@P6", descripcion);
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
                
                
            }

        /*Elimina un errror de la base de datos*/
        public void eliminarError(int codigo)
        {
            Conexion.conectar();
            cmm = new SqlCommand("DELETE FROM ErrorProduccion WHERE Codigo_Erro =" + codigo, Conexion.getConexion());
            cmm.ExecuteNonQuery();
            Conexion.desconectar();
        }

        /*Agrega un proyecto de corrreciion a la base de datos*/
        public void agregarProyecto(string nombre, string fechaINI, string fechaFIN, double esfuerzoEst, double esfuerzoReal, string descripcion)
            {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO ProyectoCorreccion (Nombre_Coreccion,FechaINI,FechaFIN,EsfuezoEstimado,EsfuerzoReal,Descripcion_Correcion) VALUES(@P1,@P2,@P3,@P4,@P5,@P6)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", nombre);
                cmm.Parameters.AddWithValue("@P2", Convert.ToDateTime(fechaINI));
                cmm.Parameters.AddWithValue("@P3", Convert.ToDateTime(fechaFIN));
                cmm.Parameters.AddWithValue("@P4", Convert.ToDouble(esfuerzoEst));
                cmm.Parameters.AddWithValue("@P5", Convert.ToDouble(esfuerzoReal));
                cmm.Parameters.AddWithValue("@P6", descripcion);
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if(ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
            }

        /*Elimina un proyecto de la base de datos*/
        public void eliminarProyecto(int codigo)
            {
                Conexion.conectar();
                cmm = new SqlCommand("DELETE FROM ProyectoCorreccion WHERE Codigo_Correcion =" + codigo, Conexion.getConexion());
                cmm.ExecuteNonQuery();
                Conexion.desconectar();
            }

        /*Agrega un rol a un servidor*/
        public void rolAServidor(string rol, string codigoServidor)
        {
            Conexion.conectar();
            try
            {
                cmm = new SqlCommand("INSERT INTO RolAServidor (Serie_Servidor,TipoRol) VALUES(@P1,@P2)", Conexion.getConexion());
                cmm.Parameters.AddWithValue("@P1", codigoServidor);
                cmm.Parameters.AddWithValue("@P2", rol);
                cmm.ExecuteNonQuery();
            }
            catch(Exception ex)
            {
                if (ex is SqlException)
                {
                    throw;
                }
            }
            finally
            {
                Conexion.desconectar();
            }
        }

        /*Agrega una persona a un proyecto*/
        public void personasProyect(int codigoSoft, string cedula)
            {
                Conexion.conectar();
                try
                {
                cmm = new SqlCommand("INSERT INTO Personas_Proyectos (Codigo_Proyecto,Cedula_Miembro) values(@P1,@P2)", Conexion.getConexion());
                    cmm.Parameters.AddWithValue("@P1", codigoSoft);
                    cmm.Parameters.AddWithValue("@P2", cedula);
                    cmm.ExecuteNonQuery();
                }
                catch (Exception ex)
                {
                    if (ex is SqlException)
                    {
                        throw;
                    }
                }
                finally
                {
                    Conexion.desconectar();

                }
               
        }

        }
    }

