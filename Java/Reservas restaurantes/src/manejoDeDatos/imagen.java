package manejoDeDatos;

import java.awt.Component;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.table.DefaultTableCellRenderer;

public class imagen extends DefaultTableCellRenderer {

    @Override
    public Component getTableCellRendererComponent(JTable jtable, Object o, boolean bln, boolean bln1, int i, int i1) {
        if (o instanceof JLabel){
            JLabel lbl = (JLabel)o;
            return lbl;
        }
        else if(o instanceof JComboBox){
            JComboBox jbc = ( JComboBox)o;
            return jbc;
        }
        
        return super.getTableCellRendererComponent(jtable, o, bln, bln1, i, i1); 
        
    }
}
