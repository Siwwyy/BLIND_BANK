#ifndef _FTP_H_
#define _FTP_H_

#include <string>
#include <iostream>
#include <Windows.h>

namespace BLINDBANK {

	static int number = 0;
	static int number_folder = 0;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::IO;
	using namespace System::Text;

	public ref class _FTP
	{
	public:
		System::Void read_file_n(String^& x)
		{
			try
			{
				StreamReader^ reader = gcnew StreamReader(this->file_path);
				System::String^ line = "";
				line = reader->ReadLine();
				x += line + " ";
				//from_file += '\n';
				while (reader->EndOfStream != true)
				{
					line = reader->ReadLine();
					x += line + " ";
					//from_file += '\n';
				}
				reader->Close();
			}
			catch (Exception^ e)
			{
				Console::WriteLine(L"Exception: {0}", e->Message);
			}
		}
	private:

		System::String^ from_file;
		System::String^ file_path;
			
		System::Void read_file()
		{
			try
			{
				StreamReader^ reader = gcnew StreamReader(this->file_path);
				System::String^ line = "";
				line = reader->ReadLine();
				from_file += line;
				from_file += '\n';
				while (reader->EndOfStream != true)
				{
					line = reader->ReadLine();
					from_file += line;
					from_file += '\n';
				}
				reader->Close();
			}
			catch (Exception^ e)
			{
				Console::WriteLine(L"Exception: {0}", e->Message);
			}
		}


	public:
		_FTP():
			from_file("")
		{

		}

		_FTP(System::String^ file_path) :
			file_path(file_path),
			from_file("")
		{
			read_file();
		}

		static System::String^ read_configure_string(System::String^ file_path, const int line_number)
		{
			try
			{
				StreamReader^ reader = gcnew StreamReader(file_path);
				System::String^ line = "";
				static int i = 0;
				while (i <= 6)
				{
					line = "";
					line = reader->ReadLine();
					if (i == line_number)
					{
						i = 0;
						return line;
						break;
					}
					++i;
				}
				reader->Close();
			}
			catch (Exception^ e)
			{
				Console::WriteLine(L"Exception: {0}", e->Message);
			}
		}


		static System::Void write_to_file_DB(System::String^ file_path)
		{
			try
			{
				String^ file = "1";
				StreamWriter^ writer = gcnew StreamWriter(file_path);
				for (size_t i = 0; i < 1; ++i)
				{
					writer->Write(file[0]);
				}
				writer->Close();
			}
			catch (Exception^ e)
			{
				Console::WriteLine(L"Exception: {0}", e->Message);
			}
		}


		static System::Void write_to_file(System::String^ to_file, System::String^ file_path)
		{
			try
			{
				//String^ file = "Prace_Domowe/"+number+file_path->Remove((file_path->Length - 2), 2);
				String^ file = "$(SolutionDir)"+number+file_path->Remove((file_path->Length - 2), 2);
				StreamWriter^ writer = gcnew StreamWriter(file);
				for (size_t i = 0; i < to_file->Length; ++i)
				{
					if (to_file[i] == '{' || to_file[i] == '}')
					{
						writer->Write('\n');
						writer->Write(to_file[i]);
						writer->Write('\n');
					}
					else if (to_file[i] == '>' || to_file[i] == ';')
					{
						writer->Write(to_file[i]);
						writer->Write('\n');
					}
					else
					{
						writer->Write(to_file[i]);
					}
				}
				writer->Close();
				++number;
			}
			catch (Exception^ e)
			{
				Console::WriteLine(L"Exception: {0}", e->Message);
			}
		}

		String^ get_from_file()
		{
			return from_file;
		}

		~_FTP() { from_file = " "; file_path = ""; }
	};
}

#endif /* _FTP_H_ */