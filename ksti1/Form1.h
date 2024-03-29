﻿#include <math.h>
#define PI 3.14

#pragma once

namespace CppCLRWinFormsProject {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	const int VERTNUM = 3; //т.к. иду путём через 2 треугольника
	const int DISMENTION = 3; //это размерность матриц (всех)

	int HMG_P[VERTNUM][DISMENTION] = { 0 }; //треугольник 1, матрица с однородными
	int HMG_REFLECTION[VERTNUM][DISMENTION] = { 0 }; //треугольник 2, матрица с однородными
	int DEK_P[VERTNUM][DISMENTION - 1] = { 0 }; //треугольник 1, матрица декартовых
	int DEK_REF[VERTNUM][DISMENTION - 1] = { 0 }; //треугольник 2, матрица декартовых
	int T_MATRIX[DISMENTION][DISMENTION] = { 0 }; //матрицы транформации 


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
	private: System::Windows::Forms::Button^ DrawBut;

	private: System::Windows::Forms::Button^ TransfBut;

	private: System::Windows::Forms::Splitter^ splitter1;
	private: System::Windows::Forms::Splitter^ splitter2;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ ScaleBut;
	private: System::Windows::Forms::Button^ CountBut;


	private: System::Windows::Forms::TextBox^ angle;

	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ RotateBut;

	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::TextBox^ textBox19;

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
			this->DrawBut = (gcnew System::Windows::Forms::Button());
			this->TransfBut = (gcnew System::Windows::Forms::Button());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			this->splitter2 = (gcnew System::Windows::Forms::Splitter());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->ScaleBut = (gcnew System::Windows::Forms::Button());
			this->CountBut = (gcnew System::Windows::Forms::Button());
			this->angle = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->RotateBut = (gcnew System::Windows::Forms::Button());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox19 = (gcnew System::Windows::Forms::TextBox());
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
			this->label9->Location = System::Drawing::Point(674, 103);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(62, 13);
			this->label9->TabIndex = 27;
			this->label9->Text = L"base vertex";
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
			// DrawBut
			// 
			this->DrawBut->Location = System::Drawing::Point(874, 238);
			this->DrawBut->Name = L"DrawBut";
			this->DrawBut->Size = System::Drawing::Size(75, 23);
			this->DrawBut->TabIndex = 30;
			this->DrawBut->Text = L"OK";
			this->DrawBut->UseVisualStyleBackColor = true;
			this->DrawBut->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// TransfBut
			// 
			this->TransfBut->Location = System::Drawing::Point(725, 498);
			this->TransfBut->Name = L"TransfBut";
			this->TransfBut->Size = System::Drawing::Size(75, 23);
			this->TransfBut->TabIndex = 31;
			this->TransfBut->Text = L"Transfer";
			this->TransfBut->UseVisualStyleBackColor = true;
			this->TransfBut->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
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
			// ScaleBut
			// 
			this->ScaleBut->Location = System::Drawing::Point(818, 498);
			this->ScaleBut->Name = L"ScaleBut";
			this->ScaleBut->Size = System::Drawing::Size(75, 23);
			this->ScaleBut->TabIndex = 35;
			this->ScaleBut->Text = L"Scale";
			this->ScaleBut->UseVisualStyleBackColor = true;
			this->ScaleBut->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// CountBut
			// 
			this->CountBut->Location = System::Drawing::Point(668, 422);
			this->CountBut->Name = L"CountBut";
			this->CountBut->Size = System::Drawing::Size(75, 23);
			this->CountBut->TabIndex = 36;
			this->CountBut->Text = L"Count";
			this->CountBut->UseVisualStyleBackColor = true;
			this->CountBut->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
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
			// RotateBut
			// 
			this->RotateBut->Location = System::Drawing::Point(909, 498);
			this->RotateBut->Name = L"RotateBut";
			this->RotateBut->Size = System::Drawing::Size(75, 23);
			this->RotateBut->TabIndex = 39;
			this->RotateBut->Text = L"Rotate";
			this->RotateBut->UseVisualStyleBackColor = true;
			this->RotateBut->Click += gcnew System::EventHandler(this, &Form1::RotateBut_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(674, 243);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(62, 13);
			this->label14->TabIndex = 40;
			this->label14->Text = L"Length, pix:";
			// 
			// textBox19
			// 
			this->textBox19->Location = System::Drawing::Point(742, 236);
			this->textBox19->Name = L"textBox19";
			this->textBox19->Size = System::Drawing::Size(67, 20);
			this->textBox19->TabIndex = 41;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Menu;
			this->ClientSize = System::Drawing::Size(997, 749);
			this->Controls->Add(this->textBox19);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->RotateBut);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->angle);
			this->Controls->Add(this->CountBut);
			this->Controls->Add(this->ScaleBut);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->splitter2);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->TransfBut);
			this->Controls->Add(this->DrawBut);
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

		//чтобы в матрицы автоматически встали единицы и нули там, где это надо:
		
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

	/*Метод для перевода в декартовые координаты. Принимаем число вершин,
	* исходную матрицу, матрицу для декартовых. Циклом ходим по строчкам
	* исходной матрицы. Делим первое и второе значение строчки на третье.
	* Так повторяем для каждой строчки. Но по факту делится на единицу всё.
	* Если в 3 столбике были нули, выкидываем ошибку.*/
	private: System::Void hmgToDek(int numOfVertexA, int hmg[][DISMENTION], //double HMG...
		int dekart[][DISMENTION - 1]) {

		for (int i = 0; i < numOfVertexA; i++) {
			double tmp = hmg[i][DISMENTION - 1];
			if (tmp != 0) {
				dekart[i][0] = hmg[i][0] / tmp;
				dekart[i][1] = hmg[i][1] / tmp;
			}
			else System::Windows::Forms::MessageBox::Show("Replace zero values.");
		}
	}

	//метод для просчёта координат для отрисовки + отрисовка другим методом
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		/*Поскольку я отрисовываю 2 равносторонних треугольника, мне
		* проще указать длину стороны, чем вершины. Но сначала проверка на то
		* если длина всё-таки не указана, то отрисовываем по вершинам. Если
		* вершины не указаны, кидаем ошибку.*/
		
		if (this->textBox19->Text->Length == 0) {

			/*проверка внутри условия, т.к. если задана длина,
			* то у нас уже не будут нули, т.к. авто расчёт.*/
			for (int i = 0; i < VERTNUM; i++) {
				for (int j = 0; j < DISMENTION; j++) {
					if (HMG_P[i][j] == 0) {
						break;
					}
				}
			}
			System::Windows::Forms::MessageBox::Show("Replace zero values.");

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
		else {

			if (this->textBox1->Text->Length == 0 && this->textBox2->Text->Length == 0) {

				int xZero = 312; //координаты центра поля
				int yZero = 245;

				this->textBox1->Text = Convert::ToString(xZero);
				this->textBox2->Text = Convert::ToString(yZero);

			} 

			HMG_P[0][0] = Convert::ToInt32(textBox1->Text);
			HMG_P[0][1] = Convert::ToInt32(textBox2->Text);

			int length = Convert::ToInt32(textBox19->Text);
			double yDelta = length / 2;
			double xDelta = sqrt(3 * pow(length, 2) / 4);

			//this->textBox1->Text = Convert::ToString(xZero);
			//this->textBox2->Text = Convert::ToString(yZero);

			this->textBox4->Text = Convert::ToString(HMG_P[0][0] - xDelta);
			this->textBox5->Text = Convert::ToString(HMG_P[0][1] - yDelta);

			this->textBox7->Text = Convert::ToString(HMG_P[0][0] + xDelta);
			this->textBox8->Text = Convert::ToString(HMG_P[0][1] + yDelta);

			//HMG_P[0][0] = xZero;
			//HMG_P[0][1] = yZero;
			HMG_P[0][2] = Convert::ToInt32(textBox3->Text);
			HMG_P[1][0] = HMG_P[0][0] - xDelta;
			HMG_P[1][1] = HMG_P[0][1] - yDelta;
			HMG_P[1][2] = Convert::ToInt32(textBox6->Text);
			HMG_P[2][0] = HMG_P[0][0] - xDelta;
			HMG_P[2][1] = HMG_P[0][1] + yDelta;
			HMG_P[2][2] = Convert::ToInt32(textBox9->Text);

			HMG_REFLECTION[0][0] = HMG_P[0][0];
			HMG_REFLECTION[0][1] = HMG_P[0][1];
			HMG_REFLECTION[0][2] = Convert::ToInt32(textBox3->Text);
			HMG_REFLECTION[1][0] = HMG_P[0][0] + xDelta;
			HMG_REFLECTION[1][1] = HMG_P[0][1] - yDelta;
			HMG_REFLECTION[1][2] = Convert::ToInt32(textBox6->Text);
			HMG_REFLECTION[2][0] = HMG_P[0][0] + xDelta;
			HMG_REFLECTION[2][1] = HMG_P[0][1] + yDelta;
			HMG_REFLECTION[2][2] = Convert::ToInt32(textBox9->Text);

			hmgToDek(VERTNUM, HMG_P, DEK_P);
			//this->pictureBox1->ResumeLayout(true);
			//this->pictureBox1->PerformLayout();
			hmgToDek(VERTNUM, HMG_REFLECTION, DEK_REF);
			//this->pictureBox1->ResumeLayout(false);
			pictureBox1->Refresh();
		}
		
	}

	//метод для отрисовки
	private: System::Void pictureBox1_Paint(System::Object^ sender, 
		System::Windows::Forms::PaintEventArgs^ e) {

		e->Graphics->DrawLine(System::Drawing::Pens::Black, DEK_P[0][0],
			DEK_P[0][1], DEK_P[1][0], DEK_P[1][1]);
		e->Graphics->DrawLine(System::Drawing::Pens::Black, DEK_P[1][0],
			DEK_P[1][1], DEK_P[2][0], DEK_P[2][1]);
		e->Graphics->DrawLine(System::Drawing::Pens::Black, DEK_P[2][0],
			DEK_P[2][1], DEK_P[0][0], DEK_P[0][1]);

		//e->Graphics->DrawLine(System::Drawing::Pens::Black, DEK_REF[0][0],
		//	DEK_REF[0][1], DEK_REF[1][0], DEK_REF[1][1]);
		//e->Graphics->DrawLine(System::Drawing::Pens::Black, DEK_REF[1][0],
		//	DEK_REF[1][1], DEK_REF[2][0], DEK_REF[2][1]);
		//e->Graphics->DrawLine(System::Drawing::Pens::Black, DEK_REF[2][0],
		//	DEK_REF[2][1], DEK_REF[0][0], DEK_REF[0][1]);


	}

	//метод чтобы посчитать синусы-косинусы для Р-матрицы и загнать их в таблицу
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


	//матрица трансформации
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->textBox10->Text = Convert::ToString(1);
		this->textBox14->Text = Convert::ToString(1);

		this->textBox11->Text = Convert::ToString(0);
		this->textBox13->Text = Convert::ToString(0);

		T_MATRIX[2][0] = Convert::ToInt32(textBox16->Text);
		T_MATRIX[2][1] = Convert::ToInt32(textBox17->Text);

		T_MATRIX[0][0] = Convert::ToInt32(textBox10->Text);
		T_MATRIX[0][1] = Convert::ToInt32(textBox11->Text);
		T_MATRIX[0][2] = Convert::ToInt32(textBox12->Text);
		T_MATRIX[1][0] = Convert::ToInt32(textBox13->Text);
		T_MATRIX[1][1] = Convert::ToInt32(textBox14->Text);
		T_MATRIX[1][2] = Convert::ToInt32(textBox15->Text);
		T_MATRIX[2][2] = Convert::ToInt32(textBox18->Text);

		double matrixResult[VERTNUM][DISMENTION] = { 0 };
		double matrixResultRef[VERTNUM][DISMENTION] = { 0 };
		
		matrix_mult(VERTNUM, HMG_P, T_MATRIX, matrixResult);
		matrix_mult(VERTNUM, HMG_REFLECTION, T_MATRIX, matrixResultRef);

		for (int i = 0; i < VERTNUM; i++) {
			for (int j = 0; j < DISMENTION; j++) {
				DEK_P[i][j] = matrixResult[i][j];
			}
		}

		for (int i = 0; i < VERTNUM; i++) {
			for (int j = 0; j < DISMENTION; j++) {
				DEK_REF[i][j] = matrixResultRef[i][j];
			}
		}
			
		pictureBox1->Refresh();
	}


	//матрица скэйл
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

		this->textBox11->Text = Convert::ToString(0);
		this->textBox13->Text = Convert::ToString(0);
		this->textBox16->Text = Convert::ToString(0);
		this->textBox17->Text = Convert::ToString(0);

		double Result[VERTNUM][DISMENTION] = { 0 };

		T_MATRIX[0][0] = Convert::ToInt32(textBox10->Text);
		T_MATRIX[1][1] = Convert::ToInt32(textBox14->Text);

		T_MATRIX[0][1] = Convert::ToInt32(textBox11->Text);
		T_MATRIX[0][2] = Convert::ToInt32(textBox12->Text);
		T_MATRIX[1][0] = Convert::ToInt32(textBox13->Text);
		T_MATRIX[1][2] = Convert::ToInt32(textBox15->Text);
		T_MATRIX[2][0] = Convert::ToInt32(textBox16->Text);
		T_MATRIX[2][1] = Convert::ToInt32(textBox17->Text);
		T_MATRIX[2][2] = Convert::ToInt32(textBox18->Text);

		Result[0][0] = ;

	}


	//матрица ротэйт
	private: System::Void RotateBut_Click(System::Object^ sender, System::EventArgs^ e) {


	}


}; //закрывает класс 

	

}
