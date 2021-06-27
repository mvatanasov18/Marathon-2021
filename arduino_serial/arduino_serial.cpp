#include <iostream>
#include <msclr\marshal_cppstd.h>
#using <System.dll>
using namespace std;
using namespace System;
using namespace System::IO::Ports;

int main()
{
	SerialPort port("COM3", 9600);
	cout << "Waiting for connection\t";
	while (!port.IsOpen)
	{
		try
		{

			port.Open();
		}
		catch (IO::IOException^ e)
		{
			cout << '.';
			Sleep(300);
		}
	}

	Sleep(1000);
	cout << endl;
	while (true)
	{
		port.Write("A");
		String^ line;
		line = port.ReadTo("@");
		string temp = msclr::interop::marshal_as<std::string>(line);
		cout << temp << endl;
	}
}