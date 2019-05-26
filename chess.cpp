// Compile me as ...
//						g++ -o chess_for_nerds chess.cpp
//

#include<bits/stdc++.h>
using namespace std;

/*
	kk - king
	qq - queen
	lr - left rook
	rr - right rook
	lk - left knight
	rk - right knight
	lb - left bishop
	rb - right bishop
	ss - soldier
	bl - blank space
	
	   1    2	 3	  4	   5    6    7    8	
	o----o----o----o----o----o----o----o----o
1	\ rr \ rk \ rb \ qq \ kk \ lb \ lk \ lr \
	o----o----o----o----o----o----o----o----o
2	\ ss \ ss \ ss \ ss \ ss \ ss \ ss \ ss \
	o----o----o----o----o----o----o----o----o
3	\    \    \    \    \    \    \    \    \
	o----o----o----o----o----o----o----o----o
4	\    \    \    \    \    \    \    \    \
	o----o----o----o----o----o----o----o----o
5	\    \    \    \    \    \    \    \    \
	o----o----o----o----o----o----o----o----o
6	\    \    \    \    \    \    \    \    \
	o----o----o----o----o----o----o----o----o
7	\ ss \ ss \ ss \ ss \ ss \ ss \ ss \ ss \
	o----o----o----o----o----o----o----o----o
8	\ lr \ lk \ lb \ qq \ kk \ rb \ rk \ rr \
	o----o----o----o----o----o----o----o----o
*/



