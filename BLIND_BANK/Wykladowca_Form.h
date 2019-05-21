#pragma once
//#include "Logowanie.h"
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

		Wykladowca_Form(const int role, String^ & Admin_Name,int a, System::Windows::Forms::Form ^ _Form) :
			role(role),
			Admin_Name(Admin_Name),
			Logowanie_Form(_Form),
			id_wykladowca(a)
		{
			InitializeComponent();

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
		//Here add mysql reader
		String^ konfiguracja = SQL_CONFIGURATION::get_konfiguracja();
	//	String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=blind_bank_db";
		//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";
		int role;
		String^ Admin_Name;
		System::Windows::Forms::Form ^ Logowanie_Form;
		int id_wykladowca;



	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Button^  btnWYLOGUJ;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  Grupy;
	private: System::Windows::Forms::TabPage^  PraceDomowe;
	private: System::Windows::Forms::TabPage^  Profil;
	private: System::Windows::Forms::Button^  btnPOKAZGRUPYGRUPY;
	private: System::Windows::Forms::DataGridView^  dgPOKAZGRUPYGRUPY;
















































































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
			this->dgPOKAZGRUPYGRUPY = (gcnew System::Windows::Forms::DataGridView());
			this->btnPOKAZGRUPYGRUPY = (gcnew System::Windows::Forms::Button());
			this->PraceDomowe = (gcnew System::Windows::Forms::TabPage());
			this->Profil = (gcnew System::Windows::Forms::TabPage());
			this->tabControl1->SuspendLayout();
			this->Grupy->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPOKAZGRUPYGRUPY))->BeginInit();
			this->SuspendLayout();
			// 
			// lblAdmin
			// 
			this->lblAdmin->AutoSize = true;
			this->lblAdmin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAdmin->Location = System::Drawing::Point(82, 9);
			this->lblAdmin->Name = L"lblAdmin";
			this->lblAdmin->Size = System::Drawing::Size(0, 29);
			this->lblAdmin->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 29);
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
			this->dateTimePicker1->Location = System::Drawing::Point(919, 6);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(151, 26);
			this->dateTimePicker1->TabIndex = 7;
			this->dateTimePicker1->Value = System::DateTime(2019, 5, 2, 12, 16, 0, 0);
			// 
			// btnWYLOGUJ
			// 
			this->btnWYLOGUJ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWYLOGUJ->Location = System::Drawing::Point(772, 4);
			this->btnWYLOGUJ->Name = L"btnWYLOGUJ";
			this->btnWYLOGUJ->Size = System::Drawing::Size(141, 31);
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
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->tabControl1->Location = System::Drawing::Point(12, 41);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1058, 707);
			this->tabControl1->TabIndex = 14;
			// 
			// Grupy
			// 
			this->Grupy->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Grupy->Controls->Add(this->dgPOKAZGRUPYGRUPY);
			this->Grupy->Controls->Add(this->btnPOKAZGRUPYGRUPY);
			this->Grupy->Location = System::Drawing::Point(4, 29);
			this->Grupy->Name = L"Grupy";
			this->Grupy->Padding = System::Windows::Forms::Padding(3);
			this->Grupy->Size = System::Drawing::Size(1050, 674);
			this->Grupy->TabIndex = 0;
			this->Grupy->Text = L"Grupy";
			// 
			// dgPOKAZGRUPYGRUPY
			// 
			this->dgPOKAZGRUPYGRUPY->AllowUserToAddRows = false;
			this->dgPOKAZGRUPYGRUPY->AllowUserToDeleteRows = false;
			this->dgPOKAZGRUPYGRUPY->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgPOKAZGRUPYGRUPY->Location = System::Drawing::Point(6, 6);
			this->dgPOKAZGRUPYGRUPY->Name = L"dgPOKAZGRUPYGRUPY";
			this->dgPOKAZGRUPYGRUPY->ReadOnly = true;
			this->dgPOKAZGRUPYGRUPY->RowTemplate->Height = 24;
			this->dgPOKAZGRUPYGRUPY->Size = System::Drawing::Size(1038, 342);
			this->dgPOKAZGRUPYGRUPY->TabIndex = 1;
			// 
			// btnPOKAZGRUPYGRUPY
			// 
			this->btnPOKAZGRUPYGRUPY->Location = System::Drawing::Point(45, 527);
			this->btnPOKAZGRUPYGRUPY->Name = L"btnPOKAZGRUPYGRUPY";
			this->btnPOKAZGRUPYGRUPY->Size = System::Drawing::Size(156, 72);
			this->btnPOKAZGRUPYGRUPY->TabIndex = 0;
			this->btnPOKAZGRUPYGRUPY->Text = L"Pokaz Grupy";
			this->btnPOKAZGRUPYGRUPY->UseVisualStyleBackColor = true;
			this->btnPOKAZGRUPYGRUPY->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnPOKAZGRUPYGRUPY_Click);
			// 
			// PraceDomowe
			// 
			this->PraceDomowe->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->PraceDomowe->Location = System::Drawing::Point(4, 29);
			this->PraceDomowe->Name = L"PraceDomowe";
			this->PraceDomowe->Padding = System::Windows::Forms::Padding(3);
			this->PraceDomowe->Size = System::Drawing::Size(1050, 674);
			this->PraceDomowe->TabIndex = 1;
			this->PraceDomowe->Text = L"Prace domowe";
			// 
			// Profil
			// 
			this->Profil->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->Profil->Location = System::Drawing::Point(4, 29);
			this->Profil->Name = L"Profil";
			this->Profil->Size = System::Drawing::Size(1050, 674);
			this->Profil->TabIndex = 2;
			this->Profil->Text = L"Profil";
			// 
			// Wykladowca_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1082, 753);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->btnWYLOGUJ);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->lblAdmin);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Wykladowca_Form";
			this->Text = L"Wykladowca";
			this->Load += gcnew System::EventHandler(this, &Wykladowca_Form::Wykladowca_Form_Load);
			this->tabControl1->ResumeLayout(false);
			this->Grupy->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgPOKAZGRUPYGRUPY))->EndInit();
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
		//pokaz_uzytkownikow(dgPOKAZGRUPYGRUPY);
	}

};
}
