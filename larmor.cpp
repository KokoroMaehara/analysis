//void plott()
{
     gStyle->SetOptFit();
     //Style->SetOptFit();
     TCanvas *c1 = new TCanvas("c1", "c1 title", 200, 100, 800, 600); //綺麗に見える設定らしい
     TFile *_file0 = TFile::Open("merge1_29.root");                   //TFile::Open("xxx.yyy"):ファイル"xxx.yyy"を開く

     TH1F *h1 = new TH1F("h1", "", 2000, 0, 10000);
     h1->SetStats(0);                                         //統計ボックスの非表示
     v1290->Draw("0.02441*(tdc-trig)+10000 >> h1", "ch==15"); //h(指定範囲の分割数,左端,右端)
     double x;
     TF1 *f1 = new TF1("f1", "[0]*(TMath::Exp(-x/[1])*(1+[2]*TMath::Cos([3]*x+[4]))+TMath::Exp(-(x-[5])/[1])*(1+[2]*TMath::Cos([3]*(x-[5])+[4])))+[6]", 2000, 8000); //フィッティングする為の関数の定義。[]で囲んである部分がフィットで変化させるパラメーター。関数を使うときはTMath::expのようにする。TMath::Gaus(Double_t x,Double_t mean,Double_t sigma)
     f1->SetNpx(10000);                                                                                                                                              //フィットした関数をプロットする細かさ

     f1->SetParameters(90, 2196.9811, 0.5, 0.0135, 6.18, 598, 0); //パラメータの初期値を決める

     f1->SetParNames("C_1", "#tau[ns]", "C_2", "#omega[rad/ns]", "#delta[rad]", "#Deltat[ns]", "C_3"); //パラメータの名前を決める
     h1->Fit("f1", "", "", 2000, 8000);                                                                //xが0.000000001から10の範囲についてフィット

     f1->Draw("same");    //読み込んだデータに重ねて書く
     c1->Print("00.png"); //xxx.pngの形式で書き出す
}
