#pragma once
//include Student_Form and Lecturer_Form too
#include "Admin_Form.h"
#include "Student_Form.h"
#include "Wykladowca_Form.h"
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
	/// Summary for Logowanie
	/// </summary>
	public ref class Logowanie : public System::Windows::Forms::Form
	{
	public:
		Logowanie(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		static void Load_Form()
		{
			Logowanie^ program = gcnew Logowanie();
			program->ShowDialog();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Logowanie()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  txtHaslo;
	private: System::Windows::Forms::TextBox^  txtIndex;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  btnZaloguj;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  txtUNIQUEINDEXNUMBER;


	private: System::Windows::Forms::TextBox^  txtEMAIL;

	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  txtNOWEHASLO;
	private: System::Windows::Forms::Button^  btnZMIENHASLO;



	protected:

	protected:










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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtHaslo = (gcnew System::Windows::Forms::TextBox());
			this->txtIndex = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->btnZaloguj = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtNOWEHASLO = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtUNIQUEINDEXNUMBER = (gcnew System::Windows::Forms::TextBox());
			this->txtEMAIL = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnZMIENHASLO = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 4);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(558, 537);
			this->tabControl1->TabIndex = 6;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::SystemColors::Highlight;
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->txtHaslo);
			this->tabPage1->Controls->Add(this->txtIndex);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->btnZaloguj);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(550, 508);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Logowanie";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(230, 166);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 31);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Haslo";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(190, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(165, 31);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Adres e-mail";
			// 
			// txtHaslo
			// 
			this->txtHaslo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtHaslo->Location = System::Drawing::Point(90, 216);
			this->txtHaslo->Name = L"txtHaslo";
			this->txtHaslo->PasswordChar = '*';
			this->txtHaslo->Size = System::Drawing::Size(367, 38);
			this->txtHaslo->TabIndex = 9;
			this->txtHaslo->Text = L"1234";
			// 
			// txtIndex
			// 
			this->txtIndex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtIndex->Location = System::Drawing::Point(90, 90);
			this->txtIndex->Name = L"txtIndex";
			this->txtIndex->Size = System::Drawing::Size(367, 38);
			this->txtIndex->TabIndex = 8;
			this->txtIndex->Text = L"kacper@gmail.com";
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(191, 397);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 58);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Zamknij";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Logowanie::button2_Click_1);
			// 
			// btnZaloguj
			// 
			this->btnZaloguj->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnZaloguj->Location = System::Drawing::Point(191, 321);
			this->btnZaloguj->Name = L"btnZaloguj";
			this->btnZaloguj->Size = System::Drawing::Size(164, 58);
			this->btnZaloguj->TabIndex = 6;
			this->btnZaloguj->Text = L"Zaloguj";
			this->btnZaloguj->UseVisualStyleBackColor = true;
			this->btnZaloguj->Click += gcnew System::EventHandler(this, &Logowanie::btnZaloguj_Click_1);
			// 
			// tabPage2
			// 
			this->tabPage2->BackColor = System::Drawing::SystemColors::Highlight;
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Controls->Add(this->txtNOWEHASLO);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->txtUNIQUEINDEXNUMBER);
			this->tabPage2->Controls->Add(this->txtEMAIL);
			this->tabPage2->Controls->Add(this->button1);
			this->tabPage2->Controls->Add(this->btnZMIENHASLO);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(550, 508);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Zmiana Hasla";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(192, 215);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(161, 31);
			this->label5->TabIndex = 19;
			this->label5->Text = L"Nowe Haslo";
			// 
			// txtNOWEHASLO
			// 
			this->txtNOWEHASLO->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtNOWEHASLO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNOWEHASLO->Location = System::Drawing::Point(83, 260);
			this->txtNOWEHASLO->Name = L"txtNOWEHASLO";
			this->txtNOWEHASLO->PasswordChar = '*';
			this->txtNOWEHASLO->Size = System::Drawing::Size(367, 38);
			this->txtNOWEHASLO->TabIndex = 18;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(117, 119);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(295, 31);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Unikalny Numer Indexu";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(183, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(165, 31);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Adres e-mail";
			// 
			// txtUNIQUEINDEXNUMBER
			// 
			this->txtUNIQUEINDEXNUMBER->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtUNIQUEINDEXNUMBER->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->txtUNIQUEINDEXNUMBER->Location = System::Drawing::Point(83, 162);
			this->txtUNIQUEINDEXNUMBER->Name = L"txtUNIQUEINDEXNUMBER";
			this->txtUNIQUEINDEXNUMBER->PasswordChar = '*';
			this->txtUNIQUEINDEXNUMBER->Size = System::Drawing::Size(367, 38);
			this->txtUNIQUEINDEXNUMBER->TabIndex = 15;
			// 
			// txtEMAIL
			// 
			this->txtEMAIL->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtEMAIL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEMAIL->Location = System::Drawing::Point(83, 66);
			this->txtEMAIL->Name = L"txtEMAIL";
			this->txtEMAIL->Size = System::Drawing::Size(367, 38);
			this->txtEMAIL->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(184, 418);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(164, 58);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Zamknij";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Logowanie::button1_Click);
			// 
			// btnZMIENHASLO
			// 
			this->btnZMIENHASLO->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnZMIENHASLO->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnZMIENHASLO->Location = System::Drawing::Point(157, 339);
			this->btnZMIENHASLO->Name = L"btnZMIENHASLO";
			this->btnZMIENHASLO->Size = System::Drawing::Size(217, 58);
			this->btnZMIENHASLO->TabIndex = 12;
			this->btnZMIENHASLO->Text = L"Zmien Haslo";
			this->btnZMIENHASLO->UseVisualStyleBackColor = true;
			this->btnZMIENHASLO->Click += gcnew System::EventHandler(this, &Logowanie::btnZMIENHASLO_Click);
			// 
			// Logowanie
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 553);
			this->Controls->Add(this->tabControl1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Logowanie";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Logowanie";
			this->Load += gcnew System::EventHandler(this, &Logowanie::Logowanie_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		////ADD YOUR CODE HERE BELOW

		

	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e)
	{
		//Close the form
		if (MessageBox::Show("Czy na pewno chcesz zamknac aplikacje?", "Uwaga!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
		{
			this->Close();
		}
	}


	private: System::Void btnZaloguj_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
		if (SQL_CONFIGURATION::get_datasource() == "1")
		{
			MessageBox::Show("PROSZE UZUPELNIC POPRAWNE DANE LOGOWANIA DO BAZY DANYCH!!", "UWAGA!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			this->Close();
		}
		else
		{

			//Here add mysql reader
			//String^ konfiguracja = L"datasource=81.171.31.230;port=3306;username=blindbankdb;password=Qwerty123;database=blindbank_db";
			//String^ konfiguracja = L"datasource=81.171.31.230;port=3306;username=blindbankdb@127.0.0.1;password=Qwerty123;database=blindbank_db";
			//String^ konfiguracja = L"datasource=remotemysql.com;port=3306;username=aUy3ZvnM7k;password=wUMpRMvSyN;database=aUy3ZvnM7k";
			//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";

			MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
			//here for us we will be selecting the role, for example if role == "Administrator" open the administrator form
			//MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT uzytkownik_id FROM uzytkownik WHERE uzytkownik_nazwa = '" + txtIndex->Text + "' AND haslo = PASSWORD('" + txtHaslo->Text + "');", laczbaze);
			MySqlCommand^ zapytanie = gcnew MySqlCommand("SELECT rola_idrola FROM uzytkownicy WHERE Email_Uzytkownika = '" + txtIndex->Text + "' AND Haslo_Uzytkownika = '" + txtHaslo->Text + "';", laczbaze);
			MySqlDataReader^ odczytanie;

			try {
				laczbaze->Open();
				odczytanie = zapytanie->ExecuteReader();

				if (odczytanie->Read())
				{
					int id_rola = odczytanie->GetInt32(0);

					//below, change it to: ROLE == ADMINISTRATOR for example open the administrator form
					if (id_rola == 1)
					{
						odczytanie->Close();

						MySqlCommand^ zapytanie_admin_name = gcnew MySqlCommand("SELECT Imie_Uzytkownika FROM uzytkownicy WHERE Email_Uzytkownika = '" + txtIndex->Text + "';", laczbaze);
						odczytanie = zapytanie_admin_name->ExecuteReader();
						if (odczytanie->Read())
						{
							String^ Admin_Name = odczytanie->GetString(0);
							this->Visible = false;
							Admin_Form^ program = gcnew Admin_Form(id_rola, Admin_Name, this);
							program->ShowDialog();

						}
					}
					else if (id_rola == 2)
					{
						odczytanie->Close();

						MySqlCommand^ zapytanie_admin_name = gcnew MySqlCommand("SELECT Imie_Uzytkownika FROM uzytkownicy WHERE Email_Uzytkownika = '" + txtIndex->Text + "';", laczbaze);
						odczytanie = zapytanie_admin_name->ExecuteReader();

						if (odczytanie->Read())
						{
							String^ Admin_Name = odczytanie->GetString(0);
							this->Visible = false;
							odczytanie->Close();
							zapytanie_admin_name = gcnew MySqlCommand("SELECT iduzytkownicy FROM uzytkownicy WHERE Email_Uzytkownika = '" + txtIndex->Text + "';", laczbaze);
							odczytanie = zapytanie_admin_name->ExecuteReader();
							odczytanie->Read();
							int id = odczytanie->GetInt32(0);
							Wykladowca_Form^ program = gcnew Wykladowca_Form(id_rola, Admin_Name, id, this);
							program->ShowDialog();
						}

					}
					else if (id_rola == 3)
					{
						odczytanie->Close();

						MySqlCommand^ zapytanie_admin_name = gcnew MySqlCommand("SELECT Imie_Uzytkownika FROM uzytkownicy WHERE Email_Uzytkownika = '" + txtIndex->Text + "';", laczbaze);
						odczytanie = zapytanie_admin_name->ExecuteReader();
						if (odczytanie->Read())
						{
							String^ Admin_Name = odczytanie->GetString(0);
							this->Visible = false;

							odczytanie->Close();
							zapytanie_admin_name = gcnew MySqlCommand("SELECT iduzytkownicy FROM uzytkownicy WHERE Email_Uzytkownika = '" + txtIndex->Text + "';", laczbaze);
							odczytanie = zapytanie_admin_name->ExecuteReader();
							odczytanie->Read();
							int id = odczytanie->GetInt32(0);
							Student_Form^ program = gcnew Student_Form(id_rola, Admin_Name, id, this);
							program->ShowDialog();

						}
					}
				}
				else
				{
					MessageBox::Show("Bledna nazwa uzytkownika lub niepoprawne haslo", "UWAGA!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show(ex->Message);
			}
			laczbaze->Close();
		}
	}


	private: System::Void btnZMIENHASLO_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//Here add mysql reader
		//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=blind_bank_db";
		//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";

		MySqlConnection^ laczbaze = gcnew MySqlConnection(SQL_CONFIGURATION::get_konfiguracja());
		MySqlCommand^ polecenie = laczbaze->CreateCommand();
		MySqlTransaction^ transakcja;

		laczbaze->Open();
		transakcja = laczbaze->BeginTransaction(IsolationLevel::ReadCommitted);

		polecenie->Connection = laczbaze;

		polecenie->Transaction = transakcja;

		try
		{
			polecenie->CommandText = "UPDATE uzytkownicy SET Haslo_Uzytkownika = '" + txtNOWEHASLO->Text + "' WHERE Unique_Index_Number = '" + txtUNIQUEINDEXNUMBER->Text + "' AND Email_Uzytkownika = '" + txtEMAIL->Text + "';";
			polecenie->ExecuteNonQuery();

			transakcja->Commit();
			MessageBox::Show("Haslo Uzytkownika zostalo poprawnie zmienione", "UWAGA!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (...)
		{
			MessageBox::Show("Bledny adres e-mail lub niepoprawny numer indexu!", "UWAGA!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			transakcja->Rollback();
		}
		laczbaze->Close();
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		//Close the form
		this->Close();
	}


private: System::Void Logowanie_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}