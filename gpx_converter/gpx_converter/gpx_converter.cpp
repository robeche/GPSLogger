// gpx_converter.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(int argc, char** argv)
{
    ifstream inputfile;
    ofstream outputfile;

    string line;

    string delimiter;

    int start;
    int end;

    char time[34];
    char trkpt[42];
    char ele[20];

    char wpt[256];
    string filename;

    if (argc == 2)
    {
        cout << "Argument is: " << argv[1];
        filename.assign(argv[1]);

        cout << "String is : " << filename;

    }



    inputfile.open(filename);
    outputfile.open("./output.gpx");

    if (outputfile.is_open())
    {
        outputfile << "<gpx" << endl;
        outputfile << "\tversion= \"1.1\"" << endl;
        outputfile << "\tcreator=\"Roberto Echeverria\"" << endl;
        outputfile << "\txmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"" << endl;
        outputfile << "\txmlns=\"http://www.topografix.com/GPX/1/1\"" << endl;
        outputfile << "\txsi:schemaLocation=\"http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd\"" << endl;
        outputfile << "\txmlns:gpxtpx=\"http://www.garmin.com/xmlschemas/TrackPointExtension/v1\">" << endl;
        outputfile << "\t<trk>" << endl;
        outputfile << "\t\t<name> La noche de Juantxo</name>" << endl;
        outputfile << "\t\t<trkseg>" << endl;

    }
    if (inputfile.is_open())
    {
        while (getline(inputfile, line))
        {
            getline(inputfile, line);

            // YEAR
            start = 0;
            delimiter = "-";
            end = line.find(delimiter);
            int year = stoi(line.substr(start, end - start));

            //MONTH
            start = end + delimiter.size();
            end = line.find(delimiter, start);
            int month = stoi(line.substr(start, end - start));

            //DAY
            start = end + delimiter.size();
            delimiter = " ";
            end = line.find(delimiter, start);
            int day = stoi(line.substr(start, end - start));

            //HOUR
            start = end + delimiter.size();
            delimiter = ":";
            end = line.find(delimiter, start);
            int hour = stoi(line.substr(start, end - start));

            //HOUR
            start = end + delimiter.size();
            delimiter = ":";
            end = line.find(delimiter, start);
            int minute = stoi(line.substr(start, end - start));

            //SECOND
            start = end + delimiter.size();
            delimiter = " ";
            end = line.find(delimiter, start);
            int second = stoi(line.substr(start, end - start));

            //LATITUDE
            start = end + delimiter.size() + 4;
            delimiter = " ";
            end = line.find(delimiter, start);
            float lat = stof(line.substr(start, end - start));

            //LONGITUDE
            start = end + delimiter.size() + 5;
            delimiter = " ";
            end = line.find(delimiter, start);
            float lon = stof(line.substr(start, end - start));

            sprintf_s(time, "<time>%04d-%02d-%02dT%02d:%02d:%02dZ</time>", year, month, day, hour, minute, second);
            sprintf_s(trkpt, "<trkpt lat=\"%.5f\" lon=\"%.5f\">", lat, lon);
            sprintf_s(ele, "<ele>0.00</ele>");

            //sprintf_s(wpt, "<wpt lat = \"%.5f\" lon = \"%5f"> < ele>3.4 < / ele > < time>2016 - 06 - 17T23:41 : 03Z< / time><extensions><gpxtpx : TrackPointExtension> < gpxtpx : hr>171 < / gpxtpx : hr > < / gpxtpx : TrackPointExtension>< / extensions>< / wpt>

            if (lat != 0.0)
            {
                outputfile << "\t\t\t" << trkpt << endl;
                outputfile << "\t\t\t\t" << ele << endl;
                outputfile << "\t\t\t\t" << time << endl;
                outputfile << "\t\t\t" << "</trkpt>" << endl;

            }


        }
        outputfile << "\t\t" << "</trkseg>" << endl;
        outputfile << "\t" << "</trk>" << endl;
        outputfile << "" << "</gpx>" << endl;

    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
