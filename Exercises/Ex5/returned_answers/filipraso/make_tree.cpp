#include "TFile.h"
#include "TTree.h"
#include "TRandom3.h"
#include "TString.h"
#include <iostream>

void make_tree(const char* outFile = "gauss.root", int N = 1000, double mean = 0.0, double sigma = 1.0) {
    TFile *f = TFile::Open(outFile, "RECREATE");
    if (!f || f->IsZombie()) {
        std::cerr << "ERROR: cannot open file" << outFile << "\n";
        return;
    }

    TTree *t = new TTree("t", "Gaussian random nums");
    double x = 0.0;
    t->Branch("x", &x, "x/D");

    TRandom3 rng(0);
    for (int i = 0; i < N; ++i) {
        x = rng.Gaus(mean, sigma);
        t->Fill();
    }

    f->cd();
    t->Write();
    f->Close();

    std::cout << "Wrote" << N << "entries to" << outFile << "in tree 't' with branch 'x'\n";
}