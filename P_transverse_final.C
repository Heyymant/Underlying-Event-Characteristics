

void P_transverse_final()
{
    TFile *f=new TFile("datafile.root");
   
    //Creating Plot stuff
    const Int_t bins = 47;
    Double_t x[bins];
    Double_t y[bins];
    Double_t counter[bins];
    
    //Creating 2-tuple
    Double_t pTmax;
    Double_t pTsumtransverse;
    
    //Tree stuff
    const Int_t maxTrack = 100;
    Int_t ntrack = 0;
    Double_t pT[maxTrack];
    Double_t phi[maxTrack];
    Double_t eta[maxTrack];
    Int_t entries;
    
    //Canvas and histogram
    TCanvas *c1 = new TCanvas("c1","Hello World",200,10,500,300);

    
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    //FIRST TREE
    TTree *tree1 = (TTree*)f->Get("pytree020");
    
    for(Int_t ff = 0; ff<bins; ff++)
    {
        x[ff] = 0.6 + ff*0.2 + 0.1;
        y[ff] = 0.0;
        
        counter[ff] = 0.0;
    }
    
    
    
    tree1->SetBranchAddress("ntrack",&ntrack);
    tree1->SetBranchAddress("phi",&phi);
    tree1->SetBranchAddress("pT",&pT);
    tree1->SetBranchAddress("eta",&eta);    
    
    
    //BiG LOOP
    
    entries = tree1->GetEntries();

    
    for(Int_t ii = 0; ii<entries; ii++)
    {
    
            // Event loop starts here
        
                
                tree1->GetEntry(ii);
                
                Int_t ntrks = ntrack;
                
                
            
                for(Int_t i=0; i<ntrks; i++)
		{
                    for(Int_t j = i; j<ntrks; j++)
			{
                        if(pT[j+1]>pT[j])
                        {
                            Double_t temp = pT[j+1];
                            pT[j+1] = pT[j];
                            pT[j] = temp;
                            
                            temp = phi[j+1];
                            phi[j+1] = phi[j];
                            phi[j] = temp;
				
                            temp = eta[j+1];
                            eta[j+1] = eta[j];
                            eta[j] = temp;				
                        }
			}
               	 }
                
                pTmax = pT[0];
                pTsumtransverse = 0;
        
                
                for(Int_t h = 0; h<ntrks; h++)
                {
                    phi[h] = phi[h] - phi[0];
                    
                    phi[h]*=180;
                    phi[h]/=3.14;
                 

                    if( (eta[h]<=2.5 && eta[h]>= -2.5) && (pT[h]>0.6))
			{                       
                    if((phi[h]<=-60 && phi[h]>=-120) || (phi[h]>=60 && phi[h]<=120) )
                        pTsumtransverse+=pT[h];
			}
                    
                }
                
                
                //Finding per unit rapidity per angle
                
                pTsumtransverse/=10.46;


        
            //50 Bins

            for(Int_t f = 0; f<bins; f++)
            {
                        if(  pTmax >= x[f]-0.1 && pTmax < x[f]+0.1  )
                        {
                            y[f] += pTsumtransverse;
                            counter[f]++;
                        }
            }
    }
    
    
    
  
    
    


    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    //SECOND TREE
    TTree *tree2 = (TTree*)f->Get("pytree2040");
    tree2->SetBranchAddress("ntrack",&ntrack);
    tree2->SetBranchAddress("phi",&phi);
    tree2->SetBranchAddress("pT",&pT);
    tree2->SetBranchAddress("eta",&eta);    
    
    //BiG LOOP
    
    entries = tree2->GetEntries();
    
    
    for(Int_t ii = 0; ii<entries; ii++)
    {
        
        // Event loop starts here
        
        
        tree2->GetEntry(ii);
        
        Int_t ntrks = ntrack;
        
            
                for(Int_t i=0; i<ntrks; i++)
		{
                    for(Int_t j = i; j<ntrks; j++)
			{
                        if(pT[j+1]>pT[j])
                        {
                            Double_t temp = pT[j+1];
                            pT[j+1] = pT[j];
                            pT[j] = temp;
                            
                            temp = phi[j+1];
                            phi[j+1] = phi[j];
                            phi[j] = temp;
				
                            temp = eta[j+1];
                            eta[j+1] = eta[j];
                            eta[j] = temp;				
                        }
			}
               	 }
                
                pTmax = pT[0];
                pTsumtransverse = 0;
        
                
                for(Int_t h = 0; h<ntrks; h++)
                {
                    phi[h] = phi[h] - phi[0];
                    
                    phi[h]*=180;
                    phi[h]/=3.14;
                 

                    if( (eta[h]<=2.5 && eta[h]>= -2.5) && (pT[h]>0.6))
			{                       
                    if((phi[h]<=-60 && phi[h]>=-120) || (phi[h]>=60 && phi[h]<=120) )
                        pTsumtransverse+=pT[h];
			}
                    
                }
                
                
                //Finding per unit rapidity per angle
                
                pTsumtransverse/=10.46;
        
        //50 Bins
        
        for(Int_t f = 0; f<bins; f++)
        {
            if(  pTmax >= x[f]-0.1 && pTmax < x[f]+0.1  )
            {
                y[f] += pTsumtransverse;
                counter[f]++;
            }
        }
    }
    
    

    
    
    
    
    
    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    //THIRD TREE
    TTree *tree3 = (TTree*)f->Get("pytree4060");
    tree3->SetBranchAddress("ntrack",&ntrack);
    tree3->SetBranchAddress("phi",&phi);
    tree3->SetBranchAddress("pT",&pT);
    tree3->SetBranchAddress("eta",&eta);    
    
    
    
    //BiG LOOP
    
    entries = tree3->GetEntries();
    
    
    for(Int_t ii = 0; ii<entries; ii++)
    {
        
        // Event loop starts here
        
        
        tree3->GetEntry(ii);
        
        Int_t ntrks = ntrack;
            
                for(Int_t i=0; i<ntrks; i++)
		{
                    for(Int_t j = i; j<ntrks; j++)
			{
                        if(pT[j+1]>pT[j])
                        {
                            Double_t temp = pT[j+1];
                            pT[j+1] = pT[j];
                            pT[j] = temp;
                            
                            temp = phi[j+1];
                            phi[j+1] = phi[j];
                            phi[j] = temp;
				
                            temp = eta[j+1];
                            eta[j+1] = eta[j];
                            eta[j] = temp;				
                        }
			}
               	 }
                
                pTmax = pT[0];
                pTsumtransverse = 0;
        
                
                for(Int_t h = 0; h<ntrks; h++)
                {
                    phi[h] = phi[h] - phi[0];
                    
                    phi[h]*=180;
                    phi[h]/=3.14;
                 

                    if( (eta[h]<=2.5 && eta[h]>= -2.5) && (pT[h]>0.6))
			{                       
                    if((phi[h]<=-60 && phi[h]>=-120) || (phi[h]>=60 && phi[h]<=120) )
                        pTsumtransverse+=pT[h];
			}
                    
                }
                
                
                //Finding per unit rapidity per angle
                
                pTsumtransverse/=10.46;
        
        
        //50 Bins
        
        for(Int_t f = 0; f<bins; f++)
        {
            if(  pTmax >= x[f]-0.1 && pTmax < x[f]+0.1  )
            {
                y[f] += pTsumtransverse;
                counter[f]++;
            }
        }
    }
    
    
    

    

    
    
    
    
    ////////////////////////////////////////////////////////////////////////////////////////////
    //FOURTH TREE
    TTree *tree4 = (TTree*)f->Get("pytree6080");
    tree4->SetBranchAddress("ntrack",&ntrack);
    tree4->SetBranchAddress("phi",&phi);
    tree4->SetBranchAddress("pT",&pT);
    tree4->SetBranchAddress("eta",&eta);    
    
    
    
    //BiG LOOP
    
    entries = tree4->GetEntries();
    
    
    for(Int_t ii = 0; ii<entries; ii++)
    {
        
        // Event loop starts here
        
        
        tree4->GetEntry(ii);
        
        Int_t ntrks = ntrack;
            
                for(Int_t i=0; i<ntrks; i++)
		{
                    for(Int_t j = i; j<ntrks; j++)
			{
                        if(pT[j+1]>pT[j])
                        {
                            Double_t temp = pT[j+1];
                            pT[j+1] = pT[j];
                            pT[j] = temp;
                            
                            temp = phi[j+1];
                            phi[j+1] = phi[j];
                            phi[j] = temp;
				
                            temp = eta[j+1];
                            eta[j+1] = eta[j];
                            eta[j] = temp;				
                        }
			}
               	 }
                
                pTmax = pT[0];
                pTsumtransverse = 0;
        
                
                for(Int_t h = 0; h<ntrks; h++)
                {
                    phi[h] = phi[h] - phi[0];
                    
                    phi[h]*=180;
                    phi[h]/=3.14;
                 

                    if( (eta[h]<=2.5 && eta[h]>= -2.5) && (pT[h]>0.6))
			{                       
                    if((phi[h]<=-60 && phi[h]>=-120) || (phi[h]>=60 && phi[h]<=120) )
                        pTsumtransverse+=pT[h];
			}
                    
                }
                
                
                //Finding per unit rapidity per angle
                
                pTsumtransverse/=10.46;
        
               
        //50 Bins
        
        for(Int_t f = 0; f<bins; f++)
        {
            if(  pTmax >= x[f]-0.1 && pTmax < x[f]+0.1  )
            {
                y[f] += pTsumtransverse;
                
                counter[f]++;
            }
        }
    }
    
    
    
    //Averaging
    for(int g = 0; g<bins; g++)
    {
        if(counter[g]!=0)
            y[g]/=counter[g];
    }
    
     
    
    //Histogramming
    
    TH1* h4 = new TH1D(
                       /* name */ "Histogram",
                       /* title */ "Ntowards",
                       /* X-dimension */ bins, 0.6, 10.0
                       /* Y-dimension */);
    
    for(Int_t da = 0; da<bins; da++)
    {
        h4->Fill(x[da],y[da]);
    }
    
    h4->Draw();
    
}

