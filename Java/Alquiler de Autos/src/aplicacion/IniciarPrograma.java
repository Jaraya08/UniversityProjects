/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package aplicacion;

import interfazgrafica.Inicio;
/**
 * Arranca la ventana de inicio del programa
 * @author Warner Diaz
 */
public class IniciarPrograma {
    public static void main(String[] args) {
        Inicio inicio = new Inicio(); //Ventana de inicio
        inicio.setVisible(true);
    }
}
