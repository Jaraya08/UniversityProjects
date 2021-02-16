/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package manejoDeDatos;

/**
 *
 * @author Jordan Araya
 */
public class Sustitucion {
    
    public Sustitucion(){}
    
    /**
     * cambiar todas las letras "ñ" por un letra "n"
     * @param palabra
     * @return retornar el nuevo string con las letras "ñ" cambiadas por "n"
     */
    public String remplazar(String palabra){
        int resultado = palabra.toLowerCase().indexOf("ñ");
        String palabreMin=palabra.toLowerCase();
        if(resultado!=-1){
            String remplazar = palabreMin.replace('ñ', 'n');
            char[] caracter = remplazar.toCharArray();
            caracter[0]=Character.toUpperCase(caracter[0]);
            return new String(caracter);
        }
        else{
            char[] caracter = palabreMin.toCharArray();
            caracter[0]=Character.toUpperCase(caracter[0]);
            return new String(caracter);
        }
        
    }
    
}
