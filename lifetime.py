from ROOT import TTree,TFile,TH1F,TCanvas,TF1

gStyle = SetOptFit()

f_in = pR.TFile("run0124_1.root")

TCanvas *c1 = new TCanvas("c1","ch1",200,100,800,600)

TF1 *f1 = new TF1("f1","[0]*exp(-x/[1])+[2]")
f1 = SetNpx(10000)
f1 = SetParameters(1,2200,0)
f1 = SetParNames("constant","#tau","offset")

v1290 = Draw("0.002441*(tdc-trig)","ch==1")
h = Fit("f1","","",-8000,-5000)
f1 = Draw("same")

c1 = Print("run1.png")
