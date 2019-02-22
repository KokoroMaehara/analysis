from ROOT import TTree,TFile,TH1F,TCanvas,TF1,TMath # ROOTから必要なクラスをimport
from ROOT import gStyle

gStyle.SetOptFit() # fitting parameterの表示

file = TFile("run0124_1.root") # Open file

c1 = TCanvas("c1","ch1",200,100,800,600) # TCanvas("name","title",size?)

f1 = TF1("f1","[0]*exp(-x/[1])+[2]") # TF1("name","funtion") = 1-Dim function
f1.SetNpx(10000) # Set the number of points used to draw the function
f1.SetParameters(1,2200,0) # Set initial value of parameters
f1.SetParNames("constant","#tau","offset") # Set parameters' name

tree = file.Get("v1290") # Get tree(:v1290) from read file
tree.Draw("0.02441*(tdc-trig)","ch==1") # Draw("branch & operation","conditions")

h = TH1F("h","tdc(ch1)",10000,0,10000) # TH1F("name","title",nbins,xmin,xmax)
h.Fit("f1","","",3000,8000) # Fit("function",?,?,xmin,xmax)

f1.Draw("same") # Draw same canvas

c1.Print("run1.png") # Print as "filename"
