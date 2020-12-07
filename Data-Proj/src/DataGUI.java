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

import java.util.List;

import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class DataGUI extends JDialog implements ActionListener {

	

	static List<String> records = new ArrayList<String>();
	static List<String> green = new ArrayList<String>();
	static List<String> yellow = new ArrayList<String>();
	static List<String> blue = new ArrayList<String>();
	static List<String> indigo = new ArrayList<String>();
	static List<String> red = new ArrayList<String>();
	static List<String> violet = new ArrayList<String>();
	static List<String> orange = new ArrayList<String>();





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
		 reader = new BufferedReader(new InputStreamReader(new FileInputStream("/Users/anthonymatos/eclipse-workspace/Data-Proj/src/project-data.txt")));

		 String currentLine = reader.readLine();
		 

			while (currentLine != null)
			{

				 if(currentLine.equals(" ") || !currentLine.equals(" ")) {
					 
					 
					 
					 //DataGUI record = new DataGUI();
					 records.add(currentLine);
					 //record.add(currentLine);
					  
					currentLine = reader.readLine();
					
					//System.out.println(records.get(0));
				 }

			}
		

	}
	
	


	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		
		Read();
		
		new DataGUI();

		
		for(int x=0; x<records.size(); x++) {
			if(records.get(x).equals("Color:green") ) {
				green.add(records.get(x-1));
				green.add(records.get(x-2));
				green.add(records.get(x-3));
				
			}
			if(records.get(x).equals("Color:yellow")) {
				yellow.add(records.get(x-1));
				yellow.add(records.get(x-2));
				yellow.add(records.get(x-3));
			}
			
			if(records.get(x).equals("Color:blue")) {
				blue.add(records.get(x-1));
				blue.add(records.get(x-2));
				blue.add(records.get(x-3));
			}
			
			if(records.get(x).equals("Color:indigo")) {
				indigo.add(records.get(x-1));
				indigo.add(records.get(x-2));
				indigo.add(records.get(x-3));
			}
			if(records.get(x).equals("Color:red")) {
				red.add(records.get(x-1));
				red.add(records.get(x-2));
				red.add(records.get(x-3));
			}
			if(records.get(x).equals("Color:violet")) {
				violet.add(records.get(x-1));
				violet.add(records.get(x-2));
				violet.add(records.get(x-3));
			}
			if(records.get(x).equals("Color:orange")) {
				orange.add(records.get(x-1));
				orange.add(records.get(x-2));
				orange.add(records.get(x-3));
			}
		}
		

		
		//for(int j=0; j<yellow.size(); j++) {
		//	System.out.println(yellow.get(j));
		//}

 
		
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
