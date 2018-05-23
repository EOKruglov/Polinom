#pragma once
#include "TPolinom.h"

namespace Polinom {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for MyForm
	/// </summary>
	TPolynom pol1, pol2, res;
	TMonom inp;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(59, 77);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(345, 20);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(56, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"coeff";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(172, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"X";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(268, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Y";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(370, 36);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(14, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Z";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(192, 33);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(33, 20);
			this->textBox3->TabIndex = 6;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(288, 33);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(33, 20);
			this->textBox4->TabIndex = 7;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(390, 33);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(33, 20);
			this->textBox5->TabIndex = 8;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(447, 77);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(60, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Add";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(530, 77);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(60, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(100, 33);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(33, 20);
			this->textBox2->TabIndex = 5;
			// 
			// textBox6
			// 
			this->textBox6->Enabled = false;
			this->textBox6->Location = System::Drawing::Point(59, 243);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(345, 20);
			this->textBox6->TabIndex = 11;
			this->textBox6->Text = L"0";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(56, 212);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"coeff";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(100, 205);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(33, 20);
			this->textBox7->TabIndex = 13;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(192, 205);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(33, 20);
			this->textBox8->TabIndex = 14;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(288, 205);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(33, 20);
			this->textBox9->TabIndex = 15;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(390, 205);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(33, 20);
			this->textBox10->TabIndex = 16;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(172, 208);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 17;
			this->label6->Text = L"X";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(268, 208);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 18;
			this->label7->Text = L"Y";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(370, 208);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(14, 13);
			this->label8->TabIndex = 19;
			this->label8->Text = L"Z";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(447, 240);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(60, 23);
			this->button3->TabIndex = 20;
			this->button3->Text = L"Add";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(530, 240);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(60, 23);
			this->button4->TabIndex = 21;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(211, 312);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(13, 13);
			this->label9->TabIndex = 22;
			this->label9->Text = L"=";
			// 
			// textBox11
			// 
			this->textBox11->Enabled = false;
			this->textBox11->Location = System::Drawing::Point(59, 364);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(679, 20);
			this->textBox11->TabIndex = 23;
			this->textBox11->Text = L"0";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(100, 145);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(60, 23);
			this->button5->TabIndex = 24;
			this->button5->Text = L"+";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(222, 145);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(60, 23);
			this->button6->TabIndex = 25;
			this->button6->Text = L"-";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(344, 145);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(60, 23);
			this->button7->TabIndex = 26;
			this->button7->Text = L"*";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(773, 361);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(75, 23);
			this->button8->TabIndex = 27;
			this->button8->Text = L"Delete";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(924, 494);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	inp.coeff = Convert::ToInt32(textBox2->Text);
	inp.x = Convert::ToInt32(textBox3->Text);
	inp.y = Convert::ToInt32(textBox4->Text);
	inp.z = Convert::ToInt32(textBox5->Text);

	pol1.InsByOrder(inp);

	textBox1->Text = "";


	for (pol1.reset(); !pol1.isEnd(); pol1.goNext())
	{
		if (pol1.getElem().coeff != 0) {
			textBox1->Text += pol1.getElem().coeff
				+ "*x^" + pol1.getElem().x
				+ "*y^" + pol1.getElem().y
				+ "*z^" + pol1.getElem().z;
			if (!pol1.isLast()) textBox1->Text += "+";
		}

	}
	}

	
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	inp.coeff = Convert::ToInt32(textBox7->Text);
	inp.x = Convert::ToInt32(textBox8->Text);
	inp.y = Convert::ToInt32(textBox9->Text);
	inp.z = Convert::ToInt32(textBox10->Text);

	pol2.InsByOrder(inp);

	textBox6->Text = "";



	for (pol2.reset(); !pol2.isEnd(); pol2.goNext())
	{
		if (pol2.getElem().coeff != 0) {
			textBox6->Text += pol2.getElem().coeff
				+ "*x^" + pol2.getElem().x
				+ "*y^" + pol2.getElem().y
				+ "*z^" + pol2.getElem().z;
			if (!pol2.isLast()) textBox6->Text += "+";
		}
	}
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	res = pol1 + pol2;
	textBox11->Text = "";

	if (!res.isEmpty()) {
		for (res.reset(); !res.isEnd(); res.goNext())
		{
			if (res.getElem().coeff != 0) {
				textBox11->Text += res.getElem().coeff
					+ "*x^" + res.getElem().x
					+ "*y^" + res.getElem().y
					+ "*z^" + res.getElem().z;
				if (!res.isLast()) textBox11 -> Text += "+";
			}
		}
	}
	else textBox11 -> Text = "0";
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	res = pol1 - pol2;
	textBox11->Text = "";

	if (!res.isEmpty()) {
		for (res.reset(); !res.isEnd(); res.goNext())
		{
			if (res.getElem().coeff != 0) {
				textBox11->Text += res.getElem().coeff
					+ "*x^" + res.getElem().x
					+ "*y^" + res.getElem().y
					+ "*z^" + res.getElem().z;
				if (!res.isLast()) textBox11->Text += "+";
			}
		}
	}
	else textBox11->Text = "0";
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	res = pol1 * pol2;
	textBox11->Text = "";

	if (!res.isEmpty()) {
		for (res.reset(); !res.isEnd(); res.goNext())
		{
			if (res.getElem().coeff != 0) {
				textBox11->Text += res.getElem().coeff
					+ "*x^" + res.getElem().x
					+ "*y^" + res.getElem().y
					+ "*z^" + res.getElem().z;
				if (!res.isLast()) textBox11->Text += "+";
			}
		}
	}
	else textBox11->Text = "0";
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	pol1.clearList();
	textBox1->Text = "0";
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	pol2.clearList();
	textBox6->Text = "0";
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	res.clearList();
	textBox11->Text = "0";
}
};
};
