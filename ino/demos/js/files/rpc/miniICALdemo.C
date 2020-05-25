/// \file
/// \ingroup tutorial_geom
/// Definition of a simple geometry (the 4 ROOT characters)
///
/// \macro_image
/// \macro_code
///
/// \author Andrei Gheata

void miniICALdemo(bool vis = true)
{
   // gStyle->SetCanvasPreferGL(true);

   TGeoManager *geom = new TGeoManager("simple1", "Simple geometry");

   //--- define some materials
   TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
//    TGeoMaterial *matAl = new TGeoMaterial("Al", 26.98,13,2.7);
//   //--- define some media
   TGeoMedium *Vacuum = new TGeoMedium("Vacuum",1, matVacuum);
  // All Units in cm
 
   int nRPC = 10;
   //--- make the top container volume
   Double_t worldx = 210.;
   Double_t worldy = 210.;
   Double_t worldz = 500.;
   Double_t rpcDim = 200; 
   Double_t glassThickness = 0.2;
   Double_t gasGap = 1.5;


   TGeoVolume *world = geom->MakeBox("TOP", Vacuum, worldx, worldy, worldz*nRPC);
   geom->SetTopVolume(world);


   // Iron plate
   Double_t ironThickness = 2.;
   TGeoVolume *ironPlate = geom->MakeBox("Ironplate", Vacuum, rpcDim+75, rpcDim+75, ironThickness);
   ironPlate->SetLineColor(kBlue);
   //ironPlate->SetTransparency(0.9);
   //ironPlate->AddNode(topGlass,1, new TGeoTranslation(0, 0, gasGap));


   TGeoVolume *rpcWorld = geom->MakeBox("TOP", Vacuum, worldx, worldy, worldz);
  
   //geom->SetVisibility(kFALSE);




   //Glass




   TGeoVolume *topGlass = geom->MakeBox("TOPGLASS", Vacuum, rpcDim, rpcDim, glassThickness);
   topGlass->SetLineColor(kBlue);
   topGlass->SetTransparency(0.9);
   rpcWorld->AddNode(topGlass,1, new TGeoTranslation(0, 0, gasGap));

   TGeoVolume *botGlass = geom->MakeBox("BOTGLASS", Vacuum, rpcDim, rpcDim, glassThickness);
   rpcWorld->AddNode(botGlass,1, new TGeoTranslation(0, 0, -gasGap));
   botGlass->SetTransparency(0.9);
   botGlass->SetLineColor(kBlue);
   
  //HoneyComb Glass
   Double_t HCspacing = 2.5;
   TGeoVolume *topHC = geom->MakeBox("TOPHC", Vacuum, rpcDim, rpcDim, glassThickness);
   topHC->SetLineColor(kRed);
   topHC->SetTransparency(0.9);
   rpcWorld->AddNode(topHC,1, new TGeoTranslation(0, 0, gasGap+HCspacing));

   TGeoVolume *botHC = geom->MakeBox("BOTHC", Vacuum, rpcDim, rpcDim, glassThickness);
   rpcWorld->AddNode(botHC,1, new TGeoTranslation(0, 0, -gasGap-HCspacing));
   botHC->SetLineColor(kRed);
   botHC->SetTransparency(0.9);

 //Strips
   Double_t stripW = 3;
   Double_t stripSpacing = 3.25;
   Double_t stripThickness =0.1;
   Double_t stripShift = 2; // how 
//top strips
   TGeoVolume *TopStrip = geom->MakeBox("TopStrips", Vacuum, rpcDim, stripW, stripThickness);
   TopStrip->SetLineColor(kYellow);
   TopStrip->SetTransparency(0.9);
   for(int i=0;i<64;i++){
   rpcWorld->AddNode(TopStrip,i+1, new TGeoTranslation(0, -rpcDim+i*(stripW+stripSpacing), gasGap+HCspacing+stripShift));
   }
//bottom strips
   TGeoVolume *BotStrip = geom->MakeBox("BotStrips", Vacuum, stripW, rpcDim, stripThickness);
   BotStrip->SetLineColor(kYellow);
   BotStrip->SetTransparency(0.9);
   for(int i=0;i<64;i++){
   rpcWorld->AddNode(BotStrip,i+1, new TGeoTranslation(-rpcDim+i*(stripW+stripSpacing),0, -gasGap-HCspacing-stripShift));
   }
//button spacer
   Double_t buttonThickness =0.5;
   Double_t innerRad =0.0;
   Double_t outerRad =5;
   Double_t buttonSpacing =35;
   

   TGeoVolume *button = geom->MakeTube("Button", Vacuum, innerRad, outerRad, buttonThickness);
   button->SetLineColor(kGray);
   button->SetTransparency(0.9);
   for(int j=0; j<10;j++){
   for(int i=0; i<10;i++){
   rpcWorld->AddNode(button,i+1, new TGeoTranslation(-rpcDim+j*(outerRad+buttonSpacing)+13, -rpcDim+i*(outerRad+buttonSpacing)+13, 0));
   }

   }


    Double_t layer_spacing =25;
    Double_t iron_offset =10;

     TEveTrack *track = new TEveTrack();
    for(int i=0;i<nRPC;i++){
     if(i!=nRPC-1)
     world->AddNode(rpcWorld,i,new TGeoTranslation(0, 0, (layer_spacing)*i));
     world->AddNode(ironPlate,i,new TGeoTranslation(0, 0, (layer_spacing)*i-iron_offset));
     track->AddPoint(-(nRPC-i)*(nRPC-i), 0, (layer_spacing)*i,i);
     
    }

   geom->AddTrack(track);
   geom->CloseGeometry();
   geom->Export("miniICAL.root");
   // disable sections to save only part of geometry

   //--- draw the ROOT box.
   // by default the picture will appear in the standard ROOT TPad.
   //if you have activated the following line in system.rootrc,
   //it will appear in the GL viewer
   //#Viewer3D.DefaultDrawOption:   ogl

   geom->SetVisLevel(4);
   if (vis) world->Draw("ogle");
    track->Draw("SAME");
  
}
