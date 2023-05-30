#include <math.h>
#define PI 3.14

#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int VERTNUM = 3;
	const int DISMENTION = 3;

	int HMG_P[VERTNUM][DISMENTION] = { 0 };
	int DEK_P[VERTNUM][DISMENTION - 1] = { 0 };
	int MATRIX_T[DISMENTION][DISMENTION] = { 0 };


	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::TextBox^ textBox7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TextBox^ textBox9;
	private: System::Windows::Forms::TextBox^ textBox10;
	private: System::Windows::Forms::TextBox^ textBox11;
	private: System::Windows::Forms::TextBox^ textBox12;
	private: System::Windows::Forms::TextBox^ textBox13;
	private: System::Windows::Forms::TextBox^ textBox14;
	private: System::Windows::Forms::TextBox^ textBox15;
	private: System::Windows::Forms::TextBox^ textBox16;
	private: System::Windows::Forms::TextBox^ textBox17;
	private: System::Windows::Forms::TextBox^ textBox18;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::Splitter^ splitter2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ angle;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ button5;

	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->textBox15 = (gcnew System::Windows::Forms::TextBox());
			this->textBox16 = (gcnew System::Windows::Forms::TextBox());
			this->textBox17 = (gcnew System::Windows::Forms::TextBox());
			this->textBox18 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->angle = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->pictureBox1->Location = System::Drawing::Point(28, 26);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(625, 490);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(805, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Painting matrix";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(767, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(14, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"X";
			this->label2->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(841, 72);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Y";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(917, 72);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(13, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(755, 100);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(37, 20);
			this->textBox1->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(828, 100);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(37, 20);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(903, 100);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(37, 20);
			this->textBox3->TabIndex = 7;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(755, 144);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(37, 20);
			this->textBox4->TabIndex = 10;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(828, 144);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(37, 20);
			this->textBox5->TabIndex = 9;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(903, 147);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(37, 20);
			this->textBox6->TabIndex = 8;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(755, 188);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(37, 20);
			this->textBox7->TabIndex = 13;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(828, 188);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(37, 20);
			this->textBox8->TabIndex = 12;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(903, 188);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(37, 20);
			this->textBox9->TabIndex = 11;
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(763, 360);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(56, 20);
			this->textBox10->TabIndex = 26;
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(837, 360);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(56, 20);
			this->textBox11->TabIndex = 25;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(909, 360);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(56, 20);
			this->textBox12->TabIndex = 24;
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(763, 405);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(56, 20);
			this->textBox13->TabIndex = 23;
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(837, 405);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(56, 20);
			this->textBox14->TabIndex = 22;
			// 
			// textBox15
			// 
			this->textBox15->Location = System::Drawing::Point(909, 405);
			this->textBox15->Name = L"textBox15";
			this->textBox15->Size = System::Drawing::Size(56, 20);
			this->textBox15->TabIndex = 21;
			// 
			// textBox16
			// 
			this->textBox16->Location = System::Drawing::Point(763, 453);
			this->textBox16->Name = L"textBox16";
			this->textBox16->Size = System::Drawing::Size(56, 20);
			this->textBox16->TabIndex = 20;
			// 
			// textBox17
			// 
			this->textBox17->Location = System::Drawing::Point(837, 453);
			this->textBox17->Name = L"textBox17";
			this->textBox17->Size = System::Drawing::Size(56, 20);
			this->textBox17->TabIndex = 19;
			// 
			// textBox18
			// 
			this->textBox18->Location = System::Drawing::Point(909, 453);
			this->textBox18->Name = L"textBox18";
			this->textBox18->Size = System::Drawing::Size(56, 20);
			this->textBox18->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(936, 328);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(13, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"1";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(860, 328);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(14, 13);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Y";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(786, 328);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(14, 13);
			this->label7->TabIndex = 15;
			this->label7->Text = L"X";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(805, 295);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(107, 13);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Transformation matrix";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(686, 103);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(42, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"vertex1";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(686, 147);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(42, 13);
			this->label10->TabIndex = 28;
			this->label10->Text = L"vertex2";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(686, 195);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(42, 13);
			this->label11->TabIndex = 29;
			this->label11->Text = L"vertex3";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(808, 233);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 30;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(725, 498);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 31;
			this->button2->Text = L"Transfer";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(0, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(3, 749);
			this->splitter1->TabIndex = 32;
			this->splitter1->TabStop = false;
			// 
			// splitter2
			// 
			this->splitter2->Location = System::Drawing::Point(3, 0);
			this->splitter2->Name = L"splitter2";
			this->splitter2->Size = System::Drawing::Size(3, 749);
			this->splitter2->TabIndex = 33;
			this->splitter2->TabStop = false;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(605, 519);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(48, 13);
			this->label12->TabIndex = 34;
			this->label12->Text = L"625x490";
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(818, 498);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 35;
			this->button3->Text = L"Scale";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(668, 422);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 36;
			this->button4->Text = L"Count";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// angle
			// 
			this->angle->Location = System::Drawing::Point(668, 396);
			this->angle->Name = L"angle";
			this->angle->Size = System::Drawing::Size(60, 20);
			this->angle->TabIndex = 37;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(669, 380);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(61, 13);
			this->label13->TabIndex = 38;
			this->label13->Text = L"Angle, deg:";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(909, 498);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 39;
			this->button5->Text = L"Rotate";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(997, 749);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->angle);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->textBox10);
			this->Controls->Add(this->textBox11);
			this->Controls->Add(this->textBox12);
			this->Controls->Add(this->textBox13);
			this->Controls->Add(this->textBox14);
			this->Controls->Add(this->textBox15);
			this->Controls->Add(this->textBox16);
			this->Controls->Add(this->textBox17);
			this->Controls->Add(this->textBox18);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox8);
			this->Controls->Add(this->textBox9);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

		this->textBox3->Text = "1";
		this->textBox6->Text = "1";
		this->textBox9->Text = "1";
		this->textBox12->Text = "0";
		this->textBox15->Text = "0";
		this->textBox18->Text = "1";
	}

