/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package kakuros;


import de.javasoft.plaf.synthetica.SyntheticaBlackEyeLookAndFeel;
import interfaz.Principal;
import java.text.ParseException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

/**
 *
 * @author Jordan Araya
 */
public class Kakuros {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        try {
            UIManager.setLookAndFeel(new SyntheticaBlackEyeLookAndFeel());
            Principal nueva = new Principal();
            nueva.setVisible(true);
//            Principal nueva = new Principal();
//            nueva.setVisible(true);
        } catch (UnsupportedLookAndFeelException ex) {
            Logger.getLogger(Kakuros.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ParseException ex) {
            Logger.getLogger(Kakuros.class.getName()).log(Level.SEVERE, null, ex);
        }

        
    }
    
}
