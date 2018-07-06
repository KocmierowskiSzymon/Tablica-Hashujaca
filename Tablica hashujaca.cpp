#include<iostream>

using namespace std;

/*------- struktura tablicy hashowej --------*/

	struct hasz
	{
		
		string slo;
		
		string nadmiar[10000];
		
	};

/*--------------------------------------------*/	
	


/*--------- Zmienne globalne ----------------*/
	
	string slowo;

	hasz tabhasz [12];
		
	int d, a, b, z, t;
	
/*---------------------------------------------*/	
	
	

/*----------------- Glowna funkcja programu --------------------*/	

	int main()
	{
		
		z = 0;
		
		while(1)
		{
		
			/*------------ Menu ---------------------*/
			
			cout << endl;
		
			cout << "Wybierz operacje, ktora chcesz wykonac" << endl;
			
			cout << "1. Wprowadz slowo do tablicy tablicy haszujacej" << endl;
			
			cout << "2. Sprawdz czy slowo jest w tablicy haszujacej" << endl;
		
			cout << "3. Wyswietl zawartosc tablicy haszujacej" << endl;
		
			cout << endl;
			
			/*-----------------------------------------*/
			
			
			
			/*------ Wybranie opcji z menu -------*/
			
			cin >> d; 
			
			/*--------------------------------------*/
			
			switch(d)
			{
			
				/*---------- Wprowadzanie slowa do tablicy hashowej ----------------*/
				
				case 1:
				{
					
					slowo = "";

					t = 0;

					a = 0;

					cin >> slowo;

					b = sizeof(slowo);

					while(slowo [t] != 0)
					{
						
						++t;
						
					}
					
					
					for(int i = 0; i < t; i++)	a =a + slowo [i];
					
					
					/* Adres w tablicy hashowej wyliczany jest poprzez wykonanie
					
					   na liczbie znakow slowa dzialania modulo wielkosc tablicy hashy*/
					
					a = a % 12;
					
					cout << a << endl;

					if(tabhasz [a].slo == "")
					{
						
						tabhasz [a].slo = slowo;

						cout << "Slowo: " << slowo << ", ma adres " << a << endl;

					}


					else
					{
					
						tabhasz [a].nadmiar [z] = slowo;
						
						++z;
						
						cout << "Slowo: "<<slowo<<", ma adres " << a << endl;
					
					}
					
					
					a = 0;
					
					break;
				}
				
				/*-----------------------------------------------------------------*/
				
				
				/*--------------------- Sprawdzenie, czy slowo znajduje sie w tablicy ---------------*/
				
				case 2:
				{
					
					a = 0;
					
					cin >> slowo;
					
					b = sizeof(slowo);
					
					for(int i = 0; i < b; i++)	a = a + slowo [i];
					
					
					/*	Aby sprawdzic, czy slowo znajduje sie w tablicy hashujacej, bedz w tablicy nadmiarowej
						
						wyliczany jest wpierw hash slowa (w tym przypadku liczba znakow modulo wielkosc tablicy hashy)
						
						po czym jest porownywane najpierw z slowem w tablicy hashujacej, jak nie ma slowa w tablicy hashujacej,
						
						to sprawdzana jest tablica nadmiaru. Jak trafimy na szukane slowo, badz pusty element tablicy
						
						zwracany jest odpowiedni komunikat a petla przerywana.*/
					
					a = a % 12;
					
					
					if(tabhasz [a].slo == slowo)
					{
						
						cout << "Slowo: " << slowo << ", znajduje sie w tablicy haszujacej" << endl;
					
					}
					
					
					else
					{
						
						for(int i = 0; i < 10000; i++)
						{
							
							if(tabhasz [a].nadmiar [i] == slowo)
							{
								
								cout << "Slowo: " << slowo << ", znajduje sie w tablicy haszujacej nadmiarowej" << endl;
								
								break;
								
							}
							
							
							if(tabhasz [a].nadmiar [i] == "")
							{
								
								cout << "Slowo: " << slowo << ", nie znajduje sie w tablicy haszujacej" << endl;
								
								break;
								
							}
						
						}
						
					}
					
					break;
					
				}
				
				/*--------------------------------------------------------*/
				
				
				/*--------- Wyswietlanie tablicy hashujacej i tablicy nadmiaru, dla poszczegolnych adresow ------------*/
				
				case 3:
				{
					
					for(int i = 0; i < 12; i++)
					{
						
						t = 0;
						
						cout << "Pod adresem: " << i << ", znajduje sie slowo: " << tabhasz [i].slo << endl;
						
						if(tabhasz [i].nadmiar [t] == "")
						{
							
							cout << "Twoja tablica nadmiarowa " << i << " jest pusta" << endl;
						
						}
						
						else
						{
							cout << "Twoja tablica nadmiarowa: " << i << " zawiera takie slowa jak: " << endl;

							while(tabhasz [i].nadmiar [t] != "")
							{
								
								cout << tabhasz [i].nadmiar [t] << ", ";

								++t;
							
							}
							
							cout<<endl;
						}
						
					}
					
				}
				
				/*-----------------------------------------------------------------------------------------*/
		}
		
		}
		
	}
	
/*-------------------------------------------------------------------------------------------*/
