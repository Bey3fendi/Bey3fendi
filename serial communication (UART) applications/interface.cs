/*
 * Created by SharpDevelop.
 * User: bb
 * Date: 5.12.2022
 * Time: 13:51
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO.Ports;
using System.Windows.Forms;

namespace bb
{
	/// <summary>
	/// Description of MainForm.
	/// </summary>
	public partial class MainForm : Form
	{
		string gelenveri=string.Empty;
        
		public MainForm()
		{
			InitializeComponent();
		}
		
		
		//port ac kismi
		void Button1Click(object sender, EventArgs e)
		{
			if (!serialPort1.IsOpen){
				serialPort1.PortName=textPort.Text;
				serialPort1.BaudRate=9600;
				serialPort1.Open();
			}
		}
		void Button2Click(object sender, EventArgs e)
		{
			serialPort1.Write("#"+textBox3.Text+"*");
		}
	    void BtnsaatClick(object sender, EventArgs e)
		{
	        serialPort1.Write("$"+textBox1.Text);
		}
		void SerialPort1DataReceived(object sender, System.IO.Ports.SerialDataReceivedEventArgs e)
		{
			string x=string.Empty;
			string c=serialPort1.ReadExisting();
			//gelenveri=gelenveri+c;
			gelenveri=x+c;
			
			//this.Invoke(new EventHandler(displaytext));
			//this.Invoke(new EventHandler(displaytext2));
			this.Invoke(new EventHandler(Button3Click));
			
//			string d=serialPort1.ReadExisting();
//			if(String.Equals(c,karsilastirma)){
//				gelenveri=gelenveri+c;
//				this.Invoke(new EventHandler(displaytext));
			
//			}
			
		}
		
void Button3Click(object sender, EventArgs e)
		{	
		textBox4.Text=gelenveri;	
		//textBox2.Text=gelenveri;
        //textBox4.Clear();
        //textBox2.Clear();
		}
		//void displaytext(object sender, EventArgs e){
//			string c=serialPort1.ReadExisting();
//			if(String.Equals(c,karsilastirma)){
//				textBox4.Text=gelenveri;
//			}
			
			
	//	}
		
		//void displaytext2(object sender, EventArgs e){
			//textBox2.Text=gelenveri;
		//}
		
		void BtnportkapatClick(object sender, EventArgs e)
		{
			if (serialPort1.IsOpen){
				serialPort1.Close();
			}
		}
		void Label4Click(object sender, EventArgs e)
		{
	
		}
		void TextPortTextChanged(object sender, EventArgs e)
		{
	
		}
		void TextBox1TextChanged(object sender, EventArgs e)
		{
	
		}
		void TextBox3TextChanged(object sender, EventArgs e)
		{
           
				
		}
		void MainFormLoad(object sender, EventArgs e)
		{

		}
		void TextBox4TextChanged(object sender, EventArgs e)
		{
				
		
		}

		void Label2Click(object sender, EventArgs e)
		{
	
		}
		void Button4Click(object sender, EventArgs e)
		{
	        textBox4.Clear();
            //textBox2.Clear();
		}



	}
}
