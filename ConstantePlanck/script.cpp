#include <iostream>
#include <fstream>
#include <string>

#include "TROOT.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TF1.h"

// void ReadCVS(const char* FileName)
void ReadCVS(const char* FileName, unsigned bins, double Range_min, double Range_max)
{
    std::ifstream CVSFile(FileName);

    std::string line;

    size_t pos = 0;
    bool NumericValue;

    double time, in1, in2;

    // TProfile *Time_Voltage_profile = new TProfile("tvp","Time - Voltage profile",100,-2.5,2.5);
    // TProfile *Time_Current_profile = new TProfile("tcp","Time - Current profile",100,-2.5,2.5);
    TProfile *Voltage_Current_profile = new TProfile("vcp","Voltaje - Current profile",bins,-1.5,0.5,"s");
    

    int lineNumber = 0;

    while( std::getline( CVSFile, line ) )
    {
        NumericValue = true;
        lineNumber++;

        if((pos = line.find(",")) != std::string::npos) {
            try
            {
                time = std::stod( line.substr(0, pos) );
                if( (lineNumber > 309) && (lineNumber < 719) )
                    time *= 0.001;
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }
            
            line.erase(0, pos + 1);
        }
        if((pos = line.find(",")) != std::string::npos) {
            try{
            
                in1 = std::stod( line.substr(0, pos) );
            }
            catch(const std::exception& e)
            {
                NumericValue = false;
                std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
                continue;
            }            
            line.erase(0, pos + 1);
        }
        try
        {
            in2 = std::stod( line );
        }
        catch(const std::exception& e)
        {
            NumericValue = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
            continue;
        }
        
        // if(NumericValue) std::cout << lineNumber << " " << time << " " << in1 << " " << in2 << std::endl;
        // if(NumericValue) Time_Voltage_profile->Fill(time,in1);
        // if(NumericValue) Time_Current_profile->Fill(time,in2);
        if(NumericValue) Voltage_Current_profile->Fill(in1,in2);
        
    }

    TCanvas *aCanvas = new TCanvas("ac","Uncorrected data",1600,600);
    aCanvas->Divide(2);

    // aCanvas->cd(1);
    // Time_Voltage_profile->Draw();
    // aCanvas->cd(2);
    // Time_Current_profile->Draw();

    aCanvas->cd(1);
    Voltage_Current_profile->Draw();
    

    gStyle->SetOptFit(1);

    TF1 *lFunc = new TF1("line","[0]+[1]*x",Range_min,Range_max);
    lFunc->SetParNames("b","m");

    aCanvas->cd(2);

    Voltage_Current_profile->Fit(lFunc,"R");
}