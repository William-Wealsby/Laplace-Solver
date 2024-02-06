#include<iostream>
#include<fstream>
#include<cmath>

//function to initalise values
void initialise(double** vals, int LX, int LY, std::string BC){
		switch(BC){
		
		case "hyperbolic":
				\\Code
				break;

		default:

				for(int i=0;i<LX;i++){
						for(int j=0;j<LY;j++){
								vals[i][j] = 0;
						}
				}
		}
}


void calc_delta(double** vals,double** delta_vals, int x, int y){
		continue;
		//
}

int main(int argc, char** argv){

		
		//	allows initalise strings for input and output file	
		std::string input = "";
		std::string output = "output/output.json";
		std::string err_output = "output/err_output.json";
		
		// reads inputs piped in via bash script, if number isn't the amount expected then it ignores them.
		if (argc==4){
				input = argv[1];
				output = argv[2];
				err_output = argv[3];
		}

		int LX=10;
		int LY=10;
		std::string BC = "";

		// create 
		




		intialise(vals,LX,LY,BC);
		
}
