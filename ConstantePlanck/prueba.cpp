#include <iostream>
#include <fstream>
#include <string>

#include "TROOT.h"
#include "TCanvas.h"
#include "TProfile.h"
#include "TF1.h"

// void ReadCVS(const char* FileName)
void ReadCVS(const char* FileName, unsigned bins, double Range_min, double Range_max, double Factor)
{
    std::ifstream CVSFile(FileName);

    std::string line;

    size_t pos = 0;
    bool NumericValue;

    double time, in1D, in2D, time2, in1T, in2T;

    TProfile *Voltage_Current_profile = new TProfile("vcp","Voltaje - Current profile",bins,-1,0.5,"s");
    TProfile *Voltage_DarkCurrent_profile = new TProfile("vdcp","Voltaje - Dark Current profile.5",bins,-1,0.5,"s");
    TProfile *Voltage_Correct= new TProfile("c-correct", "Voltaje_correctedprof", bins,-0.5,0.5,"s");

    //TProfile *Voltage_Current = new TProfile("vc","Voltaje - Current",bins,-1.5,0.5,"s");

   
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
            
                in1D = std::stod( line.substr(0, pos) );
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
            
                in2D = std::stod( line.substr(0, pos) );
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
            try
            {
                time2 = std::stod( line.substr(0, pos) );
                if( (lineNumber > 309) && (lineNumber < 719) )
                    time2 *= 0.001;
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
            
                in1T = std::stod( line.substr(0, pos) );
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
            in2T = std::stod( line );
        }
        catch(const std::exception& e)
        {
            NumericValue = false;
            std::cerr << "Non numeric value. Skipping line " << lineNumber << '\n';
            continue;
        }
     

        if(NumericValue) Voltage_Current_profile->Fill(in1D,in2D*Factor);
        if(NumericValue) Voltage_DarkCurrent_profile->Fill(in1T, in2T*Factor);
        if(NumericValue) Voltage_Correct->Add(Voltage_Current_profile,Voltage_DarkCurrent_profile,1, -1);
        
        
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
    Voltage_Correct->Draw();
    Voltage_Correct->Fit(lFunc,"R");
}