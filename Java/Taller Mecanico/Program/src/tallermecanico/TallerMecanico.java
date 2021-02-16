/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tallermecanico;

import Interfaz.PaginaPrincipal;
import de.javasoft.plaf.synthetica.SyntheticaBlackEyeLookAndFeel;
import de.javasoft.plaf.synthetica.SyntheticaBlackMoonLookAndFeel;
import de.javasoft.plaf.synthetica.SyntheticaSimple2DLookAndFeel;
import java.text.ParseException;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

/**
 *
 * @author Jordan Araya
 */
public class TallerMecanico {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
           UIManager.setLookAndFeel(new SyntheticaSimple2DLookAndFeel());
            PaginaPrincipal Nueva = new PaginaPrincipal();
            Nueva.setVisible(true);
        } catch (UnsupportedLookAndFeelException ex) {
            Logger.getLogger(TallerMecanico.class.getName()).log(Level.SEVERE, null, ex);
        } catch (ParseException ex) {
            Logger.getLogger(TallerMecanico.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
