#ifndef _FTP_H_
#define _FTP_H_

#include <string>
#include <iostream>

namespace BLINDBANK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;
	using namespace System::IO;

	public ref class _FTP
	{
	private:

		System::String^ from_file;
		System::String^ file_path;
			
		System::Void read_file()
		{
			try
			{
				//Pass the file path and file name to the StreamReader constructor.
				StreamReader^ reader = gcnew StreamReader(this->file_path);
				System::String^ line = "";
				//Read the first line of text.
				line = reader->ReadLine();
				from_file += line;
				from_file += '\n';
				//Continue to read until you reach end of file.
				while (line != "" && reader->EndOfStream != true)
				{
					line = reader->ReadLine();
					from_file += line;
					from_file += '\n';
					//Write the lie to console window.
					//Console::WriteLine(line);
					//Read the next line.
				}
				
				//Close the file.
				reader->Close();
				//Console::ReadLine();
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


		String^ get_konfiguracja()
		{
			return from_file;
		}

		~_FTP() { from_file = " "; file_path = ""; }
	};
}

#endif /* _FTP_H_ */