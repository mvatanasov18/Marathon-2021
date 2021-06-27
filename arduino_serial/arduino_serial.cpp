#include <iostream>
#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#using <System.dll>
using namespace std;
using namespace System;
using namespace System::IO::Ports;

//void dataToFile(string line)
//{
//	fstream file;
//	file.open("data.txt", ios::ate);
//	file << line;
//	file.close();
//}

void waitForConnection(SerialPort^& port)
{
	cout << "Waiting for connection\t";
	while (!port->IsOpen)
	{
		try
		{

			port->Open();
		}
		catch (IO::IOException^ e)
		{
			cout << '.';
			Sleep(300);
		}
	}
}

int main()
{
	SerialPort^ port = gcnew SerialPort("COM3", 9600);

	waitForConnection(port);
	while (true)
	{
		try
		{
			if (!port->IsOpen)
			{
				port->Open();
			}
			cout << endl;
			Sleep(100);
			while (true)
			{
				port->Write("A");
				String^ line;
				line = port->ReadTo("@");
				string temp = msclr::interop::marshal_as<std::string>(line);
				cout << temp << endl;
			}
		}
		catch (IO::IOException^ exception)
		{
			waitForConnection(port);
		}
	}

}