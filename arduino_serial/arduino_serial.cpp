#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>
#include <iomanip>
#using <System.dll>
using namespace std;
using namespace System;
using namespace System::IO::Ports;

struct WaterBody
{
	float distance, humidity, temperature, heatIndex;
};

void getData(vector<WaterBody>& vec1)
{

	string line, s_temp;

	ifstream readFile("data.txt");

	while (getline(readFile, line))
	{
		WaterBody temp;
		istringstream is(line);
		getline(is, s_temp, ',');
		temp.distance = stof(s_temp);
		getline(is, s_temp, ',');
		temp.humidity = stof(s_temp);
		getline(is, s_temp, ',');
		temp.temperature = stof(s_temp);
		getline(is, s_temp, ',');
		temp.heatIndex = stof(s_temp);

		vec1.push_back(temp);
	}

	readFile.close();
}

//void displayData(vector<WaterBody> vec1)
//{
//	for (size_t i = 0; i < vec1.size(); i++)
//	{
//		cout << setprecision(2) << fixed
//			<< "Distance: " << vec1[i].distance
//			<< " Humidity: " << vec1[i].humidity
//			<< " Temperature: " << vec1[i].temperature
//			<< " Heat Index: " << vec1[i].heatIndex << endl;
//	}
//}

void displayDataInExcel()
{

}


int main()
{
	//SerialPort port("COM3", 9600);
	//cout << "Waiting for connection\t";

	//while (!port.IsOpen)
	//{
	//	try
	//	{

	//		port.Open();
	//	}
	//	catch (IO::IOException^ e)
	//	{
	//		cout << '.';
	//		Sleep(1000);
	//	}
	//}

	//Sleep(100);
	//cout << "Beginning to read.\n";
	//
	//ofstream writeFile("data.txt", ios::app);
	//while (!_kbhit())
	//{
	//	cout << "Reading data. Press any key to stop.\n";
	//	port.Write("A");

	//	String^ line;
	//	line = port.ReadTo("@");
	//	string temp = msclr::interop::marshal_as<std::string>(line);
	//	writeFile << temp << endl;
	//}
	//writeFile.close();
	vector<WaterBody> vec1;
	getData(vec1);


	cout << endl;


}