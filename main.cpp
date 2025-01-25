include <iostream>
#include <vector>

class Polynomial_Functions {
	private:
	std::vector<std::vector<uint32_t>> Functions;
	std::vector<std::string> Polynoms;
	std::vector<uint32_t> coeff_1 = {0, 1, 2, 3};
	std::vector<uint32_t> coeff_2 = {0, 1, 2, 3, 4, 5, 6, 7};
	public:
	void get_all_functions();
	void get_vector(std::vector<uint32_t> coef, std::vector<uint32_t> &result);
	void make_string(std::vector <uint32_t> vector);
	void print();
};

void Polynomial_Functions::get_all_functions() {
	std::vector <uint32_t> polynom(4);
	std::vector <uint32_t> result(8);
	uint32_t j,k,m;
	
	for(j=0; j<4; ++j) {
		for(k=0; k<8; ++k) {
			polynom[0] = 1;
			polynom[1] = coeff_1[j];
			polynom[2] = coeff_2[k];
			polynom[3] = 0;
			get_vector(polynom, result);
			make_string(polynom);
			Functions.push_back(result);
		}
	}
	
	for(j=0; j<4; ++j) {
		for(k=0; k<8; ++k) {
			polynom[0] = 2;
			polynom[1] = coeff_1[j];
			polynom[2] = coeff_2[k];
			polynom[3] = 0;
			get_vector(polynom, result);
			make_string(polynom);
			Functions.push_back(result);
		}
	}
	
	for(k=0; k<8; ++k) {
		polynom[0] = 0;
		polynom[1] = 1;
		polynom[2] = coeff_2[k];
		polynom[3] = 0;
		get_vector(polynom, result);
		make_string(polynom);
		Functions.push_back(result);
	}
	
	for(k=0; k<8; ++k) {
		polynom[0] = 0;
		polynom[1] = 2;
		polynom[2] = coeff_2[k];
		polynom[3] = 0;
		get_vector(polynom, result);
		make_string(polynom);
		Functions.push_back(result);
	}
	
	polynom[0] = 0;
	polynom[1] = 0;
	polynom[2] = 1;
	polynom[3] = 0;
	get_vector(polynom, result);
	make_string(polynom);
	Functions.push_back(result);
	
	polynom[0] = 0;
	polynom[1] = 0;
	polynom[2] = 2;
	polynom[3] = 0;
	get_vector(polynom, result);
	make_string(polynom);
	Functions.push_back(result);
	
	polynom[0] = 0;
	polynom[1] = 0;
	polynom[2] = 4;
	polynom[3] = 0;
	get_vector(polynom, result);
	make_string(polynom);
	Functions.push_back(result);
	
	polynom[0] = 0;
	polynom[1] = 0;
	polynom[2] = 0;
	polynom[3] = 0;
	get_vector(polynom, result);
	make_string(polynom);
	Functions.push_back(result);
}

void Polynomial_Functions::get_vector(std::vector<uint32_t> coef, std::vector<uint32_t> 
&result) {
	for(int i = 0; i < 8; ++i) {
		result[i] = (coef[0]*i*i*i + coef[1]*i*i + coef[2]*i + coef[3]) % 8;
	}
}

void Polynomial_Functions::make_string(std::vector<uint32_t> vector) {
	std::string str;
	for(int i=0;i<4;++i) {
		if(i==3) {
			str += std::to_string(vector[i]);}
		else
		str += std::to_string(vector[i]) + ',';        
	}
	Polynoms.push_back(str);
}

void Polynomial_Functions::print() {
	uint32_t number = 8;
	std::cout<<"|x|";
	for(int m=0;m<8;++m) {
		std::cout << Polynoms[m]<< "|";
	}
	std::cout<<std::endl;
	for(int k=0;k<11;++k) {
		for(int i=0;i<8;++i) {
			std::cout << "|" << i << "|   ";
			for(int j=0;j<8;j++) {
				if(j+8*k>=84) {
					continue;}
				else {
					std::cout << Functions[j+8*k][i] <<"   |   ";}
				if(((i+1) % 8 == 0) && ((j+1) % 8 ==0 && k!=10)) {
					std::cout<<"\n\n|x|";
					for(int m=0;m<8;++m) {
						if(number>=84) {
							continue;}
						else {
							std::cout<< Polynoms[number]<< "|";
							number++;}
					}
				}      
			}
			std::cout << std::endl;
		}
	}
}

int main() {
	Polynomial_Functions Test;
	Test.get_all_functions();
	Test.print();
	return 0;
}