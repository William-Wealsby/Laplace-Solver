#include<iostream>
#include<fstream>
#include<cmath>

//function to initalise values
void initialise(double** vals, double** delta_vals, int LX, int LY, std::string BC){
	for (int i=0;i<LX;i++){
		for (int j=0;j<LY;j++){
			delta_vals[i][j]=0;			
		}
	}
	switch(BC){
		case "hyperbolic":
				//Code
				break;

		default:

				for(int i=0;i<LX;i++){
						for(int j=0;j<LY;j++){
								vals[i][j] = 0;
						}
				}
	}
}

//calculates differences between vals and next iteration
void calc_delta(double** vals, double** delta_vals, int x, int y){
	delta_vals[x][y] = 0.25*(vals[x+1][y]+vals[x-1][y]+vals[x][y+1]+vals[x][y-1])-vals[x][y];
}

//updates vals to to next iteration
void update_vals(double** vals, double** delta_vals, int x, int y){
	vals[x][y]+=vals[x][y];
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
	

	// create memory for arrays - vals & delta_vals
	double** vals = new double*[LY];
	for (int i=0;i<LY;i++){
		vals[i] = new double[LX];
	}
	double** delta_vals = new double*[LY];
	for (int i=0;i<LY;i++){
		delta_vals[i] = new double[LX];
	}

	//initalise memory for 
	intialise(vals,delta_vals,LX,LY,BC);


	//loop for N iterations and loop over val apart from fixed values (edges)
	for (int k=0;k<N;k++){

		for (int j=1;j<LY-1;j++){
			for (int i=1;i<LX-1;i++){
				calc_delta(vals,delta_vals,i,j);
			}
		}

		for (int j=1;j<LY-1;j++){
			for (int i=1;i<LX-1;i++){
				update_vals(vals,delta_vals,i,j);
			}
		}
	}

	//store in json format in output file






	//cleanup memory used
	for (int;i=0;i<LY;i++){
		delete[] vals[i];	
	}
	delete[] vals;

	for (int i=0;i<LY;i++){
		delete[] delta_vals[i];
	}
	delete[] delta_vals;

}
