#include "TFile.h"
#include "TTree.h"
#include "TH1D.h"
#include "TCanvas.h"
#include "TStyle.h"
#include "TF1.h"
#include "TString.h"
#include <iostream>

void plot_and_fit(const char* inFile = "gauss.root") {
    TFile *f = TFile::Open(inFile, "READ");
    if (!f || f->IsZombie()) {
        std::cerr << "ERROR: cannot open file" << inFile << "\n";
        return;
    }
    TTree *t = nullptr;
    f->GetObject("t", t);
    if (!t) {
        std::cerr << "ERROR: tree 't' not found in " << inFile << "\n";
        f->Close();
        return;
    }

    gStyle->SetCanvasColor(kWhite);
    gStyle->SetPadColor(kWhite);
    gStyle->SetFrameFillColor(kWhite);
    gStyle->SetStatColor(kWhite);

    TCanvas *c = new TCanvas("c", "Gaussian histogram", 900, 650);
    c->SetFillColor(kWhite);

    TH1D *h = new TH1D("h", "", 50, -5.0, 5.0);
    t->Draw("x>>h", "", "goff");

    h->SetLineColor(kBlack);
    h->SetLineWidth(3);
    h->SetFillColor(kYellow);
    h->SetFillStyle(1001);

    h->GetXaxis()->SetTitle("x");
    h->GetYaxis()->SetTitle("Entries");

    h->Fit("gaus");
    h->Draw("HIST");
    h->GetFunction("gaus")->Draw("SAME");
    c->SaveAs("gauss_hist_fit.png");

    f->Close();

    std::cout << "Saved plot \n";

}