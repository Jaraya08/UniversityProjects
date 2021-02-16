/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Logica;


import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import org.jpl7.Query;
import org.jpl7.Term;


/**
 *
 * @author Jordan Araya
 */
public class Prolog {
    public static ArrayList<ArrayList> Estadisticas = new ArrayList();
    public Prolog(){}
    
    /**
     *E: Ninguna
     *S: Una lista con la solucion de un kakuro proveniente de una conexion de prolog.
     *R: El Archivo.pl debe estar dentro de la carpeta de este proyecto
     *o: Realizar una conexion con prolog para extraer soluciones de un kakuros.
     * @return 
     */
    public ArrayList tablero()
    {
        ArrayList<Object> lista = new ArrayList();
        String kakuro = "consult('kakuro.pl')";
        Query prolog = new Query(kakuro);
        if(prolog.hasSolution())
        {
            String tablero = "tablero(T)";
            Query solucion = new Query(tablero);
            Term soluc = (Term) solucion.oneSolution().get("T");
            while(soluc.arity() == 2)
            {
                 lista.add(soluc.arg(1));
                    soluc = soluc.arg(2);
            }
            solucion.close();
        }
        prolog.close();
        return lista;
    }
    /**
     * E: JTable estadisticas
     * S: Una JTable con los valores de las estadisticas ingresados, se rerotna para ser mostrado en pantalla.
     * R: Ninguna.
     * O: Moestar en pantalla las estadisticas generales del juego.
     * @param estadisticas
     * @return JTable con los valores de las estadisticas generadas en toda la ejecuacion del sistema
     */
    public JTable llenarTabla(JTable estadisticas)
    {
        DefaultTableModel modelo = (DefaultTableModel) estadisticas.getModel();
        estadisticas.setModel(modelo);
        
        for(int i = 0;i<Estadisticas.size();i++)
        {
            String datos[] = new String[7];
            for(int j=0;j<Estadisticas.get(i).size();j++)
            {
                datos[j]=Estadisticas.get(i).get(j).toString();
            }
            modelo.addRow(datos);
        }
        return estadisticas;
    }
   
}
