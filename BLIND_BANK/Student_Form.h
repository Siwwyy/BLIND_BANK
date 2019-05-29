#pragma once
//#include "Logowanie.h"
#include "Configure_String.hpp"
#include <typeinfo>

namespace BLINDBANK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Student_Form
	/// </summary>
	public ref class Student_Form : public System::Windows::Forms::Form
	{
	public:
		Student_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		//currently constructor contains integer type, finally change it to string for example, String^ role
		Student_Form(const int role) :
			role(role)
		{
			InitializeComponent();

		}

		Student_Form(const int role, String^ & Admin_Name, int id, System::Windows::Forms::Form ^ _Form) :
			role(role),
			Admin_Name(Admin_Name),
			Logowanie_Form(_Form),
			_id(id),
		    jk(false)
		{
			InitializeComponent();

		}
	private: System::Windows::Forms::DataGridView^  dgAKTUALNYPLIK;
	public:

	protected:
		int _id;
		String^ _fromFile;
		String^ _filePath;
		String^ _idpd;
		String^ _fileStr;
		bool jk;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button8;

	protected:
		String^ _nazwapd;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Student_Form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblAdmin;
	protected:
	private: System::Windows::Forms::Label^  label1;

	private:
		/*
			PRIVATE VARIABLES
		*/
		//Here add mysql reader
		String^ konfiguracja = SQL_CONFIGURATION::get_konfiguracja();
		//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=blind_bank_db";
	//	String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";
		int role;
		String^ Admin_Name;
		System::Windows::Forms::Form ^ Logowanie_Form;


	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Button^  btnWYLOGUJ;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  Przeslij;
	private: System::Windows::Forms::DataGridView^  gdPrace;


	private: System::Windows::Forms::Button^  button2;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::DataGridView^  dgMain;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::DataGridView^  dgOceny;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::DataGridView^  dgGrupy;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;











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
			this->lblAdmin = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->btnWYLOGUJ = (gcnew System::Windows::Forms::Button());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->dgMain = (gcnew System::Windows::Forms::DataGridView());
			this->Przeslij = (gcnew System::Windows::Forms::TabPage());
			this->dgAKTUALNYPLIK = (gcnew System::Windows::Forms::DataGridView());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->gdPrace = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->dgOceny = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->dgGrupy = (gcnew System::Windows::Forms::DataGridView());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMain))->BeginInit();
			this->Przeslij->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAKTUALNYPLIK))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gdPrace))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgOceny))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgGrupy))->BeginInit();
			this->SuspendLayout();
			// 
			// lblAdmin
			// 
			this->lblAdmin->AutoSize = true;
			this->lblAdmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAdmin->Location = System::Drawing::Point(62, 7);
			this->lblAdmin->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblAdmin->Name = L"lblAdmin";
			this->lblAdmin->Size = System::Drawing::Size(0, 25);
			this->lblAdmin->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(9, 7);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Witaj";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CalendarFont = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->dateTimePicker1->CalendarForeColor = System::Drawing::Color::Black;
			this->dateTimePicker1->CustomFormat = L"MM/dd/yyyy";
			this->dateTimePicker1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->Location = System::Drawing::Point(692, 6);
			this->dateTimePicker1->Margin = System::Windows::Forms::Padding(2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(114, 23);
			this->dateTimePicker1->TabIndex = 7;
			this->dateTimePicker1->Value = System::DateTime(2019, 5, 2, 12, 16, 0, 0);
			// 
			// btnWYLOGUJ
			// 
			this->btnWYLOGUJ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWYLOGUJ->Location = System::Drawing::Point(582, 4);
			this->btnWYLOGUJ->Margin = System::Windows::Forms::Padding(2);
			this->btnWYLOGUJ->Name = L"btnWYLOGUJ";
			this->btnWYLOGUJ->Size = System::Drawing::Size(106, 25);
			this->btnWYLOGUJ->TabIndex = 12;
			this->btnWYLOGUJ->Text = L"Wyloguj";
			this->btnWYLOGUJ->UseVisualStyleBackColor = true;
			this->btnWYLOGUJ->Click += gcnew System::EventHandler(this, &Student_Form::btnWYLOGUJ_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->Przeslij);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(13, 34);
			this->tabControl1->Margin = System::Windows::Forms::Padding(2);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(796, 566);
			this->tabControl1->TabIndex = 13;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage1->Controls->Add(this->button8);
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->richTextBox1);
			this->tabPage1->Controls->Add(this->button7);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->dgMain);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Margin = System::Windows::Forms::Padding(2);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(2);
			this->tabPage1->Size = System::Drawing::Size(788, 540);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Ekran Glowny";
			this->tabPage1->Click += gcnew System::EventHandler(this, &Student_Form::tabPage1_Click_1);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(367, 312);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(195, 24);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Treœc wybranej pracy:";
			this->label6->Visible = false;
			this->label6->Click += gcnew System::EventHandler(this, &Student_Form::label6_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(235, 352);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(528, 146);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			this->richTextBox1->Visible = false;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button7->Location = System::Drawing::Point(26, 425);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(172, 73);
			this->button7->TabIndex = 7;
			this->button7->Text = L"Pokaz wyslane prace";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Student_Form::button7_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(249, 12);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(313, 55);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Ekran glowny";
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button3->Location = System::Drawing::Point(26, 347);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(172, 73);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Pokaz prace";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Student_Form::button3_Click);
			// 
			// dgMain
			// 
			this->dgMain->AllowUserToAddRows = false;
			this->dgMain->AllowUserToDeleteRows = false;
			this->dgMain->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgMain->Location = System::Drawing::Point(6, 88);
			this->dgMain->Name = L"dgMain";
			this->dgMain->ReadOnly = true;
			this->dgMain->Size = System::Drawing::Size(776, 211);
			this->dgMain->TabIndex = 0;
			this->dgMain->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Student_Form::dgMain_CellContentClick);
			// 
			// Przeslij
			// 
			this->Przeslij->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Przeslij->Controls->Add(this->dgAKTUALNYPLIK);
			this->Przeslij->Controls->Add(this->label4);
			this->Przeslij->Controls->Add(this->button4);
			this->Przeslij->Controls->Add(this->button2);
			this->Przeslij->Controls->Add(this->button1);
			this->Przeslij->Controls->Add(this->gdPrace);
			this->Przeslij->Location = System::Drawing::Point(4, 22);
			this->Przeslij->Margin = System::Windows::Forms::Padding(2);
			this->Przeslij->Name = L"Przeslij";
			this->Przeslij->Padding = System::Windows::Forms::Padding(2);
			this->Przeslij->Size = System::Drawing::Size(788, 540);
			this->Przeslij->TabIndex = 1;
			this->Przeslij->Text = L"Przeslij Prace Domowa";
			// 
			// dgAKTUALNYPLIK
			// 
			this->dgAKTUALNYPLIK->AllowUserToAddRows = false;
			this->dgAKTUALNYPLIK->AllowUserToDeleteRows = false;
			this->dgAKTUALNYPLIK->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgAKTUALNYPLIK->Location = System::Drawing::Point(4, 291);
			this->dgAKTUALNYPLIK->Margin = System::Windows::Forms::Padding(2);
			this->dgAKTUALNYPLIK->Name = L"dgAKTUALNYPLIK";
			this->dgAKTUALNYPLIK->ReadOnly = true;
			this->dgAKTUALNYPLIK->RowTemplate->Height = 24;
			this->dgAKTUALNYPLIK->Size = System::Drawing::Size(781, 108);
			this->dgAKTUALNYPLIK->TabIndex = 6;
			this->dgAKTUALNYPLIK->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Student_Form::dgAKTUALNYPLIK_CellContentClick);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(182, 11);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(507, 55);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Przeœlij prace domowa";
			this->label4->Click += gcnew System::EventHandler(this, &Student_Form::label4_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button4->Location = System::Drawing::Point(28, 440);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(148, 59);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Pokaz prace";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Student_Form::button4_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button2->Location = System::Drawing::Point(489, 432);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(285, 73);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Wyœlij";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Student_Form::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button1->Location = System::Drawing::Point(191, 432);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(285, 73);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Przeœlij plik";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Student_Form::button1_Click);
			// 
			// gdPrace
			// 
			this->gdPrace->AllowUserToAddRows = false;
			this->gdPrace->AllowUserToDeleteRows = false;
			this->gdPrace->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gdPrace->Location = System::Drawing::Point(4, 83);
			this->gdPrace->Margin = System::Windows::Forms::Padding(2);
			this->gdPrace->Name = L"gdPrace";
			this->gdPrace->ReadOnly = true;
			this->gdPrace->RowTemplate->Height = 24;
			this->gdPrace->Size = System::Drawing::Size(781, 184);
			this->gdPrace->TabIndex = 0;
			this->gdPrace->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Student_Form::gdPrace_CellClick);
			this->gdPrace->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Student_Form::gdPrace_CellContentClick);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Controls->Add(this->dgOceny);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Size = System::Drawing::Size(788, 540);
			this->tabPage2->TabIndex = 2;
			this->tabPage2->Text = L"Oceny";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(272, 15);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(270, 55);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Moje oceny";
			this->label3->Click += gcnew System::EventHandler(this, &Student_Form::label3_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button5->Location = System::Drawing::Point(281, 488);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(201, 49);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Wyœwietl oceny";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Student_Form::button5_Click);
			// 
			// dgOceny
			// 
			this->dgOceny->AllowUserToAddRows = false;
			this->dgOceny->AllowUserToDeleteRows = false;
			this->dgOceny->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgOceny->Location = System::Drawing::Point(3, 92);
			this->dgOceny->Name = L"dgOceny";
			this->dgOceny->ReadOnly = true;
			this->dgOceny->Size = System::Drawing::Size(784, 390);
			this->dgOceny->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage3->Controls->Add(this->label2);
			this->tabPage3->Controls->Add(this->button6);
			this->tabPage3->Controls->Add(this->dgGrupy);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Margin = System::Windows::Forms::Padding(2);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(788, 540);
			this->tabPage3->TabIndex = 3;
			this->tabPage3->Text = L"Moje Grupy";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(261, 12);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(262, 55);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Moje grupy";
			this->label2->Click += gcnew System::EventHandler(this, &Student_Form::label2_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->button6->Location = System::Drawing::Point(270, 464);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(202, 64);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Pokaz grupy";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Student_Form::button6_Click_1);
			// 
			// dgGrupy
			// 
			this->dgGrupy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgGrupy->Location = System::Drawing::Point(2, 84);
			this->dgGrupy->Margin = System::Windows::Forms::Padding(2);
			this->dgGrupy->Name = L"dgGrupy";
			this->dgGrupy->RowTemplate->Height = 24;
			this->dgGrupy->Size = System::Drawing::Size(784, 366);
			this->dgGrupy->TabIndex = 0;
			// 
			// button8
			// 
			this->button8->Enabled = false;
			this->button8->Location = System::Drawing::Point(596, 315);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(167, 23);
			this->button8->TabIndex = 10;
			this->button8->Text = L"Zatwierdz wybrana prace";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Visible = false;
			this->button8->Click += gcnew System::EventHandler(this, &Student_Form::button8_Click);
			// 
			// Student_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(811, 604);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnWYLOGUJ);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->lblAdmin);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Student_Form";
			this->Text = L"Student";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Student_Form::Student_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Student_Form::Student_Form_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMain))->EndInit();
			this->Przeslij->ResumeLayout(false);
			this->Przeslij->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgAKTUALNYPLIK))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gdPrace))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgOceny))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgGrupy))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		

	private: System::Void Student_Form_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->lblAdmin->Text = this->Admin_Name;
	}

	private: System::Void btnWYLOGUJ_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (MessageBox::Show("Czy na pewno chcesz sie wylogowac?", "Uwaga!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			this->Hide();
			this->Close();
			Logowanie_Form->Visible = true;
		}
	}

			 	private: void pokaz_uzytkownikow(System::Windows::Forms::DataGridView^ siatka)
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM uzytkownicy ORDER BY iduzytkownicy;", laczbaze);

		try {

			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;

			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			siatka->DataSource = zrodlo;

			laczbaze->Close();
		}
		catch (Exception^ komunikat)
		{
			MessageBox::Show(komunikat->Message);
		}
		siatka->Columns[0]->Visible = false;
	}

		//
		// OWN FUNCTIONS
		//		

		//own variables
		System::String^ file_path = " ";
		System::String^ from_file = " ";
		int id_aktualnego_rekordu_pd = -1;


		private: void Pokaz_plik(System::Windows::Forms::DataGridView^ siatka,System::String^ file_path, System::String^ from_file)
		{
			try {
				siatka->Columns->Clear();
				siatka->ClearSelection();
				siatka->Columns->Add("col1", "Sciezka pliku");
				siatka->Columns->Add("col2", "Zawartosc pliku");

				DataTable^ table = gcnew DataTable("MyTable");
				table->Columns->Add("Sciezka pliku");
				table->Columns->Add("Zawartosc pliku");

				siatka->Rows->Add();
				siatka->Columns[0]->Width = (file_path->Length * 5);
				siatka->Columns[1]->Width = 600;
				siatka[0, 0]->Value = file_path;
				siatka[1, 0]->Value = from_file;
				/*siatka->Columns[0] = table->Rows[0]->;
				siatka->Rows->Add();*/
			
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}
			//siatka->Columns[0]->Visible = false;
		}

		private: void pokaz_przeslane(System::Windows::Forms::DataGridView^ siatka)
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM `uzytkownicy`;", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT `pliki`.`plik`, `praca_domowa`.`title` as 'Nazwa', `praca_domowa`.`expire_date` as 'Data oddania', `pliki`.`zatwierdzona` as 'Zatwierdzona' FROM `praca_domowa`, `pliki` where `praca_domowa`.`pk` = `pliki`.`id_pd` and `pliki`.`id_osoby` = " + _id + ";", laczbaze);


			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				//	siatka->RowHeadersWidthSizeMode 
				siatka->DataSource = zrodlo;
				//siatka->Columns[2]->G = false;
				laczbaze->Close();
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}

			siatka->Columns[0]->Visible = false;

		}



		private: void pokaz_prace(System::Windows::Forms::DataGridView^ siatka)
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM `uzytkownicy`;", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT distinct `praca_domowa`.`pk` as `Numer grupy`, `praca_domowa`.`title` as `Nazwa pracy`, `praca_domowa`.`contents` as `Treœc`, `praca_domowa`.`expire_date` as `Data oddania` FROM `uzytkownicy`, `grupy_uzytkownikow`, `praca_domowa` where `uzytkownicy`.`iduzytkownicy` =`grupy_uzytkownikow`.`iduzytkownika` and `praca_domowa`.`id_grupy` = `grupy_uzytkownikow`.`idgrupy`;", laczbaze);

			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				//	siatka->RowHeadersWidthSizeMode 
				siatka->DataSource = zrodlo;
				//siatka->Columns[2]->G = false;
				laczbaze->Close();
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}
			siatka->Columns[0]->Visible = false;
		}

		private: void pokaz_oceny(System::Windows::Forms::DataGridView^ siatka)
		{
			std::string id = std::to_string(_id);
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM `uzytkownicy`;", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT distinct `praca_domowa`.`pk`, `praca_domowa`.`title` as `Nazwa pracy`, `praca_domowa`.`contents` as `Treœc`, `Ocena`.`ocena` FROM `Ocena`, `uzytkownicy`, `praca_domowa` where `praca_domowa`.`pk`  = `Ocena`.`id_pd` and `Ocena`.`id_osoby` = `uzytkownicy`.`iduzytkownicy` and `Ocena`.`id_osoby` = "+_id+";", laczbaze);

			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				//	siatka->RowHeadersWidthSizeMode 
				siatka->DataSource = zrodlo;
				//siatka->Columns[2]->G = false;
				laczbaze->Close();
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}
			siatka->Columns[0]->Visible = false;
		}

		private: void pokaz_grupy(System::Windows::Forms::DataGridView^ siatka)
		{
			std::string id = std::to_string(_id);
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM `uzytkownicy`;", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT distinct `idgrupy` as `ID Grupy` from `grupy_uzytkownikow` where `iduzytkownika` ='"+_id+"';", laczbaze);

			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				//	siatka->RowHeadersWidthSizeMode 
				siatka->DataSource = zrodlo;
				//siatka->Columns[2]->G = false;
				laczbaze->Close();
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}
			//siatka->Columns[0]->Visible = false;
		}


		private: void przeslij_prace()
		{

			if (/*zaznaczono prace domowa i przeslano plik*/true) {

				//MySqlCommand^ zapytanie = gcnew MySqlCommand("insert into `pliki` values `NULL` `" + _id + "` `123` `" + "` `aaaa` `" + _fromFile, laczbaze);
				//MySqlCommand^ zapytanie = gcnew MySqlCommand("insert into `pliki` values NULL" + _id + /*idpd, nazwa*/ _fromFile, laczbaze);

				// sprawdz czy mozna

				MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
				MySqlCommand^ polecenie = laczbaze->CreateCommand();
				MySqlTransaction^ transakcja;

				laczbaze->Open();
				transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

				polecenie->Connection = laczbaze;
				polecenie->Transaction = transakcja;


				try {

					// wstaw do bazy danych

					if (button2->Text == "Wyœlij") {
						polecenie->CommandText = "insert into `pliki` values ( NULL, " + _id + "," + _idpd + ", " + " \"" + _nazwapd + "\", \"" + _fromFile + "\")";
					}
					else {
						polecenie->CommandText = "update `pliki` set `plik` = \"" + _fromFile + "\" where id_osoby = '" + _id + "' and id_pd = '" + _idpd + "';";
					}

					polecenie->ExecuteNonQuery();
					transakcja->Commit();



					laczbaze->Close();
				
				
					MessageBox::Show("Wyslano prace.");

				}
				catch (Exception^ komunikat)
				{
					MessageBox::Show(komunikat->Message);
				}
			}
		}

		private: void update_przycisk() {
			
			std::string id = std::to_string(_id);
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * from `pliki` where `id_osoby` = '" + _id + "' and `id_pd` = '" + _idpd + "';", laczbaze);

			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);
				//MessageBox::Show("zjebales kurwa");
				//MessageBox::Show(Convert::ToString(tabela->Rows->Count));


				if (tabela->Rows->Count != 0) {
					// update
					button2->Text = "Zamien";
				}
				else {
					button2->Text = "Wyœlij";
				}

				laczbaze->Close();
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}
			//siatka->Columns[0]->Visible = false;


		}




