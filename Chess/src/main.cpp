// Chess 
#include "Chess.h"
#include "BoardManager.h"

int main()
{
	// string board = "RNBQKBNRPPPPPPPP################################pppppppprnbqkbnr"; 
	string board = "kb########################################R####R########r#R#K###";
	Chess a(board);
	BoardManager bm(board);
	int codeResponse = 0;
	string res = a.getInput();
	while (res != "exit")
	{
		/* 
		codeResponse value : 
		Illegal movements : 
		11 - there is not piece at the source(board checks)
		12 - the piece in the source is piece of your opponent(board check)
		13 - there one of your pieces at the destination (board checks)
		21 - illegal movement of that piece(piece check)
		31 - this movement will cause you checkmate(piece and board checks)

		legal movements : 
		41 - the last movement was legal and cause check (piece and board checks)
		42 - the last movement was legal, next turn (piece and board checks)
		*/

		/**/ 
		{ // put your code here instead that code
			// cout << "code response >> ";
			// cin >> codeResponse;
			codeResponse = static_cast<int>(bm.playMove(res));
			std::cout<<codeResponse<<std::endl;
			// cin>>codeResponse;
		}
		/**/

		a.setCodeResponse(codeResponse);
		res = a.getInput(); 
	}

	cout << endl << "Exiting " << endl; 
	return 0;
}