int main()
{
	//string board[8][8];
	int i,j;
	
	printf("\n\n\t\t############## MINI CHESS ##############\n");	
	string border = "	o----o----o----o----o----o----o----o----o";
	string colnum = "	   1    2    3    4    5    6    7    8";
	string colrnm = "	   8    7    6    5    4    3    2    1";
	
	fflush(stdin);
	// char rr[4] = " rr "; 		--> is wrong initialization, due to less space for the char array
	
	char rr[4] = {' ', 'r', 'r', ' '};
	char lr[4] = {' ', 'l', 'r', ' '};
	char rk[4] = {' ', 'r', 'k', ' '};
	char lk[4] = {' ', 'l', 'k', ' '};
	char rb[4] = {' ', 'r', 'b', ' '};
	char lb[4] = {' ', 'l', 'b', ' '};
	char qq[4] = {' ', 'q', 'q', ' '};
	char kk[4] = {' ', 'k', 'k', ' '};
	char ss[4] = {' ', 's', 's', ' '};
	char bl[4] = {' ', ' ', ' ', ' '};
	
	char *pawns[] = {"rr", "lr",
					 "rk", "lk",
				 	 "rb", "lb",
				 	 "qq", "kk",
				 	 "ss", "bl"};
		
	char* board[8][8];	// 2D array of pointers ??
	
	// Initializing the board
	board[0][0] = board[7][7] = "rr";
	board[0][1] = board[7][6] = "rk";
	board[0][2] = board[7][5] = "rb";
	board[0][3] = board[7][3] = "qq";
	board[0][4] = board[7][4] = "kk";
	board[0][5] = board[7][2] = "lb";
	board[0][6] = board[7][1] = "lk";
	board[0][7] = board[7][0] = "lr";
	
	for(i=0;i<8;i++)
		board[1][i] = board[6][i] = "ss";
	
	for(i=2;i<6;i++)
		for(j=0;j<8;j++)
			board[i][j] = "  ";
		
/*		
	printf("The Initial board is...\n");
	printf("\t\t\tPLAYER 0\n\n");
	cout << colnum << "\n" << border << "\n";
	for(i=0;i<8;i++)
	{
	    cout << i+1 << "\t| ";
		for(j=0;j<8;j++)		
			cout << board[i][j] << " | ";
		cout << "\n" << border << "\n";		
	}
	cout << "\n";
	printf("\t\t\tPLAYER 1\n");
*/	
		
	printf("\nInitial Board is \n");
	printf("\t\t\tPLAYER 1\n\n");
	cout << colrnm << "\n" << border << "\n";	
	for(i=7;i>=0;i--)
	{
	    cout << i+1 << "\t| ";
		for(j=7;j>=0;j--)		
			cout << board[i][j] << " | ";
		cout << "\n" << border << "\n";		
	}
	cout << "\n";
	printf("\t\t\tPLAYER 0\n");
	
	int player = 0;
	while(1)
	{
		char ans;
		cout << "-------------------------------------------------------\n";
		//char p[2];
		int sr,sc,dr,dc;		
		printf(">> Player %d's turn now\n",player);
		cout << "\tEnter the pawn's loc. and dest. (loc and dest as -1 -1 -1 -1 -1 to exit) = ";
		scanf("%d%d%d%d",&sr,&sc,&dr,&dc);
		
		if(sr==-1||sc==-1||dr==-1||dc==-1)
			break;
		board[dr-1][dc-1] = board[sr-1][sc-1];
		board[sr-1][sc-1] = "  ";
		printf("\nBoard after change :\n");
		if(player)
		{
			printf("\t\t\tPLAYER 0\n\n");
		
			cout << colnum << "\n" << border << "\n";
			for(i=0;i<8;i++)
			{
				cout << i+1 << "\t| ";
				for(j=0;j<8;j++)		
					cout << board[i][j] << " | ";
				cout << "\n" << border << "\n";		
			}		
			cout << "\n";
			printf("\t\t\tPLAYER 1\n");
		}
		else
		{
			printf("\t\t\tPLAYER 1\n\n");
			cout << colrnm << "\n" << border << "\n";	
			for(i=7;i>=0;i--)
			{
				cout << i+1 << "\t| ";
				for(j=7;j>=0;j--)		
					cout << board[i][j] << " | ";
				cout << "\n" << border << "\n";		
			}
			cout << "\n";
			printf("\t\t\tPLAYER 0\n");		
		}
		
		printf("Want to proceed ?? (y/n) ");
		cin >> ans;
		
		if(ans=='n')
			break;
		player^=1;				
		if(player)
		{
			printf("\t\t\tPLAYER 0\n\n");
		
			cout << colnum << "\n" << border << "\n";
			for(i=0;i<8;i++)
			{
				cout << i+1 << "\t| ";
				for(j=0;j<8;j++)		
					cout << board[i][j] << " | ";
				cout << "\n" << border << "\n";		
			}		
			cout << "\n";
			printf("\t\t\tPLAYER 1\n");
		}
		else
		{
			printf("\t\t\tPLAYER 1\n\n");
			cout << colrnm << "\n" << border << "\n";	
			for(i=7;i>=0;i--)
			{
				cout << i+1 << "\t| ";
				for(j=7;j>=0;j--)		
					cout << board[i][j] << " | ";
				cout << "\n" << border << "\n";		
			}
			cout << "\n";
			printf("\t\t\tPLAYER 0\n");		
		}						
	}
	
	printf("\n\n\t\t\t\t\"Thank you for your time in the Game\"\n\n\n");
	
	return 0;
}
	

/*
	kk - king
	qq - queen
	lr - left rook
	rr - right rook
	lk - left knight
	rk - right knight
	lb - left bishop
	rb - right bishop
	ss - soldier
	
	   1    2	 3	  4	   5    6    7    8	
	 ---- ---- ---- ---- ---- ---- ---- ----
1	\ rr \ rk \ rb \ qq \ kk \ lb \ lk \ lr \
	 ---- ---- ---- ---- ---- ---- ---- ----
2	\ ss \ ss \ ss \ ss \ ss \ ss \ ss \ ss \
	 ---- ---- ---- ---- ---- ---- ---- ----
3	\    \    \    \    \    \    \    \    \
	 ---- ---- ---- ---- ---- ---- ---- ----
4	\    \    \    \    \    \    \    \    \
	 ---- ---- ---- ---- ---- ---- ---- ----
5	\    \    \    \    \    \    \    \    \
	 ---- ---- ---- ---- ---- ---- ---- ----
6	\    \    \    \    \    \    \    \    \
	 ---- ---- ---- ---- ---- ---- ---- ----
7	\ ss \ ss \ ss \ ss \ ss \ ss \ ss \ ss \
	 ---- ---- ---- ---- ---- ---- ---- ----
8	\ lr \ lk \ lb \ qq \ kk \ rb \ rk \ rr \
	 ---- ---- ---- ---- ---- ---- ---- ----
*/
