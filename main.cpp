#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {

	std::fstream odczytW("wzorzec.txt");
	std::fstream odczytS("szyfr.txt");
	std::string temp;
	char alf[36] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	bool flag;
	float powtorzenia[36] = { 0 };
	int ilosc_znakow=0;
	char tab[36][36];
	float icS[19] = { 0 };

	std::vector<char> znakW;
	std::vector<int> amountW;
	float icW = 0.0;

	while (getline(odczytW, temp, '\n')) {
		//std::cout << "x: " << x << std::endl;
		int dlugosc = temp.length();

		for (int i = 0; i < dlugosc; i++) {
			if (temp[i] > 95) //gdy napotkamy ma³¹ literê zamieniamy j¹ na du¿¹
				temp[i] = (char)(temp[i] - 32); //przesuwaj¹c o 32 miejsca w kodzie ASCII
		}
		//std::cout << temp << std::endl;

		for (int i = 0 ; i < dlugosc; i ++) {
			flag = 0;
			for (int z = 0; z < 36; z++) {
				if (temp[i] == alf[z]) {
					//std::cout << temp[i] << std::endl;
					flag = 1;
					ilosc_znakow++;
					//std::wcout << "size"<< znak.size() << std::endl;
					if (znakW.size() == 0) {
						//pom.push_back(temp[i]);
						//tab.push_back(pom);
						//tab[0].push_back(1);
						//std::cout << "x: " << x << std::endl;
						znakW.push_back(temp[i]);
						amountW.push_back(1);
					}
					else {
						//if (iter != m - 1) {
						bool flag_t = 0;
						for (int x = 0; x < znakW.size(); x++) {
							if (znakW[x] == temp[i]) {
								amountW[x]++;
								flag_t = 1;
								//tab[x][x]++;
								//std::cout << temp[i] << " " << znak[x] << std::endl;;
							}

						}
						if (!flag_t) {
							//pom.push_back(temp[i]);
							//tab.push_back(pom);
							//tab[x].push_back(1);
							znakW.push_back(temp[i]);
							amountW.push_back(1);
							//std::cout << "wpis " << temp[i] << std::endl;;
						}
						//iter++;
						//}
						//else iter = 0;
					}
				}
			}
			if (!flag) {
				//std::cout << temp[i];
			}
		}

		//std::cout << std::endl;
	}
	float a = 0.0;
	for (int v = 0; v < amountW.size(); v++) {
		a += (float)(amountW[v] * (amountW[v] - 1)) / (float)(ilosc_znakow * (ilosc_znakow - 1));
	}
	icW = a;
	std::cout << "wzorzec: " << icW << std::endl;
	

	for (int m = 2; m < 21; m++) {
		float* ic = new float[m];
		

		std::vector < std::vector<int> > tab;
		std::vector <int> pom;
		std::vector <int> pom2;

		int iter = 0;
		int licznik_grup = 0;
		for (int x = 0; x < m; x++) {
			std::vector<char> znak;
			std::vector<int> amount;
			std::fstream odczytS("szyfr.txt");
			ilosc_znakow = 0;
			//std::cout << "x: " << x << std::endl;
			while (getline(odczytS, temp, '\n')) {
				//std::cout << "x: " << x << std::endl;
				int dlugosc = temp.length();

				for (int i = 0; i < dlugosc; i++) {
					if (temp[i] > 95) //gdy napotkamy ma³¹ literê zamieniamy j¹ na du¿¹
						temp[i] = (char)(temp[i] - 32); //przesuwaj¹c o 32 miejsca w kodzie ASCII
				}
				//std::cout << temp << std::endl;

				for (int i = 0+x; i < dlugosc; i += m) {
					flag = 0;
					for (int z = 0; z < 36; z++) {
						if (temp[i] == alf[z]) {
							//std::cout << temp[i] << std::endl;
							flag = 1;
							ilosc_znakow++;
							//std::wcout << "size"<< znak.size() << std::endl;
							if (znak.size() == 0) {
								//pom.push_back(temp[i]);
								//tab.push_back(pom);
								//tab[0].push_back(1);
								//std::cout << "x: " << x << std::endl;
								znak.push_back(temp[i]);
								amount.push_back(1);
							}
							else {
								//if (iter != m - 1) {
								bool flag_t = 0;
								for (int x = 0; x < znak.size(); x++) {
									if (znak[x] == temp[i]) {
										amount[x]++;
										flag_t = 1;
										//tab[x][x]++;
										//std::cout << temp[i] << " " << znak[x] << std::endl;;
									}

								}
								if (!flag_t) {
									//pom.push_back(temp[i]);
									//tab.push_back(pom);
									//tab[x].push_back(1);
									znak.push_back(temp[i]);
									amount.push_back(1);
									//std::cout << "wpis " << temp[i] << std::endl;;
								}
								//iter++;
								//}
								//else iter = 0;
							}
						}
					}
					if (!flag) {
						//std::cout << temp[i];
					}
				}

				//std::cout << std::endl;
			}
			//std::cout << "ilosc znakow: "<<ilosc_znakow << std::endl;
			float a=0.0;
			for (int j = 0; j < znak.size(); j++) {
				//std::cout << znak[j] << " ";
			}
			//std::cout << std::endl;
			for (int j = 0; j < amount.size(); j++) {
				//std::cout << amount[j] << " ";
			}
			//std::cout << std::endl;
			for (int v = 0; v < amount.size(); v++) {
				a += (float)(amount[v] * (amount[v] - 1)) / (float)(ilosc_znakow*(ilosc_znakow-1));				
			}
			ic[x] = a;
			//std::cout << "ic: " << ic[x] << " " << std::endl;
		}
		std::cout << std::endl;
		for (int l = 0; l < m; l++) {
			icS[m - 2] += ic[l];
		}
		icS[m - 2] = icS[m - 2] / m;
		std::cout << "icS: " << m << " " << icS[m - 2];
		std::cout << std::endl;
		
		//OBLICZYÆ IC DLA GRUPY
	}
	return 0;
}