#ifndef _CONFIGURE_STRING_H_
#define _CONFIGURE_STRING_H_

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

	public ref class SQL_CONFIGURATION
	{
		private:

			static String^ konfiguracja = L"datasource=remotemysql.com;port=3306;username=aUy3ZvnM7k;password=wUMpRMvSyN;database=aUy3ZvnM7k";

		public:
			SQL_CONFIGURATION()
			{

			}

			static String^ get_konfiguracja()
			{
				return konfiguracja;
			}

			~SQL_CONFIGURATION() { konfiguracja = " "; }
	};
}
#endif /* _CONFIGURE_STRING_H_ */