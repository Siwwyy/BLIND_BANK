#pragma once
//#include "Logowanie.h"

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
			Logowanie_Form(_Form)
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
		String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=blind_bank_db";
		//String^ konfiguracja = L"datasource=localhost;port=3306;username=root;password=1234;database=gabinet";
		int role;
		String^ Admin_Name;
		System::Windows::Forms::Form ^ Logowanie_Form;



	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::Button^  btnWYLOGUJ;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
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
			this->dateTimePicker1->Location = System::Drawing::Point(819, 9);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(151, 26);
			this->dateTimePicker1->TabIndex = 7;
			this->dateTimePicker1->Value = System::DateTime(2019, 5, 2, 12, 16, 0, 0);
			// 
			// btnWYLOGUJ
			// 
			this->btnWYLOGUJ->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnWYLOGUJ->Location = System::Drawing::Point(672, 7);
			this->btnWYLOGUJ->Name = L"btnWYLOGUJ";
			this->btnWYLOGUJ->Size = System::Drawing::Size(141, 31);
			this->btnWYLOGUJ->TabIndex = 13;
			this->btnWYLOGUJ->Text = L"Wyloguj";
			this->btnWYLOGUJ->UseVisualStyleBackColor = true;
			this->btnWYLOGUJ->Click += gcnew System::EventHandler(this, &Wykladowca_Form::btnWYLOGUJ_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(445, 260);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Wykladowca_Form::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(549, 59);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 15;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// Wykladowca_Form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(982, 653);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
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
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Wykladowca_Form_Load(System::Object^  sender, System::EventArgs^  e)
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
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
