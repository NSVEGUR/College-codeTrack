import java.applet.Applet;
import java.awt.*;

public class Paint extends Applet{
  public void paint(Graphics g)
  {
   //Outer  oval
   g.drawOval(624,0, 400, 200);

   //Inner oval
   g.drawOval(674,25, 300, 150);
   g.setColor(Color.lightGray);
   g.fillOval(674,25, 300, 150);

   //Outer Rectangle
   g.drawRect(0, 520, 400, 200);
   g.setColor(Color.darkGray);
   g.fillRect(0, 520, 400, 200);
  
   //Inner Rectangle
   g.setColor(Color.white);
   g.drawRect(50, 545, 300, 150);

   //Center Circle
   g.setColor(Color.black);
   g.fillOval(412, 260, 200, 200);

   //Text
   Font myFont = new Font("Lucida", Font.BOLD, 20);
   g.setFont(myFont);
   g.setColor(Color.white);
   g.drawString("Nagasai Vegur", 440, 370);
  }
}

/*
<applet code="Paint.class" width="1024" height="720"></applet
*/