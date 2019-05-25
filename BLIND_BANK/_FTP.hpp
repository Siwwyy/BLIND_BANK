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

		_FTP(System::String^ & file_path) :
			file_path(file_path),
			from_file("")
		{
			read_file();
		}

		static System::Void write_to_file(System::String^ to_file, System::String^ file_path)
		{
			try
			{
				String^ file = "Prace_Domowe/"+number+file_path->Remove((file_path->Length - 2), 2);
				StreamWriter^ writer = gcnew StreamWriter(file, true, Encoding::ASCII);
				//to_file += '~';
				for (size_t i = 0; i < to_file->Length; ++i)
				{
					/*if (to_file[i] == ' ')
					{
						writer->Write('\n');
					}*/
					writer->Write(to_file[i]);
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