#pragma once
//#include "Logowanie.h"
//#include "../BLIND_BANK/Logowanie.cpp"
#include "Configure_String.hpp"

namespace BLINDBANK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Admin_Form
	/// </summary>
	public ref class Admin_Form : public System::Windows::Forms::Form
	{
	public:
		Admin_Form(void):
			role(-1)	//default is -1 cause the ID begins from 0 or 1
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		//currently constructor contains integer type, finally change it to string for example, String^ role
		Admin_Form(const int role):
			role(role)
		{
			InitializeComponent();

		}

		Admin_Form(const int role, String^ & Admin_Name, System::Windows::Forms::Form ^ _Form) :
			role(role),
			Admin_Name(Admin_Name),
			Logowanie_Form(_Form)
		{
			InitializeComponent();

		}

	/*	Admin_Form(System::Windows::Forms::Form ^ frm1)
		{
			Logowanie_Form = frm1;
			InitializeComponent();
		}*/

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Admin_Form()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/*
			PRIVATE VARIABLES
		*/
		//Here add mysql reader
		String^ konfiguracja = SQL_CONFIGURATION::get_konfiguracja();
		//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";
		int role;
		String^ Admin_Name;
		System::Windows::Forms::Form ^ Logowanie_Form;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblAdmin;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  btnPokazUzytkownikow;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  btnWYLOGUJ;
	private: System::Windows::Forms::TabPage^  tabPage3;

	private: System::Windows::Forms::TabPage^  tabPage5;
	private: System::Windows::Forms::Label^  label2;

























	private: System::Windows::Forms::DataGridView^  dgUzytkownicy;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::DataGridView^  dgMODYFIKACJAUZYTKOWNIKA;
	private: System::Windows::Forms::TextBox^  txtIMIEMOD;

	private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::TextBox^  txtHASLOMOD;



private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::TextBox^  txtEMAILMOD;

private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::TextBox^  txtNUMERINDEXUMOD;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::TextBox^  txtNAZWISKOMOD;

private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::CheckBox^  checkboxWYKLADOWCAMOD;
private: System::Windows::Forms::CheckBox^  checkboxSTUDENTMOD;


private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Button^  btnMODYFIKUJ;

private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::DataGridView^  dgUSUNUZYTKOWNIKA;

private: System::Windows::Forms::Button^  btnPOKAZUZYTKOWNIKAUSUN;
private: System::Windows::Forms::Button^  txtUSUNUZYTKOWNIKA;
private: System::Windows::Forms::TabPage^  tabPage4;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::Button^  btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK;

private: System::Windows::Forms::TextBox^  txtIMIE;
private: System::Windows::Forms::Button^  btnDODAJUZYTKOWNIKA;


private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::CheckBox^  checkboxWYKLADOWCA;

private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::CheckBox^  checkboxSTUDENT;
private: System::Windows::Forms::TextBox^  txtNAZWISKO;


private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::TextBox^  txtHASLO;

private: System::Windows::Forms::TextBox^  txtNUMERINDEXU;

private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::TextBox^  txtEMAIL;
private: System::Windows::Forms::DataGridView^  dgNOWYUZYTKOWNIK;
private: System::Windows::Forms::DataGridView^  dgGRUPYDODANI;


private: System::Windows::Forms::DataGridView^  dgUZYTKOWNICYGRUPY;




private: System::Windows::Forms::Button^  btnPOKAZUZYTKOWNIKOWGRUPY;

private: System::Windows::Forms::DataGridView^  dgGRUPY;
private: System::Windows::Forms::GroupBox^  groupBox3;
private: System::Windows::Forms::Button^  btnDODAJDOGRUPY;
private: System::Windows::Forms::Button^  btnPOKAZGRUPY;
private: System::Windows::Forms::CheckBox^  chekcboxWYKLADOWCAGRUPA;
private: System::Windows::Forms::CheckBox^  checkboxSTUDENTGRUPA;
private: System::Windows::Forms::TabPage^  tabPage6;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::DataGridView^  dgZARZADZENIEGRUPA;

private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::Button^  btnPOKAZGRUPYZARZADZAJ;
private: System::Windows::Forms::Button^  btnUSUNGRUPE;




private: System::Windows::Forms::Button^  btnDODAJGRUPE;

private: System::Windows::Forms::TextBox^  txtNAZWAGRUPYZARZADZANIE;

private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::TextBox^  txtINFORMACJEZARZADZANIE;
private: System::Windows::Forms::Button^  btnMODYFIKUJGRUPE;
private: System::Windows::Forms::Button^  btnPOKAZGRUPYUZYTKOWNIKA;










































			 ///////////////////////////////////////////////////
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblAdmin = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->btnPOKAZGRUPYUZYTKOWNIKA = (gcnew System::Windows::Forms::Button());
			this->dgUzytkownicy = (gcnew System::Windows::Forms::DataGridView());
			this->btnPokazUzytkownikow = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK = (gcnew System::Windows::Forms::Button());
			this->txtIMIE = (gcnew System::Windows::Forms::TextBox());
			this->btnDODAJUZYTKOWNIKA = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkboxWYKLADOWCA = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->checkboxSTUDENT = (gcnew System::Windows::Forms::CheckBox());
			this->txtNAZWISKO = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtHASLO = (gcnew System::Windows::Forms::TextBox());
			this->txtNUMERINDEXU = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtEMAIL = (gcnew System::Windows::Forms::TextBox());
			this->dgNOWYUZYTKOWNIK = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->txtIMIEMOD = (gcnew System::Windows::Forms::TextBox());
			this->btnMODYFIKUJ = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->checkboxWYKLADOWCAMOD = (gcnew System::Windows::Forms::CheckBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->checkboxSTUDENTMOD = (gcnew System::Windows::Forms::CheckBox());
			this->txtNAZWISKOMOD = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->txtHASLOMOD = (gcnew System::Windows::Forms::TextBox());
			this->txtNUMERINDEXUMOD = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->txtEMAILMOD = (gcnew System::Windows::Forms::TextBox());
			this->dgMODYFIKACJAUZYTKOWNIKA = (gcnew System::Windows::Forms::DataGridView());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tabPage5 = (gcnew System::Windows::Forms::TabPage());
			this->txtUSUNUZYTKOWNIKA = (gcnew System::Windows::Forms::Button());
			this->btnPOKAZUZYTKOWNIKAUSUN = (gcnew System::Windows::Forms::Button());
			this->dgUSUNUZYTKOWNIKA = (gcnew System::Windows::Forms::DataGridView());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->chekcboxWYKLADOWCAGRUPA = (gcnew System::Windows::Forms::CheckBox());
			this->checkboxSTUDENTGRUPA = (gcnew System::Windows::Forms::CheckBox());
			this->btnDODAJDOGRUPY = (gcnew System::Windows::Forms::Button());
			this->btnPOKAZUZYTKOWNIKOWGRUPY = (gcnew System::Windows::Forms::Button());
			this->btnPOKAZGRUPY = (gcnew System::Windows::Forms::Button());
			this->dgGRUPYDODANI = (gcnew System::Windows::Forms::DataGridView());
			this->dgUZYTKOWNICYGRUPY = (gcnew System::Windows::Forms::DataGridView());
			this->dgGRUPY = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage6 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->txtNAZWAGRUPYZARZADZANIE = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->txtINFORMACJEZARZADZANIE = (gcnew System::Windows::Forms::TextBox());
			this->btnUSUNGRUPE = (gcnew System::Windows::Forms::Button());
			this->btnDODAJGRUPE = (gcnew System::Windows::Forms::Button());
			this->btnPOKAZGRUPYZARZADZAJ = (gcnew System::Windows::Forms::Button());
			this->btnMODYFIKUJGRUPE = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->dgZARZADZENIEGRUPA = (gcnew System::Windows::Forms::DataGridView());
			this->btnWYLOGUJ = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUzytkownicy))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgNOWYUZYTKOWNIK))->BeginInit();
			this->tabPage3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMODYFIKACJAUZYTKOWNIKA))->BeginInit();
			this->tabPage5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUSUNUZYTKOWNIKA))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgGRUPYDODANI))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUZYTKOWNICYGRUPY))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgGRUPY))->BeginInit();
			this->tabPage6->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgZARZADZENIEGRUPA))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Witaj";
			// 
			// lblAdmin
			// 
			this->lblAdmin->AutoSize = true;
			this->lblAdmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAdmin->Location = System::Drawing::Point(82, 5);
			this->lblAdmin->Name = L"lblAdmin";
			this->lblAdmin->Size = System::Drawing::Size(0, 29);
			this->lblAdmin->TabIndex = 2;
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
			this->dateTimePicker1->ImeMode = System::Windows::Forms::ImeMode::On;
			this->dateTimePicker1->Location = System::Drawing::Point(919, 6);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(151, 26);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->Value = System::DateTime(2019, 5, 2, 12, 16, 0, 0);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage5);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage6);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl1->Location = System::Drawing::Point(12, 41);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1058, 707);
			this->tabControl1->TabIndex = 9;
			this->tabControl1->Click += gcnew System::EventHandler(this, &Admin_Form::tabControl1_Click);
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage1->Controls->Add(this->btnPOKAZGRUPYUZYTKOWNIKA);
			this->tabPage1->Controls->Add(this->dgUzytkownicy);
			this->tabPage1->Controls->Add(this->btnPokazUzytkownikow);
			this->tabPage1->Location = System::Drawing::Point(4, 29);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1050, 674);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Pokaz Uzytkownikow";
			// 
			// btnPOKAZGRUPYUZYTKOWNIKA
			// 
			this->btnPOKAZGRUPYUZYTKOWNIKA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPOKAZGRUPYUZYTKOWNIKA->Location = System::Drawing::Point(317, 586);
			this->btnPOKAZGRUPYUZYTKOWNIKA->Name = L"btnPOKAZGRUPYUZYTKOWNIKA";
			this->btnPOKAZGRUPYUZYTKOWNIKA->Size = System::Drawing::Size(368, 67);
			this->btnPOKAZGRUPYUZYTKOWNIKA->TabIndex = 12;
			this->btnPOKAZGRUPYUZYTKOWNIKA->Text = L"Pokaz Grupy Uzytkownika";
			this->btnPOKAZGRUPYUZYTKOWNIKA->UseVisualStyleBackColor = true;
			this->btnPOKAZGRUPYUZYTKOWNIKA->Click += gcnew System::EventHandler(this, &Admin_Form::btnPOKAZGRUPYUZYTKOWNIKA_Click);
			// 
			// dgUzytkownicy
			// 
			this->dgUzytkownicy->AllowUserToAddRows = false;
			this->dgUzytkownicy->AllowUserToDeleteRows = false;
			this->dgUzytkownicy->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgUzytkownicy->Location = System::Drawing::Point(6, 8);
			this->dgUzytkownicy->Name = L"dgUzytkownicy";
			this->dgUzytkownicy->ReadOnly = true;
			this->dgUzytkownicy->RowTemplate->Height = 24;
			this->dgUzytkownicy->Size = System::Drawing::Size(1004, 550);
			this->dgUzytkownicy->TabIndex = 11;
			this->dgUzytkownicy->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Admin_Form::dgUzytkownicy_CellClick);
			// 
			// btnPokazUzytkownikow
			// 
			this->btnPokazUzytkownikow->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPokazUzytkownikow->Location = System::Drawing::Point(6, 586);
			this->btnPokazUzytkownikow->Name = L"btnPokazUzytkownikow";
			this->btnPokazUzytkownikow->Size = System::Drawing::Size(305, 67);
			this->btnPokazUzytkownikow->TabIndex = 10;
			this->btnPokazUzytkownikow->Text = L"Pokaz Uzytkownikow";
			this->btnPokazUzytkownikow->UseVisualStyleBackColor = true;
			this->btnPokazUzytkownikow->Click += gcnew System::EventHandler(this, &Admin_Form::btnPokazUzytkownikow_Click_1);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->dgNOWYUZYTKOWNIK);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 29);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1050, 674);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Dodaj Uzytkownika";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->groupBox2->Controls->Add(this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK);
			this->groupBox2->Controls->Add(this->txtIMIE);
			this->groupBox2->Controls->Add(this->btnDODAJUZYTKOWNIKA);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->checkboxWYKLADOWCA);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->checkboxSTUDENT);
			this->groupBox2->Controls->Add(this->txtNAZWISKO);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->txtHASLO);
			this->groupBox2->Controls->Add(this->txtNUMERINDEXU);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label8);
			this->groupBox2->Controls->Add(this->txtEMAIL);
			this->groupBox2->Location = System::Drawing::Point(32, 390);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(990, 260);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Modyfikacja";
			// 
			// btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK
			// 
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->Location = System::Drawing::Point(372, 188);
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->Name = L"btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK";
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->Size = System::Drawing::Size(282, 56);
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->TabIndex = 19;
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->Text = L"Pokaz Uzytkownikow";
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->UseVisualStyleBackColor = true;
			this->btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK->Click += gcnew System::EventHandler(this, &Admin_Form::btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK_Click);
			// 
			// txtIMIE
			// 
			this->txtIMIE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIMIE->Location = System::Drawing::Point(212, 27);
			this->txtIMIE->Name = L"txtIMIE";
			this->txtIMIE->Size = System::Drawing::Size(230, 30);
			this->txtIMIE->TabIndex = 4;
			// 
			// btnDODAJUZYTKOWNIKA
			// 
			this->btnDODAJUZYTKOWNIKA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnDODAJUZYTKOWNIKA->Location = System::Drawing::Point(660, 188);
			this->btnDODAJUZYTKOWNIKA->Name = L"btnDODAJUZYTKOWNIKA";
			this->btnDODAJUZYTKOWNIKA->Size = System::Drawing::Size(312, 56);
			this->btnDODAJUZYTKOWNIKA->TabIndex = 18;
			this->btnDODAJUZYTKOWNIKA->Text = L"Dodaj Uzytkownika";
			this->btnDODAJUZYTKOWNIKA->UseVisualStyleBackColor = true;
			this->btnDODAJUZYTKOWNIKA->Click += gcnew System::EventHandler(this, &Admin_Form::btnDODAJUZYTKOWNIKA_Click_1);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(36, 31);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 26);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Imie:";
			// 
			// checkboxWYKLADOWCA
			// 
			this->checkboxWYKLADOWCA->AutoSize = true;
			this->checkboxWYKLADOWCA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkboxWYKLADOWCA->Location = System::Drawing::Point(660, 104);
			this->checkboxWYKLADOWCA->Name = L"checkboxWYKLADOWCA";
			this->checkboxWYKLADOWCA->Size = System::Drawing::Size(157, 30);
			this->checkboxWYKLADOWCA->TabIndex = 17;
			this->checkboxWYKLADOWCA->Text = L"Wykladowca";
			this->checkboxWYKLADOWCA->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(36, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(112, 26);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Nazwisko:";
			// 
			// checkboxSTUDENT
			// 
			this->checkboxSTUDENT->AutoSize = true;
			this->checkboxSTUDENT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkboxSTUDENT->Location = System::Drawing::Point(660, 137);
			this->checkboxSTUDENT->Name = L"checkboxSTUDENT";
			this->checkboxSTUDENT->Size = System::Drawing::Size(109, 30);
			this->checkboxSTUDENT->TabIndex = 16;
			this->checkboxSTUDENT->Text = L"Student";
			this->checkboxSTUDENT->UseVisualStyleBackColor = true;
			// 
			// txtNAZWISKO
			// 
			this->txtNAZWISKO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNAZWISKO->Location = System::Drawing::Point(212, 69);
			this->txtNAZWISKO->Name = L"txtNAZWISKO";
			this->txtNAZWISKO->Size = System::Drawing::Size(230, 30);
			this->txtNAZWISKO->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(496, 120);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 26);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Rola:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(36, 120);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(155, 26);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Numer Indexu:";
			// 
			// txtHASLO
			// 
			this->txtHASLO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtHASLO->Location = System::Drawing::Point(660, 65);
			this->txtHASLO->Name = L"txtHASLO";
			this->txtHASLO->Size = System::Drawing::Size(230, 30);
			this->txtHASLO->TabIndex = 12;
			// 
			// txtNUMERINDEXU
			// 
			this->txtNUMERINDEXU->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNUMERINDEXU->Location = System::Drawing::Point(212, 117);
			this->txtNUMERINDEXU->MaxLength = 6;
			this->txtNUMERINDEXU->Name = L"txtNUMERINDEXU";
			this->txtNUMERINDEXU->Size = System::Drawing::Size(230, 30);
			this->txtNUMERINDEXU->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(496, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(74, 26);
			this->label7->TabIndex = 11;
			this->label7->Text = L"Haslo:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(496, 26);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(144, 26);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Adres E-mail:";
			// 
			// txtEMAIL
			// 
			this->txtEMAIL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEMAIL->Location = System::Drawing::Point(660, 23);
			this->txtEMAIL->Name = L"txtEMAIL";
			this->txtEMAIL->Size = System::Drawing::Size(230, 30);
			this->txtEMAIL->TabIndex = 10;
			// 
			// dgNOWYUZYTKOWNIK
			// 
			this->dgNOWYUZYTKOWNIK->AllowUserToAddRows = false;
			this->dgNOWYUZYTKOWNIK->AllowUserToDeleteRows = false;
			this->dgNOWYUZYTKOWNIK->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgNOWYUZYTKOWNIK->Location = System::Drawing::Point(30, 60);
			this->dgNOWYUZYTKOWNIK->Name = L"dgNOWYUZYTKOWNIK";
			this->dgNOWYUZYTKOWNIK->ReadOnly = true;
			this->dgNOWYUZYTKOWNIK->RowTemplate->Height = 24;
			this->dgNOWYUZYTKOWNIK->Size = System::Drawing::Size(990, 310);
			this->dgNOWYUZYTKOWNIK->TabIndex = 20;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(400, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(285, 39);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Nowy Uzytkownik";
			// 
			// tabPage3
			// 
			this->tabPage3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage3->Controls->Add(this->groupBox1);
			this->tabPage3->Controls->Add(this->dgMODYFIKACJAUZYTKOWNIKA);
			this->tabPage3->Controls->Add(this->label9);
			this->tabPage3->Location = System::Drawing::Point(4, 29);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1050, 674);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Modyfikuj Uzytkownika";
			// 
			// groupBox1
			// 
			this->groupBox1->BackColor = System::Drawing::SystemColors::HighlightText;
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Controls->Add(this->txtIMIEMOD);
			this->groupBox1->Controls->Add(this->btnMODYFIKUJ);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->checkboxWYKLADOWCAMOD);
			this->groupBox1->Controls->Add(this->label12);
			this->groupBox1->Controls->Add(this->checkboxSTUDENTMOD);
			this->groupBox1->Controls->Add(this->txtNAZWISKOMOD);
			this->groupBox1->Controls->Add(this->label16);
			this->groupBox1->Controls->Add(this->label13);
			this->groupBox1->Controls->Add(this->txtHASLOMOD);
			this->groupBox1->Controls->Add(this->txtNUMERINDEXUMOD);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->label14);
			this->groupBox1->Controls->Add(this->txtEMAILMOD);
			this->groupBox1->Location = System::Drawing::Point(32, 390);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(990, 260);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Modyfikacja";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(489, 188);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(282, 56);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Pokaz Uzytkownikow";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Admin_Form::button2_Click);
			// 
			// txtIMIEMOD
			// 
			this->txtIMIEMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIMIEMOD->Location = System::Drawing::Point(212, 27);
			this->txtIMIEMOD->Name = L"txtIMIEMOD";
			this->txtIMIEMOD->Size = System::Drawing::Size(230, 30);
			this->txtIMIEMOD->TabIndex = 4;
			// 
			// btnMODYFIKUJ
			// 
			this->btnMODYFIKUJ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMODYFIKUJ->Location = System::Drawing::Point(777, 188);
			this->btnMODYFIKUJ->Name = L"btnMODYFIKUJ";
			this->btnMODYFIKUJ->Size = System::Drawing::Size(195, 56);
			this->btnMODYFIKUJ->TabIndex = 18;
			this->btnMODYFIKUJ->Text = L"Modyfikuj";
			this->btnMODYFIKUJ->UseVisualStyleBackColor = true;
			this->btnMODYFIKUJ->Click += gcnew System::EventHandler(this, &Admin_Form::btnMODYFIKUJ_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(36, 31);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(60, 26);
			this->label11->TabIndex = 3;
			this->label11->Text = L"Imie:";
			// 
			// checkboxWYKLADOWCAMOD
			// 
			this->checkboxWYKLADOWCAMOD->AutoSize = true;
			this->checkboxWYKLADOWCAMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->checkboxWYKLADOWCAMOD->Location = System::Drawing::Point(660, 104);
			this->checkboxWYKLADOWCAMOD->Name = L"checkboxWYKLADOWCAMOD";
			this->checkboxWYKLADOWCAMOD->Size = System::Drawing::Size(157, 30);
			this->checkboxWYKLADOWCAMOD->TabIndex = 17;
			this->checkboxWYKLADOWCAMOD->Text = L"Wykladowca";
			this->checkboxWYKLADOWCAMOD->UseVisualStyleBackColor = true;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(36, 73);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(112, 26);
			this->label12->TabIndex = 5;
			this->label12->Text = L"Nazwisko:";
			// 
			// checkboxSTUDENTMOD
			// 
			this->checkboxSTUDENTMOD->AutoSize = true;
			this->checkboxSTUDENTMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkboxSTUDENTMOD->Location = System::Drawing::Point(660, 137);
			this->checkboxSTUDENTMOD->Name = L"checkboxSTUDENTMOD";
			this->checkboxSTUDENTMOD->Size = System::Drawing::Size(109, 30);
			this->checkboxSTUDENTMOD->TabIndex = 16;
			this->checkboxSTUDENTMOD->Text = L"Student";
			this->checkboxSTUDENTMOD->UseVisualStyleBackColor = true;
			// 
			// txtNAZWISKOMOD
			// 
			this->txtNAZWISKOMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNAZWISKOMOD->Location = System::Drawing::Point(212, 69);
			this->txtNAZWISKOMOD->Name = L"txtNAZWISKOMOD";
			this->txtNAZWISKOMOD->Size = System::Drawing::Size(230, 30);
			this->txtNAZWISKOMOD->TabIndex = 6;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(496, 120);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(63, 26);
			this->label16->TabIndex = 15;
			this->label16->Text = L"Rola:";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(36, 120);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(155, 26);
			this->label13->TabIndex = 7;
			this->label13->Text = L"Numer Indexu:";
			// 
			// txtHASLOMOD
			// 
			this->txtHASLOMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtHASLOMOD->Location = System::Drawing::Point(660, 65);
			this->txtHASLOMOD->Name = L"txtHASLOMOD";
			this->txtHASLOMOD->Size = System::Drawing::Size(230, 30);
			this->txtHASLOMOD->TabIndex = 12;
			// 
			// txtNUMERINDEXUMOD
			// 
			this->txtNUMERINDEXUMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNUMERINDEXUMOD->Location = System::Drawing::Point(212, 117);
			this->txtNUMERINDEXUMOD->MaxLength = 6;
			this->txtNUMERINDEXUMOD->Name = L"txtNUMERINDEXUMOD";
			this->txtNUMERINDEXUMOD->Size = System::Drawing::Size(230, 30);
			this->txtNUMERINDEXUMOD->TabIndex = 8;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(496, 68);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(74, 26);
			this->label15->TabIndex = 11;
			this->label15->Text = L"Haslo:";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(496, 26);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(144, 26);
			this->label14->TabIndex = 9;
			this->label14->Text = L"Adres E-mail:";
			// 
			// txtEMAILMOD
			// 
			this->txtEMAILMOD->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEMAILMOD->Location = System::Drawing::Point(660, 23);
			this->txtEMAILMOD->Name = L"txtEMAILMOD";
			this->txtEMAILMOD->Size = System::Drawing::Size(230, 30);
			this->txtEMAILMOD->TabIndex = 10;
			// 
			// dgMODYFIKACJAUZYTKOWNIKA
			// 
			this->dgMODYFIKACJAUZYTKOWNIKA->AllowUserToAddRows = false;
			this->dgMODYFIKACJAUZYTKOWNIKA->AllowUserToDeleteRows = false;
			this->dgMODYFIKACJAUZYTKOWNIKA->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgMODYFIKACJAUZYTKOWNIKA->Location = System::Drawing::Point(30, 60);
			this->dgMODYFIKACJAUZYTKOWNIKA->Name = L"dgMODYFIKACJAUZYTKOWNIKA";
			this->dgMODYFIKACJAUZYTKOWNIKA->ReadOnly = true;
			this->dgMODYFIKACJAUZYTKOWNIKA->RowTemplate->Height = 24;
			this->dgMODYFIKACJAUZYTKOWNIKA->Size = System::Drawing::Size(990, 310);
			this->dgMODYFIKACJAUZYTKOWNIKA->TabIndex = 2;
			this->dgMODYFIKACJAUZYTKOWNIKA->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Admin_Form::dgMODYFIKACJAUZYTKOWNIKA_CellClick);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(377, 10);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(362, 39);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Modyfikuj Uzytkownika";
			// 
			// tabPage5
			// 
			this->tabPage5->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage5->Controls->Add(this->txtUSUNUZYTKOWNIKA);
			this->tabPage5->Controls->Add(this->btnPOKAZUZYTKOWNIKAUSUN);
			this->tabPage5->Controls->Add(this->dgUSUNUZYTKOWNIKA);
			this->tabPage5->Controls->Add(this->label10);
			this->tabPage5->Location = System::Drawing::Point(4, 29);
			this->tabPage5->Name = L"tabPage5";
			this->tabPage5->Padding = System::Windows::Forms::Padding(3);
			this->tabPage5->Size = System::Drawing::Size(1050, 674);
			this->tabPage5->TabIndex = 4;
			this->tabPage5->Text = L"Usun Uzytkownika";
			// 
			// txtUSUNUZYTKOWNIKA
			// 
			this->txtUSUNUZYTKOWNIKA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUSUNUZYTKOWNIKA->Location = System::Drawing::Point(348, 570);
			this->txtUSUNUZYTKOWNIKA->Name = L"txtUSUNUZYTKOWNIKA";
			this->txtUSUNUZYTKOWNIKA->Size = System::Drawing::Size(282, 56);
			this->txtUSUNUZYTKOWNIKA->TabIndex = 21;
			this->txtUSUNUZYTKOWNIKA->Text = L"Usun Uzytkownika";
			this->txtUSUNUZYTKOWNIKA->UseVisualStyleBackColor = true;
			this->txtUSUNUZYTKOWNIKA->Click += gcnew System::EventHandler(this, &Admin_Form::txtUSUNUZYTKOWNIKA_Click);
			// 
			// btnPOKAZUZYTKOWNIKAUSUN
			// 
			this->btnPOKAZUZYTKOWNIKAUSUN->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPOKAZUZYTKOWNIKAUSUN->Location = System::Drawing::Point(45, 570);
			this->btnPOKAZUZYTKOWNIKAUSUN->Name = L"btnPOKAZUZYTKOWNIKAUSUN";
			this->btnPOKAZUZYTKOWNIKAUSUN->Size = System::Drawing::Size(282, 56);
			this->btnPOKAZUZYTKOWNIKAUSUN->TabIndex = 20;
			this->btnPOKAZUZYTKOWNIKAUSUN->Text = L"Pokaz Uzytkownikow";
			this->btnPOKAZUZYTKOWNIKAUSUN->UseVisualStyleBackColor = true;
			this->btnPOKAZUZYTKOWNIKAUSUN->Click += gcnew System::EventHandler(this, &Admin_Form::btnPOKAZUZYTKOWNIKAUSUN_Click);
			// 
			// dgUSUNUZYTKOWNIKA
			// 
			this->dgUSUNUZYTKOWNIKA->AllowUserToAddRows = false;
			this->dgUSUNUZYTKOWNIKA->AllowUserToDeleteRows = false;
			this->dgUSUNUZYTKOWNIKA->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgUSUNUZYTKOWNIKA->Location = System::Drawing::Point(36, 48);
			this->dgUSUNUZYTKOWNIKA->Name = L"dgUSUNUZYTKOWNIKA";
			this->dgUSUNUZYTKOWNIKA->ReadOnly = true;
			this->dgUSUNUZYTKOWNIKA->RowTemplate->Height = 24;
			this->dgUSUNUZYTKOWNIKA->Size = System::Drawing::Size(985, 473);
			this->dgUSUNUZYTKOWNIKA->TabIndex = 3;
			this->dgUSUNUZYTKOWNIKA->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Admin_Form::dgUSUNUZYTKOWNIKA_CellClick);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(383, 6);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(298, 39);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Usun Uzytkownika";
			// 
			// tabPage4
			// 
			this->tabPage4->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage4->Controls->Add(this->groupBox3);
			this->tabPage4->Controls->Add(this->dgGRUPYDODANI);
			this->tabPage4->Controls->Add(this->dgUZYTKOWNICYGRUPY);
			this->tabPage4->Controls->Add(this->dgGRUPY);
			this->tabPage4->Location = System::Drawing::Point(4, 29);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(1050, 674);
			this->tabPage4->TabIndex = 5;
			this->tabPage4->Text = L"Przydzielanie do Grup";
			// 
			// groupBox3
			// 
			this->groupBox3->BackColor = System::Drawing::SystemColors::HighlightText;
			this->groupBox3->Controls->Add(this->chekcboxWYKLADOWCAGRUPA);
			this->groupBox3->Controls->Add(this->checkboxSTUDENTGRUPA);
			this->groupBox3->Controls->Add(this->btnDODAJDOGRUPY);
			this->groupBox3->Controls->Add(this->btnPOKAZUZYTKOWNIKOWGRUPY);
			this->groupBox3->Controls->Add(this->btnPOKAZGRUPY);
			this->groupBox3->Location = System::Drawing::Point(11, 314);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(320, 318);
			this->groupBox3->TabIndex = 25;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Zarzadzaj Grupami";
			// 
			// chekcboxWYKLADOWCAGRUPA
			// 
			this->chekcboxWYKLADOWCAGRUPA->AutoSize = true;
			this->chekcboxWYKLADOWCAGRUPA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->chekcboxWYKLADOWCAGRUPA->Location = System::Drawing::Point(31, 106);
			this->chekcboxWYKLADOWCAGRUPA->Name = L"chekcboxWYKLADOWCAGRUPA";
			this->chekcboxWYKLADOWCAGRUPA->Size = System::Drawing::Size(157, 30);
			this->chekcboxWYKLADOWCAGRUPA->TabIndex = 28;
			this->chekcboxWYKLADOWCAGRUPA->Text = L"Wykladowca";
			this->chekcboxWYKLADOWCAGRUPA->UseVisualStyleBackColor = true;
			// 
			// checkboxSTUDENTGRUPA
			// 
			this->checkboxSTUDENTGRUPA->AutoSize = true;
			this->checkboxSTUDENTGRUPA->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->checkboxSTUDENTGRUPA->Location = System::Drawing::Point(31, 139);
			this->checkboxSTUDENTGRUPA->Name = L"checkboxSTUDENTGRUPA";
			this->checkboxSTUDENTGRUPA->Size = System::Drawing::Size(109, 30);
			this->checkboxSTUDENTGRUPA->TabIndex = 27;
			this->checkboxSTUDENTGRUPA->Text = L"Student";
			this->checkboxSTUDENTGRUPA->UseVisualStyleBackColor = true;
			// 
			// btnDODAJDOGRUPY
			// 
			this->btnDODAJDOGRUPY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDODAJDOGRUPY->Location = System::Drawing::Point(18, 249);
			this->btnDODAJDOGRUPY->Name = L"btnDODAJDOGRUPY";
			this->btnDODAJDOGRUPY->Size = System::Drawing::Size(282, 56);
			this->btnDODAJDOGRUPY->TabIndex = 26;
			this->btnDODAJDOGRUPY->Text = L"Dodaj do grupy";
			this->btnDODAJDOGRUPY->UseVisualStyleBackColor = true;
			this->btnDODAJDOGRUPY->Click += gcnew System::EventHandler(this, &Admin_Form::btnDODAJDOGRUPY_Click_1);
			// 
			// btnPOKAZUZYTKOWNIKOWGRUPY
			// 
			this->btnPOKAZUZYTKOWNIKOWGRUPY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPOKAZUZYTKOWNIKOWGRUPY->Location = System::Drawing::Point(18, 39);
			this->btnPOKAZUZYTKOWNIKOWGRUPY->Name = L"btnPOKAZUZYTKOWNIKOWGRUPY";
			this->btnPOKAZUZYTKOWNIKOWGRUPY->Size = System::Drawing::Size(282, 56);
			this->btnPOKAZUZYTKOWNIKOWGRUPY->TabIndex = 21;
			this->btnPOKAZUZYTKOWNIKOWGRUPY->Text = L"Pokaz ";
			this->btnPOKAZUZYTKOWNIKOWGRUPY->UseVisualStyleBackColor = true;
			this->btnPOKAZUZYTKOWNIKOWGRUPY->Click += gcnew System::EventHandler(this, &Admin_Form::btnPOKAZUZYTKOWNIKOWGRUPY_Click);
			// 
			// btnPOKAZGRUPY
			// 
			this->btnPOKAZGRUPY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnPOKAZGRUPY->Location = System::Drawing::Point(18, 180);
			this->btnPOKAZGRUPY->Name = L"btnPOKAZGRUPY";
			this->btnPOKAZGRUPY->Size = System::Drawing::Size(282, 56);
			this->btnPOKAZGRUPY->TabIndex = 25;
			this->btnPOKAZGRUPY->Text = L"Pokaz Grupy";
			this->btnPOKAZGRUPY->UseVisualStyleBackColor = true;
			this->btnPOKAZGRUPY->Click += gcnew System::EventHandler(this, &Admin_Form::btnPOKAZGRUPY_Click_1);
			// 
			// dgGRUPYDODANI
			// 
			this->dgGRUPYDODANI->AllowUserToAddRows = false;
			this->dgGRUPYDODANI->AllowUserToDeleteRows = false;
			this->dgGRUPYDODANI->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgGRUPYDODANI->Location = System::Drawing::Point(345, 314);
			this->dgGRUPYDODANI->Name = L"dgGRUPYDODANI";
			this->dgGRUPYDODANI->ReadOnly = true;
			this->dgGRUPYDODANI->RowTemplate->Height = 24;
			this->dgGRUPYDODANI->Size = System::Drawing::Size(699, 318);
			this->dgGRUPYDODANI->TabIndex = 2;
			// 
			// dgUZYTKOWNICYGRUPY
			// 
			this->dgUZYTKOWNICYGRUPY->AllowUserToAddRows = false;
			this->dgUZYTKOWNICYGRUPY->AllowUserToDeleteRows = false;
			this->dgUZYTKOWNICYGRUPY->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgUZYTKOWNICYGRUPY->Location = System::Drawing::Point(6, 6);
			this->dgUZYTKOWNICYGRUPY->Name = L"dgUZYTKOWNICYGRUPY";
			this->dgUZYTKOWNICYGRUPY->ReadOnly = true;
			this->dgUZYTKOWNICYGRUPY->RowTemplate->Height = 24;
			this->dgUZYTKOWNICYGRUPY->Size = System::Drawing::Size(501, 267);
			this->dgUZYTKOWNICYGRUPY->TabIndex = 1;
			this->dgUZYTKOWNICYGRUPY->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Admin_Form::dgUZYTKOWNICYGRUPY_CellClick);
			// 
			// dgGRUPY
			// 
			this->dgGRUPY->AllowUserToAddRows = false;
			this->dgGRUPY->AllowUserToDeleteRows = false;
			this->dgGRUPY->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgGRUPY->Location = System::Drawing::Point(543, 6);
			this->dgGRUPY->Name = L"dgGRUPY";
			this->dgGRUPY->ReadOnly = true;
			this->dgGRUPY->RowTemplate->Height = 24;
			this->dgGRUPY->Size = System::Drawing::Size(501, 267);
			this->dgGRUPY->TabIndex = 0;
			this->dgGRUPY->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Admin_Form::dgGRUPY_CellClick);
			// 
			// tabPage6
			// 
			this->tabPage6->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tabPage6->Controls->Add(this->groupBox4);
			this->tabPage6->Controls->Add(this->label17);
			this->tabPage6->Controls->Add(this->dgZARZADZENIEGRUPA);
			this->tabPage6->Location = System::Drawing::Point(4, 29);
			this->tabPage6->Name = L"tabPage6";
			this->tabPage6->Padding = System::Windows::Forms::Padding(3);
			this->tabPage6->Size = System::Drawing::Size(1050, 674);
			this->tabPage6->TabIndex = 6;
			this->tabPage6->Text = L"Zarzadzanie Grupa";
			// 
			// groupBox4
			// 
			this->groupBox4->BackColor = System::Drawing::SystemColors::HighlightText;
			this->groupBox4->Controls->Add(this->txtNAZWAGRUPYZARZADZANIE);
			this->groupBox4->Controls->Add(this->label18);
			this->groupBox4->Controls->Add(this->label19);
			this->groupBox4->Controls->Add(this->txtINFORMACJEZARZADZANIE);
			this->groupBox4->Controls->Add(this->btnUSUNGRUPE);
			this->groupBox4->Controls->Add(this->btnDODAJGRUPE);
			this->groupBox4->Controls->Add(this->btnPOKAZGRUPYZARZADZAJ);
			this->groupBox4->Controls->Add(this->btnMODYFIKUJGRUPE);
			this->groupBox4->Location = System::Drawing::Point(32, 390);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(990, 260);
			this->groupBox4->TabIndex = 20;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Zarzadzanie Grupa";
			// 
			// txtNAZWAGRUPYZARZADZANIE
			// 
			this->txtNAZWAGRUPYZARZADZANIE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtNAZWAGRUPYZARZADZANIE->Location = System::Drawing::Point(179, 52);
			this->txtNAZWAGRUPYZARZADZANIE->Name = L"txtNAZWAGRUPYZARZADZANIE";
			this->txtNAZWAGRUPYZARZADZANIE->Size = System::Drawing::Size(318, 30);
			this->txtNAZWAGRUPYZARZADZANIE->TabIndex = 23;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label18->Location = System::Drawing::Point(26, 54);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(144, 26);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Numer grupy:";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label19->Location = System::Drawing::Point(26, 123);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(120, 26);
			this->label19->TabIndex = 24;
			this->label19->Text = L"Informacje:";
			// 
			// txtINFORMACJEZARZADZANIE
			// 
			this->txtINFORMACJEZARZADZANIE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtINFORMACJEZARZADZANIE->Location = System::Drawing::Point(179, 121);
			this->txtINFORMACJEZARZADZANIE->Name = L"txtINFORMACJEZARZADZANIE";
			this->txtINFORMACJEZARZADZANIE->Size = System::Drawing::Size(696, 30);
			this->txtINFORMACJEZARZADZANIE->TabIndex = 25;
			// 
			// btnUSUNGRUPE
			// 
			this->btnUSUNGRUPE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnUSUNGRUPE->Location = System::Drawing::Point(789, 188);
			this->btnUSUNGRUPE->Name = L"btnUSUNGRUPE";
			this->btnUSUNGRUPE->Size = System::Drawing::Size(195, 56);
			this->btnUSUNGRUPE->TabIndex = 21;
			this->btnUSUNGRUPE->Text = L"Usun Grupe";
			this->btnUSUNGRUPE->UseVisualStyleBackColor = true;
			this->btnUSUNGRUPE->Click += gcnew System::EventHandler(this, &Admin_Form::btnUSUNGRUPE_Click);
			// 
			// btnDODAJGRUPE
			// 
			this->btnDODAJGRUPE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDODAJGRUPE->Location = System::Drawing::Point(343, 188);
			this->btnDODAJGRUPE->Name = L"btnDODAJGRUPE";
			this->btnDODAJGRUPE->Size = System::Drawing::Size(195, 56);
			this->btnDODAJGRUPE->TabIndex = 20;
			this->btnDODAJGRUPE->Text = L"Dodaj Grupe";
			this->btnDODAJGRUPE->UseVisualStyleBackColor = true;
			this->btnDODAJGRUPE->Click += gcnew System::EventHandler(this, &Admin_Form::btnDODAJGRUPE_Click);
			// 
			// btnPOKAZGRUPYZARZADZAJ
			// 
			this->btnPOKAZGRUPYZARZADZAJ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnPOKAZGRUPYZARZADZAJ->Location = System::Drawing::Point(26, 188);
			this->btnPOKAZGRUPYZARZADZAJ->Name = L"btnPOKAZGRUPYZARZADZAJ";
			this->btnPOKAZGRUPYZARZADZAJ->Size = System::Drawing::Size(226, 56);
			this->btnPOKAZGRUPYZARZADZAJ->TabIndex = 19;
			this->btnPOKAZGRUPYZARZADZAJ->Text = L"Pokaz Grupy";
			this->btnPOKAZGRUPYZARZADZAJ->UseVisualStyleBackColor = true;
			this->btnPOKAZGRUPYZARZADZAJ->Click += gcnew System::EventHandler(this, &Admin_Form::btnPOKAZGRUPYZARZADZAJ_Click);
			// 
			// btnMODYFIKUJGRUPE
			// 
			this->btnMODYFIKUJGRUPE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMODYFIKUJGRUPE->Location = System::Drawing::Point(544, 188);
			this->btnMODYFIKUJGRUPE->Name = L"btnMODYFIKUJGRUPE";
			this->btnMODYFIKUJGRUPE->Size = System::Drawing::Size(239, 56);
			this->btnMODYFIKUJGRUPE->TabIndex = 18;
			this->btnMODYFIKUJGRUPE->Text = L"Modyfikuj Grupe";
			this->btnMODYFIKUJGRUPE->UseVisualStyleBackColor = true;
			this->btnMODYFIKUJGRUPE->Click += gcnew System::EventHandler(this, &Admin_Form::btnMODYFIKUJGRUPE_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(390, 13);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(308, 39);
			this->label17->TabIndex = 2;
			this->label17->Text = L"Zarzadzanie Grupa";
			// 
			// dgZARZADZENIEGRUPA
			// 
			this->dgZARZADZENIEGRUPA->AllowUserToAddRows = false;
			this->dgZARZADZENIEGRUPA->AllowUserToDeleteRows = false;
			this->dgZARZADZENIEGRUPA->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgZARZADZENIEGRUPA->Location = System::Drawing::Point(30, 60);
			this->dgZARZADZENIEGRUPA->Name = L"dgZARZADZENIEGRUPA";
			this->dgZARZADZENIEGRUPA->ReadOnly = true;
			this->dgZARZADZENIEGRUPA->RowTemplate->Height = 24;
			this->dgZARZADZENIEGRUPA->Size = System::Drawing::Size(990, 310);
			this->dgZARZADZENIEGRUPA->TabIndex = 1;
			this->dgZARZADZENIEGRUPA->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Admin_Form::dgZARZADZENIEGRUPA_CellClick);
			// 
			// btnWYLOGUJ
			// 
			this->btnWYLOGUJ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWYLOGUJ->Location = System::Drawing::Point(772, 4);
			this->btnWYLOGUJ->Name = L"btnWYLOGUJ";
			this->btnWYLOGUJ->Size = System::Drawing::Size(141, 31);
			this->btnWYLOGUJ->TabIndex = 11;
			this->btnWYLOGUJ->Text = L"Wyloguj";
			this->btnWYLOGUJ->UseVisualStyleBackColor = true;
			this->btnWYLOGUJ->Click += gcnew System::EventHandler(this, &Admin_Form::btnWYLOGUJ_Click);
			// 
			// Admin_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1082, 753);
			this->Controls->Add(this->btnWYLOGUJ);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->lblAdmin);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Admin_Form";
			this->Text = L"Panel Administratora";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &Admin_Form::Admin_Form_FormClosed);
			this->Load += gcnew System::EventHandler(this, &Admin_Form::Admin_Form_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUzytkownicy))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgNOWYUZYTKOWNIK))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgMODYFIKACJAUZYTKOWNIKA))->EndInit();
			this->tabPage5->ResumeLayout(false);
			this->tabPage5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUSUNUZYTKOWNIKA))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgGRUPYDODANI))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgUZYTKOWNICYGRUPY))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgGRUPY))->EndInit();
			this->tabPage6->ResumeLayout(false);
			this->tabPage6->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgZARZADZENIEGRUPA))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*
		OWN VARIABLES
	*/
	bool closed = false;
	int id_rekordu = 0;
	int id_grupy = 0;
	int id_grupy_2 = 0;
	int row = 0;
	/*
		OWN FUNCTIONS
	*/
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


	private: void pokaz_grupy(System::Windows::Forms::DataGridView^ siatka)
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM grupy WHERE idgrupy > 1;", laczbaze);

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


	private: void pokaz_okreslonego_uzytkownika(System::Windows::Forms::DataGridView^ siatka, const int id_rekordu_uzytkownika)
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM uzytkownicy WHERE iduzytkownicy = '" + id_rekordu_uzytkownika +"'", laczbaze);

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
	}


	private: void pokaz_okreslona_grupe_uzytkownikow(System::Windows::Forms::DataGridView^ siatka, const int rola_idrola)
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM uzytkownicy WHERE rola_idrola = '" + rola_idrola + "'", laczbaze);

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
	}
	//=======================================================================================//
	//=======================================================================================//

	private: System::Void Admin_Form_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->lblAdmin->Text = this->Admin_Name;
		closed = false;
	}

	private: System::Void btnPokazUzytkownikow_Click_1(System::Object^  sender, System::EventArgs^  e)
	{
		pokaz_uzytkownikow(dgUzytkownicy);
		dgUzytkownicy->Columns[6]->Visible = false;
	}

	private: System::Void btnWYLOGUJ_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (closed != true)
		{
			if (MessageBox::Show("Czy na pewno chcesz sie wylogowac?", "Uwaga!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				this->~Admin_Form();
				Logowanie_Form->Visible = true;
				closed = true;
			}
		}
	}


	private: System::Void Admin_Form_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{	//Currently unavailable
		/*if (closed != true)
		{
			if (MessageBox::Show("Czy na pewno chcesz sie wylogowac?", "Uwaga!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
			{
				this->~Admin_Form();
				closed = true;
			}
		}*/
		Logowanie_Form->Visible = true;
	}


	private: System::Void btnDODAJUZYTKOWNIKA_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
		if ((checkboxWYKLADOWCA->Checked == true && checkboxSTUDENT->Checked == true) || (checkboxWYKLADOWCA->Checked == false && checkboxSTUDENT->Checked == false))
		{
			MessageBox::Show("Sprawdz czy poprawnie zaznaczyles role uzytkownika!");
		}
		else
		{
			//IF U WANT TO DECREMENT AUTOINCREMENT VALUE FROM MYSQL => ALTER TABLE `blind_bank_db`.`uzytkownicy` AUTO_INCREMENT = 8;
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			//CHECKING IF THE USER EXIST IN DB OR NOT
			if (txtIMIE->Text == "" || txtNAZWISKO->Text == "" || txtNUMERINDEXU->Text == "" || txtEMAIL->Text == "" || txtHASLO->Text == "")
			{
				MessageBox::Show("Sprawdz czy poprawnie wprowadziles wszystkie dane!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			}
			else
			{
				try {

					if (checkboxWYKLADOWCA->Checked == true)
					{
						//polecenie->CommandText = "INSERT INTO uzytkownicy SET Imie_Uzytkownika = '" + txtIMIE->Text + "' , Nazwisko_Uzytkownika = '" + txtNAZWISKO->Text + "' , Unique_Index_Number = '" + txtNUMERINDEXU->Text + "', Email_Uzytkownika = '" + txtEMAIL->Text + "', Haslo_Uzytkownika = '" + txtHASLO->Text + "', rola_idrola = '" + txtHASLO->Text + "';";
						polecenie->CommandText = "INSERT INTO uzytkownicy (`Imie_Uzytkownika`, `Nazwisko_Uzytkownika`, `Unique_Index_Number`, `Email_Uzytkownika`, `Haslo_Uzytkownika`, `rola_idrola`) VALUES ('" + txtIMIE->Text + "',  '" + txtNAZWISKO->Text + "', '" + txtNUMERINDEXU->Text + "', '" + txtEMAIL->Text + "', '" + txtHASLO->Text + "', '2');";
						polecenie->ExecuteNonQuery();

						transakcja->Commit();
						MessageBox::Show("Uzytkownik zostal dodany poprawnie!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
					}
					else if (checkboxSTUDENT->Checked == true)
					{
						polecenie->CommandText = "INSERT INTO uzytkownicy (`Imie_Uzytkownika`, `Nazwisko_Uzytkownika`, `Unique_Index_Number`, `Email_Uzytkownika`, `Haslo_Uzytkownika`, `rola_idrola`) VALUES ('" + txtIMIE->Text + "',  '" + txtNAZWISKO->Text + "', '" + txtNUMERINDEXU->Text + "', '" + txtEMAIL->Text + "', '" + txtHASLO->Text + "', '3');";
						polecenie->ExecuteNonQuery();

						transakcja->Commit();
						MessageBox::Show("Uzytkownik zostal dodany poprawnie!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
					}
				}
				catch (Exception^ komunikat)
				{
					//MessageBox::Show("Cos poszlo nie tak! Komunikat: " + komunikat + " !", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
					MessageBox::Show("Cos poszlo nie tak!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
					transakcja->Rollback();
				}
			}
			pokaz_uzytkownikow(dgNOWYUZYTKOWNIK);
			laczbaze->Close();
		}
	}

	
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		pokaz_uzytkownikow(dgMODYFIKACJAUZYTKOWNIKA);
	}


	private: System::Void dgMODYFIKACJAUZYTKOWNIKA_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
		{
			id_rekordu = Convert::ToInt32(dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells[0]->Value);
			if (dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["rola_idrola"]->Value->ToString() == "2")
			{
				txtIMIEMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Imie_Uzytkownika"]->Value->ToString();
				txtNAZWISKOMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Nazwisko_Uzytkownika"]->Value->ToString();
				txtNUMERINDEXUMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Unique_Index_Number"]->Value->ToString();
				txtEMAILMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Email_Uzytkownika"]->Value->ToString();
				txtHASLOMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Haslo_Uzytkownika"]->Value->ToString();
				checkboxWYKLADOWCAMOD->Checked = true;
				checkboxSTUDENTMOD->Checked = false;
			}
			else if (dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["rola_idrola"]->Value->ToString() == "3")
			{
				txtIMIEMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Imie_Uzytkownika"]->Value->ToString();
				txtNAZWISKOMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Nazwisko_Uzytkownika"]->Value->ToString();
				txtNUMERINDEXUMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Unique_Index_Number"]->Value->ToString();
				txtEMAILMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Email_Uzytkownika"]->Value->ToString();
				txtHASLOMOD->Text = dgMODYFIKACJAUZYTKOWNIKA->Rows[e->RowIndex]->Cells["Haslo_Uzytkownika"]->Value->ToString();
				checkboxWYKLADOWCAMOD->Checked = false;
				checkboxSTUDENTMOD->Checked = true;
			}
			else
			{
				txtIMIEMOD->Text = "";
				txtNAZWISKOMOD->Text = "";
				txtNUMERINDEXUMOD->Text = "";
				txtEMAILMOD->Text = "";
				txtHASLOMOD->Text = "";
				checkboxWYKLADOWCAMOD->Checked = false;
				checkboxSTUDENTMOD->Checked = false;
			}
		}
	}


	private: System::Void btnMODYFIKUJ_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (txtIMIEMOD->Text == "" || txtNAZWISKOMOD->Text == "" || txtNUMERINDEXUMOD->Text == "" || txtEMAILMOD->Text == "" || txtHASLOMOD->Text == "")
		{
			MessageBox::Show("Sprawdz czy poprawnie wprowadziles wszystkie dane!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
		else
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			try
			{
				if (checkboxWYKLADOWCAMOD->Checked == true)
				{
					polecenie->CommandText = "UPDATE uzytkownicy SET `Imie_Uzytkownika` = '" + txtIMIEMOD->Text + "', `Nazwisko_Uzytkownika` = '" + txtNAZWISKOMOD->Text + "', `Unique_Index_Number` = '" + txtNUMERINDEXUMOD->Text + "', `Email_Uzytkownika` = '" + txtEMAILMOD->Text + "', `Haslo_Uzytkownika` = '" + txtHASLOMOD->Text + "', `rola_idrola` = '2' WHERE `iduzytkownicy` = '" + id_rekordu + "';";
					polecenie->ExecuteNonQuery();

					transakcja->Commit();
					MessageBox::Show("Uzytkownik: " + txtIMIEMOD->Text + " " + txtNAZWISKOMOD->Text + " wlasnie zostal zmodyfikowany!!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				}
				else if (checkboxSTUDENTMOD->Checked == true)
				{
					polecenie->CommandText = "UPDATE uzytkownicy SET `Imie_Uzytkownika` = '" + txtIMIEMOD->Text + "', `Nazwisko_Uzytkownika` = '" + txtNAZWISKOMOD->Text + "', `Unique_Index_Number` = '" + txtNUMERINDEXUMOD->Text + "', `Email_Uzytkownika` = '" + txtEMAILMOD->Text + "', `Haslo_Uzytkownika` = '" + txtHASLOMOD->Text + "', `rola_idrola` = '3' WHERE `iduzytkownicy` = '" + id_rekordu + "';";
					polecenie->ExecuteNonQuery();

					transakcja->Commit();
					MessageBox::Show("Uzytkownik: " + txtIMIEMOD->Text + " " + txtNAZWISKOMOD->Text + " wlasnie zostal zmodyfikowany!!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				}		
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show("Wystapil problem przy modifykiacji uzytkownika!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				transakcja->Rollback();
			}
			laczbaze->Close();
		}
		pokaz_uzytkownikow(dgMODYFIKACJAUZYTKOWNIKA);
	}


	private: System::Void btnPOKAZUZYTKOWNIKAUSUN_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		pokaz_uzytkownikow(dgUSUNUZYTKOWNIKA);
		dgUSUNUZYTKOWNIKA->Columns[6]->Visible = false;
	}


	private: System::Void txtUSUNUZYTKOWNIKA_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
		MySqlCommand^ polecenie = laczbaze->CreateCommand();
		MySqlTransaction^ transakcja;

		laczbaze->Open();
		transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

		polecenie->Connection = laczbaze;
		polecenie->Transaction = transakcja;

		try
		{
			if (dgUSUNUZYTKOWNIKA->Rows[row]->Cells["rola_idrola"]->Value->ToString() == "1")
			{
				MessageBox::Show("Nie mozna usunac administratora!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			}
			else
			{
				if (MessageBox::Show("Czy usunac Uzytkownika: " + dgUSUNUZYTKOWNIKA->Rows[row]->Cells["Imie_Uzytkownika"]->Value->ToString() + " " + dgUSUNUZYTKOWNIKA->Rows[row]->Cells["Nazwisko_Uzytkownika"]->Value->ToString() + "?", " Ostrzezenie!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				{
					polecenie->CommandText = "DELETE FROM uzytkownicy WHERE `iduzytkownicy`='" + id_rekordu + "';";
					polecenie->ExecuteNonQuery();

					transakcja->Commit();
					MessageBox::Show("Uzytkownik: " + dgUSUNUZYTKOWNIKA->Rows[row]->Cells["Imie_Uzytkownika"]->Value->ToString() + " " + dgUSUNUZYTKOWNIKA->Rows[row]->Cells["Nazwisko_Uzytkownika"]->Value->ToString() + " wlasnie zostal usuniety!");
				}
			}
		}
		catch (Exception^ komunikat)
		{
			MessageBox::Show("Wystapil problem podczas usuwania uzytkownika!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			transakcja->Rollback();
		}
		laczbaze->Close();
		pokaz_uzytkownikow(dgUSUNUZYTKOWNIKA);
	}


	private: System::Void dgUSUNUZYTKOWNIKA_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
		{
			id_rekordu = Convert::ToInt32(dgUSUNUZYTKOWNIKA->Rows[e->RowIndex]->Cells[0]->Value);
			row = e->RowIndex;
		}
	}


	private: System::Void btnPOKAZUZYTKOWNIKOWNOWYUZYTKOWNIK_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		pokaz_uzytkownikow(dgNOWYUZYTKOWNIK);
		dgNOWYUZYTKOWNIK->Columns[6]->Visible = false;
	}


	private: System::Void btnPOKAZUZYTKOWNIKOWGRUPY_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (chekcboxWYKLADOWCAGRUPA->Checked == true && checkboxSTUDENTGRUPA->Checked == false)
		{
			pokaz_okreslona_grupe_uzytkownikow(dgUZYTKOWNICYGRUPY,2);
			dgUZYTKOWNICYGRUPY->Columns[6]->Visible = false;
		}
		else if (checkboxSTUDENTGRUPA->Checked == true && chekcboxWYKLADOWCAGRUPA->Checked == false)
		{
			pokaz_okreslona_grupe_uzytkownikow(dgUZYTKOWNICYGRUPY, 3);
			dgUZYTKOWNICYGRUPY->Columns[6]->Visible = false;
		}
		else
		{
			pokaz_uzytkownikow(dgUZYTKOWNICYGRUPY);
			dgUZYTKOWNICYGRUPY->Columns[6]->Visible = false;
		}
	}


	private: System::Void btnPOKAZGRUPY_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
		pokaz_grupy(dgGRUPY);
	}


	private: System::Void btnDODAJDOGRUPY_Click_1(System::Object^  sender, System::EventArgs^  e)
	{
		if (id_rekordu == -1 || id_grupy == -1)
		{
			MessageBox::Show("Sprawdz czy poprawnie zaznaczyles uzytkownika oraz grupe przed dodaniem do niej uzytkownika!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
		else
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			try
			{
				if (id_grupy != 1 && id_grupy != -1)
				{
					//INSERT INTO `blind_bank_db`.`grupy_uzytkownikow` (`iduzytkownika`, `idgrupy`, `Numer_Indexu_uzytkownika`, `Numer_Grupy`, `Informacje`) VALUES ('5', '3', '354337', '2', 'Rok Akademicki 2017/2018');
					//polecenie->CommandText = "INSERT INTO `blind_bank_db`.`uzytkownicy` (`Imie_Uzytkownika`, `Nazwisko_Uzytkownika`, `Unique_Index_Number`, `Email_Uzytkownika`, `Haslo_Uzytkownika`, `rola_idrola`, `grupy_idgrupy`) VALUES ('" + txtIMIE->Text + "',  '" + txtNAZWISKO->Text + "', '" + txtNUMERINDEXU->Text + "', '" + txtEMAIL->Text + "', '" + txtHASLO->Text + "', '2', '1');";
				//	polecenie->CommandText = "UPDATE `blind_bank_db`.`uzytkownicy` SET `grupy_idgrupy` = '" + id_grupy + "' WHERE `iduzytkownicy` = '" + id_rekordu + "';";
					//polecenie->CommandText = "INSERT INTO `blind_bank_db`.`uzytkownicy` (`grupy_idgrupy`) VALUES ('" + id_grupy + "') WHERE `iduzytkownicy` = '" + id_rekordu + "';";
					//polecenie->CommandText = "INSERT INTO grupy_uzytkownikow (iduzytkownika, idgrupy) VALUES ('" + id_rekordu + "','" + id_grupy + "');";
					polecenie->CommandText = "INSERT INTO grupy_uzytkownikow (iduzytkownika, idgrupy) VALUES ('" + id_rekordu + "','" + id_grupy + "');";
					polecenie->ExecuteNonQuery();
					transakcja->Commit();
					MessageBox::Show("Uzytkownik wlasnie zostal dodany do grupy!!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				}
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show("Wystapil problem przy dodawaniu uzytkownika do grupy!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				transakcja->Rollback();
			}
			laczbaze->Close();
			pokaz_okreslonego_uzytkownika(dgGRUPYDODANI, id_rekordu);
		}
	}


	private: System::Void dgUZYTKOWNICYGRUPY_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
		{
			id_rekordu = Convert::ToInt32(dgUZYTKOWNICYGRUPY->Rows[e->RowIndex]->Cells[0]->Value);
		}
	}


	private: System::Void dgGRUPY_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
		{
			id_grupy = Convert::ToInt32(dgGRUPY->Rows[e->RowIndex]->Cells[0]->Value);
		}
	}


	private: System::Void tabControl1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		id_grupy = -1;
		id_rekordu = -1;
	}


	private: System::Void btnPOKAZGRUPYZARZADZAJ_Click(System::Object^  sender, System::EventArgs^  e)
	{
		pokaz_grupy(dgZARZADZENIEGRUPA);
	}


	private: System::Void dgZARZADZENIEGRUPA_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
		{
			id_grupy_2 = Convert::ToInt32(dgZARZADZENIEGRUPA->Rows[e->RowIndex]->Cells[0]->Value);
			txtNAZWAGRUPYZARZADZANIE->Text = dgZARZADZENIEGRUPA->Rows[e->RowIndex]->Cells["Numer_Grupy"]->Value->ToString();
			txtINFORMACJEZARZADZANIE->Text = dgZARZADZENIEGRUPA->Rows[e->RowIndex]->Cells["Informacje"]->Value->ToString();
			row = e->RowIndex;
		}
	}


	private: System::Void btnDODAJGRUPE_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (txtNAZWAGRUPYZARZADZANIE->Text == "" || txtINFORMACJEZARZADZANIE->Text == "")
		{
			MessageBox::Show("Sprawdz czy wszystkie dane grupy sa poprawne!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
		else
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			try
			{
				if (MessageBox::Show("Czy dodac grupe: " + txtNAZWAGRUPYZARZADZANIE->Text + " " + txtINFORMACJEZARZADZANIE->Text + " ?", " Ostrzezenie!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				{
					//INSERT INTO `blind_bank_db`.`grupy` (`Numer_Grupy`, `Informacje`) VALUES ('2', 'Rok Akademicki 2016/2017');
					polecenie->CommandText = "INSERT INTO grupy (`Numer_Grupy`, `Informacje`) VALUES ( '"+ txtNAZWAGRUPYZARZADZANIE->Text +"', '"+ txtINFORMACJEZARZADZANIE->Text +"')";
					polecenie->ExecuteNonQuery();

					transakcja->Commit();
					MessageBox::Show("Grupa: " + txtNAZWAGRUPYZARZADZANIE->Text + " " + txtINFORMACJEZARZADZANIE->Text + " wlasnie zostala dodana!");
				}
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show("Wystapil problem podczas dodawania grupy!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				transakcja->Rollback();
			}
			laczbaze->Close();
		}
		pokaz_grupy(dgZARZADZENIEGRUPA);
	}


	private: System::Void btnMODYFIKUJGRUPE_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (txtNAZWAGRUPYZARZADZANIE->Text == "" || txtINFORMACJEZARZADZANIE->Text == "")
		{
			MessageBox::Show("Sprawdz czy wszystkie dane grupy sa poprawne!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
		else
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			try
			{
				polecenie->CommandText = "UPDATE grupy SET `Numer_Grupy` = '" + txtNAZWAGRUPYZARZADZANIE->Text + "' , `Informacje` = '" + txtINFORMACJEZARZADZANIE->Text + "' WHERE `idgrupy` = '" + id_grupy_2 + "';";
				polecenie->ExecuteNonQuery();
				transakcja->Commit();
				MessageBox::Show("Grupa zostala poprawnie zmodyfikowana!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show("Wystapil problem podczas modyfikowania grupy!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				transakcja->Rollback();
			}
			laczbaze->Close();
		}
		pokaz_grupy(dgZARZADZENIEGRUPA);
	}


	private: System::Void btnUSUNGRUPE_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (txtNAZWAGRUPYZARZADZANIE->Text == "" || txtINFORMACJEZARZADZANIE->Text == "")
		{
			MessageBox::Show("Sprawdz czy wszystkie dane grupy sa poprawne!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
		}
		else
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			try
			{
				if (MessageBox::Show("Czy usunac Grupe: " + dgZARZADZENIEGRUPA->Rows[row]->Cells["Numer_Grupy"]->Value->ToString() + " " + dgZARZADZENIEGRUPA->Rows[row]->Cells["Informacje"]->Value->ToString() + " ?", " Ostrzezenie!!", MessageBoxButtons::YesNo, MessageBoxIcon::Warning) == System::Windows::Forms::DialogResult::Yes)
				{
					polecenie->CommandText = "DELETE FROM grupy WHERE `idgrupy`= '" + id_grupy_2 + "';";
					polecenie->ExecuteNonQuery();
					transakcja->Commit();
					/*polecenie->CommandText = "DELETE FROM `blind_bank_db`.`grupy_uzytkownikow` WHERE `idgrupy` = '" + id_grupy_2 + "';";	//IMPORTANT
					polecenie->ExecuteNonQuery();
					transakcja->Commit();*/
					MessageBox::Show("Grupa: " + dgZARZADZENIEGRUPA->Rows[row]->Cells["Numer_Grupy"]->Value->ToString() + " " + dgZARZADZENIEGRUPA->Rows[row]->Cells["Informacje"]->Value->ToString() + " wlasnie zostala usunieta!");
				}
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show("Wystapil problem podczas usuwania grupy!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
				transakcja->Rollback();
			}
			laczbaze->Close();
		}
		pokaz_grupy(dgZARZADZENIEGRUPA);
	}


	private: System::Void btnPOKAZGRUPYUZYTKOWNIKA_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (id_rekordu != -1)
		{
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM blind_bank_db.grupy WHERE idgrupy = (SELECT idgrupy FROM blind_bank_db.grupy_uzytkownikow WHERE iduzytkownika = '"+ id_rekordu +"');", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM grupy_uzytkownikow WHERE iduzytkownika = '"+ id_rekordu +"';", laczbaze);

			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				dgUzytkownicy->DataSource = zrodlo;
				laczbaze->Close();
			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}
			dgUzytkownicy->Columns[0]->Visible = false;
		}
	}


	private: System::Void dgUzytkownicy_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
		{
			id_rekordu = Convert::ToInt32(dgUzytkownicy->Rows[e->RowIndex]->Cells[0]->Value);
		}
	}

};
}