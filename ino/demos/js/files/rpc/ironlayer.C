    // Iron layer geometry to be used for cross-section spline generation
    // Deepak Samuel
    // This code will produce an iron layer of size 1m x 1m x 5.6 cm (thick) placed inside a vacuum world
    // Run it with:
    //$ root
    //$ .L ironlayer.C
    //$ .x ironlayer.C
    void ironlayer(bool vis = true)
    {
    // gStyle->SetCanvasPreferGL(true);
    double iron_thickness= 5.6;   
    TGeoManager *geom = new TGeoManager("ironlayer", "Iron Layer");


    // All Units in cm
    
    int nRPC = 10;
    //--- make the top container volume
    Double_t worldx = 100.;
    Double_t worldy = 100.;
    Double_t worldz = iron_thickness;



    //--- define some materials
    TGeoMaterial *matVacuum = new TGeoMaterial("Vacuum", 0,0,0);
    TGeoMedium *Vacuum = new TGeoMedium("Vacuum",1, matVacuum);

    TGeoVolume *world = geom->MakeBox("TOP", Vacuum, worldx, worldy, worldz);
    geom->SetTopVolume(world);


    TGeoMaterial *matIron = new TGeoMaterial("Vacuum", 55.845,26,7.874);
    TGeoMedium *Iron = new TGeoMedium("Vacuum",1, matIron);
    TGeoVolume *ironPlate = geom->MakeBox("Ironplate", Iron, worldx, worldy, worldz);
    ironPlate->SetLineColor(kBlue);

        
    geom->CloseGeometry();
    world->Draw("ogle");
    geom->Export("ironlayer.root");

    
    }