//==============================================================================================

	

	private: System::Void matrix_mult(int numOfVertexA, int matrix1[][DISMENTION], //double matrix1,2
		int matrix2[][DISMENTION], double matrixResult[][DISMENTION]) {

		for (int i = 0; i < numOfVertexA; i++) {
			for (int j = 0; j < DISMENTION; j++) {
				matrixResult[i][j] = 0;
				for (int k = 0; k < DISMENTION; k++) {
					matrixResult[i][j] += matrix1[i][k] * matrix2[k][j];
				}
			}
		}
	}

	private: System::Void hmgToDek(int numOfVertexA, int HMG[][DISMENTION], //double HMG...
		int dekart[][DISMENTION - 1]) {

		for (int i = 0; i < numOfVertexA; i++) {
			double tmp = HMG[i][DISMENTION - 1];
			if (tmp != 0) {
				dekart[i][0] = HMG[i][0] / tmp;
				dekart[i][1] = HMG[i][1] / tmp;
			}
			else System::Windows::Forms::MessageBox::Show("Replace zero values.");
		}
	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		HMG_P[0][0] = Convert::ToInt32(textBox1->Text);
		HMG_P[0][1] = Convert::ToInt32(textBox2->Text);
		HMG_P[0][2] = Convert::ToInt32(textBox3->Text);
		HMG_P[1][0] = Convert::ToInt32(textBox4->Text);
		HMG_P[1][1] = Convert::ToInt32(textBox5->Text);
		HMG_P[1][2] = Convert::ToInt32(textBox6->Text);
		HMG_P[2][0] = Convert::ToInt32(textBox7->Text);
		HMG_P[2][1] = Convert::ToInt32(textBox8->Text);
		HMG_P[2][2] = Convert::ToInt32(textBox9->Text);

		hmgToDek(VERTNUM, HMG_P, DEK_P);

		pictureBox1->Refresh();
	}


	private: System::Void pictureBox1_Paint(System::Object^ sender, 
		System::Windows::Forms::PaintEventArgs^ e) {

		e->Graphics->DrawLine(System::Drawing::Pens::Red, DEK_P[0][0],
			DEK_P[0][1], DEK_P[1][0], DEK_P[1][1]);
		e->Graphics->DrawLine(System::Drawing::Pens::Red, DEK_P[1][0],
			DEK_P[1][1], DEK_P[2][0], DEK_P[2][1]);
		e->Graphics->DrawLine(System::Drawing::Pens::Red, DEK_P[2][0],
			DEK_P[2][1], DEK_P[0][0], DEK_P[0][1]);
	}


	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		MATRIX_T[0][0] = Convert::ToInt32(textBox10->Text);
		MATRIX_T[0][1] = Convert::ToInt32(textBox11->Text);
		MATRIX_T[0][2] = Convert::ToInt32(textBox12->Text);
		MATRIX_T[1][0] = Convert::ToInt32(textBox13->Text);
		MATRIX_T[1][1] = Convert::ToInt32(textBox14->Text);
		MATRIX_T[1][2] = Convert::ToInt32(textBox15->Text);
		MATRIX_T[2][0] = Convert::ToInt32(textBox16->Text);
		MATRIX_T[2][1] = Convert::ToInt32(textBox17->Text);
		MATRIX_T[2][2] = Convert::ToInt32(textBox18->Text);

		double Result[VERTNUM][DISMENTION] = { 0 }; // служебный массив для
		//вычислений
		matrix_mult(3, HMG_P, MATRIX_T, Result); // проведение заданного
		// преобразования
		for (int i = 0; i < VERTNUM; i++)
			for (int j = 0; j < DISMENTION; j++)
				HMG_P[i][j] = Result[i][j]; // запоминание новых
		// координат фигуры
		hmgToDek(VERTNUM, HMG_P, DEK_P); // перевод координат из
		//однородных в экранные
		pictureBox1->Refresh(); // вызов перерисовки элемента
		//pictureBox
	}


	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		MATRIX_T[0][0] = Convert::ToInt32(textBox10->Text);
		MATRIX_T[0][1] = Convert::ToInt32(textBox11->Text);
		MATRIX_T[0][2] = Convert::ToInt32(textBox12->Text);
		MATRIX_T[1][0] = Convert::ToInt32(textBox13->Text);
		MATRIX_T[1][1] = Convert::ToInt32(textBox14->Text);
		MATRIX_T[1][2] = Convert::ToInt32(textBox15->Text);
		MATRIX_T[2][0] = Convert::ToInt32(textBox16->Text);
		MATRIX_T[2][1] = Convert::ToInt32(textBox17->Text);
		MATRIX_T[2][2] = Convert::ToInt32(textBox18->Text);

	}


	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox16->Text = Convert::ToString(0);
		this->textBox17->Text = Convert::ToString(0);

		double angle1 = Convert::ToInt32(angle->Text);
		double angleRad = angle1 * PI / 180;

		double angleSin = sin(angleRad);
		double angleCos = cos(angleRad);

		this->textBox3->Text = "1";

		this->textBox10->Text = Convert::ToString(angleCos);
		this->textBox11->Text = Convert::ToString(0 - angleSin);
		this->textBox13->Text = Convert::ToString(angleSin);
		this->textBox14->Text = Convert::ToString(angleCos);

	}


}; //закрывает класс 

	

}