private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void gdPrace_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	_idpd = Convert::ToString(gdPrace->Rows[e->RowIndex]->Cells[0]->Value);
	_nazwapd = Convert::ToString(gdPrace->Rows[e->RowIndex]->Cells[1]->Value);

	MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
	MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * from `pliki` where `zatwierdzona` = 1 and `id_osoby` = '" + _id + "' and `id_pd` = '" + _idpd + "';", laczbaze);

	try {

		MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
		moja->SelectCommand = zapytanie;

		DataTable^ tabela = gcnew DataTable();
		moja->Fill(tabela);

		MessageBox::Show(Convert::ToString(tabela->Rows->Count));

		

		if (tabela->Rows->Count != 0) {
			button2->Enabled = false;
		}
		else {
			button2->Enabled = true;
		}

		laczbaze->Close();
	}
	catch (Exception^ komunikat)
	{
		MessageBox::Show(komunikat->Message);
	}
	//siatka->Columns[0]->Visible = false;



	update_przycisk();

}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Stream^ mystream;
	OpenFileDialog^ openfile = gcnew OpenFileDialog;

	if (openfile->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		if ((mystream = openfile->OpenFile()) != nullptr)
		{
			file_path = openfile->InitialDirectory + openfile->FileName;

			//MessageBox::Show(file_path);

				mystream->Close();

			_FTP my_file_reader(file_path);
			from_file = my_file_reader.get_from_file();
			Pokaz_plik(dgAKTUALNYPLIK,file_path,from_file);
			//this->richtest->Text = my_file_reader.get_from_file();

			_fromFile = from_file;
			_filePath = file_path;
		}
	}


}



	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		przeslij_prace();
		update_przycisk();

	}


