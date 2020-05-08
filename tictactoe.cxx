/*
 * SIMPLE TIC TAC TOE Using C++
 * u know the rules already
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

/*
 * atm = copy variable of number of attempt
 */
int atm=0; 

struct container{
	/*
	 *Each field contain:
	 * 	-Condition : Is this field still have 0-8 (initial) condition  or not to check who is the owner of this field
	 * 	-Occupied Status: is this field occupied yet? 
	 * 	-Attribute : Symbol X or O
	 * 
	 * Q: why are you using cond and occ? its not very effective tho
	 * A: condition is to check number attempt and the owner of the field, while occupied just check is the field has been occupied or not.
	 * 	  For example if i just using occ to check while the occ status is all zero, then the game is already 
	 *    finished because of the game checking will return true to the if parameter.
	 * 	  
	 */
	int cond, occ;
	string attr;
}table[9];

void field(){
	/*
	 * Draw the field
	 */
	cout<<setw(3)<<table[6].attr<<"|"<<setw(3)<<table[7].attr<<"|"<<setw(3)<<table[8].attr<<endl;
	cout<<"-----------"<<endl;
	cout<<setw(3)<<table[3].attr<<"|"<<setw(3)<<table[4].attr<<"|"<<setw(3)<<table[5].attr<<endl;
	cout<<"-----------"<<endl;
	cout<<setw(3)<<table[0].attr<<"|"<<setw(3)<<table[1].attr<<"|"<<setw(3)<<table[2].attr<<endl;
}

bool go_check(){
	/*
	 * Check if the game is finished or not. this function check allthe game rule and number of attempt
	 */
	int attempt;
	bool cek;
	
	//cout<<attempt<<endl;
	
	if ((table[0].attr == table[3].attr)&&(table[3].attr == table[6].attr)&&(table[0].attr == table[6].attr)){
		cek = true;
	}else if ((table[1].attr == table[4].attr)&&(table[4].attr == table[7].attr)&&(table[1].attr == table[7].attr)){
		cek = true;
	}else if ((table[2].attr == table[5].attr)&&(table[2].attr == table[8].attr)&&(table[5].attr == table[8].attr)){
		cek = true;
	}else if ((table[0].attr == table[1].attr)&&(table[0].attr == table[2].attr)&&(table[1].attr == table[2].attr)){
		cek = true;
	}else if ((table[4].attr == table[3].attr)&&(table[3].attr == table[5].attr)&&(table[4].attr == table[5].attr)){
		cek = true;
	}else if ((table[7].attr == table[8].attr)&&(table[7].attr == table[6].attr)&&(table[8].attr == table[6].attr)){
		cek = true;
	}else if ((table[0].attr == table[4].attr)&&(table[0].attr == table[8].attr)&&(table[4].attr == table[8].attr)){
		cek = true;
	}else if ((table[2].attr == table[4].attr)&&(table[2].attr == table[6].attr)&&(table[4].attr == table[6].attr)){
		cek = true;
	}else{
		cek = false;
	}
	
	attempt = 0;
	for (int i = 0; i < 9; i++)
	{
		if (table[i].occ == 0)
		{
			attempt++;
		}
	}
	atm =attempt;
	
	if (attempt == 0 && cek == false){
		cek = true;
	}
	return cek;
}

void do_game(int role){
	/*
	 * this is where the game begin
	 * im using odd and even number to check who is playing this role
	 */
	//system("CLS");
	string player1 = "X", player2 = "O", playerPlay;
	int fieldCond;
	cout<<"ROLE :"<<role<<endl;
	cout<<atm<<endl<<endl; //nah don't mind it, just print the number of attempt
	int fieldChoose;
	field();
	if (role%2 == 0)
	{
		playerPlay = player1;
		fieldCond = 1;
	}else{
		playerPlay = player2;
		fieldCond = 2;
	}
	
	cout<<"Player "<<playerPlay<<" Field Choose: ";cin>>fieldChoose;
	fieldChoose--;
	if (fieldChoose < 9 && fieldChoose >= 0 )
	{
		if (table[fieldChoose].occ == 0){
			table[fieldChoose].attr = playerPlay;
			table[fieldChoose].cond = fieldCond;
			table[fieldChoose].occ = 1;
		}else{
			cout<<"Table "<<fieldChoose<<" OCCUPIED!"<<endl;
			system("PAUSE");
			do_game(role);
		}
	}else{
		cout<<"Choose the RIGHT FIELD!"<<endl;
		system("PAUSE");
		do_game(role);
	}
	
	if(go_check()== true){
		//system("cls");
		cout<<"ROLE :"<<role<<endl;
		field();
		if (atm==0){
			cout<<"DRAW"<<endl;
		}else if (role%2 != 0){
			cout<<"PLAYER O WIN"<<endl;
		}else{
			cout<<"PLAYER X WIN"<<endl;
		}
		system("PAUSE");
		exit(0);
	}else{
		role++;
		do_game(role);
	}
}

int main()
{
	/*
	 * MAIN FUNC
	 * First Init Condition of the field
	 * Honestly im still looking for the answer about how to convert int to string in c++ haha,
	 * thats why im just manually make those attribute so when the game begin at first,
	 * the field will show you the position number
	 */
	int role=0;
	
	table[0].attr = "1";
	table[1].attr = "2";
	table[2].attr = "3";
	table[3].attr = "4";
	table[4].attr = "5";
	table[5].attr = "6";
	table[6].attr = "7";
	table[7].attr = "8";
	table[8].attr = "9";
	
	for (int i = 0; i < 9; i++)
	{
		table[i].cond = i;
		table[i].occ = 0;
	}
	do_game(role);
	
	return 0;
}

