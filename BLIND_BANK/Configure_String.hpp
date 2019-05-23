#ifndef _CONFIGURE_STRING_H_
#define _CONFIGURE_STRING_H_

#include <string>
#include <iostream>
#include "_FTP.hpp"

namespace BLINDBANK {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace MySql::Data::MySqlClient;

	public ref class SQL_CONFIGURATION
	{
		private:
			/*System::String^ file = L"DB_CONNECTION.txt";
			_FTP^ Obj = gcnew _FTP(file);*/
			static String^ konfiguracja = L"datasource=remotemysql.com;port=3306;username=aUy3ZvnM7k;password=wUMpRMvSyN;database=aUy3ZvnM7k";
		//	static String^ konfiguracja = L"datasource="+datasource+";port="+port+";username="+username+";password="+password+";database="+database+"";
			static String^ datasource;
			static String^ port;
			static String^ username;
			static String^ password;
			static String^ database;
		public:
			SQL_CONFIGURATION()
			{

			}

			SQL_CONFIGURATION(System::String^ datasource, System::String^ port, System::String^ username, System::String^ password, System::String^ database)
			{
				this->datasource = datasource;
				this->port = port;
				this->username = username;
				this->password = password;
				this->database = database;
			}

			static String^ get_konfiguracja()
			{
				return konfiguracja;
			}

			~SQL_CONFIGURATION() { konfiguracja = " "; }
	};
}
#endif /* _CONFIGURE_STRING_H_ */