private: System::Void tabPage1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	pokaz_prace(gdPrace);
	//gdPrace->Columns[6]->Visible = false;

}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	pokaz_oceny(dgOceny);
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	pokaz_prace(dgMain);
	jk = false;
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button6_Click_1(System::Object^  sender, System::EventArgs^  e) {
	pokaz_grupy(dgGrupy);

}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
}


	private: System::Void gdPrace_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{

		id_aktualnego_rekordu_pd = Convert::ToInt32(gdPrace->Rows[e->RowIndex]->Cells[0]->Value);
	}
private: System::Void dgAKTUALNYPLIK_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
}
private: System::Void Student_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
{
	Logowanie_Form->Visible = true;
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	pokaz_przeslane(dgMain);
	jk = true;
}
private: System::Void dgMain_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {


	if (jk) {
		label6->Visible = true;
		richTextBox1->Visible = true;
		button8->Visible = true;

		//String^ fileStr;
		_fileStr = Convert::ToString(dgMain->Rows[e->RowIndex]->Cells[0]->Value);

		richTextBox1->Text = _fileStr;

		button8->Enabled = !Convert::ToBoolean(dgMain->Rows[e->RowIndex]->Cells[3]->Value);


	}
	else {
		label6->Visible = false;
		richTextBox1->Visible = false;
		button8->Visible = false;
	}


	
	//_idpd = Convert::ToString(gdPrace->Rows[e->RowIndex]->Cells[0]->Value);
	//_nazwapd = Convert::ToString(gdPrace->Rows[e->RowIndex]->Cells[1]->Value);

}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {

	// zaktualizuj zatwierdzonoœc
	MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
	MySqlCommand^ polecenie = laczbaze->CreateCommand();
	MySqlTransaction^ transakcja;

	laczbaze->Open();
	transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

	polecenie->Connection = laczbaze;
	polecenie->Transaction = transakcja;


	try {

		polecenie->CommandText = "update `pliki` set `zatwierdzona` = True where `id_osoby` = '" + _id + "' and `plik` = '" + _fileStr + "';";
		
		button8->Enabled = false;

		polecenie->ExecuteNonQuery();
		transakcja->Commit();

		laczbaze->Close();


		MessageBox::Show("Zatwierdzono prace.");

	}
	catch (Exception^ komunikat)
	{
		MessageBox::Show(komunikat->Message);
	}
}
};
}
