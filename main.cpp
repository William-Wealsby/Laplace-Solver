#include<iostream>
#include<fstream>
#include<cmath>

//function to initalise values
void initialise(double** vals, double** delta_vals, int LX, int LY, int BC){
	const double pi = 3.14159265358979323846;

	for (int i=0;i<LX;i++){
		for (int j=0;j<LY;j++){
			delta_vals[i][j]=0;			
		}
	}
	switch(BC){
		case 1: // hyperbolic
			
			for (int j=0;j<LY;j++){
				vals[0][j] = std::cosh(0)*std::sin(pi*j/(LY-1));
				vals[LX-1][j] = std::cosh(pi)*std::sin(pi*j/(LY-1));
			}

			for (int i=1;i<LX-1;i++){
				vals[i][0] = std::cosh(pi*i/(LX-1))*std::sin(0);
				vals[i][LY-1] = std::cosh(pi*i/(LX-1))*std::sin(pi);
				
			}


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
	vals[x][y]+=delta_vals[x][y];
}

int main(int argc, char** argv){
		
		//	allows initalise strings for input and output file	
	std::string input = "";
	std::string output = "output/output.json";

	// reads inputs piped in via bash script, if number isn't the amount expected then it ignores them.
	if (argc==3){
			input = argv[1];
			output = argv[2];
	}
	
	int itrs=0;
	int LX=10;
	int LY=10;
	int BC=1;

	//find values from input file if it exists
	if (input!=""){
		std::ifstream inputfile(input);
		inputfile >> itrs;
		inputfile >> LX;
		inputfile >> LY;
		inputfile >> BC;
		inputfile.close();
	}
	

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
	initialise(vals,delta_vals,LX,LY,BC);


	//loop for N iterations and loop over val apart from fixed values (edges)
	for (int k=0;k<itrs;k++){

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
	std::ofstream outputfile(output);
	outputfile << "[\n";
	for (int j=0;j<LY;j++){
		
		outputfile << '[';
		for (int i=0;i<LX;i++){
			outputfile << vals[j][i];
			if(i!=LX-1){
				outputfile << ',';
			}
		}
		if (j==LX-1){outputfile << "]\n";}
		else {outputfile << "],\n";}

	}
	outputfile << ']';
	outputfile.close();


	//cleanup memory used
	for (int i=0;i<LY;i++){
		delete[] vals[i];	
	}
	delete[] vals;

	for (int i=0;i<LY;i++){
		delete[] delta_vals[i];
	}
	delete[] delta_vals;

	std::cout << "Completed";

}
