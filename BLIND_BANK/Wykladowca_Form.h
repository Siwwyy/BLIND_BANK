#pragma once
//#include "Logowanie.h"
#include "Configure_String.hpp"
//#include <vector>
#include <cliext/vector>

namespace BLINDBANK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	/// <summary>
	/// Summary for Wykladowca_Form
	/// </summary>
	public ref class Wykladowca_Form : public System::Windows::Forms::Form
	{
	public:
		Wykladowca_Form(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		//currently constructor contains integer type, finally change it to string for example, String^ role
		Wykladowca_Form(const int role) :
			role(role)
		{
			InitializeComponent();

		}

		Wykladowca_Form(const int role, String^ & Admin_Name, System::Windows::Forms::Form ^ _Form) :
			role(role),
			Admin_Name(Admin_Name),
			Logowanie_Form(_Form),
			id_wykladowca(0)
		{
			InitializeComponent();
			
			
		}

		Wykladowca_Form(const int role, String^ & Admin_Name, int a, System::Windows::Forms::Form ^ _Form) :
			role(role),
			Admin_Name(Admin_Name),
			Logowanie_Form(_Form),
			id_wykladowca(a),
			id_osoby(-1),
			nazwapliku(),
			calyplik()
		{
			InitializeComponent();
			//Zaladuj grupy do Vectora
			MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT idgrupy, Numer_Grupy , Informacje FROM grupy WHERE  idgrupy in (SELECT  idgrupy FROM grupy_uzytkownikow WHERE iduzytkownika='" + this->id_wykladowca + "');", laczbaze);

			try {

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				dgPOKAZGRUPYGRUPY->DataSource = zrodlo;

				laczbaze->Close();

				


			}
			catch (Exception^ komunikat)
			{
				MessageBox::Show(komunikat->Message);
			}



			//siatka->Columns[0]->Visible = false;
			//	siatka->Columns[7]->Visible = false;
			combobox1->BeginUpdate();
			for (int i = 0; i < dgPOKAZGRUPYGRUPY->RowCount; ++i)
			{
				idgrup.push_back(Convert::ToInt32(dgPOKAZGRUPYGRUPY->Rows[i]->Cells[0]->Value));
				String^ s = "Nr."+Convert::ToString(dgPOKAZGRUPYGRUPY->Rows[i]->Cells[1]->Value) + " " +Convert::ToString(dgPOKAZGRUPYGRUPY->Rows[i]->Cells[2]->Value);
				combobox1->Items->Add(s);
			}
			combobox1->EndUpdate();

			//Update profile card
			{
				MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
				MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Email_Uzytkownika from uzytkownicy WHERE iduzytkownicy = '"+id_wykladowca+"'", laczbaze);

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				dgtmp->DataSource = zrodlo;
				//taczable = false;
				//dgPLIKI->Columns[0]->Visible = false;
				//id_osoby = Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[0]->Value);
				lbProfilImie->Text = Convert::ToString(dgtmp->Rows[0]->Cells[0]->Value);
				lbProfilNazwisko->Text = Convert::ToString(dgtmp->Rows[0]->Cells[1]->Value);
				lbProfilEmail->Text = Convert::ToString(dgtmp->Rows[0]->Cells[2]->Value);
				laczbaze->Close();

			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Wykladowca_Form()
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
		int id_rekordu;
		//Here add mysql reader
		String^ konfiguracja = SQL_CONFIGURATION::get_konfiguracja();
		//	String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=blind_bank_db";
			//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";
		int role;
		String^ Admin_Name;
		System::Windows::Forms::Form ^ Logowanie_Form;
		int id_wykladowca;
		cliext::vector<int> idgrup;
		bool taczable = true;
		int id_osoby;
		cliext::vector<String^> nazwapliku;
		cliext::vector<String^> calyplik;


	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Button^  btnWYLOGUJ;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  Grupy;
	private: System::Windows::Forms::TabPage^  PraceDomowe;
	private: System::Windows::Forms::TabPage^  Profil;
	private: System::Windows::Forms::Button^  btnPOKAZGRUPYGRUPY;
	private: System::Windows::Forms::DataGridView^  dgPOKAZGRUPYGRUPY;
	private: System::Windows::Forms::Button^  btnPokazCzlonkow;
	private: System::Windows::Forms::TabPage^  DodajPracedomowa;
private: System::Windows::Forms::ComboBox^  combobox1;

	private: System::Windows::Forms::Label^  label5;
private: System::Windows::Forms::DateTimePicker^  timePicker;

	private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::TextBox^  titleBox;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::RichTextBox^  contentBox;

	private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  btnPOKAZPRACE;
private: System::Windows::Forms::DataGridView^  dgPOKAZPRACE;
private: System::Windows::Forms::DataGridView^  dgtmp;
private: System::Windows::Forms::Label^  lbTITLEC;
private: System::Windows::Forms::Label^  lbTITLE;
private: System::Windows::Forms::Label^  lbCONTENTC;
private: System::Windows::Forms::Label^  lbCONTENT;
private: System::Windows::Forms::Button^  btnSubmitOcena;
private: System::Windows::Forms::Label^  lbOcenaOsoba;
private: System::Windows::Forms::ComboBox^  boxOcena;
private: System::Windows::Forms::Label^  lbOsobaC;
private: System::Windows::Forms::Label^  lbOsoba;
private: System::Windows::Forms::DataGridView^  dgPLIKI;
private: System::Windows::Forms::Button^  btnDOWNLOAD;
private: System::Windows::Forms::Label^  label6;
private: System::Windows::Forms::Label^  lbProfilEmail;

private: System::Windows::Forms::Label^  lbProfilNazwisko;
private: System::Windows::Forms::Label^  lbProfilImie;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label7;



















































































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
				 this->Grupy = (gcnew System::Windows::Forms::TabPage());
				 this->btnPokazCzlonkow = (gcnew System::Windows::Forms::Button());
				 this->dgPOKAZGRUPYGRUPY = (gcnew System::Windows::Forms::DataGridView());
				 this->btnPOKAZGRUPYGRUPY = (gcnew System::Windows::Forms::Button());
				 this->PraceDomowe = (gcnew System::Windows::Forms::TabPage());
				 this->btnDOWNLOAD = (gcnew System::Windows::Forms::Button());
				 this->dgPLIKI = (gcnew System::Windows::Forms::DataGridView());
				 this->btnSubmitOcena = (gcnew System::Windows::Forms::Button());
				 this->lbOcenaOsoba = (gcnew System::Windows::Forms::Label());
				 this->boxOcena = (gcnew System::Windows::Forms::ComboBox());
				 this->lbOsobaC = (gcnew System::Windows::Forms::Label());
				 this->lbOsoba = (gcnew System::Windows::Forms::Label());
				 this->lbCONTENTC = (gcnew System::Windows::Forms::Label());
				 this->lbCONTENT = (gcnew System::Windows::Forms::Label());
				 this->lbTITLEC = (gcnew System::Windows::Forms::Label());
				 this->lbTITLE = (gcnew System::Windows::Forms::Label());
				 this->dgtmp = (gcnew System::Windows::Forms::DataGridView());
				 this->btnPOKAZPRACE = (gcnew System::Windows::Forms::Button());
				 this->dgPOKAZPRACE = (gcnew System::Windows::Forms::DataGridView());
				 this->Profil = (gcnew System::Windows::Forms::TabPage());
				 this->DodajPracedomowa = (gcnew System::Windows::Forms::TabPage());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->contentBox = (gcnew System::Windows::Forms::RichTextBox());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->timePicker = (gcnew System::Windows::Forms::DateTimePicker());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->titleBox = (gcnew System::Windows::Forms::TextBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->combobox1 = (gcnew System::Windows::Forms::ComboBox());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->lbProfilImie = (gcnew System::Windows::Forms::Label());
				 this->lbProfilNazwisko = (gcnew System::Windows::Forms::Label());
				 this->lbProfilEmail = (gcnew System::Windows::Forms::Label());
				 this->tabControl1->SuspendLayout();
				 this->Grupy->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPOKAZGRUPYGRUPY))->BeginInit();
				 this->PraceDomowe->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPLIKI))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgtmp))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPOKAZPRACE))->BeginInit();
				 this->Profil->SuspendLayout();
				 this->DodajPracedomowa->SuspendLayout();
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
				 this->dateTimePicker1->Location = System::Drawing::Point(689, 5);
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
				 this->btnWYLOGUJ->Location = System::Drawing::Point(579, 3);
				 this->btnWYLOGUJ->Margin = System::Windows::Forms::Padding(2);
				 this->btnWYLOGUJ->Name = L"btnWYLOGUJ";
				 this->btnWYLOGUJ->Size = System::Drawing::Size(106, 25);
				 this->btnWYLOGUJ->TabIndex = 13;
				 this->btnWYLOGUJ->Text = L"Wyloguj";
				 this->btnWYLOGUJ->UseVisualStyleBackColor = true;
				 this->btnWYLOGUJ->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnWYLOGUJ_Click);
				 // 
				 // tabControl1
				 // 
				 this->tabControl1->Controls->Add(this->Grupy);
				 this->tabControl1->Controls->Add(this->PraceDomowe);
				 this->tabControl1->Controls->Add(this->Profil);
				 this->tabControl1->Controls->Add(this->DodajPracedomowa);
				 this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
				 this->tabControl1->Location = System::Drawing::Point(9, 33);
				 this->tabControl1->Margin = System::Windows::Forms::Padding(2);
				 this->tabControl1->Name = L"tabControl1";
				 this->tabControl1->SelectedIndex = 0;
				 this->tabControl1->Size = System::Drawing::Size(794, 574);
				 this->tabControl1->TabIndex = 14;
				 // 
				 // Grupy
				 // 
				 this->Grupy->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->Grupy->Controls->Add(this->btnPokazCzlonkow);
				 this->Grupy->Controls->Add(this->dgPOKAZGRUPYGRUPY);
				 this->Grupy->Controls->Add(this->btnPOKAZGRUPYGRUPY);
				 this->Grupy->Location = System::Drawing::Point(4, 25);
				 this->Grupy->Margin = System::Windows::Forms::Padding(2);
				 this->Grupy->Name = L"Grupy";
				 this->Grupy->Padding = System::Windows::Forms::Padding(2);
				 this->Grupy->Size = System::Drawing::Size(786, 545);
				 this->Grupy->TabIndex = 0;
				 this->Grupy->Text = L"Grupy";
				 // 
				 // btnPokazCzlonkow
				 // 
				 this->btnPokazCzlonkow->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
				 this->btnPokazCzlonkow->Location = System::Drawing::Point(147, 462);
				 this->btnPokazCzlonkow->Margin = System::Windows::Forms::Padding(2);
				 this->btnPokazCzlonkow->Name = L"btnPokazCzlonkow";
				 this->btnPokazCzlonkow->Size = System::Drawing::Size(218, 58);
				 this->btnPokazCzlonkow->TabIndex = 2;
				 this->btnPokazCzlonkow->Text = L"Pokaz cz³onków grupy";
				 this->btnPokazCzlonkow->UseVisualStyleBackColor = true;
				 this->btnPokazCzlonkow->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnPokazCzlonkow_Click);
				 // 
				 // dgPOKAZGRUPYGRUPY
				 // 
				 this->dgPOKAZGRUPYGRUPY->AllowUserToAddRows = false;
				 this->dgPOKAZGRUPYGRUPY->AllowUserToDeleteRows = false;
				 this->dgPOKAZGRUPYGRUPY->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dgPOKAZGRUPYGRUPY->Location = System::Drawing::Point(4, 5);
				 this->dgPOKAZGRUPYGRUPY->Margin = System::Windows::Forms::Padding(2);
				 this->dgPOKAZGRUPYGRUPY->Name = L"dgPOKAZGRUPYGRUPY";
				 this->dgPOKAZGRUPYGRUPY->ReadOnly = true;
				 this->dgPOKAZGRUPYGRUPY->RowTemplate->Height = 24;
				 this->dgPOKAZGRUPYGRUPY->Size = System::Drawing::Size(778, 440);
				 this->dgPOKAZGRUPYGRUPY->TabIndex = 1;
				 this->dgPOKAZGRUPYGRUPY->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Wykladowca_Form::dgPOKAZGRUPYGRUPY_CellClick);
				 this->dgPOKAZGRUPYGRUPY->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Wykladowca_Form::dgPOKAZGRUPYGRUPY_CellContentClick);
				 // 
				 // btnPOKAZGRUPYGRUPY
				 // 
				 this->btnPOKAZGRUPYGRUPY->Location = System::Drawing::Point(26, 462);
				 this->btnPOKAZGRUPYGRUPY->Margin = System::Windows::Forms::Padding(2);
				 this->btnPOKAZGRUPYGRUPY->Name = L"btnPOKAZGRUPYGRUPY";
				 this->btnPOKAZGRUPYGRUPY->Size = System::Drawing::Size(117, 58);
				 this->btnPOKAZGRUPYGRUPY->TabIndex = 0;
				 this->btnPOKAZGRUPYGRUPY->Text = L"Pokaz Grupy";
				 this->btnPOKAZGRUPYGRUPY->UseVisualStyleBackColor = true;
				 this->btnPOKAZGRUPYGRUPY->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnPOKAZGRUPYGRUPY_Click);
				 // 
				 // PraceDomowe
				 // 
				 this->PraceDomowe->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->PraceDomowe->Controls->Add(this->btnDOWNLOAD);
				 this->PraceDomowe->Controls->Add(this->dgPLIKI);
				 this->PraceDomowe->Controls->Add(this->btnSubmitOcena);
				 this->PraceDomowe->Controls->Add(this->lbOcenaOsoba);
				 this->PraceDomowe->Controls->Add(this->boxOcena);
				 this->PraceDomowe->Controls->Add(this->lbOsobaC);
				 this->PraceDomowe->Controls->Add(this->lbOsoba);
				 this->PraceDomowe->Controls->Add(this->lbCONTENTC);
				 this->PraceDomowe->Controls->Add(this->lbCONTENT);
				 this->PraceDomowe->Controls->Add(this->lbTITLEC);
				 this->PraceDomowe->Controls->Add(this->lbTITLE);
				 this->PraceDomowe->Controls->Add(this->dgtmp);
				 this->PraceDomowe->Controls->Add(this->btnPOKAZPRACE);
				 this->PraceDomowe->Controls->Add(this->dgPOKAZPRACE);
				 this->PraceDomowe->Location = System::Drawing::Point(4, 25);
				 this->PraceDomowe->Margin = System::Windows::Forms::Padding(2);
				 this->PraceDomowe->Name = L"PraceDomowe";
				 this->PraceDomowe->Padding = System::Windows::Forms::Padding(2);
				 this->PraceDomowe->Size = System::Drawing::Size(786, 545);
				 this->PraceDomowe->TabIndex = 1;
				 this->PraceDomowe->Text = L"Prace domowe";
				 // 
				 // btnDOWNLOAD
				 // 
				 this->btnDOWNLOAD->Location = System::Drawing::Point(203, 473);
				 this->btnDOWNLOAD->Name = L"btnDOWNLOAD";
				 this->btnDOWNLOAD->Size = System::Drawing::Size(221, 67);
				 this->btnDOWNLOAD->TabIndex = 13;
				 this->btnDOWNLOAD->Text = L"Pobierz pliki";
				 this->btnDOWNLOAD->UseVisualStyleBackColor = true;
				 // 
				 // dgPLIKI
				 // 
				 this->dgPLIKI->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dgPLIKI->Location = System::Drawing::Point(6, 235);
				 this->dgPLIKI->Name = L"dgPLIKI";
				 this->dgPLIKI->Size = System::Drawing::Size(418, 232);
				 this->dgPLIKI->TabIndex = 12;
				 // 
				 // btnSubmitOcena
				 // 
				 this->btnSubmitOcena->Location = System::Drawing::Point(532, 357);
				 this->btnSubmitOcena->Margin = System::Windows::Forms::Padding(2);
				 this->btnSubmitOcena->Name = L"btnSubmitOcena";
				 this->btnSubmitOcena->Size = System::Drawing::Size(167, 52);
				 this->btnSubmitOcena->TabIndex = 11;
				 this->btnSubmitOcena->Text = L"ZatwierdŸ";
				 this->btnSubmitOcena->UseVisualStyleBackColor = true;
				 this->btnSubmitOcena->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnSubmitOcena_Click);
				 // 
				 // lbOcenaOsoba
				 // 
				 this->lbOcenaOsoba->AutoSize = true;
				 this->lbOcenaOsoba->Location = System::Drawing::Point(592, 281);
				 this->lbOcenaOsoba->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbOcenaOsoba->Name = L"lbOcenaOsoba";
				 this->lbOcenaOsoba->Size = System::Drawing::Size(50, 17);
				 this->lbOcenaOsoba->TabIndex = 10;
				 this->lbOcenaOsoba->Text = L"Ocena";
				 // 
				 // boxOcena
				 // 
				 this->boxOcena->FormattingEnabled = true;
				 this->boxOcena->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"5", L"4,5", L"4", L"3,5", L"3", L"2,5", L"2" });
				 this->boxOcena->Location = System::Drawing::Point(566, 300);
				 this->boxOcena->Margin = System::Windows::Forms::Padding(2);
				 this->boxOcena->Name = L"boxOcena";
				 this->boxOcena->Size = System::Drawing::Size(92, 24);
				 this->boxOcena->TabIndex = 9;
				 // 
				 // lbOsobaC
				 // 
				 this->lbOsobaC->AutoSize = true;
				 this->lbOsobaC->Location = System::Drawing::Point(515, 245);
				 this->lbOsobaC->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbOsobaC->MinimumSize = System::Drawing::Size(200, 0);
				 this->lbOsobaC->Name = L"lbOsobaC";
				 this->lbOsobaC->Size = System::Drawing::Size(200, 17);
				 this->lbOsobaC->TabIndex = 8;
				 this->lbOsobaC->Text = L"Nikt";
				 this->lbOsobaC->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				 // 
				 // lbOsoba
				 // 
				 this->lbOsoba->AutoSize = true;
				 this->lbOsoba->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
				 this->lbOsoba->Location = System::Drawing::Point(540, 204);
				 this->lbOsoba->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbOsoba->Name = L"lbOsoba";
				 this->lbOsoba->Size = System::Drawing::Size(157, 25);
				 this->lbOsoba->TabIndex = 7;
				 this->lbOsoba->Text = L"Wybrana osoba:";
				 // 
				 // lbCONTENTC
				 // 
				 this->lbCONTENTC->AutoSize = true;
				 this->lbCONTENTC->Location = System::Drawing::Point(467, 85);
				 this->lbCONTENTC->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbCONTENTC->MaximumSize = System::Drawing::Size(300, 0);
				 this->lbCONTENTC->MinimumSize = System::Drawing::Size(300, 0);
				 this->lbCONTENTC->Name = L"lbCONTENTC";
				 this->lbCONTENTC->Size = System::Drawing::Size(300, 17);
				 this->lbCONTENTC->TabIndex = 6;
				 this->lbCONTENTC->Text = L"          ";
				 this->lbCONTENTC->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				 // 
				 // lbCONTENT
				 // 
				 this->lbCONTENT->AutoSize = true;
				 this->lbCONTENT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
				 this->lbCONTENT->Location = System::Drawing::Point(580, 62);
				 this->lbCONTENT->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbCONTENT->Name = L"lbCONTENT";
				 this->lbCONTENT->Size = System::Drawing::Size(68, 25);
				 this->lbCONTENT->TabIndex = 5;
				 this->lbCONTENT->Text = L"Treœæ:";
				 // 
				 // lbTITLEC
				 // 
				 this->lbTITLEC->AutoSize = true;
				 this->lbTITLEC->Location = System::Drawing::Point(467, 37);
				 this->lbTITLEC->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbTITLEC->MaximumSize = System::Drawing::Size(300, 0);
				 this->lbTITLEC->MinimumSize = System::Drawing::Size(300, 0);
				 this->lbTITLEC->Name = L"lbTITLEC";
				 this->lbTITLEC->Size = System::Drawing::Size(300, 17);
				 this->lbTITLEC->TabIndex = 4;
				 this->lbTITLEC->Text = L"     ";
				 this->lbTITLEC->TextAlign = System::Drawing::ContentAlignment::TopCenter;
				 // 
				 // lbTITLE
				 // 
				 this->lbTITLE->AutoSize = true;
				 this->lbTITLE->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
				 this->lbTITLE->Location = System::Drawing::Point(580, 5);
				 this->lbTITLE->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lbTITLE->Name = L"lbTITLE";
				 this->lbTITLE->Size = System::Drawing::Size(61, 25);
				 this->lbTITLE->TabIndex = 3;
				 this->lbTITLE->Text = L"Tytu³:";
				 // 
				 // dgtmp
				 // 
				 this->dgtmp->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dgtmp->Location = System::Drawing::Point(780, 539);
				 this->dgtmp->Margin = System::Windows::Forms::Padding(2);
				 this->dgtmp->Name = L"dgtmp";
				 this->dgtmp->RowTemplate->Height = 24;
				 this->dgtmp->Size = System::Drawing::Size(8, 9);
				 this->dgtmp->TabIndex = 2;
				 // 
				 // btnPOKAZPRACE
				 // 
				 this->btnPOKAZPRACE->Location = System::Drawing::Point(6, 470);
				 this->btnPOKAZPRACE->Margin = System::Windows::Forms::Padding(2);
				 this->btnPOKAZPRACE->Name = L"btnPOKAZPRACE";
				 this->btnPOKAZPRACE->Size = System::Drawing::Size(192, 71);
				 this->btnPOKAZPRACE->TabIndex = 1;
				 this->btnPOKAZPRACE->Text = L"Poka¿ prace domowe";
				 this->btnPOKAZPRACE->UseVisualStyleBackColor = true;
				 this->btnPOKAZPRACE->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnPOKAZPRACE_Click);
				 // 
				 // dgPOKAZPRACE
				 // 
				 this->dgPOKAZPRACE->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
				 this->dgPOKAZPRACE->Location = System::Drawing::Point(4, 5);
				 this->dgPOKAZPRACE->Margin = System::Windows::Forms::Padding(2);
				 this->dgPOKAZPRACE->Name = L"dgPOKAZPRACE";
				 this->dgPOKAZPRACE->RowTemplate->Height = 24;
				 this->dgPOKAZPRACE->Size = System::Drawing::Size(420, 224);
				 this->dgPOKAZPRACE->TabIndex = 0;
				 this->dgPOKAZPRACE->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Wykladowca_Form::dgPOKAZPRACE_CellClick);
				 // 
				 // Profil
				 // 
				 this->Profil->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->Profil->Controls->Add(this->lbProfilEmail);
				 this->Profil->Controls->Add(this->lbProfilNazwisko);
				 this->Profil->Controls->Add(this->lbProfilImie);
				 this->Profil->Controls->Add(this->label8);
				 this->Profil->Controls->Add(this->label7);
				 this->Profil->Controls->Add(this->label6);
				 this->Profil->Location = System::Drawing::Point(4, 25);
				 this->Profil->Margin = System::Windows::Forms::Padding(2);
				 this->Profil->Name = L"Profil";
				 this->Profil->Size = System::Drawing::Size(786, 545);
				 this->Profil->TabIndex = 2;
				 this->Profil->Text = L"Profil";
				 // 
				 // DodajPracedomowa
				 // 
				 this->DodajPracedomowa->BackColor = System::Drawing::SystemColors::InactiveCaption;
				 this->DodajPracedomowa->Controls->Add(this->button1);
				 this->DodajPracedomowa->Controls->Add(this->contentBox);
				 this->DodajPracedomowa->Controls->Add(this->label5);
				 this->DodajPracedomowa->Controls->Add(this->timePicker);
				 this->DodajPracedomowa->Controls->Add(this->label4);
				 this->DodajPracedomowa->Controls->Add(this->titleBox);
				 this->DodajPracedomowa->Controls->Add(this->label3);
				 this->DodajPracedomowa->Controls->Add(this->label2);
				 this->DodajPracedomowa->Controls->Add(this->combobox1);
				 this->DodajPracedomowa->Location = System::Drawing::Point(4, 25);
				 this->DodajPracedomowa->Margin = System::Windows::Forms::Padding(2);
				 this->DodajPracedomowa->Name = L"DodajPracedomowa";
				 this->DodajPracedomowa->Padding = System::Windows::Forms::Padding(2);
				 this->DodajPracedomowa->Size = System::Drawing::Size(786, 545);
				 this->DodajPracedomowa->TabIndex = 3;
				 this->DodajPracedomowa->Text = L"Dodaj prace domow¹";
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(258, 481);
				 this->button1->Margin = System::Windows::Forms::Padding(2);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(264, 52);
				 this->button1->TabIndex = 8;
				 this->button1->Text = L"Dodaj";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &Wykladowca_Form::button1_Click);
				 // 
				 // contentBox
				 // 
				 this->contentBox->Location = System::Drawing::Point(109, 245);
				 this->contentBox->Margin = System::Windows::Forms::Padding(2);
				 this->contentBox->Name = L"contentBox";
				 this->contentBox->Size = System::Drawing::Size(565, 216);
				 this->contentBox->TabIndex = 7;
				 this->contentBox->Text = L"";
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(332, 174);
				 this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(124, 17);
				 this->label5->TabIndex = 6;
				 this->label5->Text = L"Termin oddawania";
				 // 
				 // timePicker
				 // 
				 this->timePicker->Location = System::Drawing::Point(304, 202);
				 this->timePicker->Margin = System::Windows::Forms::Padding(2);
				 this->timePicker->Name = L"timePicker";
				 this->timePicker->Size = System::Drawing::Size(164, 23);
				 this->timePicker->TabIndex = 5;
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(369, 132);
				 this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(39, 17);
				 this->label4->TabIndex = 4;
				 this->label4->Text = L"Tytu³";
				 // 
				 // titleBox
				 // 
				 this->titleBox->Location = System::Drawing::Point(304, 150);
				 this->titleBox->Margin = System::Windows::Forms::Padding(2);
				 this->titleBox->Name = L"titleBox";
				 this->titleBox->Size = System::Drawing::Size(164, 23);
				 this->titleBox->TabIndex = 3;
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
				 this->label3->Location = System::Drawing::Point(145, 0);
				 this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(532, 63);
				 this->label3->TabIndex = 2;
				 this->label3->Text = L"Nowa praca domowa";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(346, 88);
				 this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(100, 17);
				 this->label2->TabIndex = 1;
				 this->label2->Text = L"Wybierz grupe";
				 // 
				 // combobox1
				 // 
				 this->combobox1->FormattingEnabled = true;
				 this->combobox1->Location = System::Drawing::Point(304, 106);
				 this->combobox1->Margin = System::Windows::Forms::Padding(2);
				 this->combobox1->Name = L"combobox1";
				 this->combobox1->Size = System::Drawing::Size(164, 24);
				 this->combobox1->TabIndex = 0;
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(16, 14);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(37, 17);
				 this->label6->TabIndex = 0;
				 this->label6->Text = L"Imie:";
				 this->label6->Click += gcnew System::EventHandler(this, &Wykladowca_Form::label6_Click);
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(16, 47);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(75, 17);
				 this->label7->TabIndex = 1;
				 this->label7->Text = L"Nazwisko: ";
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(16, 78);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(50, 17);
				 this->label8->TabIndex = 2;
				 this->label8->Text = L"Email: ";
				 // 
				 // lbProfilImie
				 // 
				 this->lbProfilImie->AutoSize = true;
				 this->lbProfilImie->Location = System::Drawing::Point(103, 14);
				 this->lbProfilImie->MinimumSize = System::Drawing::Size(150, 0);
				 this->lbProfilImie->Name = L"lbProfilImie";
				 this->lbProfilImie->Size = System::Drawing::Size(150, 17);
				 this->lbProfilImie->TabIndex = 3;
				 this->lbProfilImie->Text = L" ";
				 this->lbProfilImie->Click += gcnew System::EventHandler(this, &Wykladowca_Form::lbProfilImie_Click);
				 // 
				 // lbProfilNazwisko
				 // 
				 this->lbProfilNazwisko->AutoSize = true;
				 this->lbProfilNazwisko->Location = System::Drawing::Point(103, 47);
				 this->lbProfilNazwisko->MinimumSize = System::Drawing::Size(150, 0);
				 this->lbProfilNazwisko->Name = L"lbProfilNazwisko";
				 this->lbProfilNazwisko->Size = System::Drawing::Size(150, 17);
				 this->lbProfilNazwisko->TabIndex = 4;
				 this->lbProfilNazwisko->Text = L" ";
				 // 
				 // lbProfilEmail
				 // 
				 this->lbProfilEmail->AutoSize = true;
				 this->lbProfilEmail->Location = System::Drawing::Point(103, 78);
				 this->lbProfilEmail->MinimumSize = System::Drawing::Size(150, 0);
				 this->lbProfilEmail->Name = L"lbProfilEmail";
				 this->lbProfilEmail->Size = System::Drawing::Size(150, 17);
				 this->lbProfilEmail->TabIndex = 5;
				 this->lbProfilEmail->Text = L" ";
				 // 
				 // Wykladowca_Form
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(812, 612);
				 this->Controls->Add(this->tabControl1);
				 this->Controls->Add(this->btnWYLOGUJ);
				 this->Controls->Add(this->dateTimePicker1);
				 this->Controls->Add(this->lblAdmin);
				 this->Controls->Add(this->label1);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Margin = System::Windows::Forms::Padding(2);
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"Wykladowca_Form";
				 this->Text = L"Wykladowca";
				 this->Load += gcnew System::EventHandler(this, &Wykladowca_Form::Wykladowca_Form_Load);
				 this->tabControl1->ResumeLayout(false);
				 this->Grupy->ResumeLayout(false);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPOKAZGRUPYGRUPY))->EndInit();
				 this->PraceDomowe->ResumeLayout(false);
				 this->PraceDomowe->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPLIKI))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgtmp))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPOKAZPRACE))->EndInit();
				 this->Profil->ResumeLayout(false);
				 this->Profil->PerformLayout();
				 this->DodajPracedomowa->ResumeLayout(false);
				 this->DodajPracedomowa->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
			 /*
				 OWN FUNCTIONS
			 */



	private: void pokaz_uzytkownikow(System::Windows::Forms::DataGridView^ siatka)
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Numer_Grupy , Informacje FROM grupy WHERE  idgrupy in (SELECT  idgrupy FROM grupy_uzytkownikow WHERE iduzytkownika='" + this->id_wykladowca + "');", laczbaze);

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
		//siatka->Columns[0]->Visible = false;
	//	siatka->Columns[7]->Visible = false;
	}

	private: void pokazdane_uzytkownika(System::Windows::Forms::DataGridView^ siatka, int x)
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT * FROM uzytkownicy WHERE  iduzytkownicy in (SELECT  iduzytkownika FROM grupy_uzytkownikow WHERE idgrupy='" + x + "');", laczbaze);

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
		siatka->Columns[6]->Visible = false;
   //	siatka->Columns[7]->Visible = false;
	}

			 /////////////////////////////////////////////////////////////////////////////////////////////////////
			 /////////////////////////////////////////////////////////////////////////////////////////////////////


	private: System::Void Wykladowca_Form_Load(System::Object^  sender, System::EventArgs^  e)
	{
		this->lblAdmin->Text = this->Admin_Name;
		pokaz_uzytkownikow(dgPOKAZGRUPYGRUPY);
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

	private: System::Void btnPOKAZGRUPYGRUPY_Click(System::Object^  sender, System::EventArgs^  e)
	{
		pokaz_uzytkownikow(dgPOKAZGRUPYGRUPY);
		id_rekordu = -1;
		
	}


	private: System::Void dgPOKAZGRUPYGRUPY_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {

		if (e->RowIndex >= 0)
		{
			id_rekordu = Convert::ToInt32(dgPOKAZGRUPYGRUPY->Rows[e->RowIndex]->Cells[0]->Value);
		}
	}
	private: System::Void btnPokazCzlonkow_Click(System::Object^  sender, System::EventArgs^  e) {
		if(id_rekordu > -1)pokazdane_uzytkownika(dgPOKAZGRUPYGRUPY, id_wykladowca);
		dgPOKAZGRUPYGRUPY->Columns[0]->Visible = false;
		dgPOKAZGRUPYGRUPY->Columns[5]->Visible = false;
	}



	private: System::Void dgPOKAZGRUPYGRUPY_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) 
	{
		if (e->RowIndex >= 0)
			{
				id_rekordu = Convert::ToInt32(dgPOKAZGRUPYGRUPY->Rows[e->RowIndex]->Cells[0]->Value);
			}
}


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	//IF U WANT TO DECREMENT AUTOINCREMENT VALUE FROM MYSQL => ALTER TABLE `blind_bank_db`.`uzytkownicy` AUTO_INCREMENT = 8;
	MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
	MySqlCommand^ polecenie = laczbaze->CreateCommand();
	MySqlTransaction^ transakcja;

	laczbaze->Open();
	transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

	polecenie->Connection = laczbaze;
	polecenie->Transaction = transakcja;

	//CHECKING IF THE USER EXIST IN DB OR NOT
	if (titleBox->Text=="" || contentBox->Text == "" || combobox1->SelectedValue=="")
	{
		MessageBox::Show("Sprawdz czy poprawnie wprowadziles wszystkie dane!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
	}
	else
	{
		try
		{
			//polecenie->CommandText = "INSERT INTO uzytkownicy SET Imie_Uzytkownika = '" + txtIMIE->Text + "' , Nazwisko_Uzytkownika = '" + txtNAZWISKO->Text + "' , Unique_Index_Number = '" + txtNUMERINDEXU->Text + "', Email_Uzytkownika = '" + txtEMAIL->Text + "', Haslo_Uzytkownika = '" + txtHASLO->Text + "', rola_idrola = '" + txtHASLO->Text + "';";
			polecenie->CommandText = "INSERT INTO `praca_domowa`(`pk`, `id_grupy`, `title`, `contents`, `add_date`, `expire_date`) VALUES (NULL," + idgrup[combobox1->SelectedIndex] + ",'" + titleBox->Text + "','" + contentBox->Text + "',CURRENT_TIMESTAMP, DATE '"+timePicker->Value.Year+"/"+timePicker->Value.Month+"/"+timePicker->Value.Day+"')";
			polecenie->ExecuteNonQuery();
			transakcja->Commit();

			laczbaze = gcnew MySqlConnection(konfiguracja);
			polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja2;

			laczbaze->Open();
			transakcja2 = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja2;


			//Pobierz id ostatnio dodanej pd
			//polecenie->CommandText = "SELECT pk FROM praca_domowa ORDER BY add_date desc LIMIT 1";
			//polecenie->ExecuteNonQuery();
			MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT pk FROM praca_domowa ORDER BY add_date desc LIMIT 1",laczbaze);
			//Initialize Ocena table with defaults
			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;

			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			dgtmp->DataSource = zrodlo;

			int idpd = Convert::ToInt32(dgtmp->Rows[0]->Cells[0]->Value);

			//Pobierz uzytkownikow tej grupy
			zapytanie =  gcnew MySqlCommand("SELECT iduzytkownicy FROM uzytkownicy, grupy_uzytkownikow g WHERE iduzytkownicy = g.iduzytkownika and g.idgrupy = "+ idgrup[combobox1->SelectedIndex]+" and iduzytkownicy != "+id_wykladowca+" ", laczbaze);
			MySqlDataAdapter^ moja2 = gcnew MySqlDataAdapter();
			moja2->SelectCommand = zapytanie;

			DataTable^ tabela2 = gcnew DataTable();
			moja2->Fill(tabela2);

			BindingSource^ zrodlo2 = gcnew BindingSource();
			zrodlo2->DataSource = tabela2;
			dgtmp->DataSource = zrodlo2;

			int ilu = Convert::ToInt32(dgtmp->RowCount)-1;

			for (int i = 0; i < ilu; ++i)
			{
				//MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
				polecenie->CommandText = "INSERT INTO `Ocena`(`id_osoby`, `id_pd`) VALUES ("+Convert::ToInt32(dgtmp->Rows[i]->Cells[0]->Value)+","+ Convert::ToInt32(idpd)+")";
				//zapytanie = gcnew MySqlCommand( "INSERT INTO `Ocena`(`id_osoby`, `id_pd`) VALUES ("+Convert::ToInt32(dgtmp->Rows[i]->Cells[0]->Value)+","+ Convert::ToInt32(idpd)+")", laczbaze);
				polecenie->ExecuteNonQuery();
				//laczbaze->Close();
			}
			MessageBox::Show("Dodano prace domowa!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			titleBox->Text = "";
			contentBox->Text = "";
			transakcja2->Commit();
			laczbaze->Close();
		}
		catch (Exception^ komunikat)
		{
			//MessageBox::Show("Cos poszlo nie tak! Komunikat: " + komunikat + " !", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			MessageBox::Show("Cos poszlo nie tak!", "Uwaga!", MessageBoxButtons::OK, MessageBoxIcon::Question);
			MessageBox::Show(komunikat->Message);
			transakcja->Rollback();
		}
		laczbaze->Close();
	}
}
	private: System::Void btnPOKAZPRACE_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
		MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT pk, idgrupy, Numer_Grupy as 'Nr. Grupy',Informacje, title as 'Tytu³', contents as 'Treœæ', add_date as 'Data dodania', expire_date as 'Data oddania'  FROM praca_domowa, grupy WHERE id_grupy in (SELECT idgrupy FROM grupy_uzytkownikow WHERE iduzytkownika='"+id_wykladowca+"') and praca_domowa.id_grupy = grupy.idgrupy ;", laczbaze);

		try {

			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;

			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			dgPOKAZPRACE->DataSource = zrodlo;

			laczbaze->Close();
		}
		catch (Exception^ komunikat)
		{
			MessageBox::Show(komunikat->Message);
		}
		dgPOKAZPRACE->Columns[0]->Visible = false;
		dgPOKAZPRACE->Columns[1]->Visible = false;
		//	siatka->Columns[7]->Visible = false;

		//dgPOKAZPRACE->Columns[1].
		taczable = true;
		lbCONTENTC->Text = " ";
		lbTITLEC->Text = " ";
		
	}
	private: System::Void dgPOKAZPRACE_CellClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if (taczable)
		{
			
			if (e->RowIndex >= 0 && dgPOKAZPRACE->Rows[e->RowIndex]->Cells[0]->Value != dgPOKAZPRACE->Rows[e->RowIndex]->Cells[1]->Value)
			{
				id_rekordu = Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[0]->Value);
			

			lbCONTENTC->Text = Convert::ToString(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[5]->Value);
			lbTITLEC->Text = Convert::ToString(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[4]->Value);

			MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as 'Imie', Nazwisko_Uzytkownika as 'Nazwisko', ocena as 'Ocena' FROM uzytkownicy, Ocena, grupy_uzytkownikow g, praca_domowa WHERE Ocena.id_pd ='" + id_rekordu + "' and praca_domowa.id_grupy = '" + Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[1]->Value) + "' and g.idgrupy = praca_domowa.id_grupy and g.iduzytkownika = iduzytkownicy and g.iduzytkownika != "+id_wykladowca+" and Ocena.id_osoby = iduzytkownicy  ;", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT iduzytkownicy, Imie_Uzytkownika as 'Imie', Nazwisko_Uzytkownika as 'Nazwisko', ocena as 'Ocena' FROM uzytkownicy, Ocena, praca_domowa WHERE Ocena.id_pd ='"+id_rekordu+"' and praca_domowa.id_grupy = '" + Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[1]->Value) + "' and uzytkownicy.iduzytkownicy != " + id_wykladowca + " and Ocena.id_osoby = iduzytkownicy and Ocena.id_pd = praca_domowa.pk;", laczbaze);

			MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
			moja->SelectCommand = zapytanie;

			DataTable^ tabela = gcnew DataTable();
			moja->Fill(tabela);

			BindingSource^ zrodlo = gcnew BindingSource();
			zrodlo->DataSource = tabela;
			dgPOKAZPRACE->DataSource = zrodlo;
			taczable = false;
			dgPOKAZPRACE->Columns[0]->Visible = false;
			id_osoby = Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[0]->Value);
			laczbaze->Close();

			}
		}
		else
		{
			id_osoby = Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[0]->Value);
			lbOsobaC->Text = Convert::ToString(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[1]->Value) +" "+ Convert::ToString(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[2]->Value);
			{
				MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
				//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as Imie, Nazwisko_Uzytkownika as Nazwisko , Unique_Index_Number as Numer Indexu, Email_Uzytkownika as E-mail, Haslo_Uzytkownika as Haslo, rola_idrola as Rola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
				//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika, Nazwisko_Uzytkownika, Unique_Index_Number, Email_Uzytkownika, Haslo_Uzytkownika , rola_idrola FROM blind_bank_db.uzytkownicy ORDER BY iduzytkownicy;", laczbaze);
				//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT Imie_Uzytkownika as 'Imie', Nazwisko_Uzytkownika as 'Nazwisko', ocena as 'Ocena' FROM uzytkownicy, Ocena, grupy_uzytkownikow g, praca_domowa WHERE Ocena.id_pd ='" + id_rekordu + "' and praca_domowa.id_grupy = '" + Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[1]->Value) + "' and g.idgrupy = praca_domowa.id_grupy and g.iduzytkownika = iduzytkownicy and g.iduzytkownika != "+id_wykladowca+" and Ocena.id_osoby = iduzytkownicy  ;", laczbaze);
				MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT nazwa, plik FROM pliki WHERE pliki.id_pd ='" + id_rekordu + "' and pliki.id_osoby = '" + id_osoby + "'", laczbaze);

				MySqlDataAdapter^ moja = gcnew MySqlDataAdapter();
				moja->SelectCommand = zapytanie;

				DataTable^ tabela = gcnew DataTable();
				moja->Fill(tabela);

				BindingSource^ zrodlo = gcnew BindingSource();
				zrodlo->DataSource = tabela;
				dgPLIKI->DataSource = zrodlo;
				//taczable = false;
				//dgPLIKI->Columns[0]->Visible = false;
				//id_osoby = Convert::ToInt32(dgPOKAZPRACE->Rows[e->RowIndex]->Cells[0]->Value);
				laczbaze->Close();

				nazwapliku.clear();
				calyplik.clear();
				//Wczytanie nazw i zawartoœci plików
				for (size_t i = 0; i < dgPLIKI->RowCount - 1; ++i)
				{
					nazwapliku.push_back(Convert::ToString(dgPLIKI->Rows[i]->Cells[0]->Value));
					calyplik.push_back(Convert::ToString(dgPLIKI->Rows[i]->Cells[1]->Value));
				}
			}
		}
		
	}

