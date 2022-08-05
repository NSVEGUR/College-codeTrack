import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class calculator extends Applet implements ActionListener,KeyListener
{
    Button badd, bmul, bsub, bdiv,bclear,bequal, bdot, btheme;
    Button b[]=new Button[10];
    TextField tf;
    String number1="";
    String number2="";
    String operator="";
		int flag = 0;//for theme

    public void init()
    {
			  //text field
        tf=new TextField();  
        tf.setBounds(30,40,310,60);  
        add(tf);  
        tf.addKeyListener(this); 
				//theme button
				btheme = new Button("theme");
				btheme.setBounds(350,40,70,60);
				add(btheme);
				btheme.addKeyListener(this);
				btheme.addActionListener(this);
        //buttons from 0 to 9
				int j = 0;
				for(int i=0;i<10;i++)
        {
            b[i]=new Button(""+i);
						if(i == 0)
						b[i].setBounds(110,330,70,60);
            else 
            b[i].setBounds(30+((i%3)*80),260-(j*70),70,60);
            add(b[i]);
            b[i].addActionListener(this); 
            b[i].addKeyListener(this);  
						if(i == 3)
						j = 1;
						else if(i==6)
						j = 2;
        }
        //operatorerators
        bdiv=new Button("/");  
        bdiv.setBounds(270,120,70,60);
        bmul=new Button("*");  
        bmul.setBounds(270,190,70,60);
        bsub=new Button("-");  
        bsub.setBounds(270,260,70,60);
				bclear=new Button("C");  
        bclear.setBounds(30,330,70,60);  
        bdot=new Button(".");  
        bdot.setBounds(190,330,70,60);
        badd=new Button("+");  
        badd.setBounds(270,330,70,60);
				bequal=new Button("=");  
        bequal.setBounds(350,330,70,60);
        add(bdiv);
        add(bmul);
        add(bsub);
				add(bclear);
				add(bdot);
        add(bequal);
        add(badd);
				bdiv.addActionListener(this);
				bmul.addActionListener(this);
				bsub.addActionListener(this);
        bclear.addActionListener(this);
        bdot.addActionListener(this);  
        bequal.addActionListener(this);  
        badd.addActionListener(this); 
				bdiv.addKeyListener(this);
				bmul.addKeyListener(this);
				bsub.addKeyListener(this); 
				bdot.addKeyListener(this);
        bclear.addKeyListener(this); 
        bequal.addKeyListener(this);  
        badd.addKeyListener(this);  
    
        setLayout(null);  
    }
    public void keyTyped(KeyEvent e){ 
    }  
    public void keyReleased(KeyEvent e){ 
    }  
    public void keyPressed(KeyEvent e) 
    {
            
    } 
    public void actionPerformed(ActionEvent e)
    {      
	    String button = e.getActionCommand();
	    char ch = button.charAt(0);
			if(button == "theme")
			{
				if(flag == 0)
				setBackground(Color.darkGray);
				else
				setBackground(Color.white);
				flag = flag == 0 ? 1 : 0;
			}
			else if(ch>='0' && ch<='9'|| ch=='.') 
			{ 
			if (!operator.equals("")) 
			number2 = number2 + button; 
			else
			number1 = number1 + button;   
			tf.setText(number1+operator+number2); 
			} 
			else if(ch=='C') 
			{ 
			number1 = operator = number2 = ""; 
			tf.setText(""); 
			}
			else if (ch =='=') 
			{ 
			if(!number1.equals("") && !number2.equals(""))
			{
			double temp;
			double n1=Double.parseDouble(number1);
			double n2=Double.parseDouble(number2);
			if(n2==0 && operator.equals("/"))
			{
				tf.setText(number1+operator+number2+" = Zero Division Error");
				number1 = operator = number2 = "";
			}
			else
			{
				if (operator.equals("+")) 
						temp = n1 + n2; 
				else if (operator.equals("-")) 
						temp = n1 - n2; 
				else if (operator.equals("/")) 
							temp = n1/n2; 
				else
						temp = n1*n2; 
				tf.setText(number1+operator+number2+" = "+temp); 
				number1 = Double.toString(temp);
				operator = number2 = ""; 
					}
						}
			else
			{
			number1 = operator = number2 = ""; 
			tf.setText("");
			}
				} 
			else 
			{ 
			if (operator.equals("") || number2.equals("")) 
			operator = button; 
			else 
			{ 
			double temp;
			double n1=Double.parseDouble(number1);
			double n2=Double.parseDouble(number2);
			if(n2==0 && operator.equals("/"))
			{
				tf.setText(number1+operator+number2+" = Zero Division Error");
				number1 = operator = number2 = "";
			}
			else
			{
				if (operator.equals("+")) 
						temp = n1 + n2; 
				else if (operator.equals("-")) 
						temp = n1 - n2; 
				else if (operator.equals("/")) 
							temp = n1/n2; 
				else
						temp = n1*n2; 
				number1 = Double.toString(temp); 
				operator = button; 
				number2 = ""; 
					}
						}
			tf.setText(number1+operator+number2);
				}

			}   
}

/* 
<applet code="calculator.class" width="450" height="400"> 
</applet> 
*/