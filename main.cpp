#include <iostream>
#include <cmath>
#include <cstdlib>
#include <fstream>
#include "MaterialPoint.h"
#include "VectorField.h"
#include "TApplication.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TF1.h"
#include "TAxis.h"


using namespace std;

int main() {

   const double Radius_Earth = 6372797;
   const double R_GOCE = 6622797;
   const double pi = 4.0*atan(1.0);
   const double Mass_Earth = 5.9726E+24;
   const double Density_rocks= 3000;
   const double Radius_Rocks= 1000;

   // Point that will represent the discretization of the orbit
   int N = 1000;

   //Construction of Earth (center of our reference frame)
   MaterialPoint Earth(Mass_Earth ,0.,0.,0.,0.);

   //Construction of the Mountain range, circles above the earth's surface. We created 100 mountain placed on a contour of pi
   MaterialPoint** Rock = new MaterialPoint*[100];
   for (int i=0; i<100; i++){
      double phi = 2*i*(Radius_Rocks/Radius_Earth) + pi ;
      Rock[i] = new MaterialPoint( Density_rocks*(4/3)*pi*pow(Radius_Rocks,3), 0 , (Radius_Earth)*cos(phi) , (Radius_Earth)*sin(phi) , 0);
   }

   // Gravitational field produced by the Earth on GOCE's orbit
   VectorField** G_1 = new VectorField*[N];
   for (int i=0; i<N; i++){
      double theta = 2*pi*i/N;
      Position r(R_GOCE * cos(theta) , R_GOCE * sin(theta) , 0);
      G_1[i] =new VectorField(Earth.GravitationalField(r));
   }
  
   // Gravitational field produced by the Earth and Mountains on GOCE's orbit  
   VectorField** G_2 = new VectorField*[N];
   for (int i=0; i<N; i++) {
      double theta = 2*pi*i/N;
      Position r(R_GOCE * cos(theta) , R_GOCE * sin(theta) , 0);
      VectorField E(G_1[i]);
      for (int j=0; j<100; j++) {
         E += Rock[j]->GravitationalField(r);
      }
      G_2[i] = new VectorField(E);  
   }  


   //Variation of the modulus of the gravitational field + print on an output file
   ofstream fout("output.txt");
   long double* differential= new long double[N-1];
   fout<<"Modulus' variation \t        Angle (rad)"<<endl;
   fout<<endl;
   for (int i=0; i<N-1; i++){
      differential[i] = (G_2[i+1]->Modulus() - G_2[i]->Modulus())/G_1[1]->Modulus();
      if (fabs(differential[i]) > 1E-13) {
         fout<<differential[i]<<"\t \t \t"<<2*pi*i/N<<endl;
      }
   } 
   fout.close();

   //Printing the variation of the grav. field's modulus on a canvas using ROOT's libraries
   /*
   TApplication app("App",0,0);
   TGraph* g = new TGraph ();
   for (int i=0; i<N-1; i++) {
      g->SetPoint(i,2*pi*i/N,differential[i]);
   }
   TCanvas* mygraph = new TCanvas("mygraph","Graph");
   g->Draw("A*");
   g->GetXaxis()->SetTitle("Angle (Rad)");
   g->GetYaxis()->SetTitle(" Field's Modulus Variation");
   g->SetTitle("Field's modulus variation on a 2*pi orbit");
   app.Run();
   */
   
   delete [] Rock;
   delete [] G_1;
   delete [] G_2;
   delete [] differential;

   return 0;
}
