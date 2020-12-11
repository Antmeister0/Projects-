import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

 class Person{
	private String Date;
	private String Name;
	private String Company;
	
	
	
	public Person(String date, String name, String company) {
		
		this.Date = date;
		this.Name = name;
		this.Company = company;
		
	}
	
	
	public String getDate() {
		return this.Date;
	}
	
	public String getName() {
		return this.Name;
	}
	
	public String getCompany() {
		return this.Company;
	}
	
	
	@Override   //this is to override the default way of printing out the objects with new function toString
	public String toString() {
        return ("Date:"+this.getDate()+
                " Name: "+ this.getName() +
                " Company: "+ this.getCompany() 
                );
	}
	
}

public class DataGUI extends JDialog implements ActionListener {
	

	
	static ArrayList<Person> record = new ArrayList<Person>();

	static List<Person> green = new ArrayList<Person>();
	static List<Person> yellow = new ArrayList<Person>();
	static List<Person> blue = new ArrayList<Person>();
	static List<Person> indigo = new ArrayList<Person>();
	static List<Person> red = new ArrayList<Person>();
	static List<Person> violet = new ArrayList<Person>();
	static List<Person> orange = new ArrayList<Person>();
	

	static BufferedReader reader;
	
	private JFrame frame;

	
	JButton button1;
	JButton button2;
	JButton button3;
	JButton button4;
	JButton button5;
	JButton button6;
	JButton button7;

	
	public DataGUI(){
		frame = new JFrame();
		JPanel panel = new JPanel();
		JLabel label =  new JLabel("Pick a color");
		
		panel.setBorder(BorderFactory.createEmptyBorder(30,30 ,10,30));
		panel.setLayout(new GridLayout(0,1));
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	       frame.setSize(500,500);
	       
	   
	       panel.add(label);
	       
	       button1 = new JButton("Green");
	       button2 = new JButton("Yellow");
	       button3 = new JButton("Blue");
	       button4 = new JButton("Indigo");
	       button5 = new JButton("Red");
	       button6 = new JButton("Violet");
	       button7 = new JButton("Orange");


	       button2.addActionListener(this);
	       button2.setActionCommand("yellow");
	       button2.setOpaque(true);
	       button2.setBackground(Color.YELLOW);
	       
	       
	       
	       button1.addActionListener(this);
	       button1.setActionCommand("green");
	       button1.setOpaque(true);
	       button1.setBackground(Color.GREEN);
	       
	       
	       button3.addActionListener(this);
	       button3.setActionCommand("blue");
	       button3.setOpaque(true);
	       button3.setBackground(Color.BLUE);
	       
	       button4.addActionListener(this);
	       button4.setActionCommand("indigo");
	       button4.setOpaque(true);
	       button4.setBackground(Color.PINK);
	       
	       button5.addActionListener(this);
	       button5.setActionCommand("red");
	       button5.setOpaque(true);
	       button5.setBackground(Color.RED);
	       
	       button6.addActionListener(this);
	       button6.setActionCommand("violet");
	       button6.setOpaque(true);
	       button6.setBackground(Color.MAGENTA);
	       
	       button7.addActionListener(this);
	       button7.setActionCommand("orange");
	       button7.setOpaque(true);
	       button7.setBackground(Color.ORANGE);
	       
	       
	       
	       panel.add(button1);
	       panel.add(button2);
	       panel.add(button3);
	       panel.add(button4);
	       panel.add(button5);
	       panel.add(button6);
	       panel.add(button7);



	       
	       
	       frame.add(panel,BorderLayout.CENTER);
	       // Adds Button to content pane of frame
	       frame.setTitle("Data GUI");
	       frame.setVisible(true);
	       
	       
	}
	
	
	
	public static void Read() throws IOException {
		 reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/anthonymatos/git/Projects-/Data-Proj/src/project-data.txt")));
				 String currentLine = reader.readLine();
		 
			String f1 ="";
			String f2 = "";
			String f3 = "";	
		 
			while (currentLine != null)
			{
				
				if(currentLine.contains("Date:")) {
					if(currentLine.substring(0, 5).equals("Date:")) {
						f1 = currentLine.substring(5, currentLine.length());
					}
				}
				
				

				if(currentLine.contains("Name:")) {
					if(currentLine.substring(0, 5).equals("Name:")) {
						f2 = currentLine.substring(5, currentLine.length());
						//System.out.println(""+f2);
					}
				}
				
				
				if(currentLine.contains("Company:")) {
					if(currentLine.substring(0, 8).equals("Company:")) {
						f3 = currentLine.substring(8, currentLine.length());
					}
				}
				
				if(currentLine.contains("Color:")) {
					if(currentLine.substring(0, 6).contentEquals("Color:")) {
						String color = currentLine.substring(6, currentLine.length());
						
						Person emp = new Person(f1,f2,f3);
						
						record.add(emp);
						
						addObj(color,emp);

					}
					
				}
				

				currentLine = reader.readLine();
				

			}
			
			

	}
	
	






	private static void addObj(String color, Person emp) {
		// TODO Auto-generated method stub
		
		if(color.contentEquals("green")) {
			green.add(emp);
		}
		if(color.contentEquals("yellow")) {
			yellow.add(emp);
		}
		
		if(color.contentEquals("blue")) {
			blue.add(emp);
		}
		if(color.contentEquals("indigo")) {
			indigo.add(emp);
		}
		
		if(color.contentEquals("red")) {
			red.add(emp);
		}
		
		if(color.contentEquals("violet")) {
			violet.add(emp);
		}
		
		if(color.contentEquals("orange")) {
			orange.add(emp);
		}
		
	}



	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		
		Read();
		
		new DataGUI();

		
		//System.out.println(new File(".").getAbsolutePath());
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		
		
		
		
		
		if("green".equals(e.getActionCommand())) {
		
			DialogLists.showDialog(frame, button1,  "Names in the green category:", "Name Chooser", green);

		}
		
		if("yellow".equals(e.getActionCommand())) {
			DialogLists.showDialog(frame, button2,  "Names in the yellow category:", "Name Chooser", yellow);
		}

		
		if("blue".equals(e.getActionCommand())) {
			DialogLists.showDialog(frame, button3,  "Names in the blue category:", "Name Chooser", blue);
		}
		
		if("indigo".equals(e.getActionCommand())) {
			DialogLists.showDialog(frame, button4,  "Names in the indigo category:", "Name Chooser", indigo);
		}
		if("red".equals(e.getActionCommand())) {
			DialogLists.showDialog(frame, button5,  "Names in the red category:", "Name Chooser", red);
		}
		
		if("violet".equals(e.getActionCommand())) {
			DialogLists.showDialog(frame, button6,  "Names in the violet category:", "Name Chooser", violet);
		}
		
		if("orange".equals(e.getActionCommand())) {
			DialogLists.showDialog(frame, button7,  "Names in the orange category:", "Name Chooser", orange);
		}
		

		
	}






}