private: System::Void btnSubmitOcena_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (id_osoby > -1)
		{
			float ocena;
			switch (Convert::ToInt32(boxOcena->SelectedIndex))
			{
			case 0:
				ocena = 5.f;
				break;
			case 1:
				ocena = 4.5f;
				break;
			case 2:
				ocena = 4.f;
				break;
			case 3:
				ocena = 3.5f;
				break;
			case 4:
				ocena = 3.f;
				break;
			case 5:
				ocena = 2.5f;
				break;
			case 6:
				ocena = 2.f;
				break;
			}
			//MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("UPDATE Ocena SET ocena = '"+ocena+"' WHERE id_osoby = '"+id_osoby+"' and id_pd = '"+id_rekordu+"'", laczbaze);
			MySqlConnection^ laczbaze = gcnew MySqlConnection(konfiguracja);
			MySqlCommand^ polecenie = laczbaze->CreateCommand();
			MySqlTransaction^ transakcja;

			laczbaze->Open();
			transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

			polecenie->Connection = laczbaze;
			polecenie->Transaction = transakcja;

			polecenie->CommandText = "UPDATE Ocena SET ocena = '" + ocena + "' WHERE id_osoby = '" + id_osoby + "' and id_pd = '" + id_rekordu + "'";
			polecenie->ExecuteNonQuery();
			transakcja->Commit();
			MessageBox::Show("Wystawiono ocene", "Komunikat", MessageBoxButtons::OK, MessageBoxIcon::Information);

			//transakcja->Cl
		}
	}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void lbProfilImie_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
